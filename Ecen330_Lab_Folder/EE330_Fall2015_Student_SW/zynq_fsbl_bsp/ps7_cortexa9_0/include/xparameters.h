/* Definition for CPU ID */
#define XPAR_CPU_ID 0

/* Definitions for peripheral PS7_CORTEXA9_0 */
#define XPAR_PS7_CORTEXA9_0_CPU_CLK_FREQ_HZ 650000000


/******************************************************************/

/* Canonical definitions for peripheral PS7_CORTEXA9_0 */
#define XPAR_CPU_CORTEXA9_0_CPU_CLK_FREQ_HZ 650000000


/******************************************************************/

#include "xparameters_ps.h"

#define STDIN_BASEADDRESS 0xE0001000
#define STDOUT_BASEADDRESS 0xE0001000

/******************************************************************/

/* Definitions for driver AXI_DISPCTRL */
#define XPAR_AXI_DISPCTRL_NUM_INSTANCES 2

/* Definitions for peripheral AXI_DISPCTRL_0 */
#define XPAR_AXI_DISPCTRL_0_DEVICE_ID 0
#define XPAR_AXI_DISPCTRL_0_S_AXI_BASEADDR 0x43C00000
#define XPAR_AXI_DISPCTRL_0_S_AXI_HIGHADDR 0x43C0FFFF


/* Definitions for peripheral AXI_DISPCTRL_1 */
#define XPAR_AXI_DISPCTRL_1_DEVICE_ID 1
#define XPAR_AXI_DISPCTRL_1_S_AXI_BASEADDR 0x43C10000
#define XPAR_AXI_DISPCTRL_1_S_AXI_HIGHADDR 0x43C1FFFF


/******************************************************************/

/* Definitions for driver AXI_I2S_ADI */
#define XPAR_AXI_I2S_ADI_NUM_INSTANCES 1

/* Definitions for peripheral AXI_I2S_ADI_1 */
#define XPAR_AXI_I2S_ADI_1_DEVICE_ID 0
#define XPAR_AXI_I2S_ADI_1_S_AXI_BASEADDR 0x43C20000
#define XPAR_AXI_I2S_ADI_1_S_AXI_HIGHADDR 0x43C2FFFF


/******************************************************************/

/* Definitions for driver AXIVDMA */
#define XPAR_XAXIVDMA_NUM_INSTANCES 2

/* Definitions for peripheral AXI_VDMA_0 */
#define XPAR_AXI_VDMA_0_DEVICE_ID 0
#define XPAR_AXI_VDMA_0_BASEADDR 0x43000000
#define XPAR_AXI_VDMA_0_HIGHADDR 0x4300FFFF
#define XPAR_AXI_VDMA_0_NUM_FSTORES 3
#define XPAR_AXI_VDMA_0_INCLUDE_MM2S 1
#define XPAR_AXI_VDMA_0_INCLUDE_MM2S_DRE 0
#define XPAR_AXI_VDMA_0_M_AXI_MM2S_DATA_WIDTH 64
#define XPAR_AXI_VDMA_0_INCLUDE_S2MM 0
#define XPAR_AXI_VDMA_0_INCLUDE_S2MM_DRE 0
#define XPAR_AXI_VDMA_0_M_AXI_S2MM_DATA_WIDTH 64
#define XPAR_AXI_VDMA_0_AXI_MM2S_ACLK_FREQ_HZ 0
#define XPAR_AXI_VDMA_0_AXI_S2MM_ACLK_FREQ_HZ 0
#define XPAR_AXI_VDMA_0_MM2S_GENLOCK_MODE 1
#define XPAR_AXI_VDMA_0_MM2S_GENLOCK_NUM_MASTERS 1
#define XPAR_AXI_VDMA_0_S2MM_GENLOCK_MODE 0
#define XPAR_AXI_VDMA_0_S2MM_GENLOCK_NUM_MASTERS 1
#define XPAR_AXI_VDMA_0_INCLUDE_SG 0
#define XPAR_AXI_VDMA_0_ENABLE_VIDPRMTR_READS 1
#define XPAR_AXI_VDMA_0_USE_FSYNC 1
#define XPAR_AXI_VDMA_0_FLUSH_ON_FSYNC 1
#define XPAR_AXI_VDMA_0_MM2S_LINEBUFFER_DEPTH 2048
#define XPAR_AXI_VDMA_0_S2MM_LINEBUFFER_DEPTH 512
#define XPAR_AXI_VDMA_0_INCLUDE_INTERNAL_GENLOCK 1
#define XPAR_AXI_VDMA_0_S2MM_SOF_ENABLE 1
#define XPAR_AXI_VDMA_0_M_AXIS_MM2S_TDATA_WIDTH 32
#define XPAR_AXI_VDMA_0_S_AXIS_S2MM_TDATA_WIDTH 32
#define XPAR_AXI_VDMA_0_ENABLE_DEBUG_INFO_1 0
#define XPAR_AXI_VDMA_0_ENABLE_DEBUG_INFO_5 0
#define XPAR_AXI_VDMA_0_ENABLE_DEBUG_INFO_6 0
#define XPAR_AXI_VDMA_0_ENABLE_DEBUG_INFO_7 0
#define XPAR_AXI_VDMA_0_ENABLE_DEBUG_INFO_9 0
#define XPAR_AXI_VDMA_0_ENABLE_DEBUG_INFO_13 0
#define XPAR_AXI_VDMA_0_ENABLE_DEBUG_INFO_14 0
#define XPAR_AXI_VDMA_0_ENABLE_DEBUG_INFO_15 0
#define XPAR_AXI_VDMA_0_ENABLE_DEBUG_ALL 1


