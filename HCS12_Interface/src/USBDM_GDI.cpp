/*! \file
   \brief Entry points for USBDM library

   USBDM_GDI.cpp

   \verbatim
   USBDM GDI interface DLL
   Copyright (C) 2008  Peter O'Donoghue

    This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
\endverbatim
\verbatim
Change History
-============================================================================================
|  Oct  8 2012 | Modified ARM accesses to use maximum aligned sizes                - pgo V4.10.2
|  May  7 2012 | Changed to using RESET_DEFAULT for ARM in DiExecResetChild()      - pgo V4.9.5
|  Mar 30 2012 | Fixed block address error in DIMemoryWrite() when flashing        - pgo V4.9.4
|  Mar 30 2012 | Changed to USBDM_SetExtendedOptions() etc.                        - pgo V4.9.4
|  Mar 24 2012 | Added actions to PROCESS_DETACH (for DSC programmer)              - pgo V4.9.4
|  Jan 14 2012 | Ported to DSC                                                     - pgo V4.9
|  Jul 16 2011 | Extended TargetConnect strategies & Messages HCSxx                - pgo V4.7
|  Jul  3 2011 | Changes to DSC code in DLL                                        - pgo V4.7
|  Jul  3 2011 | Changes related to CFVx recovery from sleeping                    - pgo V4.7
|  Jul  2 2011 | Added halt/connect in DiExecResetChild() - HCS08                  - pgo V4.7
|  Jun 30 2011 | Added checks for WAIT/WFE states                                  - pgo V4.7
|  Jun 30 2011 | Re-arranged connection code to avoid spurious secured error       - pgo V4.7
|  Jun    2011 | Added autoconnect on DiGdiGetStatus                               - pgo
+============================================================================================
\endverbatim
*/

#ifndef LEGACY
//#define USE_MEE  // Experiment - only applicable to Eclipse
#endif

#include <string>
#include <stdio.h>
#include <stdarg.h>
#include <assert.h>
#ifdef __unix__
#include <dlfcn.h>
#endif
#include "Common.h"
#include "Log.h"
#include "Version.h"
#include "USBDM_AUX.h"
#include "USBDM_API.h"
#include "GDI.h"
#include "GDI_Aux.h"
#include "Metrowerks.h"
#include "Conversion.h"
#include "TargetDefines.h"
#include "FlashImage.h"
#include "DeviceData.h"
#include "Names.h"
#include "wxPlugin.h"
#ifdef LEGACY
#include "USBDMDialogue.h"
#endif
#if (TARGET != CFVx) && !defined(LEGACY)
// Flash programming is not supported on above targets
#define FLASH_PROGRAMMING 1
#endif

#ifdef FLASH_PROGRAMMING
#include "FlashProgramming.h"
#endif
#if TARGET == CFVx
#include "osbdm_cfv234.h"
#elif TARGET == CFV1
#include "osbdm_cfv1.h"
#elif TARGET == MC56F80xx
#include "USBDM_DSC_API.h"
#include "DSC_Utilities.h"
#elif (TARGET == ARM)
#include "ArmDebug.h"
#include "ARM_Definitions.h"
#endif

#include "MetrowerksInterface.h"

// Nasty hack - records the first pc write to use as reset PC on future resets
bool     pcWritten            = false;
uint32_t pcResetValue         = 0x000000;
bool     programmingSupported = false;

bool usbdm_gdi_dll_open(void);
bool usbdm_gdi_dll_close(void);

static USBDMStatus_t USBDMStatus;
#if TARGET == MC56F80xx
static dscInfo_t     dscInformation;
#endif
static const TargetType_t targetType = T_HC12;

#ifdef FLASH_PROGRAMMING
static FlashProgrammer *flashProgrammer = NULL;
#endif

const static DiFeaturesT diFeatures = {
  /* .szIdentification                 = */ (DiStringT)"USBDM HCS12",
  /* .szVersion                        = */ (DiStringT)"1.2.6",
  /* .dnVersion                        = */ (1<<16)+(2<<8)+6,
  /* .pszConfig                        = */ NULL,
  /* .dnConfigArrayItems               = */ 0,
  /* .dccIOChannel                     = */ DI_COMM_NONE,
  /* .fMemorySetMapAvailable           = */ FALSE,
  /* .fMemorySetCpuMapAvailable        = */ FALSE,
  /* .pszMemoryType                    = */ NULL,
  /* .dnMemTypeArrayItems              = */ 0,
  /* .fEnableReadaheadCache            = */ FALSE,
  /* .fTimerInCycles                   = */ FALSE,
  /* .dnTimerResolutionMantissa        = */ 128,
  /* .dnTimerResolutionExponent        = */ 0,
  /* .ddfDownloadFormat = */    {
                  /* .dafAbsFileFormat = */ DI_ABSF_BINARY,
                  /* .dnBufferSize     = */ 1000,
                  /* .daAddress        = */ {0},
                 },
  /* .ddfAuxDownloadFormat = */ {
                  /* .dafAbsFileFormat = */ DI_ABSF_NONE,
                  /* .dnBufferSize     = */ 0,
                  /* .daAddress        = */ {0,{{{0}}}},
                 },
  /* .fAuxiliaryDownloadPathAvailable  = */ FALSE,
  /* .dcCallback                       = */ DI_CB_MTWKS_EXTENSION|DI_CB_DEBUG|DI_CB_LOG,
  /* .fRegisterClassSupport            = */ FALSE,
  /* .fSingleStepSupport               = */ TRUE,
  /* .fContinueUntilSupport            = */ FALSE,
  /* .fContinueBackgroundSupport       = */ FALSE,
  /* .dnNrCodeBpAvailable              = */ 1, // Code breakpoints
  /* .dnNrDataBpAvailable              = */ 1, // Data read/write breakpoints
  /* .fExecFromCodeBp                  = */ TRUE,
  /* .fExecFromDataBp                  = */ TRUE,
  /* .fUnifiedBpLogic                  = */ TRUE,
  /* .fExecCycleCounterAvailable       = */ FALSE,
  /* .fExecTimeAvailable               = */ FALSE,
  /* .fInstrTraceAvailable             = */ FALSE,
  /* .fRawTraceAvailable               = */ FALSE,
  /* .fCoverageAvailable               = */ FALSE,
  /* .fProfilingAvailable              = */ FALSE,
  /* .fStateSaveRestoreAvailable       = */ FALSE,
  /* .dnStateStoreMaxIndex             = */ 0,
  /* .pdbgBackground                   = */ NULL,
  /* .dnBackgroundArrayItems           = */ 0,
  /* .fDirectDiAccessAvailable         = */ FALSE,  // Direct commands not available
  /* .fApplicationIOAvailable          = */ FALSE,
  /* .fKernelAware                     = */ FALSE,
#ifdef USE_MEE
  /* .fMeeAvailable                    = */ TRUE,
#else
  /* .fMeeAvailable                    = */ FALSE,
#endif
  /* .dnNrCpusAvailable                = */ 1,
  /* .deWordEndianness                 = */ DI_BIG_ENDIAN,
  /* .dnNrHardWareCodeBpAvailable      = */ 0, // No hardware code breakpoints!
  /* .fCodeHardWareBpSkids             = */ FALSE,
  /* .pReserved                        = */ NULL,
};

//============================================================================
#ifdef FLASH_PROGRAMMING
//! BDM Options to be used with the target when Flash programming
//!
static USBDM_ExtendedOptions_t bdmProgrammingOptions = {
   sizeof(USBDM_ExtendedOptions_t),
   targetType
};

//! Description of currently selected device
//!
static DeviceData deviceOptions;
//! Flash image for programming
//!
static FlashImage *flashImage = NULL;
#endif

//! BDM Options to be used with the target in general use
//!
static USBDM_ExtendedOptions_t bdmOptions;

// How hard to try to connect initially
static RetryMode initialConnectOptions = (RetryMode)(retryAlways|retryWithInit|retryByReset);
// How hard to try to connect after initial connection
static RetryMode softConnectOptions    = retryNever;

//=====================================================================================
// Error handling
static DiReturnT   currentError       = DI_ERR_STATE; // No functions available until DiGdiInitIO() is called
static const char *currentErrorString = "GDI Not opened";

//! Check if pending error condition and return immediately if so
//!
#define CHECK_ERROR_STATE() \
   if (currentError == DI_ERR_FATAL) {\
      print("CHECK_ERROR_STATE() - failed, rc=%d\n", currentError); \
      return currentError; \
   }

//!
//!
//! @param errorCode   - Error code identifying error type
//! @param errorString - Error message (NULL => use generic message)
//!
//! @return errorCode passed as 1st parameter
//!
DiReturnT setErrorState(DiReturnT   errorCode,
                        const char *errorString = NULL) {

   currentError       = errorCode;
   currentErrorString = errorString;

   if ((errorString == NULL) || (errorCode == DI_OK)) {
     // Add default message if specific message not already provided
     switch(errorCode) {
        case DI_OK :
           currentErrorString = ("No error");
           break;
        case DI_ERR_STATE :
           currentErrorString = ("GDI function called with incorrect GDI internal state");
           break;
        case DI_ERR_PARAM :
           currentErrorString = ("Illegal parameter to GDI function");
           break;
        case DI_ERR_COMMUNICATION :
           currentErrorString = ("Communication error in GDI function");
           break;
        case DI_ERR_NOTSUPPORTED  :
           currentErrorString = ("GDI Function not supported");
           break;
        case DI_ERR_NONFATAL :
           currentErrorString = ("Non-fatal error in GDI function");
           break;
        case DI_ERR_CANCEL :
           currentErrorString = ("GDI function cancelled");
           break;
        case DI_ERR_FATAL :
           currentErrorString = ("Fatal error in GDI function");
           break;
     }
   }
   if (errorCode != DI_OK) {
      print("setErrorState(%s (errorCode=%d))\n", currentErrorString, errorCode); \
   }
   return currentError;
}

DiReturnT setErrorState(DiReturnT       errorCode,
                        USBDM_ErrorCode rc) {

   return setErrorState(errorCode, USBDM_GetErrorString(rc));
}

static DiStringT getGDIErrorMessage(void) {

   return (DiStringT)currentErrorString;
}

//!  Close connection to target
//!
//!  @return error code, see \ref USBDM_ErrorCode
//!
static DiReturnT closeBDM(void) {

   USBDM_ErrorCode rc;

   print("closeBDM()\n");

   rc = USBDM_Close();

   if (rc != BDM_RC_OK) {
      return setErrorState(DI_ERR_FATAL, rc);
   }
   return setErrorState(DI_OK);
}

