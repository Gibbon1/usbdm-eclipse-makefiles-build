/*
 * FlashProgrammerDialogue.h
 *
 *  Created on: 07/07/2010
 *      Author: pgo
 */

#ifndef USBDMDIALOGUE_H__
#define USBDMDIALOGUE_H__

#include <wx/frame.h>
#include <wx/notebook.h>
#include <wx/combo.h>
#include <wx/dialog.h>
#include <wx/panel.h>

#include "Shared.h"
#include "AdvancedPanel.h"
#include "InterfacePanel.h"
#include "USBDM_API.h"
#include "Log.h"

class TargetPanel;
class AdvancedPanel;

#define BASE_CAPTION _("USBDM Configuration")

/*!
 * UsbdmDialogue class declaration
 */
class UsbdmDialogue: public wxDialog {

    DECLARE_CLASS( UsbdmDialogue )
    DECLARE_EVENT_TABLE()

private:
   SharedPtr               shared;
   AppSettings            &appSettings;
   wxString                caption;
   HardwareCapabilities_t  bdmCapabilities;
   bool                    disableDialogueDisplay;
   USBDM_ErrorCode         errorSet;

   bool                    settingsAreNotPersistent;

   // Control Identifiers
   enum {
      ID_FLASH_PROGRAMMER_DIALOGUE 	= 10000,
      ID_NOTEBOOK,
      ID_DONT_SHOW_AGAIN_CHECKBOX,
      ID_BUTTON_DEFAULT,
      ID_COMMUNICATION 				   = 11000,
      ID_FLASH_PROGRAMMING 			= 12000,
   };

   // Controls
   wxNotebook*      noteBook;
   InterfacePanel  *interfacePanel;
#if defined(FLASH_PROGRAMMER) || defined(GDB_SERVER)
   TargetPanel     *flashParametersPanel;
#endif   
   AdvancedPanel   *advancedPanel;
   wxCheckBox      *dontShowAgainControl;

public:
   //! Constructors
   UsbdmDialogue(SharedPtr shared, AppSettings &appsSettings, const wxString &caption=BASE_CAPTION);

   //! Destructor
   ~UsbdmDialogue();

   void enableSettingsAreNotPersistent(bool value = true) {
      settingsAreNotPersistent = value;
   }

   //! Returns the BDM options from the internal state
   //!
   //! @param bdmOptions - where to return options
   //!
   void getBdmOptions( USBDM_ExtendedOptions_t &bdmOptions );

   SharedPtr getShared() { return shared; }

#if defined(FLASH_PROGRAMMER) || defined(GDB_SERVER)
   //! Returns the Device options from the internal state
   //!
   //! @param deviceData - where to return options
   //!
   void getDeviceData( DeviceData &deviceData );
#endif
   bool Create( wxWindow* parent, long style = wxDEFAULT_DIALOG_STYLE|wxMINIMIZE_BOX|wxRESIZE_BORDER);
   bool setDialogueValuesToDefault();
   bool TransferDataToWindow();
   bool TransferDataFromWindow();
   virtual bool updateState();

   FILE *openSettingsFile(const wxString &filename, const wxString  &attributes);

   bool loadSettings(const AppSettings &appSettings);
   bool saveSettings(AppSettings &appSettings);
//   bool loadSettingsFile(string const &fileName);
//   bool loadSettingsFileFromAppDir(string const &fileName);
//   bool saveSettingsFile(string const &fileName);
//   bool saveSettingsFileToAppDir(string const &fileName);

   // Initializes member variables
   bool Init();

   // Creates the controls and sizers
   void CreateControls();

   // Event handlers
   void OnDontShowAgainControlClick( wxCommandEvent& event );
   void OnDefaultClick( wxCommandEvent& event );
   void OnSelChanging( wxNotebookEvent& event );
   void OnSelChanged( wxNotebookEvent& event );
   void OnOkClick( wxCommandEvent& event );
   void OnCancelClick( wxCommandEvent& event );

   wxBitmap GetBitmapResource( const wxString& name );
   wxIcon GetIconResource( const wxString& name );
   static bool ShowToolTips();
   static const string settingsKey;
   wxString binaryFilename;


   USBDM_ExtendedOptions_t&   getBdmOptions()     { return shared->bdmOptions; }

#if defined(GDI) && defined(LEGACY)
   USBDM_ErrorCode execute(string const     &deviceName,
                           string const     &projectName,
                           bool              forceDisplay = false,
                           USBDM_ErrorCode (*openTarget)(void) = 0);
#elif defined(FLASH_PROGRAMMER) || defined(GDB_SERVER)
   USBDM_ErrorCode execute(wxString const &hexFilename=wxEmptyString);
#endif
};

#endif /* USBDMDIALOGUE_H_ */