/* Definitions for peripheral AXI_VDMA_1 */
#define XPAR_AXI_VDMA_1_DEVICE_ID 1
#define XPAR_AXI_VDMA_1_BASEADDR 0x43010000
#define XPAR_AXI_VDMA_1_HIGHADDR 0x4301FFFF
#define XPAR_AXI_VDMA_1_NUM_FSTORES 3
#define XPAR_AXI_VDMA_1_INCLUDE_MM2S 1
#define XPAR_AXI_VDMA_1_INCLUDE_MM2S_DRE 0
#define XPAR_AXI_VDMA_1_M_AXI_MM2S_DATA_WIDTH 64
#define XPAR_AXI_VDMA_1_INCLUDE_S2MM 0
#define XPAR_AXI_VDMA_1_INCLUDE_S2MM_DRE 0
#define XPAR_AXI_VDMA_1_M_AXI_S2MM_DATA_WIDTH 64
#define XPAR_AXI_VDMA_1_AXI_MM2S_ACLK_FREQ_HZ 0
#define XPAR_AXI_VDMA_1_AXI_S2MM_ACLK_FREQ_HZ 0
#define XPAR_AXI_VDMA_1_MM2S_GENLOCK_MODE 1
#define XPAR_AXI_VDMA_1_MM2S_GENLOCK_NUM_MASTERS 1
#define XPAR_AXI_VDMA_1_S2MM_GENLOCK_MODE 0
#define XPAR_AXI_VDMA_1_S2MM_GENLOCK_NUM_MASTERS 1
#define XPAR_AXI_VDMA_1_INCLUDE_SG 0
#define XPAR_AXI_VDMA_1_ENABLE_VIDPRMTR_READS 1
#define XPAR_AXI_VDMA_1_USE_FSYNC 1
#define XPAR_AXI_VDMA_1_FLUSH_ON_FSYNC 1
#define XPAR_AXI_VDMA_1_MM2S_LINEBUFFER_DEPTH 2048
#define XPAR_AXI_VDMA_1_S2MM_LINEBUFFER_DEPTH 512
#define XPAR_AXI_VDMA_1_INCLUDE_INTERNAL_GENLOCK 1
#define XPAR_AXI_VDMA_1_S2MM_SOF_ENABLE 1
#define XPAR_AXI_VDMA_1_M_AXIS_MM2S_TDATA_WIDTH 32
#define XPAR_AXI_VDMA_1_S_AXIS_S2MM_TDATA_WIDTH 32
#define XPAR_AXI_VDMA_1_ENABLE_DEBUG_INFO_1 0
#define XPAR_AXI_VDMA_1_ENABLE_DEBUG_INFO_5 0
#define XPAR_AXI_VDMA_1_ENABLE_DEBUG_INFO_6 0
#define XPAR_AXI_VDMA_1_ENABLE_DEBUG_INFO_7 0
#define XPAR_AXI_VDMA_1_ENABLE_DEBUG_INFO_9 0
#define XPAR_AXI_VDMA_1_ENABLE_DEBUG_INFO_13 0
#define XPAR_AXI_VDMA_1_ENABLE_DEBUG_INFO_14 0
#define XPAR_AXI_VDMA_1_ENABLE_DEBUG_INFO_15 0
#define XPAR_AXI_VDMA_1_ENABLE_DEBUG_ALL 1


/******************************************************************/

/* Canonical definitions for peripheral AXI_VDMA_0 */
#define XPAR_AXIVDMA_0_DEVICE_ID XPAR_AXI_VDMA_0_DEVICE_ID
#define XPAR_AXIVDMA_0_BASEADDR 0x43000000
#define XPAR_AXIVDMA_0_HIGHADDR 0x4300FFFF
#define XPAR_AXIVDMA_0_NUM_FSTORES 3
#define XPAR_AXIVDMA_0_INCLUDE_MM2S 1
#define XPAR_AXIVDMA_0_INCLUDE_MM2S_DRE 0
#define XPAR_AXIVDMA_0_M_AXI_MM2S_DATA_WIDTH 64
#define XPAR_AXIVDMA_0_INCLUDE_S2MM 0
#define XPAR_AXIVDMA_0_INCLUDE_S2MM_DRE 0
#define XPAR_AXIVDMA_0_M_AXI_S2MM_DATA_WIDTH 64
#define XPAR_AXIVDMA_0_AXI_MM2S_ACLK_FREQ_HZ 0
#define XPAR_AXIVDMA_0_AXI_S2MM_ACLK_FREQ_HZ 0
#define XPAR_AXIVDMA_0_MM2S_GENLOCK_MODE 1
#define XPAR_AXIVDMA_0_MM2S_GENLOCK_NUM_MASTERS 1
#define XPAR_AXIVDMA_0_S2MM_GENLOCK_MODE 0
#define XPAR_AXIVDMA_0_S2MM_GENLOCK_NUM_MASTERS 1
#define XPAR_AXIVDMA_0_INCLUDE_SG 0
#define XPAR_AXIVDMA_0_ENABLE_VIDPRMTR_READS 1
#define XPAR_AXIVDMA_0_USE_FSYNC 1
#define XPAR_AXIVDMA_0_FLUSH_ON_FSYNC 1
#define XPAR_AXIVDMA_0_MM2S_LINEBUFFER_DEPTH 2048
#define XPAR_AXIVDMA_0_S2MM_LINEBUFFER_DEPTH 512
#define XPAR_AXIVDMA_0_INCLUDE_INTERNAL_GENLOCK 1
#define XPAR_AXIVDMA_0_S2MM_SOF_ENABLE 1
#define XPAR_AXIVDMA_0_M_AXIS_MM2S_TDATA_WIDTH 32
#define XPAR_AXIVDMA_0_S_AXIS_S2MM_TDATA_WIDTH 32
#define XPAR_AXIVDMA_0_ENABLE_DEBUG_INFO_1 0
#define XPAR_AXIVDMA_0_ENABLE_DEBUG_INFO_5 0
#define XPAR_AXIVDMA_0_ENABLE_DEBUG_INFO_6 0
#define XPAR_AXIVDMA_0_ENABLE_DEBUG_INFO_7 0
#define XPAR_AXIVDMA_0_ENABLE_DEBUG_INFO_9 0
#define XPAR_AXIVDMA_0_ENABLE_DEBUG_INFO_13 0
#define XPAR_AXIVDMA_0_ENABLE_DEBUG_INFO_14 0
#define XPAR_AXIVDMA_0_ENABLE_DEBUG_INFO_15 0
#define XPAR_AXIVDMA_0_ENABLE_DEBUG_ALL 1