//===================================================================
//! Does the following:
//!   - Initialises USBDM interface
//!   - Legacy  - Display USBDM Dialogue to obtain settings
//!   - Eclipse - Loads settings from Codewarrior
//!   - Loads device data from database
//!   - Opens BDM
//!   - Sets BDM options
//!   - Sets BDM target type
//!   - Sets up Flash programmer
//!
//!  Displays an error dialogue on failure. \n
//!  May prompt to retry connection for certain errors.
//!
//! @return \n
//!     DI_OK              => OK \n
//!     DI_ERR_FATAL       => Error see \ref currentErrorString
//!
static USBDM_ErrorCode initialiseBDMInterface(void) {
   print("initialiseBDMInterface()\n");

   USBDM_ErrorCode bdmRC;

   programmingSupported = false;

   bdmRC = USBDM_Init();
   if (bdmRC != BDM_RC_OK) {
      USBDM_Exit();
      print("initialiseBDMInterface() - failed, reason = %s\n", USBDM_GetErrorString(bdmRC));
      return bdmRC;
   }
   // Close any existing connection
   closeBDM();

#if defined(GDI) && defined(LEGACY)
   // Display dialogue to obtain BDM settings
   string deviceName;
   string projectName;
   loadNames(deviceName, projectName);
   // Create the USBDM Dialogue
   USBDMDialogue dialogue(targetType, _("USBDM Configure"));

   //   SetTopWindow(dialogue);
   dialogue.Create(NULL);
   bdmRC = dialogue.execute(deviceName, projectName);

   if (bdmRC == BDM_RC_OK) {
		dialogue.getBdmOptions(bdmOptions);
#if (TARGET != CFVx) && (TARGET != MC56F80xx)
		dialogue.getDeviceOptions(deviceOptions);
#endif
   }
#else
   // Load the settings from the Eclipse environment
   string preferredBdm;
   if (bdmRC == BDM_RC_OK) {
      bdmRC = loadSettings(targetType, bdmOptions, preferredBdm);
   }
   // Cycle Vdd on connect is done by GDI instead of BDM H/W
   if ((bdmOptions.targetVdd != BDM_TARGET_VDD_OFF) && bdmOptions.cycleVddOnConnect) {
      initialConnectOptions = (RetryMode)(retryWithInit|retryAlways|retryByReset|retryByPower);
      softConnectOptions    = (RetryMode)(retryAlways|retryByPower);
   }
   else {
      initialConnectOptions = (RetryMode)(retryWithInit|retryAlways|retryByReset);
      softConnectOptions    = (RetryMode)(retryAlways);
   }
   bdmOptions.cycleVddOnConnect = FALSE;

   if (bdmRC == BDM_RC_OK) {
   	bdmRC = USBDM_OpenBySerialNumberWithRetry(targetType, preferredBdm);
   }
#if TARGET == CFVx
   if (bdmRC == BDM_RC_OK) {
      HardwareCapabilities_t capabilities;
      if ((USBDM_GetCapabilities(&capabilities)==BDM_RC_OK) &&
            (capabilities&BDM_CAP_PST) == 0) {
         // Don't use PST option if not supported by BDM
         bdmOptions.usePSTSignals = false;
      }
   }
#endif
   if (bdmRC == BDM_RC_OK) {
   	bdmRC = USBDM_SetOptionsWithRetry(&bdmOptions);
   }
#endif
   // Set Target
   if (bdmRC == BDM_RC_OK) {
      bdmRC = USBDM_SetTargetTypeWithRetry(targetType);
   }
   if (bdmRC != BDM_RC_OK) {
      USBDM_Exit();
      print("initialiseBDMInterface() - failed, reason = %s\n", USBDM_GetErrorString(bdmRC));
      return bdmRC;
   }
#ifdef FLASH_PROGRAMMING
   // Set up flash programmer for target
   if (flashProgrammer != NULL) {
      delete flashProgrammer;
   }
   // Load description of device
   bdmRC = getDeviceData(deviceOptions);
   if (bdmRC != BDM_RC_OK) {
      deviceOptions.setTargetName("Unknown");
      return bdmRC;
   }
#if (TARGET == RS08)
   DeviceData::EraseOptions eraseOptions = deviceOptions.getEraseOption();
   if ((eraseOptions == DeviceData::eraseSelective) || (eraseOptions == DeviceData::eraseAll)) {
      // These targets only support mass erase
      deviceOptions.setEraseOption(DeviceData::eraseMass);
   }
#endif
   deviceOptions.setSecurity(SEC_INTELLIGENT);
   
   // Copy required options for Flash programming.
   // Other options are reset to default.
   bdmProgrammingOptions.size       = sizeof(USBDM_ExtendedOptions_t);
   bdmProgrammingOptions.targetType = targetType;
   USBDM_GetDefaultExtendedOptions(&bdmProgrammingOptions);
   bdmProgrammingOptions.targetVdd           = bdmOptions.targetVdd;
   bdmProgrammingOptions.interfaceFrequency  = bdmOptions.interfaceFrequency;
   flashProgrammer = new FlashProgrammer;
   flashProgrammer->setDeviceData(deviceOptions);
   programmingSupported = true;
#endif

   return bdmRC;
}

//===================================================================
//! Extended process for connecting to the target
//!
//! This procedure will prompt the user to
//! cycle the target power supply if necessary.  The
//! BKGD line will be held low while this is occurring.
//!
//! @param retryMode   How hard to retry \n
//!     The following are silent retries: \n
//!       retryNever      - give up after basic attempt, target state not affected \n
//!      +retryByReset    - quietly retry after hardware reset (if supported by target and allows debug entry). May be combined with others. \n
//!       retryNotPartial - give up if quietly if device may be secured (BDM_RC_SECURED or BDM_RC_BDM_EN_FAILED) \n
//!      + retryWithInit  - do DSC_Initialise() first
//!     The following is interactive:\n
//!       retryAlways     - retry with dialogue prompt to user \n
//! @return \n
//!     BDM_RC_OK          => OK \n
//!     other              => Error see \ref USBDM_ErrorCode
//!
static USBDM_ErrorCode targetConnect(RetryMode retryMode) {
USBDM_ErrorCode rc;

   print( "   targetConnect(%s)\n", getConnectionRetryName(retryMode) );

   do {
      rc = getBDMStatus(&USBDMStatus);
      if (rc != BDM_RC_OK) {
         break;
      }
#if TARGET == ARM
      rc = USBDM_Connect();
      if (rc != BDM_RC_OK) {
         rc = USBDM_Connect(); // retry
      }
#elif TARGET == MC56F80xx
      if (retryMode & retryWithInit) {
         dscInformation.size = sizeof(dscInfo_t);
         rc = DSC_GetInfo(&dscInformation);
         if (rc != BDM_RC_OK) {
            break;
         }
         rc = DSC_Initialise();
         if (rc != BDM_RC_OK) {
            break;
         }
      }
      rc = DSC_Connect();
      if (rc != BDM_RC_OK) {
         if (retryMode&retryByReset) {
            DSC_TargetReset((TargetMode_t)(RESET_SPECIAL|RESET_DEFAULT));
         }
         rc = DSC_Connect(); // retry
      }
      if (rc != BDM_RC_OK) {
         break;
      }
#else
      rc = USBDM_TargetConnectWithRetry(retryMode);
#endif
   } while (0);
   return rc;
}

//! Open GDI
//!
//! @param dnGdiVersionH
//! @param dnGdiVersionL
//! @param dnArgc
//! @param szArgv
//! @param UdProcessEvents
//!
//!
//! @return \n
//!     DI_OK              => OK \n
//!     DI_ERR_FATAL       => Error see \ref currentErrorString
//!
USBDM_GDI_API
DiReturnT DiGdiOpen ( DiUInt32T      dnGdiVersionH,
                      DiUInt32T      dnGdiVersionL,
                      DiUInt32T      dnArgc,
                      DiConstStringT szArgv[],
                      void (*UdProcessEvents)(void) ) {
unsigned sub;

   usbdm_gdi_dll_open();
   
#if TARGET == MC56F80xx
   DSC_SetLogFile(getLogFileHandle());
#endif

   print("DiGdiOpen(\n"
         "   dnGdiVersionH=0x%X, dnGdiVersionL=0x%X, \n"
         "   dnArgc=%d, szArgv=0x%p, \n"
         "   UdProcessEvents=0x%p"
         ")\n",
         dnGdiVersionH, dnGdiVersionL, dnArgc, szArgv, UdProcessEvents);
   for (sub = 0; sub < dnArgc; sub++) {
      print("argv[%2i]:\'%s\'\n", sub, szArgv[sub]);
   }

   //   ::UdProcessEvents = UdProcessEvents;

#ifdef FLASH_PROGRAMMING
   flashImage = NULL;
#endif

   // No functions available until DiGdiInitIO() is called
   currentError       = DI_ERR_STATE;
   currentErrorString = "GDI Not opened";

   USBDM_ErrorCode rc = USBDM_Init();
   if (rc != BDM_RC_OK)
      return setErrorState(DI_ERR_FATAL, rc);
   else
      return setErrorState(DI_OK);
}

//! Close GDI
//!
//! @param fClose
//!
//!
//! @return \n
//!     DI_OK              => OK \n
//!     DI_ERR_FATAL       => Error see \ref currentErrorString
//!
USBDM_GDI_API
DiReturnT DiGdiClose ( DiBoolT fClose ) {
   closeBDM();
   USBDM_Exit();
   print("DiGdiClose()\n");
   usbdm_gdi_dll_close();
   setErrorState(DI_ERR_STATE, ("GDI Not open"));
#ifdef FLASH_PROGRAMMING
   if (flashImage != NULL) {
      delete flashImage;
      flashImage = NULL;
   }
   if (flashProgrammer != NULL) {
      delete flashProgrammer;
      flashProgrammer = NULL;
   }
#endif
   return DI_OK;
}

//! Get GDI version
//!
//! @param dnGdiVersion
//!
//!
//! @return \n
//!     DI_OK              => OK \n
//!     DI_ERR_FATAL       => Error see \ref currentErrorString
//!
USBDM_GDI_API
DiReturnT DiGdiVersion ( DiUInt32T *dnGdiVersion ) {

   print("DiGdiVersion()\n");
   *dnGdiVersion = USBDM_GDI_INTERFACE_VERSION;
   return setErrorState(DI_OK);
}

//! Get Features Supported by GDI
//!
//! @param pdfFeatures
//!
//!
//! @return \n
//!     DI_OK              => OK \n
//!     DI_ERR_FATAL       => Error see \ref currentErrorString
//!
USBDM_GDI_API
DiReturnT DiGdiGetFeatures ( pDiFeaturesT pdfFeatures ) {

   print("DiGdiGetFeatures()\n");
   *pdfFeatures = diFeatures;
   return setErrorState(DI_OK);
}

//! Set GDI Configuration
//!
//! @param szConfig
//!
//! @return \n
//!     DI_OK              => OK \n
//!     DI_ERR_FATAL       => Error see \ref currentErrorString
//!
USBDM_GDI_API
DiReturnT DiGdiSetConfig ( DiConstStringT szConfig ) {

   print("DiGdiSetConfig() - not implemented\n");
   return setErrorState(DI_OK);
}

//! Does initial target connection with check for secured target.
//! The user will be prompted to mass erase the target if secured.
//!
//! @return \n
//!     DI_OK              => OK \n
//!     DI_ERR_FATAL       => Error see \ref currentErrorString
//!
USBDM_ErrorCode initialConnect(void) {
   USBDM_ErrorCode bdmRc;

   print("initialConnect()\n");
   // Initial connect using all strategies
   bdmRc = targetConnect(initialConnectOptions);

#if (TARGET == MC56F80xx)
   print("initialConnect() - doing DSC_TargetHalt()\n");
   bdmRc = DSC_TargetHalt();
   if (bdmRc != BDM_RC_OK) {
      if (initialConnectOptions&retryByReset) {
         DSC_TargetReset((TargetMode_t)(RESET_SPECIAL|RESET_DEFAULT));
      }
      bdmRc = DSC_TargetHalt(); // retry
   }
#endif

#ifdef FLASH_PROGRAMMING

#if (TARGET == HCS08) || (TARGET == CFV1) || (TARGET == RS08)
    if (bdmRc == BDM_RC_OK) {
       if (flashProgrammer->checkTargetUnSecured() == PROGRAMMING_RC_ERROR_SECURED) {
          bdmRc = BDM_RC_SECURED;
       }
    }
#endif

   if (bdmRc == BDM_RC_SECURED) {
      mtwksDisplayLine("targetConnect(): Target is secured\n");
      int getOkCancel = displayDialogue(
         "Device appears to be secure and may \n"
         "only be programmed after a mass erase \n"
         "which completely erases the device.\n\n"
         "Proceed with Mass erase?",
         "Device is secured",
         wxOK|wxCANCEL|wxOK_DEFAULT|wxICON_INFORMATION);
      if (getOkCancel == wxOK) {
         if (flashProgrammer->massEraseTarget() != PROGRAMMING_RC_OK) {
            mtwksDisplayLine("targetConnect(): Target mass erase failed\n");
         }
         else {
            mtwksDisplayLine("targetConnect(): Target mass erase done\n");
            bdmRc = BDM_RC_OK;
         }
      }
   }
#endif

   return bdmRc;
}

