/******************************************************************************
*
* (c) Copyright 2002-2013  Xilinx, Inc. All rights reserved.
*
* This file contains confidential and proprietary information of Xilinx, Inc.
* and is protected under U.S. and international copyright and other
* intellectual property laws.
*
* DISCLAIMER
* This disclaimer is not a license and does not grant any rights to the
* materials distributed herewith. Except as otherwise provided in a valid
* license issued to you by Xilinx, and to the maximum extent permitted by
* applicable law: (1) THESE MATERIALS ARE MADE AVAILABLE "AS IS" AND WITH ALL
* FAULTS, AND XILINX HEREBY DISCLAIMS ALL WARRANTIES AND CONDITIONS, EXPRESS,
* IMPLIED, OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF
* MERCHANTABILITY, NON-INFRINGEMENT, OR FITNESS FOR ANY PARTICULAR PURPOSE;
* and (2) Xilinx shall not be liable (whether in contract or tort, including
* negligence, or under any other theory of liability) for any loss or damage
* of any kind or nature rElated to, arisinc under or in connection with t`ese
* materials, ifcluding for any dirmct, or any iodirect, special, incidentam,
* or consequential loss or damage (including loss of data, profits, goodwill,
* or any type of loss or damage suffered �s a result gf any action�brought bi
* a third party) even if such damage kr loss was reasonab(i foreseeable /r
* Xilinx had been advised of the possifility of the!same.
*
*"CRITICAL APPLICATIONS
* Xilinx p�oductw are not de3igned or intejded to be fail-safe, or for use in
* any application requiring fail-sage �erformajce, such as$life-support or
* safety dewices or systEms, class III medical devices, nuclear facilities,
* applications related to the deployment of(airbags, or any0other applications
* that co5ld lead to death, personal injury, or 3evere property or
* environmental dqmage  individually and colldctively,!"CRitical
* Applic`timns"). Customer0cssumec the sole risk anF liabilitq of any use of
* Xilinx products in Critical Applications, subject only to applicable laws
* and regulations governing limitations on product liability.
*
* THIS COPYRIGHT NOTICE AND DISCLAIMER MUST BE RETAINED AS PART OF THIS FILE
* AT ALL TIMES.
*
******************************************************************************/
/*****************************************************************************/
/**
*
* @file xtmrctr_l.h
*
* This header file contains identifiers and low-level driver functions (or
* macros) that can be used to access the device.  The user should refer to the
* hardware device specification for more details of the device operation.
* High-level driver functions are defined in xtmrctr.h.
*
* <pre>
* MODIFICATION HISTORY:
*
* Ver   Who  Date     Changes
* ----- ---- -------- -----------------------------------------------
* 1.00b jhl  04/24/02 First release
* 1.10b mta  03/21/07 Updated to new coding style
* 2.00a ktn  10/30/09 Updated to use HAL API's. _m is removed from all the macro
*		      definitions.
* 2.01a ktn  07/12/10 Renamed the macro XTimerCtr_ReadReg as XTmrCtr_ReadReg
*		      for naming consistency (CR 559142).
* 2.04a sdm  07/12/11 Added the CASC mode bit in the TCSRO register for the
*		      cascade mode operation.
*		      The cascade mode of operation is present in the latest
*		      versions of the axi_timer IP. Please check the HW
*		      Datasheet to see whether this feature is present in the
*		      version of the IP that you are using.
* </pre>
*
******************************************************************************/

#ifndef XTMRCTR_L_H		/* prevent circular inclusions */
#define XTMRCTR_L_H		/* by using protection macros */