/* Canonical definitions for peripheral AXI_VDMA_1 */
#define XPAR_AXIVDMA_1_DEVICE_ID XPAR_AXI_VDMA_1_DEVICE_ID
#define XPAR_AXIVDMA_1_BASEADDR 0x43010000
#define XPAR_AXIVDMA_1_HIGHADDR 0x4301FFFF
#define XPAR_AXIVDMA_1_NUM_FSTORES 3
#define XPAR_AXIVDMA_1_INCLUDE_MM2S 1
#define XPAR_AXIVDMA_1_INCLUDE_MM2S_DRE 0
#define XPAR_AXIVDMA_1_M_AXI_MM2S_DATA_WIDTH 64
#define XPAR_AXIVDMA_1_INCLUDE_S2MM 0
#define XPAR_AXIVDMA_1_INCLUDE_S2MM_DRE 0
#define XPAR_AXIVDMA_1_M_AXI_S2MM_DATA_WIDTH 64
#define XPAR_AXIVDMA_1_AXI_MM2S_ACLK_FREQ_HZ 0
#define XPAR_AXIVDMA_1_AXI_S2MM_ACLK_FREQ_HZ 0
#define XPAR_AXIVDMA_1_MM2S_GENLOCK_MODE 1
#define XPAR_AXIVDMA_1_MM2S_GENLOCK_NUM_MASTERS 1
#define XPAR_AXIVDMA_1_S2MM_GENLOCK_MODE 0
#define XPAR_AXIVDMA_1_S2MM_GENLOCK_NUM_MASTERS 1
#define XPAR_AXIVDMA_1_INCLUDE_SG 0
#define XPAR_AXIVDMA_1_ENABLE_VIDPRMTR_READS 1
#define XPAR_AXIVDMA_1_USE_FSYNC 1
#define XPAR_AXIVDMA_1_FLUSH_ON_FSYNC 1
#define XPAR_AXIVDMA_1_MM2S_LINEBUFFER_DEPTH 2048
#define XPAR_AXIVDMA_1_S2MM_LINEBUFFER_DEPTH 512
#define XPAR_AXIVDMA_1_INCLUDE_INTERNAL_GENLOCK 1
#define XPAR_AXIVDMA_1_S2MM_SOF_ENABLE 1
#define XPAR_AXIVDMA_1_M_AXIS_MM2S_TDATA_WIDTH 32
#define XPAR_AXIVDMA_1_S_AXIS_S2MM_TDATA_WIDTH 32
#define XPAR_AXIVDMA_1_ENABLE_DEBUG_INFO_1 0
#define XPAR_AXIVDMA_1_ENABLE_DEBUG_INFO_5 0
#define XPAR_AXIVDMA_1_ENABLE_DEBUG_INFO_6 0
#define XPAR_AXIVDMA_1_ENABLE_DEBUG_INFO_7 0
#define XPAR_AXIVDMA_1_ENABLE_DEBUG_INFO_9 0
#define XPAR_AXIVDMA_1_ENABLE_DEBUG_INFO_13 0
#define XPAR_AXIVDMA_1_ENABLE_DEBUG_INFO_14 0
#define XPAR_AXIVDMA_1_ENABLE_DEBUG_INFO_15 0
#define XPAR_AXIVDMA_1_ENABLE_DEBUG_ALL 1


/******************************************************************/

/* Definitions for driver DEVCFG */
#define XPAR_XDCFG_NUM_INSTANCES 1

/* Definitions for peripheral PS7_DEV_CFG_0 */
#define XPAR_PS7_DEV_CFG_0_DEVICE_ID 0
#define XPAR_PS7_DEV_CFG_0_BASEADDR 0xF8007000
#define XPAR_PS7_DEV_CFG_0_HIGHADDR 0xF80070FF


/******************************************************************/

/* Canonical definitions for peripheral PS7_DEV_CFG_0 */
#define XPAR_XDCFG_0_DEVICE_ID XPAR_PS7_DEV_CFG_0_DEVICE_ID
#define XPAR_XDCFG_0_BASEADDR 0xF8007000
#define XPAR_XDCFG_0_HIGHADDR 0xF80070FF


/******************************************************************/

/* Definitions for driver DMAPS */
#define XPAR_XDMAPS_NUM_INSTANCES 2

/* Definitions for peripheral PS7_DMA_NS */
#define XPAR_PS7_DMA_NS_DEVICE_ID 0
#define XPAR_PS7_DMA_NS_BASEADDR 0xF8004000
#define XPAR_PS7_DMA_NS_HIGHADDR 0xF8004FFF


/* Definitions for peripheral PS7_DMA_S */
#define XPAR_PS7_DMA_S_DEVICE_ID 1
#define XPAR_PS7_DMA_S_BASEADDR 0xF8003000
#define XPAR_PS7_DMA_S_HIGHADDR 0xF8003FFF


/******************************************************************/

/* Canonical definitions for peripheral PS7_DMA_NS */
#define XPAR_XDMAPS_0_DEVICE_ID XPAR_PS7_DMA_NS_DEVICE_ID
#define XPAR_XDMAPS_0_BASEADDR 0xF8004000
#define XPAR_XDMAPS_0_HIGHADDR 0xF8004FFF

/* Canonical definitions for peripheral PS7_DMA_S */
#define XPAR_XDMAPS_1_DEVICE_ID XPAR_PS7_DMA_S_DEVICE_ID
#define XPAR_XDMAPS_1_BASEADDR 0xF8003000
#define XPAR_XDMAPS_1_HIGHADDR 0xF8003FFF


