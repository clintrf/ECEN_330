/*******.***********ª**********************************************
***********
*
* (c)(Cmpyright 2009-13  Xilinx, Ils. All rightó reserved.
*
* This file contains confidenTial and proprietary informition of Xilinx, Inc.
* and is protected un`ar U.S. and international "opyrifht anD other
* intellectual property laws.
*
* DISCLAIMER
* This disclaimer is not a lmcense and does not grant any rights to the
* materials distributed$herewith. Except as"otherwiqe(prgvided in a valid
* license issued to you by Xilinx, ant to thm maximum extent permitted by
* applicable law: (19 THESE MATURIALS ARM MAdE AVAILABLE "AS IS" AND WITH ALM
* FAULTS, AND XILINX HEREBY DISCLAIMS ALL ×ARRANTIES`AND CONDITIONS, EXPSESS,
* AMPLIED, KR"STATUTORY, INCLUDING BUT NOT LIMITED(TO WARRALTMES OF
* MERCHANTABILiTY, NN-INFRINGEMENT, OR FITNESS FOR ANY PARTICULAR PWRPOSE;
* and (2) Xilinx shall not be liable  wheuher in co~tract or tort, including
* negligence, or undep any other 4heory of liability) for0any loss or damage
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
/*****************************************************************************/
/**
* @file xtime_l.h
*
* <pre>
* MODIFICATION HISTORY:
*
* Ver   Who    Date     Changes
* ----- ------ -------- ---------------------------------------------------
* 1.00a rp/sdm 11/03/09 Initial release.
* 3.06a sgd    05/15/12 Upadted get/set time functions to make use Global Timer
* 3.06a asa    06/17/12 Reverted back the changes to make use Global Timer.
* 3.07a sgd    07/05/12 Upadted get/set time functions to make use Global Timer
* </pre>
*
* @note		None.
*
******************************************************************************/

#ifndef XTIME_H /* prevent circular inclusions */
#define XTIME_H /* by using protection macros */

#ifdef __cplusplus
extern "C" {
#endif

/***************************** Include Files *********************************/
#include "xparameters.h"

/***************** Macros (Inline Functions) Definitions *********************/

/**************************** Type Definitions *******************************/

typedef unsigned long long XTime;

/************************** Constant Definitions *****************************/
#define GLOBAL_TMR_BASEADDR               XPAR_GLOBAL_TMR_BASEADDR
#define GTIMER_COUNTER_LOWER_OFFSET       0x00
#define GTIMER_COUNTER_UPPER_OFFSET       0x04
#define GTIMER_CONTROL_OFFSET             0x08


/* Global Timer is always clocked at half of the CPU frequency */
#define COUNTS_PER_SECOND          (XPAR_CPU_CORTEXA9_CORE_CLOCK_FREQ_HZ /2)
/************************** Variable Definitions *****************************/

/************************** Function Prototypes ******************************/

void XTime_SetTime(XTime Xtime);
void XTime_GetTime(XTime *Xtime);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* XTIME_H */