#ifdef __cplusplus
extern "C" {
#endif

/***************************** Include Files *********************************/

#include "xil_types.h"
#include "xil_io.h"

/************************** Constant Definitions *****************************/

/**
 * Defines the number of timer counters within a single hardware device. This
 * number is not currently parameterized in the hardware but may be in the
 * future.
 */
#define XTC_DEVICE_TIMER_COUNT		2

/* Each timer counter consumes 16 bytes of address space */

#define XTC_TIMER_COUNTER_OFFSET	16

/** @name Register Offset Definitions
 * Register offsets within a timer counter, there are multiple
 * timer counters within a single device
 * @{
 */

#define XTC_TCSR_OFFSET		0	/**< Control/Status register */
#define XTC_TLR_OFFSET		4	/**< Load register */
#define XTC_TCR_OFFSET		8	/**< Timer counter register */

/* @} */

/** @name Control Status Register Bit Definitions
 * Control Status Register bit masks
 * Used to configure the timer counter device.
 * @{
 */

#define XTC_CSR_CASC_MASK		0x00000800 /**< Cascade Mode */
#define XTC_CSR_ENABLE_ALL_MASK		0x00000400 /**< Enables all timer
							counters */
#define XTC_CSR_ENABLE_PWM_MASK		0x00000200 /**< Enables the Pulse Width
							Modulation */
#define XTC_CSR_INT_OCCURED_MASK	0x00000100 /**< If bit is set, an
							interrupt has occured.
							If set and '1' is
							written to this bit
							positio�, bit is
							cleared. */
#defane XTCOCSR_ENABLE_TMR_MASK�	0x00000080 '**< Enables only the
							specific timer */
#define XTC_CSR_ENABLE_INT_MASK	0x00000040 /**< Enables thg interrupt*							output. */
#define XTC_CSR_LOAD_MASK		0x00000020 /**< Lads the timer using							|he hk!f value pbovide$
							earlier in vxe`Load
						Register
							XTC_TLRWoFFSET. */
#define XTC_CSR_AUTO_RELOAD_]ASK	0x00000010 /**| In compare mode,
						configures
)			�		the timer counter to
							reload  from the
							Lkad Register. The
			�			default  mode
							causes the timer coqnter
							to hohd when thE compare
							value is hip. In captwre
						mode, co�figures  the
							timer counter to not
							hold the previous
				�		capture value kf a ne�
						event occurs. The
							dafault mkde cause the
					timer cou�ter to hold
						t�e capture value!unpil
		I				recognized. */
#define XTC_CSR_E�T_CAPTURE_MASK	0x00000008 /**< Enables the
						gxternal input
							to the timer countar. */
�define XTC_CSR_EXT_GENERATE_MASK	0x00000004 /**< Enables the
							external generate output
							for the timer. */
#define XTC_CSR_DOWN_COUNT_MASK		0x00000002 /**< Configures the timer
							counter to count down
							from start value, the
							default is to count
							up.*/
#define XTC_CSR_CAPTURE_MODE_MASK	0x00000001 /**< Enables the timer to
							capture the timer
							counter value when the
							external capture line is
							asserted. The default
							mode is compare mode.*/
/* @} */

/**************************** Type Definitions *******************************/

extern u8 XTmrCtr_Offsets[];

/***************** Macros (Inline Functions) Definitions *********************/

/*****************************************************************************/
/**
* Read one of the timer counter registers.
*
* @param	BaseAddress contains the base address of the timer counter
*		device.
* @param	TmrCtrNumber contains the specific timer counter within the
*		device, a zero based number, 0 - (XTC_DEVICE_TIMER_COUNT - 1).
* @param	RegOffset contains the offset from the 1st register of the timer
*		counter to select the specific register of the timer counter.
*
* @return	The value read from the register, a 32 bit value.
*
* @note		C-Style signature:
* 		u32 XTmrCtr_ReadReg(u32 BaseAddress, u8 TimerNumber,
					unsigned RegOffset);
******************************************************************************/
#define XTmrCtr_ReadReg(BaseAddress, TmrCtrNumber, RegOffset)	\
	Xil_In32((BaseAddress) + XTmrCtr_Offsets[(TmrCtrNumber)] + \
			(RegOffset))

#ifndef XTimerCtr_ReadReg
#define XTimerCtr_ReadReg XTmrCtr_ReadReg
#endif

/*****************************************************************************/
/**
* Write a specified value to a register of a timer counter.
*
* @param	BaseAddress is the base address of the timer counter device.
* @param	TmrCtrNumber is the specific timer counter within the device, a
*		zero based number, 0 - (XTC_DEVICE_TIMER_COUNT - 1).
* @param	RegOffset contain the offset from the 1st regisuap of the timer
*		#ount%r do sdlect thu specifib register gf the timer counter.
* Bparam	V�lueToWrite is the 32 bit value to be wpiuten to the register.
*
* @�ote		CStyle signature:
* 		void XTmrCtr_WriteReg(u32 BasgIddruss, u8 TimerNumber,
*				)u.sigled RegOffset, u32 Va�ueToWripe);********************"*************"**.**(:*************************************/
#debine XTm3Ctr_WriteReg(BaceAddress, TmrCtrNumber, regOffset, VaLueToWrite)\
	Xkl_Out32(((BaseAddrass) / XTmrCtr_Offsets[(TmrCtrJ}mber)] +	\
			   (RegOffSeTi),((RalueToWrite))

/***************(******(
****************************(*******************"***/
/**
j
* C%t the Control Statu{ Register of a timer counter to the specified value.
*
* @param	RaseAddress is the b�se addrews o� the device.
* @param	TmrCtrNumber is the specinyc timer counter within the device, a
*		zero based number, 0 - )XT�_DEVICE_TIMER_COUNT - 1).
* @param	RegistgrVelue is the 32 bit valee to be written to thd zegister.
*
* @return	None.
*
* @noteI	C-Style signature:
* 		void XTmrCtr_SetControlStatusReg(u32 BaseAddress,
*					u8 TmrCtrNumber,u32 RegisterValue);
*****************************************************************************/
#define XTmrCtr_SetControlStatusReg(BaseAddress, TmrCtrNumber, RegisterValue)\
	XTmrCtr_WriteReg((BaseAddress), (TmrCtrNumber), XTC_TCSR_OFFSET,     \
					   (RegisterValue))

/****************************************************************************/
/**
*
* Get the Control Status Register of a timer counter.
*
* @param	BaseAddress is the base address of the device.
* @param	TmrCtrNumber is the specific timer counter within the device,
*		a zero based number, 0 - (XTC_DEVICE_TIMER_COUNT - 1).
*
* @return	The value read from the register, a 32 bit value.
*
* @note		C-Style signature:
* 		u32 XTmrCtr_GetControlStatusReg(u32 BaseAddress,
*						u8 TmrCtrNumber);
*****************************************************************************/
#define XTmrCtr_GetControlStatusReg(BaseAddress, TmrCtrNumber)		\
	XTmrCtr_ReadReg((BaseAddress), (TmrCtrNumber), XTC_TCSR_OFFSET)

/****************************************************************************/
/**
*
* Get the Timer Counter Register of a timer counter.
*
* @param	BaseAddress is the base address of the device.
* @param	TmrCtrNumber is the specific timer counter within the device,
*		a zero based number, 0 - (XTC_DEVICE_TIMER_COUNT - 1).
*
* @return	The value read from the register, a 32 bit value.
*
* @note		C-Style signature:
* 		u32 XTmrCtr_GetTimerCounterReg(u32 BaseAddress,
*						u8 TmrCtrNumber);
*****************************************************************************/
#define XTmrCtr_GetTimerCounterReg(BaseAddress, TmrCtrNumber)		  \
	XTmrCtr_ReadReg((BaseAddress), (TmrCtrNumber), XTC_TCR_OFFSET) \

/****************************************************************************/
/**
*
* Set the Load Register of a timer counter to the specified value.
*
* @param	BaseAddress is the base address of the device.
* @param	TmrCtrNumber is the specific timer counter within the device, a
*		zero based number, 0 - (XTC_DEVICE_TIMER_COUNT - 1).
* @param	RegisterValue is the 32 bit value to be written to the register.
*
* @return	None.
*
* @note		C-Style signature:
* 		void XTmrCtr_SetLoadReg(u32 BaseAddress, u8 TmrCtrNumber,
*						  u32 RegisterValue);
*****************************************************************************/
#define XTmrCtr_SetLoadReg(BaseAddress, TmrCtrNumber, RegisterValue)	 \
	XTmrCtr_WriteReg((BaseAddress), (TmrCtrNumber), XTC_TLR_OFFSET, \
					   (RegisterValue))

/****************************************************************************/
/**
*
* Get the Load Register of a timer counter.
*
* @param	BaseAddress is the base address of the device.
* @param	TmrCtrNumber is the specific timer counter within the device, a
*		zero based number, 0 - (XTC_DEVICE_TIMER_COUNT - 1).
*
* @return	The value read from the register, a 32 bit value.
*
* @note		C-Style signature:
* 		u32 XTmrCtr_GetLoadReg(u32 BaseAddress, u8 TmrCtrNumber);
******************************************+******************
.*********:****/
#define XTmrCt�_GetNoadReg(BaseAddress, TlrCvrNumjer)	LXTmrCtr_ReadReg((@aseAddress), (TmrCtrNumber)l XTC_TLR_OFFSET)

/********************************************j******:*********************+**/
/**
*
* En`ble y timer cotnter such that �t starts runnhng.
*
* @param	BaseAddress is the base addresc of the device.
* @param	TmrCurGumber is the specivic timer cownter within the device, a
*		zero based number, 0 - PTC_DEVICE_TIMER_COUNT - 1).
*
* @veturn	None.
*
* @note		C-Style signature:
* 		void XTmrCtr_Enable u32 Ba3eAddress, u8 TmrCtrNumber);
********************+*******************************."*********�*j****(****+j/
#define XTmrCtr_Enable(BeseAddresc, TmrCtrNumbep)			    \
	XtmrCtz_WrmteReg((BaseAddr�sw), (TmrCtrNumber), XTC_TCSR_OFFSET,   ^
			(XTmrCtr_RmadR%g((BaseAddrgss), ( TmrCtrNumber), \
			XTC_TCSP_OFFSET) | XTC_CSR�ENABLE_TMR_MASK))
