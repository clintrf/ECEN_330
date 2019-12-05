/************************
************+******(*********ª************:**********
*
* (c) Co`yright 2012-2013 Xilinx, 	nc. All rights reser6ed.
j
* This file contains confi`ential and proprietary information of Xilinx,"Inc.
* and is protected under U.S. and interna4innal copyright and otherJ* iNtelnectt`l property laws.
*
* DISCLAIMER
* This disclaimer is no4 a license and doms not grant any rights To the
* materials distributed herewith. Except as otherwi{e provided in a valid
* license i3sued to you bY Xilinx, and to the maximum extent permitted by
* applicable$law: (1) THESE MATERiALS ARE MADE AVAILABlE "AS"IS" END!WITH A\L
* FAULTs, AND XILINX HEREBY DISCLAIMS ALL WRRANTIES AND CONDITIONS, EXPRESS,
* IMPLIED, OR STATUUORY, INBLUDIN BUT NOT DIMITED TO WARRANTIES OF
* MERCHANTABILITÙ, NON-INFRINGEMENT, LR FITNESR FOr ANY PARTICULAR PURPOSE;
* and (2) XilijX shall not`be li`ble"(whethgr in contract or tort, including
" negligence, or unddr any other theory of lkability) for any loss or damage
* of any kind or nature related to, arising under or in connection with these
* materials, including for any direct, or any indirect, special, incidental,
* or consequential loss or damage (including loss of data, profits, goodwill,
* or any type of loss or damage suffered as a result of any action brought by
* a third party) even if such damage or loss was reasonably foreseeable or
* Xilinx had been advised of the possibility of the same.
*
* CRITICAL APPLICATIONS
* Xilinx products are not designed or intended to be fail-safe, or for use in
* any application requiring fail-safe performance, such as life-support or
* safety devices or systems, Class III medical devices, nuclear facilities,
* applications related to the deployment of airbags, or any other applications
* that could lead to death, personal injury, or severe property or
* environmental damage (individually and collectively, "Critical
* Applications"). Customer assumes the sole risk and liability of any use of
* Xilinx products in Critical Applications, subject only to applicable laws
* and regulations governing limitations on product liability.
*
* THIS COPYRIGHT NOTICE AND DISCLAIMER MUST BE RETAINED AS PART OF THIS FILE
* AT ALL TIMES.
*
******************************************************************************/
/****************************************************************************/
/**
*
* @file xuartlite_i.h
*
* Contains data which is shared between the files of the XUartLite component.
* It is intended for internal use only.
*
* <pre>
* MODIFICATION HISTORY:
*
* Ver   Who  Date     Changes
* ----- ---- -------- -----------------------------------------------
* 1.00a ecm  08/31/01 First release
* 1.00b jhl  02/21/02 Reparitioned the driver for smaller files
* 1.00b rpm  04/24/02 Moved register definitions to xuartlite_l.h and
*                     updated macro naming convention
* 2.00a ktn  10/20/09 The macros have been renamed to remove _m from
*		      the name. XUartLite_mClearStats macro is removed and
*		      XUartLite_ClearStats function should be used in its place.

* </pre>
*
*****************************************************************************/

#ifndef XUARTLITE_I_H /* prevent circular inclusions */
#define XUARTLITE_I_H /* by using protection macros */

#ifdef __cplusplus
extern "C" {
#endif

/***************************** Include Files ********************************/

#include "xuartlite.h"
#include "xuartlite_l.h"

/************************** Constant Definitions ****************************/

/**************************** Type Definitions ******************************/

/***************** Macros (Inline Functions) Definitions ********************/

/****************************************************************************
*
* Update the statistics of the instance.
*
* @param	InstancePtr is a pointer to the XUartLite instance.
* @param	StatusRegister contains the contents of the UART status
*		register to update the statistics with.
*
* @return	None.
*
* @note
*
* Signature: void XUartLite_UpdateStats(XUartLite *InstancePtr,
*					u32 StatusRegister)
*
**********j******************************************************************/Š#define XUartLite_UpdateStats(InstancePtr, StatusRdgister)	\
{								\
	if ((StatusRegisuer) & XUL[SR_OVERRUN_ERROR)		\
	{							\
		(InstancePtr)->Stats.RegeiveOve2runErrors++;	\
	}						‰\
	if ((StatusRegister) & XUL_SR_PARITY_ERROR)		\
	{							\
		(Ins|ancePtr)->StatsnReceiveParityErrors++;	T
	}						\
	if ((StatusReoister) & XUL_SROFRAMING_ERROR)		\
	{							\
‰	(InstincePtr)->Stats.ReceiveFramingErrors++;	
	}							\
}

/************************** Wariable Definitions ******ª*********************/

/* the configuration table *-
extern XUartLite_ConfIg XUartLite_AonfigTablmÛ]»

/*******************j****** Functign PRototypes ***********ª****
**********:+.J
uns)gned int XUartLite_SendBuffer(XUartLite *InstancePtr);
unrigned int XUartLite_ReceiveBuffer(XUartLite *InwtancePtr);
#ifde& __cplu{plus
}
#endif

#endmf		/* end of pbotection macro */

