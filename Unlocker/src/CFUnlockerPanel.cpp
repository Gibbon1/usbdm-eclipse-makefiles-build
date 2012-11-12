/*
 * CFUnlockerDialogue.c
 *
 *  Created on: 23/10/2010
 *      Author: podonoghue
 */

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include "wx/sizer.h"
#include "wx/gbsizer.h"
#include "wx/panel.h"

#include "USBDM_API.h"
#include "USBDM_AUX.h"
#include "Log.h"
#include "Version.h"
#include "CFUnlockerPanel.h"

/*
 * ColdfireUnlockerDialogue type definition
 */
IMPLEMENT_DYNAMIC_CLASS( ColdfireUnlockerPanel, wxPanel )

/*
 * ColdfireUnlockerDialogue event table definition
 */
BEGIN_EVENT_TABLE( ColdfireUnlockerPanel, wxPanel )
    EVT_BUTTON( ID_INIT_CHAIN_BUTTON, ColdfireUnlockerPanel::OnInitChainButtonClick )
    EVT_CHOICE( ID_JTAG_DEVICE_CHOICE, ColdfireUnlockerPanel::OnJtagDeviceChoiceSelected )
    EVT_SPINCTRL( ID_IR_LENGTH_SPINCTRL, ColdfireUnlockerPanel::OnIrLengthSpinctrlUpdated )
//    EVT_UPDATE_UI( wxID_PIN_STATIC, ColdfireUnlockerDialogue::OnPinStaticUpdate )
    EVT_CHOICE( ID_TARGET_DEVICE_CHOICE, ColdfireUnlockerPanel::OnTargetDeviceChoiceSelected )
    EVT_TEXT( ID_SPEED_TEXTCTRL, ColdfireUnlockerPanel::OnSpeedTextctrlTextUpdated )
    EVT_TEXT( ID_MIN_FREQ_TEXTCTRL, ColdfireUnlockerPanel::OnMinFreqTextctrlTextUpdated )
    EVT_TEXT( ID_MAX_FREQ_TEXTCTRL, ColdfireUnlockerPanel::OnMaxFreqTextctrlTextUpdated )
    EVT_CHOICE( ID_EQUATION_CHOICE, ColdfireUnlockerPanel::OnEquationChoiceSelected )
    EVT_TEXT( ID_UNLOCK_VALUE_TEXTCTRL, ColdfireUnlockerPanel::OnUnlockValueTextctrlTextUpdated )
    EVT_TEXT( ID_CLOCK_DIVIDER_VALUE_TEXTCTRL, ColdfireUnlockerPanel::OnClockDividerValueTextctrlTextUpdated )
    EVT_BUTTON( ID_UNLOCK_BUTTON, ColdfireUnlockerPanel::OnUnlockButtonClick )
END_EVENT_TABLE()

/*
 * ColdfireUnlockerDialogue constructors
 */
ColdfireUnlockerPanel::ColdfireUnlockerPanel()
{
    Init();
}

ColdfireUnlockerPanel::ColdfireUnlockerPanel( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style )
{
    Init();
    Create(parent, id, pos, size, style);
}

/*
 * ColdfireUnlockerDialogue creator
 */
bool ColdfireUnlockerPanel::Create( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style )
{
//    SetExtraStyle(wxWS_EX_BLOCK_EVENTS);
    wxPanel::Create(parent, id, pos, size, style);
    CreateControls();
    if (GetSizer()) {
        GetSizer()->SetSizeHints(this);
    }
    knownDevices.loadConfigFile();
    loadDeviceList();
//    flashEraseMethods.loadMethods();
    loadEraseMethodsList();

    versionStaticControl->SetLabel(_(USBDM_VERSION_STRING));
    targetSpeedTextControl->SetDecimalValue(8000);
    return true;
}

/*
 * ColdfireUnlockerDialogue destructor
 */
ColdfireUnlockerPanel::~ColdfireUnlockerPanel()
{
}

/*
 * Member initialisation
 */
void ColdfireUnlockerPanel::Init()
{
   initChainButtonControl = NULL;
   numberOfDeviceStaticControl = NULL;
   jtagIdcodeStaticText = NULL;
   jtagDeviceChoiceControl = NULL;
   irLengthSpinControl = NULL;
   freescalePINStaticControl = NULL;
   totalIrLengthStaticControl = NULL;
   descriptionStaticControl = NULL;
   targetDeviceChoiceControl = NULL;
   targetSpeedTextControl = NULL;
   minimumFrequencyTextControl = NULL;
   maximumFrequencyTextControl = NULL;
   equationChoiceControl = NULL;
   unlockInstructionTextControl = NULL;
   clockDividerTextControl = NULL;
   versionStaticControl = NULL;
   unlockButtonControl = NULL;
}

/*
 * Control creation for ColdfireUnlockerDialogue
 */