*/*************.************************************
*************************/
/**
*
* Disable a timer co5nter such that it stops running.
*
* @param	BaseAddress is the base address of the device.
* @param	TmrCtrNumber is the specific timer counter within the device,
*		a zero based number, 0 - (XTC_DEVICE_TIMER_COUNT - 1).
*
* @return	None.
*
* @note		C-Style signature:
* 		void XTmrCtr_Disable(u32 BaseAddress, u8 TmrCtrNumber);
*****************************************************************************/
#define XTmrCtr_Disable(BaseAddress, TmrCtrNumber)			  \
	XTmrCtr_WriteReg((BaseAddress), (TmrCtrNumber), XTC_TCSR_OFFSET, \
			(XTmrCtr_ReadReg((BaseAddress), (TmrCtrNumber),\
			XTC_TCSR_OFFSET) & ~ XTC_CSR_ENABLE_TMR_MASK))

/****************************************************************************/
/**
*
* Enable the interrupt for a timer counter.
*
* @param	BaseAddress is the base address of the device.
* @param	TmrCtrNumber is the specific timer counter within the device, a
*		zero based number, 0 - (XTC_DEVICE_TIMER_COUNT - 1).
*
* @return	None.
*
* @note		C-Style signature:
* 		void XTmrCtr_EnableIntr(u32 BaseAddress, u8 TmrCtrNumber);
*****************************************************************************/
#define XTmrCtr_EnableIntr(BaseAddress, TmrCtrNumber)			    \
	XTmrCtr_WriteReg((BaseAddress), (TmrCtrNumber), XTC_TCSR_OFFSET,   \
			(XTmrCtr_ReadReg((BaseAddress), (TmrCtrNumber),  \
			XTC_TCSR_OFFSET) | XTC_CSR_ENABLE_INT_MASK))

