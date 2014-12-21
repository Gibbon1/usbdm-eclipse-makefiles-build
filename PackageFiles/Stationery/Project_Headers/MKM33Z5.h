/****************************************************************************************************//**
 * @file     MKM33Z5.h
 *
 * @brief    CMSIS Cortex-M Peripheral Access Layer Header File for MKM33Z5.
 *           Equivalent: MKM33Z64M5, MKM33Z128M5
 *
 * @version  V0.0
 * @date     2014/12
 *
 *******************************************************************************************************/

#ifndef MCU_MKM33Z5
#define MCU_MKM33Z5

#include <stdint.h>
#ifdef __cplusplus
extern "C" {
#endif

/* -------------------------  Interrupt Number Definition  ------------------------ */

typedef enum {
/* ------------------------  Processor Exceptions Numbers  ------------------------- */
  Reset_IRQn                    = -15,   /*!<   1 Reset Vector, invoked on Power up and warm reset                                 */
  NonMaskableInt_IRQn           = -14,   /*!<   2 Non maskable Interrupt, cannot be stopped or preempted                           */
  HardFault_IRQn                = -13,   /*!<   3 Hard Fault, all classes of Fault                                                 */
  MemoryManagement_IRQn         = -12,   /*!<   4 Memory Management, MPU mismatch, including Access Violation and No Match         */
  BusFault_IRQn                 = -11,   /*!<   5 Bus Fault, Pre-Fetch-, Memory Access Fault, other address/memory related Fault   */
  UsageFault_IRQn               = -10,   /*!<   6 Usage Fault, i.e. Undef Instruction, Illegal State Transition                    */
  SVCall_IRQn                   =  -5,   /*!<  11 System Service Call via SVC instruction                                          */
  DebugMonitor_IRQn             =  -4,   /*!<  12 Debug Monitor                                                                    */
  PendSV_IRQn                   =  -2,   /*!<  14 Pendable request for system service                                              */
  SysTick_IRQn                  =  -1,   /*!<  15 System Tick Timer                                                                */
/* ----------------------   MKM33Z4 VectorTable                      ---------------------- */
  DMA0_IRQn                     =   0,   /*!<  16 DMA0 Transfer complete                                                           */
  DMA1_IRQn                     =   1,   /*!<  17 DMA1 Transfer complete                                                           */
  DMA2_IRQn                     =   2,   /*!<  18 DMA2 Transfer complete                                                           */
  DMA3_IRQn                     =   3,   /*!<  19 DMA3 Transfer complete                                                           */
  SPI0_IRQn                     =   4,   /*!<  20 Serial Peripheral Interface 0                                                    */
  SPI1_IRQn                     =   5,   /*!<  21 Serial Peripheral Interface 1                                                    */
  PMC_IRQn                      =   6,   /*!<  22 Low-voltage detect, low-voltage warning                                          */
  TMR_0_IRQn                    =   7,   /*!<  23 Quad Timer Channel 0                                                             */
  TMR_1_IRQn                    =   8,   /*!<  24 Quad Timer Channel 1                                                             */
  TMR_2_IRQn                    =   9,   /*!<  25 Quad Timer Channel 2                                                             */
  TMR_3_IRQn                    =  10,   /*!<  26 Quad Timer Channel 3                                                             */
  PIT0_1_IRQn                   =  11,   /*!<  27 ORed Interrupt of PITs                                                           */
  LLWU_IRQn                     =  12,   /*!<  28 Low Leakage Wakeup                                                               */
  FTFA_IRQn                     =  13,   /*!<  29 FTFA Command complete or error                                                   */
  CMP0_1_IRQn                   =  14,   /*!<  30 ORed Interrupt of PRACMP                                                         */
  SLCD_IRQn                     =  15,   /*!<  31 ORed Interrupt of SLCD                                                           */
  ADC_IRQn                      =  16,   /*!<  32 ORed Interrupt from SAR                                                          */
  PTx_IRQn                      =  17,   /*!<  33 ORed Interrupt from all GPIO (PTx) ports                                         */
  RNGA_IRQn                     =  18,   /*!<  34 ORed Interrupt from RNGA                                                         */
  UART0_1_IRQn                  =  19,   /*!<  35 ORed Interrupt UART0 and UART1                                                   */
  UART2_3_IRQn                  =  20,   /*!<  36 ORed Interrupt UART2 and UART3                                                   */
  AFE_CH0_IRQn                  =  21,   /*!<  37 AFE Channel 0 ORed Interrupt                                                     */
  AFE_CH1_IRQn                  =  22,   /*!<  38 AFE Channel 1 ORed Interrupt                                                     */
  AFE_CH2_IRQn                  =  23,   /*!<  39 AFE Channel 2 ORed Interrupt                                                     */
  AFE_CH3_IRQn                  =  24,   /*!<  40 AFE Channel 3 ORed Interrupt                                                     */
  iRTC_IRQn                     =  25,   /*!<  41 iRTC Interrupt                                                                   */
  I2C0_1_IRQn                   =  26,   /*!<  42 ORed I2C interrupt                                                               */
  EWM_IRQn                      =  27,   /*!<  43 External Watchdog Monitor                                                        */
  MCG_IRQn                      =  28,   /*!<  44 MCG Loss of Clock, Loss of Lock                                                  */
  WDOG_IRQn                     =  29,   /*!<  45 ORed WDOG Interrupt                                                              */
  LPTMR_IRQn                    =  30,   /*!<  46 ORed LPTMR Interrupt                                                             */
  XBAR_IRQn                     =  31,   /*!<  47 Peripheral XBAR ORed Interrupt                                                   */
} IRQn_Type;

/* -------------------------  Exception Handlers  ------------------------ */
extern void NMI_Handler(void);
extern void HardFault_Handler(void);
extern void MemManage_Handler(void);
extern void BusFault_Handler(void);
extern void UsageFault_Handler(void);
extern void SVC_Handler(void);
extern void DebugMon_Handler(void);
extern void PendSV_Handler(void);
extern void SysTick_Handler(void);
extern void DMA0_IRQHandler(void);
extern void DMA1_IRQHandler(void);
extern void DMA2_IRQHandler(void);
extern void DMA3_IRQHandler(void);
extern void SPI0_IRQHandler(void);
extern void SPI1_IRQHandler(void);
extern void PMC_IRQHandler(void);
extern void TMR_0_IRQHandler(void);
extern void TMR_1_IRQHandler(void);
extern void TMR_2_IRQHandler(void);
extern void TMR_3_IRQHandler(void);
extern void PIT0_1_IRQHandler(void);
extern void LLWU_IRQHandler(void);
extern void FTFA_IRQHandler(void);
extern void CMP0_1_IRQHandler(void);
extern void SLCD_IRQHandler(void);
extern void ADC_IRQHandler(void);
extern void PTx_IRQHandler(void);
extern void RNGA_IRQHandler(void);
extern void UART0_1_IRQHandler(void);
extern void UART2_3_IRQHandler(void);
extern void AFE_CH0_IRQHandler(void);
extern void AFE_CH1_IRQHandler(void);
extern void AFE_CH2_IRQHandler(void);
extern void AFE_CH3_IRQHandler(void);
extern void iRTC_IRQHandler(void);
extern void I2C0_1_IRQHandler(void);
extern void EWM_IRQHandler(void);
extern void MCG_IRQHandler(void);
extern void WDOG_IRQHandler(void);
extern void LPTMR_IRQHandler(void);
extern void XBAR_IRQHandler(void);

/* ================================================================================ */
/* ================      Processor and Core Peripheral Section     ================ */
/* ================================================================================ */

/* ----------------Configuration of the cm4 Processor and Core Peripherals---------------- */
#define __CM0PLUS_REV                0x0100
#define __MPU_PRESENT            0
#define __NVIC_PRIO_BITS         2
#define __Vendor_SysTickConfig   0
#define __FPU_PRESENT            0

#include <core_cm0plus.h>   /*!< Processor and core peripherals */

#ifndef __IO
#define __IO volatile 
#endif

#ifndef __I
#define __I volatile const
#endif

#ifndef __O
#define __O volatile
#endif


/* ================================================================================ */
/* ================       Device Specific Peripheral Section       ================ */
/* ================================================================================ */



/* -------------------  Start of section using anonymous unions  ------------------ */
#if defined(__CC_ARM)
  #pragma push
  #pragma anon_unions
#elif defined(__ICCARM__)
  #pragma language=extended
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__TMS470__)
/* anonymous unions are enabled by default */
#elif defined(__TASKING__)
  #pragma warning 586
#else
  #warning Not supported compiler type
#endif

/* ================================================================================ */
/* ================           CRC (file:CRC_MKM)                   ================ */
/* ================================================================================ */

/**
 * @brief Cyclic Redundancy Check
 */
typedef struct {                                /*!<       CRC Structure                                                */
   union {                                      /*!< 0000: (size=0004)                                                  */
      __IO uint32_t  DATA;                      /*!< 0000: Data register                                                */
      struct {                                  /*!< 0000: (size=0004)                                                  */
         union {                                /*!< 0000: (size=0002)                                                  */
            __IO uint16_t  DATAL;               /*!< 0000: DATAL register                                               */
            struct {                            /*!< 0000: (size=0002)                                                  */
               __IO uint8_t   DATALL;           /*!< 0000: DATALL register                                              */
               __IO uint8_t   DATALU;           /*!< 0001: DATALU register                                              */
            };
         };
         union {                                /*!< 0000: (size=0002)                                                  */
            __IO uint16_t  DATAH;               /*!< 0002: DATAH register                                               */
            struct {                            /*!< 0000: (size=0002)                                                  */
               __IO uint8_t   DATAHL;           /*!< 0002: DATAHL register                                              */
               __IO uint8_t   DATAHU;           /*!< 0003: DATAHU register                                              */
            };
         };
      };
   };
   union {                                      /*!< 0000: (size=0004)                                                  */
      __IO uint32_t  GPOLY;                     /*!< 0004: Polynomial register                                          */
      struct {                                  /*!< 0000: (size=0004)                                                  */
         union {                                /*!< 0000: (size=0002)                                                  */
            __IO uint16_t  GPOLYL;              /*!< 0004: GPOLYL register                                              */
            struct {                            /*!< 0000: (size=0002)                                                  */
               __IO uint8_t   GPOLYLL;          /*!< 0004: GPOLYLL register                                             */
               __IO uint8_t   GPOLYLU;          /*!< 0005: GPOLYLU register                                             */
            };
         };
         union {                                /*!< 0000: (size=0002)                                                  */
            __IO uint16_t  GPOLYH;              /*!< 0006: GPOLYH register                                              */
            struct {                            /*!< 0000: (size=0002)                                                  */
               __IO uint8_t   GPOLYHL;          /*!< 0006: GPOLYHL register                                             */
               __IO uint8_t   GPOLYHU;          /*!< 0007: GPOLYHU register                                             */
            };
         };
      };
   };
   union {                                      /*!< 0000: (size=0004)                                                  */
      __IO uint32_t  CTRL;                      /*!< 0008: Control register                                             */
      struct {                                  /*!< 0000: (size=0004)                                                  */
         __I  uint8_t   RESERVED0[3];           /*!< 0008:                                                              */
         __IO uint8_t   CTRLHU;                 /*!< 000B: Control register (byte access)                               */
      };
   };
} CRC_Type;


/* -------------------------------------------------------------------------------- */
/* -----------     'CRC' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */


/* ------- CRC_DATA                                 ------ */
#define CRC_DATA_LL_MASK                         (0xFFUL << CRC_DATA_LL_SHIFT)                       /*!< CRC_DATA: LL Mask                       */
#define CRC_DATA_LL_SHIFT                        0                                                   /*!< CRC_DATA: LL Position                   */
#define CRC_DATA_LL(x)                           (((x)<<CRC_DATA_LL_SHIFT)&CRC_DATA_LL_MASK)         /*!< CRC_DATA                                */
#define CRC_DATA_LU_MASK                         (0xFFUL << CRC_DATA_LU_SHIFT)                       /*!< CRC_DATA: LU Mask                       */
#define CRC_DATA_LU_SHIFT                        8                                                   /*!< CRC_DATA: LU Position                   */
#define CRC_DATA_LU(x)                           (((x)<<CRC_DATA_LU_SHIFT)&CRC_DATA_LU_MASK)         /*!< CRC_DATA                                */
#define CRC_DATA_HL_MASK                         (0xFFUL << CRC_DATA_HL_SHIFT)                       /*!< CRC_DATA: HL Mask                       */
#define CRC_DATA_HL_SHIFT                        16                                                  /*!< CRC_DATA: HL Position                   */
#define CRC_DATA_HL(x)                           (((x)<<CRC_DATA_HL_SHIFT)&CRC_DATA_HL_MASK)         /*!< CRC_DATA                                */
#define CRC_DATA_HU_MASK                         (0xFFUL << CRC_DATA_HU_SHIFT)                       /*!< CRC_DATA: HU Mask                       */
#define CRC_DATA_HU_SHIFT                        24                                                  /*!< CRC_DATA: HU Position                   */
#define CRC_DATA_HU(x)                           (((x)<<CRC_DATA_HU_SHIFT)&CRC_DATA_HU_MASK)         /*!< CRC_DATA                                */

/* ------- CRC_DATAL                                ------ */
#define CRC_DATAL_DATAL_MASK                     (0xFFFFUL << CRC_DATAL_DATAL_SHIFT)                 /*!< CRC_DATAL: DATAL Mask                   */
#define CRC_DATAL_DATAL_SHIFT                    0                                                   /*!< CRC_DATAL: DATAL Position               */
#define CRC_DATAL_DATAL(x)                       (((x)<<CRC_DATAL_DATAL_SHIFT)&CRC_DATAL_DATAL_MASK) /*!< CRC_DATAL                               */

/* ------- CRC_DATALL                               ------ */
#define CRC_DATALL_DATALL_MASK                   (0xFFUL << CRC_DATALL_DATALL_SHIFT)                 /*!< CRC_DATALL: DATALL Mask                 */
#define CRC_DATALL_DATALL_SHIFT                  0                                                   /*!< CRC_DATALL: DATALL Position             */
#define CRC_DATALL_DATALL(x)                     (((x)<<CRC_DATALL_DATALL_SHIFT)&CRC_DATALL_DATALL_MASK) /*!< CRC_DATALL                              */

/* ------- CRC_DATALU                               ------ */
#define CRC_DATALU_DATALU_MASK                   (0xFFUL << CRC_DATALU_DATALU_SHIFT)                 /*!< CRC_DATALU: DATALU Mask                 */
#define CRC_DATALU_DATALU_SHIFT                  0                                                   /*!< CRC_DATALU: DATALU Position             */
#define CRC_DATALU_DATALU(x)                     (((x)<<CRC_DATALU_DATALU_SHIFT)&CRC_DATALU_DATALU_MASK) /*!< CRC_DATALU                              */

/* ------- CRC_DATAH                                ------ */
#define CRC_DATAH_DATAH_MASK                     (0xFFFFUL << CRC_DATAH_DATAH_SHIFT)                 /*!< CRC_DATAH: DATAH Mask                   */
#define CRC_DATAH_DATAH_SHIFT                    0                                                   /*!< CRC_DATAH: DATAH Position               */
#define CRC_DATAH_DATAH(x)                       (((x)<<CRC_DATAH_DATAH_SHIFT)&CRC_DATAH_DATAH_MASK) /*!< CRC_DATAH                               */

/* ------- CRC_DATAHL                               ------ */
#define CRC_DATAHL_DATAHL_MASK                   (0xFFUL << CRC_DATAHL_DATAHL_SHIFT)                 /*!< CRC_DATAHL: DATAHL Mask                 */
#define CRC_DATAHL_DATAHL_SHIFT                  0                                                   /*!< CRC_DATAHL: DATAHL Position             */
#define CRC_DATAHL_DATAHL(x)                     (((x)<<CRC_DATAHL_DATAHL_SHIFT)&CRC_DATAHL_DATAHL_MASK) /*!< CRC_DATAHL                              */

/* ------- CRC_DATAHU                               ------ */
#define CRC_DATAHU_DATAHU_MASK                   (0xFFUL << CRC_DATAHU_DATAHU_SHIFT)                 /*!< CRC_DATAHU: DATAHU Mask                 */
#define CRC_DATAHU_DATAHU_SHIFT                  0                                                   /*!< CRC_DATAHU: DATAHU Position             */
#define CRC_DATAHU_DATAHU(x)                     (((x)<<CRC_DATAHU_DATAHU_SHIFT)&CRC_DATAHU_DATAHU_MASK) /*!< CRC_DATAHU                              */

/* ------- CRC_GPOLY                                ------ */
#define CRC_GPOLY_LOW_MASK                       (0xFFFFUL << CRC_GPOLY_LOW_SHIFT)                   /*!< CRC_GPOLY: LOW Mask                     */
#define CRC_GPOLY_LOW_SHIFT                      0                                                   /*!< CRC_GPOLY: LOW Position                 */
#define CRC_GPOLY_LOW(x)                         (((x)<<CRC_GPOLY_LOW_SHIFT)&CRC_GPOLY_LOW_MASK)     /*!< CRC_GPOLY                               */
#define CRC_GPOLY_HIGH_MASK                      (0xFFFFUL << CRC_GPOLY_HIGH_SHIFT)                  /*!< CRC_GPOLY: HIGH Mask                    */
#define CRC_GPOLY_HIGH_SHIFT                     16                                                  /*!< CRC_GPOLY: HIGH Position                */
#define CRC_GPOLY_HIGH(x)                        (((x)<<CRC_GPOLY_HIGH_SHIFT)&CRC_GPOLY_HIGH_MASK)   /*!< CRC_GPOLY                               */

/* ------- CRC_GPOLYL                               ------ */
#define CRC_GPOLYL_GPOLYL_MASK                   (0xFFFFUL << CRC_GPOLYL_GPOLYL_SHIFT)               /*!< CRC_GPOLYL: GPOLYL Mask                 */
#define CRC_GPOLYL_GPOLYL_SHIFT                  0                                                   /*!< CRC_GPOLYL: GPOLYL Position             */
#define CRC_GPOLYL_GPOLYL(x)                     (((x)<<CRC_GPOLYL_GPOLYL_SHIFT)&CRC_GPOLYL_GPOLYL_MASK) /*!< CRC_GPOLYL                              */

/* ------- CRC_GPOLYLL                              ------ */
#define CRC_GPOLYLL_GPOLYLL_MASK                 (0xFFUL << CRC_GPOLYLL_GPOLYLL_SHIFT)               /*!< CRC_GPOLYLL: GPOLYLL Mask               */
#define CRC_GPOLYLL_GPOLYLL_SHIFT                0                                                   /*!< CRC_GPOLYLL: GPOLYLL Position           */
#define CRC_GPOLYLL_GPOLYLL(x)                   (((x)<<CRC_GPOLYLL_GPOLYLL_SHIFT)&CRC_GPOLYLL_GPOLYLL_MASK) /*!< CRC_GPOLYLL                             */

/* ------- CRC_GPOLYLU                              ------ */
#define CRC_GPOLYLU_GPOLYLU_MASK                 (0xFFUL << CRC_GPOLYLU_GPOLYLU_SHIFT)               /*!< CRC_GPOLYLU: GPOLYLU Mask               */
#define CRC_GPOLYLU_GPOLYLU_SHIFT                0                                                   /*!< CRC_GPOLYLU: GPOLYLU Position           */
#define CRC_GPOLYLU_GPOLYLU(x)                   (((x)<<CRC_GPOLYLU_GPOLYLU_SHIFT)&CRC_GPOLYLU_GPOLYLU_MASK) /*!< CRC_GPOLYLU                             */

/* ------- CRC_GPOLYH                               ------ */
#define CRC_GPOLYH_GPOLYH_MASK                   (0xFFFFUL << CRC_GPOLYH_GPOLYH_SHIFT)               /*!< CRC_GPOLYH: GPOLYH Mask                 */
#define CRC_GPOLYH_GPOLYH_SHIFT                  0                                                   /*!< CRC_GPOLYH: GPOLYH Position             */
#define CRC_GPOLYH_GPOLYH(x)                     (((x)<<CRC_GPOLYH_GPOLYH_SHIFT)&CRC_GPOLYH_GPOLYH_MASK) /*!< CRC_GPOLYH                              */

/* ------- CRC_GPOLYHL                              ------ */
#define CRC_GPOLYHL_GPOLYHL_MASK                 (0xFFUL << CRC_GPOLYHL_GPOLYHL_SHIFT)               /*!< CRC_GPOLYHL: GPOLYHL Mask               */
#define CRC_GPOLYHL_GPOLYHL_SHIFT                0                                                   /*!< CRC_GPOLYHL: GPOLYHL Position           */
#define CRC_GPOLYHL_GPOLYHL(x)                   (((x)<<CRC_GPOLYHL_GPOLYHL_SHIFT)&CRC_GPOLYHL_GPOLYHL_MASK) /*!< CRC_GPOLYHL                             */

/* ------- CRC_GPOLYHU                              ------ */
#define CRC_GPOLYHU_GPOLYHU_MASK                 (0xFFUL << CRC_GPOLYHU_GPOLYHU_SHIFT)               /*!< CRC_GPOLYHU: GPOLYHU Mask               */
#define CRC_GPOLYHU_GPOLYHU_SHIFT                0                                                   /*!< CRC_GPOLYHU: GPOLYHU Position           */
#define CRC_GPOLYHU_GPOLYHU(x)                   (((x)<<CRC_GPOLYHU_GPOLYHU_SHIFT)&CRC_GPOLYHU_GPOLYHU_MASK) /*!< CRC_GPOLYHU                             */

/* ------- CRC_CTRL                                 ------ */
#define CRC_CTRL_TCRC_MASK                       (0x01UL << CRC_CTRL_TCRC_SHIFT)                     /*!< CRC_CTRL: TCRC Mask                     */
#define CRC_CTRL_TCRC_SHIFT                      24                                                  /*!< CRC_CTRL: TCRC Position                 */
#define CRC_CTRL_WAS_MASK                        (0x01UL << CRC_CTRL_WAS_SHIFT)                      /*!< CRC_CTRL: WAS Mask                      */
#define CRC_CTRL_WAS_SHIFT                       25                                                  /*!< CRC_CTRL: WAS Position                  */
#define CRC_CTRL_FXOR_MASK                       (0x01UL << CRC_CTRL_FXOR_SHIFT)                     /*!< CRC_CTRL: FXOR Mask                     */
#define CRC_CTRL_FXOR_SHIFT                      26                                                  /*!< CRC_CTRL: FXOR Position                 */
#define CRC_CTRL_TOTR_MASK                       (0x03UL << CRC_CTRL_TOTR_SHIFT)                     /*!< CRC_CTRL: TOTR Mask                     */
#define CRC_CTRL_TOTR_SHIFT                      28                                                  /*!< CRC_CTRL: TOTR Position                 */
#define CRC_CTRL_TOTR(x)                         (((x)<<CRC_CTRL_TOTR_SHIFT)&CRC_CTRL_TOTR_MASK)     /*!< CRC_CTRL                                */
#define CRC_CTRL_TOT_MASK                        (0x03UL << CRC_CTRL_TOT_SHIFT)                      /*!< CRC_CTRL: TOT Mask                      */
#define CRC_CTRL_TOT_SHIFT                       30                                                  /*!< CRC_CTRL: TOT Position                  */
#define CRC_CTRL_TOT(x)                          (((x)<<CRC_CTRL_TOT_SHIFT)&CRC_CTRL_TOT_MASK)       /*!< CRC_CTRL                                */

/* ------- CRC_CTRLHU                               ------ */
#define CRC_CTRLHU_TCRC_MASK                     (0x01UL << CRC_CTRLHU_TCRC_SHIFT)                   /*!< CRC_CTRLHU: TCRC Mask                   */
#define CRC_CTRLHU_TCRC_SHIFT                    0                                                   /*!< CRC_CTRLHU: TCRC Position               */
#define CRC_CTRLHU_WAS_MASK                      (0x01UL << CRC_CTRLHU_WAS_SHIFT)                    /*!< CRC_CTRLHU: WAS Mask                    */
#define CRC_CTRLHU_WAS_SHIFT                     1                                                   /*!< CRC_CTRLHU: WAS Position                */
#define CRC_CTRLHU_FXOR_MASK                     (0x01UL << CRC_CTRLHU_FXOR_SHIFT)                   /*!< CRC_CTRLHU: FXOR Mask                   */
#define CRC_CTRLHU_FXOR_SHIFT                    2                                                   /*!< CRC_CTRLHU: FXOR Position               */
#define CRC_CTRLHU_TOTR_MASK                     (0x03UL << CRC_CTRLHU_TOTR_SHIFT)                   /*!< CRC_CTRLHU: TOTR Mask                   */
#define CRC_CTRLHU_TOTR_SHIFT                    4                                                   /*!< CRC_CTRLHU: TOTR Position               */
#define CRC_CTRLHU_TOTR(x)                       (((x)<<CRC_CTRLHU_TOTR_SHIFT)&CRC_CTRLHU_TOTR_MASK) /*!< CRC_CTRLHU                              */
#define CRC_CTRLHU_TOT_MASK                      (0x03UL << CRC_CTRLHU_TOT_SHIFT)                    /*!< CRC_CTRLHU: TOT Mask                    */
#define CRC_CTRLHU_TOT_SHIFT                     6                                                   /*!< CRC_CTRLHU: TOT Position                */
#define CRC_CTRLHU_TOT(x)                        (((x)<<CRC_CTRLHU_TOT_SHIFT)&CRC_CTRLHU_TOT_MASK)   /*!< CRC_CTRLHU                              */

/* -------------------------------------------------------------------------------- */
/* -----------     'CRC' Register Access macros                         ----------- */
/* -------------------------------------------------------------------------------- */

#define CRC_DATA                       (CRC->DATA)
#define CRC_DATAL                      (CRC->DATAL)
#define CRC_DATALL                     (CRC->DATALL)
#define CRC_DATALU                     (CRC->DATALU)
#define CRC_DATAH                      (CRC->DATAH)
#define CRC_DATAHL                     (CRC->DATAHL)
#define CRC_DATAHU                     (CRC->DATAHU)
#define CRC_GPOLY                      (CRC->GPOLY)
#define CRC_GPOLYL                     (CRC->GPOLYL)
#define CRC_GPOLYLL                    (CRC->GPOLYLL)
#define CRC_GPOLYLU                    (CRC->GPOLYLU)
#define CRC_GPOLYH                     (CRC->GPOLYH)
#define CRC_GPOLYHL                    (CRC->GPOLYHL)
#define CRC_GPOLYHU                    (CRC->GPOLYHU)
#define CRC_CTRL                       (CRC->CTRL)
#define CRC_CTRLHU                     (CRC->CTRLHU)

/* ================================================================================ */
/* ================           FTFA (file:FTFA)                     ================ */
/* ================================================================================ */

/**
 * @brief Flash Memory Interface
 */
typedef struct {                                /*!<       FTFA Structure                                               */
   __IO uint8_t   FSTAT;                        /*!< 0000: Flash Status Register                                        */
   __IO uint8_t   FCNFG;                        /*!< 0001: Flash Configuration Register                                 */
   __I  uint8_t   FSEC;                         /*!< 0002: Flash Security Register                                      */
   __I  uint8_t   FOPT;                         /*!< 0003: Flash Option Register                                        */
   __IO uint8_t   FCCOB3;                       /*!< 0004: FCCOB 3 - Usually Flash address [7..0]                       */
   __IO uint8_t   FCCOB2;                       /*!< 0005: FCCOB 2 - Usually Flash address [15..8]                      */
   __IO uint8_t   FCCOB1;                       /*!< 0006: FCCOB 1 - Usually Flash address [23..16]                     */
   __IO uint8_t   FCCOB0;                       /*!< 0007: FCCOB 0 - Usually FCMD (a code that defines the flash command)  */
   __IO uint8_t   FCCOB7;                       /*!< 0008: FCCOB 7 - Usually Data Byte 3                                */
   __IO uint8_t   FCCOB6;                       /*!< 0009: FCCOB 6 - Usually Data Byte 2                                */
   __IO uint8_t   FCCOB5;                       /*!< 000A: FCCOB 5 - Usually Data Byte 1                                */
   __IO uint8_t   FCCOB4;                       /*!< 000B: FCCOB 4 - Usually Data Byte 0                                */
   __IO uint8_t   FCCOBB;                       /*!< 000C: FCCOB B - Usually Data Byte 7                                */
   __IO uint8_t   FCCOBA;                       /*!< 000D: FCCOB A - Usually Data Byte 6                                */
   __IO uint8_t   FCCOB9;                       /*!< 000E: FCCOB 9 - Usually Data Byte 5                                */
   __IO uint8_t   FCCOB8;                       /*!< 000F: FCCOB 8 - Usually Data Byte 4                                */
   __IO uint8_t   FPROT3;                       /*!< 0010: Program Flash Protection                                     */
   __IO uint8_t   FPROT2;                       /*!< 0011: Program Flash Protection                                     */
   __IO uint8_t   FPROT1;                       /*!< 0012: Program Flash Protection                                     */
   __IO uint8_t   FPROT0;                       /*!< 0013: Program Flash Protection                                     */
} FTFA_Type;


/* -------------------------------------------------------------------------------- */
/* -----------     'FTFA' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */


/* ------- FTFA_FSTAT                               ------ */
#define FTFA_FSTAT_MGSTAT0_MASK                  (0x01UL << FTFA_FSTAT_MGSTAT0_SHIFT)                /*!< FTFA_FSTAT: MGSTAT0 Mask                */
#define FTFA_FSTAT_MGSTAT0_SHIFT                 0                                                   /*!< FTFA_FSTAT: MGSTAT0 Position            */
#define FTFA_FSTAT_FPVIOL_MASK                   (0x01UL << FTFA_FSTAT_FPVIOL_SHIFT)                 /*!< FTFA_FSTAT: FPVIOL Mask                 */
#define FTFA_FSTAT_FPVIOL_SHIFT                  4                                                   /*!< FTFA_FSTAT: FPVIOL Position             */
#define FTFA_FSTAT_ACCERR_MASK                   (0x01UL << FTFA_FSTAT_ACCERR_SHIFT)                 /*!< FTFA_FSTAT: ACCERR Mask                 */
#define FTFA_FSTAT_ACCERR_SHIFT                  5                                                   /*!< FTFA_FSTAT: ACCERR Position             */
#define FTFA_FSTAT_RDCOLERR_MASK                 (0x01UL << FTFA_FSTAT_RDCOLERR_SHIFT)               /*!< FTFA_FSTAT: RDCOLERR Mask               */
#define FTFA_FSTAT_RDCOLERR_SHIFT                6                                                   /*!< FTFA_FSTAT: RDCOLERR Position           */
#define FTFA_FSTAT_CCIF_MASK                     (0x01UL << FTFA_FSTAT_CCIF_SHIFT)                   /*!< FTFA_FSTAT: CCIF Mask                   */
#define FTFA_FSTAT_CCIF_SHIFT                    7                                                   /*!< FTFA_FSTAT: CCIF Position               */

/* ------- FTFA_FCNFG                               ------ */
#define FTFA_FCNFG_ERSSUSP_MASK                  (0x01UL << FTFA_FCNFG_ERSSUSP_SHIFT)                /*!< FTFA_FCNFG: ERSSUSP Mask                */
#define FTFA_FCNFG_ERSSUSP_SHIFT                 4                                                   /*!< FTFA_FCNFG: ERSSUSP Position            */
#define FTFA_FCNFG_ERSAREQ_MASK                  (0x01UL << FTFA_FCNFG_ERSAREQ_SHIFT)                /*!< FTFA_FCNFG: ERSAREQ Mask                */
#define FTFA_FCNFG_ERSAREQ_SHIFT                 5                                                   /*!< FTFA_FCNFG: ERSAREQ Position            */
#define FTFA_FCNFG_RDCOLLIE_MASK                 (0x01UL << FTFA_FCNFG_RDCOLLIE_SHIFT)               /*!< FTFA_FCNFG: RDCOLLIE Mask               */
#define FTFA_FCNFG_RDCOLLIE_SHIFT                6                                                   /*!< FTFA_FCNFG: RDCOLLIE Position           */
#define FTFA_FCNFG_CCIE_MASK                     (0x01UL << FTFA_FCNFG_CCIE_SHIFT)                   /*!< FTFA_FCNFG: CCIE Mask                   */
#define FTFA_FCNFG_CCIE_SHIFT                    7                                                   /*!< FTFA_FCNFG: CCIE Position               */

/* ------- FTFA_FSEC                                ------ */
#define FTFA_FSEC_SEC_MASK                       (0x03UL << FTFA_FSEC_SEC_SHIFT)                     /*!< FTFA_FSEC: SEC Mask                     */
#define FTFA_FSEC_SEC_SHIFT                      0                                                   /*!< FTFA_FSEC: SEC Position                 */
#define FTFA_FSEC_SEC(x)                         (((x)<<FTFA_FSEC_SEC_SHIFT)&FTFA_FSEC_SEC_MASK)     /*!< FTFA_FSEC                               */
#define FTFA_FSEC_FSLACC_MASK                    (0x03UL << FTFA_FSEC_FSLACC_SHIFT)                  /*!< FTFA_FSEC: FSLACC Mask                  */
#define FTFA_FSEC_FSLACC_SHIFT                   2                                                   /*!< FTFA_FSEC: FSLACC Position              */
#define FTFA_FSEC_FSLACC(x)                      (((x)<<FTFA_FSEC_FSLACC_SHIFT)&FTFA_FSEC_FSLACC_MASK) /*!< FTFA_FSEC                               */
#define FTFA_FSEC_MEEN_MASK                      (0x03UL << FTFA_FSEC_MEEN_SHIFT)                    /*!< FTFA_FSEC: MEEN Mask                    */
#define FTFA_FSEC_MEEN_SHIFT                     4                                                   /*!< FTFA_FSEC: MEEN Position                */
#define FTFA_FSEC_MEEN(x)                        (((x)<<FTFA_FSEC_MEEN_SHIFT)&FTFA_FSEC_MEEN_MASK)   /*!< FTFA_FSEC                               */
#define FTFA_FSEC_KEYEN_MASK                     (0x03UL << FTFA_FSEC_KEYEN_SHIFT)                   /*!< FTFA_FSEC: KEYEN Mask                   */
#define FTFA_FSEC_KEYEN_SHIFT                    6                                                   /*!< FTFA_FSEC: KEYEN Position               */
#define FTFA_FSEC_KEYEN(x)                       (((x)<<FTFA_FSEC_KEYEN_SHIFT)&FTFA_FSEC_KEYEN_MASK) /*!< FTFA_FSEC                               */

/* ------- FTFA_FOPT                                ------ */
#define FTFA_FOPT_OPT_MASK                       (0xFFUL << FTFA_FOPT_OPT_SHIFT)                     /*!< FTFA_FOPT: OPT Mask                     */
#define FTFA_FOPT_OPT_SHIFT                      0                                                   /*!< FTFA_FOPT: OPT Position                 */
#define FTFA_FOPT_OPT(x)                         (((x)<<FTFA_FOPT_OPT_SHIFT)&FTFA_FOPT_OPT_MASK)     /*!< FTFA_FOPT                               */

/* ------- FTFA_FCCOB                               ------ */
#define FTFA_FCCOB_CCOBn_MASK                    (0xFFUL << FTFA_FCCOB_CCOBn_SHIFT)                  /*!< FTFA_FCCOB: CCOBn Mask                  */
#define FTFA_FCCOB_CCOBn_SHIFT                   0                                                   /*!< FTFA_FCCOB: CCOBn Position              */
#define FTFA_FCCOB_CCOBn(x)                      (((x)<<FTFA_FCCOB_CCOBn_SHIFT)&FTFA_FCCOB_CCOBn_MASK) /*!< FTFA_FCCOB                              */

/* ------- FTFA_FPROT                               ------ */
#define FTFA_FPROT_PROT_MASK                     (0xFFUL << FTFA_FPROT_PROT_SHIFT)                   /*!< FTFA_FPROT: PROT Mask                   */
#define FTFA_FPROT_PROT_SHIFT                    0                                                   /*!< FTFA_FPROT: PROT Position               */
#define FTFA_FPROT_PROT(x)                       (((x)<<FTFA_FPROT_PROT_SHIFT)&FTFA_FPROT_PROT_MASK) /*!< FTFA_FPROT                              */

/* -------------------------------------------------------------------------------- */
/* -----------     'FTFA' Register Access macros                        ----------- */
/* -------------------------------------------------------------------------------- */

#define FTFA_FSTAT                     (FTFA->FSTAT)
#define FTFA_FCNFG                     (FTFA->FCNFG)
#define FTFA_FSEC                      (FTFA->FSEC)
#define FTFA_FOPT                      (FTFA->FOPT)
#define FTFA_FCCOB3                    (FTFA->FCCOB3)
#define FTFA_FCCOB2                    (FTFA->FCCOB2)
#define FTFA_FCCOB1                    (FTFA->FCCOB1)
#define FTFA_FCCOB0                    (FTFA->FCCOB0)
#define FTFA_FCCOB7                    (FTFA->FCCOB7)
#define FTFA_FCCOB6                    (FTFA->FCCOB6)
#define FTFA_FCCOB5                    (FTFA->FCCOB5)
#define FTFA_FCCOB4                    (FTFA->FCCOB4)
#define FTFA_FCCOBB                    (FTFA->FCCOBB)
#define FTFA_FCCOBA                    (FTFA->FCCOBA)
#define FTFA_FCCOB9                    (FTFA->FCCOB9)
#define FTFA_FCCOB8                    (FTFA->FCCOB8)
#define FTFA_FPROT3                    (FTFA->FPROT3)
#define FTFA_FPROT2                    (FTFA->FPROT2)
#define FTFA_FPROT1                    (FTFA->FPROT1)
#define FTFA_FPROT0                    (FTFA->FPROT0)

/* ================================================================================ */
/* ================           GPIOA (file:GPIOA_MKM)               ================ */
/* ================================================================================ */

/**
 * @brief General Purpose Input/Output
 */
typedef struct {                                /*!<       GPIOA Structure                                              */
   __IO uint8_t   PDOR;                         /*!< 0000: Port Data Output Register                                    */
   __I  uint8_t   RESERVED0[15];                /*!< 0001:                                                              */
   __I  uint8_t   PDIR;                         /*!< 0010: Port Data Input Register                                     */
   __I  uint8_t   RESERVED1[3];                 /*!< 0011:                                                              */
   __IO uint8_t   PDDR;                         /*!< 0014: Port Data Direction Register                                 */
   __I  uint8_t   RESERVED2[7];                 /*!< 0015:                                                              */
   __IO uint8_t   GACR;                         /*!< 001C: GPIO Attribute Checker Register                              */
} GPIOA_Type;


/* -------------------------------------------------------------------------------- */
/* -----------     'GPIOA' Position & Mask macros                       ----------- */
/* -------------------------------------------------------------------------------- */


/* ------- GPIOA_PDOR                               ------ */
#define GPIO_PDOR_PDO0_MASK                      (0x01UL << GPIO_PDOR_PDO0_SHIFT)                    /*!< GPIOA_PDOR: PDO0 Mask                   */
#define GPIO_PDOR_PDO0_SHIFT                     0                                                   /*!< GPIOA_PDOR: PDO0 Position               */
#define GPIO_PDOR_PDO1_MASK                      (0x01UL << GPIO_PDOR_PDO1_SHIFT)                    /*!< GPIOA_PDOR: PDO1 Mask                   */
#define GPIO_PDOR_PDO1_SHIFT                     1                                                   /*!< GPIOA_PDOR: PDO1 Position               */
#define GPIO_PDOR_PDO2_MASK                      (0x01UL << GPIO_PDOR_PDO2_SHIFT)                    /*!< GPIOA_PDOR: PDO2 Mask                   */
#define GPIO_PDOR_PDO2_SHIFT                     2                                                   /*!< GPIOA_PDOR: PDO2 Position               */
#define GPIO_PDOR_PDO3_MASK                      (0x01UL << GPIO_PDOR_PDO3_SHIFT)                    /*!< GPIOA_PDOR: PDO3 Mask                   */
#define GPIO_PDOR_PDO3_SHIFT                     3                                                   /*!< GPIOA_PDOR: PDO3 Position               */
#define GPIO_PDOR_PDO4_MASK                      (0x01UL << GPIO_PDOR_PDO4_SHIFT)                    /*!< GPIOA_PDOR: PDO4 Mask                   */
#define GPIO_PDOR_PDO4_SHIFT                     4                                                   /*!< GPIOA_PDOR: PDO4 Position               */
#define GPIO_PDOR_PDO5_MASK                      (0x01UL << GPIO_PDOR_PDO5_SHIFT)                    /*!< GPIOA_PDOR: PDO5 Mask                   */
#define GPIO_PDOR_PDO5_SHIFT                     5                                                   /*!< GPIOA_PDOR: PDO5 Position               */
#define GPIO_PDOR_PDO6_MASK                      (0x01UL << GPIO_PDOR_PDO6_SHIFT)                    /*!< GPIOA_PDOR: PDO6 Mask                   */
#define GPIO_PDOR_PDO6_SHIFT                     6                                                   /*!< GPIOA_PDOR: PDO6 Position               */
#define GPIO_PDOR_PDO7_MASK                      (0x01UL << GPIO_PDOR_PDO7_SHIFT)                    /*!< GPIOA_PDOR: PDO7 Mask                   */
#define GPIO_PDOR_PDO7_SHIFT                     7                                                   /*!< GPIOA_PDOR: PDO7 Position               */

/* ------- GPIOA_PDIR                               ------ */
#define GPIO_PDIR_PDI0_MASK                      (0x01UL << GPIO_PDIR_PDI0_SHIFT)                    /*!< GPIOA_PDIR: PDI0 Mask                   */
#define GPIO_PDIR_PDI0_SHIFT                     0                                                   /*!< GPIOA_PDIR: PDI0 Position               */
#define GPIO_PDIR_PDI1_MASK                      (0x01UL << GPIO_PDIR_PDI1_SHIFT)                    /*!< GPIOA_PDIR: PDI1 Mask                   */
#define GPIO_PDIR_PDI1_SHIFT                     1                                                   /*!< GPIOA_PDIR: PDI1 Position               */
#define GPIO_PDIR_PDI2_MASK                      (0x01UL << GPIO_PDIR_PDI2_SHIFT)                    /*!< GPIOA_PDIR: PDI2 Mask                   */
#define GPIO_PDIR_PDI2_SHIFT                     2                                                   /*!< GPIOA_PDIR: PDI2 Position               */
#define GPIO_PDIR_PDI3_MASK                      (0x01UL << GPIO_PDIR_PDI3_SHIFT)                    /*!< GPIOA_PDIR: PDI3 Mask                   */
#define GPIO_PDIR_PDI3_SHIFT                     3                                                   /*!< GPIOA_PDIR: PDI3 Position               */
#define GPIO_PDIR_PDI4_MASK                      (0x01UL << GPIO_PDIR_PDI4_SHIFT)                    /*!< GPIOA_PDIR: PDI4 Mask                   */
#define GPIO_PDIR_PDI4_SHIFT                     4                                                   /*!< GPIOA_PDIR: PDI4 Position               */
#define GPIO_PDIR_PDI5_MASK                      (0x01UL << GPIO_PDIR_PDI5_SHIFT)                    /*!< GPIOA_PDIR: PDI5 Mask                   */
#define GPIO_PDIR_PDI5_SHIFT                     5                                                   /*!< GPIOA_PDIR: PDI5 Position               */
#define GPIO_PDIR_PDI6_MASK                      (0x01UL << GPIO_PDIR_PDI6_SHIFT)                    /*!< GPIOA_PDIR: PDI6 Mask                   */
#define GPIO_PDIR_PDI6_SHIFT                     6                                                   /*!< GPIOA_PDIR: PDI6 Position               */
#define GPIO_PDIR_PDI7_MASK                      (0x01UL << GPIO_PDIR_PDI7_SHIFT)                    /*!< GPIOA_PDIR: PDI7 Mask                   */
#define GPIO_PDIR_PDI7_SHIFT                     7                                                   /*!< GPIOA_PDIR: PDI7 Position               */

/* ------- GPIOA_PDDR                               ------ */
#define GPIO_PDDR_PDD0_MASK                      (0x01UL << GPIO_PDDR_PDD0_SHIFT)                    /*!< GPIOA_PDDR: PDD0 Mask                   */
#define GPIO_PDDR_PDD0_SHIFT                     0                                                   /*!< GPIOA_PDDR: PDD0 Position               */
#define GPIO_PDDR_PDD1_MASK                      (0x01UL << GPIO_PDDR_PDD1_SHIFT)                    /*!< GPIOA_PDDR: PDD1 Mask                   */
#define GPIO_PDDR_PDD1_SHIFT                     1                                                   /*!< GPIOA_PDDR: PDD1 Position               */
#define GPIO_PDDR_PDD2_MASK                      (0x01UL << GPIO_PDDR_PDD2_SHIFT)                    /*!< GPIOA_PDDR: PDD2 Mask                   */
#define GPIO_PDDR_PDD2_SHIFT                     2                                                   /*!< GPIOA_PDDR: PDD2 Position               */
#define GPIO_PDDR_PDD3_MASK                      (0x01UL << GPIO_PDDR_PDD3_SHIFT)                    /*!< GPIOA_PDDR: PDD3 Mask                   */
#define GPIO_PDDR_PDD3_SHIFT                     3                                                   /*!< GPIOA_PDDR: PDD3 Position               */
#define GPIO_PDDR_PDD4_MASK                      (0x01UL << GPIO_PDDR_PDD4_SHIFT)                    /*!< GPIOA_PDDR: PDD4 Mask                   */
#define GPIO_PDDR_PDD4_SHIFT                     4                                                   /*!< GPIOA_PDDR: PDD4 Position               */
#define GPIO_PDDR_PDD5_MASK                      (0x01UL << GPIO_PDDR_PDD5_SHIFT)                    /*!< GPIOA_PDDR: PDD5 Mask                   */
#define GPIO_PDDR_PDD5_SHIFT                     5                                                   /*!< GPIOA_PDDR: PDD5 Position               */
#define GPIO_PDDR_PDD6_MASK                      (0x01UL << GPIO_PDDR_PDD6_SHIFT)                    /*!< GPIOA_PDDR: PDD6 Mask                   */
#define GPIO_PDDR_PDD6_SHIFT                     6                                                   /*!< GPIOA_PDDR: PDD6 Position               */
#define GPIO_PDDR_PDD7_MASK                      (0x01UL << GPIO_PDDR_PDD7_SHIFT)                    /*!< GPIOA_PDDR: PDD7 Mask                   */
#define GPIO_PDDR_PDD7_SHIFT                     7                                                   /*!< GPIOA_PDDR: PDD7 Position               */

/* ------- GPIOA_GACR                               ------ */
#define GPIO_GACR_ACB_MASK                       (0x07UL << GPIO_GACR_ACB_SHIFT)                     /*!< GPIOA_GACR: ACB Mask                    */
#define GPIO_GACR_ACB_SHIFT                      0                                                   /*!< GPIOA_GACR: ACB Position                */
#define GPIO_GACR_ACB(x)                         (((x)<<GPIO_GACR_ACB_SHIFT)&GPIO_GACR_ACB_MASK)     /*!< GPIOA_GACR                              */
#define GPIO_GACR_ROB_MASK                       (0x01UL << GPIO_GACR_ROB_SHIFT)                     /*!< GPIOA_GACR: ROB Mask                    */
#define GPIO_GACR_ROB_SHIFT                      7                                                   /*!< GPIOA_GACR: ROB Position                */

/* -------------------------------------------------------------------------------- */
/* -----------     'GPIOA' Register Access macros                       ----------- */
/* -------------------------------------------------------------------------------- */

#define GPIOA_PDOR                     (GPIOA->PDOR)
#define GPIOA_PDIR                     (GPIOA->PDIR)
#define GPIOA_PDDR                     (GPIOA->PDDR)
#define GPIOA_GACR                     (GPIOA->GACR)

/* ================================================================================ */
/* ================           GPIOB (derived from GPIOA)           ================ */
/* ================================================================================ */

/**
 * @brief General Purpose Input/Output
 */
typedef GPIOA_Type GPIOB_Type;  /*!< GPIOB Structure                                             */


/* -------------------------------------------------------------------------------- */
/* -----------     'GPIOB' Register Access macros                       ----------- */
/* -------------------------------------------------------------------------------- */

#define GPIOB_PDOR                     (GPIOB->PDOR)
#define GPIOB_PDIR                     (GPIOB->PDIR)
#define GPIOB_PDDR                     (GPIOB->PDDR)
#define GPIOB_GACR                     (GPIOB->GACR)

/* ================================================================================ */
/* ================           GPIOC (derived from GPIOA)           ================ */
/* ================================================================================ */

/**
 * @brief General Purpose Input/Output
 */
typedef GPIOA_Type GPIOC_Type;  /*!< GPIOC Structure                                             */


/* -------------------------------------------------------------------------------- */
/* -----------     'GPIOC' Register Access macros                       ----------- */
/* -------------------------------------------------------------------------------- */

#define GPIOC_PDOR                     (GPIOC->PDOR)
#define GPIOC_PDIR                     (GPIOC->PDIR)
#define GPIOC_PDDR                     (GPIOC->PDDR)
#define GPIOC_GACR                     (GPIOC->GACR)

/* ================================================================================ */
/* ================           GPIOD (derived from GPIOA)           ================ */
/* ================================================================================ */

/**
 * @brief General Purpose Input/Output
 */
typedef GPIOA_Type GPIOD_Type;  /*!< GPIOD Structure                                             */


/* -------------------------------------------------------------------------------- */
/* -----------     'GPIOD' Register Access macros                       ----------- */
/* -------------------------------------------------------------------------------- */

#define GPIOD_PDOR                     (GPIOD->PDOR)
#define GPIOD_PDIR                     (GPIOD->PDIR)
#define GPIOD_PDDR                     (GPIOD->PDDR)
#define GPIOD_GACR                     (GPIOD->GACR)

/* ================================================================================ */
/* ================           GPIOE (derived from GPIOA)           ================ */
/* ================================================================================ */

/**
 * @brief General Purpose Input/Output
 */
typedef GPIOA_Type GPIOE_Type;  /*!< GPIOE Structure                                             */


/* -------------------------------------------------------------------------------- */
/* -----------     'GPIOE' Register Access macros                       ----------- */
/* -------------------------------------------------------------------------------- */

#define GPIOE_PDOR                     (GPIOE->PDOR)
#define GPIOE_PDIR                     (GPIOE->PDIR)
#define GPIOE_PDDR                     (GPIOE->PDDR)
#define GPIOE_GACR                     (GPIOE->GACR)

/* ================================================================================ */
/* ================           GPIOF (derived from GPIOA)           ================ */
/* ================================================================================ */

/**
 * @brief General Purpose Input/Output
 */
typedef GPIOA_Type GPIOF_Type;  /*!< GPIOF Structure                                             */


/* -------------------------------------------------------------------------------- */
/* -----------     'GPIOF' Register Access macros                       ----------- */
/* -------------------------------------------------------------------------------- */

#define GPIOF_PDOR                     (GPIOF->PDOR)
#define GPIOF_PDIR                     (GPIOF->PDIR)
#define GPIOF_PDDR                     (GPIOF->PDDR)
#define GPIOF_GACR                     (GPIOF->GACR)

/* ================================================================================ */
/* ================           GPIOG (derived from GPIOA)           ================ */
/* ================================================================================ */

/**
 * @brief General Purpose Input/Output
 */
typedef GPIOA_Type GPIOG_Type;  /*!< GPIOG Structure                                             */


/* -------------------------------------------------------------------------------- */
/* -----------     'GPIOG' Register Access macros                       ----------- */
/* -------------------------------------------------------------------------------- */

#define GPIOG_PDOR                     (GPIOG->PDOR)
#define GPIOG_PDIR                     (GPIOG->PDIR)
#define GPIOG_PDDR                     (GPIOG->PDDR)
#define GPIOG_GACR                     (GPIOG->GACR)

/* ================================================================================ */
/* ================           GPIOH (derived from GPIOA)           ================ */
/* ================================================================================ */

/**
 * @brief General Purpose Input/Output
 */
typedef GPIOA_Type GPIOH_Type;  /*!< GPIOH Structure                                             */


/* -------------------------------------------------------------------------------- */
/* -----------     'GPIOH' Register Access macros                       ----------- */
/* -------------------------------------------------------------------------------- */

#define GPIOH_PDOR                     (GPIOH->PDOR)
#define GPIOH_PDIR                     (GPIOH->PDIR)
#define GPIOH_PDDR                     (GPIOH->PDDR)
#define GPIOH_GACR                     (GPIOH->GACR)

/* ================================================================================ */
/* ================           GPIOI (derived from GPIOA)           ================ */
/* ================================================================================ */

/**
 * @brief General Purpose Input/Output
 */
typedef GPIOA_Type GPIOI_Type;  /*!< GPIOI Structure                                             */


/* -------------------------------------------------------------------------------- */
/* -----------     'GPIOI' Register Access macros                       ----------- */
/* -------------------------------------------------------------------------------- */

#define GPIOI_PDOR                     (GPIOI->PDOR)
#define GPIOI_PDIR                     (GPIOI->PDIR)
#define GPIOI_PDDR                     (GPIOI->PDDR)
#define GPIOI_GACR                     (GPIOI->GACR)

/* ================================================================================ */
/* ================           I2C0 (file:I2C0_MKM)                 ================ */
/* ================================================================================ */

/**
 * @brief Inter-Integrated Circuit
 */
typedef struct {                                /*!<       I2C0 Structure                                               */
   __IO uint8_t   A1;                           /*!< 0000: Address Register 1                                           */
   __IO uint8_t   F;                            /*!< 0001: Frequency Divider register                                   */
   __IO uint8_t   C1;                           /*!< 0002: Control Register 1                                           */
   __IO uint8_t   S;                            /*!< 0003: Status Register                                              */
   __IO uint8_t   D;                            /*!< 0004: Data I/O register                                            */
   __IO uint8_t   C2;                           /*!< 0005: Control Register 2                                           */
   __IO uint8_t   FLT;                          /*!< 0006: Programmable Input Glitch Filter register                    */
   __IO uint8_t   RA;                           /*!< 0007: Range Address register                                       */
   __IO uint8_t   SMB;                          /*!< 0008: SMBus Control and Status register                            */
   __IO uint8_t   A2;                           /*!< 0009: Address Register 2                                           */
   __IO uint8_t   SLTH;                         /*!< 000A: SCL Low Timeout Register High                                */
   __IO uint8_t   SLTL;                         /*!< 000B: SCL Low Timeout Register Low                                 */
} I2C0_Type;


/* -------------------------------------------------------------------------------- */
/* -----------     'I2C0' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */


/* ------- I2C0_A1                                  ------ */
#define I2C_A1_AD_MASK                           (0x7FUL << I2C_A1_AD_SHIFT)                         /*!< I2C0_A1: AD Mask                        */
#define I2C_A1_AD_SHIFT                          1                                                   /*!< I2C0_A1: AD Position                    */
#define I2C_A1_AD(x)                             (((x)<<I2C_A1_AD_SHIFT)&I2C_A1_AD_MASK)             /*!< I2C0_A1                                 */

/* ------- I2C0_F                                   ------ */
#define I2C_F_ICR_MASK                           (0x3FUL << I2C_F_ICR_SHIFT)                         /*!< I2C0_F: ICR Mask                        */
#define I2C_F_ICR_SHIFT                          0                                                   /*!< I2C0_F: ICR Position                    */
#define I2C_F_ICR(x)                             (((x)<<I2C_F_ICR_SHIFT)&I2C_F_ICR_MASK)             /*!< I2C0_F                                  */
#define I2C_F_MULT_MASK                          (0x03UL << I2C_F_MULT_SHIFT)                        /*!< I2C0_F: MULT Mask                       */
#define I2C_F_MULT_SHIFT                         6                                                   /*!< I2C0_F: MULT Position                   */
#define I2C_F_MULT(x)                            (((x)<<I2C_F_MULT_SHIFT)&I2C_F_MULT_MASK)           /*!< I2C0_F                                  */

/* ------- I2C0_C1                                  ------ */
#define I2C_C1_DMAEN_MASK                        (0x01UL << I2C_C1_DMAEN_SHIFT)                      /*!< I2C0_C1: DMAEN Mask                     */
#define I2C_C1_DMAEN_SHIFT                       0                                                   /*!< I2C0_C1: DMAEN Position                 */
#define I2C_C1_WUEN_MASK                         (0x01UL << I2C_C1_WUEN_SHIFT)                       /*!< I2C0_C1: WUEN Mask                      */
#define I2C_C1_WUEN_SHIFT                        1                                                   /*!< I2C0_C1: WUEN Position                  */
#define I2C_C1_RSTA_MASK                         (0x01UL << I2C_C1_RSTA_SHIFT)                       /*!< I2C0_C1: RSTA Mask                      */
#define I2C_C1_RSTA_SHIFT                        2                                                   /*!< I2C0_C1: RSTA Position                  */
#define I2C_C1_TXAK_MASK                         (0x01UL << I2C_C1_TXAK_SHIFT)                       /*!< I2C0_C1: TXAK Mask                      */
#define I2C_C1_TXAK_SHIFT                        3                                                   /*!< I2C0_C1: TXAK Position                  */
#define I2C_C1_TX_MASK                           (0x01UL << I2C_C1_TX_SHIFT)                         /*!< I2C0_C1: TX Mask                        */
#define I2C_C1_TX_SHIFT                          4                                                   /*!< I2C0_C1: TX Position                    */
#define I2C_C1_MST_MASK                          (0x01UL << I2C_C1_MST_SHIFT)                        /*!< I2C0_C1: MST Mask                       */
#define I2C_C1_MST_SHIFT                         5                                                   /*!< I2C0_C1: MST Position                   */
#define I2C_C1_IICIE_MASK                        (0x01UL << I2C_C1_IICIE_SHIFT)                      /*!< I2C0_C1: IICIE Mask                     */
#define I2C_C1_IICIE_SHIFT                       6                                                   /*!< I2C0_C1: IICIE Position                 */
#define I2C_C1_IICEN_MASK                        (0x01UL << I2C_C1_IICEN_SHIFT)                      /*!< I2C0_C1: IICEN Mask                     */
#define I2C_C1_IICEN_SHIFT                       7                                                   /*!< I2C0_C1: IICEN Position                 */

/* ------- I2C0_S                                   ------ */
#define I2C_S_RXAK_MASK                          (0x01UL << I2C_S_RXAK_SHIFT)                        /*!< I2C0_S: RXAK Mask                       */
#define I2C_S_RXAK_SHIFT                         0                                                   /*!< I2C0_S: RXAK Position                   */
#define I2C_S_IICIF_MASK                         (0x01UL << I2C_S_IICIF_SHIFT)                       /*!< I2C0_S: IICIF Mask                      */
#define I2C_S_IICIF_SHIFT                        1                                                   /*!< I2C0_S: IICIF Position                  */
#define I2C_S_SRW_MASK                           (0x01UL << I2C_S_SRW_SHIFT)                         /*!< I2C0_S: SRW Mask                        */
#define I2C_S_SRW_SHIFT                          2                                                   /*!< I2C0_S: SRW Position                    */
#define I2C_S_RAM_MASK                           (0x01UL << I2C_S_RAM_SHIFT)                         /*!< I2C0_S: RAM Mask                        */
#define I2C_S_RAM_SHIFT                          3                                                   /*!< I2C0_S: RAM Position                    */
#define I2C_S_ARBL_MASK                          (0x01UL << I2C_S_ARBL_SHIFT)                        /*!< I2C0_S: ARBL Mask                       */
#define I2C_S_ARBL_SHIFT                         4                                                   /*!< I2C0_S: ARBL Position                   */
#define I2C_S_BUSY_MASK                          (0x01UL << I2C_S_BUSY_SHIFT)                        /*!< I2C0_S: BUSY Mask                       */
#define I2C_S_BUSY_SHIFT                         5                                                   /*!< I2C0_S: BUSY Position                   */
#define I2C_S_IAAS_MASK                          (0x01UL << I2C_S_IAAS_SHIFT)                        /*!< I2C0_S: IAAS Mask                       */
#define I2C_S_IAAS_SHIFT                         6                                                   /*!< I2C0_S: IAAS Position                   */
#define I2C_S_TCF_MASK                           (0x01UL << I2C_S_TCF_SHIFT)                         /*!< I2C0_S: TCF Mask                        */
#define I2C_S_TCF_SHIFT                          7                                                   /*!< I2C0_S: TCF Position                    */

/* ------- I2C0_D                                   ------ */
#define I2C_D_DATA_MASK                          (0xFFUL << I2C_D_DATA_SHIFT)                        /*!< I2C0_D: DATA Mask                       */
#define I2C_D_DATA_SHIFT                         0                                                   /*!< I2C0_D: DATA Position                   */
#define I2C_D_DATA(x)                            (((x)<<I2C_D_DATA_SHIFT)&I2C_D_DATA_MASK)           /*!< I2C0_D                                  */

/* ------- I2C0_C2                                  ------ */
#define I2C_C2_AD_MASK                           (0x07UL << I2C_C2_AD_SHIFT)                         /*!< I2C0_C2: AD Mask                        */
#define I2C_C2_AD_SHIFT                          0                                                   /*!< I2C0_C2: AD Position                    */
#define I2C_C2_AD(x)                             (((x)<<I2C_C2_AD_SHIFT)&I2C_C2_AD_MASK)             /*!< I2C0_C2                                 */
#define I2C_C2_RMEN_MASK                         (0x01UL << I2C_C2_RMEN_SHIFT)                       /*!< I2C0_C2: RMEN Mask                      */
#define I2C_C2_RMEN_SHIFT                        3                                                   /*!< I2C0_C2: RMEN Position                  */
#define I2C_C2_SBRC_MASK                         (0x01UL << I2C_C2_SBRC_SHIFT)                       /*!< I2C0_C2: SBRC Mask                      */
#define I2C_C2_SBRC_SHIFT                        4                                                   /*!< I2C0_C2: SBRC Position                  */
#define I2C_C2_HDRS_MASK                         (0x01UL << I2C_C2_HDRS_SHIFT)                       /*!< I2C0_C2: HDRS Mask                      */
#define I2C_C2_HDRS_SHIFT                        5                                                   /*!< I2C0_C2: HDRS Position                  */
#define I2C_C2_ADEXT_MASK                        (0x01UL << I2C_C2_ADEXT_SHIFT)                      /*!< I2C0_C2: ADEXT Mask                     */
#define I2C_C2_ADEXT_SHIFT                       6                                                   /*!< I2C0_C2: ADEXT Position                 */
#define I2C_C2_GCAEN_MASK                        (0x01UL << I2C_C2_GCAEN_SHIFT)                      /*!< I2C0_C2: GCAEN Mask                     */
#define I2C_C2_GCAEN_SHIFT                       7                                                   /*!< I2C0_C2: GCAEN Position                 */

/* ------- I2C0_FLT                                 ------ */
#define I2C_FLT_FLT_MASK                         (0x1FUL << I2C_FLT_FLT_SHIFT)                       /*!< I2C0_FLT: FLT Mask                      */
#define I2C_FLT_FLT_SHIFT                        0                                                   /*!< I2C0_FLT: FLT Position                  */
#define I2C_FLT_FLT(x)                           (((x)<<I2C_FLT_FLT_SHIFT)&I2C_FLT_FLT_MASK)         /*!< I2C0_FLT                                */
#define I2C_FLT_STOPIE_MASK                      (0x01UL << I2C_FLT_STOPIE_SHIFT)                    /*!< I2C0_FLT: STOPIE Mask                   */
#define I2C_FLT_STOPIE_SHIFT                     5                                                   /*!< I2C0_FLT: STOPIE Position               */
#define I2C_FLT_STOPF_MASK                       (0x01UL << I2C_FLT_STOPF_SHIFT)                     /*!< I2C0_FLT: STOPF Mask                    */
#define I2C_FLT_STOPF_SHIFT                      6                                                   /*!< I2C0_FLT: STOPF Position                */
#define I2C_FLT_SHEN_MASK                        (0x01UL << I2C_FLT_SHEN_SHIFT)                      /*!< I2C0_FLT: SHEN Mask                     */
#define I2C_FLT_SHEN_SHIFT                       7                                                   /*!< I2C0_FLT: SHEN Position                 */

/* ------- I2C0_RA                                  ------ */
#define I2C_RA_RAD_MASK                          (0x7FUL << I2C_RA_RAD_SHIFT)                        /*!< I2C0_RA: RAD Mask                       */
#define I2C_RA_RAD_SHIFT                         1                                                   /*!< I2C0_RA: RAD Position                   */
#define I2C_RA_RAD(x)                            (((x)<<I2C_RA_RAD_SHIFT)&I2C_RA_RAD_MASK)           /*!< I2C0_RA                                 */

/* ------- I2C0_SMB                                 ------ */
#define I2C_SMB_SHTF2IE_MASK                     (0x01UL << I2C_SMB_SHTF2IE_SHIFT)                   /*!< I2C0_SMB: SHTF2IE Mask                  */
#define I2C_SMB_SHTF2IE_SHIFT                    0                                                   /*!< I2C0_SMB: SHTF2IE Position              */
#define I2C_SMB_SHTF2_MASK                       (0x01UL << I2C_SMB_SHTF2_SHIFT)                     /*!< I2C0_SMB: SHTF2 Mask                    */
#define I2C_SMB_SHTF2_SHIFT                      1                                                   /*!< I2C0_SMB: SHTF2 Position                */
#define I2C_SMB_SHTF1_MASK                       (0x01UL << I2C_SMB_SHTF1_SHIFT)                     /*!< I2C0_SMB: SHTF1 Mask                    */
#define I2C_SMB_SHTF1_SHIFT                      2                                                   /*!< I2C0_SMB: SHTF1 Position                */
#define I2C_SMB_SLTF_MASK                        (0x01UL << I2C_SMB_SLTF_SHIFT)                      /*!< I2C0_SMB: SLTF Mask                     */
#define I2C_SMB_SLTF_SHIFT                       3                                                   /*!< I2C0_SMB: SLTF Position                 */
#define I2C_SMB_TCKSEL_MASK                      (0x01UL << I2C_SMB_TCKSEL_SHIFT)                    /*!< I2C0_SMB: TCKSEL Mask                   */
#define I2C_SMB_TCKSEL_SHIFT                     4                                                   /*!< I2C0_SMB: TCKSEL Position               */
#define I2C_SMB_SIICAEN_MASK                     (0x01UL << I2C_SMB_SIICAEN_SHIFT)                   /*!< I2C0_SMB: SIICAEN Mask                  */
#define I2C_SMB_SIICAEN_SHIFT                    5                                                   /*!< I2C0_SMB: SIICAEN Position              */
#define I2C_SMB_ALERTEN_MASK                     (0x01UL << I2C_SMB_ALERTEN_SHIFT)                   /*!< I2C0_SMB: ALERTEN Mask                  */
#define I2C_SMB_ALERTEN_SHIFT                    6                                                   /*!< I2C0_SMB: ALERTEN Position              */
#define I2C_SMB_FACK_MASK                        (0x01UL << I2C_SMB_FACK_SHIFT)                      /*!< I2C0_SMB: FACK Mask                     */
#define I2C_SMB_FACK_SHIFT                       7                                                   /*!< I2C0_SMB: FACK Position                 */

/* ------- I2C0_A2                                  ------ */
#define I2C_A2_SAD_MASK                          (0x7FUL << I2C_A2_SAD_SHIFT)                        /*!< I2C0_A2: SAD Mask                       */
#define I2C_A2_SAD_SHIFT                         1                                                   /*!< I2C0_A2: SAD Position                   */
#define I2C_A2_SAD(x)                            (((x)<<I2C_A2_SAD_SHIFT)&I2C_A2_SAD_MASK)           /*!< I2C0_A2                                 */

/* ------- I2C0_SLTH                                ------ */
#define I2C_SLTH_SSLT_MASK                       (0xFFUL << I2C_SLTH_SSLT_SHIFT)                     /*!< I2C0_SLTH: SSLT Mask                    */
#define I2C_SLTH_SSLT_SHIFT                      0                                                   /*!< I2C0_SLTH: SSLT Position                */
#define I2C_SLTH_SSLT(x)                         (((x)<<I2C_SLTH_SSLT_SHIFT)&I2C_SLTH_SSLT_MASK)     /*!< I2C0_SLTH                               */

/* ------- I2C0_SLTL                                ------ */
#define I2C_SLTL_SSLT_MASK                       (0xFFUL << I2C_SLTL_SSLT_SHIFT)                     /*!< I2C0_SLTL: SSLT Mask                    */
#define I2C_SLTL_SSLT_SHIFT                      0                                                   /*!< I2C0_SLTL: SSLT Position                */
#define I2C_SLTL_SSLT(x)                         (((x)<<I2C_SLTL_SSLT_SHIFT)&I2C_SLTL_SSLT_MASK)     /*!< I2C0_SLTL                               */

/* -------------------------------------------------------------------------------- */
/* -----------     'I2C0' Register Access macros                        ----------- */
/* -------------------------------------------------------------------------------- */

#define I2C0_A1                        (I2C0->A1)
#define I2C0_F                         (I2C0->F)
#define I2C0_C1                        (I2C0->C1)
#define I2C0_S                         (I2C0->S)
#define I2C0_D                         (I2C0->D)
#define I2C0_C2                        (I2C0->C2)
#define I2C0_FLT                       (I2C0->FLT)
#define I2C0_RA                        (I2C0->RA)
#define I2C0_SMB                       (I2C0->SMB)
#define I2C0_A2                        (I2C0->A2)
#define I2C0_SLTH                      (I2C0->SLTH)
#define I2C0_SLTL                      (I2C0->SLTL)

/* ================================================================================ */
/* ================           LLWU (file:LLWU_MKL_1)               ================ */
/* ================================================================================ */

/**
 * @brief Low leakage wakeup unit
 */
typedef struct {                                /*!<       LLWU Structure                                               */
   __IO uint8_t   PE1;                          /*!< 0000: Pin Enable 1 Register                                        */
   __IO uint8_t   PE2;                          /*!< 0001: Pin Enable 2 Register                                        */
   __IO uint8_t   PE3;                          /*!< 0002: Pin Enable 3 Register                                        */
   __IO uint8_t   PE4;                          /*!< 0003: Pin Enable 4 Register                                        */
   __IO uint8_t   ME;                           /*!< 0004: Module Enable Register                                       */
   __IO uint8_t   F1;                           /*!< 0005: Flag 1 Register                                              */
   __IO uint8_t   F2;                           /*!< 0006: Flag 2 Register                                              */
   __IO uint8_t   F3;                           /*!< 0007: Flag 3 Register                                              */
   __IO uint8_t   FILT1;                        /*!< 0008: Pin Filter 1 register                                        */
   __IO uint8_t   FILT2;                        /*!< 0009: Pin Filter 2 register                                        */
} LLWU_Type;


/* -------------------------------------------------------------------------------- */
/* -----------     'LLWU' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */


/* ------- LLWU_PE1                                 ------ */
#define LLWU_PE1_WUPE0_MASK                      (0x03UL << LLWU_PE1_WUPE0_SHIFT)                    /*!< LLWU_PE1: WUPE0 Mask                    */
#define LLWU_PE1_WUPE0_SHIFT                     0                                                   /*!< LLWU_PE1: WUPE0 Position                */
#define LLWU_PE1_WUPE0(x)                        (((x)<<LLWU_PE1_WUPE0_SHIFT)&LLWU_PE1_WUPE0_MASK)   /*!< LLWU_PE1                                */
#define LLWU_PE1_WUPE1_MASK                      (0x03UL << LLWU_PE1_WUPE1_SHIFT)                    /*!< LLWU_PE1: WUPE1 Mask                    */
#define LLWU_PE1_WUPE1_SHIFT                     2                                                   /*!< LLWU_PE1: WUPE1 Position                */
#define LLWU_PE1_WUPE1(x)                        (((x)<<LLWU_PE1_WUPE1_SHIFT)&LLWU_PE1_WUPE1_MASK)   /*!< LLWU_PE1                                */
#define LLWU_PE1_WUPE2_MASK                      (0x03UL << LLWU_PE1_WUPE2_SHIFT)                    /*!< LLWU_PE1: WUPE2 Mask                    */
#define LLWU_PE1_WUPE2_SHIFT                     4                                                   /*!< LLWU_PE1: WUPE2 Position                */
#define LLWU_PE1_WUPE2(x)                        (((x)<<LLWU_PE1_WUPE2_SHIFT)&LLWU_PE1_WUPE2_MASK)   /*!< LLWU_PE1                                */
#define LLWU_PE1_WUPE3_MASK                      (0x03UL << LLWU_PE1_WUPE3_SHIFT)                    /*!< LLWU_PE1: WUPE3 Mask                    */
#define LLWU_PE1_WUPE3_SHIFT                     6                                                   /*!< LLWU_PE1: WUPE3 Position                */
#define LLWU_PE1_WUPE3(x)                        (((x)<<LLWU_PE1_WUPE3_SHIFT)&LLWU_PE1_WUPE3_MASK)   /*!< LLWU_PE1                                */

/* ------- LLWU_PE2                                 ------ */
#define LLWU_PE2_WUPE4_MASK                      (0x03UL << LLWU_PE2_WUPE4_SHIFT)                    /*!< LLWU_PE2: WUPE4 Mask                    */
#define LLWU_PE2_WUPE4_SHIFT                     0                                                   /*!< LLWU_PE2: WUPE4 Position                */
#define LLWU_PE2_WUPE4(x)                        (((x)<<LLWU_PE2_WUPE4_SHIFT)&LLWU_PE2_WUPE4_MASK)   /*!< LLWU_PE2                                */
#define LLWU_PE2_WUPE5_MASK                      (0x03UL << LLWU_PE2_WUPE5_SHIFT)                    /*!< LLWU_PE2: WUPE5 Mask                    */
#define LLWU_PE2_WUPE5_SHIFT                     2                                                   /*!< LLWU_PE2: WUPE5 Position                */
#define LLWU_PE2_WUPE5(x)                        (((x)<<LLWU_PE2_WUPE5_SHIFT)&LLWU_PE2_WUPE5_MASK)   /*!< LLWU_PE2                                */
#define LLWU_PE2_WUPE6_MASK                      (0x03UL << LLWU_PE2_WUPE6_SHIFT)                    /*!< LLWU_PE2: WUPE6 Mask                    */
#define LLWU_PE2_WUPE6_SHIFT                     4                                                   /*!< LLWU_PE2: WUPE6 Position                */
#define LLWU_PE2_WUPE6(x)                        (((x)<<LLWU_PE2_WUPE6_SHIFT)&LLWU_PE2_WUPE6_MASK)   /*!< LLWU_PE2                                */
#define LLWU_PE2_WUPE7_MASK                      (0x03UL << LLWU_PE2_WUPE7_SHIFT)                    /*!< LLWU_PE2: WUPE7 Mask                    */
#define LLWU_PE2_WUPE7_SHIFT                     6                                                   /*!< LLWU_PE2: WUPE7 Position                */
#define LLWU_PE2_WUPE7(x)                        (((x)<<LLWU_PE2_WUPE7_SHIFT)&LLWU_PE2_WUPE7_MASK)   /*!< LLWU_PE2                                */

/* ------- LLWU_PE3                                 ------ */
#define LLWU_PE3_WUPE8_MASK                      (0x03UL << LLWU_PE3_WUPE8_SHIFT)                    /*!< LLWU_PE3: WUPE8 Mask                    */
#define LLWU_PE3_WUPE8_SHIFT                     0                                                   /*!< LLWU_PE3: WUPE8 Position                */
#define LLWU_PE3_WUPE8(x)                        (((x)<<LLWU_PE3_WUPE8_SHIFT)&LLWU_PE3_WUPE8_MASK)   /*!< LLWU_PE3                                */
#define LLWU_PE3_WUPE9_MASK                      (0x03UL << LLWU_PE3_WUPE9_SHIFT)                    /*!< LLWU_PE3: WUPE9 Mask                    */
#define LLWU_PE3_WUPE9_SHIFT                     2                                                   /*!< LLWU_PE3: WUPE9 Position                */
#define LLWU_PE3_WUPE9(x)                        (((x)<<LLWU_PE3_WUPE9_SHIFT)&LLWU_PE3_WUPE9_MASK)   /*!< LLWU_PE3                                */
#define LLWU_PE3_WUPE10_MASK                     (0x03UL << LLWU_PE3_WUPE10_SHIFT)                   /*!< LLWU_PE3: WUPE10 Mask                   */
#define LLWU_PE3_WUPE10_SHIFT                    4                                                   /*!< LLWU_PE3: WUPE10 Position               */
#define LLWU_PE3_WUPE10(x)                       (((x)<<LLWU_PE3_WUPE10_SHIFT)&LLWU_PE3_WUPE10_MASK) /*!< LLWU_PE3                                */
#define LLWU_PE3_WUPE11_MASK                     (0x03UL << LLWU_PE3_WUPE11_SHIFT)                   /*!< LLWU_PE3: WUPE11 Mask                   */
#define LLWU_PE3_WUPE11_SHIFT                    6                                                   /*!< LLWU_PE3: WUPE11 Position               */
#define LLWU_PE3_WUPE11(x)                       (((x)<<LLWU_PE3_WUPE11_SHIFT)&LLWU_PE3_WUPE11_MASK) /*!< LLWU_PE3                                */

/* ------- LLWU_PE4                                 ------ */
#define LLWU_PE4_WUPE12_MASK                     (0x03UL << LLWU_PE4_WUPE12_SHIFT)                   /*!< LLWU_PE4: WUPE12 Mask                   */
#define LLWU_PE4_WUPE12_SHIFT                    0                                                   /*!< LLWU_PE4: WUPE12 Position               */
#define LLWU_PE4_WUPE12(x)                       (((x)<<LLWU_PE4_WUPE12_SHIFT)&LLWU_PE4_WUPE12_MASK) /*!< LLWU_PE4                                */
#define LLWU_PE4_WUPE13_MASK                     (0x03UL << LLWU_PE4_WUPE13_SHIFT)                   /*!< LLWU_PE4: WUPE13 Mask                   */
#define LLWU_PE4_WUPE13_SHIFT                    2                                                   /*!< LLWU_PE4: WUPE13 Position               */
#define LLWU_PE4_WUPE13(x)                       (((x)<<LLWU_PE4_WUPE13_SHIFT)&LLWU_PE4_WUPE13_MASK) /*!< LLWU_PE4                                */
#define LLWU_PE4_WUPE14_MASK                     (0x03UL << LLWU_PE4_WUPE14_SHIFT)                   /*!< LLWU_PE4: WUPE14 Mask                   */
#define LLWU_PE4_WUPE14_SHIFT                    4                                                   /*!< LLWU_PE4: WUPE14 Position               */
#define LLWU_PE4_WUPE14(x)                       (((x)<<LLWU_PE4_WUPE14_SHIFT)&LLWU_PE4_WUPE14_MASK) /*!< LLWU_PE4                                */
#define LLWU_PE4_WUPE15_MASK                     (0x03UL << LLWU_PE4_WUPE15_SHIFT)                   /*!< LLWU_PE4: WUPE15 Mask                   */
#define LLWU_PE4_WUPE15_SHIFT                    6                                                   /*!< LLWU_PE4: WUPE15 Position               */
#define LLWU_PE4_WUPE15(x)                       (((x)<<LLWU_PE4_WUPE15_SHIFT)&LLWU_PE4_WUPE15_MASK) /*!< LLWU_PE4                                */

/* ------- LLWU_ME                                  ------ */
#define LLWU_ME_WUME_MASK                        (0xFFUL << LLWU_ME_WUME_SHIFT)                      /*!< LLWU_ME: WUME Mask                      */
#define LLWU_ME_WUME_SHIFT                       0                                                   /*!< LLWU_ME: WUME Position                  */
#define LLWU_ME_WUME(x)                          (((x)<<LLWU_ME_WUME_SHIFT)&LLWU_ME_WUME_MASK)       /*!< LLWU_ME                                 */

/* ------- LLWU_F1                                  ------ */
#define LLWU_F1_WUF0_MASK                        (0xFFUL << LLWU_F1_WUF0_SHIFT)                      /*!< LLWU_F1: WUF0 Mask                      */
#define LLWU_F1_WUF0_SHIFT                       0                                                   /*!< LLWU_F1: WUF0 Position                  */
#define LLWU_F1_WUF0(x)                          (((x)<<LLWU_F1_WUF0_SHIFT)&LLWU_F1_WUF0_MASK)       /*!< LLWU_F1                                 */

/* ------- LLWU_F2                                  ------ */
#define LLWU_F2_WUFn_MASK                        (0xFFUL << LLWU_F2_WUFn_SHIFT)                      /*!< LLWU_F2: WUFn Mask                      */
#define LLWU_F2_WUFn_SHIFT                       0                                                   /*!< LLWU_F2: WUFn Position                  */
#define LLWU_F2_WUFn(x)                          (((x)<<LLWU_F2_WUFn_SHIFT)&LLWU_F2_WUFn_MASK)       /*!< LLWU_F2                                 */

/* ------- LLWU_F3                                  ------ */
#define LLWU_F3_MWUFn_MASK                       (0xFFUL << LLWU_F3_MWUFn_SHIFT)                     /*!< LLWU_F3: MWUFn Mask                     */
#define LLWU_F3_MWUFn_SHIFT                      0                                                   /*!< LLWU_F3: MWUFn Position                 */
#define LLWU_F3_MWUFn(x)                         (((x)<<LLWU_F3_MWUFn_SHIFT)&LLWU_F3_MWUFn_MASK)     /*!< LLWU_F3                                 */

/* ------- LLWU_FILT                                ------ */
#define LLWU_FILT_FILTSEL_MASK                   (0x0FUL << LLWU_FILT_FILTSEL_SHIFT)                 /*!< LLWU_FILT: FILTSEL Mask                 */
#define LLWU_FILT_FILTSEL_SHIFT                  0                                                   /*!< LLWU_FILT: FILTSEL Position             */
#define LLWU_FILT_FILTSEL(x)                     (((x)<<LLWU_FILT_FILTSEL_SHIFT)&LLWU_FILT_FILTSEL_MASK) /*!< LLWU_FILT                               */
#define LLWU_FILT_FILTE_MASK                     (0x03UL << LLWU_FILT_FILTE_SHIFT)                   /*!< LLWU_FILT: FILTE Mask                   */
#define LLWU_FILT_FILTE_SHIFT                    5                                                   /*!< LLWU_FILT: FILTE Position               */
#define LLWU_FILT_FILTE(x)                       (((x)<<LLWU_FILT_FILTE_SHIFT)&LLWU_FILT_FILTE_MASK) /*!< LLWU_FILT                               */
#define LLWU_FILT_FILTF_MASK                     (0x01UL << LLWU_FILT_FILTF_SHIFT)                   /*!< LLWU_FILT: FILTF Mask                   */
#define LLWU_FILT_FILTF_SHIFT                    7                                                   /*!< LLWU_FILT: FILTF Position               */

/* -------------------------------------------------------------------------------- */
/* -----------     'LLWU' Register Access macros                        ----------- */
/* -------------------------------------------------------------------------------- */

#define LLWU_PE1                       (LLWU->PE1)
#define LLWU_PE2                       (LLWU->PE2)
#define LLWU_PE3                       (LLWU->PE3)
#define LLWU_PE4                       (LLWU->PE4)
#define LLWU_ME                        (LLWU->ME)
#define LLWU_F1                        (LLWU->F1)
#define LLWU_F2                        (LLWU->F2)
#define LLWU_F3                        (LLWU->F3)
#define LLWU_FILT1                     (LLWU->FILT1)
#define LLWU_FILT2                     (LLWU->FILT2)

/* ================================================================================ */
/* ================           LPTMR0 (file:LPTMR0_MKM)             ================ */
/* ================================================================================ */

/**
 * @brief Low Power Timer
 */
typedef struct {                                /*!<       LPTMR0 Structure                                             */
   __IO uint32_t  CSR;                          /*!< 0000: Control Status Register                                      */
   __IO uint32_t  PSR;                          /*!< 0004: Prescale Register                                            */
   __IO uint32_t  CMR;                          /*!< 0008: Compare Register                                             */
   __I  uint32_t  CNR;                          /*!< 000C: Counter Register                                             */
} LPTMR0_Type;


/* -------------------------------------------------------------------------------- */
/* -----------     'LPTMR0' Position & Mask macros                      ----------- */
/* -------------------------------------------------------------------------------- */


/* ------- LPTMR0_CSR                               ------ */
#define LPTMR_CSR_TEN_MASK                       (0x01UL << LPTMR_CSR_TEN_SHIFT)                     /*!< LPTMR0_CSR: TEN Mask                    */
#define LPTMR_CSR_TEN_SHIFT                      0                                                   /*!< LPTMR0_CSR: TEN Position                */
#define LPTMR_CSR_TMS_MASK                       (0x01UL << LPTMR_CSR_TMS_SHIFT)                     /*!< LPTMR0_CSR: TMS Mask                    */
#define LPTMR_CSR_TMS_SHIFT                      1                                                   /*!< LPTMR0_CSR: TMS Position                */
#define LPTMR_CSR_TFC_MASK                       (0x01UL << LPTMR_CSR_TFC_SHIFT)                     /*!< LPTMR0_CSR: TFC Mask                    */
#define LPTMR_CSR_TFC_SHIFT                      2                                                   /*!< LPTMR0_CSR: TFC Position                */
#define LPTMR_CSR_TPP_MASK                       (0x01UL << LPTMR_CSR_TPP_SHIFT)                     /*!< LPTMR0_CSR: TPP Mask                    */
#define LPTMR_CSR_TPP_SHIFT                      3                                                   /*!< LPTMR0_CSR: TPP Position                */
#define LPTMR_CSR_TPS_MASK                       (0x03UL << LPTMR_CSR_TPS_SHIFT)                     /*!< LPTMR0_CSR: TPS Mask                    */
#define LPTMR_CSR_TPS_SHIFT                      4                                                   /*!< LPTMR0_CSR: TPS Position                */
#define LPTMR_CSR_TPS(x)                         (((x)<<LPTMR_CSR_TPS_SHIFT)&LPTMR_CSR_TPS_MASK)     /*!< LPTMR0_CSR                              */
#define LPTMR_CSR_TIE_MASK                       (0x01UL << LPTMR_CSR_TIE_SHIFT)                     /*!< LPTMR0_CSR: TIE Mask                    */
#define LPTMR_CSR_TIE_SHIFT                      6                                                   /*!< LPTMR0_CSR: TIE Position                */
#define LPTMR_CSR_TCF_MASK                       (0x01UL << LPTMR_CSR_TCF_SHIFT)                     /*!< LPTMR0_CSR: TCF Mask                    */
#define LPTMR_CSR_TCF_SHIFT                      7                                                   /*!< LPTMR0_CSR: TCF Position                */

/* ------- LPTMR0_PSR                               ------ */
#define LPTMR_PSR_PCS_MASK                       (0x03UL << LPTMR_PSR_PCS_SHIFT)                     /*!< LPTMR0_PSR: PCS Mask                    */
#define LPTMR_PSR_PCS_SHIFT                      0                                                   /*!< LPTMR0_PSR: PCS Position                */
#define LPTMR_PSR_PCS(x)                         (((x)<<LPTMR_PSR_PCS_SHIFT)&LPTMR_PSR_PCS_MASK)     /*!< LPTMR0_PSR                              */
#define LPTMR_PSR_PBYP_MASK                      (0x01UL << LPTMR_PSR_PBYP_SHIFT)                    /*!< LPTMR0_PSR: PBYP Mask                   */
#define LPTMR_PSR_PBYP_SHIFT                     2                                                   /*!< LPTMR0_PSR: PBYP Position               */
#define LPTMR_PSR_PRESCALE_MASK                  (0x0FUL << LPTMR_PSR_PRESCALE_SHIFT)                /*!< LPTMR0_PSR: PRESCALE Mask               */
#define LPTMR_PSR_PRESCALE_SHIFT                 3                                                   /*!< LPTMR0_PSR: PRESCALE Position           */
#define LPTMR_PSR_PRESCALE(x)                    (((x)<<LPTMR_PSR_PRESCALE_SHIFT)&LPTMR_PSR_PRESCALE_MASK) /*!< LPTMR0_PSR                              */

/* ------- LPTMR0_CMR                               ------ */
#define LPTMR_CMR_COMPARE_MASK                   (0xFFFFUL << LPTMR_CMR_COMPARE_SHIFT)               /*!< LPTMR0_CMR: COMPARE Mask                */
#define LPTMR_CMR_COMPARE_SHIFT                  0                                                   /*!< LPTMR0_CMR: COMPARE Position            */
#define LPTMR_CMR_COMPARE(x)                     (((x)<<LPTMR_CMR_COMPARE_SHIFT)&LPTMR_CMR_COMPARE_MASK) /*!< LPTMR0_CMR                              */

/* ------- LPTMR0_CNR                               ------ */
#define LPTMR_CNR_COUNTER_MASK                   (0xFFFFUL << LPTMR_CNR_COUNTER_SHIFT)               /*!< LPTMR0_CNR: COUNTER Mask                */
#define LPTMR_CNR_COUNTER_SHIFT                  0                                                   /*!< LPTMR0_CNR: COUNTER Position            */
#define LPTMR_CNR_COUNTER(x)                     (((x)<<LPTMR_CNR_COUNTER_SHIFT)&LPTMR_CNR_COUNTER_MASK) /*!< LPTMR0_CNR                              */

/* -------------------------------------------------------------------------------- */
/* -----------     'LPTMR0' Register Access macros                      ----------- */
/* -------------------------------------------------------------------------------- */

#define LPTMR0_CSR                     (LPTMR0->CSR)
#define LPTMR0_PSR                     (LPTMR0->PSR)
#define LPTMR0_CMR                     (LPTMR0->CMR)
#define LPTMR0_CNR                     (LPTMR0->CNR)

/* ================================================================================ */
/* ================           MCG (file:MCG_MKM)                   ================ */
/* ================================================================================ */

/**
 * @brief Multipurpose Clock Generator module
 */
typedef struct {                                /*!<       MCG Structure                                                */
   __IO uint8_t   C1;                           /*!< 0000: Control 1 Register                                           */
   __IO uint8_t   C2;                           /*!< 0001: Control 2 Register                                           */
   __IO uint8_t   C3;                           /*!< 0002: Control 3 Register                                           */
   __IO uint8_t   C4;                           /*!< 0003: Control 4 Register                                           */
   __IO uint8_t   C5;                           /*!< 0004: Control 5 Register                                           */
   __IO uint8_t   C6;                           /*!< 0005: Control 6 Register                                           */
   __I  uint8_t   S;                            /*!< 0006: Status Register                                              */
   __I  uint8_t   RESERVED0;                    /*!< 0007:                                                              */
   __IO uint8_t   SC;                           /*!< 0008: Status and Control Register                                  */
   __I  uint8_t   RESERVED1;                    /*!< 0009:                                                              */
   __IO uint8_t   ATCVH;                        /*!< 000A: Auto Trim Compare Value High Register                        */
   __IO uint8_t   ATCVL;                        /*!< 000B: Auto Trim Compare Value Low Register                         */
   __IO uint8_t   C7;                           /*!< 000C: Control 7 Register                                           */
   __IO uint8_t   C8;                           /*!< 000D: Control 8 Register                                           */
   __IO uint8_t   C9;                           /*!< 000E: Control 9 Register                                           */
} MCG_Type;


/* -------------------------------------------------------------------------------- */
/* -----------     'MCG' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */


/* ------- MCG_C1                                   ------ */
#define MCG_C1_IREFSTEN_MASK                     (0x01UL << MCG_C1_IREFSTEN_SHIFT)                   /*!< MCG_C1: IREFSTEN Mask                   */
#define MCG_C1_IREFSTEN_SHIFT                    0                                                   /*!< MCG_C1: IREFSTEN Position               */
#define MCG_C1_IRCLKEN_MASK                      (0x01UL << MCG_C1_IRCLKEN_SHIFT)                    /*!< MCG_C1: IRCLKEN Mask                    */
#define MCG_C1_IRCLKEN_SHIFT                     1                                                   /*!< MCG_C1: IRCLKEN Position                */
#define MCG_C1_IREFS_MASK                        (0x01UL << MCG_C1_IREFS_SHIFT)                      /*!< MCG_C1: IREFS Mask                      */
#define MCG_C1_IREFS_SHIFT                       2                                                   /*!< MCG_C1: IREFS Position                  */
#define MCG_C1_FRDIV_MASK                        (0x07UL << MCG_C1_FRDIV_SHIFT)                      /*!< MCG_C1: FRDIV Mask                      */
#define MCG_C1_FRDIV_SHIFT                       3                                                   /*!< MCG_C1: FRDIV Position                  */
#define MCG_C1_FRDIV(x)                          (((x)<<MCG_C1_FRDIV_SHIFT)&MCG_C1_FRDIV_MASK)       /*!< MCG_C1                                  */
#define MCG_C1_CLKS_MASK                         (0x03UL << MCG_C1_CLKS_SHIFT)                       /*!< MCG_C1: CLKS Mask                       */
#define MCG_C1_CLKS_SHIFT                        6                                                   /*!< MCG_C1: CLKS Position                   */
#define MCG_C1_CLKS(x)                           (((x)<<MCG_C1_CLKS_SHIFT)&MCG_C1_CLKS_MASK)         /*!< MCG_C1                                  */

/* ------- MCG_C2                                   ------ */
#define MCG_C2_IRCS_MASK                         (0x01UL << MCG_C2_IRCS_SHIFT)                       /*!< MCG_C2: IRCS Mask                       */
#define MCG_C2_IRCS_SHIFT                        0                                                   /*!< MCG_C2: IRCS Position                   */
#define MCG_C2_LP_MASK                           (0x01UL << MCG_C2_LP_SHIFT)                         /*!< MCG_C2: LP Mask                         */
#define MCG_C2_LP_SHIFT                          1                                                   /*!< MCG_C2: LP Position                     */
#define MCG_C2_EREFS0_MASK                       (0x01UL << MCG_C2_EREFS0_SHIFT)                     /*!< MCG_C2: EREFS0 Mask                     */
#define MCG_C2_EREFS0_SHIFT                      2                                                   /*!< MCG_C2: EREFS0 Position                 */
#define MCG_C2_HGO0_MASK                         (0x01UL << MCG_C2_HGO0_SHIFT)                       /*!< MCG_C2: HGO0 Mask                       */
#define MCG_C2_HGO0_SHIFT                        3                                                   /*!< MCG_C2: HGO0 Position                   */
#define MCG_C2_RANGE0_MASK                       (0x03UL << MCG_C2_RANGE0_SHIFT)                     /*!< MCG_C2: RANGE0 Mask                     */
#define MCG_C2_RANGE0_SHIFT                      4                                                   /*!< MCG_C2: RANGE0 Position                 */
#define MCG_C2_RANGE0(x)                         (((x)<<MCG_C2_RANGE0_SHIFT)&MCG_C2_RANGE0_MASK)     /*!< MCG_C2                                  */
#define MCG_C2_LOCRE0_MASK                       (0x01UL << MCG_C2_LOCRE0_SHIFT)                     /*!< MCG_C2: LOCRE0 Mask                     */
#define MCG_C2_LOCRE0_SHIFT                      7                                                   /*!< MCG_C2: LOCRE0 Position                 */

/* ------- MCG_C3                                   ------ */
#define MCG_C3_SCTRIM_MASK                       (0xFFUL << MCG_C3_SCTRIM_SHIFT)                     /*!< MCG_C3: SCTRIM Mask                     */
#define MCG_C3_SCTRIM_SHIFT                      0                                                   /*!< MCG_C3: SCTRIM Position                 */
#define MCG_C3_SCTRIM(x)                         (((x)<<MCG_C3_SCTRIM_SHIFT)&MCG_C3_SCTRIM_MASK)     /*!< MCG_C3                                  */

/* ------- MCG_C4                                   ------ */
#define MCG_C4_SCFTRIM_MASK                      (0x01UL << MCG_C4_SCFTRIM_SHIFT)                    /*!< MCG_C4: SCFTRIM Mask                    */
#define MCG_C4_SCFTRIM_SHIFT                     0                                                   /*!< MCG_C4: SCFTRIM Position                */
#define MCG_C4_FCTRIM_MASK                       (0x0FUL << MCG_C4_FCTRIM_SHIFT)                     /*!< MCG_C4: FCTRIM Mask                     */
#define MCG_C4_FCTRIM_SHIFT                      1                                                   /*!< MCG_C4: FCTRIM Position                 */
#define MCG_C4_FCTRIM(x)                         (((x)<<MCG_C4_FCTRIM_SHIFT)&MCG_C4_FCTRIM_MASK)     /*!< MCG_C4                                  */
#define MCG_C4_DRST_DRS_MASK                     (0x03UL << MCG_C4_DRST_DRS_SHIFT)                   /*!< MCG_C4: DRST_DRS Mask                   */
#define MCG_C4_DRST_DRS_SHIFT                    5                                                   /*!< MCG_C4: DRST_DRS Position               */
#define MCG_C4_DRST_DRS(x)                       (((x)<<MCG_C4_DRST_DRS_SHIFT)&MCG_C4_DRST_DRS_MASK) /*!< MCG_C4                                  */
#define MCG_C4_DMX32_MASK                        (0x01UL << MCG_C4_DMX32_SHIFT)                      /*!< MCG_C4: DMX32 Mask                      */
#define MCG_C4_DMX32_SHIFT                       7                                                   /*!< MCG_C4: DMX32 Position                  */

/* ------- MCG_C5                                   ------ */
#define MCG_C5_PLLSTEN0_MASK                     (0x01UL << MCG_C5_PLLSTEN0_SHIFT)                   /*!< MCG_C5: PLLSTEN0 Mask                   */
#define MCG_C5_PLLSTEN0_SHIFT                    5                                                   /*!< MCG_C5: PLLSTEN0 Position               */
#define MCG_C5_PLLCLKEN0_MASK                    (0x01UL << MCG_C5_PLLCLKEN0_SHIFT)                  /*!< MCG_C5: PLLCLKEN0 Mask                  */
#define MCG_C5_PLLCLKEN0_SHIFT                   6                                                   /*!< MCG_C5: PLLCLKEN0 Position              */

/* ------- MCG_C6                                   ------ */
#define MCG_C6_CME0_MASK                         (0x01UL << MCG_C6_CME0_SHIFT)                       /*!< MCG_C6: CME0 Mask                       */
#define MCG_C6_CME0_SHIFT                        5                                                   /*!< MCG_C6: CME0 Position                   */
#define MCG_C6_PLLS_MASK                         (0x01UL << MCG_C6_PLLS_SHIFT)                       /*!< MCG_C6: PLLS Mask                       */
#define MCG_C6_PLLS_SHIFT                        6                                                   /*!< MCG_C6: PLLS Position                   */
#define MCG_C6_LOLIE0_MASK                       (0x01UL << MCG_C6_LOLIE0_SHIFT)                     /*!< MCG_C6: LOLIE0 Mask                     */
#define MCG_C6_LOLIE0_SHIFT                      7                                                   /*!< MCG_C6: LOLIE0 Position                 */

/* ------- MCG_S                                    ------ */
#define MCG_S_IRCST_MASK                         (0x01UL << MCG_S_IRCST_SHIFT)                       /*!< MCG_S: IRCST Mask                       */
#define MCG_S_IRCST_SHIFT                        0                                                   /*!< MCG_S: IRCST Position                   */
#define MCG_S_OSCINIT0_MASK                      (0x01UL << MCG_S_OSCINIT0_SHIFT)                    /*!< MCG_S: OSCINIT0 Mask                    */
#define MCG_S_OSCINIT0_SHIFT                     1                                                   /*!< MCG_S: OSCINIT0 Position                */
#define MCG_S_CLKST_MASK                         (0x03UL << MCG_S_CLKST_SHIFT)                       /*!< MCG_S: CLKST Mask                       */
#define MCG_S_CLKST_SHIFT                        2                                                   /*!< MCG_S: CLKST Position                   */
#define MCG_S_CLKST(x)                           (((x)<<MCG_S_CLKST_SHIFT)&MCG_S_CLKST_MASK)         /*!< MCG_S                                   */
#define MCG_S_IREFST_MASK                        (0x01UL << MCG_S_IREFST_SHIFT)                      /*!< MCG_S: IREFST Mask                      */
#define MCG_S_IREFST_SHIFT                       4                                                   /*!< MCG_S: IREFST Position                  */
#define MCG_S_PLLST_MASK                         (0x01UL << MCG_S_PLLST_SHIFT)                       /*!< MCG_S: PLLST Mask                       */
#define MCG_S_PLLST_SHIFT                        5                                                   /*!< MCG_S: PLLST Position                   */
#define MCG_S_LOCK0_MASK                         (0x01UL << MCG_S_LOCK0_SHIFT)                       /*!< MCG_S: LOCK0 Mask                       */
#define MCG_S_LOCK0_SHIFT                        6                                                   /*!< MCG_S: LOCK0 Position                   */
#define MCG_S_LOLS0_MASK                         (0x01UL << MCG_S_LOLS0_SHIFT)                       /*!< MCG_S: LOLS0 Mask                       */
#define MCG_S_LOLS0_SHIFT                        7                                                   /*!< MCG_S: LOLS0 Position                   */

/* ------- MCG_SC                                   ------ */
#define MCG_SC_LOCS0_MASK                        (0x01UL << MCG_SC_LOCS0_SHIFT)                      /*!< MCG_SC: LOCS0 Mask                      */
#define MCG_SC_LOCS0_SHIFT                       0                                                   /*!< MCG_SC: LOCS0 Position                  */
#define MCG_SC_FCRDIV_MASK                       (0x07UL << MCG_SC_FCRDIV_SHIFT)                     /*!< MCG_SC: FCRDIV Mask                     */
#define MCG_SC_FCRDIV_SHIFT                      1                                                   /*!< MCG_SC: FCRDIV Position                 */
#define MCG_SC_FCRDIV(x)                         (((x)<<MCG_SC_FCRDIV_SHIFT)&MCG_SC_FCRDIV_MASK)     /*!< MCG_SC                                  */
#define MCG_SC_FLTPRSRV_MASK                     (0x01UL << MCG_SC_FLTPRSRV_SHIFT)                   /*!< MCG_SC: FLTPRSRV Mask                   */
#define MCG_SC_FLTPRSRV_SHIFT                    4                                                   /*!< MCG_SC: FLTPRSRV Position               */
#define MCG_SC_ATMF_MASK                         (0x01UL << MCG_SC_ATMF_SHIFT)                       /*!< MCG_SC: ATMF Mask                       */
#define MCG_SC_ATMF_SHIFT                        5                                                   /*!< MCG_SC: ATMF Position                   */
#define MCG_SC_ATMS_MASK                         (0x01UL << MCG_SC_ATMS_SHIFT)                       /*!< MCG_SC: ATMS Mask                       */
#define MCG_SC_ATMS_SHIFT                        6                                                   /*!< MCG_SC: ATMS Position                   */
#define MCG_SC_ATME_MASK                         (0x01UL << MCG_SC_ATME_SHIFT)                       /*!< MCG_SC: ATME Mask                       */
#define MCG_SC_ATME_SHIFT                        7                                                   /*!< MCG_SC: ATME Position                   */

/* ------- MCG_ATCVH                                ------ */
#define MCG_ATCVH_ATCVH_MASK                     (0xFFUL << MCG_ATCVH_ATCVH_SHIFT)                   /*!< MCG_ATCVH: ATCVH Mask                   */
#define MCG_ATCVH_ATCVH_SHIFT                    0                                                   /*!< MCG_ATCVH: ATCVH Position               */
#define MCG_ATCVH_ATCVH(x)                       (((x)<<MCG_ATCVH_ATCVH_SHIFT)&MCG_ATCVH_ATCVH_MASK) /*!< MCG_ATCVH                               */

/* ------- MCG_ATCVL                                ------ */
#define MCG_ATCVL_ATCVL_MASK                     (0xFFUL << MCG_ATCVL_ATCVL_SHIFT)                   /*!< MCG_ATCVL: ATCVL Mask                   */
#define MCG_ATCVL_ATCVL_SHIFT                    0                                                   /*!< MCG_ATCVL: ATCVL Position               */
#define MCG_ATCVL_ATCVL(x)                       (((x)<<MCG_ATCVL_ATCVL_SHIFT)&MCG_ATCVL_ATCVL_MASK) /*!< MCG_ATCVL                               */

/* ------- MCG_C7                                   ------ */
#define MCG_C7_OSCSEL_MASK                       (0x01UL << MCG_C7_OSCSEL_SHIFT)                     /*!< MCG_C7: OSCSEL Mask                     */
#define MCG_C7_OSCSEL_SHIFT                      0                                                   /*!< MCG_C7: OSCSEL Position                 */
#define MCG_C7_PLL32KREFSEL_MASK                 (0x03UL << MCG_C7_PLL32KREFSEL_SHIFT)               /*!< MCG_C7: PLL32KREFSEL Mask               */
#define MCG_C7_PLL32KREFSEL_SHIFT                6                                                   /*!< MCG_C7: PLL32KREFSEL Position           */
#define MCG_C7_PLL32KREFSEL(x)                   (((x)<<MCG_C7_PLL32KREFSEL_SHIFT)&MCG_C7_PLL32KREFSEL_MASK) /*!< MCG_C7                                  */

/* ------- MCG_C8                                   ------ */
#define MCG_C8_LOCS1_MASK                        (0x01UL << MCG_C8_LOCS1_SHIFT)                      /*!< MCG_C8: LOCS1 Mask                      */
#define MCG_C8_LOCS1_SHIFT                       0                                                   /*!< MCG_C8: LOCS1 Position                  */
#define MCG_C8_COARSE_LOLIE_MASK                 (0x01UL << MCG_C8_COARSE_LOLIE_SHIFT)               /*!< MCG_C8: COARSE_LOLIE Mask               */
#define MCG_C8_COARSE_LOLIE_SHIFT                4                                                   /*!< MCG_C8: COARSE_LOLIE Position           */
#define MCG_C8_CME1_MASK                         (0x01UL << MCG_C8_CME1_SHIFT)                       /*!< MCG_C8: CME1 Mask                       */
#define MCG_C8_CME1_SHIFT                        5                                                   /*!< MCG_C8: CME1 Position                   */
#define MCG_C8_LOLRE_MASK                        (0x01UL << MCG_C8_LOLRE_SHIFT)                      /*!< MCG_C8: LOLRE Mask                      */
#define MCG_C8_LOLRE_SHIFT                       6                                                   /*!< MCG_C8: LOLRE Position                  */
#define MCG_C8_LOCRE1_MASK                       (0x01UL << MCG_C8_LOCRE1_SHIFT)                     /*!< MCG_C8: LOCRE1 Mask                     */
#define MCG_C8_LOCRE1_SHIFT                      7                                                   /*!< MCG_C8: LOCRE1 Position                 */

/* ------- MCG_C9                                   ------ */
#define MCG_C9_COARSE_LOCK_MASK                  (0x01UL << MCG_C9_COARSE_LOCK_SHIFT)                /*!< MCG_C9: COARSE_LOCK Mask                */
#define MCG_C9_COARSE_LOCK_SHIFT                 6                                                   /*!< MCG_C9: COARSE_LOCK Position            */
#define MCG_C9_COARSE_LOLS_MASK                  (0x01UL << MCG_C9_COARSE_LOLS_SHIFT)                /*!< MCG_C9: COARSE_LOLS Mask                */
#define MCG_C9_COARSE_LOLS_SHIFT                 7                                                   /*!< MCG_C9: COARSE_LOLS Position            */

/* -------------------------------------------------------------------------------- */
/* -----------     'MCG' Register Access macros                         ----------- */
/* -------------------------------------------------------------------------------- */

#define MCG_C1                         (MCG->C1)
#define MCG_C2                         (MCG->C2)
#define MCG_C3                         (MCG->C3)
#define MCG_C4                         (MCG->C4)
#define MCG_C5                         (MCG->C5)
#define MCG_C6                         (MCG->C6)
#define MCG_S                          (MCG->S)
#define MCG_SC                         (MCG->SC)
#define MCG_ATCVH                      (MCG->ATCVH)
#define MCG_ATCVL                      (MCG->ATCVL)
#define MCG_C7                         (MCG->C7)
#define MCG_C8                         (MCG->C8)
#define MCG_C9                         (MCG->C9)

/* ================================================================================ */
/* ================           MCM (file:MCM_MKM)                   ================ */
/* ================================================================================ */

/**
 * @brief Core Platform Miscellaneous Control Module
 */
typedef struct {                                /*!<       MCM Structure                                                */
   __I  uint32_t  RESERVED0[2];                 /*!< 0000:                                                              */
   __I  uint16_t  PLASC;                        /*!< 0008: Crossbar Switch (AXBS) Slave Configuration                   */
   __I  uint16_t  PLAMC;                        /*!< 000A: Crossbar Switch (AXBS) Master Configuration                  */
   __IO uint32_t  PLACR;                        /*!< 000C: Platform Control Register                                    */
   __I  uint32_t  RESERVED1[8];                 /*!< 0010:                                                              */
   __IO uint32_t  PID;                          /*!< 0030: Process ID register                                          */
   __I  uint32_t  RESERVED2[3];                 /*!< 0034:                                                              */
   __IO uint32_t  CPO;                          /*!< 0040: Compute Operation Control Register                           */
   __I  uint32_t  RESERVED3[15];                /*!< 0044:                                                              */
   __IO uint32_t  MATCRn;                       /*!< 0080: Master Attribute Configuration Register                      */
} MCM_Type;


/* -------------------------------------------------------------------------------- */
/* -----------     'MCM' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */


/* ------- MCM_PLASC                                ------ */
#define MCM_PLASC_ASC_MASK                       (0xFFUL << MCM_PLASC_ASC_SHIFT)                     /*!< MCM_PLASC: ASC Mask                     */
#define MCM_PLASC_ASC_SHIFT                      0                                                   /*!< MCM_PLASC: ASC Position                 */
#define MCM_PLASC_ASC(x)                         (((x)<<MCM_PLASC_ASC_SHIFT)&MCM_PLASC_ASC_MASK)     /*!< MCM_PLASC                               */

/* ------- MCM_PLAMC                                ------ */
#define MCM_PLAMC_AMC_MASK                       (0xFFUL << MCM_PLAMC_AMC_SHIFT)                     /*!< MCM_PLAMC: AMC Mask                     */
#define MCM_PLAMC_AMC_SHIFT                      0                                                   /*!< MCM_PLAMC: AMC Position                 */
#define MCM_PLAMC_AMC(x)                         (((x)<<MCM_PLAMC_AMC_SHIFT)&MCM_PLAMC_AMC_MASK)     /*!< MCM_PLAMC                               */

/* ------- MCM_PLACR                                ------ */
#define MCM_PLACR_ARB_MASK                       (0x01UL << MCM_PLACR_ARB_SHIFT)                     /*!< MCM_PLACR: ARB Mask                     */
#define MCM_PLACR_ARB_SHIFT                      9                                                   /*!< MCM_PLACR: ARB Position                 */
#define MCM_PLACR_CFCC_MASK                      (0x01UL << MCM_PLACR_CFCC_SHIFT)                    /*!< MCM_PLACR: CFCC Mask                    */
#define MCM_PLACR_CFCC_SHIFT                     10                                                  /*!< MCM_PLACR: CFCC Position                */
#define MCM_PLACR_DFCDA_MASK                     (0x01UL << MCM_PLACR_DFCDA_SHIFT)                   /*!< MCM_PLACR: DFCDA Mask                   */
#define MCM_PLACR_DFCDA_SHIFT                    11                                                  /*!< MCM_PLACR: DFCDA Position               */
#define MCM_PLACR_DFCIC_MASK                     (0x01UL << MCM_PLACR_DFCIC_SHIFT)                   /*!< MCM_PLACR: DFCIC Mask                   */
#define MCM_PLACR_DFCIC_SHIFT                    12                                                  /*!< MCM_PLACR: DFCIC Position               */
#define MCM_PLACR_DFCC_MASK                      (0x01UL << MCM_PLACR_DFCC_SHIFT)                    /*!< MCM_PLACR: DFCC Mask                    */
#define MCM_PLACR_DFCC_SHIFT                     13                                                  /*!< MCM_PLACR: DFCC Position                */
#define MCM_PLACR_EFDS_MASK                      (0x01UL << MCM_PLACR_EFDS_SHIFT)                    /*!< MCM_PLACR: EFDS Mask                    */
#define MCM_PLACR_EFDS_SHIFT                     14                                                  /*!< MCM_PLACR: EFDS Position                */
#define MCM_PLACR_DFCS_MASK                      (0x01UL << MCM_PLACR_DFCS_SHIFT)                    /*!< MCM_PLACR: DFCS Mask                    */
#define MCM_PLACR_DFCS_SHIFT                     15                                                  /*!< MCM_PLACR: DFCS Position                */

/* ------- MCM_PID                                  ------ */
#define MCM_PID_M0_PID_MASK                      (0xFFUL << MCM_PID_M0_PID_SHIFT)                    /*!< MCM_PID: M0_PID Mask                    */
#define MCM_PID_M0_PID_SHIFT                     0                                                   /*!< MCM_PID: M0_PID Position                */
#define MCM_PID_M0_PID(x)                        (((x)<<MCM_PID_M0_PID_SHIFT)&MCM_PID_M0_PID_MASK)   /*!< MCM_PID                                 */

/* ------- MCM_CPO                                  ------ */
#define MCM_CPO_CPOREQ_MASK                      (0x01UL << MCM_CPO_CPOREQ_SHIFT)                    /*!< MCM_CPO: CPOREQ Mask                    */
#define MCM_CPO_CPOREQ_SHIFT                     0                                                   /*!< MCM_CPO: CPOREQ Position                */
#define MCM_CPO_CPOACK_MASK                      (0x01UL << MCM_CPO_CPOACK_SHIFT)                    /*!< MCM_CPO: CPOACK Mask                    */
#define MCM_CPO_CPOACK_SHIFT                     1                                                   /*!< MCM_CPO: CPOACK Position                */
#define MCM_CPO_CPOWOI_MASK                      (0x01UL << MCM_CPO_CPOWOI_SHIFT)                    /*!< MCM_CPO: CPOWOI Mask                    */
#define MCM_CPO_CPOWOI_SHIFT                     2                                                   /*!< MCM_CPO: CPOWOI Position                */

/* ------- MCM_MATCRn                               ------ */
#define MCM_MATCRn_ATC0_MASK                     (0x07UL << MCM_MATCRn_ATC0_SHIFT)                   /*!< MCM_MATCRn: ATC0 Mask                   */
#define MCM_MATCRn_ATC0_SHIFT                    0                                                   /*!< MCM_MATCRn: ATC0 Position               */
#define MCM_MATCRn_ATC0(x)                       (((x)<<MCM_MATCRn_ATC0_SHIFT)&MCM_MATCRn_ATC0_MASK) /*!< MCM_MATCRn                              */
#define MCM_MATCRn_RO0_MASK                      (0x01UL << MCM_MATCRn_RO0_SHIFT)                    /*!< MCM_MATCRn: RO0 Mask                    */
#define MCM_MATCRn_RO0_SHIFT                     7                                                   /*!< MCM_MATCRn: RO0 Position                */
#define MCM_MATCRn_ATC2_MASK                     (0x07UL << MCM_MATCRn_ATC2_SHIFT)                   /*!< MCM_MATCRn: ATC2 Mask                   */
#define MCM_MATCRn_ATC2_SHIFT                    16                                                  /*!< MCM_MATCRn: ATC2 Position               */
#define MCM_MATCRn_ATC2(x)                       (((x)<<MCM_MATCRn_ATC2_SHIFT)&MCM_MATCRn_ATC2_MASK) /*!< MCM_MATCRn                              */
#define MCM_MATCRn_RO2_MASK                      (0x01UL << MCM_MATCRn_RO2_SHIFT)                    /*!< MCM_MATCRn: RO2 Mask                    */
#define MCM_MATCRn_RO2_SHIFT                     23                                                  /*!< MCM_MATCRn: RO2 Position                */

/* -------------------------------------------------------------------------------- */
/* -----------     'MCM' Register Access macros                         ----------- */
/* -------------------------------------------------------------------------------- */

#define MCM_PLASC                      (MCM->PLASC)
#define MCM_PLAMC                      (MCM->PLAMC)
#define MCM_PLACR                      (MCM->PLACR)
#define MCM_PID                        (MCM->PID)
#define MCM_CPO                        (MCM->CPO)
#define MCM_MATCRn                     (MCM->MATCRn)

/* ================================================================================ */
/* ================           NV (file:NV_FTFA)                    ================ */
/* ================================================================================ */

/**
 * @brief Flash configuration field
 */
typedef struct {                                /*!<       NV Structure                                                 */
   __I  uint8_t   BACKKEY3;                     /*!< 0000: Backdoor Comparison Key 3                                    */
   __I  uint8_t   BACKKEY2;                     /*!< 0001: Backdoor Comparison Key 2                                    */
   __I  uint8_t   BACKKEY1;                     /*!< 0002: Backdoor Comparison Key 1                                    */
   __I  uint8_t   BACKKEY0;                     /*!< 0003: Backdoor Comparison Key 0                                    */
   __I  uint8_t   BACKKEY7;                     /*!< 0004: Backdoor Comparison Key 7                                    */
   __I  uint8_t   BACKKEY6;                     /*!< 0005: Backdoor Comparison Key 6                                    */
   __I  uint8_t   BACKKEY5;                     /*!< 0006: Backdoor Comparison Key 5                                    */
   __I  uint8_t   BACKKEY4;                     /*!< 0007: Backdoor Comparison Key 4                                    */
   __I  uint8_t   FPROT3;                       /*!< 0008: Non-volatile P-Flash Protection Register                     */
   __I  uint8_t   FPROT2;                       /*!< 0009: Non-volatile P-Flash Protection Register                     */
   __I  uint8_t   FPROT1;                       /*!< 000A: Non-volatile P-Flash Protection Register                     */
   __I  uint8_t   FPROT0;                       /*!< 000B: Non-volatile P-Flash Protection Register                     */
   __I  uint8_t   FSEC;                         /*!< 000C: Non-volatile Flash Security Register                         */
   __I  uint8_t   FOPT;                         /*!< 000D: Non-volatile Flash Option Register                           */
} NV_Type;


/* -------------------------------------------------------------------------------- */
/* -----------     'NV' Position & Mask macros                          ----------- */
/* -------------------------------------------------------------------------------- */


/* ------- NV_BACKKEY                               ------ */
#define NV_BACKKEY_KEY_MASK                      (0xFFUL << NV_BACKKEY_KEY_SHIFT)                    /*!< NV_BACKKEY: KEY Mask                    */
#define NV_BACKKEY_KEY_SHIFT                     0                                                   /*!< NV_BACKKEY: KEY Position                */
#define NV_BACKKEY_KEY(x)                        (((x)<<NV_BACKKEY_KEY_SHIFT)&NV_BACKKEY_KEY_MASK)   /*!< NV_BACKKEY                              */

/* ------- NV_FPROT                                 ------ */
#define NV_FPROT_PROT_MASK                       (0xFFUL << NV_FPROT_PROT_SHIFT)                     /*!< NV_FPROT: PROT Mask                     */
#define NV_FPROT_PROT_SHIFT                      0                                                   /*!< NV_FPROT: PROT Position                 */
#define NV_FPROT_PROT(x)                         (((x)<<NV_FPROT_PROT_SHIFT)&NV_FPROT_PROT_MASK)     /*!< NV_FPROT                                */

/* ------- NV_FSEC                                  ------ */
#define NV_FSEC_SEC_MASK                         (0x03UL << NV_FSEC_SEC_SHIFT)                       /*!< NV_FSEC: SEC Mask                       */
#define NV_FSEC_SEC_SHIFT                        0                                                   /*!< NV_FSEC: SEC Position                   */
#define NV_FSEC_SEC(x)                           (((x)<<NV_FSEC_SEC_SHIFT)&NV_FSEC_SEC_MASK)         /*!< NV_FSEC                                 */
#define NV_FSEC_FSLACC_MASK                      (0x03UL << NV_FSEC_FSLACC_SHIFT)                    /*!< NV_FSEC: FSLACC Mask                    */
#define NV_FSEC_FSLACC_SHIFT                     2                                                   /*!< NV_FSEC: FSLACC Position                */
#define NV_FSEC_FSLACC(x)                        (((x)<<NV_FSEC_FSLACC_SHIFT)&NV_FSEC_FSLACC_MASK)   /*!< NV_FSEC                                 */
#define NV_FSEC_MEEN_MASK                        (0x03UL << NV_FSEC_MEEN_SHIFT)                      /*!< NV_FSEC: MEEN Mask                      */
#define NV_FSEC_MEEN_SHIFT                       4                                                   /*!< NV_FSEC: MEEN Position                  */
#define NV_FSEC_MEEN(x)                          (((x)<<NV_FSEC_MEEN_SHIFT)&NV_FSEC_MEEN_MASK)       /*!< NV_FSEC                                 */
#define NV_FSEC_KEYEN_MASK                       (0x03UL << NV_FSEC_KEYEN_SHIFT)                     /*!< NV_FSEC: KEYEN Mask                     */
#define NV_FSEC_KEYEN_SHIFT                      6                                                   /*!< NV_FSEC: KEYEN Position                 */
#define NV_FSEC_KEYEN(x)                         (((x)<<NV_FSEC_KEYEN_SHIFT)&NV_FSEC_KEYEN_MASK)     /*!< NV_FSEC                                 */

/* ------- NV_FOPT                                  ------ */
#define NV_FOPT_LPBOOT_MASK                      (0x01UL << NV_FOPT_LPBOOT_SHIFT)                    /*!< NV_FOPT: LPBOOT Mask                    */
#define NV_FOPT_LPBOOT_SHIFT                     0                                                   /*!< NV_FOPT: LPBOOT Position                */
#define NV_FOPT_NMI_DIS_MASK                     (0x01UL << NV_FOPT_NMI_DIS_SHIFT)                   /*!< NV_FOPT: NMI_DIS Mask                   */
#define NV_FOPT_NMI_DIS_SHIFT                    2                                                   /*!< NV_FOPT: NMI_DIS Position               */
#define NV_FOPT_RESET_PIN_CFG_MASK               (0x01UL << NV_FOPT_RESET_PIN_CFG_SHIFT)             /*!< NV_FOPT: RESET_PIN_CFG Mask             */
#define NV_FOPT_RESET_PIN_CFG_SHIFT              3                                                   /*!< NV_FOPT: RESET_PIN_CFG Position         */
#define NV_FOPT_LPBOOT1_MASK                     (0x01UL << NV_FOPT_LPBOOT1_SHIFT)                   /*!< NV_FOPT: LPBOOT1 Mask                   */
#define NV_FOPT_LPBOOT1_SHIFT                    4                                                   /*!< NV_FOPT: LPBOOT1 Position               */
#define NV_FOPT_FAST_INIT_MASK                   (0x01UL << NV_FOPT_FAST_INIT_SHIFT)                 /*!< NV_FOPT: FAST_INIT Mask                 */
#define NV_FOPT_FAST_INIT_SHIFT                  5                                                   /*!< NV_FOPT: FAST_INIT Position             */

/* -------------------------------------------------------------------------------- */
/* -----------     'NV' Register Access macros                          ----------- */
/* -------------------------------------------------------------------------------- */

#define NV_BACKKEY3                    (NV->BACKKEY3)
#define NV_BACKKEY2                    (NV->BACKKEY2)
#define NV_BACKKEY1                    (NV->BACKKEY1)
#define NV_BACKKEY0                    (NV->BACKKEY0)
#define NV_BACKKEY7                    (NV->BACKKEY7)
#define NV_BACKKEY6                    (NV->BACKKEY6)
#define NV_BACKKEY5                    (NV->BACKKEY5)
#define NV_BACKKEY4                    (NV->BACKKEY4)
#define NV_FPROT3                      (NV->FPROT3)
#define NV_FPROT2                      (NV->FPROT2)
#define NV_FPROT1                      (NV->FPROT1)
#define NV_FPROT0                      (NV->FPROT0)
#define NV_FSEC                        (NV->FSEC)
#define NV_FOPT                        (NV->FOPT)

/* ================================================================================ */
/* ================           OSC0 (file:OSC_MKM)                  ================ */
/* ================================================================================ */

/**
 * @brief System Oscillator
 */
typedef struct {                                /*!<       OSC0 Structure                                               */
   __IO uint8_t   CR;                           /*!< 0000: Control Register                                             */
} OSC0_Type;


/* -------------------------------------------------------------------------------- */
/* -----------     'OSC0' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */


/* ------- OSC0_CR                                  ------ */
#define OSC_CR_SC16P_MASK                        (0x01UL << OSC_CR_SC16P_SHIFT)                      /*!< OSC0_CR: SC16P Mask                     */
#define OSC_CR_SC16P_SHIFT                       0                                                   /*!< OSC0_CR: SC16P Position                 */
#define OSC_CR_SC8P_MASK                         (0x01UL << OSC_CR_SC8P_SHIFT)                       /*!< OSC0_CR: SC8P Mask                      */
#define OSC_CR_SC8P_SHIFT                        1                                                   /*!< OSC0_CR: SC8P Position                  */
#define OSC_CR_SC4P_MASK                         (0x01UL << OSC_CR_SC4P_SHIFT)                       /*!< OSC0_CR: SC4P Mask                      */
#define OSC_CR_SC4P_SHIFT                        2                                                   /*!< OSC0_CR: SC4P Position                  */
#define OSC_CR_SC2P_MASK                         (0x01UL << OSC_CR_SC2P_SHIFT)                       /*!< OSC0_CR: SC2P Mask                      */
#define OSC_CR_SC2P_SHIFT                        3                                                   /*!< OSC0_CR: SC2P Position                  */
#define OSC_CR_EREFSTEN_MASK                     (0x01UL << OSC_CR_EREFSTEN_SHIFT)                   /*!< OSC0_CR: EREFSTEN Mask                  */
#define OSC_CR_EREFSTEN_SHIFT                    5                                                   /*!< OSC0_CR: EREFSTEN Position              */
#define OSC_CR_ERCLKEN_MASK                      (0x01UL << OSC_CR_ERCLKEN_SHIFT)                    /*!< OSC0_CR: ERCLKEN Mask                   */
#define OSC_CR_ERCLKEN_SHIFT                     7                                                   /*!< OSC0_CR: ERCLKEN Position               */

/* -------------------------------------------------------------------------------- */
/* -----------     'OSC0' Register Access macros                        ----------- */
/* -------------------------------------------------------------------------------- */

#define OSC0_CR                        (OSC0->CR)

/* ================================================================================ */
/* ================           PORTA (file:PORTA_MKM)               ================ */
/* ================================================================================ */

/**
 * @brief Pin Control and Interrupts
 */
typedef struct {                                /*!<       PORTA Structure                                              */
   __IO uint32_t  PCR[8];                       /*!< 0000: Pin Control Register                                         */
   __I  uint32_t  RESERVED0[24];                /*!< 0020:                                                              */
   __IO uint32_t  GPCLR;                        /*!< 0080: Global Pin Control Low Register                              */
   __IO uint32_t  GPCHR;                        /*!< 0084: Global Pin Control High Register                             */
   __I  uint32_t  RESERVED1[6];                 /*!< 0088:                                                              */
   __IO uint32_t  ISFR;                         /*!< 00A0: Interrupt Status Flag Register                               */
   __I  uint32_t  RESERVED2[7];                 /*!< 00A4:                                                              */
   __IO uint32_t  DFER;                         /*!< 00C0: Digital Filter Enable Register                               */
   __IO uint32_t  DFCR;                         /*!< 00C4: Digital Filter Clock Register                                */
   __IO uint32_t  DFWR;                         /*!< 00C8: Digital Filter Width Register                                */
} PORTA_Type;


/* -------------------------------------------------------------------------------- */
/* -----------     'PORTA' Position & Mask macros                       ----------- */
/* -------------------------------------------------------------------------------- */


/* ------- PORTA_PCR                                ------ */
#define PORT_PCR_PS_MASK                         (0x01UL << PORT_PCR_PS_SHIFT)                       /*!< PORTA_PCR: PS Mask                      */
#define PORT_PCR_PS_SHIFT                        0                                                   /*!< PORTA_PCR: PS Position                  */
#define PORT_PCR_PE_MASK                         (0x01UL << PORT_PCR_PE_SHIFT)                       /*!< PORTA_PCR: PE Mask                      */
#define PORT_PCR_PE_SHIFT                        1                                                   /*!< PORTA_PCR: PE Position                  */
#define PORT_PCR_SRE_MASK                        (0x01UL << PORT_PCR_SRE_SHIFT)                      /*!< PORTA_PCR: SRE Mask                     */
#define PORT_PCR_SRE_SHIFT                       2                                                   /*!< PORTA_PCR: SRE Position                 */
#define PORT_PCR_MUX_MASK                        (0x07UL << PORT_PCR_MUX_SHIFT)                      /*!< PORTA_PCR: MUX Mask                     */
#define PORT_PCR_MUX_SHIFT                       8                                                   /*!< PORTA_PCR: MUX Position                 */
#define PORT_PCR_MUX(x)                          (((x)<<PORT_PCR_MUX_SHIFT)&PORT_PCR_MUX_MASK)       /*!< PORTA_PCR                               */
#define PORT_PCR_LK_MASK                         (0x01UL << PORT_PCR_LK_SHIFT)                       /*!< PORTA_PCR: LK Mask                      */
#define PORT_PCR_LK_SHIFT                        15                                                  /*!< PORTA_PCR: LK Position                  */
#define PORT_PCR_IRQC_MASK                       (0x0FUL << PORT_PCR_IRQC_SHIFT)                     /*!< PORTA_PCR: IRQC Mask                    */
#define PORT_PCR_IRQC_SHIFT                      16                                                  /*!< PORTA_PCR: IRQC Position                */
#define PORT_PCR_IRQC(x)                         (((x)<<PORT_PCR_IRQC_SHIFT)&PORT_PCR_IRQC_MASK)     /*!< PORTA_PCR                               */
#define PORT_PCR_ISF_MASK                        (0x01UL << PORT_PCR_ISF_SHIFT)                      /*!< PORTA_PCR: ISF Mask                     */
#define PORT_PCR_ISF_SHIFT                       24                                                  /*!< PORTA_PCR: ISF Position                 */

/* ------- PORTA_GPCLR                              ------ */
#define PORT_GPCLR_GPWD_MASK                     (0xFFFFUL << PORT_GPCLR_GPWD_SHIFT)                 /*!< PORTA_GPCLR: GPWD Mask                  */
#define PORT_GPCLR_GPWD_SHIFT                    0                                                   /*!< PORTA_GPCLR: GPWD Position              */
#define PORT_GPCLR_GPWD(x)                       (((x)<<PORT_GPCLR_GPWD_SHIFT)&PORT_GPCLR_GPWD_MASK) /*!< PORTA_GPCLR                             */
#define PORT_GPCLR_GPWE_MASK                     (0xFFFFUL << PORT_GPCLR_GPWE_SHIFT)                 /*!< PORTA_GPCLR: GPWE Mask                  */
#define PORT_GPCLR_GPWE_SHIFT                    16                                                  /*!< PORTA_GPCLR: GPWE Position              */
#define PORT_GPCLR_GPWE(x)                       (((x)<<PORT_GPCLR_GPWE_SHIFT)&PORT_GPCLR_GPWE_MASK) /*!< PORTA_GPCLR                             */

/* ------- PORTA_GPCHR                              ------ */
#define PORT_GPCHR_GPWD_MASK                     (0xFFFFUL << PORT_GPCHR_GPWD_SHIFT)                 /*!< PORTA_GPCHR: GPWD Mask                  */
#define PORT_GPCHR_GPWD_SHIFT                    0                                                   /*!< PORTA_GPCHR: GPWD Position              */
#define PORT_GPCHR_GPWD(x)                       (((x)<<PORT_GPCHR_GPWD_SHIFT)&PORT_GPCHR_GPWD_MASK) /*!< PORTA_GPCHR                             */
#define PORT_GPCHR_GPWE_MASK                     (0xFFFFUL << PORT_GPCHR_GPWE_SHIFT)                 /*!< PORTA_GPCHR: GPWE Mask                  */
#define PORT_GPCHR_GPWE_SHIFT                    16                                                  /*!< PORTA_GPCHR: GPWE Position              */
#define PORT_GPCHR_GPWE(x)                       (((x)<<PORT_GPCHR_GPWE_SHIFT)&PORT_GPCHR_GPWE_MASK) /*!< PORTA_GPCHR                             */

/* ------- PORTA_ISFR                               ------ */
#define PORT_ISFR_ISF0_MASK                      (0x01UL << PORT_ISFR_ISF0_SHIFT)                    /*!< PORTA_ISFR: ISF0 Mask                   */
#define PORT_ISFR_ISF0_SHIFT                     0                                                   /*!< PORTA_ISFR: ISF0 Position               */
#define PORT_ISFR_ISF1_MASK                      (0x01UL << PORT_ISFR_ISF1_SHIFT)                    /*!< PORTA_ISFR: ISF1 Mask                   */
#define PORT_ISFR_ISF1_SHIFT                     1                                                   /*!< PORTA_ISFR: ISF1 Position               */
#define PORT_ISFR_ISF2_MASK                      (0x01UL << PORT_ISFR_ISF2_SHIFT)                    /*!< PORTA_ISFR: ISF2 Mask                   */
#define PORT_ISFR_ISF2_SHIFT                     2                                                   /*!< PORTA_ISFR: ISF2 Position               */
#define PORT_ISFR_ISF3_MASK                      (0x01UL << PORT_ISFR_ISF3_SHIFT)                    /*!< PORTA_ISFR: ISF3 Mask                   */
#define PORT_ISFR_ISF3_SHIFT                     3                                                   /*!< PORTA_ISFR: ISF3 Position               */
#define PORT_ISFR_ISF4_MASK                      (0x01UL << PORT_ISFR_ISF4_SHIFT)                    /*!< PORTA_ISFR: ISF4 Mask                   */
#define PORT_ISFR_ISF4_SHIFT                     4                                                   /*!< PORTA_ISFR: ISF4 Position               */
#define PORT_ISFR_ISF5_MASK                      (0x01UL << PORT_ISFR_ISF5_SHIFT)                    /*!< PORTA_ISFR: ISF5 Mask                   */
#define PORT_ISFR_ISF5_SHIFT                     5                                                   /*!< PORTA_ISFR: ISF5 Position               */
#define PORT_ISFR_ISF6_MASK                      (0x01UL << PORT_ISFR_ISF6_SHIFT)                    /*!< PORTA_ISFR: ISF6 Mask                   */
#define PORT_ISFR_ISF6_SHIFT                     6                                                   /*!< PORTA_ISFR: ISF6 Position               */
#define PORT_ISFR_ISF7_MASK                      (0x01UL << PORT_ISFR_ISF7_SHIFT)                    /*!< PORTA_ISFR: ISF7 Mask                   */
#define PORT_ISFR_ISF7_SHIFT                     7                                                   /*!< PORTA_ISFR: ISF7 Position               */
#define PORT_ISFR_ISF8_MASK                      (0x01UL << PORT_ISFR_ISF8_SHIFT)                    /*!< PORTA_ISFR: ISF8 Mask                   */
#define PORT_ISFR_ISF8_SHIFT                     8                                                   /*!< PORTA_ISFR: ISF8 Position               */
#define PORT_ISFR_ISF9_MASK                      (0x01UL << PORT_ISFR_ISF9_SHIFT)                    /*!< PORTA_ISFR: ISF9 Mask                   */
#define PORT_ISFR_ISF9_SHIFT                     9                                                   /*!< PORTA_ISFR: ISF9 Position               */
#define PORT_ISFR_ISF10_MASK                     (0x01UL << PORT_ISFR_ISF10_SHIFT)                   /*!< PORTA_ISFR: ISF10 Mask                  */
#define PORT_ISFR_ISF10_SHIFT                    10                                                  /*!< PORTA_ISFR: ISF10 Position              */
#define PORT_ISFR_ISF11_MASK                     (0x01UL << PORT_ISFR_ISF11_SHIFT)                   /*!< PORTA_ISFR: ISF11 Mask                  */
#define PORT_ISFR_ISF11_SHIFT                    11                                                  /*!< PORTA_ISFR: ISF11 Position              */
#define PORT_ISFR_ISF12_MASK                     (0x01UL << PORT_ISFR_ISF12_SHIFT)                   /*!< PORTA_ISFR: ISF12 Mask                  */
#define PORT_ISFR_ISF12_SHIFT                    12                                                  /*!< PORTA_ISFR: ISF12 Position              */
#define PORT_ISFR_ISF13_MASK                     (0x01UL << PORT_ISFR_ISF13_SHIFT)                   /*!< PORTA_ISFR: ISF13 Mask                  */
#define PORT_ISFR_ISF13_SHIFT                    13                                                  /*!< PORTA_ISFR: ISF13 Position              */
#define PORT_ISFR_ISF14_MASK                     (0x01UL << PORT_ISFR_ISF14_SHIFT)                   /*!< PORTA_ISFR: ISF14 Mask                  */
#define PORT_ISFR_ISF14_SHIFT                    14                                                  /*!< PORTA_ISFR: ISF14 Position              */
#define PORT_ISFR_ISF15_MASK                     (0x01UL << PORT_ISFR_ISF15_SHIFT)                   /*!< PORTA_ISFR: ISF15 Mask                  */
#define PORT_ISFR_ISF15_SHIFT                    15                                                  /*!< PORTA_ISFR: ISF15 Position              */
#define PORT_ISFR_ISF16_MASK                     (0x01UL << PORT_ISFR_ISF16_SHIFT)                   /*!< PORTA_ISFR: ISF16 Mask                  */
#define PORT_ISFR_ISF16_SHIFT                    16                                                  /*!< PORTA_ISFR: ISF16 Position              */
#define PORT_ISFR_ISF17_MASK                     (0x01UL << PORT_ISFR_ISF17_SHIFT)                   /*!< PORTA_ISFR: ISF17 Mask                  */
#define PORT_ISFR_ISF17_SHIFT                    17                                                  /*!< PORTA_ISFR: ISF17 Position              */
#define PORT_ISFR_ISF18_MASK                     (0x01UL << PORT_ISFR_ISF18_SHIFT)                   /*!< PORTA_ISFR: ISF18 Mask                  */
#define PORT_ISFR_ISF18_SHIFT                    18                                                  /*!< PORTA_ISFR: ISF18 Position              */
#define PORT_ISFR_ISF19_MASK                     (0x01UL << PORT_ISFR_ISF19_SHIFT)                   /*!< PORTA_ISFR: ISF19 Mask                  */
#define PORT_ISFR_ISF19_SHIFT                    19                                                  /*!< PORTA_ISFR: ISF19 Position              */
#define PORT_ISFR_ISF20_MASK                     (0x01UL << PORT_ISFR_ISF20_SHIFT)                   /*!< PORTA_ISFR: ISF20 Mask                  */
#define PORT_ISFR_ISF20_SHIFT                    20                                                  /*!< PORTA_ISFR: ISF20 Position              */
#define PORT_ISFR_ISF21_MASK                     (0x01UL << PORT_ISFR_ISF21_SHIFT)                   /*!< PORTA_ISFR: ISF21 Mask                  */
#define PORT_ISFR_ISF21_SHIFT                    21                                                  /*!< PORTA_ISFR: ISF21 Position              */
#define PORT_ISFR_ISF22_MASK                     (0x01UL << PORT_ISFR_ISF22_SHIFT)                   /*!< PORTA_ISFR: ISF22 Mask                  */
#define PORT_ISFR_ISF22_SHIFT                    22                                                  /*!< PORTA_ISFR: ISF22 Position              */
#define PORT_ISFR_ISF23_MASK                     (0x01UL << PORT_ISFR_ISF23_SHIFT)                   /*!< PORTA_ISFR: ISF23 Mask                  */
#define PORT_ISFR_ISF23_SHIFT                    23                                                  /*!< PORTA_ISFR: ISF23 Position              */
#define PORT_ISFR_ISF24_MASK                     (0x01UL << PORT_ISFR_ISF24_SHIFT)                   /*!< PORTA_ISFR: ISF24 Mask                  */
#define PORT_ISFR_ISF24_SHIFT                    24                                                  /*!< PORTA_ISFR: ISF24 Position              */
#define PORT_ISFR_ISF25_MASK                     (0x01UL << PORT_ISFR_ISF25_SHIFT)                   /*!< PORTA_ISFR: ISF25 Mask                  */
#define PORT_ISFR_ISF25_SHIFT                    25                                                  /*!< PORTA_ISFR: ISF25 Position              */
#define PORT_ISFR_ISF26_MASK                     (0x01UL << PORT_ISFR_ISF26_SHIFT)                   /*!< PORTA_ISFR: ISF26 Mask                  */
#define PORT_ISFR_ISF26_SHIFT                    26                                                  /*!< PORTA_ISFR: ISF26 Position              */
#define PORT_ISFR_ISF27_MASK                     (0x01UL << PORT_ISFR_ISF27_SHIFT)                   /*!< PORTA_ISFR: ISF27 Mask                  */
#define PORT_ISFR_ISF27_SHIFT                    27                                                  /*!< PORTA_ISFR: ISF27 Position              */
#define PORT_ISFR_ISF28_MASK                     (0x01UL << PORT_ISFR_ISF28_SHIFT)                   /*!< PORTA_ISFR: ISF28 Mask                  */
#define PORT_ISFR_ISF28_SHIFT                    28                                                  /*!< PORTA_ISFR: ISF28 Position              */
#define PORT_ISFR_ISF29_MASK                     (0x01UL << PORT_ISFR_ISF29_SHIFT)                   /*!< PORTA_ISFR: ISF29 Mask                  */
#define PORT_ISFR_ISF29_SHIFT                    29                                                  /*!< PORTA_ISFR: ISF29 Position              */
#define PORT_ISFR_ISF30_MASK                     (0x01UL << PORT_ISFR_ISF30_SHIFT)                   /*!< PORTA_ISFR: ISF30 Mask                  */
#define PORT_ISFR_ISF30_SHIFT                    30                                                  /*!< PORTA_ISFR: ISF30 Position              */
#define PORT_ISFR_ISF31_MASK                     (0x01UL << PORT_ISFR_ISF31_SHIFT)                   /*!< PORTA_ISFR: ISF31 Mask                  */
#define PORT_ISFR_ISF31_SHIFT                    31                                                  /*!< PORTA_ISFR: ISF31 Position              */

/* ------- PORTA_DFER                               ------ */
#define PORT_DFER_DFE_MASK                       (0xFFFFFFFFUL << PORT_DFER_DFE_SHIFT)               /*!< PORTA_DFER: DFE Mask                    */
#define PORT_DFER_DFE_SHIFT                      0                                                   /*!< PORTA_DFER: DFE Position                */
#define PORT_DFER_DFE(x)                         (((x)<<PORT_DFER_DFE_SHIFT)&PORT_DFER_DFE_MASK)     /*!< PORTA_DFER                              */

/* ------- PORTA_DFCR                               ------ */
#define PORT_DFCR_CS_MASK                        (0x01UL << PORT_DFCR_CS_SHIFT)                      /*!< PORTA_DFCR: CS Mask                     */
#define PORT_DFCR_CS_SHIFT                       0                                                   /*!< PORTA_DFCR: CS Position                 */

/* ------- PORTA_DFWR                               ------ */
#define PORT_DFWR_CS_MASK                        (0x1FUL << PORT_DFWR_CS_SHIFT)                      /*!< PORTA_DFWR: CS Mask                     */
#define PORT_DFWR_CS_SHIFT                       0                                                   /*!< PORTA_DFWR: CS Position                 */
#define PORT_DFWR_CS(x)                          (((x)<<PORT_DFWR_CS_SHIFT)&PORT_DFWR_CS_MASK)       /*!< PORTA_DFWR                              */

/* -------------------------------------------------------------------------------- */
/* -----------     'PORTA' Register Access macros                       ----------- */
/* -------------------------------------------------------------------------------- */

#define PORTA_PCR0                     (PORTA->PCR[0])
#define PORTA_PCR1                     (PORTA->PCR[1])
#define PORTA_PCR2                     (PORTA->PCR[2])
#define PORTA_PCR3                     (PORTA->PCR[3])
#define PORTA_PCR4                     (PORTA->PCR[4])
#define PORTA_PCR5                     (PORTA->PCR[5])
#define PORTA_PCR6                     (PORTA->PCR[6])
#define PORTA_PCR7                     (PORTA->PCR[7])
#define PORTA_GPCLR                    (PORTA->GPCLR)
#define PORTA_GPCHR                    (PORTA->GPCHR)
#define PORTA_ISFR                     (PORTA->ISFR)
#define PORTA_DFER                     (PORTA->DFER)
#define PORTA_DFCR                     (PORTA->DFCR)
#define PORTA_DFWR                     (PORTA->DFWR)

/* ================================================================================ */
/* ================           PORTB (derived from PORTA)           ================ */
/* ================================================================================ */

/**
 * @brief Pin Control and Interrupts
 */
typedef PORTA_Type PORTB_Type;  /*!< PORTB Structure                                             */


/* -------------------------------------------------------------------------------- */
/* -----------     'PORTB' Register Access macros                       ----------- */
/* -------------------------------------------------------------------------------- */

#define PORTB_PCR0                     (PORTB->PCR[0])
#define PORTB_PCR1                     (PORTB->PCR[1])
#define PORTB_PCR2                     (PORTB->PCR[2])
#define PORTB_PCR3                     (PORTB->PCR[3])
#define PORTB_PCR4                     (PORTB->PCR[4])
#define PORTB_PCR5                     (PORTB->PCR[5])
#define PORTB_PCR6                     (PORTB->PCR[6])
#define PORTB_PCR7                     (PORTB->PCR[7])
#define PORTB_GPCLR                    (PORTB->GPCLR)
#define PORTB_GPCHR                    (PORTB->GPCHR)
#define PORTB_ISFR                     (PORTB->ISFR)
#define PORTB_DFER                     (PORTB->DFER)
#define PORTB_DFCR                     (PORTB->DFCR)
#define PORTB_DFWR                     (PORTB->DFWR)

/* ================================================================================ */
/* ================           PORTC (derived from PORTA)           ================ */
/* ================================================================================ */

/**
 * @brief Pin Control and Interrupts
 */
typedef PORTA_Type PORTC_Type;  /*!< PORTC Structure                                             */


/* -------------------------------------------------------------------------------- */
/* -----------     'PORTC' Register Access macros                       ----------- */
/* -------------------------------------------------------------------------------- */

#define PORTC_PCR0                     (PORTC->PCR[0])
#define PORTC_PCR1                     (PORTC->PCR[1])
#define PORTC_PCR2                     (PORTC->PCR[2])
#define PORTC_PCR3                     (PORTC->PCR[3])
#define PORTC_PCR4                     (PORTC->PCR[4])
#define PORTC_PCR5                     (PORTC->PCR[5])
#define PORTC_PCR6                     (PORTC->PCR[6])
#define PORTC_PCR7                     (PORTC->PCR[7])
#define PORTC_GPCLR                    (PORTC->GPCLR)
#define PORTC_GPCHR                    (PORTC->GPCHR)
#define PORTC_ISFR                     (PORTC->ISFR)
#define PORTC_DFER                     (PORTC->DFER)
#define PORTC_DFCR                     (PORTC->DFCR)
#define PORTC_DFWR                     (PORTC->DFWR)

/* ================================================================================ */
/* ================           PORTD (derived from PORTA)           ================ */
/* ================================================================================ */

/**
 * @brief Pin Control and Interrupts
 */
typedef PORTA_Type PORTD_Type;  /*!< PORTD Structure                                             */


/* -------------------------------------------------------------------------------- */
/* -----------     'PORTD' Register Access macros                       ----------- */
/* -------------------------------------------------------------------------------- */

#define PORTD_PCR0                     (PORTD->PCR[0])
#define PORTD_PCR1                     (PORTD->PCR[1])
#define PORTD_PCR2                     (PORTD->PCR[2])
#define PORTD_PCR3                     (PORTD->PCR[3])
#define PORTD_PCR4                     (PORTD->PCR[4])
#define PORTD_PCR5                     (PORTD->PCR[5])
#define PORTD_PCR6                     (PORTD->PCR[6])
#define PORTD_PCR7                     (PORTD->PCR[7])
#define PORTD_GPCLR                    (PORTD->GPCLR)
#define PORTD_GPCHR                    (PORTD->GPCHR)
#define PORTD_ISFR                     (PORTD->ISFR)
#define PORTD_DFER                     (PORTD->DFER)
#define PORTD_DFCR                     (PORTD->DFCR)
#define PORTD_DFWR                     (PORTD->DFWR)

/* ================================================================================ */
/* ================           PORTE (derived from PORTA)           ================ */
/* ================================================================================ */

/**
 * @brief Pin Control and Interrupts
 */
typedef PORTA_Type PORTE_Type;  /*!< PORTE Structure                                             */


/* -------------------------------------------------------------------------------- */
/* -----------     'PORTE' Register Access macros                       ----------- */
/* -------------------------------------------------------------------------------- */

#define PORTE_PCR0                     (PORTE->PCR[0])
#define PORTE_PCR1                     (PORTE->PCR[1])
#define PORTE_PCR2                     (PORTE->PCR[2])
#define PORTE_PCR3                     (PORTE->PCR[3])
#define PORTE_PCR4                     (PORTE->PCR[4])
#define PORTE_PCR5                     (PORTE->PCR[5])
#define PORTE_PCR6                     (PORTE->PCR[6])
#define PORTE_PCR7                     (PORTE->PCR[7])
#define PORTE_GPCLR                    (PORTE->GPCLR)
#define PORTE_GPCHR                    (PORTE->GPCHR)
#define PORTE_ISFR                     (PORTE->ISFR)
#define PORTE_DFER                     (PORTE->DFER)
#define PORTE_DFCR                     (PORTE->DFCR)
#define PORTE_DFWR                     (PORTE->DFWR)

/* ================================================================================ */
/* ================           PORTF (derived from PORTA)           ================ */
/* ================================================================================ */

/**
 * @brief Pin Control and Interrupts
 */
typedef PORTA_Type PORTF_Type;  /*!< PORTF Structure                                             */


/* -------------------------------------------------------------------------------- */
/* -----------     'PORTF' Register Access macros                       ----------- */
/* -------------------------------------------------------------------------------- */

#define PORTF_PCR0                     (PORTF->PCR[0])
#define PORTF_PCR1                     (PORTF->PCR[1])
#define PORTF_PCR2                     (PORTF->PCR[2])
#define PORTF_PCR3                     (PORTF->PCR[3])
#define PORTF_PCR4                     (PORTF->PCR[4])
#define PORTF_PCR5                     (PORTF->PCR[5])
#define PORTF_PCR6                     (PORTF->PCR[6])
#define PORTF_PCR7                     (PORTF->PCR[7])
#define PORTF_GPCLR                    (PORTF->GPCLR)
#define PORTF_GPCHR                    (PORTF->GPCHR)
#define PORTF_ISFR                     (PORTF->ISFR)
#define PORTF_DFER                     (PORTF->DFER)
#define PORTF_DFCR                     (PORTF->DFCR)
#define PORTF_DFWR                     (PORTF->DFWR)

/* ================================================================================ */
/* ================           PORTG (derived from PORTA)           ================ */
/* ================================================================================ */

/**
 * @brief Pin Control and Interrupts
 */
typedef PORTA_Type PORTG_Type;  /*!< PORTG Structure                                             */


/* -------------------------------------------------------------------------------- */
/* -----------     'PORTG' Register Access macros                       ----------- */
/* -------------------------------------------------------------------------------- */

#define PORTG_PCR0                     (PORTG->PCR[0])
#define PORTG_PCR1                     (PORTG->PCR[1])
#define PORTG_PCR2                     (PORTG->PCR[2])
#define PORTG_PCR3                     (PORTG->PCR[3])
#define PORTG_PCR4                     (PORTG->PCR[4])
#define PORTG_PCR5                     (PORTG->PCR[5])
#define PORTG_PCR6                     (PORTG->PCR[6])
#define PORTG_PCR7                     (PORTG->PCR[7])
#define PORTG_GPCLR                    (PORTG->GPCLR)
#define PORTG_GPCHR                    (PORTG->GPCHR)
#define PORTG_ISFR                     (PORTG->ISFR)
#define PORTG_DFER                     (PORTG->DFER)
#define PORTG_DFCR                     (PORTG->DFCR)
#define PORTG_DFWR                     (PORTG->DFWR)

/* ================================================================================ */
/* ================           PORTH (derived from PORTA)           ================ */
/* ================================================================================ */

/**
 * @brief Pin Control and Interrupts
 */
typedef PORTA_Type PORTH_Type;  /*!< PORTH Structure                                             */


/* -------------------------------------------------------------------------------- */
/* -----------     'PORTH' Register Access macros                       ----------- */
/* -------------------------------------------------------------------------------- */

#define PORTH_PCR0                     (PORTH->PCR[0])
#define PORTH_PCR1                     (PORTH->PCR[1])
#define PORTH_PCR2                     (PORTH->PCR[2])
#define PORTH_PCR3                     (PORTH->PCR[3])
#define PORTH_PCR4                     (PORTH->PCR[4])
#define PORTH_PCR5                     (PORTH->PCR[5])
#define PORTH_PCR6                     (PORTH->PCR[6])
#define PORTH_PCR7                     (PORTH->PCR[7])
#define PORTH_GPCLR                    (PORTH->GPCLR)
#define PORTH_GPCHR                    (PORTH->GPCHR)
#define PORTH_ISFR                     (PORTH->ISFR)
#define PORTH_DFER                     (PORTH->DFER)
#define PORTH_DFCR                     (PORTH->DFCR)
#define PORTH_DFWR                     (PORTH->DFWR)

/* ================================================================================ */
/* ================           PORTI (derived from PORTA)           ================ */
/* ================================================================================ */

/**
 * @brief Pin Control and Interrupts
 */
typedef PORTA_Type PORTI_Type;  /*!< PORTI Structure                                             */


/* -------------------------------------------------------------------------------- */
/* -----------     'PORTI' Register Access macros                       ----------- */
/* -------------------------------------------------------------------------------- */

#define PORTI_PCR0                     (PORTI->PCR[0])
#define PORTI_PCR1                     (PORTI->PCR[1])
#define PORTI_PCR2                     (PORTI->PCR[2])
#define PORTI_PCR3                     (PORTI->PCR[3])
#define PORTI_PCR4                     (PORTI->PCR[4])
#define PORTI_PCR5                     (PORTI->PCR[5])
#define PORTI_PCR6                     (PORTI->PCR[6])
#define PORTI_PCR7                     (PORTI->PCR[7])
#define PORTI_GPCLR                    (PORTI->GPCLR)
#define PORTI_GPCHR                    (PORTI->GPCHR)
#define PORTI_ISFR                     (PORTI->ISFR)
#define PORTI_DFER                     (PORTI->DFER)
#define PORTI_DFCR                     (PORTI->DFCR)
#define PORTI_DFWR                     (PORTI->DFWR)

/* ================================================================================ */
/* ================           RCM (file:RCM_MKM)                   ================ */
/* ================================================================================ */

/**
 * @brief Reset Control Module
 */
typedef struct {                                /*!<       RCM Structure                                                */
   __I  uint8_t   SRS0;                         /*!< 0000: System Reset Status Register 0                               */
   __I  uint8_t   SRS1;                         /*!< 0001: System Reset Status Register 1                               */
   __I  uint16_t  RESERVED0;                    /*!< 0002:                                                              */
   __IO uint8_t   RPFC;                         /*!< 0004: Reset Pin Filter Control Register                            */
   __IO uint8_t   RPFW;                         /*!< 0005: Reset Pin Filter Width Register                              */
} RCM_Type;


/* -------------------------------------------------------------------------------- */
/* -----------     'RCM' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */


/* ------- RCM_SRS0                                 ------ */
#define RCM_SRS0_WAKEUP_MASK                     (0x01UL << RCM_SRS0_WAKEUP_SHIFT)                   /*!< RCM_SRS0: WAKEUP Mask                   */
#define RCM_SRS0_WAKEUP_SHIFT                    0                                                   /*!< RCM_SRS0: WAKEUP Position               */
#define RCM_SRS0_LVD_MASK                        (0x01UL << RCM_SRS0_LVD_SHIFT)                      /*!< RCM_SRS0: LVD Mask                      */
#define RCM_SRS0_LVD_SHIFT                       1                                                   /*!< RCM_SRS0: LVD Position                  */
#define RCM_SRS0_LOC_MASK                        (0x01UL << RCM_SRS0_LOC_SHIFT)                      /*!< RCM_SRS0: LOC Mask                      */
#define RCM_SRS0_LOC_SHIFT                       2                                                   /*!< RCM_SRS0: LOC Position                  */
#define RCM_SRS0_LOL_MASK                        (0x01UL << RCM_SRS0_LOL_SHIFT)                      /*!< RCM_SRS0: LOL Mask                      */
#define RCM_SRS0_LOL_SHIFT                       3                                                   /*!< RCM_SRS0: LOL Position                  */
#define RCM_SRS0_WDOG_MASK                       (0x01UL << RCM_SRS0_WDOG_SHIFT)                     /*!< RCM_SRS0: WDOG Mask                     */
#define RCM_SRS0_WDOG_SHIFT                      5                                                   /*!< RCM_SRS0: WDOG Position                 */
#define RCM_SRS0_PIN_MASK                        (0x01UL << RCM_SRS0_PIN_SHIFT)                      /*!< RCM_SRS0: PIN Mask                      */
#define RCM_SRS0_PIN_SHIFT                       6                                                   /*!< RCM_SRS0: PIN Position                  */
#define RCM_SRS0_POR_MASK                        (0x01UL << RCM_SRS0_POR_SHIFT)                      /*!< RCM_SRS0: POR Mask                      */
#define RCM_SRS0_POR_SHIFT                       7                                                   /*!< RCM_SRS0: POR Position                  */

/* ------- RCM_SRS1                                 ------ */
#define RCM_SRS1_LOCKUP_MASK                     (0x01UL << RCM_SRS1_LOCKUP_SHIFT)                   /*!< RCM_SRS1: LOCKUP Mask                   */
#define RCM_SRS1_LOCKUP_SHIFT                    1                                                   /*!< RCM_SRS1: LOCKUP Position               */
#define RCM_SRS1_SW_MASK                         (0x01UL << RCM_SRS1_SW_SHIFT)                       /*!< RCM_SRS1: SW Mask                       */
#define RCM_SRS1_SW_SHIFT                        2                                                   /*!< RCM_SRS1: SW Position                   */
#define RCM_SRS1_MDM_AP_MASK                     (0x01UL << RCM_SRS1_MDM_AP_SHIFT)                   /*!< RCM_SRS1: MDM_AP Mask                   */
#define RCM_SRS1_MDM_AP_SHIFT                    3                                                   /*!< RCM_SRS1: MDM_AP Position               */
#define RCM_SRS1_SACKERR_MASK                    (0x01UL << RCM_SRS1_SACKERR_SHIFT)                  /*!< RCM_SRS1: SACKERR Mask                  */
#define RCM_SRS1_SACKERR_SHIFT                   5                                                   /*!< RCM_SRS1: SACKERR Position              */

/* ------- RCM_RPFC                                 ------ */
#define RCM_RPFC_RSTFLTSRW_MASK                  (0x03UL << RCM_RPFC_RSTFLTSRW_SHIFT)                /*!< RCM_RPFC: RSTFLTSRW Mask                */
#define RCM_RPFC_RSTFLTSRW_SHIFT                 0                                                   /*!< RCM_RPFC: RSTFLTSRW Position            */
#define RCM_RPFC_RSTFLTSRW(x)                    (((x)<<RCM_RPFC_RSTFLTSRW_SHIFT)&RCM_RPFC_RSTFLTSRW_MASK) /*!< RCM_RPFC                                */
#define RCM_RPFC_RSTFLTSS_MASK                   (0x01UL << RCM_RPFC_RSTFLTSS_SHIFT)                 /*!< RCM_RPFC: RSTFLTSS Mask                 */
#define RCM_RPFC_RSTFLTSS_SHIFT                  2                                                   /*!< RCM_RPFC: RSTFLTSS Position             */

/* ------- RCM_RPFW                                 ------ */
#define RCM_RPFW_RSTFLTSEL_MASK                  (0x1FUL << RCM_RPFW_RSTFLTSEL_SHIFT)                /*!< RCM_RPFW: RSTFLTSEL Mask                */
#define RCM_RPFW_RSTFLTSEL_SHIFT                 0                                                   /*!< RCM_RPFW: RSTFLTSEL Position            */
#define RCM_RPFW_RSTFLTSEL(x)                    (((x)<<RCM_RPFW_RSTFLTSEL_SHIFT)&RCM_RPFW_RSTFLTSEL_MASK) /*!< RCM_RPFW                                */

/* -------------------------------------------------------------------------------- */
/* -----------     'RCM' Register Access macros                         ----------- */
/* -------------------------------------------------------------------------------- */

#define RCM_SRS0                       (RCM->SRS0)
#define RCM_SRS1                       (RCM->SRS1)
#define RCM_RPFC                       (RCM->RPFC)
#define RCM_RPFW                       (RCM->RPFW)

/* ================================================================================ */
/* ================           RNG (file:RNG_1)                     ================ */
/* ================================================================================ */

/**
 * @brief Random Number Generator Accelerator
 */
typedef struct {                                /*!<       RNG Structure                                                */
   __IO uint32_t  CR;                           /*!< 0000: RNGA Control Register                                        */
   __I  uint32_t  SR;                           /*!< 0004: RNGA Status Register                                         */
   __O  uint32_t  ER;                           /*!< 0008: RNGA Entropy Register                                        */
   __I  uint32_t  OR;                           /*!< 000C: RNGA Output Register                                         */
} RNG_Type;


/* -------------------------------------------------------------------------------- */
/* -----------     'RNG' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */


/* ------- RNG_CR                                   ------ */
#define RNG_CR_GO_MASK                           (0x01UL << RNG_CR_GO_SHIFT)                         /*!< RNG_CR: GO Mask                         */
#define RNG_CR_GO_SHIFT                          0                                                   /*!< RNG_CR: GO Position                     */
#define RNG_CR_HA_MASK                           (0x01UL << RNG_CR_HA_SHIFT)                         /*!< RNG_CR: HA Mask                         */
#define RNG_CR_HA_SHIFT                          1                                                   /*!< RNG_CR: HA Position                     */
#define RNG_CR_INTM_MASK                         (0x01UL << RNG_CR_INTM_SHIFT)                       /*!< RNG_CR: INTM Mask                       */
#define RNG_CR_INTM_SHIFT                        2                                                   /*!< RNG_CR: INTM Position                   */
#define RNG_CR_CLRI_MASK                         (0x01UL << RNG_CR_CLRI_SHIFT)                       /*!< RNG_CR: CLRI Mask                       */
#define RNG_CR_CLRI_SHIFT                        3                                                   /*!< RNG_CR: CLRI Position                   */
#define RNG_CR_SLP_MASK                          (0x01UL << RNG_CR_SLP_SHIFT)                        /*!< RNG_CR: SLP Mask                        */
#define RNG_CR_SLP_SHIFT                         4                                                   /*!< RNG_CR: SLP Position                    */

/* ------- RNG_SR                                   ------ */
#define RNG_SR_SECV_MASK                         (0x01UL << RNG_SR_SECV_SHIFT)                       /*!< RNG_SR: SECV Mask                       */
#define RNG_SR_SECV_SHIFT                        0                                                   /*!< RNG_SR: SECV Position                   */
#define RNG_SR_LRS_MASK                          (0x01UL << RNG_SR_LRS_SHIFT)                        /*!< RNG_SR: LRS Mask                        */
#define RNG_SR_LRS_SHIFT                         1                                                   /*!< RNG_SR: LRS Position                    */
#define RNG_SR_ORU_MASK                          (0x01UL << RNG_SR_ORU_SHIFT)                        /*!< RNG_SR: ORU Mask                        */
#define RNG_SR_ORU_SHIFT                         2                                                   /*!< RNG_SR: ORU Position                    */
#define RNG_SR_ERRI_MASK                         (0x01UL << RNG_SR_ERRI_SHIFT)                       /*!< RNG_SR: ERRI Mask                       */
#define RNG_SR_ERRI_SHIFT                        3                                                   /*!< RNG_SR: ERRI Position                   */
#define RNG_SR_SLP_MASK                          (0x01UL << RNG_SR_SLP_SHIFT)                        /*!< RNG_SR: SLP Mask                        */
#define RNG_SR_SLP_SHIFT                         4                                                   /*!< RNG_SR: SLP Position                    */
#define RNG_SR_OREG_LVL_MASK                     (0xFFUL << RNG_SR_OREG_LVL_SHIFT)                   /*!< RNG_SR: OREG_LVL Mask                   */
#define RNG_SR_OREG_LVL_SHIFT                    8                                                   /*!< RNG_SR: OREG_LVL Position               */
#define RNG_SR_OREG_LVL(x)                       (((x)<<RNG_SR_OREG_LVL_SHIFT)&RNG_SR_OREG_LVL_MASK) /*!< RNG_SR                                  */
#define RNG_SR_OREG_SIZE_MASK                    (0xFFUL << RNG_SR_OREG_SIZE_SHIFT)                  /*!< RNG_SR: OREG_SIZE Mask                  */
#define RNG_SR_OREG_SIZE_SHIFT                   16                                                  /*!< RNG_SR: OREG_SIZE Position              */
#define RNG_SR_OREG_SIZE(x)                      (((x)<<RNG_SR_OREG_SIZE_SHIFT)&RNG_SR_OREG_SIZE_MASK) /*!< RNG_SR                                  */

/* ------- RNG_ER                                   ------ */
#define RNG_ER_EXT_ENT_MASK                      (0xFFFFFFFFUL << RNG_ER_EXT_ENT_SHIFT)              /*!< RNG_ER: EXT_ENT Mask                    */
#define RNG_ER_EXT_ENT_SHIFT                     0                                                   /*!< RNG_ER: EXT_ENT Position                */
#define RNG_ER_EXT_ENT(x)                        (((x)<<RNG_ER_EXT_ENT_SHIFT)&RNG_ER_EXT_ENT_MASK)   /*!< RNG_ER                                  */

/* ------- RNG_OR                                   ------ */
#define RNG_OR_RANDOUT_MASK                      (0xFFFFFFFFUL << RNG_OR_RANDOUT_SHIFT)              /*!< RNG_OR: RANDOUT Mask                    */
#define RNG_OR_RANDOUT_SHIFT                     0                                                   /*!< RNG_OR: RANDOUT Position                */
#define RNG_OR_RANDOUT(x)                        (((x)<<RNG_OR_RANDOUT_SHIFT)&RNG_OR_RANDOUT_MASK)   /*!< RNG_OR                                  */

/* -------------------------------------------------------------------------------- */
/* -----------     'RNG' Register Access macros                         ----------- */
/* -------------------------------------------------------------------------------- */

#define RNG_CR                         (RNG->CR)
#define RNG_SR                         (RNG->SR)
#define RNG_ER                         (RNG->ER)
#define RNG_OR                         (RNG->OR)

/* ================================================================================ */
/* ================           ROM (file:ROM_MKL)                   ================ */
/* ================================================================================ */

/**
 * @brief System ROM
 */
typedef struct {                                /*!<       ROM Structure                                                */
   __I  uint32_t  ENTRY[3];                     /*!< 0000: Entry                                                        */
   __I  uint32_t  TABLEMARK;                    /*!< 000C: End of Table Marker Register                                 */
   __I  uint32_t  RESERVED0[1007];              /*!< 0010:                                                              */
   __I  uint32_t  SYSACCESS;                    /*!< 0FCC: System Access Register                                       */
   __I  uint32_t  PERIPHID4;                    /*!< 0FD0: Peripheral ID Register                                       */
   __I  uint32_t  PERIPHID5;                    /*!< 0FD4: Peripheral ID Register                                       */
   __I  uint32_t  PERIPHID6;                    /*!< 0FD8: Peripheral ID Register                                       */
   __I  uint32_t  PERIPHID7;                    /*!< 0FDC: Peripheral ID Register                                       */
   __I  uint32_t  PERIPHID0;                    /*!< 0FE0: Peripheral ID Register                                       */
   __I  uint32_t  PERIPHID1;                    /*!< 0FE4: Peripheral ID Register                                       */
   __I  uint32_t  PERIPHID2;                    /*!< 0FE8: Peripheral ID Register                                       */
   __I  uint32_t  PERIPHID3;                    /*!< 0FEC: Peripheral ID Register                                       */
   __I  uint32_t  COMPID[4];                    /*!< 0FF0: Component ID Register                                        */
} ROM_Type;


/* -------------------------------------------------------------------------------- */
/* -----------     'ROM' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */


/* ------- ROM_ENTRY                                ------ */
#define ROM_ENTRY_ENTRY_MASK                     (0xFFFFFFFFUL << ROM_ENTRY_ENTRY_SHIFT)             /*!< ROM_ENTRY: ENTRY Mask                   */
#define ROM_ENTRY_ENTRY_SHIFT                    0                                                   /*!< ROM_ENTRY: ENTRY Position               */
#define ROM_ENTRY_ENTRY(x)                       (((x)<<ROM_ENTRY_ENTRY_SHIFT)&ROM_ENTRY_ENTRY_MASK) /*!< ROM_ENTRY                               */

/* ------- ROM_TABLEMARK                            ------ */
#define ROM_TABLEMARK_MARK_MASK                  (0xFFFFFFFFUL << ROM_TABLEMARK_MARK_SHIFT)          /*!< ROM_TABLEMARK: MARK Mask                */
#define ROM_TABLEMARK_MARK_SHIFT                 0                                                   /*!< ROM_TABLEMARK: MARK Position            */
#define ROM_TABLEMARK_MARK(x)                    (((x)<<ROM_TABLEMARK_MARK_SHIFT)&ROM_TABLEMARK_MARK_MASK) /*!< ROM_TABLEMARK                           */

/* ------- ROM_SYSACCESS                            ------ */
#define ROM_SYSACCESS_SYSACCESS_MASK             (0xFFFFFFFFUL << ROM_SYSACCESS_SYSACCESS_SHIFT)     /*!< ROM_SYSACCESS: SYSACCESS Mask           */
#define ROM_SYSACCESS_SYSACCESS_SHIFT            0                                                   /*!< ROM_SYSACCESS: SYSACCESS Position       */
#define ROM_SYSACCESS_SYSACCESS(x)               (((x)<<ROM_SYSACCESS_SYSACCESS_SHIFT)&ROM_SYSACCESS_SYSACCESS_MASK) /*!< ROM_SYSACCESS                           */

/* ------- ROM_PERIPHID                             ------ */
#define ROM_PERIPHID_PERIPHID_MASK               (0xFFFFFFFFUL << ROM_PERIPHID_PERIPHID_SHIFT)       /*!< ROM_PERIPHID: PERIPHID Mask             */
#define ROM_PERIPHID_PERIPHID_SHIFT              0                                                   /*!< ROM_PERIPHID: PERIPHID Position         */
#define ROM_PERIPHID_PERIPHID(x)                 (((x)<<ROM_PERIPHID_PERIPHID_SHIFT)&ROM_PERIPHID_PERIPHID_MASK) /*!< ROM_PERIPHID                            */

/* ------- ROM_COMPID                               ------ */
#define ROM_COMPID_COMPID_MASK                   (0xFFFFFFFFUL << ROM_COMPID_COMPID_SHIFT)           /*!< ROM_COMPID: COMPID Mask                 */
#define ROM_COMPID_COMPID_SHIFT                  0                                                   /*!< ROM_COMPID: COMPID Position             */
#define ROM_COMPID_COMPID(x)                     (((x)<<ROM_COMPID_COMPID_SHIFT)&ROM_COMPID_COMPID_MASK) /*!< ROM_COMPID                              */

/* -------------------------------------------------------------------------------- */
/* -----------     'ROM' Register Access macros                         ----------- */
/* -------------------------------------------------------------------------------- */

#define ROM_ENTRY0                     (ROM->ENTRY[0])
#define ROM_ENTRY1                     (ROM->ENTRY[1])
#define ROM_ENTRY2                     (ROM->ENTRY[2])
#define ROM_TABLEMARK                  (ROM->TABLEMARK)
#define ROM_SYSACCESS                  (ROM->SYSACCESS)
#define ROM_PERIPHID4                  (ROM->PERIPHID4)
#define ROM_PERIPHID5                  (ROM->PERIPHID5)
#define ROM_PERIPHID6                  (ROM->PERIPHID6)
#define ROM_PERIPHID7                  (ROM->PERIPHID7)
#define ROM_PERIPHID0                  (ROM->PERIPHID0)
#define ROM_PERIPHID1                  (ROM->PERIPHID1)
#define ROM_PERIPHID2                  (ROM->PERIPHID2)
#define ROM_PERIPHID3                  (ROM->PERIPHID3)
#define ROM_COMPID0                    (ROM->COMPID[0])
#define ROM_COMPID1                    (ROM->COMPID[1])
#define ROM_COMPID2                    (ROM->COMPID[2])
#define ROM_COMPID3                    (ROM->COMPID[3])

/* ================================================================================ */
/* ================           RTC (file:RTC_MKM)                   ================ */
/* ================================================================================ */

/**
 * @brief Independent Real-time clock
 */
typedef struct {                                /*!<       RTC Structure                                                */
   __IO uint16_t  YEARMON;                      /*!< 0000: Year and Month Counters Register                             */
   __IO uint16_t  DAYS;                         /*!< 0002: Days and Day-of-Week Counters Register                       */
   __IO uint16_t  HOURMIN;                      /*!< 0004: Hours and Minutes Counters Register                          */
   __IO uint16_t  SECONDS;                      /*!< 0006: Seconds Counters Register                                    */
   __IO uint16_t  ALM_YEARMON;                  /*!< 0008: Year and Months Alarm Register                               */
   __IO uint16_t  ALM_DAYS;                     /*!< 000A: Days Alarm Register                                          */
   __IO uint16_t  ALM_HOURMIN;                  /*!< 000C: Hours and Minutes Alarm Register                             */
   __IO uint16_t  ALM_SECONDS;                  /*!< 000E: Seconds Alarm Register                                       */
   __IO uint16_t  CTRL;                         /*!< 0010: Control Register                                             */
   union {                                      /*!< 0000: (size=0002)                                                  */
      __IO uint16_t  STATUS;                    /*!< 0012: Status Register                                              */
      __IO uint8_t   STATUS_B;                  /*!< 0012: Status Register                                              */
   };
   __IO uint16_t  ISR;                          /*!< 0014: Interrupt Status Register                                    */
   __IO uint16_t  IER;                          /*!< 0016: Interrupt Enable Register                                    */
   __I  uint32_t  RESERVED0[2];                 /*!< 0018:                                                              */
   union {                                      /*!< 0000: (size=0002)                                                  */
      __IO uint16_t  GP_DATA_REG;               /*!< 0020: General Purpose Data Register                                */
      __IO uint16_t  OSC;                       /*!< 0020: RTC Control Register                                         */
   };
   __IO uint16_t  DST_HOUR;                     /*!< 0022: Daylight Saving Hour Register                                */
   __IO uint16_t  DST_MONTH;                    /*!< 0024: Daylight Saving Month Register                               */
   __IO uint16_t  DST_DAY;                      /*!< 0026: Daylight Saving Day Register                                 */
   __IO uint16_t  COMPEN;                       /*!< 0028: Compensation Register                                        */
   __I  uint16_t  RESERVED1;                    /*!< 002A:                                                              */
   __IO uint16_t  TAMPER_DIRECTION;             /*!< 002C: Tamper Direction Register                                    */
   __IO uint16_t  TAMPER_QSCR;                  /*!< 002E: Tamper Queue Status and Control Register                     */
   __I  uint16_t  RESERVED2;                    /*!< 0030:                                                              */
   __IO uint16_t  TAMPER_SCR;                   /*!< 0032: Tamper Status and Control Register                           */
   __IO uint16_t  FILTER01_CFG;                 /*!< 0034: Tamper 01 Filter Configuration Register                      */
   __IO uint16_t  FILTER2_CFG;                  /*!< 0036: Tamper 2 Filter Configuration Register                       */
   __I  uint32_t  RESERVED3[2];                 /*!< 0038:                                                              */
   __IO uint16_t  TAMPER_QUEUE;                 /*!< 0040: Tamper Queue Register                                        */
   __IO uint16_t  CTRL2;                        /*!< 0042: Control 2 Register                                           */
} RTC_Type;


/* -------------------------------------------------------------------------------- */
/* -----------     'RTC' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */


/* ------- RTC_YEARMON                              ------ */
#define RTC_YEARMON_MON_CNT_MASK                 (0x0FUL << RTC_YEARMON_MON_CNT_SHIFT)               /*!< RTC_YEARMON: MON_CNT Mask               */
#define RTC_YEARMON_MON_CNT_SHIFT                0                                                   /*!< RTC_YEARMON: MON_CNT Position           */
#define RTC_YEARMON_MON_CNT(x)                   (((x)<<RTC_YEARMON_MON_CNT_SHIFT)&RTC_YEARMON_MON_CNT_MASK) /*!< RTC_YEARMON                             */
#define RTC_YEARMON_YROFST_MASK                  (0xFFUL << RTC_YEARMON_YROFST_SHIFT)                /*!< RTC_YEARMON: YROFST Mask                */
#define RTC_YEARMON_YROFST_SHIFT                 8                                                   /*!< RTC_YEARMON: YROFST Position            */
#define RTC_YEARMON_YROFST(x)                    (((x)<<RTC_YEARMON_YROFST_SHIFT)&RTC_YEARMON_YROFST_MASK) /*!< RTC_YEARMON                             */

/* ------- RTC_DAYS                                 ------ */
#define RTC_DAYS_DAY_CNT_MASK                    (0x1FUL << RTC_DAYS_DAY_CNT_SHIFT)                  /*!< RTC_DAYS: DAY_CNT Mask                  */
#define RTC_DAYS_DAY_CNT_SHIFT                   0                                                   /*!< RTC_DAYS: DAY_CNT Position              */
#define RTC_DAYS_DAY_CNT(x)                      (((x)<<RTC_DAYS_DAY_CNT_SHIFT)&RTC_DAYS_DAY_CNT_MASK) /*!< RTC_DAYS                                */
#define RTC_DAYS_DOW_MASK                        (0x07UL << RTC_DAYS_DOW_SHIFT)                      /*!< RTC_DAYS: DOW Mask                      */
#define RTC_DAYS_DOW_SHIFT                       8                                                   /*!< RTC_DAYS: DOW Position                  */
#define RTC_DAYS_DOW(x)                          (((x)<<RTC_DAYS_DOW_SHIFT)&RTC_DAYS_DOW_MASK)       /*!< RTC_DAYS                                */

/* ------- RTC_HOURMIN                              ------ */
#define RTC_HOURMIN_MIN_CNT_MASK                 (0x3FUL << RTC_HOURMIN_MIN_CNT_SHIFT)               /*!< RTC_HOURMIN: MIN_CNT Mask               */
#define RTC_HOURMIN_MIN_CNT_SHIFT                0                                                   /*!< RTC_HOURMIN: MIN_CNT Position           */
#define RTC_HOURMIN_MIN_CNT(x)                   (((x)<<RTC_HOURMIN_MIN_CNT_SHIFT)&RTC_HOURMIN_MIN_CNT_MASK) /*!< RTC_HOURMIN                             */
#define RTC_HOURMIN_HOUR_CNT_MASK                (0x1FUL << RTC_HOURMIN_HOUR_CNT_SHIFT)              /*!< RTC_HOURMIN: HOUR_CNT Mask              */
#define RTC_HOURMIN_HOUR_CNT_SHIFT               8                                                   /*!< RTC_HOURMIN: HOUR_CNT Position          */
#define RTC_HOURMIN_HOUR_CNT(x)                  (((x)<<RTC_HOURMIN_HOUR_CNT_SHIFT)&RTC_HOURMIN_HOUR_CNT_MASK) /*!< RTC_HOURMIN                             */

/* ------- RTC_SECONDS                              ------ */
#define RTC_SECONDS_SEC_CNT_MASK                 (0x3FUL << RTC_SECONDS_SEC_CNT_SHIFT)               /*!< RTC_SECONDS: SEC_CNT Mask               */
#define RTC_SECONDS_SEC_CNT_SHIFT                0                                                   /*!< RTC_SECONDS: SEC_CNT Position           */
#define RTC_SECONDS_SEC_CNT(x)                   (((x)<<RTC_SECONDS_SEC_CNT_SHIFT)&RTC_SECONDS_SEC_CNT_MASK) /*!< RTC_SECONDS                             */

/* ------- RTC_ALM_YEARMON                          ------ */
#define RTC_ALM_YEARMON_ALM_MON_MASK             (0x0FUL << RTC_ALM_YEARMON_ALM_MON_SHIFT)           /*!< RTC_ALM_YEARMON: ALM_MON Mask           */
#define RTC_ALM_YEARMON_ALM_MON_SHIFT            0                                                   /*!< RTC_ALM_YEARMON: ALM_MON Position       */
#define RTC_ALM_YEARMON_ALM_MON(x)               (((x)<<RTC_ALM_YEARMON_ALM_MON_SHIFT)&RTC_ALM_YEARMON_ALM_MON_MASK) /*!< RTC_ALM_YEARMON                         */
#define RTC_ALM_YEARMON_ALM_YEAR_MASK            (0xFFUL << RTC_ALM_YEARMON_ALM_YEAR_SHIFT)          /*!< RTC_ALM_YEARMON: ALM_YEAR Mask          */
#define RTC_ALM_YEARMON_ALM_YEAR_SHIFT           8                                                   /*!< RTC_ALM_YEARMON: ALM_YEAR Position      */
#define RTC_ALM_YEARMON_ALM_YEAR(x)              (((x)<<RTC_ALM_YEARMON_ALM_YEAR_SHIFT)&RTC_ALM_YEARMON_ALM_YEAR_MASK) /*!< RTC_ALM_YEARMON                         */

/* ------- RTC_ALM_DAYS                             ------ */
#define RTC_ALM_DAYS_ALM_DAY_MASK                (0x1FUL << RTC_ALM_DAYS_ALM_DAY_SHIFT)              /*!< RTC_ALM_DAYS: ALM_DAY Mask              */
#define RTC_ALM_DAYS_ALM_DAY_SHIFT               0                                                   /*!< RTC_ALM_DAYS: ALM_DAY Position          */
#define RTC_ALM_DAYS_ALM_DAY(x)                  (((x)<<RTC_ALM_DAYS_ALM_DAY_SHIFT)&RTC_ALM_DAYS_ALM_DAY_MASK) /*!< RTC_ALM_DAYS                            */

/* ------- RTC_ALM_HOURMIN                          ------ */
#define RTC_ALM_HOURMIN_ALM_MIN_MASK             (0x3FUL << RTC_ALM_HOURMIN_ALM_MIN_SHIFT)           /*!< RTC_ALM_HOURMIN: ALM_MIN Mask           */
#define RTC_ALM_HOURMIN_ALM_MIN_SHIFT            0                                                   /*!< RTC_ALM_HOURMIN: ALM_MIN Position       */
#define RTC_ALM_HOURMIN_ALM_MIN(x)               (((x)<<RTC_ALM_HOURMIN_ALM_MIN_SHIFT)&RTC_ALM_HOURMIN_ALM_MIN_MASK) /*!< RTC_ALM_HOURMIN                         */
#define RTC_ALM_HOURMIN_ALM_HOUR_MASK            (0x1FUL << RTC_ALM_HOURMIN_ALM_HOUR_SHIFT)          /*!< RTC_ALM_HOURMIN: ALM_HOUR Mask          */
#define RTC_ALM_HOURMIN_ALM_HOUR_SHIFT           8                                                   /*!< RTC_ALM_HOURMIN: ALM_HOUR Position      */
#define RTC_ALM_HOURMIN_ALM_HOUR(x)              (((x)<<RTC_ALM_HOURMIN_ALM_HOUR_SHIFT)&RTC_ALM_HOURMIN_ALM_HOUR_MASK) /*!< RTC_ALM_HOURMIN                         */

/* ------- RTC_ALM_SECONDS                          ------ */
#define RTC_ALM_SECONDS_ALM_SEC_MASK             (0x3FUL << RTC_ALM_SECONDS_ALM_SEC_SHIFT)           /*!< RTC_ALM_SECONDS: ALM_SEC Mask           */
#define RTC_ALM_SECONDS_ALM_SEC_SHIFT            0                                                   /*!< RTC_ALM_SECONDS: ALM_SEC Position       */
#define RTC_ALM_SECONDS_ALM_SEC(x)               (((x)<<RTC_ALM_SECONDS_ALM_SEC_SHIFT)&RTC_ALM_SECONDS_ALM_SEC_MASK) /*!< RTC_ALM_SECONDS                         */

/* ------- RTC_CTRL                                 ------ */
#define RTC_CTRL_FINEEN_MASK                     (0x01UL << RTC_CTRL_FINEEN_SHIFT)                   /*!< RTC_CTRL: FINEEN Mask                   */
#define RTC_CTRL_FINEEN_SHIFT                    0                                                   /*!< RTC_CTRL: FINEEN Position               */
#define RTC_CTRL_COMP_EN_MASK                    (0x01UL << RTC_CTRL_COMP_EN_SHIFT)                  /*!< RTC_CTRL: COMP_EN Mask                  */
#define RTC_CTRL_COMP_EN_SHIFT                   1                                                   /*!< RTC_CTRL: COMP_EN Position              */
#define RTC_CTRL_ALM_MATCH_MASK                  (0x03UL << RTC_CTRL_ALM_MATCH_SHIFT)                /*!< RTC_CTRL: ALM_MATCH Mask                */
#define RTC_CTRL_ALM_MATCH_SHIFT                 2                                                   /*!< RTC_CTRL: ALM_MATCH Position            */
#define RTC_CTRL_ALM_MATCH(x)                    (((x)<<RTC_CTRL_ALM_MATCH_SHIFT)&RTC_CTRL_ALM_MATCH_MASK) /*!< RTC_CTRL                                */
#define RTC_CTRL_TIMER_STB_MASK_MASK             (0x01UL << RTC_CTRL_TIMER_STB_MASK_SHIFT)           /*!< RTC_CTRL: TIMER_STB_MASK Mask           */
#define RTC_CTRL_TIMER_STB_MASK_SHIFT            4                                                   /*!< RTC_CTRL: TIMER_STB_MASK Position       */
#define RTC_CTRL_DST_EN_MASK                     (0x01UL << RTC_CTRL_DST_EN_SHIFT)                   /*!< RTC_CTRL: DST_EN Mask                   */
#define RTC_CTRL_DST_EN_SHIFT                    6                                                   /*!< RTC_CTRL: DST_EN Position               */
#define RTC_CTRL_SWR_MASK                        (0x01UL << RTC_CTRL_SWR_SHIFT)                      /*!< RTC_CTRL: SWR Mask                      */
#define RTC_CTRL_SWR_SHIFT                       8                                                   /*!< RTC_CTRL: SWR Position                  */
#define RTC_CTRL_CLKOUT_MASK                     (0x03UL << RTC_CTRL_CLKOUT_SHIFT)                   /*!< RTC_CTRL: CLKOUT Mask                   */
#define RTC_CTRL_CLKOUT_SHIFT                    13                                                  /*!< RTC_CTRL: CLKOUT Position               */
#define RTC_CTRL_CLKOUT(x)                       (((x)<<RTC_CTRL_CLKOUT_SHIFT)&RTC_CTRL_CLKOUT_MASK) /*!< RTC_CTRL                                */

/* ------- RTC_STATUS                               ------ */
#define RTC_STATUS_INVAL_BIT_MASK                (0x01UL << RTC_STATUS_INVAL_BIT_SHIFT)              /*!< RTC_STATUS: INVAL_BIT Mask              */
#define RTC_STATUS_INVAL_BIT_SHIFT               0                                                   /*!< RTC_STATUS: INVAL_BIT Position          */
#define RTC_STATUS_WRITE_PROT_EN_MASK            (0x01UL << RTC_STATUS_WRITE_PROT_EN_SHIFT)          /*!< RTC_STATUS: WRITE_PROT_EN Mask          */
#define RTC_STATUS_WRITE_PROT_EN_SHIFT           1                                                   /*!< RTC_STATUS: WRITE_PROT_EN Position      */
#define RTC_STATUS_CPU_LOW_VOLT_MASK             (0x01UL << RTC_STATUS_CPU_LOW_VOLT_SHIFT)           /*!< RTC_STATUS: CPU_LOW_VOLT Mask           */
#define RTC_STATUS_CPU_LOW_VOLT_SHIFT            2                                                   /*!< RTC_STATUS: CPU_LOW_VOLT Position       */
#define RTC_STATUS_RST_SRC_MASK                  (0x01UL << RTC_STATUS_RST_SRC_SHIFT)                /*!< RTC_STATUS: RST_SRC Mask                */
#define RTC_STATUS_RST_SRC_SHIFT                 3                                                   /*!< RTC_STATUS: RST_SRC Position            */
#define RTC_STATUS_CMP_INT_MASK                  (0x01UL << RTC_STATUS_CMP_INT_SHIFT)                /*!< RTC_STATUS: CMP_INT Mask                */
#define RTC_STATUS_CMP_INT_SHIFT                 5                                                   /*!< RTC_STATUS: CMP_INT Position            */
#define RTC_STATUS_WE_MASK                       (0x03UL << RTC_STATUS_WE_SHIFT)                     /*!< RTC_STATUS: WE Mask                     */
#define RTC_STATUS_WE_SHIFT                      6                                                   /*!< RTC_STATUS: WE Position                 */
#define RTC_STATUS_WE(x)                         (((x)<<RTC_STATUS_WE_SHIFT)&RTC_STATUS_WE_MASK)     /*!< RTC_STATUS                              */
#define RTC_STATUS_BUS_ERR_MASK                  (0x03UL << RTC_STATUS_BUS_ERR_SHIFT)                /*!< RTC_STATUS: BUS_ERR Mask                */
#define RTC_STATUS_BUS_ERR_SHIFT                 8                                                   /*!< RTC_STATUS: BUS_ERR Position            */
#define RTC_STATUS_BUS_ERR(x)                    (((x)<<RTC_STATUS_BUS_ERR_SHIFT)&RTC_STATUS_BUS_ERR_MASK) /*!< RTC_STATUS                              */
#define RTC_STATUS_CMP_DONE_MASK                 (0x01UL << RTC_STATUS_CMP_DONE_SHIFT)               /*!< RTC_STATUS: CMP_DONE Mask               */
#define RTC_STATUS_CMP_DONE_SHIFT                11                                                  /*!< RTC_STATUS: CMP_DONE Position           */

/* ------- RTC_STATUS_B                             ------ */
#define RTC_STATUS_B_INVAL_BIT_MASK              (0x01UL << RTC_STATUS_B_INVAL_BIT_SHIFT)            /*!< RTC_STATUS_B: INVAL_BIT Mask            */
#define RTC_STATUS_B_INVAL_BIT_SHIFT             0                                                   /*!< RTC_STATUS_B: INVAL_BIT Position        */
#define RTC_STATUS_B_WRITE_PROT_EN_MASK          (0x01UL << RTC_STATUS_B_WRITE_PROT_EN_SHIFT)        /*!< RTC_STATUS_B: WRITE_PROT_EN Mask        */
#define RTC_STATUS_B_WRITE_PROT_EN_SHIFT         1                                                   /*!< RTC_STATUS_B: WRITE_PROT_EN Position    */
#define RTC_STATUS_B_CPU_LOW_VOLT_MASK           (0x01UL << RTC_STATUS_B_CPU_LOW_VOLT_SHIFT)         /*!< RTC_STATUS_B: CPU_LOW_VOLT Mask         */
#define RTC_STATUS_B_CPU_LOW_VOLT_SHIFT          2                                                   /*!< RTC_STATUS_B: CPU_LOW_VOLT Position     */
#define RTC_STATUS_B_RST_SRC_MASK                (0x01UL << RTC_STATUS_B_RST_SRC_SHIFT)              /*!< RTC_STATUS_B: RST_SRC Mask              */
#define RTC_STATUS_B_RST_SRC_SHIFT               3                                                   /*!< RTC_STATUS_B: RST_SRC Position          */
#define RTC_STATUS_B_CMP_INT_MASK                (0x01UL << RTC_STATUS_B_CMP_INT_SHIFT)              /*!< RTC_STATUS_B: CMP_INT Mask              */
#define RTC_STATUS_B_CMP_INT_SHIFT               5                                                   /*!< RTC_STATUS_B: CMP_INT Position          */
#define RTC_STATUS_B_WE_MASK                     (0x03UL << RTC_STATUS_B_WE_SHIFT)                   /*!< RTC_STATUS_B: WE Mask                   */
#define RTC_STATUS_B_WE_SHIFT                    6                                                   /*!< RTC_STATUS_B: WE Position               */
#define RTC_STATUS_B_WE(x)                       (((x)<<RTC_STATUS_B_WE_SHIFT)&RTC_STATUS_B_WE_MASK) /*!< RTC_STATUS_B                            */

/* ------- RTC_ISR                                  ------ */
#define RTC_ISR_TAMPER_IS_MASK                   (0x01UL << RTC_ISR_TAMPER_IS_SHIFT)                 /*!< RTC_ISR: TAMPER_IS Mask                 */
#define RTC_ISR_TAMPER_IS_SHIFT                  0                                                   /*!< RTC_ISR: TAMPER_IS Position             */
#define RTC_ISR_ALM_IS_MASK                      (0x01UL << RTC_ISR_ALM_IS_SHIFT)                    /*!< RTC_ISR: ALM_IS Mask                    */
#define RTC_ISR_ALM_IS_SHIFT                     2                                                   /*!< RTC_ISR: ALM_IS Position                */
#define RTC_ISR_DAY_IS_MASK                      (0x01UL << RTC_ISR_DAY_IS_SHIFT)                    /*!< RTC_ISR: DAY_IS Mask                    */
#define RTC_ISR_DAY_IS_SHIFT                     3                                                   /*!< RTC_ISR: DAY_IS Position                */
#define RTC_ISR_HOUR_IS_MASK                     (0x01UL << RTC_ISR_HOUR_IS_SHIFT)                   /*!< RTC_ISR: HOUR_IS Mask                   */
#define RTC_ISR_HOUR_IS_SHIFT                    4                                                   /*!< RTC_ISR: HOUR_IS Position               */
#define RTC_ISR_MIN_IS_MASK                      (0x01UL << RTC_ISR_MIN_IS_SHIFT)                    /*!< RTC_ISR: MIN_IS Mask                    */
#define RTC_ISR_MIN_IS_SHIFT                     5                                                   /*!< RTC_ISR: MIN_IS Position                */
#define RTC_ISR_IS_1HZ_MASK                      (0x01UL << RTC_ISR_IS_1HZ_SHIFT)                    /*!< RTC_ISR: IS_1HZ Mask                    */
#define RTC_ISR_IS_1HZ_SHIFT                     6                                                   /*!< RTC_ISR: IS_1HZ Position                */
#define RTC_ISR_IS_2HZ_MASK                      (0x01UL << RTC_ISR_IS_2HZ_SHIFT)                    /*!< RTC_ISR: IS_2HZ Mask                    */
#define RTC_ISR_IS_2HZ_SHIFT                     7                                                   /*!< RTC_ISR: IS_2HZ Position                */
#define RTC_ISR_IS_4HZ_MASK                      (0x01UL << RTC_ISR_IS_4HZ_SHIFT)                    /*!< RTC_ISR: IS_4HZ Mask                    */
#define RTC_ISR_IS_4HZ_SHIFT                     8                                                   /*!< RTC_ISR: IS_4HZ Position                */
#define RTC_ISR_IS_8HZ_MASK                      (0x01UL << RTC_ISR_IS_8HZ_SHIFT)                    /*!< RTC_ISR: IS_8HZ Mask                    */
#define RTC_ISR_IS_8HZ_SHIFT                     9                                                   /*!< RTC_ISR: IS_8HZ Position                */
#define RTC_ISR_IS_16HZ_MASK                     (0x01UL << RTC_ISR_IS_16HZ_SHIFT)                   /*!< RTC_ISR: IS_16HZ Mask                   */
#define RTC_ISR_IS_16HZ_SHIFT                    10                                                  /*!< RTC_ISR: IS_16HZ Position               */
#define RTC_ISR_IS_32HZ_MASK                     (0x01UL << RTC_ISR_IS_32HZ_SHIFT)                   /*!< RTC_ISR: IS_32HZ Mask                   */
#define RTC_ISR_IS_32HZ_SHIFT                    11                                                  /*!< RTC_ISR: IS_32HZ Position               */
#define RTC_ISR_IS_64HZ_MASK                     (0x01UL << RTC_ISR_IS_64HZ_SHIFT)                   /*!< RTC_ISR: IS_64HZ Mask                   */
#define RTC_ISR_IS_64HZ_SHIFT                    12                                                  /*!< RTC_ISR: IS_64HZ Position               */
#define RTC_ISR_IS_128HZ_MASK                    (0x01UL << RTC_ISR_IS_128HZ_SHIFT)                  /*!< RTC_ISR: IS_128HZ Mask                  */
#define RTC_ISR_IS_128HZ_SHIFT                   13                                                  /*!< RTC_ISR: IS_128HZ Position              */
#define RTC_ISR_IS_256HZ_MASK                    (0x01UL << RTC_ISR_IS_256HZ_SHIFT)                  /*!< RTC_ISR: IS_256HZ Mask                  */
#define RTC_ISR_IS_256HZ_SHIFT                   14                                                  /*!< RTC_ISR: IS_256HZ Position              */
#define RTC_ISR_IS_512HZ_MASK                    (0x01UL << RTC_ISR_IS_512HZ_SHIFT)                  /*!< RTC_ISR: IS_512HZ Mask                  */
#define RTC_ISR_IS_512HZ_SHIFT                   15                                                  /*!< RTC_ISR: IS_512HZ Position              */

/* ------- RTC_IER                                  ------ */
#define RTC_IER_TAMPER_IE_MASK                   (0x01UL << RTC_IER_TAMPER_IE_SHIFT)                 /*!< RTC_IER: TAMPER_IE Mask                 */
#define RTC_IER_TAMPER_IE_SHIFT                  0                                                   /*!< RTC_IER: TAMPER_IE Position             */
#define RTC_IER_ALM_IE_MASK                      (0x01UL << RTC_IER_ALM_IE_SHIFT)                    /*!< RTC_IER: ALM_IE Mask                    */
#define RTC_IER_ALM_IE_SHIFT                     2                                                   /*!< RTC_IER: ALM_IE Position                */
#define RTC_IER_DAY_IE_MASK                      (0x01UL << RTC_IER_DAY_IE_SHIFT)                    /*!< RTC_IER: DAY_IE Mask                    */
#define RTC_IER_DAY_IE_SHIFT                     3                                                   /*!< RTC_IER: DAY_IE Position                */
#define RTC_IER_HOUR_IE_MASK                     (0x01UL << RTC_IER_HOUR_IE_SHIFT)                   /*!< RTC_IER: HOUR_IE Mask                   */
#define RTC_IER_HOUR_IE_SHIFT                    4                                                   /*!< RTC_IER: HOUR_IE Position               */
#define RTC_IER_MIN_IE_MASK                      (0x01UL << RTC_IER_MIN_IE_SHIFT)                    /*!< RTC_IER: MIN_IE Mask                    */
#define RTC_IER_MIN_IE_SHIFT                     5                                                   /*!< RTC_IER: MIN_IE Position                */
#define RTC_IER_IE_1HZ_MASK                      (0x01UL << RTC_IER_IE_1HZ_SHIFT)                    /*!< RTC_IER: IE_1HZ Mask                    */
#define RTC_IER_IE_1HZ_SHIFT                     6                                                   /*!< RTC_IER: IE_1HZ Position                */
#define RTC_IER_IE_2HZ_MASK                      (0x01UL << RTC_IER_IE_2HZ_SHIFT)                    /*!< RTC_IER: IE_2HZ Mask                    */
#define RTC_IER_IE_2HZ_SHIFT                     7                                                   /*!< RTC_IER: IE_2HZ Position                */
#define RTC_IER_IE_4HZ_MASK                      (0x01UL << RTC_IER_IE_4HZ_SHIFT)                    /*!< RTC_IER: IE_4HZ Mask                    */
#define RTC_IER_IE_4HZ_SHIFT                     8                                                   /*!< RTC_IER: IE_4HZ Position                */
#define RTC_IER_IE_8HZ_MASK                      (0x01UL << RTC_IER_IE_8HZ_SHIFT)                    /*!< RTC_IER: IE_8HZ Mask                    */
#define RTC_IER_IE_8HZ_SHIFT                     9                                                   /*!< RTC_IER: IE_8HZ Position                */
#define RTC_IER_IE_16HZ_MASK                     (0x01UL << RTC_IER_IE_16HZ_SHIFT)                   /*!< RTC_IER: IE_16HZ Mask                   */
#define RTC_IER_IE_16HZ_SHIFT                    10                                                  /*!< RTC_IER: IE_16HZ Position               */
#define RTC_IER_IE_32HZ_MASK                     (0x01UL << RTC_IER_IE_32HZ_SHIFT)                   /*!< RTC_IER: IE_32HZ Mask                   */
#define RTC_IER_IE_32HZ_SHIFT                    11                                                  /*!< RTC_IER: IE_32HZ Position               */
#define RTC_IER_IE_64HZ_MASK                     (0x01UL << RTC_IER_IE_64HZ_SHIFT)                   /*!< RTC_IER: IE_64HZ Mask                   */
#define RTC_IER_IE_64HZ_SHIFT                    12                                                  /*!< RTC_IER: IE_64HZ Position               */
#define RTC_IER_IE_128HZ_MASK                    (0x01UL << RTC_IER_IE_128HZ_SHIFT)                  /*!< RTC_IER: IE_128HZ Mask                  */
#define RTC_IER_IE_128HZ_SHIFT                   13                                                  /*!< RTC_IER: IE_128HZ Position              */
#define RTC_IER_IE_256HZ_MASK                    (0x01UL << RTC_IER_IE_256HZ_SHIFT)                  /*!< RTC_IER: IE_256HZ Mask                  */
#define RTC_IER_IE_256HZ_SHIFT                   14                                                  /*!< RTC_IER: IE_256HZ Position              */
#define RTC_IER_IE_512HZ_MASK                    (0x01UL << RTC_IER_IE_512HZ_SHIFT)                  /*!< RTC_IER: IE_512HZ Mask                  */
#define RTC_IER_IE_512HZ_SHIFT                   15                                                  /*!< RTC_IER: IE_512HZ Position              */

/* ------- RTC_GP_DATA_REG                          ------ */

/* ------- RTC_OSC                                  ------ */
#define RTC_OSC_OSC_DISABLE_MASK                 (0x01UL << RTC_OSC_OSC_DISABLE_SHIFT)               /*!< RTC_OSC: OSC_DISABLE Mask               */
#define RTC_OSC_OSC_DISABLE_SHIFT                0                                                   /*!< RTC_OSC: OSC_DISABLE Position           */
#define RTC_OSC_SC2P_MASK                        (0x01UL << RTC_OSC_SC2P_SHIFT)                      /*!< RTC_OSC: SC2P Mask                      */
#define RTC_OSC_SC2P_SHIFT                       1                                                   /*!< RTC_OSC: SC2P Position                  */
#define RTC_OSC_SC4P_MASK                        (0x01UL << RTC_OSC_SC4P_SHIFT)                      /*!< RTC_OSC: SC4P Mask                      */
#define RTC_OSC_SC4P_SHIFT                       2                                                   /*!< RTC_OSC: SC4P Position                  */
#define RTC_OSC_SC8P_MASK                        (0x01UL << RTC_OSC_SC8P_SHIFT)                      /*!< RTC_OSC: SC8P Mask                      */
#define RTC_OSC_SC8P_SHIFT                       3                                                   /*!< RTC_OSC: SC8P Position                  */
#define RTC_OSC_SC16P_MASK                       (0x01UL << RTC_OSC_SC16P_SHIFT)                     /*!< RTC_OSC: SC16P Mask                     */
#define RTC_OSC_SC16P_SHIFT                      4                                                   /*!< RTC_OSC: SC16P Position                 */
#define RTC_OSC_BOOT_MODE_MASK                   (0x01UL << RTC_OSC_BOOT_MODE_SHIFT)                 /*!< RTC_OSC: BOOT_MODE Mask                 */
#define RTC_OSC_BOOT_MODE_SHIFT                  7                                                   /*!< RTC_OSC: BOOT_MODE Position             */

/* ------- RTC_DST_HOUR                             ------ */
#define RTC_DST_HOUR_DST_END_HOUR_MASK           (0x1FUL << RTC_DST_HOUR_DST_END_HOUR_SHIFT)         /*!< RTC_DST_HOUR: DST_END_HOUR Mask         */
#define RTC_DST_HOUR_DST_END_HOUR_SHIFT          0                                                   /*!< RTC_DST_HOUR: DST_END_HOUR Position     */
#define RTC_DST_HOUR_DST_END_HOUR(x)             (((x)<<RTC_DST_HOUR_DST_END_HOUR_SHIFT)&RTC_DST_HOUR_DST_END_HOUR_MASK) /*!< RTC_DST_HOUR                            */
#define RTC_DST_HOUR_DST_START_HOUR_MASK         (0x1FUL << RTC_DST_HOUR_DST_START_HOUR_SHIFT)       /*!< RTC_DST_HOUR: DST_START_HOUR Mask       */
#define RTC_DST_HOUR_DST_START_HOUR_SHIFT        8                                                   /*!< RTC_DST_HOUR: DST_START_HOUR Position   */
#define RTC_DST_HOUR_DST_START_HOUR(x)           (((x)<<RTC_DST_HOUR_DST_START_HOUR_SHIFT)&RTC_DST_HOUR_DST_START_HOUR_MASK) /*!< RTC_DST_HOUR                            */

/* ------- RTC_DST_MONTH                            ------ */
#define RTC_DST_MONTH_DST_END_MONTH_MASK         (0x0FUL << RTC_DST_MONTH_DST_END_MONTH_SHIFT)       /*!< RTC_DST_MONTH: DST_END_MONTH Mask       */
#define RTC_DST_MONTH_DST_END_MONTH_SHIFT        0                                                   /*!< RTC_DST_MONTH: DST_END_MONTH Position   */
#define RTC_DST_MONTH_DST_END_MONTH(x)           (((x)<<RTC_DST_MONTH_DST_END_MONTH_SHIFT)&RTC_DST_MONTH_DST_END_MONTH_MASK) /*!< RTC_DST_MONTH                           */
#define RTC_DST_MONTH_DST_START_MONTH_MASK       (0x0FUL << RTC_DST_MONTH_DST_START_MONTH_SHIFT)     /*!< RTC_DST_MONTH: DST_START_MONTH Mask     */
#define RTC_DST_MONTH_DST_START_MONTH_SHIFT      8                                                   /*!< RTC_DST_MONTH: DST_START_MONTH Position */
#define RTC_DST_MONTH_DST_START_MONTH(x)         (((x)<<RTC_DST_MONTH_DST_START_MONTH_SHIFT)&RTC_DST_MONTH_DST_START_MONTH_MASK) /*!< RTC_DST_MONTH                           */

/* ------- RTC_DST_DAY                              ------ */
#define RTC_DST_DAY_DST_END_DAY_MASK             (0x1FUL << RTC_DST_DAY_DST_END_DAY_SHIFT)           /*!< RTC_DST_DAY: DST_END_DAY Mask           */
#define RTC_DST_DAY_DST_END_DAY_SHIFT            0                                                   /*!< RTC_DST_DAY: DST_END_DAY Position       */
#define RTC_DST_DAY_DST_END_DAY(x)               (((x)<<RTC_DST_DAY_DST_END_DAY_SHIFT)&RTC_DST_DAY_DST_END_DAY_MASK) /*!< RTC_DST_DAY                             */
#define RTC_DST_DAY_DST_START_DAY_MASK           (0x1FUL << RTC_DST_DAY_DST_START_DAY_SHIFT)         /*!< RTC_DST_DAY: DST_START_DAY Mask         */
#define RTC_DST_DAY_DST_START_DAY_SHIFT          8                                                   /*!< RTC_DST_DAY: DST_START_DAY Position     */
#define RTC_DST_DAY_DST_START_DAY(x)             (((x)<<RTC_DST_DAY_DST_START_DAY_SHIFT)&RTC_DST_DAY_DST_START_DAY_MASK) /*!< RTC_DST_DAY                             */

/* ------- RTC_COMPEN                               ------ */

/* ------- RTC_TAMPER_DIRECTION                     ------ */
#define RTC_TAMPER_DIRECTION_A_P_TAMP_MASK       (0x0FUL << RTC_TAMPER_DIRECTION_A_P_TAMP_SHIFT)     /*!< RTC_TAMPER_DIRECTION: A_P_TAMP Mask     */
#define RTC_TAMPER_DIRECTION_A_P_TAMP_SHIFT      0                                                   /*!< RTC_TAMPER_DIRECTION: A_P_TAMP Position */
#define RTC_TAMPER_DIRECTION_A_P_TAMP(x)         (((x)<<RTC_TAMPER_DIRECTION_A_P_TAMP_SHIFT)&RTC_TAMPER_DIRECTION_A_P_TAMP_MASK) /*!< RTC_TAMPER_DIRECTION                    */
#define RTC_TAMPER_DIRECTION_I_O_TAMP_MASK       (0x0FUL << RTC_TAMPER_DIRECTION_I_O_TAMP_SHIFT)     /*!< RTC_TAMPER_DIRECTION: I_O_TAMP Mask     */
#define RTC_TAMPER_DIRECTION_I_O_TAMP_SHIFT      8                                                   /*!< RTC_TAMPER_DIRECTION: I_O_TAMP Position */
#define RTC_TAMPER_DIRECTION_I_O_TAMP(x)         (((x)<<RTC_TAMPER_DIRECTION_I_O_TAMP_SHIFT)&RTC_TAMPER_DIRECTION_I_O_TAMP_MASK) /*!< RTC_TAMPER_DIRECTION                    */

/* ------- RTC_TAMPER_QSCR                          ------ */
#define RTC_TAMPER_QSCR_Q_FULL_MASK              (0x01UL << RTC_TAMPER_QSCR_Q_FULL_SHIFT)            /*!< RTC_TAMPER_QSCR: Q_FULL Mask            */
#define RTC_TAMPER_QSCR_Q_FULL_SHIFT             0                                                   /*!< RTC_TAMPER_QSCR: Q_FULL Position        */
#define RTC_TAMPER_QSCR_Q_FULL_INT_EN_MASK       (0x01UL << RTC_TAMPER_QSCR_Q_FULL_INT_EN_SHIFT)     /*!< RTC_TAMPER_QSCR: Q_FULL_INT_EN Mask     */
#define RTC_TAMPER_QSCR_Q_FULL_INT_EN_SHIFT      1                                                   /*!< RTC_TAMPER_QSCR: Q_FULL_INT_EN Position */
#define RTC_TAMPER_QSCR_Q_CLEAR_MASK             (0x01UL << RTC_TAMPER_QSCR_Q_CLEAR_SHIFT)           /*!< RTC_TAMPER_QSCR: Q_CLEAR Mask           */
#define RTC_TAMPER_QSCR_Q_CLEAR_SHIFT            2                                                   /*!< RTC_TAMPER_QSCR: Q_CLEAR Position       */
#define RTC_TAMPER_QSCR_LFSR_CLK_SEL_MASK        (0x07UL << RTC_TAMPER_QSCR_LFSR_CLK_SEL_SHIFT)      /*!< RTC_TAMPER_QSCR: LFSR_CLK_SEL Mask      */
#define RTC_TAMPER_QSCR_LFSR_CLK_SEL_SHIFT       8                                                   /*!< RTC_TAMPER_QSCR: LFSR_CLK_SEL Position  */
#define RTC_TAMPER_QSCR_LFSR_CLK_SEL(x)          (((x)<<RTC_TAMPER_QSCR_LFSR_CLK_SEL_SHIFT)&RTC_TAMPER_QSCR_LFSR_CLK_SEL_MASK) /*!< RTC_TAMPER_QSCR                         */
#define RTC_TAMPER_QSCR_LFSR_DURATION_MASK       (0x0FUL << RTC_TAMPER_QSCR_LFSR_DURATION_SHIFT)     /*!< RTC_TAMPER_QSCR: LFSR_DURATION Mask     */
#define RTC_TAMPER_QSCR_LFSR_DURATION_SHIFT      12                                                  /*!< RTC_TAMPER_QSCR: LFSR_DURATION Position */
#define RTC_TAMPER_QSCR_LFSR_DURATION(x)         (((x)<<RTC_TAMPER_QSCR_LFSR_DURATION_SHIFT)&RTC_TAMPER_QSCR_LFSR_DURATION_MASK) /*!< RTC_TAMPER_QSCR                         */

/* ------- RTC_TAMPER_SCR                           ------ */
#define RTC_TAMPER_SCR_TMPR_EN_MASK              (0x0FUL << RTC_TAMPER_SCR_TMPR_EN_SHIFT)            /*!< RTC_TAMPER_SCR: TMPR_EN Mask            */
#define RTC_TAMPER_SCR_TMPR_EN_SHIFT             0                                                   /*!< RTC_TAMPER_SCR: TMPR_EN Position        */
#define RTC_TAMPER_SCR_TMPR_EN(x)                (((x)<<RTC_TAMPER_SCR_TMPR_EN_SHIFT)&RTC_TAMPER_SCR_TMPR_EN_MASK) /*!< RTC_TAMPER_SCR                          */
#define RTC_TAMPER_SCR_TMPR_STS_MASK             (0x0FUL << RTC_TAMPER_SCR_TMPR_STS_SHIFT)           /*!< RTC_TAMPER_SCR: TMPR_STS Mask           */
#define RTC_TAMPER_SCR_TMPR_STS_SHIFT            8                                                   /*!< RTC_TAMPER_SCR: TMPR_STS Position       */
#define RTC_TAMPER_SCR_TMPR_STS(x)               (((x)<<RTC_TAMPER_SCR_TMPR_STS_SHIFT)&RTC_TAMPER_SCR_TMPR_STS_MASK) /*!< RTC_TAMPER_SCR                          */

/* ------- RTC_FILTER01_CFG                         ------ */
#define RTC_FILTER01_CFG_FIL_DUR1_MASK           (0x07UL << RTC_FILTER01_CFG_FIL_DUR1_SHIFT)         /*!< RTC_FILTER01_CFG: FIL_DUR1 Mask         */
#define RTC_FILTER01_CFG_FIL_DUR1_SHIFT          0                                                   /*!< RTC_FILTER01_CFG: FIL_DUR1 Position     */
#define RTC_FILTER01_CFG_FIL_DUR1(x)             (((x)<<RTC_FILTER01_CFG_FIL_DUR1_SHIFT)&RTC_FILTER01_CFG_FIL_DUR1_MASK) /*!< RTC_FILTER01_CFG                        */
#define RTC_FILTER01_CFG_CLK_SEL1_MASK           (0x07UL << RTC_FILTER01_CFG_CLK_SEL1_SHIFT)         /*!< RTC_FILTER01_CFG: CLK_SEL1 Mask         */
#define RTC_FILTER01_CFG_CLK_SEL1_SHIFT          4                                                   /*!< RTC_FILTER01_CFG: CLK_SEL1 Position     */
#define RTC_FILTER01_CFG_CLK_SEL1(x)             (((x)<<RTC_FILTER01_CFG_CLK_SEL1_SHIFT)&RTC_FILTER01_CFG_CLK_SEL1_MASK) /*!< RTC_FILTER01_CFG                        */
#define RTC_FILTER01_CFG_POL1_MASK               (0x01UL << RTC_FILTER01_CFG_POL1_SHIFT)             /*!< RTC_FILTER01_CFG: POL1 Mask             */
#define RTC_FILTER01_CFG_POL1_SHIFT              7                                                   /*!< RTC_FILTER01_CFG: POL1 Position         */
#define RTC_FILTER01_CFG_FIL_DUR0_MASK           (0x0FUL << RTC_FILTER01_CFG_FIL_DUR0_SHIFT)         /*!< RTC_FILTER01_CFG: FIL_DUR0 Mask         */
#define RTC_FILTER01_CFG_FIL_DUR0_SHIFT          8                                                   /*!< RTC_FILTER01_CFG: FIL_DUR0 Position     */
#define RTC_FILTER01_CFG_FIL_DUR0(x)             (((x)<<RTC_FILTER01_CFG_FIL_DUR0_SHIFT)&RTC_FILTER01_CFG_FIL_DUR0_MASK) /*!< RTC_FILTER01_CFG                        */
#define RTC_FILTER01_CFG_CLK_SEL0_MASK           (0x07UL << RTC_FILTER01_CFG_CLK_SEL0_SHIFT)         /*!< RTC_FILTER01_CFG: CLK_SEL0 Mask         */
#define RTC_FILTER01_CFG_CLK_SEL0_SHIFT          12                                                  /*!< RTC_FILTER01_CFG: CLK_SEL0 Position     */
#define RTC_FILTER01_CFG_CLK_SEL0(x)             (((x)<<RTC_FILTER01_CFG_CLK_SEL0_SHIFT)&RTC_FILTER01_CFG_CLK_SEL0_MASK) /*!< RTC_FILTER01_CFG                        */
#define RTC_FILTER01_CFG_POL0_MASK               (0x01UL << RTC_FILTER01_CFG_POL0_SHIFT)             /*!< RTC_FILTER01_CFG: POL0 Mask             */
#define RTC_FILTER01_CFG_POL0_SHIFT              15                                                  /*!< RTC_FILTER01_CFG: POL0 Position         */

/* ------- RTC_FILTER2_CFG                          ------ */
#define RTC_FILTER2_CFG_FIL_DUR2_MASK            (0x0FUL << RTC_FILTER2_CFG_FIL_DUR2_SHIFT)          /*!< RTC_FILTER2_CFG: FIL_DUR2 Mask          */
#define RTC_FILTER2_CFG_FIL_DUR2_SHIFT           8                                                   /*!< RTC_FILTER2_CFG: FIL_DUR2 Position      */
#define RTC_FILTER2_CFG_FIL_DUR2(x)              (((x)<<RTC_FILTER2_CFG_FIL_DUR2_SHIFT)&RTC_FILTER2_CFG_FIL_DUR2_MASK) /*!< RTC_FILTER2_CFG                         */
#define RTC_FILTER2_CFG_CLK_SEL2_MASK            (0x07UL << RTC_FILTER2_CFG_CLK_SEL2_SHIFT)          /*!< RTC_FILTER2_CFG: CLK_SEL2 Mask          */
#define RTC_FILTER2_CFG_CLK_SEL2_SHIFT           12                                                  /*!< RTC_FILTER2_CFG: CLK_SEL2 Position      */
#define RTC_FILTER2_CFG_CLK_SEL2(x)              (((x)<<RTC_FILTER2_CFG_CLK_SEL2_SHIFT)&RTC_FILTER2_CFG_CLK_SEL2_MASK) /*!< RTC_FILTER2_CFG                         */
#define RTC_FILTER2_CFG_POL2_MASK                (0x01UL << RTC_FILTER2_CFG_POL2_SHIFT)              /*!< RTC_FILTER2_CFG: POL2 Mask              */
#define RTC_FILTER2_CFG_POL2_SHIFT               15                                                  /*!< RTC_FILTER2_CFG: POL2 Position          */

/* ------- RTC_TAMPER_QUEUE                         ------ */
#define RTC_TAMPER_QUEUE_TAMPER_DATA_MASK        (0x7FFFUL << RTC_TAMPER_QUEUE_TAMPER_DATA_SHIFT)    /*!< RTC_TAMPER_QUEUE: TAMPER_DATA Mask      */
#define RTC_TAMPER_QUEUE_TAMPER_DATA_SHIFT       0                                                   /*!< RTC_TAMPER_QUEUE: TAMPER_DATA Position  */
#define RTC_TAMPER_QUEUE_TAMPER_DATA(x)          (((x)<<RTC_TAMPER_QUEUE_TAMPER_DATA_SHIFT)&RTC_TAMPER_QUEUE_TAMPER_DATA_MASK) /*!< RTC_TAMPER_QUEUE                        */

/* ------- RTC_CTRL2                                ------ */
#define RTC_CTRL2_TAMP_CFG_OVER_MASK             (0x01UL << RTC_CTRL2_TAMP_CFG_OVER_SHIFT)           /*!< RTC_CTRL2: TAMP_CFG_OVER Mask           */
#define RTC_CTRL2_TAMP_CFG_OVER_SHIFT            0                                                   /*!< RTC_CTRL2: TAMP_CFG_OVER Position       */
#define RTC_CTRL2_WAKEUP_STATUS_MASK             (0x03UL << RTC_CTRL2_WAKEUP_STATUS_SHIFT)           /*!< RTC_CTRL2: WAKEUP_STATUS Mask           */
#define RTC_CTRL2_WAKEUP_STATUS_SHIFT            5                                                   /*!< RTC_CTRL2: WAKEUP_STATUS Position       */
#define RTC_CTRL2_WAKEUP_STATUS(x)               (((x)<<RTC_CTRL2_WAKEUP_STATUS_SHIFT)&RTC_CTRL2_WAKEUP_STATUS_MASK) /*!< RTC_CTRL2                               */
#define RTC_CTRL2_WAKEUP_MODE_MASK               (0x01UL << RTC_CTRL2_WAKEUP_MODE_SHIFT)             /*!< RTC_CTRL2: WAKEUP_MODE Mask             */
#define RTC_CTRL2_WAKEUP_MODE_SHIFT              7                                                   /*!< RTC_CTRL2: WAKEUP_MODE Position         */

/* -------------------------------------------------------------------------------- */
/* -----------     'RTC' Register Access macros                         ----------- */
/* -------------------------------------------------------------------------------- */

#define RTC_YEARMON                    (RTC->YEARMON)
#define RTC_DAYS                       (RTC->DAYS)
#define RTC_HOURMIN                    (RTC->HOURMIN)
#define RTC_SECONDS                    (RTC->SECONDS)
#define RTC_ALM_YEARMON                (RTC->ALM_YEARMON)
#define RTC_ALM_DAYS                   (RTC->ALM_DAYS)
#define RTC_ALM_HOURMIN                (RTC->ALM_HOURMIN)
#define RTC_ALM_SECONDS                (RTC->ALM_SECONDS)
#define RTC_CTRL                       (RTC->CTRL)
#define RTC_STATUS                     (RTC->STATUS)
#define RTC_STATUS_B                   (RTC->STATUS_B)
#define RTC_ISR                        (RTC->ISR)
#define RTC_IER                        (RTC->IER)
#define RTC_GP_DATA_REG                (RTC->GP_DATA_REG)
#define RTC_OSC                        (RTC->OSC)
#define RTC_DST_HOUR                   (RTC->DST_HOUR)
#define RTC_DST_MONTH                  (RTC->DST_MONTH)
#define RTC_DST_DAY                    (RTC->DST_DAY)
#define RTC_COMPEN                     (RTC->COMPEN)
#define RTC_TAMPER_DIRECTION           (RTC->TAMPER_DIRECTION)
#define RTC_TAMPER_QSCR                (RTC->TAMPER_QSCR)
#define RTC_TAMPER_SCR                 (RTC->TAMPER_SCR)
#define RTC_FILTER01_CFG               (RTC->FILTER01_CFG)
#define RTC_FILTER2_CFG                (RTC->FILTER2_CFG)
#define RTC_TAMPER_QUEUE               (RTC->TAMPER_QUEUE)
#define RTC_CTRL2                      (RTC->CTRL2)

/* ================================================================================ */
/* ================           RTC_RAM (file:RTC_MKM_RAM)           ================ */
/* ================================================================================ */

/**
 * @brief Battery backed RAM
 */
typedef struct {                                /*!<       RTC_RAM Structure                                            */
   __IO uint8_t   FILE[32];                     /*!< 0000: Battery backed RAM                                           */
} RTC_RAM_Type;


/* -------------------------------------------------------------------------------- */
/* -----------     'RTC_RAM' Position & Mask macros                     ----------- */
/* -------------------------------------------------------------------------------- */


/* ------- RTC_RAM_FILE                             ------ */

/* -------------------------------------------------------------------------------- */
/* -----------     'RTC_RAM' Register Access macros                     ----------- */
/* -------------------------------------------------------------------------------- */

#define RTC_RAM_FILE0                  (RTC_RAM->FILE[0])
#define RTC_RAM_FILE1                  (RTC_RAM->FILE[1])
#define RTC_RAM_FILE2                  (RTC_RAM->FILE[2])
#define RTC_RAM_FILE3                  (RTC_RAM->FILE[3])
#define RTC_RAM_FILE4                  (RTC_RAM->FILE[4])
#define RTC_RAM_FILE5                  (RTC_RAM->FILE[5])
#define RTC_RAM_FILE6                  (RTC_RAM->FILE[6])
#define RTC_RAM_FILE7                  (RTC_RAM->FILE[7])
#define RTC_RAM_FILE8                  (RTC_RAM->FILE[8])
#define RTC_RAM_FILE9                  (RTC_RAM->FILE[9])
#define RTC_RAM_FILE10                 (RTC_RAM->FILE[10])
#define RTC_RAM_FILE11                 (RTC_RAM->FILE[11])
#define RTC_RAM_FILE12                 (RTC_RAM->FILE[12])
#define RTC_RAM_FILE13                 (RTC_RAM->FILE[13])
#define RTC_RAM_FILE14                 (RTC_RAM->FILE[14])
#define RTC_RAM_FILE15                 (RTC_RAM->FILE[15])
#define RTC_RAM_FILE16                 (RTC_RAM->FILE[16])
#define RTC_RAM_FILE17                 (RTC_RAM->FILE[17])
#define RTC_RAM_FILE18                 (RTC_RAM->FILE[18])
#define RTC_RAM_FILE19                 (RTC_RAM->FILE[19])
#define RTC_RAM_FILE20                 (RTC_RAM->FILE[20])
#define RTC_RAM_FILE21                 (RTC_RAM->FILE[21])
#define RTC_RAM_FILE22                 (RTC_RAM->FILE[22])
#define RTC_RAM_FILE23                 (RTC_RAM->FILE[23])
#define RTC_RAM_FILE24                 (RTC_RAM->FILE[24])
#define RTC_RAM_FILE25                 (RTC_RAM->FILE[25])
#define RTC_RAM_FILE26                 (RTC_RAM->FILE[26])
#define RTC_RAM_FILE27                 (RTC_RAM->FILE[27])
#define RTC_RAM_FILE28                 (RTC_RAM->FILE[28])
#define RTC_RAM_FILE29                 (RTC_RAM->FILE[29])
#define RTC_RAM_FILE30                 (RTC_RAM->FILE[30])
#define RTC_RAM_FILE31                 (RTC_RAM->FILE[31])

/* ================================================================================ */
/* ================           SIM (file:SIM_MKMxxZxxM5)            ================ */
/* ================================================================================ */

/**
 * @brief System Integration Module
 */
typedef struct {                                /*!<       SIM Structure                                                */
   __IO uint32_t  SOPT1;                        /*!< 0000: System Options Register 1                                    */
   __IO uint32_t  SOPT1_CFG;                    /*!< 0004: SOPT1 Configuration Register                                 */
   __I  uint32_t  RESERVED0[1023];              /*!< 0008:                                                              */
   __IO uint32_t  CTRL_REG;                     /*!< 1004: System Control Register                                      */
   __I  uint32_t  RESERVED1[7];                 /*!< 1008:                                                              */
   __I  uint32_t  SDID;                         /*!< 1024: System Device Identification Register                        */
   __I  uint32_t  RESERVED2[3];                 /*!< 1028:                                                              */
   __IO uint32_t  SCGC4;                        /*!< 1034: System Clock Gating Control Register 4                       */
   __IO uint32_t  SCGC5;                        /*!< 1038: System Clock Gating Control Register 5                       */
   __IO uint32_t  SCGC6;                        /*!< 103C: System Clock Gating Control Register 6                       */
   __IO uint32_t  SCGC7;                        /*!< 1040: System Clock Gating Control Register 7                       */
   __IO uint32_t  CLKDIV1;                      /*!< 1044: System Clock Divider Register 1                              */
   __I  uint32_t  RESERVED3;                    /*!< 1048:                                                              */
   __IO uint32_t  FCFG1;                        /*!< 104C: Flash Configuration Register 1                               */
   __I  uint32_t  FCFG2;                        /*!< 1050: Flash Configuration Register 2                               */
   __I  uint32_t  UID[4];                       /*!< 1054: Unique Identification Register                               */
   __I  uint32_t  RESERVED4[2];                 /*!< 1064:                                                              */
   __IO uint32_t  MISC_CTL;                     /*!< 106C: Miscellaneous Control Register                               */
} SIM_Type;


/* -------------------------------------------------------------------------------- */
/* -----------     'SIM' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */


/* ------- SIM_SOPT1                                ------ */
#define SIM_SOPT1_SRAMSIZE_MASK                  (0x0FUL << SIM_SOPT1_SRAMSIZE_SHIFT)                /*!< SIM_SOPT1: SRAMSIZE Mask                */
#define SIM_SOPT1_SRAMSIZE_SHIFT                 12                                                  /*!< SIM_SOPT1: SRAMSIZE Position            */
#define SIM_SOPT1_SRAMSIZE(x)                    (((x)<<SIM_SOPT1_SRAMSIZE_SHIFT)&SIM_SOPT1_SRAMSIZE_MASK) /*!< SIM_SOPT1                               */
#define SIM_SOPT1_OSC32KSEL_MASK                 (0x03UL << SIM_SOPT1_OSC32KSEL_SHIFT)               /*!< SIM_SOPT1: OSC32KSEL Mask               */
#define SIM_SOPT1_OSC32KSEL_SHIFT                18                                                  /*!< SIM_SOPT1: OSC32KSEL Position           */
#define SIM_SOPT1_OSC32KSEL(x)                   (((x)<<SIM_SOPT1_OSC32KSEL_SHIFT)&SIM_SOPT1_OSC32KSEL_MASK) /*!< SIM_SOPT1                               */

/* ------- SIM_SOPT1_CFG                            ------ */
#define SIM_SOPT1_CFG_LPTMR1SEL_MASK             (0x03UL << SIM_SOPT1_CFG_LPTMR1SEL_SHIFT)           /*!< SIM_SOPT1_CFG: LPTMR1SEL Mask           */
#define SIM_SOPT1_CFG_LPTMR1SEL_SHIFT            0                                                   /*!< SIM_SOPT1_CFG: LPTMR1SEL Position       */
#define SIM_SOPT1_CFG_LPTMR1SEL(x)               (((x)<<SIM_SOPT1_CFG_LPTMR1SEL_SHIFT)&SIM_SOPT1_CFG_LPTMR1SEL_MASK) /*!< SIM_SOPT1_CFG                           */
#define SIM_SOPT1_CFG_LPTMR2SEL_MASK             (0x03UL << SIM_SOPT1_CFG_LPTMR2SEL_SHIFT)           /*!< SIM_SOPT1_CFG: LPTMR2SEL Mask           */
#define SIM_SOPT1_CFG_LPTMR2SEL_SHIFT            2                                                   /*!< SIM_SOPT1_CFG: LPTMR2SEL Position       */
#define SIM_SOPT1_CFG_LPTMR2SEL(x)               (((x)<<SIM_SOPT1_CFG_LPTMR2SEL_SHIFT)&SIM_SOPT1_CFG_LPTMR2SEL_MASK) /*!< SIM_SOPT1_CFG                           */
#define SIM_SOPT1_CFG_LPTMR3SEL_MASK             (0x03UL << SIM_SOPT1_CFG_LPTMR3SEL_SHIFT)           /*!< SIM_SOPT1_CFG: LPTMR3SEL Mask           */
#define SIM_SOPT1_CFG_LPTMR3SEL_SHIFT            4                                                   /*!< SIM_SOPT1_CFG: LPTMR3SEL Position       */
#define SIM_SOPT1_CFG_LPTMR3SEL(x)               (((x)<<SIM_SOPT1_CFG_LPTMR3SEL_SHIFT)&SIM_SOPT1_CFG_LPTMR3SEL_MASK) /*!< SIM_SOPT1_CFG                           */
#define SIM_SOPT1_CFG_CMPOLPTMR0SEL_MASK         (0x01UL << SIM_SOPT1_CFG_CMPOLPTMR0SEL_SHIFT)       /*!< SIM_SOPT1_CFG: CMPOLPTMR0SEL Mask       */
#define SIM_SOPT1_CFG_CMPOLPTMR0SEL_SHIFT        6                                                   /*!< SIM_SOPT1_CFG: CMPOLPTMR0SEL Position   */
#define SIM_SOPT1_CFG_RAMSBDIS_MASK              (0x01UL << SIM_SOPT1_CFG_RAMSBDIS_SHIFT)            /*!< SIM_SOPT1_CFG: RAMSBDIS Mask            */
#define SIM_SOPT1_CFG_RAMSBDIS_SHIFT             8                                                   /*!< SIM_SOPT1_CFG: RAMSBDIS Position        */
#define SIM_SOPT1_CFG_RAMBPEN_MASK               (0x01UL << SIM_SOPT1_CFG_RAMBPEN_SHIFT)             /*!< SIM_SOPT1_CFG: RAMBPEN Mask             */
#define SIM_SOPT1_CFG_RAMBPEN_SHIFT              9                                                   /*!< SIM_SOPT1_CFG: RAMBPEN Position         */

/* ------- SIM_CTRL_REG                             ------ */
#define SIM_CTRL_REG_NMIDIS_MASK                 (0x01UL << SIM_CTRL_REG_NMIDIS_SHIFT)               /*!< SIM_CTRL_REG: NMIDIS Mask               */
#define SIM_CTRL_REG_NMIDIS_SHIFT                0                                                   /*!< SIM_CTRL_REG: NMIDIS Position           */
#define SIM_CTRL_REG_PLL_VLP_EN_MASK             (0x01UL << SIM_CTRL_REG_PLL_VLP_EN_SHIFT)           /*!< SIM_CTRL_REG: PLL_VLP_EN Mask           */
#define SIM_CTRL_REG_PLL_VLP_EN_SHIFT            1                                                   /*!< SIM_CTRL_REG: PLL_VLP_EN Position       */
#define SIM_CTRL_REG_PTC2_HD_EN_MASK             (0x01UL << SIM_CTRL_REG_PTC2_HD_EN_SHIFT)           /*!< SIM_CTRL_REG: PTC2_HD_EN Mask           */
#define SIM_CTRL_REG_PTC2_HD_EN_SHIFT            2                                                   /*!< SIM_CTRL_REG: PTC2_HD_EN Position       */
#define SIM_CTRL_REG_SAR_TRG_CLK_SEL_MASK        (0x03UL << SIM_CTRL_REG_SAR_TRG_CLK_SEL_SHIFT)      /*!< SIM_CTRL_REG: SAR_TRG_CLK_SEL Mask      */
#define SIM_CTRL_REG_SAR_TRG_CLK_SEL_SHIFT       3                                                   /*!< SIM_CTRL_REG: SAR_TRG_CLK_SEL Position  */
#define SIM_CTRL_REG_SAR_TRG_CLK_SEL(x)          (((x)<<SIM_CTRL_REG_SAR_TRG_CLK_SEL_SHIFT)&SIM_CTRL_REG_SAR_TRG_CLK_SEL_MASK) /*!< SIM_CTRL_REG                            */
#define SIM_CTRL_REG_CLKOUTSEL_MASK              (0x07UL << SIM_CTRL_REG_CLKOUTSEL_SHIFT)            /*!< SIM_CTRL_REG: CLKOUTSEL Mask            */
#define SIM_CTRL_REG_CLKOUTSEL_SHIFT             5                                                   /*!< SIM_CTRL_REG: CLKOUTSEL Position        */
#define SIM_CTRL_REG_CLKOUTSEL(x)                (((x)<<SIM_CTRL_REG_CLKOUTSEL_SHIFT)&SIM_CTRL_REG_CLKOUTSEL_MASK) /*!< SIM_CTRL_REG                            */

/* ------- SIM_SDID                                 ------ */
#define SIM_SDID_PINID_MASK                      (0x0FUL << SIM_SDID_PINID_SHIFT)                    /*!< SIM_SDID: PINID Mask                    */
#define SIM_SDID_PINID_SHIFT                     0                                                   /*!< SIM_SDID: PINID Position                */
#define SIM_SDID_PINID(x)                        (((x)<<SIM_SDID_PINID_SHIFT)&SIM_SDID_PINID_MASK)   /*!< SIM_SDID                                */
#define SIM_SDID_DIEID_MASK                      (0x0FUL << SIM_SDID_DIEID_SHIFT)                    /*!< SIM_SDID: DIEID Mask                    */
#define SIM_SDID_DIEID_SHIFT                     4                                                   /*!< SIM_SDID: DIEID Position                */
#define SIM_SDID_DIEID(x)                        (((x)<<SIM_SDID_DIEID_SHIFT)&SIM_SDID_DIEID_MASK)   /*!< SIM_SDID                                */
#define SIM_SDID_REVID_MASK                      (0x0FUL << SIM_SDID_REVID_SHIFT)                    /*!< SIM_SDID: REVID Mask                    */
#define SIM_SDID_REVID_SHIFT                     8                                                   /*!< SIM_SDID: REVID Position                */
#define SIM_SDID_REVID(x)                        (((x)<<SIM_SDID_REVID_SHIFT)&SIM_SDID_REVID_MASK)   /*!< SIM_SDID                                */
#define SIM_SDID_SRAMSIZE_MASK                   (0x0FUL << SIM_SDID_SRAMSIZE_SHIFT)                 /*!< SIM_SDID: SRAMSIZE Mask                 */
#define SIM_SDID_SRAMSIZE_SHIFT                  12                                                  /*!< SIM_SDID: SRAMSIZE Position             */
#define SIM_SDID_SRAMSIZE(x)                     (((x)<<SIM_SDID_SRAMSIZE_SHIFT)&SIM_SDID_SRAMSIZE_MASK) /*!< SIM_SDID                                */
#define SIM_SDID_ATTR_MASK                       (0x0FUL << SIM_SDID_ATTR_SHIFT)                     /*!< SIM_SDID: ATTR Mask                     */
#define SIM_SDID_ATTR_SHIFT                      16                                                  /*!< SIM_SDID: ATTR Position                 */
#define SIM_SDID_ATTR(x)                         (((x)<<SIM_SDID_ATTR_SHIFT)&SIM_SDID_ATTR_MASK)     /*!< SIM_SDID                                */
#define SIM_SDID_SERIESID_MASK                   (0x0FUL << SIM_SDID_SERIESID_SHIFT)                 /*!< SIM_SDID: SERIESID Mask                 */
#define SIM_SDID_SERIESID_SHIFT                  20                                                  /*!< SIM_SDID: SERIESID Position             */
#define SIM_SDID_SERIESID(x)                     (((x)<<SIM_SDID_SERIESID_SHIFT)&SIM_SDID_SERIESID_MASK) /*!< SIM_SDID                                */
#define SIM_SDID_SUBFAMID_MASK                   (0x0FUL << SIM_SDID_SUBFAMID_SHIFT)                 /*!< SIM_SDID: SUBFAMID Mask                 */
#define SIM_SDID_SUBFAMID_SHIFT                  24                                                  /*!< SIM_SDID: SUBFAMID Position             */
#define SIM_SDID_SUBFAMID(x)                     (((x)<<SIM_SDID_SUBFAMID_SHIFT)&SIM_SDID_SUBFAMID_MASK) /*!< SIM_SDID                                */
#define SIM_SDID_FAMID_MASK                      (0x0FUL << SIM_SDID_FAMID_SHIFT)                    /*!< SIM_SDID: FAMID Mask                    */
#define SIM_SDID_FAMID_SHIFT                     28                                                  /*!< SIM_SDID: FAMID Position                */
#define SIM_SDID_FAMID(x)                        (((x)<<SIM_SDID_FAMID_SHIFT)&SIM_SDID_FAMID_MASK)   /*!< SIM_SDID                                */

/* ------- SIM_SCGC4                                ------ */
#define SIM_SCGC4_EWM_MASK                       (0x01UL << SIM_SCGC4_EWM_SHIFT)                     /*!< SIM_SCGC4: EWM Mask                     */
#define SIM_SCGC4_EWM_SHIFT                      1                                                   /*!< SIM_SCGC4: EWM Position                 */
#define SIM_SCGC4_MCG_MASK                       (0x01UL << SIM_SCGC4_MCG_SHIFT)                     /*!< SIM_SCGC4: MCG Mask                     */
#define SIM_SCGC4_MCG_SHIFT                      4                                                   /*!< SIM_SCGC4: MCG Position                 */
#define SIM_SCGC4_OSC_MASK                       (0x01UL << SIM_SCGC4_OSC_SHIFT)                     /*!< SIM_SCGC4: OSC Mask                     */
#define SIM_SCGC4_OSC_SHIFT                      6                                                   /*!< SIM_SCGC4: OSC Position                 */
#define SIM_SCGC4_I2C0_MASK                      (0x01UL << SIM_SCGC4_I2C0_SHIFT)                    /*!< SIM_SCGC4: I2C0 Mask                    */
#define SIM_SCGC4_I2C0_SHIFT                     7                                                   /*!< SIM_SCGC4: I2C0 Position                */
#define SIM_SCGC4_I2C1_MASK                      (0x01UL << SIM_SCGC4_I2C1_SHIFT)                    /*!< SIM_SCGC4: I2C1 Mask                    */
#define SIM_SCGC4_I2C1_SHIFT                     8                                                   /*!< SIM_SCGC4: I2C1 Position                */
#define SIM_SCGC4_UART0_MASK                     (0x01UL << SIM_SCGC4_UART0_SHIFT)                   /*!< SIM_SCGC4: UART0 Mask                   */
#define SIM_SCGC4_UART0_SHIFT                    10                                                  /*!< SIM_SCGC4: UART0 Position               */
#define SIM_SCGC4_UART1_MASK                     (0x01UL << SIM_SCGC4_UART1_SHIFT)                   /*!< SIM_SCGC4: UART1 Mask                   */
#define SIM_SCGC4_UART1_SHIFT                    11                                                  /*!< SIM_SCGC4: UART1 Position               */
#define SIM_SCGC4_UART2_MASK                     (0x01UL << SIM_SCGC4_UART2_SHIFT)                   /*!< SIM_SCGC4: UART2 Mask                   */
#define SIM_SCGC4_UART2_SHIFT                    12                                                  /*!< SIM_SCGC4: UART2 Position               */
#define SIM_SCGC4_UART3_MASK                     (0x01UL << SIM_SCGC4_UART3_SHIFT)                   /*!< SIM_SCGC4: UART3 Mask                   */
#define SIM_SCGC4_UART3_SHIFT                    13                                                  /*!< SIM_SCGC4: UART3 Position               */
#define SIM_SCGC4_VREF_MASK                      (0x01UL << SIM_SCGC4_VREF_SHIFT)                    /*!< SIM_SCGC4: VREF Mask                    */
#define SIM_SCGC4_VREF_SHIFT                     15                                                  /*!< SIM_SCGC4: VREF Position                */
#define SIM_SCGC4_CMP0_MASK                      (0x01UL << SIM_SCGC4_CMP0_SHIFT)                    /*!< SIM_SCGC4: CMP0 Mask                    */
#define SIM_SCGC4_CMP0_SHIFT                     18                                                  /*!< SIM_SCGC4: CMP0 Position                */
#define SIM_SCGC4_CMP1_MASK                      (0x01UL << SIM_SCGC4_CMP1_SHIFT)                    /*!< SIM_SCGC4: CMP1 Mask                    */
#define SIM_SCGC4_CMP1_SHIFT                     19                                                  /*!< SIM_SCGC4: CMP1 Position                */
#define SIM_SCGC4_SPI0_MASK                      (0x01UL << SIM_SCGC4_SPI0_SHIFT)                    /*!< SIM_SCGC4: SPI0 Mask                    */
#define SIM_SCGC4_SPI0_SHIFT                     21                                                  /*!< SIM_SCGC4: SPI0 Position                */
#define SIM_SCGC4_SPI1_MASK                      (0x01UL << SIM_SCGC4_SPI1_SHIFT)                    /*!< SIM_SCGC4: SPI1 Mask                    */
#define SIM_SCGC4_SPI1_SHIFT                     22                                                  /*!< SIM_SCGC4: SPI1 Position                */

/* ------- SIM_SCGC5                                ------ */
#define SIM_SCGC5_SLCD_MASK                      (0x01UL << SIM_SCGC5_SLCD_SHIFT)                    /*!< SIM_SCGC5: SLCD Mask                    */
#define SIM_SCGC5_SLCD_SHIFT                     3                                                   /*!< SIM_SCGC5: SLCD Position                */
#define SIM_SCGC5_PORTA_MASK                     (0x01UL << SIM_SCGC5_PORTA_SHIFT)                   /*!< SIM_SCGC5: PORTA Mask                   */
#define SIM_SCGC5_PORTA_SHIFT                    6                                                   /*!< SIM_SCGC5: PORTA Position               */
#define SIM_SCGC5_PORTB_MASK                     (0x01UL << SIM_SCGC5_PORTB_SHIFT)                   /*!< SIM_SCGC5: PORTB Mask                   */
#define SIM_SCGC5_PORTB_SHIFT                    7                                                   /*!< SIM_SCGC5: PORTB Position               */
#define SIM_SCGC5_PORTC_MASK                     (0x01UL << SIM_SCGC5_PORTC_SHIFT)                   /*!< SIM_SCGC5: PORTC Mask                   */
#define SIM_SCGC5_PORTC_SHIFT                    8                                                   /*!< SIM_SCGC5: PORTC Position               */
#define SIM_SCGC5_PORTD_MASK                     (0x01UL << SIM_SCGC5_PORTD_SHIFT)                   /*!< SIM_SCGC5: PORTD Mask                   */
#define SIM_SCGC5_PORTD_SHIFT                    9                                                   /*!< SIM_SCGC5: PORTD Position               */
#define SIM_SCGC5_PORTE_MASK                     (0x01UL << SIM_SCGC5_PORTE_SHIFT)                   /*!< SIM_SCGC5: PORTE Mask                   */
#define SIM_SCGC5_PORTE_SHIFT                    10                                                  /*!< SIM_SCGC5: PORTE Position               */
#define SIM_SCGC5_PORTF_MASK                     (0x01UL << SIM_SCGC5_PORTF_SHIFT)                   /*!< SIM_SCGC5: PORTF Mask                   */
#define SIM_SCGC5_PORTF_SHIFT                    11                                                  /*!< SIM_SCGC5: PORTF Position               */
#define SIM_SCGC5_PORTG_MASK                     (0x01UL << SIM_SCGC5_PORTG_SHIFT)                   /*!< SIM_SCGC5: PORTG Mask                   */
#define SIM_SCGC5_PORTG_SHIFT                    12                                                  /*!< SIM_SCGC5: PORTG Position               */
#define SIM_SCGC5_PORTH_MASK                     (0x01UL << SIM_SCGC5_PORTH_SHIFT)                   /*!< SIM_SCGC5: PORTH Mask                   */
#define SIM_SCGC5_PORTH_SHIFT                    13                                                  /*!< SIM_SCGC5: PORTH Position               */
#define SIM_SCGC5_PORTI_MASK                     (0x01UL << SIM_SCGC5_PORTI_SHIFT)                   /*!< SIM_SCGC5: PORTI Mask                   */
#define SIM_SCGC5_PORTI_SHIFT                    14                                                  /*!< SIM_SCGC5: PORTI Position               */
#define SIM_SCGC5_IRTC_MASK                      (0x01UL << SIM_SCGC5_IRTC_SHIFT)                    /*!< SIM_SCGC5: IRTC Mask                    */
#define SIM_SCGC5_IRTC_SHIFT                     16                                                  /*!< SIM_SCGC5: IRTC Position                */
#define SIM_SCGC5_IRTCREGFILE_MASK               (0x01UL << SIM_SCGC5_IRTCREGFILE_SHIFT)             /*!< SIM_SCGC5: IRTCREGFILE Mask             */
#define SIM_SCGC5_IRTCREGFILE_SHIFT              17                                                  /*!< SIM_SCGC5: IRTCREGFILE Position         */
#define SIM_SCGC5_WDOG_MASK                      (0x01UL << SIM_SCGC5_WDOG_SHIFT)                    /*!< SIM_SCGC5: WDOG Mask                    */
#define SIM_SCGC5_WDOG_SHIFT                     19                                                  /*!< SIM_SCGC5: WDOG Position                */
#define SIM_SCGC5_XBAR_MASK                      (0x01UL << SIM_SCGC5_XBAR_SHIFT)                    /*!< SIM_SCGC5: XBAR Mask                    */
#define SIM_SCGC5_XBAR_SHIFT                     21                                                  /*!< SIM_SCGC5: XBAR Position                */
#define SIM_SCGC5_TMR0_MASK                      (0x01UL << SIM_SCGC5_TMR0_SHIFT)                    /*!< SIM_SCGC5: TMR0 Mask                    */
#define SIM_SCGC5_TMR0_SHIFT                     23                                                  /*!< SIM_SCGC5: TMR0 Position                */
#define SIM_SCGC5_TMR1_MASK                      (0x01UL << SIM_SCGC5_TMR1_SHIFT)                    /*!< SIM_SCGC5: TMR1 Mask                    */
#define SIM_SCGC5_TMR1_SHIFT                     24                                                  /*!< SIM_SCGC5: TMR1 Position                */
#define SIM_SCGC5_TMR2_MASK                      (0x01UL << SIM_SCGC5_TMR2_SHIFT)                    /*!< SIM_SCGC5: TMR2 Mask                    */
#define SIM_SCGC5_TMR2_SHIFT                     25                                                  /*!< SIM_SCGC5: TMR2 Position                */
#define SIM_SCGC5_TMR3_MASK                      (0x01UL << SIM_SCGC5_TMR3_SHIFT)                    /*!< SIM_SCGC5: TMR3 Mask                    */
#define SIM_SCGC5_TMR3_SHIFT                     26                                                  /*!< SIM_SCGC5: TMR3 Position                */

/* ------- SIM_SCGC6                                ------ */
#define SIM_SCGC6_FTFA_MASK                      (0x01UL << SIM_SCGC6_FTFA_SHIFT)                    /*!< SIM_SCGC6: FTFA Mask                    */
#define SIM_SCGC6_FTFA_SHIFT                     0                                                   /*!< SIM_SCGC6: FTFA Position                */
#define SIM_SCGC6_DMAMUX0_MASK                   (0x01UL << SIM_SCGC6_DMAMUX0_SHIFT)                 /*!< SIM_SCGC6: DMAMUX0 Mask                 */
#define SIM_SCGC6_DMAMUX0_SHIFT                  1                                                   /*!< SIM_SCGC6: DMAMUX0 Position             */
#define SIM_SCGC6_DMAMUX1_MASK                   (0x01UL << SIM_SCGC6_DMAMUX1_SHIFT)                 /*!< SIM_SCGC6: DMAMUX1 Mask                 */
#define SIM_SCGC6_DMAMUX1_SHIFT                  2                                                   /*!< SIM_SCGC6: DMAMUX1 Position             */
#define SIM_SCGC6_DMAMUX2_MASK                   (0x01UL << SIM_SCGC6_DMAMUX2_SHIFT)                 /*!< SIM_SCGC6: DMAMUX2 Mask                 */
#define SIM_SCGC6_DMAMUX2_SHIFT                  3                                                   /*!< SIM_SCGC6: DMAMUX2 Position             */
#define SIM_SCGC6_DMAMUX3_MASK                   (0x01UL << SIM_SCGC6_DMAMUX3_SHIFT)                 /*!< SIM_SCGC6: DMAMUX3 Mask                 */
#define SIM_SCGC6_DMAMUX3_SHIFT                  4                                                   /*!< SIM_SCGC6: DMAMUX3 Position             */
#define SIM_SCGC6_RNGA_MASK                      (0x01UL << SIM_SCGC6_RNGA_SHIFT)                    /*!< SIM_SCGC6: RNGA Mask                    */
#define SIM_SCGC6_RNGA_SHIFT                     9                                                   /*!< SIM_SCGC6: RNGA Position                */
#define SIM_SCGC6_ADC_MASK                       (0x01UL << SIM_SCGC6_ADC_SHIFT)                     /*!< SIM_SCGC6: ADC Mask                     */
#define SIM_SCGC6_ADC_SHIFT                      11                                                  /*!< SIM_SCGC6: ADC Position                 */
#define SIM_SCGC6_PIT0_MASK                      (0x01UL << SIM_SCGC6_PIT0_SHIFT)                    /*!< SIM_SCGC6: PIT0 Mask                    */
#define SIM_SCGC6_PIT0_SHIFT                     13                                                  /*!< SIM_SCGC6: PIT0 Position                */
#define SIM_SCGC6_PIT1_MASK                      (0x01UL << SIM_SCGC6_PIT1_SHIFT)                    /*!< SIM_SCGC6: PIT1 Mask                    */
#define SIM_SCGC6_PIT1_SHIFT                     14                                                  /*!< SIM_SCGC6: PIT1 Position                */
#define SIM_SCGC6_AFE_MASK                       (0x01UL << SIM_SCGC6_AFE_SHIFT)                     /*!< SIM_SCGC6: AFE Mask                     */
#define SIM_SCGC6_AFE_SHIFT                      16                                                  /*!< SIM_SCGC6: AFE Position                 */
#define SIM_SCGC6_CRC_MASK                       (0x01UL << SIM_SCGC6_CRC_SHIFT)                     /*!< SIM_SCGC6: CRC Mask                     */
#define SIM_SCGC6_CRC_SHIFT                      20                                                  /*!< SIM_SCGC6: CRC Position                 */
#define SIM_SCGC6_LPTMR_MASK                     (0x01UL << SIM_SCGC6_LPTMR_SHIFT)                   /*!< SIM_SCGC6: LPTMR Mask                   */
#define SIM_SCGC6_LPTMR_SHIFT                    28                                                  /*!< SIM_SCGC6: LPTMR Position               */
#define SIM_SCGC6_SIM_LP_MASK                    (0x01UL << SIM_SCGC6_SIM_LP_SHIFT)                  /*!< SIM_SCGC6: SIM_LP Mask                  */
#define SIM_SCGC6_SIM_LP_SHIFT                   30                                                  /*!< SIM_SCGC6: SIM_LP Position              */
#define SIM_SCGC6_SIM_HP_MASK                    (0x01UL << SIM_SCGC6_SIM_HP_SHIFT)                  /*!< SIM_SCGC6: SIM_HP Mask                  */
#define SIM_SCGC6_SIM_HP_SHIFT                   31                                                  /*!< SIM_SCGC6: SIM_HP Position              */

/* ------- SIM_SCGC7                                ------ */
#define SIM_SCGC7_MPU_MASK                       (0x01UL << SIM_SCGC7_MPU_SHIFT)                     /*!< SIM_SCGC7: MPU Mask                     */
#define SIM_SCGC7_MPU_SHIFT                      0                                                   /*!< SIM_SCGC7: MPU Position                 */
#define SIM_SCGC7_DMA_MASK                       (0x01UL << SIM_SCGC7_DMA_SHIFT)                     /*!< SIM_SCGC7: DMA Mask                     */
#define SIM_SCGC7_DMA_SHIFT                      1                                                   /*!< SIM_SCGC7: DMA Position                 */

/* ------- SIM_CLKDIV1                              ------ */
#define SIM_CLKDIV1_SYSCLKMODE_MASK              (0x01UL << SIM_CLKDIV1_SYSCLKMODE_SHIFT)            /*!< SIM_CLKDIV1: SYSCLKMODE Mask            */
#define SIM_CLKDIV1_SYSCLKMODE_SHIFT             27                                                  /*!< SIM_CLKDIV1: SYSCLKMODE Position        */
#define SIM_CLKDIV1_SYSDIV_MASK                  (0x0FUL << SIM_CLKDIV1_SYSDIV_SHIFT)                /*!< SIM_CLKDIV1: SYSDIV Mask                */
#define SIM_CLKDIV1_SYSDIV_SHIFT                 28                                                  /*!< SIM_CLKDIV1: SYSDIV Position            */
#define SIM_CLKDIV1_SYSDIV(x)                    (((x)<<SIM_CLKDIV1_SYSDIV_SHIFT)&SIM_CLKDIV1_SYSDIV_MASK) /*!< SIM_CLKDIV1                             */

/* ------- SIM_FCFG1                                ------ */
#define SIM_FCFG1_FLASHDIS_MASK                  (0x01UL << SIM_FCFG1_FLASHDIS_SHIFT)                /*!< SIM_FCFG1: FLASHDIS Mask                */
#define SIM_FCFG1_FLASHDIS_SHIFT                 0                                                   /*!< SIM_FCFG1: FLASHDIS Position            */
#define SIM_FCFG1_FLASHDOZE_MASK                 (0x01UL << SIM_FCFG1_FLASHDOZE_SHIFT)               /*!< SIM_FCFG1: FLASHDOZE Mask               */
#define SIM_FCFG1_FLASHDOZE_SHIFT                1                                                   /*!< SIM_FCFG1: FLASHDOZE Position           */
#define SIM_FCFG1_PFSIZE_MASK                    (0x0FUL << SIM_FCFG1_PFSIZE_SHIFT)                  /*!< SIM_FCFG1: PFSIZE Mask                  */
#define SIM_FCFG1_PFSIZE_SHIFT                   24                                                  /*!< SIM_FCFG1: PFSIZE Position              */
#define SIM_FCFG1_PFSIZE(x)                      (((x)<<SIM_FCFG1_PFSIZE_SHIFT)&SIM_FCFG1_PFSIZE_MASK) /*!< SIM_FCFG1                               */

/* ------- SIM_FCFG2                                ------ */
#define SIM_FCFG2_MAXADDR0_MASK                  (0x7FUL << SIM_FCFG2_MAXADDR0_SHIFT)                /*!< SIM_FCFG2: MAXADDR0 Mask                */
#define SIM_FCFG2_MAXADDR0_SHIFT                 24                                                  /*!< SIM_FCFG2: MAXADDR0 Position            */
#define SIM_FCFG2_MAXADDR0(x)                    (((x)<<SIM_FCFG2_MAXADDR0_SHIFT)&SIM_FCFG2_MAXADDR0_MASK) /*!< SIM_FCFG2                               */

/* ------- SIM_UID                                  ------ */
#define SIM_UID_UID_MASK                         (0xFFFFFFFFUL << SIM_UID_UID_SHIFT)                 /*!< SIM_UID: UID Mask                       */
#define SIM_UID_UID_SHIFT                        0                                                   /*!< SIM_UID: UID Position                   */
#define SIM_UID_UID(x)                           (((x)<<SIM_UID_UID_SHIFT)&SIM_UID_UID_MASK)         /*!< SIM_UID                                 */

/* ------- SIM_MISC_CTL                             ------ */
#define SIM_MISC_CTL_XBARAFEMODOUTSEL_MASK       (0x03UL << SIM_MISC_CTL_XBARAFEMODOUTSEL_SHIFT)     /*!< SIM_MISC_CTL: XBARAFEMODOUTSEL Mask     */
#define SIM_MISC_CTL_XBARAFEMODOUTSEL_SHIFT      0                                                   /*!< SIM_MISC_CTL: XBARAFEMODOUTSEL Position */
#define SIM_MISC_CTL_XBARAFEMODOUTSEL(x)         (((x)<<SIM_MISC_CTL_XBARAFEMODOUTSEL_SHIFT)&SIM_MISC_CTL_XBARAFEMODOUTSEL_MASK) /*!< SIM_MISC_CTL                            */
#define SIM_MISC_CTL_DMADONESEL_MASK             (0x03UL << SIM_MISC_CTL_DMADONESEL_SHIFT)           /*!< SIM_MISC_CTL: DMADONESEL Mask           */
#define SIM_MISC_CTL_DMADONESEL_SHIFT            2                                                   /*!< SIM_MISC_CTL: DMADONESEL Position       */
#define SIM_MISC_CTL_DMADONESEL(x)               (((x)<<SIM_MISC_CTL_DMADONESEL_SHIFT)&SIM_MISC_CTL_DMADONESEL_MASK) /*!< SIM_MISC_CTL                            */
#define SIM_MISC_CTL_AFECLKSEL_MASK              (0x03UL << SIM_MISC_CTL_AFECLKSEL_SHIFT)            /*!< SIM_MISC_CTL: AFECLKSEL Mask            */
#define SIM_MISC_CTL_AFECLKSEL_SHIFT             4                                                   /*!< SIM_MISC_CTL: AFECLKSEL Position        */
#define SIM_MISC_CTL_AFECLKSEL(x)                (((x)<<SIM_MISC_CTL_AFECLKSEL_SHIFT)&SIM_MISC_CTL_AFECLKSEL_MASK) /*!< SIM_MISC_CTL                            */
#define SIM_MISC_CTL_AFECLKPADDIR_MASK           (0x01UL << SIM_MISC_CTL_AFECLKPADDIR_SHIFT)         /*!< SIM_MISC_CTL: AFECLKPADDIR Mask         */
#define SIM_MISC_CTL_AFECLKPADDIR_SHIFT          6                                                   /*!< SIM_MISC_CTL: AFECLKPADDIR Position     */
#define SIM_MISC_CTL_UARTMODTYPE_MASK            (0x01UL << SIM_MISC_CTL_UARTMODTYPE_SHIFT)          /*!< SIM_MISC_CTL: UARTMODTYPE Mask          */
#define SIM_MISC_CTL_UARTMODTYPE_SHIFT           7                                                   /*!< SIM_MISC_CTL: UARTMODTYPE Position      */
#define SIM_MISC_CTL_UART0IRSEL_MASK             (0x01UL << SIM_MISC_CTL_UART0IRSEL_SHIFT)           /*!< SIM_MISC_CTL: UART0IRSEL Mask           */
#define SIM_MISC_CTL_UART0IRSEL_SHIFT            8                                                   /*!< SIM_MISC_CTL: UART0IRSEL Position       */
#define SIM_MISC_CTL_UART1IRSEL_MASK             (0x01UL << SIM_MISC_CTL_UART1IRSEL_SHIFT)           /*!< SIM_MISC_CTL: UART1IRSEL Mask           */
#define SIM_MISC_CTL_UART1IRSEL_SHIFT            9                                                   /*!< SIM_MISC_CTL: UART1IRSEL Position       */
#define SIM_MISC_CTL_UART2IRSEL_MASK             (0x01UL << SIM_MISC_CTL_UART2IRSEL_SHIFT)           /*!< SIM_MISC_CTL: UART2IRSEL Mask           */
#define SIM_MISC_CTL_UART2IRSEL_SHIFT            10                                                  /*!< SIM_MISC_CTL: UART2IRSEL Position       */
#define SIM_MISC_CTL_UART3IRSEL_MASK             (0x01UL << SIM_MISC_CTL_UART3IRSEL_SHIFT)           /*!< SIM_MISC_CTL: UART3IRSEL Mask           */
#define SIM_MISC_CTL_UART3IRSEL_SHIFT            11                                                  /*!< SIM_MISC_CTL: UART3IRSEL Position       */
#define SIM_MISC_CTL_XBARPITOUTSEL_MASK          (0x03UL << SIM_MISC_CTL_XBARPITOUTSEL_SHIFT)        /*!< SIM_MISC_CTL: XBARPITOUTSEL Mask        */
#define SIM_MISC_CTL_XBARPITOUTSEL_SHIFT         12                                                  /*!< SIM_MISC_CTL: XBARPITOUTSEL Position    */
#define SIM_MISC_CTL_XBARPITOUTSEL(x)            (((x)<<SIM_MISC_CTL_XBARPITOUTSEL_SHIFT)&SIM_MISC_CTL_XBARPITOUTSEL_MASK) /*!< SIM_MISC_CTL                            */
#define SIM_MISC_CTL_EWMINSEL_MASK               (0x01UL << SIM_MISC_CTL_EWMINSEL_SHIFT)             /*!< SIM_MISC_CTL: EWMINSEL Mask             */
#define SIM_MISC_CTL_EWMINSEL_SHIFT              14                                                  /*!< SIM_MISC_CTL: EWMINSEL Position         */
#define SIM_MISC_CTL_TMR0PLLCLKSEL_MASK          (0x01UL << SIM_MISC_CTL_TMR0PLLCLKSEL_SHIFT)        /*!< SIM_MISC_CTL: TMR0PLLCLKSEL Mask        */
#define SIM_MISC_CTL_TMR0PLLCLKSEL_SHIFT         15                                                  /*!< SIM_MISC_CTL: TMR0PLLCLKSEL Position    */
#define SIM_MISC_CTL_TMR0SCSSEL_MASK             (0x01UL << SIM_MISC_CTL_TMR0SCSSEL_SHIFT)           /*!< SIM_MISC_CTL: TMR0SCSSEL Mask           */
#define SIM_MISC_CTL_TMR0SCSSEL_SHIFT            16                                                  /*!< SIM_MISC_CTL: TMR0SCSSEL Position       */
#define SIM_MISC_CTL_TMR1SCSSEL_MASK             (0x01UL << SIM_MISC_CTL_TMR1SCSSEL_SHIFT)           /*!< SIM_MISC_CTL: TMR1SCSSEL Mask           */
#define SIM_MISC_CTL_TMR1SCSSEL_SHIFT            17                                                  /*!< SIM_MISC_CTL: TMR1SCSSEL Position       */
#define SIM_MISC_CTL_TMR2SCSSEL_MASK             (0x01UL << SIM_MISC_CTL_TMR2SCSSEL_SHIFT)           /*!< SIM_MISC_CTL: TMR2SCSSEL Mask           */
#define SIM_MISC_CTL_TMR2SCSSEL_SHIFT            18                                                  /*!< SIM_MISC_CTL: TMR2SCSSEL Position       */
#define SIM_MISC_CTL_TMR3SCSSEL_MASK             (0x01UL << SIM_MISC_CTL_TMR3SCSSEL_SHIFT)           /*!< SIM_MISC_CTL: TMR3SCSSEL Mask           */
#define SIM_MISC_CTL_TMR3SCSSEL_SHIFT            19                                                  /*!< SIM_MISC_CTL: TMR3SCSSEL Position       */
#define SIM_MISC_CTL_TMR0PCSSEL_MASK             (0x03UL << SIM_MISC_CTL_TMR0PCSSEL_SHIFT)           /*!< SIM_MISC_CTL: TMR0PCSSEL Mask           */
#define SIM_MISC_CTL_TMR0PCSSEL_SHIFT            20                                                  /*!< SIM_MISC_CTL: TMR0PCSSEL Position       */
#define SIM_MISC_CTL_TMR0PCSSEL(x)               (((x)<<SIM_MISC_CTL_TMR0PCSSEL_SHIFT)&SIM_MISC_CTL_TMR0PCSSEL_MASK) /*!< SIM_MISC_CTL                            */
#define SIM_MISC_CTL_TMR1PCSSEL_MASK             (0x03UL << SIM_MISC_CTL_TMR1PCSSEL_SHIFT)           /*!< SIM_MISC_CTL: TMR1PCSSEL Mask           */
#define SIM_MISC_CTL_TMR1PCSSEL_SHIFT            22                                                  /*!< SIM_MISC_CTL: TMR1PCSSEL Position       */
#define SIM_MISC_CTL_TMR1PCSSEL(x)               (((x)<<SIM_MISC_CTL_TMR1PCSSEL_SHIFT)&SIM_MISC_CTL_TMR1PCSSEL_MASK) /*!< SIM_MISC_CTL                            */
#define SIM_MISC_CTL_TMR2PCSSEL_MASK             (0x03UL << SIM_MISC_CTL_TMR2PCSSEL_SHIFT)           /*!< SIM_MISC_CTL: TMR2PCSSEL Mask           */
#define SIM_MISC_CTL_TMR2PCSSEL_SHIFT            24                                                  /*!< SIM_MISC_CTL: TMR2PCSSEL Position       */
#define SIM_MISC_CTL_TMR2PCSSEL(x)               (((x)<<SIM_MISC_CTL_TMR2PCSSEL_SHIFT)&SIM_MISC_CTL_TMR2PCSSEL_MASK) /*!< SIM_MISC_CTL                            */
#define SIM_MISC_CTL_TMR3PCSSEL_MASK             (0x03UL << SIM_MISC_CTL_TMR3PCSSEL_SHIFT)           /*!< SIM_MISC_CTL: TMR3PCSSEL Mask           */
#define SIM_MISC_CTL_TMR3PCSSEL_SHIFT            26                                                  /*!< SIM_MISC_CTL: TMR3PCSSEL Position       */
#define SIM_MISC_CTL_TMR3PCSSEL(x)               (((x)<<SIM_MISC_CTL_TMR3PCSSEL_SHIFT)&SIM_MISC_CTL_TMR3PCSSEL_MASK) /*!< SIM_MISC_CTL                            */
#define SIM_MISC_CTL_RTCCLKSEL_MASK              (0x01UL << SIM_MISC_CTL_RTCCLKSEL_SHIFT)            /*!< SIM_MISC_CTL: RTCCLKSEL Mask            */
#define SIM_MISC_CTL_RTCCLKSEL_SHIFT             28                                                  /*!< SIM_MISC_CTL: RTCCLKSEL Position        */
#define SIM_MISC_CTL_VREFBUFOUTEN_MASK           (0x01UL << SIM_MISC_CTL_VREFBUFOUTEN_SHIFT)         /*!< SIM_MISC_CTL: VREFBUFOUTEN Mask         */
#define SIM_MISC_CTL_VREFBUFOUTEN_SHIFT          29                                                  /*!< SIM_MISC_CTL: VREFBUFOUTEN Position     */
#define SIM_MISC_CTL_VREFBUFINSEL_MASK           (0x01UL << SIM_MISC_CTL_VREFBUFINSEL_SHIFT)         /*!< SIM_MISC_CTL: VREFBUFINSEL Mask         */
#define SIM_MISC_CTL_VREFBUFINSEL_SHIFT          30                                                  /*!< SIM_MISC_CTL: VREFBUFINSEL Position     */
#define SIM_MISC_CTL_VREFBUFPD_MASK              (0x01UL << SIM_MISC_CTL_VREFBUFPD_SHIFT)            /*!< SIM_MISC_CTL: VREFBUFPD Mask            */
#define SIM_MISC_CTL_VREFBUFPD_SHIFT             31                                                  /*!< SIM_MISC_CTL: VREFBUFPD Position        */

/* -------------------------------------------------------------------------------- */
/* -----------     'SIM' Register Access macros                         ----------- */
/* -------------------------------------------------------------------------------- */

#define SIM_SOPT1                      (SIM->SOPT1)
#define SIM_SOPT1_CFG                  (SIM->SOPT1_CFG)
#define SIM_CTRL_REG                   (SIM->CTRL_REG)
#define SIM_SDID                       (SIM->SDID)
#define SIM_SCGC4                      (SIM->SCGC4)
#define SIM_SCGC5                      (SIM->SCGC5)
#define SIM_SCGC6                      (SIM->SCGC6)
#define SIM_SCGC7                      (SIM->SCGC7)
#define SIM_CLKDIV1                    (SIM->CLKDIV1)
#define SIM_FCFG1                      (SIM->FCFG1)
#define SIM_FCFG2                      (SIM->FCFG2)
#define SIM_UID0                       (SIM->UID[0])
#define SIM_UID1                       (SIM->UID[1])
#define SIM_UID2                       (SIM->UID[2])
#define SIM_UID3                       (SIM->UID[3])
#define SIM_MISC_CTL                   (SIM->MISC_CTL)

/* ================================================================================ */
/* ================           SMC (file:SMC_MKM)                   ================ */
/* ================================================================================ */

/**
 * @brief System Mode Controller
 */
typedef struct {                                /*!<       SMC Structure                                                */
   __IO uint8_t   PMPROT;                       /*!< 0000: Power Mode Protection Register                               */
   __IO uint8_t   PMCTRL;                       /*!< 0001: Power Mode Control Register                                  */
   __IO uint8_t   STOPCTRL;                     /*!< 0002: Stop Control Register                                        */
   __I  uint8_t   PMSTAT;                       /*!< 0003: Power Mode Status Register                                   */
} SMC_Type;


/* -------------------------------------------------------------------------------- */
/* -----------     'SMC' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */


/* ------- SMC_PMPROT                               ------ */
#define SMC_PMPROT_AVLLS_MASK                    (0x01UL << SMC_PMPROT_AVLLS_SHIFT)                  /*!< SMC_PMPROT: AVLLS Mask                  */
#define SMC_PMPROT_AVLLS_SHIFT                   1                                                   /*!< SMC_PMPROT: AVLLS Position              */
#define SMC_PMPROT_AVLP_MASK                     (0x01UL << SMC_PMPROT_AVLP_SHIFT)                   /*!< SMC_PMPROT: AVLP Mask                   */
#define SMC_PMPROT_AVLP_SHIFT                    5                                                   /*!< SMC_PMPROT: AVLP Position               */

/* ------- SMC_PMCTRL                               ------ */
#define SMC_PMCTRL_STOPM_MASK                    (0x07UL << SMC_PMCTRL_STOPM_SHIFT)                  /*!< SMC_PMCTRL: STOPM Mask                  */
#define SMC_PMCTRL_STOPM_SHIFT                   0                                                   /*!< SMC_PMCTRL: STOPM Position              */
#define SMC_PMCTRL_STOPM(x)                      (((x)<<SMC_PMCTRL_STOPM_SHIFT)&SMC_PMCTRL_STOPM_MASK) /*!< SMC_PMCTRL                              */
#define SMC_PMCTRL_STOPA_MASK                    (0x01UL << SMC_PMCTRL_STOPA_SHIFT)                  /*!< SMC_PMCTRL: STOPA Mask                  */
#define SMC_PMCTRL_STOPA_SHIFT                   3                                                   /*!< SMC_PMCTRL: STOPA Position              */
#define SMC_PMCTRL_RUNM_MASK                     (0x03UL << SMC_PMCTRL_RUNM_SHIFT)                   /*!< SMC_PMCTRL: RUNM Mask                   */
#define SMC_PMCTRL_RUNM_SHIFT                    5                                                   /*!< SMC_PMCTRL: RUNM Position               */
#define SMC_PMCTRL_RUNM(x)                       (((x)<<SMC_PMCTRL_RUNM_SHIFT)&SMC_PMCTRL_RUNM_MASK) /*!< SMC_PMCTRL                              */

/* ------- SMC_STOPCTRL                             ------ */
#define SMC_STOPCTRL_VLLSM_MASK                  (0x07UL << SMC_STOPCTRL_VLLSM_SHIFT)                /*!< SMC_STOPCTRL: VLLSM Mask                */
#define SMC_STOPCTRL_VLLSM_SHIFT                 0                                                   /*!< SMC_STOPCTRL: VLLSM Position            */
#define SMC_STOPCTRL_VLLSM(x)                    (((x)<<SMC_STOPCTRL_VLLSM_SHIFT)&SMC_STOPCTRL_VLLSM_MASK) /*!< SMC_STOPCTRL                            */
#define SMC_STOPCTRL_PORPO_MASK                  (0x01UL << SMC_STOPCTRL_PORPO_SHIFT)                /*!< SMC_STOPCTRL: PORPO Mask                */
#define SMC_STOPCTRL_PORPO_SHIFT                 5                                                   /*!< SMC_STOPCTRL: PORPO Position            */
#define SMC_STOPCTRL_PSTOPO_MASK                 (0x03UL << SMC_STOPCTRL_PSTOPO_SHIFT)               /*!< SMC_STOPCTRL: PSTOPO Mask               */
#define SMC_STOPCTRL_PSTOPO_SHIFT                6                                                   /*!< SMC_STOPCTRL: PSTOPO Position           */
#define SMC_STOPCTRL_PSTOPO(x)                   (((x)<<SMC_STOPCTRL_PSTOPO_SHIFT)&SMC_STOPCTRL_PSTOPO_MASK) /*!< SMC_STOPCTRL                            */

/* ------- SMC_PMSTAT                               ------ */
#define SMC_PMSTAT_PMSTAT_MASK                   (0x7FUL << SMC_PMSTAT_PMSTAT_SHIFT)                 /*!< SMC_PMSTAT: PMSTAT Mask                 */
#define SMC_PMSTAT_PMSTAT_SHIFT                  0                                                   /*!< SMC_PMSTAT: PMSTAT Position             */
#define SMC_PMSTAT_PMSTAT(x)                     (((x)<<SMC_PMSTAT_PMSTAT_SHIFT)&SMC_PMSTAT_PMSTAT_MASK) /*!< SMC_PMSTAT                              */

/* -------------------------------------------------------------------------------- */
/* -----------     'SMC' Register Access macros                         ----------- */
/* -------------------------------------------------------------------------------- */

#define SMC_PMPROT                     (SMC->PMPROT)
#define SMC_PMCTRL                     (SMC->PMCTRL)
#define SMC_STOPCTRL                   (SMC->STOPCTRL)
#define SMC_PMSTAT                     (SMC->PMSTAT)

/* ================================================================================ */
/* ================           SPI0 (file:SPI0_MKM)                 ================ */
/* ================================================================================ */

/**
 * @brief Serial Peripheral Interface
 */
typedef struct {                                /*!<       SPI0 Structure                                               */
   __I  uint8_t   S;                            /*!< 0000: SPI status register                                          */
   __IO uint8_t   BR;                           /*!< 0001: SPI baud rate register                                       */
   __IO uint8_t   C2;                           /*!< 0002: SPI control register 2                                       */
   __IO uint8_t   C1;                           /*!< 0003: SPI control register 1                                       */
   __IO uint8_t   ML;                           /*!< 0004: SPI match register low                                       */
   __IO uint8_t   MH;                           /*!< 0005: SPI match register high                                      */
   __IO uint8_t   DL;                           /*!< 0006: SPI data register low                                        */
   __IO uint8_t   DH;                           /*!< 0007: SPI data register high                                       */
} SPI0_Type;


/* -------------------------------------------------------------------------------- */
/* -----------     'SPI0' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */


/* ------- SPI0_S                                   ------ */
#define SPI_S_RFIFOEF_MASK                       (0x01UL << SPI_S_RFIFOEF_SHIFT)                     /*!< SPI0_S: RFIFOEF Mask                    */
#define SPI_S_RFIFOEF_SHIFT                      0                                                   /*!< SPI0_S: RFIFOEF Position                */
#define SPI_S_TXFULLF_MASK                       (0x01UL << SPI_S_TXFULLF_SHIFT)                     /*!< SPI0_S: TXFULLF Mask                    */
#define SPI_S_TXFULLF_SHIFT                      1                                                   /*!< SPI0_S: TXFULLF Position                */
#define SPI_S_TNEAREF_MASK                       (0x01UL << SPI_S_TNEAREF_SHIFT)                     /*!< SPI0_S: TNEAREF Mask                    */
#define SPI_S_TNEAREF_SHIFT                      2                                                   /*!< SPI0_S: TNEAREF Position                */
#define SPI_S_RNFULLF_MASK                       (0x01UL << SPI_S_RNFULLF_SHIFT)                     /*!< SPI0_S: RNFULLF Mask                    */
#define SPI_S_RNFULLF_SHIFT                      3                                                   /*!< SPI0_S: RNFULLF Position                */
#define SPI_S_MODF_MASK                          (0x01UL << SPI_S_MODF_SHIFT)                        /*!< SPI0_S: MODF Mask                       */
#define SPI_S_MODF_SHIFT                         4                                                   /*!< SPI0_S: MODF Position                   */
#define SPI_S_SPTEF_MASK                         (0x01UL << SPI_S_SPTEF_SHIFT)                       /*!< SPI0_S: SPTEF Mask                      */
#define SPI_S_SPTEF_SHIFT                        5                                                   /*!< SPI0_S: SPTEF Position                  */
#define SPI_S_SPMF_MASK                          (0x01UL << SPI_S_SPMF_SHIFT)                        /*!< SPI0_S: SPMF Mask                       */
#define SPI_S_SPMF_SHIFT                         6                                                   /*!< SPI0_S: SPMF Position                   */
#define SPI_S_SPRF_MASK                          (0x01UL << SPI_S_SPRF_SHIFT)                        /*!< SPI0_S: SPRF Mask                       */
#define SPI_S_SPRF_SHIFT                         7                                                   /*!< SPI0_S: SPRF Position                   */

/* ------- SPI0_BR                                  ------ */
#define SPI_BR_SPR_MASK                          (0x0FUL << SPI_BR_SPR_SHIFT)                        /*!< SPI0_BR: SPR Mask                       */
#define SPI_BR_SPR_SHIFT                         0                                                   /*!< SPI0_BR: SPR Position                   */
#define SPI_BR_SPR(x)                            (((x)<<SPI_BR_SPR_SHIFT)&SPI_BR_SPR_MASK)           /*!< SPI0_BR                                 */
#define SPI_BR_SPPR_MASK                         (0x07UL << SPI_BR_SPPR_SHIFT)                       /*!< SPI0_BR: SPPR Mask                      */
#define SPI_BR_SPPR_SHIFT                        4                                                   /*!< SPI0_BR: SPPR Position                  */
#define SPI_BR_SPPR(x)                           (((x)<<SPI_BR_SPPR_SHIFT)&SPI_BR_SPPR_MASK)         /*!< SPI0_BR                                 */

/* ------- SPI0_C2                                  ------ */
#define SPI_C2_SPC0_MASK                         (0x01UL << SPI_C2_SPC0_SHIFT)                       /*!< SPI0_C2: SPC0 Mask                      */
#define SPI_C2_SPC0_SHIFT                        0                                                   /*!< SPI0_C2: SPC0 Position                  */
#define SPI_C2_SPISWAI_MASK                      (0x01UL << SPI_C2_SPISWAI_SHIFT)                    /*!< SPI0_C2: SPISWAI Mask                   */
#define SPI_C2_SPISWAI_SHIFT                     1                                                   /*!< SPI0_C2: SPISWAI Position               */
#define SPI_C2_RXDMAE_MASK                       (0x01UL << SPI_C2_RXDMAE_SHIFT)                     /*!< SPI0_C2: RXDMAE Mask                    */
#define SPI_C2_RXDMAE_SHIFT                      2                                                   /*!< SPI0_C2: RXDMAE Position                */
#define SPI_C2_BIDIROE_MASK                      (0x01UL << SPI_C2_BIDIROE_SHIFT)                    /*!< SPI0_C2: BIDIROE Mask                   */
#define SPI_C2_BIDIROE_SHIFT                     3                                                   /*!< SPI0_C2: BIDIROE Position               */
#define SPI_C2_MODFEN_MASK                       (0x01UL << SPI_C2_MODFEN_SHIFT)                     /*!< SPI0_C2: MODFEN Mask                    */
#define SPI_C2_MODFEN_SHIFT                      4                                                   /*!< SPI0_C2: MODFEN Position                */
#define SPI_C2_TXDMAE_MASK                       (0x01UL << SPI_C2_TXDMAE_SHIFT)                     /*!< SPI0_C2: TXDMAE Mask                    */
#define SPI_C2_TXDMAE_SHIFT                      5                                                   /*!< SPI0_C2: TXDMAE Position                */
#define SPI_C2_SPIMODE_MASK                      (0x01UL << SPI_C2_SPIMODE_SHIFT)                    /*!< SPI0_C2: SPIMODE Mask                   */
#define SPI_C2_SPIMODE_SHIFT                     6                                                   /*!< SPI0_C2: SPIMODE Position               */
#define SPI_C2_SPMIE_MASK                        (0x01UL << SPI_C2_SPMIE_SHIFT)                      /*!< SPI0_C2: SPMIE Mask                     */
#define SPI_C2_SPMIE_SHIFT                       7                                                   /*!< SPI0_C2: SPMIE Position                 */

/* ------- SPI0_C1                                  ------ */
#define SPI_C1_LSBFE_MASK                        (0x01UL << SPI_C1_LSBFE_SHIFT)                      /*!< SPI0_C1: LSBFE Mask                     */
#define SPI_C1_LSBFE_SHIFT                       0                                                   /*!< SPI0_C1: LSBFE Position                 */
#define SPI_C1_SSOE_MASK                         (0x01UL << SPI_C1_SSOE_SHIFT)                       /*!< SPI0_C1: SSOE Mask                      */
#define SPI_C1_SSOE_SHIFT                        1                                                   /*!< SPI0_C1: SSOE Position                  */
#define SPI_C1_CPHA_MASK                         (0x01UL << SPI_C1_CPHA_SHIFT)                       /*!< SPI0_C1: CPHA Mask                      */
#define SPI_C1_CPHA_SHIFT                        2                                                   /*!< SPI0_C1: CPHA Position                  */
#define SPI_C1_CPOL_MASK                         (0x01UL << SPI_C1_CPOL_SHIFT)                       /*!< SPI0_C1: CPOL Mask                      */
#define SPI_C1_CPOL_SHIFT                        3                                                   /*!< SPI0_C1: CPOL Position                  */
#define SPI_C1_MSTR_MASK                         (0x01UL << SPI_C1_MSTR_SHIFT)                       /*!< SPI0_C1: MSTR Mask                      */
#define SPI_C1_MSTR_SHIFT                        4                                                   /*!< SPI0_C1: MSTR Position                  */
#define SPI_C1_SPTIE_MASK                        (0x01UL << SPI_C1_SPTIE_SHIFT)                      /*!< SPI0_C1: SPTIE Mask                     */
#define SPI_C1_SPTIE_SHIFT                       5                                                   /*!< SPI0_C1: SPTIE Position                 */
#define SPI_C1_SPE_MASK                          (0x01UL << SPI_C1_SPE_SHIFT)                        /*!< SPI0_C1: SPE Mask                       */
#define SPI_C1_SPE_SHIFT                         6                                                   /*!< SPI0_C1: SPE Position                   */
#define SPI_C1_SPIE_MASK                         (0x01UL << SPI_C1_SPIE_SHIFT)                       /*!< SPI0_C1: SPIE Mask                      */
#define SPI_C1_SPIE_SHIFT                        7                                                   /*!< SPI0_C1: SPIE Position                  */

/* ------- SPI0_ML                                  ------ */
#define SPI_ML_Bits_MASK                         (0xFFUL << SPI_ML_Bits_SHIFT)                       /*!< SPI0_ML: Bits Mask                      */
#define SPI_ML_Bits_SHIFT                        0                                                   /*!< SPI0_ML: Bits Position                  */
#define SPI_ML_Bits(x)                           (((x)<<SPI_ML_Bits_SHIFT)&SPI_ML_Bits_MASK)         /*!< SPI0_ML                                 */

/* ------- SPI0_MH                                  ------ */
#define SPI_MH_Bits_MASK                         (0xFFUL << SPI_MH_Bits_SHIFT)                       /*!< SPI0_MH: Bits Mask                      */
#define SPI_MH_Bits_SHIFT                        0                                                   /*!< SPI0_MH: Bits Position                  */
#define SPI_MH_Bits(x)                           (((x)<<SPI_MH_Bits_SHIFT)&SPI_MH_Bits_MASK)         /*!< SPI0_MH                                 */

/* ------- SPI0_DL                                  ------ */
#define SPI_DL_Bits_MASK                         (0xFFUL << SPI_DL_Bits_SHIFT)                       /*!< SPI0_DL: Bits Mask                      */
#define SPI_DL_Bits_SHIFT                        0                                                   /*!< SPI0_DL: Bits Position                  */
#define SPI_DL_Bits(x)                           (((x)<<SPI_DL_Bits_SHIFT)&SPI_DL_Bits_MASK)         /*!< SPI0_DL                                 */

/* ------- SPI0_DH                                  ------ */
#define SPI_DH_Bits_MASK                         (0xFFUL << SPI_DH_Bits_SHIFT)                       /*!< SPI0_DH: Bits Mask                      */
#define SPI_DH_Bits_SHIFT                        0                                                   /*!< SPI0_DH: Bits Position                  */
#define SPI_DH_Bits(x)                           (((x)<<SPI_DH_Bits_SHIFT)&SPI_DH_Bits_MASK)         /*!< SPI0_DH                                 */

/* -------------------------------------------------------------------------------- */
/* -----------     'SPI0' Register Access macros                        ----------- */
/* -------------------------------------------------------------------------------- */

#define SPI0_S                         (SPI0->S)
#define SPI0_BR                        (SPI0->BR)
#define SPI0_C2                        (SPI0->C2)
#define SPI0_C1                        (SPI0->C1)
#define SPI0_ML                        (SPI0->ML)
#define SPI0_MH                        (SPI0->MH)
#define SPI0_DL                        (SPI0->DL)
#define SPI0_DH                        (SPI0->DH)

/* ================================================================================ */
/* ================           SPI1 (file:SPI1_MKM_FIFO)            ================ */
/* ================================================================================ */

/**
 * @brief Serial Peripheral Interface
 */
typedef struct {                                /*!<       SPI1 Structure                                               */
   __I  uint8_t   S;                            /*!< 0000: SPI status register                                          */
   __IO uint8_t   BR;                           /*!< 0001: SPI baud rate register                                       */
   __IO uint8_t   C2;                           /*!< 0002: SPI control register 2                                       */
   __IO uint8_t   C1;                           /*!< 0003: SPI control register 1                                       */
   __IO uint8_t   ML;                           /*!< 0004: SPI match register low                                       */
   __IO uint8_t   MH;                           /*!< 0005: SPI match register high                                      */
   __IO uint8_t   DL;                           /*!< 0006: SPI data register low                                        */
   __IO uint8_t   DH;                           /*!< 0007: SPI data register high                                       */
   __I  uint16_t  RESERVED0;                    /*!< 0008:                                                              */
   __IO uint8_t   CI;                           /*!< 000A: SPI clear interrupt register                                 */
   __IO uint8_t   C3;                           /*!< 000B: SPI control register 3                                       */
} SPI1_Type;


/* -------------------------------------------------------------------------------- */
/* -----------     'SPI1' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */


/* ------- SPI1_S                                   ------ */

/* ------- SPI1_BR                                  ------ */

/* ------- SPI1_C2                                  ------ */

/* ------- SPI1_C1                                  ------ */

/* ------- SPI1_ML                                  ------ */

/* ------- SPI1_MH                                  ------ */

/* ------- SPI1_DL                                  ------ */

/* ------- SPI1_DH                                  ------ */

/* ------- SPI1_CI                                  ------ */
#define SPI_CI_SPRFCI_MASK                       (0x01UL << SPI_CI_SPRFCI_SHIFT)                     /*!< SPI1_CI: SPRFCI Mask                    */
#define SPI_CI_SPRFCI_SHIFT                      0                                                   /*!< SPI1_CI: SPRFCI Position                */
#define SPI_CI_SPTEFCI_MASK                      (0x01UL << SPI_CI_SPTEFCI_SHIFT)                    /*!< SPI1_CI: SPTEFCI Mask                   */
#define SPI_CI_SPTEFCI_SHIFT                     1                                                   /*!< SPI1_CI: SPTEFCI Position               */
#define SPI_CI_RNFULLFCI_MASK                    (0x01UL << SPI_CI_RNFULLFCI_SHIFT)                  /*!< SPI1_CI: RNFULLFCI Mask                 */
#define SPI_CI_RNFULLFCI_SHIFT                   2                                                   /*!< SPI1_CI: RNFULLFCI Position             */
#define SPI_CI_TNEAREFCI_MASK                    (0x01UL << SPI_CI_TNEAREFCI_SHIFT)                  /*!< SPI1_CI: TNEAREFCI Mask                 */
#define SPI_CI_TNEAREFCI_SHIFT                   3                                                   /*!< SPI1_CI: TNEAREFCI Position             */
#define SPI_CI_RXFOF_MASK                        (0x01UL << SPI_CI_RXFOF_SHIFT)                      /*!< SPI1_CI: RXFOF Mask                     */
#define SPI_CI_RXFOF_SHIFT                       4                                                   /*!< SPI1_CI: RXFOF Position                 */
#define SPI_CI_TXFOF_MASK                        (0x01UL << SPI_CI_TXFOF_SHIFT)                      /*!< SPI1_CI: TXFOF Mask                     */
#define SPI_CI_TXFOF_SHIFT                       5                                                   /*!< SPI1_CI: TXFOF Position                 */
#define SPI_CI_RXFERR_MASK                       (0x01UL << SPI_CI_RXFERR_SHIFT)                     /*!< SPI1_CI: RXFERR Mask                    */
#define SPI_CI_RXFERR_SHIFT                      6                                                   /*!< SPI1_CI: RXFERR Position                */
#define SPI_CI_TXFERR_MASK                       (0x01UL << SPI_CI_TXFERR_SHIFT)                     /*!< SPI1_CI: TXFERR Mask                    */
#define SPI_CI_TXFERR_SHIFT                      7                                                   /*!< SPI1_CI: TXFERR Position                */

/* ------- SPI1_C3                                  ------ */
#define SPI_C3_FIFOMODE_MASK                     (0x01UL << SPI_C3_FIFOMODE_SHIFT)                   /*!< SPI1_C3: FIFOMODE Mask                  */
#define SPI_C3_FIFOMODE_SHIFT                    0                                                   /*!< SPI1_C3: FIFOMODE Position              */
#define SPI_C3_RNFULLIEN_MASK                    (0x01UL << SPI_C3_RNFULLIEN_SHIFT)                  /*!< SPI1_C3: RNFULLIEN Mask                 */
#define SPI_C3_RNFULLIEN_SHIFT                   1                                                   /*!< SPI1_C3: RNFULLIEN Position             */
#define SPI_C3_TNEARIEN_MASK                     (0x01UL << SPI_C3_TNEARIEN_SHIFT)                   /*!< SPI1_C3: TNEARIEN Mask                  */
#define SPI_C3_TNEARIEN_SHIFT                    2                                                   /*!< SPI1_C3: TNEARIEN Position              */
#define SPI_C3_INTCLR_MASK                       (0x01UL << SPI_C3_INTCLR_SHIFT)                     /*!< SPI1_C3: INTCLR Mask                    */
#define SPI_C3_INTCLR_SHIFT                      3                                                   /*!< SPI1_C3: INTCLR Position                */
#define SPI_C3_RNFULLF_MARK_MASK                 (0x01UL << SPI_C3_RNFULLF_MARK_SHIFT)               /*!< SPI1_C3: RNFULLF_MARK Mask              */
#define SPI_C3_RNFULLF_MARK_SHIFT                4                                                   /*!< SPI1_C3: RNFULLF_MARK Position          */
#define SPI_C3_TNEAREF_MARK_MASK                 (0x01UL << SPI_C3_TNEAREF_MARK_SHIFT)               /*!< SPI1_C3: TNEAREF_MARK Mask              */
#define SPI_C3_TNEAREF_MARK_SHIFT                5                                                   /*!< SPI1_C3: TNEAREF_MARK Position          */

/* -------------------------------------------------------------------------------- */
/* -----------     'SPI1' Register Access macros                        ----------- */
/* -------------------------------------------------------------------------------- */

#define SPI1_S                         (SPI1->S)
#define SPI1_BR                        (SPI1->BR)
#define SPI1_C2                        (SPI1->C2)
#define SPI1_C1                        (SPI1->C1)
#define SPI1_ML                        (SPI1->ML)
#define SPI1_MH                        (SPI1->MH)
#define SPI1_DL                        (SPI1->DL)
#define SPI1_DH                        (SPI1->DH)
#define SPI1_CI                        (SPI1->CI)
#define SPI1_C3                        (SPI1->C3)

/* ================================================================================ */
/* ================           SYST (file:SysTick_0)                ================ */
/* ================================================================================ */

/**
 * @brief System timer SysTick
 */
typedef struct {                                /*!<       SYST Structure                                               */
   __IO uint32_t  CSR;                          /*!< 0000: Control and Status Register                                  */
   __IO uint32_t  RVR;                          /*!< 0004: Reload Value Register                                        */
   __IO uint32_t  CVR;                          /*!< 0008: Current Value Register                                       */
   __I  uint32_t  CALIB;                        /*!< 000C: Calibration Value Register                                   */
} SYST_Type;


/* -------------------------------------------------------------------------------- */
/* -----------     'SYST' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */


/* ------- SYST_CSR                                 ------ */
#define SYST_CSR_ENABLE_MASK                     (0x01UL << SYST_CSR_ENABLE_SHIFT)                   /*!< SYST_CSR: ENABLE Mask                   */
#define SYST_CSR_ENABLE_SHIFT                    0                                                   /*!< SYST_CSR: ENABLE Position               */
#define SYST_CSR_TICKINT_MASK                    (0x01UL << SYST_CSR_TICKINT_SHIFT)                  /*!< SYST_CSR: TICKINT Mask                  */
#define SYST_CSR_TICKINT_SHIFT                   1                                                   /*!< SYST_CSR: TICKINT Position              */
#define SYST_CSR_CLKSOURCE_MASK                  (0x01UL << SYST_CSR_CLKSOURCE_SHIFT)                /*!< SYST_CSR: CLKSOURCE Mask                */
#define SYST_CSR_CLKSOURCE_SHIFT                 2                                                   /*!< SYST_CSR: CLKSOURCE Position            */
#define SYST_CSR_COUNTFLAG_MASK                  (0x01UL << SYST_CSR_COUNTFLAG_SHIFT)                /*!< SYST_CSR: COUNTFLAG Mask                */
#define SYST_CSR_COUNTFLAG_SHIFT                 16                                                  /*!< SYST_CSR: COUNTFLAG Position            */

/* ------- SYST_RVR                                 ------ */
#define SYST_RVR_RELOAD_MASK                     (0xFFFFFFUL << SYST_RVR_RELOAD_SHIFT)               /*!< SYST_RVR: RELOAD Mask                   */
#define SYST_RVR_RELOAD_SHIFT                    0                                                   /*!< SYST_RVR: RELOAD Position               */
#define SYST_RVR_RELOAD(x)                       (((x)<<SYST_RVR_RELOAD_SHIFT)&SYST_RVR_RELOAD_MASK) /*!< SYST_RVR                                */

/* ------- SYST_CVR                                 ------ */
#define SYST_CVR_CURRENT_MASK                    (0xFFFFFFUL << SYST_CVR_CURRENT_SHIFT)              /*!< SYST_CVR: CURRENT Mask                  */
#define SYST_CVR_CURRENT_SHIFT                   0                                                   /*!< SYST_CVR: CURRENT Position              */
#define SYST_CVR_CURRENT(x)                      (((x)<<SYST_CVR_CURRENT_SHIFT)&SYST_CVR_CURRENT_MASK) /*!< SYST_CVR                                */

/* ------- SYST_CALIB                               ------ */
#define SYST_CALIB_TENMS_MASK                    (0xFFFFFFUL << SYST_CALIB_TENMS_SHIFT)              /*!< SYST_CALIB: TENMS Mask                  */
#define SYST_CALIB_TENMS_SHIFT                   0                                                   /*!< SYST_CALIB: TENMS Position              */
#define SYST_CALIB_TENMS(x)                      (((x)<<SYST_CALIB_TENMS_SHIFT)&SYST_CALIB_TENMS_MASK) /*!< SYST_CALIB                              */
#define SYST_CALIB_SKEW_MASK                     (0x01UL << SYST_CALIB_SKEW_SHIFT)                   /*!< SYST_CALIB: SKEW Mask                   */
#define SYST_CALIB_SKEW_SHIFT                    30                                                  /*!< SYST_CALIB: SKEW Position               */
#define SYST_CALIB_NOREF_MASK                    (0x01UL << SYST_CALIB_NOREF_SHIFT)                  /*!< SYST_CALIB: NOREF Mask                  */
#define SYST_CALIB_NOREF_SHIFT                   31                                                  /*!< SYST_CALIB: NOREF Position              */

/* -------------------------------------------------------------------------------- */
/* -----------     'SYST' Register Access macros                        ----------- */
/* -------------------------------------------------------------------------------- */

#define SYST_CSR                       (SYST->CSR)
#define SYST_RVR                       (SYST->RVR)
#define SYST_CVR                       (SYST->CVR)
#define SYST_CALIB                     (SYST->CALIB)

/* ================================================================================ */
/* ================           UART0 (file:UART0_MKM_C7816)         ================ */
/* ================================================================================ */

/**
 * @brief Universal Asynchronous Receiver/Transmitter
 */
typedef struct {                                /*!<       UART0 Structure                                              */
   __IO uint8_t   BDH;                          /*!< 0000: Baud Rate Register: High                                     */
   __IO uint8_t   BDL;                          /*!< 0001: Baud Rate Register: Low                                      */
   __IO uint8_t   C1;                           /*!< 0002: Control Register 1                                           */
   __IO uint8_t   C2;                           /*!< 0003: Control Register 2                                           */
   __I  uint8_t   S1;                           /*!< 0004: Status Register 1                                            */
   __IO uint8_t   S2;                           /*!< 0005: Status Register 2                                            */
   __IO uint8_t   C3;                           /*!< 0006: Control Register 3                                           */
   __IO uint8_t   D;                            /*!< 0007: Data Register                                                */
   __IO uint8_t   MA1;                          /*!< 0008: Match Address Registers 1                                    */
   __IO uint8_t   MA2;                          /*!< 0009: Match Address Registers 2                                    */
   __IO uint8_t   C4;                           /*!< 000A: Control Register 4                                           */
   __IO uint8_t   C5;                           /*!< 000B: Control Register 5                                           */
   __I  uint8_t   ED;                           /*!< 000C: Extended Data Register                                       */
   __IO uint8_t   MODEM;                        /*!< 000D: Modem Register                                               */
   __I  uint16_t  RESERVED0;                    /*!< 000E:                                                              */
   __IO uint8_t   PFIFO;                        /*!< 0010: FIFO Parameters                                              */
   __IO uint8_t   CFIFO;                        /*!< 0011: FIFO Control Register                                        */
   __IO uint8_t   SFIFO;                        /*!< 0012: FIFO Status Register                                         */
   __IO uint8_t   TWFIFO;                       /*!< 0013: FIFO Transmit Watermark                                      */
   __I  uint8_t   TCFIFO;                       /*!< 0014: FIFO Transmit Count                                          */
   __IO uint8_t   RWFIFO;                       /*!< 0015: FIFO Receive Watermark                                       */
   __I  uint8_t   RCFIFO;                       /*!< 0016: FIFO Receive Count                                           */
   __I  uint8_t   RESERVED1;                    /*!< 0017:                                                              */
   __IO uint8_t   C7816;                        /*!< 0018: 7816 Control Register                                        */
   __IO uint8_t   IE7816;                       /*!< 0019: 7816 Interrupt Enable Register                               */
   __IO uint8_t   IS7816;                       /*!< 001A: 7816 Interrupt Status Register                               */
   union {                                      /*!< 0000: (size=0001)                                                  */
      __IO uint8_t   WP7816T0;                  /*!< 001B: 7816 Wait Parameter Register                                 */
      __IO uint8_t   WP7816T1;                  /*!< 001B: 7816 Wait Parameter Register                                 */
   };
   __IO uint8_t   WN7816;                       /*!< 001C: 7816 Wait N Register                                         */
   __IO uint8_t   WF7816;                       /*!< 001D: 7816 Wait FD Register                                        */
   __IO uint8_t   ET7816;                       /*!< 001E: 7816 Error Threshold Register                                */
   __IO uint8_t   TL7816;                       /*!< 001F: 7816 Transmit Length Register                                */
} UART0_Type;


/* -------------------------------------------------------------------------------- */
/* -----------     'UART0' Position & Mask macros                       ----------- */
/* -------------------------------------------------------------------------------- */


/* ------- UART0_BDH                                ------ */
#define UART_BDH_SBR_MASK                        (0x1FUL << UART_BDH_SBR_SHIFT)                      /*!< UART0_BDH: SBR Mask                     */
#define UART_BDH_SBR_SHIFT                       0                                                   /*!< UART0_BDH: SBR Position                 */
#define UART_BDH_SBR(x)                          (((x)<<UART_BDH_SBR_SHIFT)&UART_BDH_SBR_MASK)       /*!< UART0_BDH                               */
#define UART_BDH_RXEDGIE_MASK                    (0x01UL << UART_BDH_RXEDGIE_SHIFT)                  /*!< UART0_BDH: RXEDGIE Mask                 */
#define UART_BDH_RXEDGIE_SHIFT                   6                                                   /*!< UART0_BDH: RXEDGIE Position             */

/* ------- UART0_BDL                                ------ */
#define UART_BDL_SBR_MASK                        (0xFFUL << UART_BDL_SBR_SHIFT)                      /*!< UART0_BDL: SBR Mask                     */
#define UART_BDL_SBR_SHIFT                       0                                                   /*!< UART0_BDL: SBR Position                 */
#define UART_BDL_SBR(x)                          (((x)<<UART_BDL_SBR_SHIFT)&UART_BDL_SBR_MASK)       /*!< UART0_BDL                               */

/* ------- UART0_C1                                 ------ */
#define UART_C1_PT_MASK                          (0x01UL << UART_C1_PT_SHIFT)                        /*!< UART0_C1: PT Mask                       */
#define UART_C1_PT_SHIFT                         0                                                   /*!< UART0_C1: PT Position                   */
#define UART_C1_PE_MASK                          (0x01UL << UART_C1_PE_SHIFT)                        /*!< UART0_C1: PE Mask                       */
#define UART_C1_PE_SHIFT                         1                                                   /*!< UART0_C1: PE Position                   */
#define UART_C1_ILT_MASK                         (0x01UL << UART_C1_ILT_SHIFT)                       /*!< UART0_C1: ILT Mask                      */
#define UART_C1_ILT_SHIFT                        2                                                   /*!< UART0_C1: ILT Position                  */
#define UART_C1_WAKE_MASK                        (0x01UL << UART_C1_WAKE_SHIFT)                      /*!< UART0_C1: WAKE Mask                     */
#define UART_C1_WAKE_SHIFT                       3                                                   /*!< UART0_C1: WAKE Position                 */
#define UART_C1_M_MASK                           (0x01UL << UART_C1_M_SHIFT)                         /*!< UART0_C1: M Mask                        */
#define UART_C1_M_SHIFT                          4                                                   /*!< UART0_C1: M Position                    */
#define UART_C1_RSRC_MASK                        (0x01UL << UART_C1_RSRC_SHIFT)                      /*!< UART0_C1: RSRC Mask                     */
#define UART_C1_RSRC_SHIFT                       5                                                   /*!< UART0_C1: RSRC Position                 */
#define UART_C1_LOOPS_MASK                       (0x01UL << UART_C1_LOOPS_SHIFT)                     /*!< UART0_C1: LOOPS Mask                    */
#define UART_C1_LOOPS_SHIFT                      7                                                   /*!< UART0_C1: LOOPS Position                */

/* ------- UART0_C2                                 ------ */
#define UART_C2_SBK_MASK                         (0x01UL << UART_C2_SBK_SHIFT)                       /*!< UART0_C2: SBK Mask                      */
#define UART_C2_SBK_SHIFT                        0                                                   /*!< UART0_C2: SBK Position                  */
#define UART_C2_RWU_MASK                         (0x01UL << UART_C2_RWU_SHIFT)                       /*!< UART0_C2: RWU Mask                      */
#define UART_C2_RWU_SHIFT                        1                                                   /*!< UART0_C2: RWU Position                  */
#define UART_C2_RE_MASK                          (0x01UL << UART_C2_RE_SHIFT)                        /*!< UART0_C2: RE Mask                       */
#define UART_C2_RE_SHIFT                         2                                                   /*!< UART0_C2: RE Position                   */
#define UART_C2_TE_MASK                          (0x01UL << UART_C2_TE_SHIFT)                        /*!< UART0_C2: TE Mask                       */
#define UART_C2_TE_SHIFT                         3                                                   /*!< UART0_C2: TE Position                   */
#define UART_C2_ILIE_MASK                        (0x01UL << UART_C2_ILIE_SHIFT)                      /*!< UART0_C2: ILIE Mask                     */
#define UART_C2_ILIE_SHIFT                       4                                                   /*!< UART0_C2: ILIE Position                 */
#define UART_C2_RIE_MASK                         (0x01UL << UART_C2_RIE_SHIFT)                       /*!< UART0_C2: RIE Mask                      */
#define UART_C2_RIE_SHIFT                        5                                                   /*!< UART0_C2: RIE Position                  */
#define UART_C2_TCIE_MASK                        (0x01UL << UART_C2_TCIE_SHIFT)                      /*!< UART0_C2: TCIE Mask                     */
#define UART_C2_TCIE_SHIFT                       6                                                   /*!< UART0_C2: TCIE Position                 */
#define UART_C2_TIE_MASK                         (0x01UL << UART_C2_TIE_SHIFT)                       /*!< UART0_C2: TIE Mask                      */
#define UART_C2_TIE_SHIFT                        7                                                   /*!< UART0_C2: TIE Position                  */

/* ------- UART0_S1                                 ------ */
#define UART_S1_PF_MASK                          (0x01UL << UART_S1_PF_SHIFT)                        /*!< UART0_S1: PF Mask                       */
#define UART_S1_PF_SHIFT                         0                                                   /*!< UART0_S1: PF Position                   */
#define UART_S1_FE_MASK                          (0x01UL << UART_S1_FE_SHIFT)                        /*!< UART0_S1: FE Mask                       */
#define UART_S1_FE_SHIFT                         1                                                   /*!< UART0_S1: FE Position                   */
#define UART_S1_NF_MASK                          (0x01UL << UART_S1_NF_SHIFT)                        /*!< UART0_S1: NF Mask                       */
#define UART_S1_NF_SHIFT                         2                                                   /*!< UART0_S1: NF Position                   */
#define UART_S1_OR_MASK                          (0x01UL << UART_S1_OR_SHIFT)                        /*!< UART0_S1: OR Mask                       */
#define UART_S1_OR_SHIFT                         3                                                   /*!< UART0_S1: OR Position                   */
#define UART_S1_IDLE_MASK                        (0x01UL << UART_S1_IDLE_SHIFT)                      /*!< UART0_S1: IDLE Mask                     */
#define UART_S1_IDLE_SHIFT                       4                                                   /*!< UART0_S1: IDLE Position                 */
#define UART_S1_RDRF_MASK                        (0x01UL << UART_S1_RDRF_SHIFT)                      /*!< UART0_S1: RDRF Mask                     */
#define UART_S1_RDRF_SHIFT                       5                                                   /*!< UART0_S1: RDRF Position                 */
#define UART_S1_TC_MASK                          (0x01UL << UART_S1_TC_SHIFT)                        /*!< UART0_S1: TC Mask                       */
#define UART_S1_TC_SHIFT                         6                                                   /*!< UART0_S1: TC Position                   */
#define UART_S1_TDRE_MASK                        (0x01UL << UART_S1_TDRE_SHIFT)                      /*!< UART0_S1: TDRE Mask                     */
#define UART_S1_TDRE_SHIFT                       7                                                   /*!< UART0_S1: TDRE Position                 */

/* ------- UART0_S2                                 ------ */
#define UART_S2_RAF_MASK                         (0x01UL << UART_S2_RAF_SHIFT)                       /*!< UART0_S2: RAF Mask                      */
#define UART_S2_RAF_SHIFT                        0                                                   /*!< UART0_S2: RAF Position                  */
#define UART_S2_BRK13_MASK                       (0x01UL << UART_S2_BRK13_SHIFT)                     /*!< UART0_S2: BRK13 Mask                    */
#define UART_S2_BRK13_SHIFT                      2                                                   /*!< UART0_S2: BRK13 Position                */
#define UART_S2_RWUID_MASK                       (0x01UL << UART_S2_RWUID_SHIFT)                     /*!< UART0_S2: RWUID Mask                    */
#define UART_S2_RWUID_SHIFT                      3                                                   /*!< UART0_S2: RWUID Position                */
#define UART_S2_RXINV_MASK                       (0x01UL << UART_S2_RXINV_SHIFT)                     /*!< UART0_S2: RXINV Mask                    */
#define UART_S2_RXINV_SHIFT                      4                                                   /*!< UART0_S2: RXINV Position                */
#define UART_S2_MSBF_MASK                        (0x01UL << UART_S2_MSBF_SHIFT)                      /*!< UART0_S2: MSBF Mask                     */
#define UART_S2_MSBF_SHIFT                       5                                                   /*!< UART0_S2: MSBF Position                 */
#define UART_S2_RXEDGIF_MASK                     (0x01UL << UART_S2_RXEDGIF_SHIFT)                   /*!< UART0_S2: RXEDGIF Mask                  */
#define UART_S2_RXEDGIF_SHIFT                    6                                                   /*!< UART0_S2: RXEDGIF Position              */

/* ------- UART0_C3                                 ------ */
#define UART_C3_PEIE_MASK                        (0x01UL << UART_C3_PEIE_SHIFT)                      /*!< UART0_C3: PEIE Mask                     */
#define UART_C3_PEIE_SHIFT                       0                                                   /*!< UART0_C3: PEIE Position                 */
#define UART_C3_FEIE_MASK                        (0x01UL << UART_C3_FEIE_SHIFT)                      /*!< UART0_C3: FEIE Mask                     */
#define UART_C3_FEIE_SHIFT                       1                                                   /*!< UART0_C3: FEIE Position                 */
#define UART_C3_NEIE_MASK                        (0x01UL << UART_C3_NEIE_SHIFT)                      /*!< UART0_C3: NEIE Mask                     */
#define UART_C3_NEIE_SHIFT                       2                                                   /*!< UART0_C3: NEIE Position                 */
#define UART_C3_ORIE_MASK                        (0x01UL << UART_C3_ORIE_SHIFT)                      /*!< UART0_C3: ORIE Mask                     */
#define UART_C3_ORIE_SHIFT                       3                                                   /*!< UART0_C3: ORIE Position                 */
#define UART_C3_TXINV_MASK                       (0x01UL << UART_C3_TXINV_SHIFT)                     /*!< UART0_C3: TXINV Mask                    */
#define UART_C3_TXINV_SHIFT                      4                                                   /*!< UART0_C3: TXINV Position                */
#define UART_C3_TXDIR_MASK                       (0x01UL << UART_C3_TXDIR_SHIFT)                     /*!< UART0_C3: TXDIR Mask                    */
#define UART_C3_TXDIR_SHIFT                      5                                                   /*!< UART0_C3: TXDIR Position                */
#define UART_C3_T8_MASK                          (0x01UL << UART_C3_T8_SHIFT)                        /*!< UART0_C3: T8 Mask                       */
#define UART_C3_T8_SHIFT                         6                                                   /*!< UART0_C3: T8 Position                   */
#define UART_C3_R8_MASK                          (0x01UL << UART_C3_R8_SHIFT)                        /*!< UART0_C3: R8 Mask                       */
#define UART_C3_R8_SHIFT                         7                                                   /*!< UART0_C3: R8 Position                   */

/* ------- UART0_D                                  ------ */
#define UART_D_RT_MASK                           (0xFFUL << UART_D_RT_SHIFT)                         /*!< UART0_D: RT Mask                        */
#define UART_D_RT_SHIFT                          0                                                   /*!< UART0_D: RT Position                    */
#define UART_D_RT(x)                             (((x)<<UART_D_RT_SHIFT)&UART_D_RT_MASK)             /*!< UART0_D                                 */

/* ------- UART0_MA                                 ------ */
#define UART_MA_MA_MASK                          (0xFFUL << UART_MA_MA_SHIFT)                        /*!< UART0_MA: MA Mask                       */
#define UART_MA_MA_SHIFT                         0                                                   /*!< UART0_MA: MA Position                   */
#define UART_MA_MA(x)                            (((x)<<UART_MA_MA_SHIFT)&UART_MA_MA_MASK)           /*!< UART0_MA                                */

/* ------- UART0_C4                                 ------ */
#define UART_C4_BRFA_MASK                        (0x1FUL << UART_C4_BRFA_SHIFT)                      /*!< UART0_C4: BRFA Mask                     */
#define UART_C4_BRFA_SHIFT                       0                                                   /*!< UART0_C4: BRFA Position                 */
#define UART_C4_BRFA(x)                          (((x)<<UART_C4_BRFA_SHIFT)&UART_C4_BRFA_MASK)       /*!< UART0_C4                                */
#define UART_C4_M10_MASK                         (0x01UL << UART_C4_M10_SHIFT)                       /*!< UART0_C4: M10 Mask                      */
#define UART_C4_M10_SHIFT                        5                                                   /*!< UART0_C4: M10 Position                  */
#define UART_C4_MAEN2_MASK                       (0x01UL << UART_C4_MAEN2_SHIFT)                     /*!< UART0_C4: MAEN2 Mask                    */
#define UART_C4_MAEN2_SHIFT                      6                                                   /*!< UART0_C4: MAEN2 Position                */
#define UART_C4_MAEN1_MASK                       (0x01UL << UART_C4_MAEN1_SHIFT)                     /*!< UART0_C4: MAEN1 Mask                    */
#define UART_C4_MAEN1_SHIFT                      7                                                   /*!< UART0_C4: MAEN1 Position                */

/* ------- UART0_C5                                 ------ */
#define UART_C5_RDMAS_MASK                       (0x01UL << UART_C5_RDMAS_SHIFT)                     /*!< UART0_C5: RDMAS Mask                    */
#define UART_C5_RDMAS_SHIFT                      5                                                   /*!< UART0_C5: RDMAS Position                */
#define UART_C5_TDMAS_MASK                       (0x01UL << UART_C5_TDMAS_SHIFT)                     /*!< UART0_C5: TDMAS Mask                    */
#define UART_C5_TDMAS_SHIFT                      7                                                   /*!< UART0_C5: TDMAS Position                */

/* ------- UART0_ED                                 ------ */
#define UART_ED_PARITYE_MASK                     (0x01UL << UART_ED_PARITYE_SHIFT)                   /*!< UART0_ED: PARITYE Mask                  */
#define UART_ED_PARITYE_SHIFT                    6                                                   /*!< UART0_ED: PARITYE Position              */
#define UART_ED_NOISY_MASK                       (0x01UL << UART_ED_NOISY_SHIFT)                     /*!< UART0_ED: NOISY Mask                    */
#define UART_ED_NOISY_SHIFT                      7                                                   /*!< UART0_ED: NOISY Position                */

/* ------- UART0_MODEM                              ------ */
#define UART_MODEM_TXCTSE_MASK                   (0x01UL << UART_MODEM_TXCTSE_SHIFT)                 /*!< UART0_MODEM: TXCTSE Mask                */
#define UART_MODEM_TXCTSE_SHIFT                  0                                                   /*!< UART0_MODEM: TXCTSE Position            */
#define UART_MODEM_TXRTSE_MASK                   (0x01UL << UART_MODEM_TXRTSE_SHIFT)                 /*!< UART0_MODEM: TXRTSE Mask                */
#define UART_MODEM_TXRTSE_SHIFT                  1                                                   /*!< UART0_MODEM: TXRTSE Position            */
#define UART_MODEM_TXRTSPOL_MASK                 (0x01UL << UART_MODEM_TXRTSPOL_SHIFT)               /*!< UART0_MODEM: TXRTSPOL Mask              */
#define UART_MODEM_TXRTSPOL_SHIFT                2                                                   /*!< UART0_MODEM: TXRTSPOL Position          */
#define UART_MODEM_RXRTSE_MASK                   (0x01UL << UART_MODEM_RXRTSE_SHIFT)                 /*!< UART0_MODEM: RXRTSE Mask                */
#define UART_MODEM_RXRTSE_SHIFT                  3                                                   /*!< UART0_MODEM: RXRTSE Position            */

/* ------- UART0_PFIFO                              ------ */
#define UART_PFIFO_RXFIFOSIZE_MASK               (0x07UL << UART_PFIFO_RXFIFOSIZE_SHIFT)             /*!< UART0_PFIFO: RXFIFOSIZE Mask            */
#define UART_PFIFO_RXFIFOSIZE_SHIFT              0                                                   /*!< UART0_PFIFO: RXFIFOSIZE Position        */
#define UART_PFIFO_RXFIFOSIZE(x)                 (((x)<<UART_PFIFO_RXFIFOSIZE_SHIFT)&UART_PFIFO_RXFIFOSIZE_MASK) /*!< UART0_PFIFO                             */
#define UART_PFIFO_RXFE_MASK                     (0x01UL << UART_PFIFO_RXFE_SHIFT)                   /*!< UART0_PFIFO: RXFE Mask                  */
#define UART_PFIFO_RXFE_SHIFT                    3                                                   /*!< UART0_PFIFO: RXFE Position              */
#define UART_PFIFO_TXFIFOSIZE_MASK               (0x07UL << UART_PFIFO_TXFIFOSIZE_SHIFT)             /*!< UART0_PFIFO: TXFIFOSIZE Mask            */
#define UART_PFIFO_TXFIFOSIZE_SHIFT              4                                                   /*!< UART0_PFIFO: TXFIFOSIZE Position        */
#define UART_PFIFO_TXFIFOSIZE(x)                 (((x)<<UART_PFIFO_TXFIFOSIZE_SHIFT)&UART_PFIFO_TXFIFOSIZE_MASK) /*!< UART0_PFIFO                             */
#define UART_PFIFO_TXFE_MASK                     (0x01UL << UART_PFIFO_TXFE_SHIFT)                   /*!< UART0_PFIFO: TXFE Mask                  */
#define UART_PFIFO_TXFE_SHIFT                    7                                                   /*!< UART0_PFIFO: TXFE Position              */

/* ------- UART0_CFIFO                              ------ */
#define UART_CFIFO_RXUFE_MASK                    (0x01UL << UART_CFIFO_RXUFE_SHIFT)                  /*!< UART0_CFIFO: RXUFE Mask                 */
#define UART_CFIFO_RXUFE_SHIFT                   0                                                   /*!< UART0_CFIFO: RXUFE Position             */
#define UART_CFIFO_TXOFE_MASK                    (0x01UL << UART_CFIFO_TXOFE_SHIFT)                  /*!< UART0_CFIFO: TXOFE Mask                 */
#define UART_CFIFO_TXOFE_SHIFT                   1                                                   /*!< UART0_CFIFO: TXOFE Position             */
#define UART_CFIFO_RXOFE_MASK                    (0x01UL << UART_CFIFO_RXOFE_SHIFT)                  /*!< UART0_CFIFO: RXOFE Mask                 */
#define UART_CFIFO_RXOFE_SHIFT                   2                                                   /*!< UART0_CFIFO: RXOFE Position             */
#define UART_CFIFO_RXFLUSH_MASK                  (0x01UL << UART_CFIFO_RXFLUSH_SHIFT)                /*!< UART0_CFIFO: RXFLUSH Mask               */
#define UART_CFIFO_RXFLUSH_SHIFT                 6                                                   /*!< UART0_CFIFO: RXFLUSH Position           */
#define UART_CFIFO_TXFLUSH_MASK                  (0x01UL << UART_CFIFO_TXFLUSH_SHIFT)                /*!< UART0_CFIFO: TXFLUSH Mask               */
#define UART_CFIFO_TXFLUSH_SHIFT                 7                                                   /*!< UART0_CFIFO: TXFLUSH Position           */

/* ------- UART0_SFIFO                              ------ */
#define UART_SFIFO_RXUF_MASK                     (0x01UL << UART_SFIFO_RXUF_SHIFT)                   /*!< UART0_SFIFO: RXUF Mask                  */
#define UART_SFIFO_RXUF_SHIFT                    0                                                   /*!< UART0_SFIFO: RXUF Position              */
#define UART_SFIFO_TXOF_MASK                     (0x01UL << UART_SFIFO_TXOF_SHIFT)                   /*!< UART0_SFIFO: TXOF Mask                  */
#define UART_SFIFO_TXOF_SHIFT                    1                                                   /*!< UART0_SFIFO: TXOF Position              */
#define UART_SFIFO_RXOF_MASK                     (0x01UL << UART_SFIFO_RXOF_SHIFT)                   /*!< UART0_SFIFO: RXOF Mask                  */
#define UART_SFIFO_RXOF_SHIFT                    2                                                   /*!< UART0_SFIFO: RXOF Position              */
#define UART_SFIFO_RXEMPT_MASK                   (0x01UL << UART_SFIFO_RXEMPT_SHIFT)                 /*!< UART0_SFIFO: RXEMPT Mask                */
#define UART_SFIFO_RXEMPT_SHIFT                  6                                                   /*!< UART0_SFIFO: RXEMPT Position            */
#define UART_SFIFO_TXEMPT_MASK                   (0x01UL << UART_SFIFO_TXEMPT_SHIFT)                 /*!< UART0_SFIFO: TXEMPT Mask                */
#define UART_SFIFO_TXEMPT_SHIFT                  7                                                   /*!< UART0_SFIFO: TXEMPT Position            */

/* ------- UART0_TWFIFO                             ------ */
#define UART_TWFIFO_TXWATER_MASK                 (0xFFUL << UART_TWFIFO_TXWATER_SHIFT)               /*!< UART0_TWFIFO: TXWATER Mask              */
#define UART_TWFIFO_TXWATER_SHIFT                0                                                   /*!< UART0_TWFIFO: TXWATER Position          */
#define UART_TWFIFO_TXWATER(x)                   (((x)<<UART_TWFIFO_TXWATER_SHIFT)&UART_TWFIFO_TXWATER_MASK) /*!< UART0_TWFIFO                            */

/* ------- UART0_TCFIFO                             ------ */
#define UART_TCFIFO_TXCOUNT_MASK                 (0xFFUL << UART_TCFIFO_TXCOUNT_SHIFT)               /*!< UART0_TCFIFO: TXCOUNT Mask              */
#define UART_TCFIFO_TXCOUNT_SHIFT                0                                                   /*!< UART0_TCFIFO: TXCOUNT Position          */
#define UART_TCFIFO_TXCOUNT(x)                   (((x)<<UART_TCFIFO_TXCOUNT_SHIFT)&UART_TCFIFO_TXCOUNT_MASK) /*!< UART0_TCFIFO                            */

/* ------- UART0_RWFIFO                             ------ */
#define UART_RWFIFO_RXWATER_MASK                 (0xFFUL << UART_RWFIFO_RXWATER_SHIFT)               /*!< UART0_RWFIFO: RXWATER Mask              */
#define UART_RWFIFO_RXWATER_SHIFT                0                                                   /*!< UART0_RWFIFO: RXWATER Position          */
#define UART_RWFIFO_RXWATER(x)                   (((x)<<UART_RWFIFO_RXWATER_SHIFT)&UART_RWFIFO_RXWATER_MASK) /*!< UART0_RWFIFO                            */

/* ------- UART0_RCFIFO                             ------ */
#define UART_RCFIFO_RXCOUNT_MASK                 (0xFFUL << UART_RCFIFO_RXCOUNT_SHIFT)               /*!< UART0_RCFIFO: RXCOUNT Mask              */
#define UART_RCFIFO_RXCOUNT_SHIFT                0                                                   /*!< UART0_RCFIFO: RXCOUNT Position          */
#define UART_RCFIFO_RXCOUNT(x)                   (((x)<<UART_RCFIFO_RXCOUNT_SHIFT)&UART_RCFIFO_RXCOUNT_MASK) /*!< UART0_RCFIFO                            */

/* ------- UART0_C7816                              ------ */
#define UART_C7816_ISO_7816E_MASK                (0x01UL << UART_C7816_ISO_7816E_SHIFT)              /*!< UART0_C7816: ISO_7816E Mask             */
#define UART_C7816_ISO_7816E_SHIFT               0                                                   /*!< UART0_C7816: ISO_7816E Position         */
#define UART_C7816_TTYPE_MASK                    (0x01UL << UART_C7816_TTYPE_SHIFT)                  /*!< UART0_C7816: TTYPE Mask                 */
#define UART_C7816_TTYPE_SHIFT                   1                                                   /*!< UART0_C7816: TTYPE Position             */
#define UART_C7816_INIT_MASK                     (0x01UL << UART_C7816_INIT_SHIFT)                   /*!< UART0_C7816: INIT Mask                  */
#define UART_C7816_INIT_SHIFT                    2                                                   /*!< UART0_C7816: INIT Position              */
#define UART_C7816_ANACK_MASK                    (0x01UL << UART_C7816_ANACK_SHIFT)                  /*!< UART0_C7816: ANACK Mask                 */
#define UART_C7816_ANACK_SHIFT                   3                                                   /*!< UART0_C7816: ANACK Position             */
#define UART_C7816_ONACK_MASK                    (0x01UL << UART_C7816_ONACK_SHIFT)                  /*!< UART0_C7816: ONACK Mask                 */
#define UART_C7816_ONACK_SHIFT                   4                                                   /*!< UART0_C7816: ONACK Position             */

/* ------- UART0_IE7816                             ------ */
#define UART_IE7816_RXTE_MASK                    (0x01UL << UART_IE7816_RXTE_SHIFT)                  /*!< UART0_IE7816: RXTE Mask                 */
#define UART_IE7816_RXTE_SHIFT                   0                                                   /*!< UART0_IE7816: RXTE Position             */
#define UART_IE7816_TXTE_MASK                    (0x01UL << UART_IE7816_TXTE_SHIFT)                  /*!< UART0_IE7816: TXTE Mask                 */
#define UART_IE7816_TXTE_SHIFT                   1                                                   /*!< UART0_IE7816: TXTE Position             */
#define UART_IE7816_GTVE_MASK                    (0x01UL << UART_IE7816_GTVE_SHIFT)                  /*!< UART0_IE7816: GTVE Mask                 */
#define UART_IE7816_GTVE_SHIFT                   2                                                   /*!< UART0_IE7816: GTVE Position             */
#define UART_IE7816_INITDE_MASK                  (0x01UL << UART_IE7816_INITDE_SHIFT)                /*!< UART0_IE7816: INITDE Mask               */
#define UART_IE7816_INITDE_SHIFT                 4                                                   /*!< UART0_IE7816: INITDE Position           */
#define UART_IE7816_BWTE_MASK                    (0x01UL << UART_IE7816_BWTE_SHIFT)                  /*!< UART0_IE7816: BWTE Mask                 */
#define UART_IE7816_BWTE_SHIFT                   5                                                   /*!< UART0_IE7816: BWTE Position             */
#define UART_IE7816_CWTE_MASK                    (0x01UL << UART_IE7816_CWTE_SHIFT)                  /*!< UART0_IE7816: CWTE Mask                 */
#define UART_IE7816_CWTE_SHIFT                   6                                                   /*!< UART0_IE7816: CWTE Position             */
#define UART_IE7816_WTE_MASK                     (0x01UL << UART_IE7816_WTE_SHIFT)                   /*!< UART0_IE7816: WTE Mask                  */
#define UART_IE7816_WTE_SHIFT                    7                                                   /*!< UART0_IE7816: WTE Position              */

/* ------- UART0_IS7816                             ------ */
#define UART_IS7816_RXT_MASK                     (0x01UL << UART_IS7816_RXT_SHIFT)                   /*!< UART0_IS7816: RXT Mask                  */
#define UART_IS7816_RXT_SHIFT                    0                                                   /*!< UART0_IS7816: RXT Position              */
#define UART_IS7816_TXT_MASK                     (0x01UL << UART_IS7816_TXT_SHIFT)                   /*!< UART0_IS7816: TXT Mask                  */
#define UART_IS7816_TXT_SHIFT                    1                                                   /*!< UART0_IS7816: TXT Position              */
#define UART_IS7816_GTV_MASK                     (0x01UL << UART_IS7816_GTV_SHIFT)                   /*!< UART0_IS7816: GTV Mask                  */
#define UART_IS7816_GTV_SHIFT                    2                                                   /*!< UART0_IS7816: GTV Position              */
#define UART_IS7816_INITD_MASK                   (0x01UL << UART_IS7816_INITD_SHIFT)                 /*!< UART0_IS7816: INITD Mask                */
#define UART_IS7816_INITD_SHIFT                  4                                                   /*!< UART0_IS7816: INITD Position            */
#define UART_IS7816_BWT_MASK                     (0x01UL << UART_IS7816_BWT_SHIFT)                   /*!< UART0_IS7816: BWT Mask                  */
#define UART_IS7816_BWT_SHIFT                    5                                                   /*!< UART0_IS7816: BWT Position              */
#define UART_IS7816_CWT_MASK                     (0x01UL << UART_IS7816_CWT_SHIFT)                   /*!< UART0_IS7816: CWT Mask                  */
#define UART_IS7816_CWT_SHIFT                    6                                                   /*!< UART0_IS7816: CWT Position              */
#define UART_IS7816_WT_MASK                      (0x01UL << UART_IS7816_WT_SHIFT)                    /*!< UART0_IS7816: WT Mask                   */
#define UART_IS7816_WT_SHIFT                     7                                                   /*!< UART0_IS7816: WT Position               */

/* ------- UART0_WP7816T0                           ------ */
#define UART_WP7816T0_WI_MASK                    (0xFFUL << UART_WP7816T0_WI_SHIFT)                  /*!< UART0_WP7816T0: WI Mask                 */
#define UART_WP7816T0_WI_SHIFT                   0                                                   /*!< UART0_WP7816T0: WI Position             */
#define UART_WP7816T0_WI(x)                      (((x)<<UART_WP7816T0_WI_SHIFT)&UART_WP7816T0_WI_MASK) /*!< UART0_WP7816T0                          */

/* ------- UART0_WP7816T1                           ------ */
#define UART_WP7816T1_BWI_MASK                   (0x0FUL << UART_WP7816T1_BWI_SHIFT)                 /*!< UART0_WP7816T1: BWI Mask                */
#define UART_WP7816T1_BWI_SHIFT                  0                                                   /*!< UART0_WP7816T1: BWI Position            */
#define UART_WP7816T1_BWI(x)                     (((x)<<UART_WP7816T1_BWI_SHIFT)&UART_WP7816T1_BWI_MASK) /*!< UART0_WP7816T1                          */
#define UART_WP7816T1_CWI_MASK                   (0x0FUL << UART_WP7816T1_CWI_SHIFT)                 /*!< UART0_WP7816T1: CWI Mask                */
#define UART_WP7816T1_CWI_SHIFT                  4                                                   /*!< UART0_WP7816T1: CWI Position            */
#define UART_WP7816T1_CWI(x)                     (((x)<<UART_WP7816T1_CWI_SHIFT)&UART_WP7816T1_CWI_MASK) /*!< UART0_WP7816T1                          */

/* ------- UART0_WN7816                             ------ */
#define UART_WN7816_GTN_MASK                     (0xFFUL << UART_WN7816_GTN_SHIFT)                   /*!< UART0_WN7816: GTN Mask                  */
#define UART_WN7816_GTN_SHIFT                    0                                                   /*!< UART0_WN7816: GTN Position              */
#define UART_WN7816_GTN(x)                       (((x)<<UART_WN7816_GTN_SHIFT)&UART_WN7816_GTN_MASK) /*!< UART0_WN7816                            */

/* ------- UART0_WF7816                             ------ */
#define UART_WF7816_GTFD_MASK                    (0xFFUL << UART_WF7816_GTFD_SHIFT)                  /*!< UART0_WF7816: GTFD Mask                 */
#define UART_WF7816_GTFD_SHIFT                   0                                                   /*!< UART0_WF7816: GTFD Position             */
#define UART_WF7816_GTFD(x)                      (((x)<<UART_WF7816_GTFD_SHIFT)&UART_WF7816_GTFD_MASK) /*!< UART0_WF7816                            */

/* ------- UART0_ET7816                             ------ */
#define UART_ET7816_RXTHRESHOLD_MASK             (0x0FUL << UART_ET7816_RXTHRESHOLD_SHIFT)           /*!< UART0_ET7816: RXTHRESHOLD Mask          */
#define UART_ET7816_RXTHRESHOLD_SHIFT            0                                                   /*!< UART0_ET7816: RXTHRESHOLD Position      */
#define UART_ET7816_RXTHRESHOLD(x)               (((x)<<UART_ET7816_RXTHRESHOLD_SHIFT)&UART_ET7816_RXTHRESHOLD_MASK) /*!< UART0_ET7816                            */
#define UART_ET7816_TXTHRESHOLD_MASK             (0x0FUL << UART_ET7816_TXTHRESHOLD_SHIFT)           /*!< UART0_ET7816: TXTHRESHOLD Mask          */
#define UART_ET7816_TXTHRESHOLD_SHIFT            4                                                   /*!< UART0_ET7816: TXTHRESHOLD Position      */
#define UART_ET7816_TXTHRESHOLD(x)               (((x)<<UART_ET7816_TXTHRESHOLD_SHIFT)&UART_ET7816_TXTHRESHOLD_MASK) /*!< UART0_ET7816                            */

/* ------- UART0_TL7816                             ------ */
#define UART_TL7816_TLEN_MASK                    (0xFFUL << UART_TL7816_TLEN_SHIFT)                  /*!< UART0_TL7816: TLEN Mask                 */
#define UART_TL7816_TLEN_SHIFT                   0                                                   /*!< UART0_TL7816: TLEN Position             */
#define UART_TL7816_TLEN(x)                      (((x)<<UART_TL7816_TLEN_SHIFT)&UART_TL7816_TLEN_MASK) /*!< UART0_TL7816                            */

/* -------------------------------------------------------------------------------- */
/* -----------     'UART0' Register Access macros                       ----------- */
/* -------------------------------------------------------------------------------- */

#define UART0_BDH                      (UART0->BDH)
#define UART0_BDL                      (UART0->BDL)
#define UART0_C1                       (UART0->C1)
#define UART0_C2                       (UART0->C2)
#define UART0_S1                       (UART0->S1)
#define UART0_S2                       (UART0->S2)
#define UART0_C3                       (UART0->C3)
#define UART0_D                        (UART0->D)
#define UART0_MA1                      (UART0->MA1)
#define UART0_MA2                      (UART0->MA2)
#define UART0_C4                       (UART0->C4)
#define UART0_C5                       (UART0->C5)
#define UART0_ED                       (UART0->ED)
#define UART0_MODEM                    (UART0->MODEM)
#define UART0_PFIFO                    (UART0->PFIFO)
#define UART0_CFIFO                    (UART0->CFIFO)
#define UART0_SFIFO                    (UART0->SFIFO)
#define UART0_TWFIFO                   (UART0->TWFIFO)
#define UART0_TCFIFO                   (UART0->TCFIFO)
#define UART0_RWFIFO                   (UART0->RWFIFO)
#define UART0_RCFIFO                   (UART0->RCFIFO)
#define UART0_C7816                    (UART0->C7816)
#define UART0_IE7816                   (UART0->IE7816)
#define UART0_IS7816                   (UART0->IS7816)
#define UART0_WP7816T0                 (UART0->WP7816T0)
#define UART0_WP7816T1                 (UART0->WP7816T1)
#define UART0_WN7816                   (UART0->WN7816)
#define UART0_WF7816                   (UART0->WF7816)
#define UART0_ET7816                   (UART0->ET7816)
#define UART0_TL7816                   (UART0->TL7816)

/* ================================================================================ */
/* ================           UART1 (derived from UART0)           ================ */
/* ================================================================================ */

/**
 * @brief Universal Asynchronous Receiver/Transmitter
 */
typedef UART0_Type UART1_Type;  /*!< UART1 Structure                                             */


/* -------------------------------------------------------------------------------- */
/* -----------     'UART1' Register Access macros                       ----------- */
/* -------------------------------------------------------------------------------- */

#define UART1_BDH                      (UART1->BDH)
#define UART1_BDL                      (UART1->BDL)
#define UART1_C1                       (UART1->C1)
#define UART1_C2                       (UART1->C2)
#define UART1_S1                       (UART1->S1)
#define UART1_S2                       (UART1->S2)
#define UART1_C3                       (UART1->C3)
#define UART1_D                        (UART1->D)
#define UART1_MA1                      (UART1->MA1)
#define UART1_MA2                      (UART1->MA2)
#define UART1_C4                       (UART1->C4)
#define UART1_C5                       (UART1->C5)
#define UART1_ED                       (UART1->ED)
#define UART1_MODEM                    (UART1->MODEM)
#define UART1_PFIFO                    (UART1->PFIFO)
#define UART1_CFIFO                    (UART1->CFIFO)
#define UART1_SFIFO                    (UART1->SFIFO)
#define UART1_TWFIFO                   (UART1->TWFIFO)
#define UART1_TCFIFO                   (UART1->TCFIFO)
#define UART1_RWFIFO                   (UART1->RWFIFO)
#define UART1_RCFIFO                   (UART1->RCFIFO)
#define UART1_C7816                    (UART1->C7816)
#define UART1_IE7816                   (UART1->IE7816)
#define UART1_IS7816                   (UART1->IS7816)
#define UART1_WP7816T0                 (UART1->WP7816T0)
#define UART1_WP7816T1                 (UART1->WP7816T1)
#define UART1_WN7816                   (UART1->WN7816)
#define UART1_WF7816                   (UART1->WF7816)
#define UART1_ET7816                   (UART1->ET7816)
#define UART1_TL7816                   (UART1->TL7816)

/* ================================================================================ */
/* ================           UART2 (derived from UART0)           ================ */
/* ================================================================================ */

/**
 * @brief Universal Asynchronous Receiver/Transmitter
 */
typedef UART0_Type UART2_Type;  /*!< UART2 Structure                                             */


/* -------------------------------------------------------------------------------- */
/* -----------     'UART2' Register Access macros                       ----------- */
/* -------------------------------------------------------------------------------- */

#define UART2_BDH                      (UART2->BDH)
#define UART2_BDL                      (UART2->BDL)
#define UART2_C1                       (UART2->C1)
#define UART2_C2                       (UART2->C2)
#define UART2_S1                       (UART2->S1)
#define UART2_S2                       (UART2->S2)
#define UART2_C3                       (UART2->C3)
#define UART2_D                        (UART2->D)
#define UART2_MA1                      (UART2->MA1)
#define UART2_MA2                      (UART2->MA2)
#define UART2_C4                       (UART2->C4)
#define UART2_C5                       (UART2->C5)
#define UART2_ED                       (UART2->ED)
#define UART2_MODEM                    (UART2->MODEM)
#define UART2_PFIFO                    (UART2->PFIFO)
#define UART2_CFIFO                    (UART2->CFIFO)
#define UART2_SFIFO                    (UART2->SFIFO)
#define UART2_TWFIFO                   (UART2->TWFIFO)
#define UART2_TCFIFO                   (UART2->TCFIFO)
#define UART2_RWFIFO                   (UART2->RWFIFO)
#define UART2_RCFIFO                   (UART2->RCFIFO)
#define UART2_C7816                    (UART2->C7816)
#define UART2_IE7816                   (UART2->IE7816)
#define UART2_IS7816                   (UART2->IS7816)
#define UART2_WP7816T0                 (UART2->WP7816T0)
#define UART2_WP7816T1                 (UART2->WP7816T1)
#define UART2_WN7816                   (UART2->WN7816)
#define UART2_WF7816                   (UART2->WF7816)
#define UART2_ET7816                   (UART2->ET7816)
#define UART2_TL7816                   (UART2->TL7816)

/* ================================================================================ */
/* ================           UART3 (derived from UART1)           ================ */
/* ================================================================================ */

/**
 * @brief Universal Asynchronous Receiver/Transmitter
 */
typedef UART1_Type UART3_Type;  /*!< UART3 Structure                                             */


/* -------------------------------------------------------------------------------- */
/* -----------     'UART3' Register Access macros                       ----------- */
/* -------------------------------------------------------------------------------- */

#define UART3_BDH                      (UART3->BDH)
#define UART3_BDL                      (UART3->BDL)
#define UART3_C1                       (UART3->C1)
#define UART3_C2                       (UART3->C2)
#define UART3_S1                       (UART3->S1)
#define UART3_S2                       (UART3->S2)
#define UART3_C3                       (UART3->C3)
#define UART3_D                        (UART3->D)
#define UART3_MA1                      (UART3->MA1)
#define UART3_MA2                      (UART3->MA2)
#define UART3_C4                       (UART3->C4)
#define UART3_C5                       (UART3->C5)
#define UART3_ED                       (UART3->ED)
#define UART3_MODEM                    (UART3->MODEM)
#define UART3_PFIFO                    (UART3->PFIFO)
#define UART3_CFIFO                    (UART3->CFIFO)
#define UART3_SFIFO                    (UART3->SFIFO)
#define UART3_TWFIFO                   (UART3->TWFIFO)
#define UART3_TCFIFO                   (UART3->TCFIFO)
#define UART3_RWFIFO                   (UART3->RWFIFO)
#define UART3_RCFIFO                   (UART3->RCFIFO)
#define UART3_C7816                    (UART3->C7816)
#define UART3_IE7816                   (UART3->IE7816)
#define UART3_IS7816                   (UART3->IS7816)
#define UART3_WP7816T0                 (UART3->WP7816T0)
#define UART3_WP7816T1                 (UART3->WP7816T1)
#define UART3_WN7816                   (UART3->WN7816)
#define UART3_WF7816                   (UART3->WF7816)
#define UART3_ET7816                   (UART3->ET7816)
#define UART3_TL7816                   (UART3->TL7816)

/* ================================================================================ */
/* ================           VREF (file:VREF_MKM)                 ================ */
/* ================================================================================ */

/**
 * @brief Voltage Reference
 */
typedef struct {                                /*!<       VREF Structure                                               */
   __IO uint8_t   VREFH_TRM;                    /*!< 0000: Trim Register                                                */
   __IO uint8_t   SC;                           /*!< 0001: Status and Control Register                                  */
   __I  uint8_t   RESERVED0[3];                 /*!< 0002:                                                              */
   __IO uint8_t   VREFL_TRM;                    /*!< 0005: Trim Register                                                */
} VREF_Type;


/* -------------------------------------------------------------------------------- */
/* -----------     'VREF' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */


/* ------- VREF_VREFH_TRM                           ------ */
#define VREF_VREFH_TRM_TRIM_MASK                 (0x3FUL << VREF_VREFH_TRM_TRIM_SHIFT)               /*!< VREF_VREFH_TRM: TRIM Mask               */
#define VREF_VREFH_TRM_TRIM_SHIFT                0                                                   /*!< VREF_VREFH_TRM: TRIM Position           */
#define VREF_VREFH_TRM_TRIM(x)                   (((x)<<VREF_VREFH_TRM_TRIM_SHIFT)&VREF_VREFH_TRM_TRIM_MASK) /*!< VREF_VREFH_TRM                          */
#define VREF_VREFH_TRM_CHOPEN_MASK               (0x01UL << VREF_VREFH_TRM_CHOPEN_SHIFT)             /*!< VREF_VREFH_TRM: CHOPEN Mask             */
#define VREF_VREFH_TRM_CHOPEN_SHIFT              6                                                   /*!< VREF_VREFH_TRM: CHOPEN Position         */

/* ------- VREF_SC                                  ------ */
#define VREF_SC_MODE_LV_MASK                     (0x03UL << VREF_SC_MODE_LV_SHIFT)                   /*!< VREF_SC: MODE_LV Mask                   */
#define VREF_SC_MODE_LV_SHIFT                    0                                                   /*!< VREF_SC: MODE_LV Position               */
#define VREF_SC_MODE_LV(x)                       (((x)<<VREF_SC_MODE_LV_SHIFT)&VREF_SC_MODE_LV_MASK) /*!< VREF_SC                                 */
#define VREF_SC_VREFST_MASK                      (0x01UL << VREF_SC_VREFST_SHIFT)                    /*!< VREF_SC: VREFST Mask                    */
#define VREF_SC_VREFST_SHIFT                     2                                                   /*!< VREF_SC: VREFST Position                */
#define VREF_SC_REGEN_MASK                       (0x01UL << VREF_SC_REGEN_SHIFT)                     /*!< VREF_SC: REGEN Mask                     */
#define VREF_SC_REGEN_SHIFT                      6                                                   /*!< VREF_SC: REGEN Position                 */
#define VREF_SC_VREFEN_MASK                      (0x01UL << VREF_SC_VREFEN_SHIFT)                    /*!< VREF_SC: VREFEN Mask                    */
#define VREF_SC_VREFEN_SHIFT                     7                                                   /*!< VREF_SC: VREFEN Position                */

/* ------- VREF_VREFL_TRM                           ------ */
#define VREF_VREFL_TRM_VREFL_TRIM_MASK           (0x07UL << VREF_VREFL_TRM_VREFL_TRIM_SHIFT)         /*!< VREF_VREFL_TRM: VREFL_TRIM Mask         */
#define VREF_VREFL_TRM_VREFL_TRIM_SHIFT          0                                                   /*!< VREF_VREFL_TRM: VREFL_TRIM Position     */
#define VREF_VREFL_TRM_VREFL_TRIM(x)             (((x)<<VREF_VREFL_TRM_VREFL_TRIM_SHIFT)&VREF_VREFL_TRM_VREFL_TRIM_MASK) /*!< VREF_VREFL_TRM                          */
#define VREF_VREFL_TRM_VREFL_EN_MASK             (0x01UL << VREF_VREFL_TRM_VREFL_EN_SHIFT)           /*!< VREF_VREFL_TRM: VREFL_EN Mask           */
#define VREF_VREFL_TRM_VREFL_EN_SHIFT            3                                                   /*!< VREF_VREFL_TRM: VREFL_EN Position       */
#define VREF_VREFL_TRM_VREFL_SEL_MASK            (0x01UL << VREF_VREFL_TRM_VREFL_SEL_SHIFT)          /*!< VREF_VREFL_TRM: VREFL_SEL Mask          */
#define VREF_VREFL_TRM_VREFL_SEL_SHIFT           4                                                   /*!< VREF_VREFL_TRM: VREFL_SEL Position      */

/* -------------------------------------------------------------------------------- */
/* -----------     'VREF' Register Access macros                        ----------- */
/* -------------------------------------------------------------------------------- */

#define VREF_VREFH_TRM                 (VREF->VREFH_TRM)
#define VREF_SC                        (VREF->SC)
#define VREF_VREFL_TRM                 (VREF->VREFL_TRM)

/* ================================================================================ */
/* ================           WDOG (file:WDOG_MKM)                 ================ */
/* ================================================================================ */

/**
 * @brief Watchdog Timer
 */
typedef struct {                                /*!<       WDOG Structure                                               */
   __IO uint16_t  STCTRLH;                      /*!< 0000: Status and Control Register High                             */
   __IO uint16_t  STCTRLL;                      /*!< 0002: Status and Control Register Low                              */
   union {                                      /*!< 0000: (size=0004)                                                  */
      __IO uint32_t  TOVAL;                     /*!< 0004: Time-out Value Register High TOVALL:TOVALH                   */
      struct {                                  /*!< 0000: (size=0004)                                                  */
         __IO uint16_t  TOVALH;                 /*!< 0004: Time-out Value Register High                                 */
         __IO uint16_t  TOVALL;                 /*!< 0006: Time-out Value Register Low                                  */
      };
   };
   union {                                      /*!< 0000: (size=0004)                                                  */
      __IO uint32_t  WIN;                       /*!< 0008: Window Register (WINL:WINH)                                  */
      struct {                                  /*!< 0000: (size=0004)                                                  */
         __IO uint16_t  WINH;                   /*!< 0008: Window Register High                                         */
         __IO uint16_t  WINL;                   /*!< 000A: Window Register Low                                          */
      };
   };
   __IO uint16_t  REFRESH;                      /*!< 000C: Refresh Register                                             */
   __IO uint16_t  UNLOCK;                       /*!< 000E: Unlock Register                                              */
   union {                                      /*!< 0000: (size=0004)                                                  */
      __IO uint32_t  TMROUT;                    /*!< 0010: Timer Output Register (TMROUTL:TMROUTH)                      */
      struct {                                  /*!< 0000: (size=0004)                                                  */
         __IO uint16_t  TMROUTH;                /*!< 0010: Timer Output Register High                                   */
         __IO uint16_t  TMROUTL;                /*!< 0012: Timer Output Register Low                                    */
      };
   };
   __IO uint16_t  RSTCNT;                       /*!< 0014: Reset Count Register                                         */
   __IO uint16_t  PRESC;                        /*!< 0016: Prescaler Register                                           */
} WDOG_Type;


/* -------------------------------------------------------------------------------- */
/* -----------     'WDOG' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */


/* ------- WDOG_STCTRLH                             ------ */
#define WDOG_STCTRLH_WDOGEN_MASK                 (0x01UL << WDOG_STCTRLH_WDOGEN_SHIFT)               /*!< WDOG_STCTRLH: WDOGEN Mask               */
#define WDOG_STCTRLH_WDOGEN_SHIFT                0                                                   /*!< WDOG_STCTRLH: WDOGEN Position           */
#define WDOG_STCTRLH_CLKSRC_MASK                 (0x01UL << WDOG_STCTRLH_CLKSRC_SHIFT)               /*!< WDOG_STCTRLH: CLKSRC Mask               */
#define WDOG_STCTRLH_CLKSRC_SHIFT                1                                                   /*!< WDOG_STCTRLH: CLKSRC Position           */
#define WDOG_STCTRLH_IRQRSTEN_MASK               (0x01UL << WDOG_STCTRLH_IRQRSTEN_SHIFT)             /*!< WDOG_STCTRLH: IRQRSTEN Mask             */
#define WDOG_STCTRLH_IRQRSTEN_SHIFT              2                                                   /*!< WDOG_STCTRLH: IRQRSTEN Position         */
#define WDOG_STCTRLH_WINEN_MASK                  (0x01UL << WDOG_STCTRLH_WINEN_SHIFT)                /*!< WDOG_STCTRLH: WINEN Mask                */
#define WDOG_STCTRLH_WINEN_SHIFT                 3                                                   /*!< WDOG_STCTRLH: WINEN Position            */
#define WDOG_STCTRLH_ALLOWUPDATE_MASK            (0x01UL << WDOG_STCTRLH_ALLOWUPDATE_SHIFT)          /*!< WDOG_STCTRLH: ALLOWUPDATE Mask          */
#define WDOG_STCTRLH_ALLOWUPDATE_SHIFT           4                                                   /*!< WDOG_STCTRLH: ALLOWUPDATE Position      */
#define WDOG_STCTRLH_DBGEN_MASK                  (0x01UL << WDOG_STCTRLH_DBGEN_SHIFT)                /*!< WDOG_STCTRLH: DBGEN Mask                */
#define WDOG_STCTRLH_DBGEN_SHIFT                 5                                                   /*!< WDOG_STCTRLH: DBGEN Position            */
#define WDOG_STCTRLH_STOPEN_MASK                 (0x01UL << WDOG_STCTRLH_STOPEN_SHIFT)               /*!< WDOG_STCTRLH: STOPEN Mask               */
#define WDOG_STCTRLH_STOPEN_SHIFT                6                                                   /*!< WDOG_STCTRLH: STOPEN Position           */
#define WDOG_STCTRLH_WAITEN_MASK                 (0x01UL << WDOG_STCTRLH_WAITEN_SHIFT)               /*!< WDOG_STCTRLH: WAITEN Mask               */
#define WDOG_STCTRLH_WAITEN_SHIFT                7                                                   /*!< WDOG_STCTRLH: WAITEN Position           */
#define WDOG_STCTRLH_TESTWDOG_MASK               (0x01UL << WDOG_STCTRLH_TESTWDOG_SHIFT)             /*!< WDOG_STCTRLH: TESTWDOG Mask             */
#define WDOG_STCTRLH_TESTWDOG_SHIFT              10                                                  /*!< WDOG_STCTRLH: TESTWDOG Position         */
#define WDOG_STCTRLH_TESTSEL_MASK                (0x01UL << WDOG_STCTRLH_TESTSEL_SHIFT)              /*!< WDOG_STCTRLH: TESTSEL Mask              */
#define WDOG_STCTRLH_TESTSEL_SHIFT               11                                                  /*!< WDOG_STCTRLH: TESTSEL Position          */
#define WDOG_STCTRLH_BYTESEL_MASK                (0x03UL << WDOG_STCTRLH_BYTESEL_SHIFT)              /*!< WDOG_STCTRLH: BYTESEL Mask              */
#define WDOG_STCTRLH_BYTESEL_SHIFT               12                                                  /*!< WDOG_STCTRLH: BYTESEL Position          */
#define WDOG_STCTRLH_BYTESEL(x)                  (((x)<<WDOG_STCTRLH_BYTESEL_SHIFT)&WDOG_STCTRLH_BYTESEL_MASK) /*!< WDOG_STCTRLH                            */
#define WDOG_STCTRLH_DISTESTWDOG_MASK            (0x01UL << WDOG_STCTRLH_DISTESTWDOG_SHIFT)          /*!< WDOG_STCTRLH: DISTESTWDOG Mask          */
#define WDOG_STCTRLH_DISTESTWDOG_SHIFT           14                                                  /*!< WDOG_STCTRLH: DISTESTWDOG Position      */

/* ------- WDOG_STCTRLL                             ------ */
#define WDOG_STCTRLL_INTFLG_MASK                 (0x01UL << WDOG_STCTRLL_INTFLG_SHIFT)               /*!< WDOG_STCTRLL: INTFLG Mask               */
#define WDOG_STCTRLL_INTFLG_SHIFT                15                                                  /*!< WDOG_STCTRLL: INTFLG Position           */

/* ------- WDOG_TOVAL                               ------ */
#define WDOG_TOVAL_TOVAL_MASK                    (0xFFFFFFFFUL << WDOG_TOVAL_TOVAL_SHIFT)            /*!< WDOG_TOVAL: TOVAL Mask                  */
#define WDOG_TOVAL_TOVAL_SHIFT                   0                                                   /*!< WDOG_TOVAL: TOVAL Position              */
#define WDOG_TOVAL_TOVAL(x)                      (((x)<<WDOG_TOVAL_TOVAL_SHIFT)&WDOG_TOVAL_TOVAL_MASK) /*!< WDOG_TOVAL                              */

/* ------- WDOG_TOVALH                              ------ */
#define WDOG_TOVALH_TOVALHIGH_MASK               (0xFFFFUL << WDOG_TOVALH_TOVALHIGH_SHIFT)           /*!< WDOG_TOVALH: TOVALHIGH Mask             */
#define WDOG_TOVALH_TOVALHIGH_SHIFT              0                                                   /*!< WDOG_TOVALH: TOVALHIGH Position         */
#define WDOG_TOVALH_TOVALHIGH(x)                 (((x)<<WDOG_TOVALH_TOVALHIGH_SHIFT)&WDOG_TOVALH_TOVALHIGH_MASK) /*!< WDOG_TOVALH                             */

/* ------- WDOG_TOVALL                              ------ */
#define WDOG_TOVALL_TOVALLOW_MASK                (0xFFFFUL << WDOG_TOVALL_TOVALLOW_SHIFT)            /*!< WDOG_TOVALL: TOVALLOW Mask              */
#define WDOG_TOVALL_TOVALLOW_SHIFT               0                                                   /*!< WDOG_TOVALL: TOVALLOW Position          */
#define WDOG_TOVALL_TOVALLOW(x)                  (((x)<<WDOG_TOVALL_TOVALLOW_SHIFT)&WDOG_TOVALL_TOVALLOW_MASK) /*!< WDOG_TOVALL                             */

/* ------- WDOG_WIN                                 ------ */
#define WDOG_WIN_WIN_MASK                        (0xFFFFFFFFUL << WDOG_WIN_WIN_SHIFT)                /*!< WDOG_WIN: WIN Mask                      */
#define WDOG_WIN_WIN_SHIFT                       0                                                   /*!< WDOG_WIN: WIN Position                  */
#define WDOG_WIN_WIN(x)                          (((x)<<WDOG_WIN_WIN_SHIFT)&WDOG_WIN_WIN_MASK)       /*!< WDOG_WIN                                */

/* ------- WDOG_WINH                                ------ */
#define WDOG_WINH_WINHIGH_MASK                   (0xFFFFUL << WDOG_WINH_WINHIGH_SHIFT)               /*!< WDOG_WINH: WINHIGH Mask                 */
#define WDOG_WINH_WINHIGH_SHIFT                  0                                                   /*!< WDOG_WINH: WINHIGH Position             */
#define WDOG_WINH_WINHIGH(x)                     (((x)<<WDOG_WINH_WINHIGH_SHIFT)&WDOG_WINH_WINHIGH_MASK) /*!< WDOG_WINH                               */

/* ------- WDOG_WINL                                ------ */
#define WDOG_WINL_WINLOW_MASK                    (0xFFFFUL << WDOG_WINL_WINLOW_SHIFT)                /*!< WDOG_WINL: WINLOW Mask                  */
#define WDOG_WINL_WINLOW_SHIFT                   0                                                   /*!< WDOG_WINL: WINLOW Position              */
#define WDOG_WINL_WINLOW(x)                      (((x)<<WDOG_WINL_WINLOW_SHIFT)&WDOG_WINL_WINLOW_MASK) /*!< WDOG_WINL                               */

/* ------- WDOG_REFRESH                             ------ */
#define WDOG_REFRESH_WDOGREFRESH_MASK            (0xFFFFUL << WDOG_REFRESH_WDOGREFRESH_SHIFT)        /*!< WDOG_REFRESH: WDOGREFRESH Mask          */
#define WDOG_REFRESH_WDOGREFRESH_SHIFT           0                                                   /*!< WDOG_REFRESH: WDOGREFRESH Position      */
#define WDOG_REFRESH_WDOGREFRESH(x)              (((x)<<WDOG_REFRESH_WDOGREFRESH_SHIFT)&WDOG_REFRESH_WDOGREFRESH_MASK) /*!< WDOG_REFRESH                            */

/* ------- WDOG_UNLOCK                              ------ */
#define WDOG_UNLOCK_WDOGUNLOCK_MASK              (0xFFFFUL << WDOG_UNLOCK_WDOGUNLOCK_SHIFT)          /*!< WDOG_UNLOCK: WDOGUNLOCK Mask            */
#define WDOG_UNLOCK_WDOGUNLOCK_SHIFT             0                                                   /*!< WDOG_UNLOCK: WDOGUNLOCK Position        */
#define WDOG_UNLOCK_WDOGUNLOCK(x)                (((x)<<WDOG_UNLOCK_WDOGUNLOCK_SHIFT)&WDOG_UNLOCK_WDOGUNLOCK_MASK) /*!< WDOG_UNLOCK                             */

/* ------- WDOG_TMROUT                              ------ */
#define WDOG_TMROUT_TIMEROUTHIGH_MASK            (0xFFFFFFFFUL << WDOG_TMROUT_TIMEROUTHIGH_SHIFT)    /*!< WDOG_TMROUT: TIMEROUTHIGH Mask          */
#define WDOG_TMROUT_TIMEROUTHIGH_SHIFT           0                                                   /*!< WDOG_TMROUT: TIMEROUTHIGH Position      */
#define WDOG_TMROUT_TIMEROUTHIGH(x)              (((x)<<WDOG_TMROUT_TIMEROUTHIGH_SHIFT)&WDOG_TMROUT_TIMEROUTHIGH_MASK) /*!< WDOG_TMROUT                             */

/* ------- WDOG_TMROUTH                             ------ */
#define WDOG_TMROUTH_TIMEROUTHIGH_MASK           (0xFFFFUL << WDOG_TMROUTH_TIMEROUTHIGH_SHIFT)       /*!< WDOG_TMROUTH: TIMEROUTHIGH Mask         */
#define WDOG_TMROUTH_TIMEROUTHIGH_SHIFT          0                                                   /*!< WDOG_TMROUTH: TIMEROUTHIGH Position     */
#define WDOG_TMROUTH_TIMEROUTHIGH(x)             (((x)<<WDOG_TMROUTH_TIMEROUTHIGH_SHIFT)&WDOG_TMROUTH_TIMEROUTHIGH_MASK) /*!< WDOG_TMROUTH                            */

/* ------- WDOG_TMROUTL                             ------ */
#define WDOG_TMROUTL_TIMEROUTLOW_MASK            (0xFFFFUL << WDOG_TMROUTL_TIMEROUTLOW_SHIFT)        /*!< WDOG_TMROUTL: TIMEROUTLOW Mask          */
#define WDOG_TMROUTL_TIMEROUTLOW_SHIFT           0                                                   /*!< WDOG_TMROUTL: TIMEROUTLOW Position      */
#define WDOG_TMROUTL_TIMEROUTLOW(x)              (((x)<<WDOG_TMROUTL_TIMEROUTLOW_SHIFT)&WDOG_TMROUTL_TIMEROUTLOW_MASK) /*!< WDOG_TMROUTL                            */

/* ------- WDOG_RSTCNT                              ------ */
#define WDOG_RSTCNT_RSTCNT_MASK                  (0xFFFFUL << WDOG_RSTCNT_RSTCNT_SHIFT)              /*!< WDOG_RSTCNT: RSTCNT Mask                */
#define WDOG_RSTCNT_RSTCNT_SHIFT                 0                                                   /*!< WDOG_RSTCNT: RSTCNT Position            */
#define WDOG_RSTCNT_RSTCNT(x)                    (((x)<<WDOG_RSTCNT_RSTCNT_SHIFT)&WDOG_RSTCNT_RSTCNT_MASK) /*!< WDOG_RSTCNT                             */

/* ------- WDOG_PRESC                               ------ */
#define WDOG_PRESC_PRESCVAL_MASK                 (0x07UL << WDOG_PRESC_PRESCVAL_SHIFT)               /*!< WDOG_PRESC: PRESCVAL Mask               */
#define WDOG_PRESC_PRESCVAL_SHIFT                8                                                   /*!< WDOG_PRESC: PRESCVAL Position           */
#define WDOG_PRESC_PRESCVAL(x)                   (((x)<<WDOG_PRESC_PRESCVAL_SHIFT)&WDOG_PRESC_PRESCVAL_MASK) /*!< WDOG_PRESC                              */

/* -------------------------------------------------------------------------------- */
/* -----------     'WDOG' Register Access macros                        ----------- */
/* -------------------------------------------------------------------------------- */

#define WDOG_STCTRLH                   (WDOG->STCTRLH)
#define WDOG_STCTRLL                   (WDOG->STCTRLL)
#define WDOG_TOVAL                     (WDOG->TOVAL)
#define WDOG_TOVALH                    (WDOG->TOVALH)
#define WDOG_TOVALL                    (WDOG->TOVALL)
#define WDOG_WIN                       (WDOG->WIN)
#define WDOG_WINH                      (WDOG->WINH)
#define WDOG_WINL                      (WDOG->WINL)
#define WDOG_REFRESH                   (WDOG->REFRESH)
#define WDOG_UNLOCK                    (WDOG->UNLOCK)
#define WDOG_TMROUT                    (WDOG->TMROUT)
#define WDOG_TMROUTH                   (WDOG->TMROUTH)
#define WDOG_TMROUTL                   (WDOG->TMROUTL)
#define WDOG_RSTCNT                    (WDOG->RSTCNT)
#define WDOG_PRESC                     (WDOG->PRESC)
/* --------------------  End of section using anonymous unions  ------------------- */
#if defined(__CC_ARM)
  #pragma pop
#elif defined(__ICCARM__)
  /* leave anonymous unions enabled */
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__TMS470__)
  /* anonymous unions are enabled by default */
#elif defined(__TASKING__)
  #pragma warning restore
#else
  #warning Not supported compiler type
#endif

/* ================================================================================ */
/* ================              Peripheral memory map             ================ */
/* ================================================================================ */

#define CRC_BASE_PTR                   0x40034000UL
#define FTFA_BASE_PTR                  0x40020000UL
#define GPIOA_BASE_PTR                 0x400FF000UL
#define GPIOB_BASE_PTR                 0x400FF001UL
#define GPIOC_BASE_PTR                 0x400FF002UL
#define GPIOD_BASE_PTR                 0x400FF003UL
#define GPIOE_BASE_PTR                 0x400FF040UL
#define GPIOF_BASE_PTR                 0x400FF041UL
#define GPIOG_BASE_PTR                 0x400FF042UL
#define GPIOH_BASE_PTR                 0x400FF043UL
#define GPIOI_BASE_PTR                 0x400FF080UL
#define I2C0_BASE_PTR                  0x40067000UL
#define LLWU_BASE_PTR                  0x4007C000UL
#define LPTMR0_BASE_PTR                0x4003C000UL
#define MCG_BASE_PTR                   0x40064000UL
#define MCM_BASE_PTR                   0xF0003000UL
#define NV_BASE_PTR                    0x00000400UL
#define OSC0_BASE_PTR                  0x40066000UL
#define PORTA_BASE_PTR                 0x40046000UL
#define PORTB_BASE_PTR                 0x40047000UL
#define PORTC_BASE_PTR                 0x40048000UL
#define PORTD_BASE_PTR                 0x40049000UL
#define PORTE_BASE_PTR                 0x4004A000UL
#define PORTF_BASE_PTR                 0x4004B000UL
#define PORTG_BASE_PTR                 0x4004C000UL
#define PORTH_BASE_PTR                 0x4004D000UL
#define PORTI_BASE_PTR                 0x4004E000UL
#define RCM_BASE_PTR                   0x4007B000UL
#define RNG_BASE_PTR                   0x40029000UL
#define ROM_BASE_PTR                   0xF0002000UL
#define RTC_BASE_PTR                   0x40050000UL
#define RTC_RAM_BASE_PTR               0x40051000UL
#define SIM_BASE_PTR                   0x4003E000UL
#define SMC_BASE_PTR                   0x4007E000UL
#define SPI0_BASE_PTR                  0x40075000UL
#define SPI1_BASE_PTR                  0x40076000UL
#define SYST_BASE_PTR                  0xE000E010UL
#define UART0_BASE_PTR                 0x4006A000UL
#define UART1_BASE_PTR                 0x4006B000UL
#define UART2_BASE_PTR                 0x4006C000UL
#define UART3_BASE_PTR                 0x4006D000UL
#define VREF_BASE_PTR                  0x4006F000UL
#define WDOG_BASE_PTR                  0x40053000UL

/* ================================================================================ */
/* ================             Peripheral declarations            ================ */
/* ================================================================================ */

#define CRC                            ((volatile CRC_Type    *) CRC_BASE_PTR)
#define FTFA                           ((volatile FTFA_Type   *) FTFA_BASE_PTR)
#define GPIOA                          ((volatile GPIOA_Type  *) GPIOA_BASE_PTR)
#define GPIOB                          ((volatile GPIOB_Type  *) GPIOB_BASE_PTR)
#define GPIOC                          ((volatile GPIOC_Type  *) GPIOC_BASE_PTR)
#define GPIOD                          ((volatile GPIOD_Type  *) GPIOD_BASE_PTR)
#define GPIOE                          ((volatile GPIOE_Type  *) GPIOE_BASE_PTR)
#define GPIOF                          ((volatile GPIOF_Type  *) GPIOF_BASE_PTR)
#define GPIOG                          ((volatile GPIOG_Type  *) GPIOG_BASE_PTR)
#define GPIOH                          ((volatile GPIOH_Type  *) GPIOH_BASE_PTR)
#define GPIOI                          ((volatile GPIOI_Type  *) GPIOI_BASE_PTR)
#define I2C0                           ((volatile I2C0_Type   *) I2C0_BASE_PTR)
#define LLWU                           ((volatile LLWU_Type   *) LLWU_BASE_PTR)
#define LPTMR0                         ((volatile LPTMR0_Type *) LPTMR0_BASE_PTR)
#define MCG                            ((volatile MCG_Type    *) MCG_BASE_PTR)
#define MCM                            ((volatile MCM_Type    *) MCM_BASE_PTR)
#define NV                             ((volatile NV_Type     *) NV_BASE_PTR)
#define OSC0                           ((volatile OSC0_Type   *) OSC0_BASE_PTR)
#define PORTA                          ((volatile PORTA_Type  *) PORTA_BASE_PTR)
#define PORTB                          ((volatile PORTB_Type  *) PORTB_BASE_PTR)
#define PORTC                          ((volatile PORTC_Type  *) PORTC_BASE_PTR)
#define PORTD                          ((volatile PORTD_Type  *) PORTD_BASE_PTR)
#define PORTE                          ((volatile PORTE_Type  *) PORTE_BASE_PTR)
#define PORTF                          ((volatile PORTF_Type  *) PORTF_BASE_PTR)
#define PORTG                          ((volatile PORTG_Type  *) PORTG_BASE_PTR)
#define PORTH                          ((volatile PORTH_Type  *) PORTH_BASE_PTR)
#define PORTI                          ((volatile PORTI_Type  *) PORTI_BASE_PTR)
#define RCM                            ((volatile RCM_Type    *) RCM_BASE_PTR)
#define RNG                            ((volatile RNG_Type    *) RNG_BASE_PTR)
#define ROM                            ((volatile ROM_Type    *) ROM_BASE_PTR)
#define RTC                            ((volatile RTC_Type    *) RTC_BASE_PTR)
#define RTC_RAM                        ((volatile RTC_RAM_Type *) RTC_RAM_BASE_PTR)
#define SIM                            ((volatile SIM_Type    *) SIM_BASE_PTR)
#define SMC                            ((volatile SMC_Type    *) SMC_BASE_PTR)
#define SPI0                           ((volatile SPI0_Type   *) SPI0_BASE_PTR)
#define SPI1                           ((volatile SPI1_Type   *) SPI1_BASE_PTR)
#define SYST                           ((volatile SYST_Type   *) SYST_BASE_PTR)
#define UART0                          ((volatile UART0_Type  *) UART0_BASE_PTR)
#define UART1                          ((volatile UART1_Type  *) UART1_BASE_PTR)
#define UART2                          ((volatile UART2_Type  *) UART2_BASE_PTR)
#define UART3                          ((volatile UART3_Type  *) UART3_BASE_PTR)
#define VREF                           ((volatile VREF_Type   *) VREF_BASE_PTR)
#define WDOG                           ((volatile WDOG_Type   *) WDOG_BASE_PTR)

#ifdef __cplusplus
}
#endif


#endif  /* MCU_MKM33Z5 */