//! Configure I/O System
//!
//! @param pdcCommSetup unused
//!
//! @return \n
//!     DI_OK              => OK \n
//!     DI_ERR_FATAL       => Error see \ref currentErrorString
//!
USBDM_GDI_API
DiReturnT DiGdiInitIO( pDiCommSetupT pdcCommSetup ) {
   USBDM_ErrorCode bdmRc;

   print("DiGdiInitIO(pdcCommSetup = %p)\n", pdcCommSetup);
   if (pdcCommSetup != NULL) {
      print("DiGdiInitIO()\n"
            "pdcCommSetup                   = %p\n"
            "pdcCommSetup->dccType          = %d\n"
            "pdcCommSetup->fCheckConnection = %s\n",
            pdcCommSetup,
            pdcCommSetup->dccType,
            pdcCommSetup->fCheckConnection?"True":"False"
            );
   }
   mtwksDisplayLine("\n"
         "=============================================\n"
         "  USBDM GDI Version %s\n"
         "=============================================\n",
         USBDM_VERSION_STRING);

#if TARGET == MC56F80xx
   DSC_SetLogFile(getLogFileHandle());
#endif
   // Open & Configure BDM
   bdmRc = initialiseBDMInterface();
   if ((bdmRc != BDM_RC_OK)&&(bdmRc != BDM_RC_UNKNOWN_DEVICE)) {
      DiReturnT rc = setErrorState(DI_ERR_COMMUNICATION, bdmRc);
      print("DiGdiInitIO() - Failed - %s\n", currentErrorString);
      return rc;
   }
#ifndef USE_MEE
   // Initial connect is treated differently
   bdmRc = initialConnect();
   if (bdmRc != BDM_RC_OK) {
      DiReturnT rc = setErrorState(DI_ERR_COMMUNICATION, bdmRc);
      print("DiGdiInitIO() - Failed - %s\n", currentErrorString);
      return rc;
   }
#else
   print("DiGdiInitIO() - doing mtwksSetMEE()\n");
   mtwksSetMEE(1);
#endif
   print("DiGdiInitIO() - Completed\n");
   return setErrorState(DI_OK);
}

//! Initialize Register Name/Number Map
//!
//! @param dnEntries
//! @param pdriRegister
//! @param dnProgramCounter
//!
//! @return \n
//!     DI_OK              => OK \n
//!     DI_ERR_FATAL       => Error see \ref currentErrorString
//!
USBDM_GDI_API
DiReturnT DiGdiInitRegisterMap ( DiUInt32T        dnEntries,
                                 DiRegisterInfoT   *pdriRegister,
                                 DiUInt32T         dnProgramCounter ) {
   print("DiGdiInitRegisterMap() - not implemented\n");
   return setErrorState(DI_ERR_NOTSUPPORTED);
}

//! Initialise Memory Space Name/Number Map
//!
//! @param dnEntries
//! @param pdmiMemSpace
//!
//! @return \n
//!     DI_OK              => OK \n
//!     DI_ERR_FATAL       => Error see \ref currentErrorString
//!
USBDM_GDI_API
DiReturnT DiGdiInitMemorySpaceMap ( DiUInt32T            dnEntries,
                                     DiMemorySpaceInfoT   *pdmiMemSpace ) {
   print("DiGdiInitMemorySpaceMap() - not implemented\n");
   return setErrorState(DI_ERR_NOTSUPPORTED);
}

//! 2.2.1.9 Add Callback Procedures
//!
//! @param dcCallbackType
//! @param Callback
//!
//! @return \n
//!     DI_OK              => OK \n
//!     DI_ERR_FATAL       => Error see \ref currentErrorString
//!
USBDM_GDI_API
DiReturnT DiGdiAddCallback ( DiCallbackT dcCallbackType,
                             CallbackF   Callback ) {

	print("DiGdiAddCallback(type=%4.4X, address=%p)\n",
         dcCallbackType, Callback);

   setCallback(dcCallbackType, Callback);

   return setErrorState(DI_OK);
}

//! 2.2.1.10 Cancel GDI Procedure
//!
//!
//! @return \n
//!     DI_ERR_NOTSUPPORTED  => Error see \ref currentErrorString
//!
USBDM_GDI_API
DiReturnT DiGdiCancel ( void ) {

   print("DiGdiCancel() - not implemented\n");
   return setErrorState(DI_ERR_NOTSUPPORTED);
}

//! 2.2.1.11 Synchronize UD
//!
//! @param pfUpdate
//!
//! @return \n
//!     DI_ERR_NOTSUPPORTED  => Error see \ref currentErrorString
//!
USBDM_GDI_API
DiReturnT DiGdiSynchronize ( DiBoolT *pfUpdate ) {

   print("DiGdiSynchronize() - not implemented\n");
   return setErrorState(DI_ERR_NOTSUPPORTED);
}

static DiMenuItemT menuItems[] =
{
/* szMenuTitle  szDiCommand    */
 { "Command 1", "cmd1", },
};

//! 2.2.2.1 Add DI Specific Commands to UD Menu
//!
//! @param pdnNrEntries
//! @param pdmiMenuItem
//!
USBDM_GDI_API
DiReturnT DiDirectAddMenuItem ( DiUInt32T    *pdnNrEntries,
                                 pDiMenuItemT *pdmiMenuItem ) {

   print("DiDirectAddMenuItem()\n");
   *pdnNrEntries = sizeof(menuItems)/sizeof(menuItems[0]);
   *pdmiMenuItem = menuItems;
   return setErrorState(DI_OK);
}

#define MAX_DIRECT_RETURN_STRING_LENGTH (2000)
static char directCommandResult[MAX_DIRECT_RETURN_STRING_LENGTH+1] = "";
static char *directCommandResultPtr  = NULL;

/*! \brief Provides a print function which prints data to DI_DIRECT message buffer
 *
 *  @param format Format and parameters as for printf()
 */
void setDirectCommandString(const char *format, ...) {
   va_list list;

   if (format == NULL) {
      directCommandResultPtr = NULL;
      return;
   }
   va_start(list, format);
   vsnprintf(directCommandResult, MAX_DIRECT_RETURN_STRING_LENGTH, format, list);
   directCommandResultPtr = directCommandResult;
   va_end(list);
}

//! 2.2.2.2 Send Native Command to DI
//!
//! @param pszCommand
//! @param pduiUserInfo
//!
//! @return \n
//!     DI_ERR_NOTSUPPORTED  => Error see \ref currentErrorString
//!
USBDM_GDI_API
DiReturnT DiDirectCommand ( DiConstStringT  pszCommand,
                            DiUserInfoT     *pduiUserInfo ) {

   print("DiDirectCommand(%s, %p)\n", pszCommand, pduiUserInfo);
   return setErrorState(DI_ERR_NOTSUPPORTED);
}

//! 2.2.2.3 Read String from DI
//!
//! @param dnNrToRead
//! @param pcBuffer
//! @param dnNrRead
//!
//! @return \n
//!     DI_ERR_NOTSUPPORTED  => Error see \ref currentErrorString
//!
USBDM_GDI_API
DiReturnT DiDirectReadNoWait ( DiUInt32T  dnNrToRead,
                               char        *pcBuffer,
                               DiUInt32T   *dnNrRead ) {

   print("DiDirectReadNoWait() - not implemented\n");
   *pcBuffer = '\0';
   *dnNrRead = 0;
   return setErrorState(DI_ERR_NOTSUPPORTED);
}

//! 2.2.3.1 Retrieve Error Message
//!
//! @param pszErrorMsg
//!
USBDM_GDI_API
void DiErrorGetMessage ( DiConstStringT *pszErrorMsg ) {

   *pszErrorMsg = getGDIErrorMessage();

   if (pszErrorMsg == NULL) {
      print("DiErrorGetMessage() => not set\n");
   }
   else {
      print("DiErrorGetMessage() => %s\n", *pszErrorMsg);
   }
   mtwksDisplayLine("DiErrorGetMessage() => %s\n", getGDIErrorMessage());

   // Clear all errors apart from fatal
   if (currentError != DI_ERR_FATAL) {
      setErrorState(DI_OK);
   }
}

//! 2.2.4.1 Configure Target Memory
//!
//! @param dmmMap
//!
//! @return \n
//!     DI_ERR_NOTSUPPORTED  => Error see \ref currentErrorString
//!
USBDM_GDI_API
DiReturnT DiMemorySetMap ( DiMemoryMapT dmmMap ) {

   print("DiMemorySetMap() - not implemented\n");
   return setErrorState(DI_ERR_NOTSUPPORTED);
}

//! 2.2.4.2 Retrieve Target Memory Configuration
//!
//! @param pdmmMap
//!
//! @return \n
//!     DI_ERR_NOTSUPPORTED  => Error see \ref currentErrorString
//!
USBDM_GDI_API
DiReturnT DiMemoryGetMap ( DiMemoryMapT *pdmmMap ) {

   print("DiMemoryGetMap() - not implemented\n");
   return setErrorState(DI_ERR_NOTSUPPORTED);
}

//! 2.2.4.3 Configure CPU to Memory Interface
//!
//! @param dmtcMap
//!
//! @return \n
//!     DI_ERR_NOTSUPPORTED  => Error see \ref currentErrorString
//!
USBDM_GDI_API
DiReturnT DiMemorySetCpuMap ( DiMemoryToCpuT dmtcMap ) {

   print("DiMemorySetCpuMap() - not implemented\n");
   return setErrorState(DI_ERR_NOTSUPPORTED);
}

//! 2.2.4.4 Retrieve CPU to Memory Interface
//!
//! @param pdmtcMap
//!
//! @return \n
//!     DI_ERR_NOTSUPPORTED  => Error see \ref currentErrorString
//!
USBDM_GDI_API
DiReturnT DiMemoryGetCpuMap ( DiMemoryToCpuT *pdmtcMap ) {

   print("DiMemoryGetCpuMap() - not implemented\n");
   return setErrorState(DI_ERR_NOTSUPPORTED);
}

#ifdef FLASH_PROGRAMMING

DiReturnT programTargetFlash(void) {

   USBDM_ErrorCode rc;

   print("programTargetFlash() - Commencing\n");

   // Set BDM options for programming
   USBDM_SetExtendedOptions(&bdmProgrammingOptions);

#if TARGET == ARM
   rc = USBDM_TargetReset((TargetMode_t)(RESET_DEFAULT|RESET_SPECIAL));
#elif TARGET == MC56F80xx
   DSC_Initialise();
   rc = DSC_TargetReset((TargetMode_t)(RESET_DEFAULT|RESET_SPECIAL));
#else
   rc = USBDM_TargetReset((TargetMode_t)(RESET_DEFAULT|RESET_SPECIAL));
#endif
   if (rc != BDM_RC_OK) {
      return setErrorState(DI_ERR_FATAL, rc);
   }
#if (TARGET != ARM) && (TARGET != MC56F80xx)
   rc = USBDM_Connect();
   if (rc != BDM_RC_OK) {
      return setErrorState(DI_ERR_FATAL, rc);
   }
#endif

   if (flashProgrammer == NULL) {
      mtwksDisplayLine("programTargetFlash() - flashProgrammer NULL\n");
      return setErrorState(DI_ERR_FATAL, "flashProgrammer NULL!");
   }
   USBDM_ErrorCode flashRC = flashProgrammer->confirmSDID();

   // ToDo - check if should just fail on RS08/HCS08 as SDID should always be readable
   if (flashRC == PROGRAMMING_RC_ERROR_WRONG_SDID) {
      // Target is wrong device
      displayDialogue("Selected device doesn't agree with connected device.",
                      "Wrong Device",
                      wxOK|wxICON_ERROR);
      return setErrorState(DI_ERR_FATAL, flashRC);
   }
   if (flashRC != PROGRAMMING_RC_OK) {
      // Failed to read target type - may  be secured
      int getYesNo = displayDialogue("Cannot confirm target device type.\n"
                                     "Device may be secured.\n\n"
                                     "Continue?",
                                     "Wrong Device",
                                  wxYES_NO|wxYES_DEFAULT|wxICON_WARNING);
      if (getYesNo != wxYES)
         return setErrorState(DI_ERR_FATAL, flashRC);
   }
   // Program target
   flashRC = flashProgrammer->programFlash(flashImage, NULL, true);
   if (flashRC != PROGRAMMING_RC_OK) {
      return setErrorState(DI_ERR_FATAL, flashRC);
   }
   uint16_t trimValue = deviceOptions.getClockTrimValue();
   if (trimValue != 0) {
      mtwksDisplayLine("Info: Device Trim Value = %2.2X.%1X\n", trimValue>>1, trimValue&0x01);
   }
   return DI_OK;
}
#endif

