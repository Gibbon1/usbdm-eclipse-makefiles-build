/*
 * clock_private-MKxxM10Z.h
 *
 *  Created on: Nov 6, 2012
 *      Author: podonoghue
 */

#ifndef CLOCK_PRIVATE_H_
#define CLOCK_PRIVATE_H_

#include <stdint.h>
#include "derivative.h"
#include "clock.h"

#ifdef __cplusplus
extern "C" {
#endif

//-------- <<< Use Configuration Wizard in Context Menu >>> -----------------

//===================================
// Validators
// Common clock settings
// <validate=net.sourceforge.usbdm.annotationEditor.validators.ClockValidate_MKxxM10>
// PLL clock
// <validate=net.sourceforge.usbdm.annotationEditor.validators.PllClockValidate>
// FLL clock
// <validate=net.sourceforge.usbdm.annotationEditor.validators.FllClockValidate>

// Convention
// name_V = field value
// name_M = field mask i.e. value in correct position for register

//-------- <<< Use Configuration Wizard in Context Menu >>> -----------------

// OSCCLK_CLOCK ==============================
//
//   <o> Frequency of Main External Clock or Crystal (Hz)  <name=oscclk_clock> <0-50000000>
//   <i> Frequency of external crystal or clock on XTAL/EXTAL
#define OSCCLK_CLOCK (8000000UL)

// OSC32KCLK_CLOCK
// Assumed to be only available when main oscillator operating with 32kHz crystal on XTAL/EXTAL
#if (OSCCLK_CLOCK < 31000) || (OSCCLK_CLOCK> 33000)
#define OSC32KCLK_CLOCK (0)
#else
#define OSC32KCLK_CLOCK OSCCLK_CLOCK
#endif

// RTCCLK_CLOCK ==============================
//
//   <o> Frequency of RTC External Clock or Crystal (Hz) <name=rtcclk_clock>
//   <i> Frequency of external crystal or clock on XTAL32/EXTAL32 [Typically 32768 Hz]
#define RTCCLK_CLOCK (32768UL)

// SYSTEM_LOW_POWER_CLOCK ==============================
//
//   <o> Frequency of Internal Low Power Oscillator Clock (Hz) <constant> <name=system_low_power_clock>
//   <i> Dependent on device. [Typically ~1kHz]
#define SYSTEM_LOW_POWER_CLOCK (1000UL)

// SYSTEM_ERC_CLOCK ==============================
//
//   <o> External Reference Clock (Hz) <constant> <name=system_erc_clock>
//   <i> Derived from the OSCCLK0 (external crystal or clock source on XTAL/EXTAL) or RTC_CLOCK(XTAL32/EXTAL32)
#define SYSTEM_ERC_CLOCK (8000000UL)

// SYSTEM_SLOW_IRC_CLOCK ==============================
//
//   <o> Frequency of Slow Internal Reference Clock (Hz) <constant> <name=system_slow_irc_clock>
//   <i> Dependent on device and clock Trim. [Typically ~32kHz]
#define SYSTEM_SLOW_IRC_CLOCK (32768UL)

// SYSTEM_FAST_IRC_CLOCK ==============================
//
//   <o> Frequency of Fast Internal Reference Clock (Hz) <constant> <name=system_fast_irc_clock>
//   <i> Dependent on device and clock Trim. [Typically ~4MHz]
#define SYSTEM_FAST_IRC_CLOCK (4000000UL)

//========================================================================================
//========================================================================================
// CLOCK_MODE ===============================
//
//   <o> Clock Mode <name=clock_mode>
//   <i> Basic choice for final clock mode
//<i> FLL Engaged Internal(FEI)
//<i> In FEI mode, MCGOUT is derived from the FLL clock (DCOCLK) that is controlled by the 32 kHz Internal Reference Clock (IRC). 
//<i> The FLL loop will lock the DCO frequency to the FLL factor, as selected by the C4[DRST_DRS] and C4[DMX32] bits, times the 
//<i> internal reference frequency.
//<i>
//<i> FLL Engaged External(FEE)
//<i> In FEE mode, MCGOUT is derived from the FLL clock (DCOCLK) that is controlled by the external reference clock. The FLL loop
//<i> will lock the DCO frequency to the FLL factor, as selected by C4[DRST_DRS] and C4[DMX32] bits, times the external reference
//<i> frequency, as specified by the C1[FRDIV] and C2[RANGE].
//<i>
//<i> FLL Bypassed Internal(FBI)
//<i> In FBI mode, the MCGOUT clock is derived either from the slow (32 kHz IRC) or fast (2 MHz IRC) internal reference clock, 
//<i> as selected by the C2[IRCS] bit. The FLL is operational but its output is not used. This mode is useful to allow the FLL
//<i> to acquire its target frequency while the MCGOUT clock is driven from the C2[IRCS] selected internal reference clock. The
//<i> FLL clock (DCOCLK) is controlled by the slow internal reference clock, and the DCO clock frequency locks to a multiplication
//<i> factor, as selected by the C4[DRST_DRS] and C4[DMX32] bits, times the internal reference frequency.
//<i>
//<i> FLL Bypassed External(FBE)
//<i> In FBE mode, the MCGOUT clock is derived from the external reference clock. The FLL is operational but its output is not
//<i> used. This mode is useful to allow the FLL to acquire its target frequency while the MCGOUT clock is driven from the 
//<i> external reference clock. The FLL clock (DCOCLK) is controlled by the external reference clock, and the DCO clock frequency
//<i> locks to a multiplication factor, as selected by the C4[DRST_DRS] and C4[DMX32] bits, times the divided external reference
//<i> frequency. 
//<i>
//<i> PLL Engaged External(PEE)
//<i> In PEE mode, the MCGOUT is derived from the PLL clock, which is controlled by the external reference clock. The PLL clock
//<i> frequency locks to a multiplication factor, as specified by C6[VDIV], times the external reference frequency, as specified 
//<i> by C5[PRDIV]. 
//<i>
//<i> PLL Bypassed External(PBE)
//<i> In PBE mode, MCGOUT is derived from the OSCSEL external reference clock; the PLL is operational, but its output clock is 
//<i> not used. This mode is useful to allow the PLL to acquire its target frequency while MCGOUT is driven from the external 
//<i> reference clock. The PLL clock frequency locks to a multiplication factor, as specified by its [VDIV], times the external
//<i> reference frequency, as specified by its [PRDIV].
//<i>
//<i> Bypassed Low Power Internal (BLPI/FBILP)
//<i> In BLPI mode, MCGOUT is derived from the internal reference clock. The FLL is disabled and PLL is disabled even if the 
//<i> C5[PLLCLKEN] is set to 1. 
//<i>
//<i> Bypassed Low Power External (BLPE/FBELP) 
//<i> In BLPE mode, MCGOUT is derived from the external reference clock. The FLL is disabled and PLL is disabled even if the
//<i> C5[PLLCLKEN] is set to 1.
//     <0=> No setup (Reset default)
//     <1=> FLL Engaged Internal (FEI)
//     <2=> FLL Engaged External (FEE)
//     <3=> FLL bypassed internal (FBI)
//     <4=> Bypassed low power internal (BLPI)
//     <5=> FLL bypassed external (FBE)
//     <6=> Bypassed low power external (BLPE)
//     <7=> PLL Bypassed External (PBE)
//     <8=> PLL Engaged External (PEE)
#define CLOCK_MODE 1

// Clock modes
#define CLOCK_MODE_NONE     0
#define CLOCK_MODE_FEI      1
#define CLOCK_MODE_FEE      2
#define CLOCK_MODE_FBI      3
#define CLOCK_MODE_BLPI     4
#define CLOCK_MODE_FBE      5
#define CLOCK_MODE_BLPE     6
#define CLOCK_MODE_PBE      7
#define CLOCK_MODE_PEE      8

// PLL_TARGET_CLOCK =======================================
//
//  <o> PLL Output clock frequency (Hz) <48000000-100000000> <name=pllTargetFrequency>
//  <i> Used for MCGPLLCLK system clock
//  <i> Used for main MCGOUTCLK system clock if PEE mode is selected.
#define PLL_TARGET_CLOCK 96000000UL

// FLL_TARGET_CLOCK =======================================
//
//  <o> FLL Output clock frequency (Hz) <name=fllTargetFrequency>
//  <i> Used for MCGFLLCLK system clock
//  <i> Used for main MCGOUTCLK system clock if FEI or FEE mode is selected.
#define FLL_TARGET_CLOCK 83886080UL

// SYSTEM_MCGOUT_CLOCK =======================================
//
//  <o> System MCGOUT Clock (Hz) <name=system_mcgout_clock> <constant>
//  <i> MCG Main clock output
//  <i> Derived from slow IRC, fast IRC, ERC, FLL or PLL
#define SYSTEM_MCGOUT_CLOCK 83886080UL

// SYSTEM_MCGIR_CLOCK =======================================
//
//  <o> System MCGIR Clock (Hz) <name=system_mcgir_clock> <constant>
//  <i> MCG Internal Reference Clock
//  <i> Derived from slow IRC or fast IRC
#define SYSTEM_MCGIR_CLOCK 32768UL

// SYSTEM_CORE_CLOCK =======================================
//
//  <o> System Core Clock (Hz) <name=system_core_clock> <constant>
//  <i> Clocks the ARM Cortex-M4 core and bus masters
//  <i> Derived from MCGOUT Clock after division by OUTDIV1
//  <i> Must be less than or equal to 100 MHz. 
#define SYSTEM_CORE_CLOCK 83886080UL

// SYSTEM_BUS_CLOCK =======================================
//
//  <o> System Bus Clock (Hz) <name=system_bus_clock> <constant>
//  <i> Clocks the bus slaves and peripheral
//  <i> Derived from MCGOUT Clock after division by OUTDIV2
//  <i> Must be less than or equal to 50 MHz and less than or equal to the Core Clock frequency. 
//  <i> Must be an integer divisor of the Core Clock. 
#define SYSTEM_BUS_CLOCK 41943040UL

// SYSTEM_FLEXBUS_CLOCK =======================================
//
//  <o> System Flexbus Clock (Hz) <name=system_flexbus_clock> <constant>
//  <i> Clocks the flexbus interface
//  <i> Derived from MCGOUT clock after division by OUTDIV3.
//  <i> Must be less than or equal to 50 MHz and less than or equal to the Bus Clock frequency.
#define SYSTEM_FLEXBUS_CLOCK 41943040UL

// SYSTEM_FLASH_CLOCK =======================================
//
//  <o> System Flash Clock (Hz) <name=system_flash_clock> <constant>
//  <i> Clocks the flash memory
//  <i> Derived from MCGOUT clock after division by OUTDIV4.
//  <i> Must be less than or equal to 25 MHz and less than or equal to the Bus Clock frequency. 
//  <i> Must be an integer divisor of the Core Clock. 
#define SYSTEM_FLASH_CLOCK 20971520UL

// <h> System Clock dividers
// SIM_CLKDIV1_OUTDIV1 ================================
//
//   <o> Core & System Clock Divider (OUTDIV1) - Divide by <1-16> <#-1> <name=sim_clkdiv1_outdiv1>
//   <i> Clocks the ARM Cortex-M4 core and bus masters [SIM_CLKDIV1_OUTDIV1]
//   <i> MCGOUTCLK clock is source. Default /1
#define SIM_CLKDIV1_OUTDIV1_V (0)
#define SIM_CLKDIV1_OUTDIV1_M SIM_CLKDIV1_OUTDIV1(SIM_CLKDIV1_OUTDIV1_V)

// SIM_CLKDIV1_OUTDIV2 ================================
//
//   <o> Bus Clock Divider (OUTDIV2) - Divide by <1-16> <#-1> <name=sim_clkdiv1_outdiv2>
//   <i> Clocks the bus slaves and peripheral [SIM_CLKDIV1_OUTDIV2]
//   <i> MCGOUTCLK clock is source. Default /2
#define SIM_CLKDIV1_OUTDIV2_V (1)
#define SIM_CLKDIV1_OUTDIV2_M SIM_CLKDIV1_OUTDIV2(SIM_CLKDIV1_OUTDIV2_V)

// SIM_CLKDIV1_OUTDIV3 ================================
//
//   <o> Flexbus Clock Divider (OUTDIV3) - Divide by <1-16> <#-1> <name=sim_clkdiv1_outdiv3>
//   <i> Clocks the flexbus interface [SIM_CLKDIV1_OUTDIV3]
//   <i> MCGOUTCLK clock is source. Default /2
#define SIM_CLKDIV1_OUTDIV3_V (1)
#define SIM_CLKDIV1_OUTDIV3_M SIM_CLKDIV1_OUTDIV3(SIM_CLKDIV1_OUTDIV3_V)

// SIM_CLKDIV1_OUTDIV4 ================================
//
//   <o> Flash Clock Divider (OUTDIV4) - Divide by <1-16> <#-1> <name=sim_clkdiv1_outdiv4>
//   <i> Clocks the flash memory [SIM_CLKDIV1_OUTDIV4]
//   <i> MCGOUTCLK clock is source. Default /4
#ifndef SIM_CLKDIV1_OUTDIV4_V
#define SIM_CLKDIV1_OUTDIV4_V (3)
#endif

#define SIM_CLKDIV1_OUTDIV4_M SIM_CLKDIV1_OUTDIV4(SIM_CLKDIV1_OUTDIV4_V)

// </h>

//========================================================================================
//========================================================================================
// <h> OSC Control Register (OSC_CR) 

// OSC_CR_ERCLKEN ===============================
//
//   <q> External Reference Enable (ERCLKEN) 
//   <i> Enables external reference clock [OSC_CR_ERCLKEN]
//     <0=> Disabled
//     <1=> Enabled
#define OSC_CR_ERCLKEN_V 0
#define OSC_CR_ERCLKEN_M (OSC_CR_ERCLKEN_V<<OSC_CR_ERCLKEN_SHIFT)

// OSC_CR_EREFSTEN ===============================
//
//   <q> External Reference Stop Enable (EREFSTEN)
//   <i> Determines if external reference clock is enabled in Stop mode [OSC_CR_EREFSTEN]
//     <0=> Disabled in Stop mode
//     <1=> Enabled in Stop mode
#define OSC_CR_EREFSTEN_V 0
#define OSC_CR_EREFSTEN_M (OSC_CR_EREFSTEN_V<<OSC_CR_EREFSTEN_SHIFT)

// OSC_CR_SC2P ===============================
//
//   <q0> Oscillator Capacitor Load Configure
//   <i> Configures the oscillator load capacitance [OSC_CR_SC2P]
//     <0=>
//     <1=> +2pF

// OSC_CR_SC4P ===============================
//
//   <q1> Oscillator Capacitor Load Configure
//   <i> Configures the oscillator load capacitance [OSC_CR_SC4P]
//     <0=>
//     <1=> +4pF

// OSC_CR_SC8P ===============================
//
//   <q2> Oscillator Capacitor Load Configure
//   <i> Configures the oscillator load capacitance [OSC_CR_SC8P]
//     <0=>
//     <1=> +8pF

// OSC_CR_SC16P ===============================
//
//   <q3> Oscillator Capacitor Load Configure
//   <i> Configures the oscillator load capacitance [OSC_CR_SC16P]
//     <0=>
//     <1=> +16pF

#define OSC_CR_SCP_M ((0<<OSC_CR_SC2P_SHIFT)|(0<<OSC_CR_SC4P_SHIFT)|(1<<OSC_CR_SC8P_SHIFT)|(0<<OSC_CR_SC16P_SHIFT))
// </h>

//========================================================================================
//========================================================================================
// <h> RTC Control Register (RTC_CR)
	
// RTC_CR_OSCE ===============================
//
//   <q> RTC Oscillator Enable (OSCE)
//   <i> Enables 32.768 kHz RTC oscillator[RTC_CR_OSCE]
//     <0=> Disabled
//     <1=> Enabled
#define RTC_CR_OSCE_V 1
#define RTC_CR_OSCE_M (RTC_CR_OSCE_V<<RTC_CR_OSCE_SHIFT)

// RTC_CR_CLKO ===============================
//
//   <q> RTC 32kHz Clock Output (CLKO)
//   <i> Determines if RTC 32kHz Clock is available to peripherals [RTC_CR_CLKO]
//     <0=> The 32kHz clock is output to other peripherals
//     <1=> The 32kHz clock is not output to other peripherals
#define RTC_CR_CLKO_V 0
#define RTC_CR_CLKO_M (RTC_CR_CLKO_V<<RTC_CR_CLKO_SHIFT)

// RTC_CR_UM ===============================
//
//   <q> Update Mode (UM)
//   <i> Allows the SR[TCE] to be written even when the Status Register is locked. [RTC_CR_UM]
//   <i> When set, the SR[TCE] can always be written if the SR[TIF] or SR[TOF] are set or if the SR[TCE] is clear.
//     <0=> Registers cannot be written when locked.
//     <1=> Registers can be written when locked under limited conditions
#define RTC_CR_UM_V 0
#define RTC_CR_UM_M (RTC_CR_UM_V<<RTC_CR_UM_SHIFT)

// RTC_CR_SUP ===============================
//
//   <q> Supervisor Access (SUP)
//   <i> Determines if the RTC register access is available in non-supervisor mode [RTC_CR_SUP]
//   <i> Non supported write accesses generate a bus error.
//     <0=> Non-supervisor mode write accesses are not supported
//     <1=> Non-supervisor mode write accesses are supported
#define RTC_CR_SUP_V 1
#define RTC_CR_SUP_M (RTC_CR_SUP_V<<RTC_CR_SUP_SHIFT)

// RTC_CR_WPE ===============================
//
//   <q> Wakeup Pin Enable (WPE)
//   <i> Determines if the wakeup pin is asserted on RTC interrupt when powered done [RTC_CR_WPE]
//   <i> The wakeup pin is optional and not available on all devices.
//     <0=> Wakeup pin is disabled.
//     <1=> Wakeup pin is enabled.
#define RTC_CR_WPE_V 0
#define RTC_CR_WPE_M (RTC_CR_WPE_V<<RTC_CR_WPE_SHIFT)

// RTC_CR_SC2P ===============================
//
//   <q0> Oscillator Capacitor Load Configure
//   <i> Configures the oscillator load capacitance [RTC_CR_SC2P]
//     <0=>
//     <1=> +2pF

// RTC_CR_SC4P ===============================
//
//   <q1> Oscillator Capacitor Load Configure
//   <i> Configures the oscillator load capacitance [RTC_CR_SC4P]
//     <0=>
//     <1=> +4pF

// RTC_CR_SC8P ===============================
//
//   <q2> Oscillator Capacitor Load Configure
//   <i> Configures the oscillator load capacitance [RTC_CR_SC8P]
//     <0=>
//     <1=> +8pF

// RTC_CR_SC16P ===============================
//
//   <q3> Oscillator Capacitor Load Configure
//   <i> Configures the oscillator load capacitance [RTC_CR_SC16P]
//     <0=>
//     <1=> +16pF

#define RTC_CR_SCP_M ((0<<RTC_CR_SC2P_SHIFT)|(0<<RTC_CR_SC4P_SHIFT)|(1<<RTC_CR_SC8P_SHIFT)|(0<<RTC_CR_SC16P_SHIFT))
// </h>

//========================================================================================
//========================================================================================
// <h> MCG Control Register 1 (MCG_C1)

// MCG_C1_CLKS =======================================
//
//  <o> MCGOUTCLK Clock Source Select (CLKS) [0-2] <constant> <name=mcg_c1_clks>
//  <i> Selects the clock source for MCGOUTCLK [MCG_C1_CLKS]
//  <i> This option is determined by the Clock Mode selection
//      <0=> Output of FLL or PLL is selected
//      <1=> Internal reference clock is selected
//      <2=> External reference clock is selected
#define MCG_C1_CLKS_V 0
#define MCG_C1_CLKS_M MCG_C1_CLKS(MCG_C1_CLKS_V)

// MCG_C1_FRDIV ================================
//
//   <o> FLL External Reference Divider (FRDIV) <0-7> <constant> <name=mcg_c1_frdiv>
//   <i> Selects the amount to divide down the external reference clock for the FLL. [MCG_C1_FRDIV]
//   <i> The resulting frequency must be in the range 31.25 kHz to 39.0625 kHz
//   <i> Division factor depends on Clock Range [MGC_C2_RANGE0]
//   <i> This option is determined by the Clock Mode and FLL input clock
//      <0=> Divide by 1 or 32
//      <1=> Divide by 2 or 64
//      <2=> Divide by 4 or 128
//      <3=> Divide by 8 or 256
//      <4=> Divide by 16 or 512
//      <5=> Divide by 32 or 1024
//      <6=> Divide by 64 or 1280
//      <7=> Divide by 128 or 1536
#define MCG_C1_FRDIV_V 3
#define MCG_C1_FRDIV_M (MCG_C1_FRDIV_V<<MCG_C1_FRDIV_SHIFT)

// MCG_C1_IREFS ================================
//
//   <o> Internal Reference Select (IREFS) <constant> <name=mcg_c1_irefs>
//   <i> Selects the reference clock source for the FLL [MCG_C1_IREFS]
//   <i> This option is determined by the Clock Mode selection
//      <0=> External Reference Clock
//      <1=> Slow Internal Clock
#define MCG_C1_IREFS_V 1
#define MCG_C1_IREFS_M (MCG_C1_IREFS_V<<MCG_C1_IREFS_SHIFT)

// MCG_C1_IRCLKEN ==============================
//
//   <q> Internal Reference Clock Enable (IRCLKEN)
//   <i> Enables the internal reference clock for use as MCGIRCLK [MCG_C1_IRCLKEN]
//      <0=> Inactive
//      <1=> Active
#define MCG_C1_IRCLKEN_V   0
#define MCG_C1_IRCLKEN_M   (1<<MCG_C1_IRCLKEN_SHIFT)

// MCG_C1_IREFSTEN =============================
//
//   <q> Internal Reference Stop Enable (IREFSTEN)
//   <i> Determines if IRS is enabled in Stop mode [MCG_C1_IREFSTEN]
//      <0=> IR disabled in STOP
//      <1=> IR enabled in STOP
#define MCG_C1_IREFSTEN_V   0
#define MCG_C1_IREFSTEN_M   (MCG_C1_IREFSTEN_V<<MCG_C1_IREFSTEN_SHIFT)

// </h>

//========================================================================================
//========================================================================================
// <h> MCG Control Register 2 (MCG_C2)


// MCG_C2_RANGE =============================
//
//   <o> Frequency Range Select (RANGE) <constant> <name=mcg_c2_range0>
//   <i> Selects the frequency range for the crystal oscillator or external clock source [MCG_C2_RANGE0]
//   <i> This value is calculated from the FLL input clock frequency
//      <0=> Low range
//      <1=> High range
//      <2=> Very High range
#define MCG_C2_RANGE_V   1
#define MCG_C2_RANGE_M   (MCG_C2_RANGE_V<<MCG_C2_RANGE_SHIFT)

// MCG_C2_HGO =============================
//
//   <q> Oscillator Gain (HGO)
//   <i> Controls the crystal oscillator mode of operation [MCG_C2_HGO]
//      <0=> Low power
//      <1=> High gain
#define MCG_C2_HGO_V   0
#define MCG_C2_HGO_M   (MCG_C2_HGO_V<<MCG_C2_HGO_SHIFT)

// MCG_C2_EREFS0 =============================
//
//   <q> External Reference Select (EREFS0) <name=mcg_c2_erefs0>
//   <i> Determines whether a clock or crystal is used for the external reference clock [C2_EREFS0]
//      <0=> External clock
//      <1=> Oscillator
#define MCG_C2_EREFS_V  1
#define MCG_C2_EREFS_M (MCG_C2_EREFS_V<<MCG_C2_EREFS_SHIFT)

// MCG_C2_LP =============================
//
//   <o> Low Power Select (LP) <constant> <name=mcg_c2_lp>
//   <i> Whether FLL continues operation when bypassed [MCG_C2_LP]
//   <i> This option is determined by the Clock Mode selection
//      <0=> FLL is enabled in bypass modes
//      <1=> FLL is disabled in bypass modes
#define MCG_C2_LP_V  0
#define MCG_C2_LP_M (MCG_C2_LP_V<<MCG_C2_LP_SHIFT)

// MCG_C2_IRCS ==============================
//
//   <q> MCG IRC Clock Source (IRCS) <name=mcg_c2_ircs>
//   <i> MCG Internal Clock Source [MCG_C2_IRCS]
//     <0=> Slow internal reference clock
//     <1=> Fast internal reference clock
#define MCG_C2_IRCS_V 0
#define MCG_C2_IRCS_M (MCG_C2_IRCS_V<<MCG_C2_IRCS_SHIFT)

// </h>

//========================================================================================
//========================================================================================
// <h> MCG Control Register 4 (MCG_C4)

// MCG_C4_DMX32 ==============================
//
//   <q> DMX32 DCO lock range (DMX32) <name=mcg_c4_dmx32>
//   <i> Optimise for 32.768 kHz Reference [MCG_C4_DMX32]
//     <0=> Wide lock range 31.25-39.06 kHz
//     <1=> Optimised for 32.768 kHz reference
#define MCG_C4_DMX32_V  0
#define MCG_C4_DMX32_M (MCG_C4_DMX32_V<<MCG_C4_DMX32_SHIFT)

// MCG_C4_DRST_DRS =============================
//
//   <o> DCO Range Select (DRST_DRS) <constant> <0-3> <name=mcg_c4_drst_drs>
//   <i> Frequency range for the FLL output, DCOOUT [MCG_C4_DRST_DRS]
//      <0=> Low (x640/x732, 20-25/24 MHz)
//      <1=> Mid (x1280/x1464, 40-50/48 MHz)
//      <2=> Mid-high (x1920/x2197, 60-75/72 MHz)
//      <3=> High (x2560/x2929, 80-100/96 MHz)
#define MCG_C4_DRST_DRS_V  3
#define MCG_C4_DRST_DRS_M (MCG_C4_DRST_DRS_V<<MCG_C4_DRST_DRS_SHIFT)

// </h>

//========================================================================================
//========================================================================================
// <h> MCG Control Register 5 (MCG_C5)

// MCG_C5_PLLCLKEN ==============================
//
//   <q> PLL Clock Enable (PLLCLKEN)
//   <i> Enables the PLL independent of PLLS and enables the PLL clock for use as MCGPLLCLK. [MCG_C5_PLLCLKEN]
//     <0=> MCGPLLCLK is inactive.
//     <1=> MCGPLLCLK is active.
#define MCG_C5_PLLCLKEN_V    0
#define MCG_C5_PLLCLKEN_M   (MCG_C5_PLLCLKEN_V<<MCG_C5_PLLCLKEN_SHIFT)

// MCG_C5_PLLSTEN ==============================
//
//   <q> PLL Stop Enable (PLLSTEN)
//   <i> Enables the PLL Clock during Normal Stop. [MCG_C5_PLLSTEN]
//     <0=> MCGPLLCLK is disabled in any Stop mode.
//     <1=> MCGPLLCLK is enabled in Normal Stop mode.
#define MCG_C5_PLLSTEN_V    0
#define MCG_C5_PLLSTEN_M   (MCG_C5_PLLSTEN_V<<MCG_C5_PLLSTEN_SHIFT)

// MCG_C5_PRDIV ==============================
//
//   <o> PLL External Reference Divider (PRDIV0) Divide by: <name=mcg_c5_prdiv0>  <#-1> <1-24>
//   <i> Determines the amount to divide down the external reference clock for the PLL. [MCG_C5_PRDIV0]
//   <i> This value is calculated from PLL input and output clock frequencies
#define MCG_C5_PRDIV_V    1
#define MCG_C5_PRDIV_M   (MCG_C5_PRDIV_V<<MCG_C5_PRDIV_SHIFT)

// </h>

//========================================================================================
//========================================================================================
// <h> MCG Control Register 6 (MCG_C6)

// MCG_C6_LOLIE ==============================
//
//   <q> Loss of Lock interrupt Enable (LOLIE0)
//   <i> Determines if an interrupt request is made following a loss of lock indication. [MCG_C6_LOLIE]
//   <i> This bit only has an effect when LOLS 0 is set.
//     <0=> No interrupt request
//     <1=> Interrupt request on LOL
#define MCG_C6_LOLIE_V    0
#define MCG_C6_LOLIE_M   (MCG_C6_LOLIE_V<<MCG_C6_LOLIE_SHIFT)

// MCG_C6_PLLS ==============================
//
//   <o> FLL/PLL selected as Clock source when CLKS=0 (PLLS) <constant> <name=mcg_c6_plls>
//   <i> Selects PLL or FLL output [MCG_C6_PLLS]
//     <0=> FLL is selected
//     <1=> PLL is selected
#define MCG_C6_PLLS_V    0
#define MCG_C6_PLLS_M   (MCG_C6_PLLS_V<<MCG_C6_PLLS_SHIFT)

// MCG_C6_CME ==============================
//
//   <q> Clock Monitor Enable (CME)
//   <i> Determines if a reset request is made following a loss of external clock indication. [MCG_C6_CME]
//   <i> This field must be set to a logic 1 only when the ICS is in an operational mode that uses the external clock (FEE, FBE, or FBELP).
//      <0=> Clock monitor is disabled.
//      <1=> Clock monitor is enabled.
#define MCG_C6_CME_V (0)
#define MCG_C6_CME_M (MCG_C6_CME_V<<MCG_C6_CME_SHIFT)

// MCG_C6_VDIV ==============================
//
//   <o> VCO Divider (VDIV) Multiply by: <constant> <name=mcg_c6_vdiv0> <#-24>
//   <i> Determines the multiplication factor for the reference clock of the PLL. [MCG_C6_VDIV]
//   <i> This value is calculated from PLL input and output clock frequencies
#define MCG_C6_VDIV_V (0)
#define MCG_C6_VDIV_M (MCG_C6_VDIV_V<<MCG_C6_VDIV_SHIFT)

// </h>


// ERC_AFTER_FRDIV_CLOCK = External reference clock after dividers
#if (MCG_C2_RANGE_V == 0)
#define ERC_AFTER_FRDIV_CLOCK (SYSTEM_OSCER_CLOCK/(1<<MCG_C1_FRDIV_V))
#elif (MCG_C1_FRDIV_V <= 5)
#define ERC_AFTER_FRDIV_CLOCK (SYSTEM_OSCER_CLOCK/(1<<(MCG_C1_FRDIV_V+5)))
#elif (MCG_C1_FRDIV_V == 6)
#define ERC_AFTER_FRDIV_CLOCK (SYSTEM_OSCER_CLOCK/(1<<5)/40)
#elif (MCG_C1_FRDIV_V == 7)
#define ERC_AFTER_FRDIV_CLOCK (SYSTEM_OSCER_CLOCK/(1<<5)/48)
#endif

// SYSTEM_MCGFF_CLOCK  ==============================
// Only available if less than 1/8 MCGOUT clock
#if (MCG_C1_IREFS_V == 0)
#define SYSTEM_MCGFF_CLOCK (ERC_AFTER_FRDIV_CLOCK/2)  // External Reference clock after dividers
#else
#define SYSTEM_MCGFF_CLOCK (SYSTEM_SLOW_IRC_CLOCK/2)  // Slow internal clock (nominally 32 kHz)
#endif

// SYSTEM_PERIPHERAL_CLOCK  ==============================
// <h> Peripheral Clock Source Selection

// SIM_SOPT2_PLLFLLSEL =============================
//
//   <q> Peripheral clock source (PLL/FLL)
//   <i> Source for clock used by some peripherals [SIM_SOPT2_PLLFLLSEL]
//      <0=> FLL (MCGFLLCLK)
//      <1=> PLL (MCGPLLCLK)
#define SIM_SOPT2_PLLFLLSEL_V  1
#define SIM_SOPT2_PLLFLLSEL_M (SIM_SOPT2_PLLFLLSEL_V<<SIM_SOPT2_PLLFLLSEL_SHIFT)

#if (SIM_SOPT2_PLLFLLSEL_V == 0) 
#define SYSTEM_PERIPHERAL_CLOCK SYSTEM_MCGFLL_CLOCK
#else
#define SYSTEM_PERIPHERAL_CLOCK SYSTEM_MCGPLL_CLOCK
#endif


// SIM_SOPT1_OSC32KSEL ================================
//
//   <o> 32kHz Clock Source (ERCLK32)
//   <i> Source for nominal 32K clock for peripherals [SIM_SOPT1_OSC32KSEL]
//     <0=> System Oscillator (OSC32KCLK)
//     <1=> RTC 32.768kHz oscillator
#define SIM_SOPT1_OSC32KSEL_V (1)
#define SIM_SOPT1_OSC32KSEL_M (1<<SIM_SOPT1_OSC32KSEL_SHIFT)

#if SIM_SOPT1_OSC32KSEL_V == 0
#define SYSTEM_ERCLK32_CLOCK OSC32KCLK_CLOCK          // Main Oscillator operating in 32kHz mode
#elif SIM_SOPT1_OSC32KSEL_V == 1
#define SYSTEM_ERCLK32_CLOCK SYSTEM_LOW_POWER_CLOCK   // LPO
#else
#error "Invalid ERCLK32 clock selected"
#endif

// LPTMR0_CLKSRC ==============================
//
//   <o> LPTMR0 Clock Source
//   <i> Low Power Timer clock source - [LPTMR0_PSR_PCS]
//     <0=> MCG Internal Reference Clock (MCGIRCLK)
//     <1=> Low power oscillator (LPO - 1kHz)
//     <2=> 32kHz Clock Source (ERCLK32)
//     <3=> Oscillator External Reference Clock (OSCERCLK)
#define LPTMR0_CLKSRC_M LPTMR0_PSR_PCS(0)

#if (LPTMR0_CLKSRC_M == LPTMR0_PSR_PCS(0))
#define SYSTEM_LPTMR0_CLOCK SYSTEM_MCGIR_CLOCK
#elif (LPTMR0_CLKSRC_M == LPTMR0_PSR_PCS(1))
#define SYSTEM_LPTMR0_CLOCK SYSTEM_LOW_POWER_CLOCK
#elif (LPTMR0_CLKSRC_M == LPTMR0_PSR_PCS(2))
#define SYSTEM_LPTMR0_CLOCK SYSTEM_ERCLK32_CLOCK
#elif (LPTMR0_CLKSRC_M == LPTMR0_PSR_PCS(3))
#define SYSTEM_LPTMR0_CLOCK SYSTEM_OSCER_CLOCK
#endif

#define SYSTEM_UART0_CLOCK SystemCoreClock
#define SYSTEM_UART1_CLOCK SystemCoreClock
#define SYSTEM_UART2_CLOCK SystemBusClock
#define SYSTEM_UART3_CLOCK SystemBusClock
#define SYSTEM_UART4_CLOCK SystemBusClock
#define SYSTEM_UART5_CLOCK SystemBusClock

// </h>

// ERRATA_E2448 ================================
//
//   <q> Implement work-around for ERRATA E2448
#define ERRATA_E2448 (0)

// SYSTEM_OSCER_CLOCK ================================
// Always connected to main oscillator
#define SYSTEM_OSCER_CLOCK OSCCLK_CLOCK

// SYSTEM_MCGPLL_CLOCK  ==============================
#define SYSTEM_MCGPLL_CLOCK PLL_TARGET_CLOCK

// MCGFLLCLK_CLOCK  ==============================
#define SYSTEM_MCGFLL_CLOCK FLL_TARGET_CLOCK

/*
 * The following are 'public' definitions
 *
 * SYSTEM_MCGIR_CLOCK   	MCG Internal Reference clock
 * SYSTEM_MCGFF_CLOCK  		MCG Fixed Frequency ! (from SlowIRC/ERC_DIV/Peripheral bus clock)
 * SYSTEM_MCGFLL_CLOCK  	MCG FLL clock (from FLL)
 * SYSTEM_MCGPLL_CLOCK  	MCG PLL clock (from PLL)
 * SYSTEM_MCGOUT_CLOCK      MCG OUT clock (from SlowIRC/FastIRC/ExternalRC/PLL/FLL)
 * SYSTEM_PERIPHERAL_CLOCK	Peripheral clock
 * SYSTEM_OSCER_CLOCK		Main oscillator/clock
 * SYSTEM_OSC32K_CLOCK      32kHz oscillator/clock
 * SYSTEM_BUS_CLOCK
 * SYSTEM_CORE_CLOCK
 */

void clock_initialise(void);

#ifdef __cplusplus
}
#endif

#endif /* CLOCK_PRIVATE_H_ */