void ColdfireUnlockerPanel::CreateControls()
{
////@begin ColdfireUnlockerDialogue content construction
    // Generated by DialogBlocks, 23/10/2010 14:32:45 (Personal Edition)

    ColdfireUnlockerPanel* dialogue = this;

    wxBoxSizer* dialogueSizerV = new wxBoxSizer(wxVERTICAL);
    dialogue->SetSizer(dialogueSizerV);

    //====================================================================

    wxStaticBox* itemStaticBoxSizer3Static = new wxStaticBox(dialogue, wxID_ANY, _("1. JTAG Chain"));
    wxStaticBoxSizer* itemStaticBoxSizer3 = new wxStaticBoxSizer(itemStaticBoxSizer3Static, wxHORIZONTAL);
    dialogueSizerV->Add(itemStaticBoxSizer3, 0, wxGROW|wxALL, 5);

    initChainButtonControl = new wxButton( dialogue, ID_INIT_CHAIN_BUTTON, _("Initialise JTAG chain"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStaticBoxSizer3->Add(initChainButtonControl, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    numberOfDeviceStaticControl = new wxStaticText( dialogue, wxID_NUMBER_OF_DEVICES_STATIC, _("Number of devices found: -"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStaticBoxSizer3->Add(numberOfDeviceStaticControl, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    //====================================================================

    wxStaticBox* itemStaticBoxSizer6Static = new wxStaticBox(dialogue, wxID_ANY, _("2. Select device in chain to erase"));
    wxStaticBoxSizer* itemStaticBoxSizer6 = new wxStaticBoxSizer(itemStaticBoxSizer6Static, wxVERTICAL);
    dialogueSizerV->Add(itemStaticBoxSizer6, 0, wxGROW|wxALL, 5);

    wxGridBagSizer* gridBagSizer = new wxGridBagSizer(4,4);
    itemStaticBoxSizer6->Add(gridBagSizer, 0, wxGROW|wxALL, 5);

    wxStaticText* itemStaticText8 = new wxStaticText( dialogue, wxID_STATIC, _("JTAG Device #"), wxDefaultPosition, wxDefaultSize, 0 );
    gridBagSizer->Add(itemStaticText8, wxGBPosition(0,1), wxGBSpan(1,1),wxALIGN_CENTER_VERTICAL);

    wxStaticText* itemStaticText9 = new wxStaticText( dialogue, wxID_STATIC, _("IR\nLength"), wxDefaultPosition, wxDefaultSize, 0 );
    gridBagSizer->Add(itemStaticText9, wxGBPosition(0,2), wxGBSpan(1,1),wxALIGN_CENTER_VERTICAL);

    jtagIdcodeStaticText = new wxStaticText( dialogue, wxID_JTAG_IDCODE_STATIC, _("IDCODE: - 00000000 "), wxDefaultPosition, wxDefaultSize, 0 );
    gridBagSizer->Add(jtagIdcodeStaticText, wxGBPosition(0,3), wxGBSpan(1,1),wxALIGN_CENTER_VERTICAL);

    wxArrayString jtagDeviceChoiceControlStrings;
//    jtagDeviceChoiceControl = new wxChoice( dialogue, ID_JTAG_DEVICE_CHOICE, wxDefaultPosition, wxSize(150,30), jtagDeviceChoiceControlStrings, 0 );
    jtagDeviceChoiceControl = new wxChoice( dialogue, ID_JTAG_DEVICE_CHOICE, wxDefaultPosition, wxDefaultSize, jtagDeviceChoiceControlStrings, 0 );
    jtagDeviceChoiceControl->Enable(false);
    gridBagSizer->Add(jtagDeviceChoiceControl, wxGBPosition(1,1), wxGBSpan(1,1),wxALIGN_CENTER_VERTICAL);

    irLengthSpinControl = new wxSpinCtrl( dialogue, ID_IR_LENGTH_SPINCTRL, _T("0"), wxDefaultPosition, wxSize(40, -1), wxSP_ARROW_KEYS, 0, 100, 0 );
    gridBagSizer->Add(irLengthSpinControl, wxGBPosition(1,2), wxGBSpan(1,1),wxALIGN_CENTER_VERTICAL);

    freescalePINStaticControl = new wxStaticText( dialogue, wxID_PIN_STATIC, _("Freescale PIN: -"), wxDefaultPosition, wxDefaultSize, 0 );
    gridBagSizer->Add(freescalePINStaticControl, wxGBPosition(1,3), wxGBSpan(1,1),wxALIGN_CENTER_VERTICAL);

    totalIrLengthStaticControl = new wxStaticText( dialogue, wxID_STATIC, _("Total IR Length: -"), wxDefaultPosition, wxDefaultSize, 0 );
    gridBagSizer->Add(totalIrLengthStaticControl, wxGBPosition(2,1), wxGBSpan(1,1),wxALIGN_CENTER_VERTICAL);

    descriptionStaticControl = new wxStaticText( dialogue, wxID_STATIC, _("Desc: -"), wxDefaultPosition, wxDefaultSize, 0 );
    gridBagSizer->Add(descriptionStaticControl, wxGBPosition(2,2), wxGBSpan(1,2),wxALIGN_CENTER_VERTICAL);

    //====================================================================

    wxStaticBox* itemStaticBoxSizer18Static = new wxStaticBox(dialogue, wxID_ANY, _("3. Select target device type and speed"));
    wxStaticBoxSizer* itemStaticBoxSizer18 = new wxStaticBoxSizer(itemStaticBoxSizer18Static, wxHORIZONTAL);
    dialogueSizerV->Add(itemStaticBoxSizer18, 0, wxGROW|wxALL, 5);

    wxArrayString targetDeviceChoiceControlStrings;
    targetDeviceChoiceControl = new wxChoice( dialogue, ID_TARGET_DEVICE_CHOICE, wxDefaultPosition, wxDefaultSize, targetDeviceChoiceControlStrings, 0 );
    itemStaticBoxSizer18->Add(targetDeviceChoiceControl, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    targetSpeedTextControl = new NumberTextEditCtrl( dialogue, ID_SPEED_TEXTCTRL, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    itemStaticBoxSizer18->Add(targetSpeedTextControl, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText21 = new wxStaticText( dialogue, wxID_STATIC, _("kHz"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStaticBoxSizer18->Add(itemStaticText21, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    //====================================================================

    wxStaticBox* itemStaticBoxSizer22Static = new wxStaticBox(dialogue, wxID_ANY, _("4. Select Flash clock limits and equation"));
    wxStaticBoxSizer* itemStaticBoxSizer22 = new wxStaticBoxSizer(itemStaticBoxSizer22Static, wxVERTICAL);
    dialogueSizerV->Add(itemStaticBoxSizer22, 0, wxGROW|wxALL, 5);

    wxBoxSizer* itemBoxSizer23 = new wxBoxSizer(wxHORIZONTAL);
    itemStaticBoxSizer22->Add(itemBoxSizer23, 0, wxGROW, 5);

    wxBoxSizer* itemBoxSizer24 = new wxBoxSizer(wxVERTICAL);
    itemBoxSizer23->Add(itemBoxSizer24, 1, wxGROW|wxALL, 5);

    wxStaticText* itemStaticText25 = new wxStaticText( dialogue, wxID_STATIC, _("Minimum Frequency"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer24->Add(itemStaticText25, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    minimumFrequencyTextControl = new NumberTextEditCtrl( dialogue, ID_MIN_FREQ_TEXTCTRL, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer24->Add(minimumFrequencyTextControl, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer27 = new wxBoxSizer(wxVERTICAL);
    itemBoxSizer23->Add(itemBoxSizer27, 1, wxGROW|wxALL, 5);

    wxStaticText* itemStaticText28 = new wxStaticText( dialogue, wxID_STATIC, _("Maximum Frequency"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer27->Add(itemStaticText28, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    maximumFrequencyTextControl = new NumberTextEditCtrl( dialogue, ID_MAX_FREQ_TEXTCTRL, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer27->Add(maximumFrequencyTextControl, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxArrayString equationChoiceControlStrings;
    equationChoiceControl = new wxChoice( dialogue, ID_EQUATION_CHOICE, wxDefaultPosition, wxDefaultSize, equationChoiceControlStrings, 0 );
    itemStaticBoxSizer22->Add(equationChoiceControl, 0, wxGROW|wxALL, 5);

    //====================================================================

    wxStaticBox* itemStaticBoxSizer31Static = new wxStaticBox(dialogue, wxID_ANY, _("5. Select Erase parameters"));
    wxStaticBoxSizer* itemStaticBoxSizer31 = new wxStaticBoxSizer(itemStaticBoxSizer31Static, wxHORIZONTAL);
    dialogueSizerV->Add(itemStaticBoxSizer31, 0, wxGROW|wxALL, 5);

    wxBoxSizer* itemBoxSizer32 = new wxBoxSizer(wxVERTICAL);
    itemStaticBoxSizer31->Add(itemBoxSizer32, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText33 = new wxStaticText( dialogue, wxID_STATIC, _("Unlock Instruction (hex)"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer32->Add(itemStaticText33, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    unlockInstructionTextControl = new NumberTextEditCtrl( dialogue, ID_UNLOCK_VALUE_TEXTCTRL, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer32->Add(unlockInstructionTextControl, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer35 = new wxBoxSizer(wxVERTICAL);
    itemStaticBoxSizer31->Add(itemBoxSizer35, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText36 = new wxStaticText( dialogue, wxID_STATIC, _("Clk Divider value (hex)"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer35->Add(itemStaticText36, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    clockDividerTextControl = new NumberTextEditCtrl( dialogue, ID_CLOCK_DIVIDER_VALUE_TEXTCTRL, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer35->Add(clockDividerTextControl, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    versionStaticControl = new wxStaticText( dialogue, wxID_VERSION_STATIC, _("CF Unlocker V4"), wxDefaultPosition, wxDefaultSize, 0 );
    dialogueSizerV->Add(versionStaticControl, 0, wxALIGN_RIGHT|wxALL, 5);

    //====================================================================

    wxBoxSizer* itemBoxSizer39 = new wxBoxSizer(wxHORIZONTAL);
    dialogueSizerV->Add(itemBoxSizer39, 0, wxGROW|wxALL, 5);

    wxButton* itemButton40 = new wxButton( dialogue, wxID_CANCEL, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer39->Add(itemButton40, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemBoxSizer39->Add(5, 5, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    unlockButtonControl = new wxButton( dialogue, ID_UNLOCK_BUTTON, _("6. Unlock and Erase"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer39->Add(unlockButtonControl, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

////@end ColdfireUnlockerDialogue content construction
}

//============================================================================
//============================================================================
//============================================================================
// Event handlers
//

/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_INIT_CHAIN_BUTTON
 */
void ColdfireUnlockerPanel::OnInitChainButtonClick( wxCommandEvent& event )
{
   USBDM_SetExtendedOptions(&bdmOptions);
#if TARGET == CFVx
   if (USBDM_SetTargetTypeWithRetry(T_CFVx) != BDM_RC_OK) {
      return;
   }
#elif TARGET == MC56F80xx
   if (USBDM_SetTargetTypeWithRetry(T_MC56F80xx) != BDM_RC_OK) {
      return;
   }
#endif
   loadJTAGDeviceList();
   USBDM_SetTargetType(T_OFF);
}

/*
 * wxEVT_COMMAND_CHOICE_SELECTED event handler for ID_JTAG_DEVICE_CHOICE
 */
void ColdfireUnlockerPanel::OnJtagDeviceChoiceSelected( wxCommandEvent& event )
{
   print("IDC_JTAG_DEVICE_COMBO\n");
   updateDeviceDetails();
}

/*
 * wxEVT_COMMAND_SPINCTRL_UPDATED event handler for ID_IR_LENGTH_SPINCTRL
 */
void ColdfireUnlockerPanel::OnIrLengthSpinctrlUpdated( wxSpinEvent& event )
{
   //print("IDC_IRLENGTH_EDIT\n");
   unsigned int irLength = event.GetPosition();
   JTAG_Chain::getTargetDevice().irLength = irLength;
}

///*
// * wxEVT_UPDATE_UI event handler for wxID_PIN_STATIC
// */
//
//void ColdfireUnlockerDialogue::OnPinStaticUpdate( wxUpdateUIEvent& event )
//{
//    event.Skip();
//}

/*
 * wxEVT_COMMAND_CHOICE_SELECTED event handler for ID_TARGET_DEVICE_CHOICE
 */
void ColdfireUnlockerPanel::OnTargetDeviceChoiceSelected( wxCommandEvent& event )
{
   updateEraseParameters();
}

/*
 * wxEVT_COMMAND_TEXT_UPDATED event handler for ID_SPEED_TEXTCTRL
 */

void ColdfireUnlockerPanel::OnSpeedTextctrlTextUpdated( wxCommandEvent& event )
{
   updateClockDividerValue();
}

/*
 * wxEVT_COMMAND_TEXT_UPDATED event handler for ID_MIN_FREQ_TEXTCTRL
 */
void ColdfireUnlockerPanel::OnMinFreqTextctrlTextUpdated( wxCommandEvent& event )
{
   updateClockDividerValue();
}

/*
 * wxEVT_COMMAND_TEXT_UPDATED event handler for ID_MAX_FREQ_TEXTCTRL
 */
void ColdfireUnlockerPanel::OnMaxFreqTextctrlTextUpdated( wxCommandEvent& event )
{
   updateClockDividerValue();
}

/*
 * wxEVT_COMMAND_CHOICE_SELECTED event handler for ID_EQUATION_CHOICE
 */
void ColdfireUnlockerPanel::OnEquationChoiceSelected( wxCommandEvent& event )
{
   int index = event.GetSelection();
   FlashEraseMethods::setMethodIndex(index);
   updateClockDividerValue();
}

/*
 * wxEVT_COMMAND_TEXT_UPDATED event handler for ID_UNLOCK_VALUE_TEXTCTRL
 */
void ColdfireUnlockerPanel::OnUnlockValueTextctrlTextUpdated( wxCommandEvent& event )
{
    event.Skip();
}

/*
 * wxEVT_COMMAND_TEXT_UPDATED event handler for ID_CLOCK_DIVIDER_VALUE_TEXTCTRL
 */
void ColdfireUnlockerPanel::OnClockDividerValueTextctrlTextUpdated( wxCommandEvent& event )
{
    event.Skip();
}

/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_UNLOCK_BUTTON
 */
void ColdfireUnlockerPanel::OnUnlockButtonClick( wxCommandEvent& event )
{
#if TARGET == CFVx
   eraseCFVxDevice();
#elif TARGET == MC56F80xx
   eraseDscDevice();
#endif
   USBDM_SetTargetType(T_OFF);
}

/*
 * Should we show tooltips?
 */
bool ColdfireUnlockerPanel::ShowToolTips()
{
    return true;
}

/*
 * Get bitmap resources
 */

wxBitmap ColdfireUnlockerPanel::GetBitmapResource( const wxString& name )
{
    wxUnusedVar(name);
    return wxNullBitmap;
}

/*
 * Get icon resources
 */
wxIcon ColdfireUnlockerPanel::GetIconResource( const wxString& name )
{
    wxUnusedVar(name);
    return wxNullIcon;
}

//! \brief Loads the Target device type Combobox
//!
//! @param hDlg      : handle to the dialogue
//!
void ColdfireUnlockerPanel::loadDeviceList() {
   unsigned int deviceCount;

   for (deviceCount = 0; deviceCount < KnownDevices::deviceCount; deviceCount++) {
      targetDeviceChoiceControl->Append(wxString::FromAscii(KnownDevices::deviceData[deviceCount].name));
   }
   targetDeviceChoiceControl->SetSelection(0);
}

//! \brief Loads the Clock equation selection combobox
//!
//! @param hDlg : handle for dialogue
//!
void ColdfireUnlockerPanel::loadEraseMethodsList() {
   unsigned int methodNum;

   for (methodNum=0; methodNum<FlashEraseMethods::getNumMethods(); methodNum++) {
      equationChoiceControl->Append(wxString::FromAscii(FlashEraseMethods::getMethod(methodNum)->getDescription()));
   }
   equationChoiceControl->SetSelection(0);
}

//! \brief Update dialogue for a change in attribute affecting Clock Divider value
//! e.g. Clock divider eqn, Fmin, Fmax or target clock freq.
//!
//! @param hDlg : handle for dialogue
//!
void ColdfireUnlockerPanel::updateClockDividerValue() {
   unsigned long clockFreq, fMax, fMin;
   int clkDividerValue;

   clockFreq = targetSpeedTextControl->GetDecimalValue();
   fMax      = maximumFrequencyTextControl->GetDecimalValue();
   fMin      = minimumFrequencyTextControl->GetDecimalValue();

   clkDividerValue = FlashEraseMethods::getCurrentMethod()->findFlashDividerValue(clockFreq, fMin, fMax);

   if (clkDividerValue >= 0) {
      clockDividerTextControl->SetHexValue(clkDividerValue&0xFF);
      unlockButtonControl->Enable();
   }
   else {
      clockDividerTextControl->SetValue(_("Invalid"));
      unlockButtonControl->Enable(false);
   }
}

//! \brief Update dialogue for change in selection affecting erase parameters
//! e.g. Target device selection
//!
//! Updated values:
//!   IR length
//!   Fmin
//!   Fmax
//!   Clock divider equation
//!   Unlock value
//!
//! \ref updateClockDividerValue() is called to propagate changes
//!
//! @param hDlg : handle for dialogue
//!
void ColdfireUnlockerPanel::updateEraseParameters() {
   int enableParameters;

   int index = targetDeviceChoiceControl->GetSelection();

   print("updateEraseParameters(): index = %d\n", index);

   if (index == wxNOT_FOUND) {
      maximumFrequencyTextControl->SetValue(_("Invalid"));
      minimumFrequencyTextControl->SetValue(_("Invalid"));
      clockDividerTextControl->SetValue(_("Invalid"));
      maximumFrequencyTextControl->SetValue(_("Invalid"));
      return;
   }

   clkdivDrLength = KnownDevices::deviceData[index].dataLength;

   // Update IR Length
   if (KnownDevices::deviceData[index].irLengthKnown) { // IR Length is known & fixed
      irLengthSpinControl->SetValue(KnownDevices::deviceData[index].instructionLength);
      irLengthSpinControl->Disable();
   }
   else { // Allow IR Length to be varied
//      irLengthSpinControl->SetValue(JTAG_Chain::getTargetDevice().irLength);
      irLengthSpinControl->Disable();
   }

   // Update Fmin
   minimumFrequencyTextControl->SetDecimalValue(KnownDevices::deviceData[index].fMin/1000);

   // Update Fmax
   maximumFrequencyTextControl->SetDecimalValue(KnownDevices::deviceData[index].fMax/1000);

   // Update Unlock instruction value
   unlockInstructionTextControl->SetHexValue(KnownDevices::deviceData[index].unlockInstruction);

   // Update erase methods
   FlashEraseMethods::setMethodIndex(KnownDevices::deviceData[index].flashEquation);
   equationChoiceControl->SetSelection(FlashEraseMethods::getCurrentMethodIndex());

   // Only enable parameter changes for custom device
   enableParameters = (index == 1);
   minimumFrequencyTextControl->Enable(enableParameters);
   maximumFrequencyTextControl->Enable(enableParameters);
   equationChoiceControl->Enable(enableParameters);
   equationChoiceControl->Enable(enableParameters);
   clockDividerTextControl->Enable(enableParameters);
   unlockInstructionTextControl->Enable(enableParameters);

   updateClockDividerValue();
}

//! \brief Update dialogue for changes in device selected in JTAG chain
//!
//! Updated value:
//!    JEDEC Code
//!    (Freescale) Part Number
//!    Description
//!    Device Type combo (and disabled if known device)
//!    IR length
//!
//! The device selected in the JTAG chain is updated.
//!
//! @param hDlg : handle for dialogue
//! @note updateEraseParameters(hDlg) is called to propagate changes
//!
void ColdfireUnlockerPanel::updateDeviceDetails() {
   char buff[100];
   int jedecCode;
   int partNum;
   int freescalePIN;
   int index;

   index = jtagDeviceChoiceControl->GetSelection();

   if (index == wxNOT_FOUND) {
      jtagIdcodeStaticText->SetLabel(_("Invalid"));
      return;
   }

   JTAG_Chain::selectTargetDevice(index);

   jedecCode    = JEDEC_ID(JTAG_Chain::devices[index].idcode);
   partNum      = PART_NUM(JTAG_Chain::devices[index].idcode);
   freescalePIN = FREESCALE_PIN(JTAG_Chain::devices[index].idcode);

   sprintf(buff, "IDCODE : %8.8X", JTAG_Chain::getTargetDevice().idcode);
   jtagIdcodeStaticText->SetLabel(wxString::FromAscii(buff));

   if (JTAG_Chain::getTargetDevice().idcode == 0) // No JTAG IDCODE
      freescalePINStaticControl->SetLabel(_(""));
   else {
      if (jedecCode != FREESCALE_JEDEC)
         sprintf(buff, "Part No. : %4.4X", partNum);
      else
         sprintf(buff, "Freescale PIN : %3.3X", freescalePIN);
      freescalePINStaticControl->SetLabel(wxString::FromAscii(buff));
      }

   sprintf(buff, "Desc : %s", JTAG_Chain::getTargetDevice().deviceData->description);
   //print("%s\n",buff);
   descriptionStaticControl->SetLabel(wxString::FromAscii(buff));

   targetDeviceChoiceControl->SetSelection(JTAG_Chain::getTargetDevice().deviceData->index);
   targetDeviceChoiceControl->Enable(JTAG_Chain::getTargetDevice().deviceData == &KnownDevices::unRecognizedDevice);

   irLengthSpinControl->SetValue(JTAG_Chain::getTargetDevice().irLength);

   updateEraseParameters();
}

//! \brief Populates the JTAG device combobox with the devices found in the JTAG chain
//!
//! @param hDlg : handle for dialogue
//!
//! @note : Assumes \ref JTAG_Chain contains the devices found
//! @note : updateDeviceDetails(hDlg) is called to update the display
//!
void ColdfireUnlockerPanel::loadJTAGDeviceList() {
   unsigned int device;
   char buff[100];

   print( "loadJTAGDevicesList():Identifying devices\n");
   JTAG_Chain::initialiseJTAGChain();

   // Populate JTAG device list
   jtagDeviceChoiceControl->Clear();

   for (device = 0; device < JTAG_Chain::deviceCount; device++) {
      sprintf(buff, "%d.%15.15s", device,
              JTAG_Chain::devices[device].deviceData->name);
      jtagDeviceChoiceControl->Append(wxString::FromAscii(buff));
   }
   jtagDeviceChoiceControl->SetSelection(0);

   jtagDeviceChoiceControl->Enable(JTAG_Chain::deviceCount>1);

   sprintf(buff, "Number of devices found : %d", JTAG_Chain::deviceCount);
   numberOfDeviceStaticControl->SetLabel(wxString::FromAscii(buff));

   sprintf(buff, "Total IR length:%3d", JTAG_Chain::irLength);
   totalIrLengthStaticControl->SetLabel(wxString::FromAscii(buff));

   updateDeviceDetails();
}

//! \brief This routine tries to locate the given device in the JTAG IR chain.
//! Unfortunately there is no guaranteed method to do this without
//! knowing the length of the JTAG instruction register of all devices
//! in the chain.
//!
//! Some special case are OK:\n
//! - A single device - the device we wish to erase.\n
//! - First device in chain - the length of the IR after can be determined
//!   from the total IR length and the IR length of the device to erase.\n
//! - Last device in chain - the length of the IR before can be determined
//!   from the total IR length and the IR length of the device to erase.\n
//!
//! The JTAG standard requires that the least significant 2 bits of the IR
//! read as "01". This allows potential IR boundaries to be determined.
//! This results in another special case:
//! - # of boundaries == # of devices - The IR can be exactly located.
//!
//! Otherwise a trial-and-error method is used.  This makes use of the
//! boundaries determined above, the know number of devices before and after
//! the desired device and the know size of the IR for that device.
//!
//! @param deviceNum => position of device in chain (0 based from TDO end of chain)
//!
void ColdfireUnlockerPanel::findDeviceInJTAGChain(unsigned int deviceNum) {
   unsigned int index;
   unsigned int oIndex;
   unsigned int iIndex;
   unsigned int irLength;
   uint8_t  lastBit;
   unsigned int bitNum;
   unsigned int boundaries[JTAG_Chain:: MAX_JTAG_DEVICES];
   struct {
      unsigned int start;
      unsigned int end;
   } usefulBoundaries[JTAG_Chain::MAX_JTAG_DEVICES];
   unsigned int usefulIrCount;
   unsigned int irCount;
   unsigned int irStart, irEnd;
   int confirmStart, confirmEnd;

   print( "findDeviceInJTAGChain()\n");

   irLength = JTAG_Chain::irLength;

   // Debug - report IR chain contents
   //===========================================================================
   bitVector irReg(irLength);
   USBDM_JTAG_Reset();
   USBDM_JTAG_SelectShift(JTAG_SHIFT_IR);
   USBDM_JTAG_Read(irLength, JTAG_STAY_SHIFT, irReg.getArray());
   print( "findDeviceInJTAGChain(): JTAG IRs => %s\n", irReg.toBinString());

   // The JTAG standard requires the 1st two bits in the IR to be "01".
   // Read the JTAG IR chain looking for a "01" pattern which MAY indicate the
   // Boundary b/w two device IRs
   //===========================================================================
   //
   print( "             0    1    2    3    4    5    6    7    8\n");
   print( "Boundary @");

   irCount = 0;
   bitNum = 0;
   lastBit = 0;
   do {
      //print( "bit[%3d] => %d\n", bitNum, irReg[bitNum]);
      if ((irReg[bitNum] == 0) && (lastBit == 1)) {
         print( " %3d,", bitNum-1);
         boundaries[irCount++] = bitNum-1;
      }
      lastBit = irReg[bitNum];
   } while (bitNum++ < irReg.getLength());

   print( "\n");

   if (irCount < JTAG_Chain::deviceCount) { // Not enough "01" patterns!
      print( "Can't find sufficient IRs!\n");
   }

   // Check for special cases
   if (deviceNum == 0) { // 1st in chain
      print("First in chain\n");
      irStart = 0;
      irEnd   = JTAG_Chain::devices[deviceNum].deviceData->instructionLength-1;
   }
   else if (deviceNum == JTAG_Chain::deviceCount-1) { // last in chain
      print("Last in chain\n");
      irStart = irLength-JTAG_Chain::devices[deviceNum].deviceData->instructionLength;
      irEnd   = irLength-1;
   }
   else if (irCount == JTAG_Chain::deviceCount) { // Same # of "01" as devices!
      print("IR pattern matches expected pattern\n");
      irStart = boundaries[deviceNum];
      irEnd   = boundaries[deviceNum]+JTAG_Chain::devices[deviceNum].deviceData->instructionLength;
   }
   else { // trial and error
      // Find potential boundaries.  These are:
      // - Within the correct range
      // - Result in the correct IR length
      usefulIrCount = 0;
      for (oIndex=deviceNum; oIndex<=irCount-(JTAG_Chain::deviceCount-deviceNum); oIndex++) {
         for (iIndex = oIndex+1; iIndex<=irCount-(JTAG_Chain::deviceCount-deviceNum)+1; iIndex++) {
            print( "Trying %d-%d", oIndex, iIndex);
            if (boundaries[iIndex]-boundaries[oIndex] ==
                JTAG_Chain::devices[deviceNum].deviceData->instructionLength) {
               usefulBoundaries[usefulIrCount].start = boundaries[oIndex];
               usefulBoundaries[usefulIrCount++].end = boundaries[iIndex]-1;
               print( " X\n");
            }
            else
               print( "\n");
         }
      }
      if (usefulIrCount == 0) {
         print( "No suitable boundaries found\n");
         irStart = 0;
         irEnd   = 0;
      }
      else if (usefulIrCount == 1) {
         print( "Only 1 suitable boundary found\n");
         irStart = usefulBoundaries[0].start;
         irEnd   = usefulBoundaries[0].end;
      }
      else {
         print( "> 1 suitable boundary found\n");
         irStart = 0;
         irEnd   = 0;
      }
   }
   confirmStart = FALSE;
   confirmEnd   = FALSE;

   // Sanity Check - There should be IR boundaries at the correct locations.
   for (index=0; index<irCount; index++) {
      if (confirmStart) {
         confirmEnd   = confirmEnd || (boundaries[index] == irEnd+1);
      }
      else {
         confirmStart = (boundaries[index] == irStart);
      }
   }
   confirmEnd   = confirmEnd || (irLength == irEnd+1);

   // Confirm IDCODE boundaries are plausible
   if (!confirmStart)
      print( "Start not confirmed\n");
   if (!confirmEnd)
      print( "End not confirmed\n");
   print( "Device IR[%d...%d]\n", irEnd, irStart);

#if 0
   // Confirm device location by reading IDCODE
   for (index = 0; index <(MAX_JTAG_IR_CHAIN_LENGTH+7)/8; index++)
      irReg[index] = 0xFF;

   // Select device to read IDCODE
   // Set all other devices to BYPASS
   temp[0] = JTAG_Chain::devices[deviceNum].deviceData->idcodeInstruction;
   fillVector(irReg, 1, 0, irLength);
//   insertField(irReg, temp, irStart, irEnd);
   USBDM_jtag_sel_reset();
   USBDM_jtag_sel_shift(IR);
   USBDM_jtag_write(irLength, JTAG_EXIT_IDLE, irReg);
   USBDM_jtag_sel_shift(DR);
   USBDM_JTAG_Read(32+JTAG_Chain::deviceCount-1, JTAG_EXIT_IDLE, irReg);
//   extractField(irReg, temp, deviceNum, deviceNum+32-1);
   if (temp[0] != JTAG_Chain::devices[deviceNum].deviceData->idcode)
      print( "IDCODE not confirmed\n");
#endif
}

//! \brief Erases the currently selected device
//!
//! @param hDlg : handle for dialogue
//!
USBDM_ErrorCode ColdfireUnlockerPanel::eraseDscDevice() {
   unsigned int deviceNumber = 0;
   uint8_t      unlockCommand[1];
   uint8_t      clockDividerValue[1];

   unlockCommand[0]     = unlockInstructionTextControl->GetHexValue();
   clockDividerValue[0] = clockDividerTextControl->GetHexValue();

   print("Erasing JTAG device #%d, Unlock command=%2.2X, Clock Divider=%2.2X\n",
         deviceNumber, unlockCommand[0], clockDividerValue[0]);

   USBDM_ErrorCode rc = BDM_RC_OK;
   do {
      rc = USBDM_SetExtendedOptions(&bdmOptions);
      if (rc != BDM_RC_OK) {
         return rc;
      }
      rc = USBDM_SetTargetTypeWithRetry(T_MC56F80xx);
      if (rc != BDM_RC_OK) {
         return rc;
      }
      USBDM_TargetReset((TargetMode_t)(RESET_SPECIAL|RESET_DEFAULT));
      if (rc != BDM_RC_OK) {
         return rc;
      }
   } while (0);

   deviceNumber = JTAG_Chain::currentDeviceNum;
   JTAG_Chain::reset();
   JTAG_Chain::writeIR(unlockCommand, JTAG_EXIT_SHIFT_DR);
   JTAG_Chain::write(clkdivDrLength, clockDividerValue, JTAG_EXIT_IDLE);
   wxMilliSleep(2000); // Let erase complete
   JTAG_Chain::reset();
   return rc;
}

//! \brief Erases the currently selected device
//!
//! @param hDlg : handle for dialogue
//!
USBDM_ErrorCode ColdfireUnlockerPanel::eraseCFVxDevice() {
   unsigned int deviceNumber = 0;
   uint8_t      unlockCommand[1];
   uint8_t      clockDividerValue[1];

   unlockCommand[0]     = unlockInstructionTextControl->GetHexValue();
   clockDividerValue[0] = clockDividerTextControl->GetHexValue();

   print("Erasing JTAG device #%d, Unlock command=%2.2X, Clock Divider=%2.2X\n",
         deviceNumber, unlockCommand[0], clockDividerValue[0]);

   USBDM_ErrorCode rc = BDM_RC_OK;
   do {
      rc = USBDM_SetExtendedOptions(&bdmOptions);
      if (rc != BDM_RC_OK) {
         return rc;
      }
      rc = USBDM_SetTargetTypeWithRetry(T_CFVx);
      if (rc != BDM_RC_OK) {
         return rc;
      }
      USBDM_TargetReset((TargetMode_t)(RESET_SPECIAL|RESET_DEFAULT));
      if (rc != BDM_RC_OK) {
         return rc;
      }
   } while (0);

   deviceNumber = JTAG_Chain::currentDeviceNum;
   JTAG_Chain::reset();
   JTAG_Chain::writeIR(unlockCommand, JTAG_EXIT_SHIFT_DR);
   JTAG_Chain::write(clkdivDrLength, clockDividerValue, JTAG_EXIT_IDLE);
   wxMilliSleep(2000); // Let erase complete
   JTAG_Chain::reset();

   return rc;
}