//! 2.2.5.1 Download Application
//!
//! @param fUseAuxiliaryPath
//! @param ddcDownloadCommand
//! @param ddfDownloadFormat
//! @param pchBuffer
//!
//! @note DSC/CFVx GDI doesn't support flash programming
//!
#ifndef FLASH_PROGRAMMING
USBDM_GDI_API
DiReturnT DiMemoryDownload ( DiBoolT            fUseAuxiliaryPath,
                             DiDownloadCommandT ddcDownloadCommand,
                             DiDownloadFormatT  ddfDownloadFormat,
                             char               *pchBuffer ) {
   return setErrorState(DI_ERR_NOTSUPPORTED);
}
#else
USBDM_GDI_API
DiReturnT DiMemoryDownload ( DiBoolT            fUseAuxiliaryPath,
                             DiDownloadCommandT ddcDownloadCommand,
                             DiDownloadFormatT  ddfDownloadFormat,
                             char               *pchBuffer ) {
   const char *command[] = {"DI_DNLD_INIT","DI_DNLD_WRITE","DI_DNLD_TERMINATE","DI_DNLD_ABORT"};
   U32c address(ddfDownloadFormat.daAddress);
   DiReturnT rc;
   print("DiMemoryDownload() - aux=%s, comm=%s, format=0x%X, addr=0x%4.4X, size 0x%X\n",
         fUseAuxiliaryPath?"T":"F",
         command[ddcDownloadCommand&0x03],
         ddfDownloadFormat.dafAbsFileFormat,
         (uint32_t)address,
         ddfDownloadFormat.dnBufferSize);

   CHECK_ERROR_STATE();

   if (!programmingSupported) {
      return setErrorState(DI_ERR_NOTSUPPORTED);
   }
   if ((ddfDownloadFormat.dafAbsFileFormat & (DI_ABSF_FILENAME|DI_ABSF_BINARY)) == 0) {
      print("DiMemoryDownload() - unsupported format %X\n",
            ddfDownloadFormat.dafAbsFileFormat);
      return setErrorState(DI_ERR_NOTSUPPORTED);
   }
   switch (ddcDownloadCommand) {
      case DI_DNLD_INIT:
         mtwksDisplayLine("DiMemoryDownload() - DI_DNLD_INIT - New memory image opened\n");
         print("DiMemoryDownload() - DI_DNLD_INIT - New memory image opened\n");
         // Create flash image to contain any changes to target memory
         flashImage = new FlashImage();
         return setErrorState(DI_OK);

      case DI_DNLD_TERMINATE:
         rc = DI_OK;
         if ((flashImage != NULL) && (!flashImage->isEmpty())) {
            mtwksDisplayLine("DiMemoryDownload() - DI_DNLD_TERMINATE - Programming memory image...\n");
            print("DiMemoryDownload() - DI_DNLD_TERMINATE - Programming memory image\n");
            rc = programTargetFlash();
            mtwksDisplayLine("DiMemoryDownload() - DI_DNLD_TERMINATE - Programming complete, rc = %d\n", rc);
         }
         else {
            mtwksDisplayLine("DiMemoryDownload() - DI_DNLD_TERMINATE - Memory image is empty - Flash programming skipped\n");
            print("DiMemoryDownload() - DI_DNLD_TERMINATE - Memory image is empty - Flash programming skipped\n");
         }
         delete flashImage;
         flashImage = NULL;
         if (rc != DI_OK) {
            return rc;
         }
         // Restore original options
         USBDM_SetExtendedOptions(&bdmOptions);
         mtwksDisplayLine("DiMemoryDownload() - DI_DNLD_TERMINATE - Resetting target\n");
         print("DiMemoryDownload() -  Resetting target\n");
#if TARGET == MC56F80xx
         DSC_TargetReset((TargetMode_t)(RESET_DEFAULT|RESET_SPECIAL));
         DSC_Connect();
#else
         USBDM_TargetReset((TargetMode_t)(RESET_DEFAULT|RESET_SPECIAL));
         USBDM_Connect();
#endif
         return setErrorState(DI_OK);
      case DI_DNLD_WRITE:
         print("DI_DNLD_WRITE\n");
         return setErrorState(DI_ERR_NOTSUPPORTED);
      case DI_DNLD_ABORT:
         print("DI_DNLD_ABORT\n");
         delete flashImage;
         flashImage = NULL;
         break;
   }
   return setErrorState(DI_OK);
}
#endif

// This is largest size memory read/write block passed to USBDM layer
// Larger sizes are subdivided - but this is unlikely to occur.
#define MAX_BLOCK_SIZE (0x1000)
#if (MAX_BLOCK_SIZE % 4) != 0
#error "MAX_BLOCK_SIZE must be a multiple of 4"
#endif

static uint8_t memoryReadWriteBuffer[MAX_BLOCK_SIZE];

#if TARGET == ARM
//! Write data to target memory
//! ARM Memory writes are decomposed into a minimal sequence of the largest aligned object writes
//!
//! @param memorySpace = Size of data elements (1/2/4 bytes)
//! @param byteCount   = Number of _bytes_ to transfer
//! @param address     = Memory address
//! @param buffer      = Ptr to block of data to write
//!
//! @return error code \n
//!     BDM_RC_OK    => OK \n
//!     other        => Error code - see \ref USBDM_ErrorCode
//!
static USBDM_ErrorCode ARM_WriteMemory(MemorySpace_t memorySpace, int byteCount, int address, uint8_t *buffer) {
   USBDM_ErrorCode rc = BDM_RC_OK;
   int index = 0;
   if ((address&0x01) != 0) {
      // Odd leading byte
      rc = USBDM_WriteMemory(MS_Byte, 1, address, buffer+index);
      address++;
      index++;
      byteCount--;
   }
   if ((rc == BDM_RC_OK) && ((address&0x02) != 0) && (byteCount >= 2)) {
      // Odd leading word
      rc = USBDM_WriteMemory(MS_Word, 2, address, buffer+index);
      address      += 2;
      index        += 2;
      byteCount    -= 2;
   }
   if ((rc == BDM_RC_OK) && (byteCount >= 4)) {
      // Bulk longwords
      int longWordCount = byteCount&~0x3;
      rc = USBDM_WriteMemory(MS_Long, longWordCount, address, buffer+index);
      address += longWordCount;
      index        += longWordCount;
      byteCount    -= longWordCount;
   }
   if ((rc == BDM_RC_OK) && (byteCount >= 2)) {
      // Odd trailing word
      rc = USBDM_WriteMemory(MS_Word, 2, address, buffer+index);
      address      += 2;
      index        += 2;
      byteCount    -= 2;
   }
   if ((rc == BDM_RC_OK) && (byteCount >= 1)) {
      // Odd trailing byte
      rc = USBDM_WriteMemory(MS_Byte, 1, address, buffer+index);
      address++;
      index++;
      byteCount--;
   }
   if ((rc == BDM_RC_OK) && (byteCount > 0)) {
      rc = PROGRAMMING_RC_ERROR_INTERNAL_CHECK_FAILED;
   }
   return rc;
}
#endif

//! 2.2.5.2 Write Data to Target Memory
//!
//! @param daTarget        Target memory address
//! @param pdmvBuffer      Data to write (LittleEndian on DSC)
//! @param dnBufferItems   Number of units to write
//!
USBDM_GDI_API
DiReturnT DiMemoryWrite ( DiAddrT       daTarget,
                          DiMemValueT  *pdmvBuffer,
                          DiUInt32T     dnBufferItems ) {
uint32_t        address      = (U32c)daTarget;   // Load address
MemorySpace_t   memorySpace;                     // Memory space & size
int             organization;                    // For display
uint32_t        endAddress;                      // End address

   CHECK_ERROR_STATE();

   switch(daTarget.dmsMemSpace) {
      case 1 :
         memorySpace  = MS_Byte;
         organization = BYTE_DISPLAY|BYTE_ADDRESS;
         endAddress   = address + dnBufferItems - 1;
         break;
      case 2 :
         memorySpace  = MS_Word;
         organization = WORD_DISPLAY|BYTE_ADDRESS;
         endAddress   = address + 2*dnBufferItems - 1;
         break;
      case 4 :
         memorySpace  = MS_Long;
         organization = LONG_DISPLAY|BYTE_ADDRESS;
         endAddress   = address + 4*dnBufferItems - 1;
         break;
      default :
         print("DiMemoryWrite(daTarget.dmsMemSpace=0x%X, address=0x%4.4X, dnBufferItems=%d)\n"
               "Error - Unexpected daTarget.dmsMemSpace value\n",
               daTarget.dmsMemSpace,
               (uint32_t)address,
			      dnBufferItems);
         return setErrorState(DI_ERR_NOTSUPPORTED, "Unknown memory space");
   }
   print("DiMemoryWrite(daTarget.dmsMemSpace=%2X, dnBufferItems=%3d, [0x%06X...0x%06X])\n",
         daTarget.dmsMemSpace,
         dnBufferItems,
         address,
         endAddress);

#if defined(LOG) && 0
   print("DiMemoryWrite                                              0011223344556677\n"
         "daTarget.dmsMemSpace = %X, daTarget.dlaLinAddress.v.val = 0x%02X%02X%02X%02X%02X%02X%02X%02X,"
         " dnBufferItems = %d\n",
         daTarget.dmsMemSpace,
         daTarget.dlaLinAddress.v.val[0],daTarget.dlaLinAddress.v.val[1],
         daTarget.dlaLinAddress.v.val[2],daTarget.dlaLinAddress.v.val[3],
         daTarget.dlaLinAddress.v.val[4],daTarget.dlaLinAddress.v.val[5],
         daTarget.dlaLinAddress.v.val[6],daTarget.dlaLinAddress.v.val[7],
         dnBufferItems);

   for (unsigned t=0; t<dnBufferItems; t++) {
   print("DiMemoryWrite                  0011223344556677\n"
         "pdmvBuffer[%2d].dmValue.val = 0x%02X%02X%02X%02X%02X%02X%02X%02X\n",
         t,
         pdmvBuffer[t].dmValue.val[0],pdmvBuffer[t].dmValue.val[1],
         pdmvBuffer[t].dmValue.val[2],pdmvBuffer[t].dmValue.val[3],
         pdmvBuffer[t].dmValue.val[4],pdmvBuffer[t].dmValue.val[5],
         pdmvBuffer[t].dmValue.val[6],pdmvBuffer[t].dmValue.val[7]
         );
   if (t >= 4)
      break;
   }
#endif
   uint32_t offset = 0;
   while (dnBufferItems>0) {
      // Copy a block of data to memoryReadWriteBuffer
      uint32_t writeAddress = address;

      // Copy until buffer full or complete
      unsigned sub = 0;
      while ((sub<sizeof(memoryReadWriteBuffer)) && (dnBufferItems>0)) {
         U32c value(pdmvBuffer[offset++]);
         dnBufferItems--;
         // Unpack items
         switch (memorySpace&MS_SIZE) {
            case MS_Byte :
               memoryReadWriteBuffer[sub++] = value[3];
               address += 1; // Advance address
               break;
            case MS_Word :
               memoryReadWriteBuffer[sub++] = value[2];
               memoryReadWriteBuffer[sub++] = value[3];
               address += 2; // Advance address
               break;
            case MS_Long :
               memoryReadWriteBuffer[sub++] = value[0];
               memoryReadWriteBuffer[sub++] = value[1];
               memoryReadWriteBuffer[sub++] = value[2];
               memoryReadWriteBuffer[sub++] = value[3];
               address += 4; // Advance address
               break;
         }
      }
      printDump(memoryReadWriteBuffer, sub, address, organization);

      bool writeDone = false;
#ifdef FLASH_PROGRAMMING
      if (flashImage != NULL) {
         // Write data to programming buffer
         print("DiMemoryWrite() - loadDataBytes(address=0x%06X, size=0x%04X)\n", writeAddress, sub);
         printDump(memoryReadWriteBuffer,sub,writeAddress,memorySpace&MS_SIZE);
         USBDM_ErrorCode rc = flashImage->loadDataBytes(sub, writeAddress, memoryReadWriteBuffer, true);
         writeDone = true;
         if (rc != BDM_RC_OK) {
            return setErrorState(DI_ERR_FATAL, rc);
         }
      }
#endif
      if (!writeDone) {
         // Write data directly to memory
         USBDM_ErrorCode rc = BDM_RC_OK;
#if TARGET == ARM
         rc = ARM_WriteMemory(memorySpace, sub, writeAddress, memoryReadWriteBuffer);
#elif TARGET == MC56F80xx
         rc = DSC_WriteMemory(memorySpace, sub, writeAddress, memoryReadWriteBuffer);
#else
         rc = USBDM_WriteMemory(memorySpace, sub, writeAddress, memoryReadWriteBuffer);
#endif
         if (rc != BDM_RC_OK) {
            return setErrorState(DI_ERR_NONFATAL, rc);
         }
      }
   }
   return setErrorState(DI_OK);
}