/******************************************************************/

/* Definitions for driver EMACPS */
#define XPAR_XEMACPS_NUM_INSTANCES 1

/* Definitions for peripheral PS7_ETHERNET_0 */
#define XPAR_PS7_ETHERNET_0_DEVICE_ID 0
#define XPAR_PS7_ETHERNET_0_BASEADDR 0xE000B000
#define XPAR_PS7_ETHERNET_0_HIGHADDR 0xE000BFFF
#define XPAR_PS7_ETHERNET_0_ENET_CLK_FREQ_HZ 125000000
#define XPAR_PS7_ETHERNET_0_ENET_SLCR_1000MBPS_DIV0 8
#define XPAR_PS7_ETHERNET_0_ENET_SLCR_1000MBPS_DIV1 1
#define XPAR_PS7_ETHERNET_0_ENET_SLCR_100MBPS_DIV0 8
#define XPAR_PS7_ETHERNET_0_ENET_SLCR_100MBPS_DIV1 5
#define XPAR_PS7_ETHERNET_0_ENET_SLCR_10MBPS_DIV0 8
#define XPAR_PS7_ETHERNET_0_ENET_SLCR_10MBPS_DIV1 50


/******************************************************************/

/* Canonical definitions for peripheral PS7_ETHERNET_0 */
#define XPAR_XEMACPS_0_DEVICE_ID XPAR_PS7_ETHERNET_0_DEVICE_ID
#define XPAR_XEMACPS_0_BASEADDR 0xE000B000
#define XPAR_XEMACPS_0_HIGHADDR 0xE000BFFF
#define XPAR_XEMACPS_0_ENET_CLK_FREQ_HZ 125000000
#define XPAR_XEMACPS_0_ENET_SLCR_1000Mbps_DIV0 8
#define XPAR_XEMACPS_0_ENET_SLCR_1000Mbps_DIV1 1
#define XPAR_XEMACPS_0_ENET_SLCR_100Mbps_DIV0 8
#define XPAR_XEMACPS_0_ENET_SLCR_100Mbps_DIV1 5
#define XPAR_XEMACPS_0_ENET_SLCR_10Mbps_DIV0 8
#define XPAR_XEMACPS_0_ENET_SLCR_10Mbps_DIV1 50


/******************************************************************/


/* Definitions for peripheral PS7_AFI_0 */
#define XPAR_PS7_AFI_0_S_AXI_BASEADDR 0xF8008000
#define XPAR_PS7_AFI_0_S_AXI_HIGHADDR 0xF8008FFF


/* Definitions for peripheral PS7_AFI_1 */
#define XPAR_PS7_AFI_1_S_AXI_BASEADDR 0xF8009000
#define XPAR_PS7_AFI_1_S_AXI_HIGHADDR 0xF8009FFF


/* Definitions for peripheral PS7_AFI_2 */
#define XPAR_PS7_AFI_2_S_AXI_BASEADDR 0xF800A000
#define XPAR_PS7_AFI_2_S_AXI_HIGHADDR 0xF800AFFF


/* Definitions for peripheral PS7_AFI_3 */
#define XPAR_PS7_AFI_3_S_AXI_BASEADDR 0xF800B000
#define XPAR_PS7_AFI_3_S_AXI_HIGHADDR 0xF800BFFF


/* Definitions for peripheral PS7_CORESIGHT_COMP_0 */
#define XPAR_PS7_CORESIGHT_COMP_0_S_AXI_BASEADDR 0xF8800000
#define XPAR_PS7_CORESIGHT_COMP_0_S_AXI_HIGHADDR 0xF88FFFFF


/* Definitions for peripheral PS7_DDR_0 */
#define XPAR_PS7_DDR_0_S_AXI_BASEADDR 0x00100000
#define XPAR_PS7_DDR_0_S_AXI_HIGHADDR 0x1FFFFFFF


/* Definitions for peripheral PS7_DDRC_0 */
#define XPAR_PS7_DDRC_0_S_AXI_BASEADDR 0xF8006000
#define XPAR_PS7_DDRC_0_S_AXI_HIGHADDR 0xF8006FFF


/* Definitions for peripheral PS7_GLOBALTIMER_0 */
#define XPAR_PS7_GLOBALTIMER_0_S_AXI_BASEADDR 0xF8F00200
#define XPAR_PS7_GLOBALTIMER_0_S_AXI_HIGHADDR 0xF8F002FF


/* Definitions for peripheral PS7_GPV_0 */
#define XPAR_PS7_GPV_0_S_AXI_BASEADDR 0xF8900000
#define XPAR_PS7_GPV_0_S_AXI_HIGHADDR 0xF89FFFFF


/* Definitions for peripheral PS7_INTC_DIST_0 */
#define XPAR_PS7_INTC_DIST_0_S_AXI_BASEADDR 0xF8F01000
#define XPAR_PS7_INTC_DIST_0_S_AXI_HIGHADDR 0xF8F01FFF


/* Definitions for peripheral PS7_IOP_BUS_CONFIG_0 */
#define XPAR_PS7_IOP_BUS_CONFIG_0_S_AXI_BASEADDR 0xE0200000
#define XPAR_PS7_IOP_BUS_CONFIG_0_S_AXI_HIGHADDR 0xE0200FFF


/* Definitions for peripheral PS7_L2CACHEC_0 */
#define XPAR_PS7_L2CACHEC_0_S_AXI_BASEADDR 0xF8F02000
#define XPAR_PS7_L2CACHEC_0_S_AXI_HIGHADDR 0xF8F02FFF


/* Definitions for peripheral PS7_OCMC_0 */
#define XPAR_PS7_OCMC_0_S_AXI_BASEADDR 0xF800C000
#define XPAR_PS7_OCMC_0_S_AXI_HIGHADDR 0xF800CFFF