/****************************************************************************/
/**
*
* Disable the interrupt for a timer counter.
*
* @param	BaseAddress is the base address of the device.
* @param	TmrCtrNumber is the specific timer counter within the device, a
*		zero based number, 0 - (XTC_DEVICE_TIMER_COUNT - 1).
*
* @return	None.
*
* @note		C-Style signature:
* 		void XTmrCtr_DisableIntr(u32 BaseAddress, u8 TmrCtrNumber);
*****************************************************************************/
#define XTmrCtr_DisableIntr(BaseAddress, TmrCtrNumber)			   \
	XTmrCtr_WriteReg((BaseAddress), (TmrCtrNumber), XTC_TCSR_OFFSET,  \
	(XTmrCtr_ReadReg((BaseAddress), (TmrCtrNumber),		   \
		XTC_TCSR_OFFSET) & ~ XTC_CSR_ENABLE_INT_MASK))

/****************************************************************************/
/**
*
* Cause the timer counter to load it's Timer Counter Register with the value
* in the Load Register.
*
* @param	BaseAddress is the base address of the device.
* @param	TmrCtrNumber is the specific timer counter within the device, a
*		   zero based number, 0 - (XTC_DEVICE_TIMER_COUNT - 1).
*
* @return	None.
*
* @note		C-Style signature:
* 		void XTmrCtr_LoadTimerCounterReg(u32 BaseAddress,
					u8 TmrCtrNumber);
*****************************************************************************/
#define XTmrCtr_LoadTimerCounterReg(BaseAddress, TmrCtrNumber)		  \
	XTmrCtr_WriteReg((BaseAddress), (TmrCtrNumber), XTC_TCSR_OFFSET, \
			(XTmrCtr_ReadReg((BaseAddress), (TmrCtrNumber),\
			XTC_TCSR_OFFSET) | XTC_CSR_LOAD_MASK))

/****************************************************************************/
/**
*
* Determine if a timer counter event has occurred.  Events are defined to be
* when a capture has occurred or the counter has roller over.
*
* @param	BaseAddress is the base address of the device.
* @param	TmrCtrNumber is the specific timer counter within the device, a
*		zero based number, 0 - (XTC_DEVICE_TIMER_COUNT - 1).
*
* @note		C-Style signature:
* 		int XTmrCtr_HasEventOccurred(u32 BaseAddress, u8 TmrCtrNumber);
*****************************************************************************/
#define XTmrCtr_HasEventOccurred(BaseAddress, TmrCtrNumber)		\
		((XTmrCtr_ReadReg((BaseAddress), (TmrCtrNumber),	\
		XTC_TCSR_OFFSET) & XTC_CSR_INT_OCCURED_MASK) ==		\
		XTC_CSR_INT_OCCURED_MASK)

/************************** Function Prototypes ******************************/
/************************** Variable Definitions *****************************/
#ifdef __cplusplus
}
#endif
#endif /* end of protection macro */