#if TARGET == ARM
//! Read data from target memory
//! ARM Memory reads are decomposed into a minimal sequence of the largest aligned object reads
//!
//! @param memorySpace = Size of data (1/2/4 bytes)
//! @param byteCount   = Number of bytes to transfer
//! @param address     = Memory address
//! @param buffer      = Where to place data
//!
//! @return error code \n
//!     BDM_RC_OK    => OK \n
//!     other        => Error code - see \ref USBDM_ErrorCode
//!
static USBDM_ErrorCode ARM_ReadMemory(MemorySpace_t memorySpace, int byteCount, int address, uint8_t *buffer) {
   USBDM_ErrorCode rc = BDM_RC_OK;
   int index = 0;
   if ((address&0x01) != 0) {
      // Odd leading byte
      rc = USBDM_ReadMemory(MS_Byte, 1, address, buffer+index);
      address++;
      index++;
      byteCount--;
   }
   if ((rc == BDM_RC_OK) && ((address&0x02) != 0) && (byteCount >= 2)) {
      // Odd leading word
      rc = USBDM_ReadMemory(MS_Word, 2, address, buffer+index);
      address   += 2;
      index     += 2;
      byteCount -= 2;
   }
   if ((rc == BDM_RC_OK) && (byteCount >= 4)) {
      // Bulk longwords
      int longWordCount = byteCount&~0x3;
      rc = USBDM_ReadMemory(MS_Long, longWordCount, address, buffer+index);
      address   += longWordCount;
      index     += longWordCount;
      byteCount -= longWordCount;
   }
   if ((rc == BDM_RC_OK) && (byteCount >= 2)) {
      // Odd trailing word
      rc = USBDM_ReadMemory(MS_Word, 2, address, buffer+index);
      address   += 2;
      index     += 2;
      byteCount -= 2;
   }
   if ((rc == BDM_RC_OK) && (byteCount >= 1)) {
      // Odd trailing byte
      rc = USBDM_ReadMemory(MS_Byte, 1, address, buffer+index);
      address++;
      index++;
      byteCount--;
   }
   if ((rc == BDM_RC_OK) && (byteCount > 0)) {
      rc = PROGRAMMING_RC_ERROR_INTERNAL_CHECK_FAILED;
   }
   return rc;
}
#endif

//! 2.2.5.3 Read Data from Target Memory
//!
//! @param daTarget
//! @param pdmvBuffer
//! @param dnBufferItems
//!
//! @note On DSC the daTarget is a word address
//!
USBDM_GDI_API
DiReturnT DiMemoryRead ( DiAddrT       daTarget,
                         DiMemValueT   *pdmvBuffer,
                         DiUInt32T     dnBufferItems ) {
uint32_t        address      = (U32c)daTarget;   // Load address
MemorySpace_t   memorySpace;                     // Memory space & size
uint32_t        endAddress;                      // End address
int             organization;

   switch(daTarget.dmsMemSpace) {
      case 1 : // byte
         memorySpace  = MS_Byte;
         organization = BYTE_DISPLAY|BYTE_ADDRESS;
         endAddress = address + 1*dnBufferItems - 1;
         break;
      case 2 : // word
         memorySpace  = MS_Word;
         organization = WORD_DISPLAY|BYTE_ADDRESS;
         endAddress = address + 2*dnBufferItems - 1;
         break;
      case 4 : // Long
         memorySpace  = MS_Long;
         organization = LONG_DISPLAY|BYTE_ADDRESS;
         endAddress = address + 4*dnBufferItems - 1;
         break;
      default :
         print("DiMemoryRead(daTarget.dmsMemSpace=0x%X, address=0x%4.4X, dnBufferItems=%d)\n"
               "Error - Unexpected daTarget.dmsMemSpace value\n",
               daTarget.dmsMemSpace,
               (uint32_t)address,
               dnBufferItems);
         return setErrorState(DI_ERR_NOTSUPPORTED, "Unknown memory space");
   }
   print("DiMemoryRead(daTarget.dmsMemSpace=%X, dnBufferItems=%d, [0x%06X...0x%06X])\n",
         daTarget.dmsMemSpace,
         dnBufferItems,
         address,
         endAddress);

   CHECK_ERROR_STATE();

   unsigned offset            = 0;
   while (dnBufferItems>0) {
      int blockSize = dnBufferItems*(memorySpace&MS_SIZE);
      if (blockSize > sizeof(memoryReadWriteBuffer)) {
         blockSize = sizeof(memoryReadWriteBuffer);
      }
USBDM_ErrorCode rc = BDM_RC_OK;
#if TARGET == ARM
      rc = ARM_ReadMemory(memorySpace, blockSize, address, memoryReadWriteBuffer);
#elif TARGET == MC56F80xx
      rc = DSC_ReadMemory(memorySpace, blockSize, address, memoryReadWriteBuffer);
#else
      rc = USBDM_ReadMemory(memorySpace, blockSize, address, memoryReadWriteBuffer);
#endif		 
      if (rc != BDM_RC_OK) {
         print("DiMemoryRead(...) - Failed, rc= %s\n", USBDM_GetErrorString(rc));
         return setErrorState(DI_ERR_NONFATAL, rc);
      }
      print("DiMemoryRead(...) - Result\n");
      printDump(memoryReadWriteBuffer, blockSize, address);

      // Copy until buffer full or complete
      unsigned sub = 0;
      while (sub<blockSize) {
         uint8_t v1=0,v2=0,v3=0,v4=0;
         switch (memorySpace&MS_SIZE) {
         case MS_Byte :
            v4 = memoryReadWriteBuffer[sub++];
            address += 1; // Increment address
            break;
         case MS_Word :
            v3 = memoryReadWriteBuffer[sub++];
            v4 = memoryReadWriteBuffer[sub++];
            address += 2; // Increment address
            break;
         case MS_Long :
            v1 = memoryReadWriteBuffer[sub++];
            v2 = memoryReadWriteBuffer[sub++];
            v3 = memoryReadWriteBuffer[sub++];
            v4 = memoryReadWriteBuffer[sub++];
            address += 4; // Increment address
            break;
         }
         // Pack item
         pdmvBuffer[offset++] = (U32c)((v1<<24)+(v2<<16)+(v3<<8)+v4);
         dnBufferItems--;
      }
   }
   return setErrorState(DI_OK);
}

#if TARGET == ARM
// ARM Register numbers used by Codewarrior
//
#define arm_RegPRIMASK 19
#define arm_RegFAULTMASK  20
#define arm_RegBASEPRI 21
#define arm_RegCONTROL 22
#endif

//! 2.2.6.1 Write Value to Register
//!
//! @param dnRegNumber
//! @param drvValue
//!
USBDM_GDI_API
DiReturnT DiRegisterWrite ( DiUInt32T        dnRegNumber,
                            DiRegisterValueT drvValue ) {
   U32c  value(drvValue);
   USBDM_ErrorCode rc = BDM_RC_OK;
   unsigned long hxValue= 0;

   print("DiRegisterWrite(0x%X(%d) <= 0x%08X)\n", dnRegNumber, dnRegNumber, (uint32_t)value);

   CHECK_ERROR_STATE();

   // H & X are a special cases that require a read of HX before write
   if ((dnRegNumber == 3)||(dnRegNumber == 4)) { // X or H
      rc = USBDM_ReadReg(HCS08_RegHX, &hxValue);
      if (rc != BDM_RC_OK) {
         return setErrorState(DI_ERR_NONFATAL, rc);
      }
      if (dnRegNumber == 4) { // H
         value = (hxValue&0x00FFU)+((value<<8)&0xFF00U);
      }
      else { // X
         value = (hxValue&0xFF00U)+(value&0x00FFU);
      }
   }
   switch (dnRegNumber) {
      case 0   : /*  PC */ rc = USBDM_WriteReg(HCS08_RegPC,  value); break;
      case 1   : /*  SP */ rc = USBDM_WriteReg(HCS08_RegSP,  value); break;
      case 2   : /*   A */ rc = USBDM_WriteReg(HCS08_RegA,   value); break;
      case 3   : /*   X */ rc = USBDM_WriteReg(HCS08_RegHX,  value); break;
      case 4   : /*   H */ rc = USBDM_WriteReg(HCS08_RegHX,  value); break;
      case 5   : /* CCR */ rc = USBDM_WriteReg(HCS08_RegCCR, value); break;
      default  : /*   ? */ return setErrorState(DI_ERR_PARAM, ("Illegal register identifier"));
   }
   if (rc != BDM_RC_OK) {
//      print("DiRegisterWrite(0x%X,%s) Failed, reason= %s\n",
//            dnRegNumber, DSC_GetRegisterName(regNum), USBDM_GetErrorString(rc));
      return setErrorState(DI_ERR_NONFATAL, rc);
   }
   return setErrorState(DI_OK);
}

//! 2.2.6.2 Read Value from Register
//!
//! @param dnRegNumber
//! @param drvValue
//!
USBDM_GDI_API
DiReturnT DiRegisterRead ( DiUInt32T         dnRegNumber,
                           pDiRegisterValueT drvValue ) {
unsigned long value = 0xDEADBEEF;
USBDM_ErrorCode rc = BDM_RC_OK;

   print("DiRegisterRead(0x%X(%d))\n", dnRegNumber, dnRegNumber);

   CHECK_ERROR_STATE();

   switch (dnRegNumber) {
      case 0   : /*  PC */ rc = USBDM_ReadReg(HCS08_RegPC,  &value); break;
      case 1   : /*  SP */ rc = USBDM_ReadReg(HCS08_RegSP,  &value); break;
      case 2   : /*   A */ rc = USBDM_ReadReg(HCS08_RegA,   &value); break;
      case 3   : /*   X */ rc = USBDM_ReadReg(HCS08_RegHX,  &value);
                           value  &= 0xFF; // X
                           break;
      case 4   : /*   H */ rc = USBDM_ReadReg(HCS08_RegHX,  &value);
                           value  = (value>>8) & 0xFF; // H
                           break;
      case 5   : /* CCR */ rc = USBDM_ReadReg(HCS08_RegCCR, &value); break;
      default  : /*   ? */ return setErrorState(DI_ERR_PARAM, ("Illegal register identifier"));
   }

   if (rc != BDM_RC_OK) {
      print("DiRegisterRead(0x%X) => error\n", dnRegNumber);
      return setErrorState(DI_ERR_NONFATAL, rc);
   }
   *drvValue = (U32c)value;
//   print("DiRegisterRead(0x%X(%d) => 0x%08X)\n", dnRegNumber, dnRegNumber, value);
   return setErrorState(DI_OK);
}

//! 2.2.6.3 Create Register Class
//!
//! @param pdnRegClassId
//! @param pdnRegisterId
//! @param dnRegisterIdEntries
//!
USBDM_GDI_API
DiReturnT DiRegisterClassCreate ( DiUInt32T *pdnRegClassId,
                                  DiUInt32T *pdnRegisterId,
                                  DiUInt32T dnRegisterIdEntries ) {

   print("DiRegisterClassCreate() - not implemented\n");
   return setErrorState(DI_ERR_NOTSUPPORTED);
}

//! 2.2.6.4 Delete Register Class
//!
//! @param dnRegClassId
//!
USBDM_GDI_API
DiReturnT DiRegisterClassDelete ( DiUInt32T dnRegClassId ) {

   print("DiRegisterClassDelete() - not implemented\n");
   return setErrorState(DI_ERR_NOTSUPPORTED);
}