/* Definitions for peripheral PS7_PL310_0 */
#define XPAR_PS7_PL310_0_S_AXI_BASEADDR 0xF8F02000
#define XPAR_PS7_PL310_0_S_AXI_HIGHADDR 0xF8F02FFF


/* Definitions for peripheral PS7_PMU_0 */
#define XPAR_PS7_PMU_0_S_AXI_BASEADDR 0xF8891000
#define XPAR_PS7_PMU_0_S_AXI_HIGHADDR 0xF8891FFF
#define XPAR_PS7_PMU_0_PMU1_S_AXI_BASEADDR 0xF8893000
#define XPAR_PS7_PMU_0_PMU1_S_AXI_HIGHADDR 0xF8893FFF


/* Definitions for peripheral PS7_QSPI_LINEAR_0 */
#define XPAR_PS7_QSPI_LINEAR_0_S_AXI_BASEADDR 0xFC000000
#define XPAR_PS7_QSPI_LINEAR_0_S_AXI_HIGHADDR 0xFCFFFFFF


/* Definitions for peripheral PS7_RAM_0 */
#define XPAR_PS7_RAM_0_S_AXI_BASEADDR 0x00000000
#define XPAR_PS7_RAM_0_S_AXI_HIGHADDR 0x0003FFFF


/* Definitions for peripheral PS7_RAM_1 */
#define XPAR_PS7_RAM_1_S_AXI_BASEADDR 0xFFFC0000
#define XPAR_PS7_RAM_1_S_AXI_HIGHADDR 0xFFFFFFFF


/* Definitions for peripheral PS7_SCUC_0 */
#define XPAR_PS7_SCUC_0_S_AXI_BASEADDR 0xF8F00000
#define XPAR_PS7_SCUC_0_S_AXI_HIGHADDR 0xF8F000FC


/* Definitions for peripheral PS7_SLCR_0 */
#define XPAR_PS7_SLCR_0_S_AXI_BASEADDR 0xF8000000
#define XPAR_PS7_SLCR_0_S_AXI_HIGHADDR 0xF8000FFF


/******************************************************************/

/* Definitions for driver GPIO */
#define XPAR_XGPIO_NUM_INSTANCES 5

/* Definitions for peripheral AXI_GPIO_TFT_CONTROL */
#define XPAR_AXI_GPIO_TFT_CONTROL_BASEADDR 0x41230000
#define XPAR_AXI_GPIO_TFT_CONTROL_HIGHADDR 0x4123FFFF
#define XPAR_AXI_GPIO_TFT_CONTROL_DEVICE_ID 0
#define XPAR_AXI_GPIO_TFT_CONTROL_INTERRUPT_PRESENT 0
#define XPAR_AXI_GPIO_TFT_CONTROL_IS_DUAL 0


/* Definitions for peripheral AXI_GPIO_TFT_DATA_BUS */
#define XPAR_AXI_GPIO_TFT_DATA_BUS_BASEADDR 0x41240000
#define XPAR_AXI_GPIO_TFT_DATA_BUS_HIGHADDR 0x4124FFFF
#define XPAR_AXI_GPIO_TFT_DATA_BUS_DEVICE_ID 1
#define XPAR_AXI_GPIO_TFT_DATA_BUS_INTERRUPT_PRESENT 0
#define XPAR_AXI_GPIO_TFT_DATA_BUS_IS_DUAL 0


/* Definitions for peripheral LEDS */
#define XPAR_LEDS_BASEADDR 0x41210000
#define XPAR_LEDS_HIGHADDR 0x4121FFFF
#define XPAR_LEDS_DEVICE_ID 2
#define XPAR_LEDS_INTERRUPT_PRESENT 0
#define XPAR_LEDS_IS_DUAL 0


/* Definitions for peripheral PUSH_BUTTONS */
#define XPAR_PUSH_BUTTONS_BASEADDR 0x41200000
#define XPAR_PUSH_BUTTONS_HIGHADDR 0x4120FFFF
#define XPAR_PUSH_BUTTONS_DEVICE_ID 3
#define XPAR_PUSH_BUTTONS_INTERRUPT_PRESENT 0
#define XPAR_PUSH_BUTTONS_IS_DUAL 0


/* Definitions for peripheral SLIDE_SWITCHES */
#define XPAR_SLIDE_SWITCHES_BASEADDR 0x41220000
#define XPAR_SLIDE_SWITCHES_HIGHADDR 0x4122FFFF
#define XPAR_SLIDE_SWITCHES_DEVICE_ID 4
#define XPAR_SLIDE_SWITCHES_INTERRUPT_PRESENT 0
#define XPAR_SLIDE_SWITCHES_IS_DUAL 0


/******************************************************************/

/* Canonical definitions for peripheral AXI_GPIO_TFT_CONTROL */
#define XPAR_GPIO_0_BASEADDR 0x41230000
#define XPAR_GPIO_0_HIGHADDR 0x4123FFFF
#define XPAR_GPIO_0_DEVICE_ID XPAR_AXI_GPIO_TFT_CONTROL_DEVICE_ID
#define XPAR_GPIO_0_INTERRUPT_PRESENT 0
#define XPAR_GPIO_0_IS_DUAL 0

/* Canonical definitions for peripheral AXI_GPIO_TFT_DATA_BUS */
#define XPAR_GPIO_1_BASEADDR 0x41240000
#define XPAR_GPIO_1_HIGHADDR 0x4124FFFF
#define XPAR_GPIO_1_DEVICE_ID XPAR_AXI_GPIO_TFT_DATA_BUS_DEVICE_ID
#define XPAR_GPIO_1_INTERRUPT_PRESENT 0
#define XPAR_GPIO_1_IS_DUAL 0

/* Canonical definitions for peripheral LEDS */
#define XPAR_GPIO_2_BASEADDR 0x41210000
#define XPAR_GPIO_2_HIGHADDR 0x4121FFFF
#define XPAR_GPIO_2_DEVICE_ID XPAR_LEDS_DEVICE_ID
#define XPAR_GPIO_2_INTERRUPT_PRESENT 0
#define XPAR_GPIO_2_IS_DUAL 0