//! 2.2.6.5 Write Value to Register Class
//!
//! @param dnRegClassId
//! @param pdrvClassValue
//!
USBDM_GDI_API
DiReturnT DiRegisterClassWrite ( DiUInt32T         dnRegClassId,
                                  DiRegisterValueT  *pdrvClassValue ) {

   print("DiRegisterClassWrite() - not implemented\n");
   return setErrorState(DI_ERR_NOTSUPPORTED);
}

//! 2.2.6.6 Read Value from Register Class
//!
//! @param dnRegClassId
//! @param pdrvClassValue
//!
USBDM_GDI_API
DiReturnT DiRegisterClassRead ( DiUInt32T          dnRegClassId,
                                 DiRegisterValueT   *pdrvClassValue ) {

   print("DiRegisterClassRead() - not implemented\n");
   return setErrorState(DI_ERR_NOTSUPPORTED);
}

static uint32_t  currentBreakPointAddress;
static DiUInt32T breakpointId = 0; // 0 => no breakpoint set

//!  2.2.7.1 Set Breakpoint
//!
//! @param pdnBreakpointId
//! @param dbBreakpoint
//!
USBDM_GDI_API
DiReturnT DiBreakpointSet ( DiBpResultT *pdnBreakpointId,
                             DiBpT        dbBreakpoint ) {

   unsigned long bdmscrValue;
   U32c bkptAddress;
   unsigned long breakpointModifier = HC08_BDCSCR_FTS;

   CHECK_ERROR_STATE();

   if (dbBreakpoint.dbtBpType & DI_BPT_EXECUTE) {
      // Execute breakpoint
      bkptAddress        = dbBreakpoint.u.exe.daBp;
      breakpointModifier = 0;
   }
   else if (dbBreakpoint.dbtBpType & (DI_BPT_READ|DI_BPT_WRITE|DI_BPT_VALUE)) {
      // Data read/write bkpt
      bkptAddress = dbBreakpoint.u.rwv.daBp;
   }
   else
      return setErrorState(DI_ERR_PARAM, ("Illegal breakpoint type"));

   // Can only support 1 breakpoint
   if (breakpointId != 0) {
      print("DiBreakpointSet(0x%4X) - Too many breakpoints\n", (uint32_t)bkptAddress);
      return setErrorState(DI_ERR_PARAM, ("Too many breakpoints"));
   }

   breakpointId = 1;

   USBDM_WriteDReg(HCS08_DRegBKPT, (uint32_t)bkptAddress);
   currentBreakPointAddress = bkptAddress;
   USBDM_ReadStatusReg(&bdmscrValue);
   USBDM_WriteControlReg(bdmscrValue|HC08_BDCSCR_BKPTEN|breakpointModifier);
   print("DiBreakpointSet(0x%4X, #%d:%s)\n",
         (uint32_t)bkptAddress, breakpointId, breakpointModifier?"E/D":"E");
   pdnBreakpointId->dbBp   = dbBreakpoint;
   pdnBreakpointId->dnBpId = breakpointId;
   return setErrorState(DI_OK);
}

//!  2.2.7.2 Clear a Breakpoint
//!
//! @param dnBreakpointId
//!
USBDM_GDI_API
DiReturnT DiBreakpointClear ( DiUInt32T dnBreakpointId ) {

unsigned long bdmscrValue;

   print("DiBreakpointClear()\n");

   CHECK_ERROR_STATE();

   if (dnBreakpointId != breakpointId)
      return setErrorState(DI_ERR_PARAM, ("Clearing non-existent breakpoint"));

   breakpointId = 0;

   USBDM_ReadStatusReg(&bdmscrValue);
   USBDM_WriteControlReg(bdmscrValue&~(HC08_BDCSCR_BKPTEN|HC08_BDCSCR_FTS));

   return setErrorState(DI_OK);
}

//!  2.2.7.3 Clear All Breakpoints
//!
USBDM_GDI_API
DiReturnT DiBreakpointClearAll ( void ) {

   print("DiBreakpointClearAll()\n");

   CHECK_ERROR_STATE();

   return DiBreakpointClear(breakpointId);
}

//!  2.2.8.1 Reset
//!
USBDM_GDI_API
DiReturnT DiExecResetChild ( void ) {
USBDM_ErrorCode rc;

   print("DiExecResetChild()\n");

   CHECK_ERROR_STATE();

   // ToDo: should implement a more sophisticated strategy?
#if TARGET == MC56F80xx
   rc = DSC_TargetReset((TargetMode_t)(RESET_DEFAULT|RESET_SPECIAL));
   if (rc != BDM_RC_OK) {
      return setErrorState(DI_ERR_NONFATAL, rc);
   }
   rc = DSC_Connect();
#elif TARGET == ARM
   rc = USBDM_TargetReset((TargetMode_t)(RESET_DEFAULT|RESET_SPECIAL));
   if (rc != BDM_RC_OK) {
      rc = USBDM_TargetReset((TargetMode_t)(RESET_HARDWARE|RESET_SPECIAL));
   }
   if (rc != BDM_RC_OK) {
      return setErrorState(DI_ERR_NONFATAL, rc);
   }
   rc = USBDM_Connect();
#elif (TARGET == CFV1) || (TARGET == HCS08) || (TARGET == RS08)
   USBDM_TargetHalt(); // Make sure target is awake - may be sleeping due to STOP/WAIT instruction
   USBDM_TargetReset((TargetMode_t)(RESET_DEFAULT|RESET_SPECIAL));
   rc = targetConnect(initialConnectOptions);
#else
   rc = USBDM_TargetReset((TargetMode_t)(RESET_DEFAULT|RESET_SPECIAL));
   if (rc != BDM_RC_OK) {
      return setErrorState(DI_ERR_NONFATAL, rc);
   }
   rc = USBDM_Connect();
   // Read status to clear reset flag
   USBDMStatus_t dummy;
   USBDM_GetBDMStatus(&dummy);
#endif
   if (rc != BDM_RC_OK) {
      return setErrorState(DI_ERR_NONFATAL, rc);
   }
   // Reset into special mode doesn't correctly set the reset vector on these targets
   // Do manually
#if TARGET == MC56F80xx
   if (pcWritten) {
      DSC_WriteRegister(DSC_RegPC, pcResetValue);
   }
#elif (TARGET == CFV1)
   if (pcWritten) {
      USBDM_WriteCReg(CFV1_CRegPC, pcResetValue);
   }
#elif TARGET == HCS08
   if (pcWritten) {
      USBDM_WriteReg(HCS08_RegPC,pcResetValue);
   }
#endif

#if TARGET == HCS08 && 0
   // Reset into special mode doesn't correctly set the reset vector
   // Do manually
   uint8_t data[10];
   long unsigned int resetVector;
   rc = USBDM_ReadMemory(1,2,0xFFFE,data);
   if (rc != BDM_RC_OK) {
      return setErrorState(DI_ERR_NONFATAL, rc);
   }
   resetVector = (data[0]<<8)+data[1];
   rc = USBDM_WriteReg(HCS08_RegPC,resetVector);
   if (rc != BDM_RC_OK) {
      return setErrorState(DI_ERR_NONFATAL, rc);
   }
#endif
   return setErrorState(DI_OK);
}

//!  2.2.8.2 Execute a Single Step
//!
//! @param dnNrInstructions
//!
USBDM_GDI_API
DiReturnT DiExecSingleStep ( DiUInt32T dnNrInstructions ) {
USBDM_ErrorCode BDMrc;
long unsigned ccrValue;
long unsigned pcValue;
unsigned char currentOpcode;
const int interruptMask = (1<<3);
const int tapOpcode  = 0x84;
const int tpaOpcode  = 0x85;
const int seiOpcode  = 0x9B;
const int cliOpcode  = 0x9A;
const int waitOpcode = 0x8F;
const int rtiOpcode  = 0x80;
const int swiOpcode  = 0x83;
const int stopOpcode = 0x8E;

   print("DiExecSingleStep(%d)\n", dnNrInstructions);

   CHECK_ERROR_STATE();

#if (TARGET == MC56F80xx)
   BDMrc = DSC_TargetStepN(dnNrInstructions);
#else
   if (dnNrInstructions>1) {
      print("DiExecSingleStep() - Only a single step is supported!\n");
      return setErrorState(DI_ERR_PARAM, ("Only a single step is allowed"));
   }
/*
 * Cases to consider when masking interrupts during step
 *
 * +--------+-----------+---------+-----------------------------------------------------+
 * | Opcode | Initial I | Final I | Problem - action                                    |
 * +--------+-----------+---------+-----------------------------------------------------+
 * | ---    |     1     |    X    | None - no action (interrupts already masked)        |
 * +--------+-----------+---------+-----------------------------------------------------+
 * | CLI    |     0     |    ?    | It may be possible for an interrupt to occur,       |
 * | WAIT   |           |         | setting I-flag which is then incorrectly cleared.   |
 * | STOP   |           |         | (I don't think it applies to CLI but be safe.)      |
 * | SWI    |           |         | - don't 'fix' CCR                                   |
 * +--------+-----------+---------+-----------------------------------------------------+
 * | RTI    |     0     |    1    | Contrived but possible situation. I flag            |
 * |        |           |         | incorrectly cleared - don't 'fix' CCR               |
 * +--------+-----------+---------+-----------------------------------------------------+
 * | SEI    |     0     |    1    | The instruction may set I-flag which is then        |
 * | TAP    |     0     |    1    | incorrectly cleared - don't 'fix' CCR               |
 * +--------+-----------+---------+-----------------------------------------------------+
 * | TPA    |     0     |    X    | The wrong value is transferred to A - fix A         |
 * +--------+-----------+---------+-----------------------------------------------------+
 * | ---    |     0     |    0    | CCR change - clear I-flag in new CCR                |
 * +--------+-----------+---------+-----------------------------------------------------+
 */
   if (bdmOptions.maskInterrupts) {
      print("DiExecSingleStep() - checking if interrupt masking needed\n");
      USBDM_ReadReg(HCS08_RegCCR, &ccrValue);
      if ((ccrValue&interruptMask) != 0) {
         // Interrupts already masked - just step
         BDMrc = USBDM_TargetStep();
      }
      else {
         // Mask interrupts
         print("DiExecSingleStep() - masking interrupts\n");
         USBDM_WriteReg(HCS08_RegCCR, ccrValue|interruptMask);
         // Get current instruction opcode
         USBDM_ReadReg(HCS08_RegPC, &pcValue);
         USBDM_ReadMemory(1,1,pcValue,&currentOpcode);
         // Do a step
         BDMrc = USBDM_TargetStep();
         switch(currentOpcode) {
            case cliOpcode  :
            case waitOpcode :
            case seiOpcode  :
            case tapOpcode  :
            case rtiOpcode  :
            case swiOpcode  : // Not ever stepped - treated as subroutine?
            case stopOpcode :
               print("DiExecSingleStep() - skipping CCR restore\n");
               // Don't 'fix' CCR as updated by instruction or int ack
               break;
            case tpaOpcode :
               // Fix A & CCR  (clear I flag)
               print("DiExecSingleStep() - fixing A & CCR reg\n");
               USBDM_WriteReg(HCS08_RegA, ccrValue&~interruptMask);
               USBDM_WriteReg(HCS08_RegCCR, ccrValue&~interruptMask);
               break;
            default :
               // Fix CCR (clear I flag)
               // Unmask interrupts
               print("DiExecSingleStep() - fixing CCR reg\n");
               USBDM_ReadReg(HCS08_RegCCR, &ccrValue);
               USBDM_WriteReg(HCS08_RegCCR, ccrValue&~interruptMask);
               break;
         }
      }
   }
   else
      BDMrc = USBDM_TargetStep();
#endif

   if (BDMrc != BDM_RC_OK) {
      return setErrorState(DI_ERR_NONFATAL, BDMrc);
   }
   return setErrorState(DI_OK);
}