/* Canonical definitions for peripheral PUSH_BUTTONS */
#define XPAR_GPIO_3_BASEADDR 0x41200000
#define XPAR_GPIO_3_HIGHADDR 0x4120FFFF
#define XPAR_GPIO_3_DEVICE_ID XPAR_PUSH_BUTTONS_DEVICE_ID
#define XPAR_GPIO_3_INTERRUPT_PRESENT 0
#define XPAR_GPIO_3_IS_DUAL 0

/* Canonical definitions for peripheral SLIDE_SWITCHES */
#define XPAR_GPIO_4_BASEADDR 0x41220000
#define XPAR_GPIO_4_HIGHADDR 0x4122FFFF
#define XPAR_GPIO_4_DEVICE_ID XPAR_SLIDE_SWITCHES_DEVICE_ID
#define XPAR_GPIO_4_INTERRUPT_PRESENT 0
#define XPAR_GPIO_4_IS_DUAL 0


/******************************************************************/

/* Definitions for driver GPIOPS */
#define XPAR_XGPIOPS_NUM_INSTANCES 1

/* Definitions for peripheral PS7_GPIO_0 */
#define XPAR_PS7_GPIO_0_DEVICE_ID 0
#define XPAR_PS7_GPIO_0_BASEADDR 0xE000A000
#define XPAR_PS7_GPIO_0_HIGHADDR 0xE000AFFF


/******************************************************************/

/* Canonical definitions for peripheral PS7_GPIO_0 */
#define XPAR_XGPIOPS_0_DEVICE_ID XPAR_PS7_GPIO_0_DEVICE_ID
#define XPAR_XGPIOPS_0_BASEADDR 0xE000A000
#define XPAR_XGPIOPS_0_HIGHADDR 0xE000AFFF


/******************************************************************/

/* Definitions for driver IICPS */
#define XPAR_XIICPS_NUM_INSTANCES 1

/* Definitions for peripheral PS7_I2C_0 */
#define XPAR_PS7_I2C_0_DEVICE_ID 0
#define XPAR_PS7_I2C_0_BASEADDR 0xE0004000
#define XPAR_PS7_I2C_0_HIGHADDR 0xE0004FFF
#define XPAR_PS7_I2C_0_I2C_CLK_FREQ_HZ 108333336


/******************************************************************/

/* Canonical definitions for peripheral PS7_I2C_0 */
#define XPAR_XIICPS_0_DEVICE_ID XPAR_PS7_I2C_0_DEVICE_ID
#define XPAR_XIICPS_0_BASEADDR 0xE0004000
#define XPAR_XIICPS_0_HIGHADDR 0xE0004FFF
#define XPAR_XIICPS_0_I2C_CLK_FREQ_HZ 108333336


/******************************************************************/

/* Definitions for driver QSPIPS */
#define XPAR_XQSPIPS_NUM_INSTANCES 1

/* Definitions for peripheral PS7_QSPI_0 */
#define XPAR_PS7_QSPI_0_DEVICE_ID 0
#define XPAR_PS7_QSPI_0_BASEADDR 0xE000D000
#define XPAR_PS7_QSPI_0_HIGHADDR 0xE000DFFF
#define XPAR_PS7_QSPI_0_QSPI_CLK_FREQ_HZ 200000000
#define XPAR_PS7_QSPI_0_QSPI_MODE 0


/******************************************************************/

/* Canonical definitions for peripheral PS7_QSPI_0 */
#define XPAR_XQSPIPS_0_DEVICE_ID XPAR_PS7_QSPI_0_DEVICE_ID
#define XPAR_XQSPIPS_0_BASEADDR 0xE000D000
#define XPAR_XQSPIPS_0_HIGHADDR 0xE000DFFF
#define XPAR_XQSPIPS_0_QSPI_CLK_FREQ_HZ 200000000
#define XPAR_XQSPIPS_0_QSPI_MODE 0


/******************************************************************/


/***Definitions for Core_nIRQ/nFIQ interrupts ****/
/* Definitions for driver SCUGIC */
#define XPAR_XSCUGIC_NUM_INSTANCES 1

/* Definitions for peripheral PS7_SCUGIC_0 */
#define XPAR_PS7_SCUGIC_0_DEVICE_ID 0
#define XPAR_PS7_SCUGIC_0_BASEADDR 0xF8F00100
#define XPAR_PS7_SCUGIC_0_HIGHADDR 0xF8F001FF
#define XPAR_PS7_SCUGIC_0_DIST_BASEADDR 0xF8F01000


/******************************************************************/

/* Canonical definitions for peripheral PS7_SCUGIC_0 */
#define XPAR_SCUGIC_0_DEVICE_ID 0
#define XPAR_SCUGIC_0_CPU_BASEADDR 0xF8F00100
#define XPAR_SCUGIC_0_CPU_HIGHADDR 0xF8F001FF
#define XPAR_SCUGIC_0_DIST_BASEADDR 0xF8F01000


/******************************************************************/

/* Definitions for driver SCUTIMER */
#define XPAR_XSCUTIMER_NUM_INSTANCES 1

/* Definitions for peripheral PS7_SCUTIMER_0 */
#define XPAR_PS7_SCUTIMER_0_DEVICE_ID 0
#define XPAR_PS7_SCUTIMER_0_BASEADDR 0xF8F00600
#define XPAR_PS7_SCUTIMER_0_HIGHADDR 0xF8F0061F


/******************************************************************/

/* Canonical definitions for peripheral PS7_SCUTIMER_0 */
#define XPAR_XSCUTIMER_0_DEVICE_ID XPAR_PS7_SCUTIMER_0_DEVICE_ID
#define XPAR_XSCUTIMER_0_BASEADDR 0xF8F00600
#define XPAR_XSCUTIMER_0_HIGHADDR 0xF8F0061F


/******************************************************************/