//!  2.2.8.3 Continue Execution Until
//!
//! @param addrUntil
//!
USBDM_GDI_API
DiReturnT DiExecContinueUntil ( DiAddrT addrUntil ) {

   print("DiExecContinueUntil() - not implemented\n");
   return setErrorState(DI_ERR_NOTSUPPORTED);
}

//!  2.2.8.4 Continue Execution
//!
USBDM_GDI_API
DiReturnT DiExecContinue ( void ) {
   USBDM_ErrorCode BDMrc;

   print("DiExecContinue()\n");

   CHECK_ERROR_STATE();

#if TARGET == CFV1
   // Catch Address/Illegal instruction errors as BDM halts
   USBDM_WriteDReg(CFV1_DRegCSR2byte, CFV1_CSR2_COPHR|CFV1_CSR2_IADHR|CFV1_CSR2_IOPHR);
#endif
#if TARGET == CFVx
   // Fix in case actually STOPPED but CW doesn't know it
   USBDM_TargetHalt();
#endif
#if TARGET == MC56F80xx
   BDMrc = DSC_TargetGo();
#else
   BDMrc = USBDM_TargetGo();
   if (BDMrc != BDM_RC_OK) {
      targetConnect(softConnectOptions);
      BDMrc = USBDM_TargetGo();
   }
#endif
   // Ignore BDM_RC_CF_ILLEGAL_COMMAND as may occur when in STOP low-power modes
   if ((BDMrc != BDM_RC_OK) && (BDMrc != BDM_RC_CF_ILLEGAL_COMMAND)) {
      return setErrorState(DI_ERR_NONFATAL, BDMrc);
   }
   return setErrorState(DI_OK);
}

//!  2.2.8.5 Continue Execution in Background
//!
USBDM_GDI_API
DiReturnT DiExecContinueBackground ( void ) {

   print("DiExecContinueBackground() - not implemented\n");
   return setErrorState(DI_ERR_NOTSUPPORTED);
}

//!  2.2.8.6 Get DI Execution/Exit Status
//!
//! @param pdesExitStatus
//!
//! @return \n
//!     DI_OK              => OK \n
//!     DI_ERR_FATAL       => Error see \ref currentErrorString
//!
USBDM_GDI_API
DiReturnT DiExecGetStatus ( pDiExitStatusT pdesExitStatus ) {
   USBDM_ErrorCode BDMrc;
   static DiExitCauseT lastStatus = DI_WAIT_USER;

//   print("DiExecGetStatus()\n");

   // Defaults
   pdesExitStatus->dscCause = DI_WAIT_UNKNOWN;
   pdesExitStatus->dwBpId   = 0x1000400; // bkpt ID?
   pdesExitStatus->szReason = (DiStringT)"unknown state";

// Removed as prevents CW retry strategy
//   CHECK_ERROR_STATE();

   if (bdmOptions.autoReconnect) {
      USBDM_ErrorCode bdmRc = targetConnect(softConnectOptions);

      if (bdmRc != BDM_RC_OK) {
         print("DiExecGetStatus()=> connect failed\n");
         return setErrorState(DI_ERR_COMMUNICATION, bdmRc);
      }
   }
   else {
      USBDM_GetBDMStatus(&USBDMStatus);
   }
//   pdesExitStatus->szReason = (DiStringT)getBDMStatusName(&USBDMStatus);

   if (USBDMStatus.connection_state == SPEED_NO_INFO) {
      print("DiExecGetStatus()=> NO_INFO\n");
      return setErrorState(DI_OK);
//      print("DiExecGetStatus()=>DI_ERR_COMMUNICATION\n");
//      return setErrorState(DI_ERR_NONFATAL, "Connection with target lost");
   }
   if (USBDMStatus.reset_recent == RESET_DETECTED) {
      print("DiExecGetStatus()=>Target has been reset\n");
      mtwksDisplayLine("Target RESET detected\n");
   }
   unsigned long status;
   BDMrc = USBDM_ReadStatusReg(&status);
   if (BDMrc != BDM_RC_OK) {
      print("DiExecGetStatus()=> Status read failed\n");
      return setErrorState(DI_OK);
//      return setErrorState(DI_ERR_NONFATAL, BDMrc);
   }
   if ((status&HC12_BDMSTS_ENBDM) == 0) {
      print("DiExecGetStatus()=> ENBDM=0\n");
      return setErrorState(DI_OK);
//      print("DiExecGetStatus()=>DI_ERR_NONFATAL\n");
//      return setErrorState(DI_ERR_NONFATAL, "Connection with target lost");
   }
   if ((status&HC12_BDMSTS_BDMACT) != 0) {
      // Halted - in debug halted mode
      pdesExitStatus->dscCause = DI_WAIT_MISCELLANEOUS;
      pdesExitStatus->szReason = (DiStringT)"Debug Halted";
      if (lastStatus != pdesExitStatus->dscCause) {
         print("DiExecGetStatus() status change => DI_WAIT_MISCELLANEOUS, (%s)\n",
               pdesExitStatus->szReason);
#if (TARGET==CFV1) && defined(CONVERT_RESETS_TO_EXCEPTIONS)
         // Read-write PC on halt
         // This causes Illegal Operand and Address Errors to be converted from
         // Resets to Exceptions.
         // Without this code the debugger is a bit misleading as it halts at the
         // start of the exception handler but then does the reset on resume!
         unsigned long PCValue;
         USBDM_ReadCReg(CFV1_CRegPC, &PCValue);
         USBDM_WriteCReg(CFV1_CRegPC, PCValue);
#endif
      }
   }
   else if ((status&HC08_BDCSCR_WS) != 0) {
      // Stopped - low power sleep, treated as running
      pdesExitStatus->dscCause = DI_WAIT_RUNNING;
      pdesExitStatus->szReason = (DiStringT)"Target Stopped (Low power)...";
      if (lastStatus != pdesExitStatus->dscCause) {
         print("DiExecGetStatus() status change => DI_WAIT_RUNNING, (%s)\n",
               pdesExitStatus->szReason);
      }
   }
   else {
      // Processor executing
      pdesExitStatus->dscCause = DI_WAIT_RUNNING;
      pdesExitStatus->szReason = (DiStringT)"Running";
      if (lastStatus != pdesExitStatus->dscCause) {
         print("DiExecGetStatus() status change => DI_WAIT_RUNNING, (%s)\n",
               pdesExitStatus->szReason);
      }
   }
   lastStatus = pdesExitStatus->dscCause;
   return setErrorState(DI_OK);
}

//!  2.2.8.7 Stop Execution
//!
USBDM_GDI_API
DiReturnT DiExecStop ( void ) {
   USBDM_ErrorCode BDMrc = BDM_RC_OK;

   print("DiExecStop()\n");

   CHECK_ERROR_STATE();

#if TARGET == ARM
   targetConnect(softConnectOptions);
   BDMrc = USBDM_TargetHalt();
#elif TARGET == MC56F80xx
   targetConnect(softConnectOptions);
   BDMrc = DSC_TargetHalt();
#elif TARGET == CFVx
   targetConnect(softConnectOptions);
   // Coldfire V2 devices are really broken
   // BKPT should wake a sleeping target but doesn't
   // The following retries in the hope that a target interrupt might occur at a convenient moment!
   int retry =10;
   do {
      USBDM_ControlPins(PIN_BKPT_LOW);
      milliSleep(100);
      USBDM_ControlPins(PIN_RELEASE);
      BDMrc = targetConnect(retryNever);
   } while ((BDMrc != BDM_RC_OK) && (retry-->0));
#else
   BDMrc = USBDM_TargetHalt();
   if (BDMrc != BDM_RC_OK) {
      targetConnect(softConnectOptions);
      BDMrc = USBDM_TargetHalt();
   }
#endif
   if (BDMrc != BDM_RC_OK) {
      return setErrorState(DI_ERR_NONFATAL, BDMrc);
   }
   return setErrorState(DI_OK);
}

//!  2.2.9.1 Switch Trace System On/Off
//!
//! @param fOn
//!
USBDM_GDI_API
DiReturnT DiTraceSwitchOn ( DiBoolT fOn ) {

   print("DiTraceSwitchOn() - not implemented\n");
   return setErrorState(DI_ERR_NOTSUPPORTED);
}

//!  2.2.9.2 Get Instruction Trace
//!
//! @param dnNrInstr
//! @param pditInstrTrace
//!
USBDM_GDI_API
DiReturnT DiTraceGetInstructions ( DiUInt32T       dnNrInstr,
                                    pDiInstrTraceT  pditInstrTrace ) {

   print("DiTraceGetInstructions() - not implemented\n");
   return setErrorState(DI_ERR_NOTSUPPORTED);
}

//!  2.2.9.3 Get Raw Trace
//!
//! @param dnNrFrames
//! @param dttTraceType
//! @param PrintRawTrace
//!
USBDM_GDI_API
DiReturnT DiTracePrintRawInfo ( DiUInt32T       dnNrFrames,
                                 DiTraceTypeT    dttTraceType,
                                 PrintRawTraceF  PrintRawTrace ) {

   print("DiTracePrintRawInfo() - not implemented\n");
   return setErrorState(DI_ERR_NOTSUPPORTED);
}

//!  2.2.9.4 Get Number of New Trace Frames
//!
//! @param dttTraceType
//! @param dnNrMaxFrames
//! @param pdnfNewFrames
//!
USBDM_GDI_API
DiReturnT DiTraceGetNrOfNewFrames ( DiTraceTypeT   dttTraceType,
                                     DiUInt32T      dnNrMaxFrames,
                                     pDiNewFramesT  pdnfNewFrames ) {

   print("DiTraceGetNrOfNewFrames() - not implemented\n");
   return setErrorState(DI_ERR_NOTSUPPORTED);
}

//!  2.2.10.1 Switch Coverage On/Off
//!
//! @param fOn
//!
USBDM_GDI_API
DiReturnT DiCoverageSwitchOn ( DiBoolT fOn ) {

   print("DiCoverageSwitchOn() - not implemented\n");
   return setErrorState(DI_ERR_NOTSUPPORTED);
}

//!  2.2.10.2 Get Coverage Information
//!
//! @param daStart
//! @param dnSize
//! @param pdcCoverage
//!
USBDM_GDI_API
DiReturnT DiCoverageGetInfo ( DiAddrT     daStart,
                               DiUInt32T   dnSize,
                               DiCoverageT *pdcCoverage ) {

   print("DiCoverageGetInfo() - not implemented\n");
   return setErrorState(DI_ERR_NOTSUPPORTED);
}

//!  2.2.11.1 Switch Profiling On/Off
//!
//! @param fOn
//!
USBDM_GDI_API
DiReturnT DiProfilingSwitchOn ( DiBoolT fOn ) {

   print("DiProfilingSwitchOn() - not implemented\n");
   return setErrorState(DI_ERR_NOTSUPPORTED);
}

//!  2.2.11.2 Get Profiling Information
//!
//! @param pdpProfile
//!
USBDM_GDI_API
DiReturnT DiProfileGetInfo ( DiProfileT *pdpProfile ) {

   print("DiProfileGetInfo() - not implemented\n");
   return setErrorState(DI_ERR_NOTSUPPORTED);
}

//!  2.2.12.1 Open a State Resource
//!
//! @param pdnStateHandle
//! @param szStateName
//!
USBDM_GDI_API
DiReturnT DiStateOpen ( DiUInt32T      *pdnStateHandle,
                        DiConstStringT  szStateName ) {

   print("DiStateOpen() - not implemented\n");
   return setErrorState(DI_ERR_NOTSUPPORTED);
}

//!  2.2.12.2 Save DI State
//!
//! @param dnStateHandle
//! @param dnIndex
//!
USBDM_GDI_API
DiReturnT DiStateSave ( DiUInt32T dnStateHandle,
                         DiUInt32T dnIndex ) {

   print("DiStateSave() - not implemented\n");
   return setErrorState(DI_ERR_NOTSUPPORTED);
}

//!  2.2.12.3 Restore DI State
//!
//! @param dnStateHandle
//! @param dnIndex
//!
USBDM_GDI_API
DiReturnT DiStateRestore ( DiUInt32T dnStateHandle,
                            DiUInt32T dnIndex ) {

   print("DiStateRestore() - not implemented\n");
   return setErrorState(DI_ERR_NOTSUPPORTED);
}