/* Definitions for driver SCUWDT */
#define XPAR_XSCUWDT_NUM_INSTANCES 1

/* Definitions for peripheral PS7_SCUWDT_0 */
#define XPAR_PS7_SCUWDT_0_DEVICE_ID 0
#define XPAR_PS7_SCUWDT_0_BASEADDR 0xF8F00620
#define XPAR_PS7_SCUWDT_0_HIGHADDR 0xF8F006FF


/******************************************************************/

/* Canonical definitions for peripheral PS7_SCUWDT_0 */
#define XPAR_SCUWDT_0_DEVICE_ID XPAR_PS7_SCUWDT_0_DEVICE_ID
#define XPAR_SCUWDT_0_BASEADDR 0xF8F00620
#define XPAR_SCUWDT_0_HIGHADDR 0xF8F006FF


/******************************************************************/

/* Definitions for driver SDPS */
#define XPAR_XSDPS_NUM_INSTANCES 1

/* Definitions for peripheral PS7_SD_0 */
#define XPAR_PS7_SD_0_DEVICE_ID 0
#define XPAR_PS7_SD_0_BASEADDR 0xE0100000
#define XPAR_PS7_SD_0_HIGHADDR 0xE0100FFF
#define XPAR_PS7_SD_0_SDIO_CLK_FREQ_HZ 50000000


/******************************************************************/

/* Canonical definitions for peripheral PS7_SD_0 */
#define XPAR_XSDPS_0_DEVICE_ID XPAR_PS7_SD_0_DEVICE_ID
#define XPAR_XSDPS_0_BASEADDR 0xE0100000
#define XPAR_XSDPS_0_HIGHADDR 0xE0100FFF
#define XPAR_XSDPS_0_SDIO_CLK_FREQ_HZ 50000000


/******************************************************************/

/* Definitions for driver SPI */
#define XPAR_XSPI_NUM_INSTANCES 1

/* Definitions for peripheral SPI_TFT_0 */
#define XPAR_SPI_TFT_0_DEVICE_ID 0
#define XPAR_SPI_TFT_0_BASEADDR 0x41E00000
#define XPAR_SPI_TFT_0_HIGHADDR 0x41E0FFFF
#define XPAR_SPI_TFT_0_FIFO_DEPTH 16
#define XPAR_SPI_TFT_0_FIFO_EXIST 1
#define XPAR_SPI_TFT_0_SPI_SLAVE_ONLY 0
#define XPAR_SPI_TFT_0_NUM_SS_BITS 2
#define XPAR_SPI_TFT_0_NUM_TRANSFER_BITS 8
#define XPAR_SPI_TFT_0_SPI_MODE 0
#define XPAR_SPI_TFT_0_TYPE_OF_AXI4_INTERFACE 0
#define XPAR_SPI_TFT_0_AXI4_BASEADDR 0
#define XPAR_SPI_TFT_0_AXI4_HIGHADDR 0
#define XPAR_SPI_TFT_0_XIP_MODE 0

/* Canonical definitions for peripheral SPI_TFT_0 */
#define XPAR_SPI_0_DEVICE_ID 0
#define XPAR_SPI_0_BASEADDR 0x41E00000
#define XPAR_SPI_0_HIGHADDR 0x41E0FFFF
#define XPAR_SPI_0_FIFO_DEPTH 16
#define XPAR_SPI_0_FIFO_EXIST 1
#define XPAR_SPI_0_SPI_SLAVE_ONLY 0
#define XPAR_SPI_0_NUM_SS_BITS 2
#define XPAR_SPI_0_NUM_TRANSFER_BITS 8
#define XPAR_SPI_0_SPI_MODE 0
#define XPAR_SPI_0_TYPE_OF_AXI4_INTERFACE 0
#define XPAR_SPI_0_AXI4_BASEADDR 0
#define XPAR_SPI_0_AXI4_HIGHADDR 0
#define XPAR_SPI_0_XIP_MODE 0
#define XPAR_SPI_0_USE_STARTUP 0



/******************************************************************/

/* Definitions for driver SYSMON */
#define XPAR_XSYSMON_NUM_INSTANCES 1

/* Definitions for peripheral AXI_XADC_0 */
#define XPAR_AXI_XADC_0_DEVICE_ID 0
#define XPAR_AXI_XADC_0_BASEADDR 0x43C30000
#define XPAR_AXI_XADC_0_HIGHADDR 0x43C3FFFF
#define XPAR_AXI_XADC_0_INCLUDE_INTR 1


/******************************************************************/

/* Canonical definitions for peripheral AXI_XADC_0 */
#define XPAR_SYSMON_0_DEVICE_ID XPAR_AXI_XADC_0_DEVICE_ID
#define XPAR_SYSMON_0_BASEADDR 0x43C30000
#define XPAR_SYSMON_0_HIGHADDR 0x43C3FFFF
#define XPAR_SYSMON_0_INCLUDE_INTR 1


/******************************************************************/

/* Definitions for driver TMRCTR */
#define XPAR_XTMRCTR_NUM_INSTANCES 3

/* Definitions for peripheral AXI_TIMER_0 */
#define XPAR_AXI_TIMER_0_DEVICE_ID 0
#define XPAR_AXI_TIMER_0_BASEADDR 0x42800000
#define XPAR_AXI_TIMER_0_HIGHADDR 0x4280FFFF
#define XPAR_AXI_TIMER_0_CLOCK_FREQ_HZ 100000000


/* Definitions for peripheral AXI_TIMER_1 */
#define XPAR_AXI_TIMER_1_DEVICE_ID 1
#define XPAR_AXI_TIMER_1_BASEADDR 0x42810000
#define XPAR_AXI_TIMER_1_HIGHADDR 0x4281FFFF
#define XPAR_AXI_TIMER_1_CLOCK_FREQ_HZ 100000000