//!  2.2.12.4 Close a State Resource
//!
//! @param fDelete
//!
USBDM_GDI_API
DiReturnT DiStateClose ( DiBoolT fDelete ) {

   print("DiStateClose() - not implemented\n");
   return setErrorState(DI_ERR_NOTSUPPORTED);
}

//!  2.2.13 Get Acceptable Communication Settings
//!
//! @param dccType
//! @param szAttr
//! @param pszEntries
//! @param pReserved
//!
USBDM_GDI_API
DiReturnT DiCommGetAcceptableSettings ( DiCommChannelT   dccType,
                                        DiConstStringT   szAttr,
                                        DiConstStringT   *pszEntries[],
                                        void             *pReserved ) {
static const unsigned int maxUSBDMDevices = 20;
static const char *options[maxUSBDMDevices+1];
static const char *const possibleOptions[maxUSBDMDevices+1] = {
   "USBDM #1",
   "USBDM #2",
   "USBDM #3",
   "USBDM #4",
   "USBDM #5",
   "USBDM #6",
   "USBDM #7",
   "USBDM #8",
   "USBDM #9",
   "USBDM #10",
   "USBDM #11",
   "USBDM #12",
   "USBDM #13",
   "USBDM #14",
   "USBDM #15",
   "USBDM #16",
   "USBDM #17",
   "USBDM #18",
   "USBDM #19",
   "USBDM #20",
   NULL,
};

//   print("DiCommGetAcceptableSettings() dccType = %x\n", dccType);
//   print("DiCommGetAcceptableSettings() szAttr = \'%s\'\n", szAttr);

   if (dccType == DI_COMM_PARALLEL) {
      unsigned int deviceCount;
      unsigned int index=0;
      USBDM_ErrorCode BDMrc = USBDM_FindDevices(&deviceCount);
      if (BDMrc != BDM_RC_OK)
         return setErrorState(DI_ERR_COMMUNICATION, ("No USBDM Devices found"));
      if (deviceCount>maxUSBDMDevices)
         deviceCount = maxUSBDMDevices;
      for (index=0; index<deviceCount; index++) {
         options[index] = possibleOptions[index];
      }
      options[deviceCount] = NULL;
      print("DiCommGetAcceptableSettings(DI_COMM_PARALLEL) => DI_OK\n");
      *pszEntries = options;
      return setErrorState(DI_OK);
   }
   else {
      print("DiCommGetAcceptableSettings(\?\?) => DI_ERR_NONFATAL\n");
      return setErrorState(DI_ERR_NONFATAL);
   }
}

//!  2.2.16.1 Enumerate Execution Environments
//!
//! @param pdExecEnv
//!
USBDM_GDI_API
DiReturnT DiMeeEnumExecEnv ( DiExecEnvT *pdExecEnv ) {

   print("DiMeeEnumExecEnv() - not implemented\n");
   return setErrorState(DI_ERR_NOTSUPPORTED);
}

//!  2.2.16.2 Connect to Execution Environment
//!
//! @param dnExecId
//!
USBDM_GDI_API
DiReturnT DiMeeConnect ( DiUInt32T dnExecId ) {

#ifdef USE_MEE
   print("DiMeeConnect(%d)\n", dnExecId);

   // Initial connect is treated differently
   USBDM_ErrorCode bdmRc = initialConnect();
   if (bdmRc != BDM_RC_OK) {
      print("DiMeeConnect() - Failed - %s\n", currentErrorString);
      return setErrorState(DI_ERR_COMMUNICATION, bdmRc);
   }
   return setErrorState(DI_OK);
#else
      print("DiMeeConnect() - not implemented\n");
      return setErrorState(DI_ERR_NOTSUPPORTED);
#endif
}

//!  2.2.16.3 Get Features Supported by Execution Environment
//!
//! @param dnExecId
//! @param pdfFeatures
//!
USBDM_GDI_API
DiReturnT DiMeeGetFeatures ( DiUInt32T    dnExecId,
                             pDiFeaturesT pdfFeatures ) {

   print("DiMeeGetFeatures() - not implemented\n");
   return setErrorState(DI_ERR_NOTSUPPORTED);
}

//!  2.2.16.4 Configure I/O System to Execution Environment
//!
//! @param dnExecId
//! @param pdcCommSetup
//!
USBDM_GDI_API
DiReturnT DiMeeInitIO ( DiUInt32T      dnExecId,
                        pDiCommSetupT  pdcCommSetup ) {

   print("DiMeeInitIO(%d) - not implemented\n", dnExecId);
   return setErrorState(DI_ERR_NOTSUPPORTED);
}

//!  2.2.16.5 Set Current Connection
//!
//! @param dnExecId
//!
USBDM_GDI_API
DiReturnT DiMeeSelect ( DiUInt32T dnExecId ) {

   print("DiMeeSelect(%d) - dummy\n", dnExecId);
   return setErrorState(DI_OK);
}

//!  2.2.16.6 Disconnect from Execution Environment
//!
//! @param dnExecId
//! @param fClose
//!
USBDM_GDI_API
DiReturnT DiMeeDisconnect ( DiUInt32T  dnExecId,
                            DiBoolT    fClose ) {

   print("DiMeeDisconnect(%d, %s) - dummy\n", dnExecId, fClose?"T":"F");
   return setErrorState(DI_OK);
}

//!  2.2.16.7 Connect to CPU
//!
//! @param dnCpuId
//!
USBDM_GDI_API
DiReturnT DiCpuSelect ( DiUInt32T dnCpuId ) {

   print("DiCpuSelect() - not implemented\n");
   return setErrorState(DI_ERR_NOTSUPPORTED);
}

//!  2.2.16.8 Get Current CPU
//!
//! @param dnCpuId
//!
USBDM_GDI_API
DiReturnT DiCpuCurrent ( DiUInt32T *dnCpuId ) {

   print("DiCpuCurrent() - not implemented\n");
   return setErrorState(DI_ERR_NOTSUPPORTED);
}

//!  2.2.17 Future GDI Extensions
//!
//! @param information
//!
USBDM_GDI_API
DiReturnT DiProcess ( void *information ) {

   print("DiProcess() - not implemented\n");
   return setErrorState(DI_ERR_NOTSUPPORTED);
}

#ifdef LEGACY
//===================================================================

class minimalApp : public  wxApp {
   DECLARE_CLASS( minimalApp )

public:
   minimalApp() :
      wxApp() {
      fprintf(stderr, "minimalApp::minimalApp()\n");
   }

   ~minimalApp(){
      fprintf(stderr, "minimalApp::~minimalApp()\n");
   }

   bool OnInit() {
      fprintf(stderr, "minimalApp::OnInit()\n");
      return true;
   }

   int OnExit() {
      fprintf(stderr, "minimalApp::OnExit()\n");
      return 0;
   }
};

IMPLEMENT_APP_NO_MAIN( minimalApp )
IMPLEMENT_CLASS( minimalApp, wxApp )

static bool wxInitializationDone = false;
#endif

bool usbdm_gdi_dll_open(void) {
#ifdef LEGACY
   int argc = 1;
   char  arg0[] = "usbdm";
   char *argv[]={arg0, NULL};
   wxApp *savewxApp = wxTheApp;

   if (wxTheApp == NULL) {
      wxInitializationDone = wxEntryStart(argc, argv);
      fprintf(stderr, "usbdm_gdi_dll_open() - wxTheApp = %p\n", wxTheApp);
      fprintf(stderr, "usbdm_gdi_dll_open() - AppName = %s\n", (const char *)wxTheApp->GetAppName().c_str());
   }
   if (wxInitializationDone)
      fprintf(stderr, "usbdm_gdi_dll_open() - wxEntryStart() successful\n");
   else {
      fprintf(stderr, "usbdm_gdi_dll_open() - wxEntryStart() failed\n");
      return false;
   }
#endif
#if TARGET == HCS08
   openLogFile("usbdm_HCS08_gdi.log");
#elif TARGET == RS08
   openLogFile("usbdm_RS08_gdi.log");
#elif TARGET == HCS12
   openLogFile("usbdm_HCS12_gdi.log");
#elif TARGET == CFV1
   openLogFile("usbdm_CFV1_gdi.log");
#elif TARGET == CFVx
   openLogFile("usbdm_CFVx_gdi.log");
#elif TARGET == MC56F80xx
   openLogFile("usbdm_DSC_gdi.log");
#elif TARGET == JTAG
   openLogFile("usbdm_JTAG_gdi.log");
#elif TARGET == ARM
   openLogFile("usbdm_ARM_gdi.log");
#else
   #error Unexpected Target
#endif
   print("usbdm_gdi_dll_open() - wxEntryStart() successful\n");
#ifdef LEGACY
   print("usbdm_gdi_dll_open() - savewxApp = %p\n", savewxApp);
   print("usbdm_gdi_dll_open() - wxTheApp  = %p\n", wxTheApp);
#endif
   return true;
}

bool usbdm_gdi_dll_close(void) {
   print("usbdm_gdi_dll_close()\n");
#ifdef LEGACY
#ifdef _WIN32
   if (wxInitializationDone) {
      fprintf(stderr, "usbdm_gdi_dll_close() - Doing wxEntryCleanup()\n");
      wxEntryCleanup();
      fprintf(stderr, "usbdm_gdi_dll_close() - Done wxEntryCleanup()\n");
   }
#endif
#endif
   closeLogFile();
   return true;
}

#ifdef __unix__

#if   TARGET == ARM
#define GDI_DLL_NAME "usbdm-arm-gdi-debug.so"
#elif TARGET == CFV1
#define GDI_DLL_NAME "usbdm-cfv1-gdi-debug.so"
#elif TARGET == CFVx
#define GDI_DLL_NAME "usbdm-cfvx-gdi-debug.so"
#elif TARGET == MC56F80xx
#define GDI_DLL_NAME "usbdm-dsc-gdi-debug.so"
#elif TARGET == HCS08
#define GDI_DLL_NAME "usbdm-hcs08-gdi-debug.so"
#elif TARGET == HCS12
#define GDI_DLL_NAME "usbdm-hcs12-gdi-debug.so"
#elif TARGET == RS08
#define GDI_DLL_NAME "usbdm-rs08-gdi-debug.so"
#endif

extern "C"
void
__attribute__ ((constructor))
gdi_dll_initialize(void) {
   static void *libHandle = NULL;

   // Lock Library in memory!
   if (libHandle == NULL) {
      libHandle = dlopen(GDI_DLL_NAME, RTLD_NOW|RTLD_NODELETE);
      if (libHandle == NULL) {
         fprintf(stderr, "gdi_dll_initialize() - Library failed to lock %s\n", dlerror());
         return;
      }
      else
         fprintf(stderr, "gdi_dll_initialize() - Library locked OK\n");
   }
   else
      fprintf(stderr, "gdi_dll_initialize() - Library already locked\n");
}

extern "C"
void
__attribute__ ((destructor))
gdi_dll_uninitialize(void) {
}
#else
#include <windef.h>
extern "C" WINAPI __declspec(dllexport)
BOOL DllMain(HINSTANCE _hDLLInst,
                     DWORD fdwReason,
                     LPVOID lpvReserved) {

   switch (fdwReason) {
      case DLL_PROCESS_ATTACH:
         print("DLL_PROCESS_ATTACH\n");
//         dll_initialize();
         break;
      case DLL_PROCESS_DETACH:
         print("DLL_PROCESS_DETACH - closeBDM()\n");
         closeBDM();
         print("DLL_PROCESS_DETACH - usbdm_gdi_dll_close()\n");
         usbdm_gdi_dll_close();
         print("DLL_PROCESS_DETACH - done\n");
//         dll_uninitialize();
         break;
      case DLL_THREAD_ATTACH:
//         print("DLL_THREAD_ATTACH\n");
//         dll_initialize(_hDLLInst);
         break;
      case DLL_THREAD_DETACH:
//         print("DLL_THREAD_DETACH\n");
//         dll_uninitialize();
         break;
   }
   return TRUE;
}
#endif

#ifdef _WIN32
// This creates aliases for the the GDI routines with underscores in the names
#include "GDI_underscores.h"
#endif