/* Definitions for peripheral AXI_TIMER_2 */
#define XPAR_AXI_TIMER_2_DEVICE_ID 2
#define XPAR_AXI_TIMER_2_BASEADDR 0x42820000
#define XPAR_AXI_TIMER_2_HIGHADDR 0x4282FFFF
#define XPAR_AXI_TIMER_2_CLOCK_FREQ_HZ 100000000


/******************************************************************/

/* Canonical definitions for peripheral AXI_TIMER_0 */
#define XPAR_TMRCTR_0_DEVICE_ID 0
#define XPAR_TMRCTR_0_BASEADDR 0x42800000
#define XPAR_TMRCTR_0_HIGHADDR 0x4280FFFF
#define XPAR_TMRCTR_0_CLOCK_FREQ_HZ XPAR_AXI_TIMER_0_CLOCK_FREQ_HZ
/* Canonical definitions for peripheral AXI_TIMER_1 */
#define XPAR_TMRCTR_1_DEVICE_ID 0
#define XPAR_TMRCTR_1_BASEADDR 0x42810000
#define XPAR_TMRCTR_1_HIGHADDR 0x4281FFFF
#define XPAR_TMRCTR_1_CLOCK_FREQ_HZ XPAR_AXI_TIMER_1_CLOCK_FREQ_HZ
/* Canonical definitions for peripheral AXI_TIMER_2 */
#define XPAR_TMRCTR_2_DEVICE_ID 0
#define XPAR_TMRCTR_2_BASEADDR 0x42820000
#define XPAR_TMRCTR_2_HIGHADDR 0x4282FFFF
#define XPAR_TMRCTR_2_CLOCK_FREQ_HZ XPAR_AXI_TIMER_2_CLOCK_FREQ_HZ

/******************************************************************/

/* Definitions for driver UARTLITE */
#define XPAR_XUARTLITE_NUM_INSTANCES 1

/* Definitions for peripheral BLUETOOTH_UARTLITE_0 */
#define XPAR_BLUETOOTH_UARTLITE_0_BASEADDR 0x42C00000
#define XPAR_BLUETOOTH_UARTLITE_0_HIGHADDR 0x42C0FFFF
#define XPAR_BLUETOOTH_UARTLITE_0_DEVICE_ID 0
#define XPAR_BLUETOOTH_UARTLITE_0_BAUDRATE 9600
#define XPAR_BLUETOOTH_UARTLITE_0_USE_PARITY 0
#define XPAR_BLUETOOTH_UARTLITE_0_ODD_PARITY 0
#define XPAR_BLUETOOTH_UARTLITE_0_DATA_BITS 8


/******************************************************************/

/* Canonical definitions for peripheral BLUETOOTH_UARTLITE_0 */
#define XPAR_UARTLITE_0_DEVICE_ID XPAR_BLUETOOTH_UARTLITE_0_DEVICE_ID
#define XPAR_UARTLITE_0_BASEADDR 0x42C00000
#define XPAR_UARTLITE_0_HIGHADDR 0x42C0FFFF
#define XPAR_UARTLITE_0_BAUDRATE 9600
#define XPAR_UARTLITE_0_USE_PARITY 0
#define XPAR_UARTLITE_0_ODD_PARITY 0
#define XPAR_UARTLITE_0_DATA_BITS 8


/******************************************************************/

/* Definitions for driver UARTPS */
#define XPAR_XUARTPS_NUM_INSTANCES 1

/* Definitions for peripheral PS7_UART_1 */
#define XPAR_PS7_UART_1_DEVICE_ID 0
#define XPAR_PS7_UART_1_BASEADDR 0xE0001000
#define XPAR_PS7_UART_1_HIGHADDR 0xE0001FFF
#define XPAR_PS7_UART_1_UART_CLK_FREQ_HZ 50000000
#define XPAR_PS7_UART_1_HAS_MODEM 0


/******************************************************************/

/* Canonical definitions for peripheral PS7_UART_1 */
#define XPAR_XUARTPS_0_DEVICE_ID XPAR_PS7_UART_1_DEVICE_ID
#define XPAR_XUARTPS_0_BASEADDR 0xE0001000
#define XPAR_XUARTPS_0_HIGHADDR 0xE0001FFF
#define XPAR_XUARTPS_0_UART_CLK_FREQ_HZ 50000000
#define XPAR_XUARTPS_0_HAS_MODEM 0


/******************************************************************/

/* Definitions for driver USBPS */
#define XPAR_XUSBPS_NUM_INSTANCES 1

/* Definitions for peripheral PS7_USB_0 */
#define XPAR_PS7_USB_0_DEVICE_ID 0
#define XPAR_PS7_USB_0_BASEADDR 0xE0002000
#define XPAR_PS7_USB_0_HIGHADDR 0xE0002FFF


/******************************************************************/

/* Canonical definitions for peripheral PS7_USB_0 */
#define XPAR_XUSBPS_0_DEVICE_ID XPAR_PS7_USB_0_DEVICE_ID
#define XPAR_XUSBPS_0_BASEADDR 0xE0002000
#define XPAR_XUSBPS_0_HIGHADDR 0xE0002FFF


/******************************************************************/

/* Definitions for driver XADCPS */
#define XPAR_XADCPS_NUM_INSTANCES 1

/* Definitions for peripheral PS7_XADC_0 */
#define XPAR_PS7_XADC_0_DEVICE_ID 0
#define XPAR_PS7_XADC_0_BASEADDR 0xF8007100
#define XPAR_PS7_XADC_0_HIGHADDR 0xF8007120


/******************************************************************/

/* Canonical definitions for peripheral PS7_XADC_0 */
#define XPAR_XADCPS_0_DEVICE_ID XPAR_PS7_XADC_0_DEVICE_ID
#define XPAR_XADCPS_0_BASEADDR 0xF8007100
#define XPAR_XADCPS_0_HIGHADDR 0xF8007120


/******************************************************************/

/* Xilinx FAT File System Library (XilFFs) User Settings */
#define FILE_SYSTEM_INTERFACE_SD
