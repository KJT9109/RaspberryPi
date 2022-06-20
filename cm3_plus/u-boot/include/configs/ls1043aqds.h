/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Copyright 2015 Freescale Semiconductor, Inc.
 */

#ifndef __LS1043AQDS_H__
#define __LS1043AQDS_H__

#include "ls1043a_common.h"

#define CONFIG_LAYERSCAPE_NS_ACCESS

/* Physical Memory Map */

#define SPD_EEPROM_ADDRESS		0x51
#define CONFIG_SYS_SPD_BUS_NUM		0

#ifdef CONFIG_DDR_ECC
#define CONFIG_MEM_INIT_VALUE           0xdeadbeef
#endif

#ifdef CONFIG_SYS_DPAA_FMAN
#define RGMII_PHY1_ADDR		0x1
#define RGMII_PHY2_ADDR		0x2
#define SGMII_CARD_PORT1_PHY_ADDR 0x1C
#define SGMII_CARD_PORT2_PHY_ADDR 0x1D
#define SGMII_CARD_PORT3_PHY_ADDR 0x1E
#define SGMII_CARD_PORT4_PHY_ADDR 0x1F
/* PHY address on QSGMII riser card on slot 1 */
#define QSGMII_CARD_PORT1_PHY_ADDR_S1 0x4
#define QSGMII_CARD_PORT2_PHY_ADDR_S1 0x5
#define QSGMII_CARD_PORT3_PHY_ADDR_S1 0x6
#define QSGMII_CARD_PORT4_PHY_ADDR_S1 0x7
/* PHY address on QSGMII riser card on slot 2 */
#define QSGMII_CARD_PORT1_PHY_ADDR_S2 0x8
#define QSGMII_CARD_PORT2_PHY_ADDR_S2 0x9
#define QSGMII_CARD_PORT3_PHY_ADDR_S2 0xA
#define QSGMII_CARD_PORT4_PHY_ADDR_S2 0xB
#endif

/* SATA */

/* EEPROM */
#define CONFIG_SYS_I2C_EEPROM_NXID
#define CONFIG_SYS_EEPROM_BUS_NUM		0

#define CONFIG_SYS_SATA				AHCI_BASE_ADDR

/*
 * IFC Definitions
 */
#if !defined(CONFIG_QSPI_BOOT) && !defined(CONFIG_SD_BOOT_QSPI)
#define CONFIG_SYS_NOR0_CSPR_EXT	(0x0)
#define CONFIG_SYS_NOR0_CSPR	(CSPR_PHYS_ADDR(CONFIG_SYS_FLASH_BASE_PHYS) | \
				CSPR_PORT_SIZE_16 | \
				CSPR_MSEL_NOR | \
				CSPR_V)
#define CONFIG_SYS_NOR1_CSPR_EXT	(0x0)
#define CONFIG_SYS_NOR1_CSPR	(CSPR_PHYS_ADDR(CONFIG_SYS_FLASH_BASE_PHYS \
				+ 0x8000000) | \
				CSPR_PORT_SIZE_16 | \
				CSPR_MSEL_NOR | \
				CSPR_V)
#define CONFIG_SYS_NOR_AMASK		IFC_AMASK(128 * 1024 * 1024)

#define CONFIG_SYS_NOR_CSOR		(CSOR_NOR_ADM_SHIFT(4) | \
					CSOR_NOR_TRHZ_80)
#define CONFIG_SYS_NOR_FTIM0		(FTIM0_NOR_TACSE(0x4) | \
					FTIM0_NOR_TEADC(0x5) | \
					FTIM0_NOR_TEAHC(0x5))
#define CONFIG_SYS_NOR_FTIM1		(FTIM1_NOR_TACO(0x35) | \
					FTIM1_NOR_TRAD_NOR(0x1a) | \
					FTIM1_NOR_TSEQRAD_NOR(0x13))
#define CONFIG_SYS_NOR_FTIM2		(FTIM2_NOR_TCS(0x4) | \
					FTIM2_NOR_TCH(0x4) | \
					FTIM2_NOR_TWPH(0xe) | \
					FTIM2_NOR_TWP(0x1c))
#define CONFIG_SYS_NOR_FTIM3		0

#define CONFIG_SYS_MAX_FLASH_SECT	1024	/* sectors per device */
#define CONFIG_SYS_FLASH_ERASE_TOUT	60000	/* Flash Erase Timeout (ms) */
#define CONFIG_SYS_FLASH_WRITE_TOUT	500	/* Flash Write Timeout (ms) */

#define CONFIG_SYS_FLASH_EMPTY_INFO
#define CONFIG_SYS_FLASH_BANKS_LIST	{CONFIG_SYS_FLASH_BASE_PHYS, \
					CONFIG_SYS_FLASH_BASE_PHYS + 0x8000000}

#define CONFIG_SYS_WRITE_SWAPPED_DATA

/*
 * NAND Flash Definitions
 */

#define CONFIG_SYS_NAND_BASE		0x7e800000
#define CONFIG_SYS_NAND_BASE_PHYS	CONFIG_SYS_NAND_BASE

#define CONFIG_SYS_NAND_CSPR_EXT	(0x0)

#define CONFIG_SYS_NAND_CSPR	(CSPR_PHYS_ADDR(CONFIG_SYS_NAND_BASE_PHYS) \
				| CSPR_PORT_SIZE_8	\
				| CSPR_MSEL_NAND	\
				| CSPR_V)
#define CONFIG_SYS_NAND_AMASK	IFC_AMASK(64*1024)
#define CONFIG_SYS_NAND_CSOR	(CSOR_NAND_ECC_ENC_EN	/* ECC on encode */ \
				| CSOR_NAND_ECC_DEC_EN	/* ECC on decode */ \
				| CSOR_NAND_ECC_MODE_4	/* 4-bit ECC */ \
				| CSOR_NAND_RAL_3	/* RAL = 3 Bytes */ \
				| CSOR_NAND_PGS_2K	/* Page Size = 2K */ \
				| CSOR_NAND_SPRZ_64	/* Spare size = 64 */ \
				| CSOR_NAND_PB(64))	/* 64 Pages Per Block */

#define CONFIG_SYS_NAND_FTIM0		(FTIM0_NAND_TCCST(0x7) | \
					FTIM0_NAND_TWP(0x18)   | \
					FTIM0_NAND_TWCHT(0x7) | \
					FTIM0_NAND_TWH(0xa))
#define CONFIG_SYS_NAND_FTIM1		(FTIM1_NAND_TADLE(0x32) | \
					FTIM1_NAND_TWBE(0x39)  | \
					FTIM1_NAND_TRR(0xe)   | \
					FTIM1_NAND_TRP(0x18))
#define CONFIG_SYS_NAND_FTIM2		(FTIM2_NAND_TRAD(0xf) | \
					FTIM2_NAND_TREH(0xa) | \
					FTIM2_NAND_TWHRE(0x1e))
#define CONFIG_SYS_NAND_FTIM3           0x0

#define CONFIG_SYS_NAND_BASE_LIST	{ CONFIG_SYS_NAND_BASE }
#define CONFIG_SYS_MAX_NAND_DEVICE	1
#define CONFIG_MTD_NAND_VERIFY_WRITE
#endif

#ifdef CONFIG_NAND_BOOT
#define CONFIG_SPL_PAD_TO		0x20000		/* block aligned */
#define CONFIG_SYS_NAND_U_BOOT_SIZE	(640 << 10)
#endif

#if defined(CONFIG_TFABOOT) || \
	defined(CONFIG_QSPI_BOOT) || defined(CONFIG_SD_BOOT_QSPI)
#endif

/*
 * QIXIS Definitions
 */

#ifdef CONFIG_FSL_QIXIS
#define QIXIS_BASE			0x7fb00000
#define QIXIS_BASE_PHYS			QIXIS_BASE
#define CONFIG_SYS_I2C_FPGA_ADDR	0x66
#define QIXIS_LBMAP_SWITCH		6
#define QIXIS_LBMAP_MASK		0x0f
#define QIXIS_LBMAP_SHIFT		0
#define QIXIS_LBMAP_DFLTBANK		0x00
#define QIXIS_LBMAP_ALTBANK		0x04
#define QIXIS_LBMAP_NAND		0x09
#define QIXIS_LBMAP_SD			0x00
#define QIXIS_LBMAP_SD_QSPI		0xff
#define QIXIS_LBMAP_QSPI		0xff
#define QIXIS_RCW_SRC_NAND		0x106
#define QIXIS_RCW_SRC_SD		0x040
#define QIXIS_RCW_SRC_QSPI		0x045
#define QIXIS_RST_CTL_RESET		0x41
#define QIXIS_RCFG_CTL_RECONFIG_IDLE	0x20
#define QIXIS_RCFG_CTL_RECONFIG_START	0x21
#define QIXIS_RCFG_CTL_WATCHDOG_ENBLE	0x08

#define CONFIG_SYS_FPGA_CSPR_EXT	(0x0)
#define CONFIG_SYS_FPGA_CSPR		(CSPR_PHYS_ADDR(QIXIS_BASE_PHYS) | \
					CSPR_PORT_SIZE_8 | \
					CSPR_MSEL_GPCM | \
					CSPR_V)
#define CONFIG_SYS_FPGA_AMASK		IFC_AMASK(64 * 1024)
#define CONFIG_SYS_FPGA_CSOR		(CSOR_NOR_ADM_SHIFT(4) | \
					CSOR_NOR_NOR_MODE_AVD_NOR | \
					CSOR_NOR_TRHZ_80)

/*
 * QIXIS Timing parameters for IFC GPCM
 */
#define CONFIG_SYS_FPGA_FTIM0		(FTIM0_GPCM_TACSE(0xc) | \
					FTIM0_GPCM_TEADC(0x20) | \
					FTIM0_GPCM_TEAHC(0x10))
#define CONFIG_SYS_FPGA_FTIM1		(FTIM1_GPCM_TACO(0x50) | \
					FTIM1_GPCM_TRAD(0x1f))
#define CONFIG_SYS_FPGA_FTIM2		(FTIM2_GPCM_TCS(0x8) | \
					FTIM2_GPCM_TCH(0x8) | \
					FTIM2_GPCM_TWP(0xf0))
#define CONFIG_SYS_FPGA_FTIM3		0x0
#endif

#ifdef CONFIG_TFABOOT
#define CONFIG_SYS_CSPR0_EXT		CONFIG_SYS_NOR0_CSPR_EXT
#define CONFIG_SYS_CSPR0		CONFIG_SYS_NOR0_CSPR
#define CONFIG_SYS_AMASK0		CONFIG_SYS_NOR_AMASK
#define CONFIG_SYS_CSOR0		CONFIG_SYS_NOR_CSOR
#define CONFIG_SYS_CS0_FTIM0		CONFIG_SYS_NOR_FTIM0
#define CONFIG_SYS_CS0_FTIM1		CONFIG_SYS_NOR_FTIM1
#define CONFIG_SYS_CS0_FTIM2		CONFIG_SYS_NOR_FTIM2
#define CONFIG_SYS_CS0_FTIM3		CONFIG_SYS_NOR_FTIM3
#define CONFIG_SYS_CSPR1_EXT		CONFIG_SYS_NOR1_CSPR_EXT
#define CONFIG_SYS_CSPR1		CONFIG_SYS_NOR1_CSPR
#define CONFIG_SYS_AMASK1		CONFIG_SYS_NOR_AMASK
#define CONFIG_SYS_CSOR1		CONFIG_SYS_NOR_CSOR
#define CONFIG_SYS_CS1_FTIM0		CONFIG_SYS_NOR_FTIM0
#define CONFIG_SYS_CS1_FTIM1		CONFIG_SYS_NOR_FTIM1
#define CONFIG_SYS_CS1_FTIM2		CONFIG_SYS_NOR_FTIM2
#define CONFIG_SYS_CS1_FTIM3		CONFIG_SYS_NOR_FTIM3
#define CONFIG_SYS_CSPR2_EXT		CONFIG_SYS_NAND_CSPR_EXT
#define CONFIG_SYS_CSPR2		CONFIG_SYS_NAND_CSPR
#define CONFIG_SYS_AMASK2		CONFIG_SYS_NAND_AMASK
#define CONFIG_SYS_CSOR2		CONFIG_SYS_NAND_CSOR
#define CONFIG_SYS_CS2_FTIM0		CONFIG_SYS_NAND_FTIM0
#define CONFIG_SYS_CS2_FTIM1		CONFIG_SYS_NAND_FTIM1
#define CONFIG_SYS_CS2_FTIM2		CONFIG_SYS_NAND_FTIM2
#define CONFIG_SYS_CS2_FTIM3		CONFIG_SYS_NAND_FTIM3
#define CONFIG_SYS_CSPR3_EXT		CONFIG_SYS_FPGA_CSPR_EXT
#define CONFIG_SYS_CSPR3		CONFIG_SYS_FPGA_CSPR
#define CONFIG_SYS_AMASK3		CONFIG_SYS_FPGA_AMASK
#define CONFIG_SYS_CSOR3		CONFIG_SYS_FPGA_CSOR
#define CONFIG_SYS_CS3_FTIM0		CONFIG_SYS_FPGA_FTIM0
#define CONFIG_SYS_CS3_FTIM1		CONFIG_SYS_FPGA_FTIM1
#define CONFIG_SYS_CS3_FTIM2		CONFIG_SYS_FPGA_FTIM2
#define CONFIG_SYS_CS3_FTIM3		CONFIG_SYS_FPGA_FTIM3
#else
#ifdef CONFIG_NAND_BOOT
#define CONFIG_SYS_CSPR0_EXT		CONFIG_SYS_NAND_CSPR_EXT
#define CONFIG_SYS_CSPR0		CONFIG_SYS_NAND_CSPR
#define CONFIG_SYS_AMASK0		CONFIG_SYS_NAND_AMASK
#define CONFIG_SYS_CSOR0		CONFIG_SYS_NAND_CSOR
#define CONFIG_SYS_CS0_FTIM0		CONFIG_SYS_NAND_FTIM0
#define CONFIG_SYS_CS0_FTIM1		CONFIG_SYS_NAND_FTIM1
#define CONFIG_SYS_CS0_FTIM2		CONFIG_SYS_NAND_FTIM2
#define CONFIG_SYS_CS0_FTIM3		CONFIG_SYS_NAND_FTIM3
#define CONFIG_SYS_CSPR1_EXT		CONFIG_SYS_NOR0_CSPR_EXT
#define CONFIG_SYS_CSPR1		CONFIG_SYS_NOR0_CSPR
#define CONFIG_SYS_AMASK1		CONFIG_SYS_NOR_AMASK
#define CONFIG_SYS_CSOR1		CONFIG_SYS_NOR_CSOR
#define CONFIG_SYS_CS1_FTIM0		CONFIG_SYS_NOR_FTIM0
#define CONFIG_SYS_CS1_FTIM1		CONFIG_SYS_NOR_FTIM1
#define CONFIG_SYS_CS1_FTIM2		CONFIG_SYS_NOR_FTIM2
#define CONFIG_SYS_CS1_FTIM3		CONFIG_SYS_NOR_FTIM3
#define CONFIG_SYS_CSPR2_EXT		CONFIG_SYS_NOR1_CSPR_EXT
#define CONFIG_SYS_CSPR2		CONFIG_SYS_NOR1_CSPR
#define CONFIG_SYS_AMASK2		CONFIG_SYS_NOR_AMASK
#define CONFIG_SYS_CSOR2		CONFIG_SYS_NOR_CSOR
#define CONFIG_SYS_CS2_FTIM0		CONFIG_SYS_NOR_FTIM0
#define CONFIG_SYS_CS2_FTIM1		CONFIG_SYS_NOR_FTIM1
#define CONFIG_SYS_CS2_FTIM2		CONFIG_SYS_NOR_FTIM2
#define CONFIG_SYS_CS2_FTIM3		CONFIG_SYS_NOR_FTIM3
#define CONFIG_SYS_CSPR3_EXT		CONFIG_SYS_FPGA_CSPR_EXT
#define CONFIG_SYS_CSPR3		CONFIG_SYS_FPGA_CSPR
#define CONFIG_SYS_AMASK3		CONFIG_SYS_FPGA_AMASK
#define CONFIG_SYS_CSOR3		CONFIG_SYS_FPGA_CSOR
#define CONFIG_SYS_CS3_FTIM0		CONFIG_SYS_FPGA_FTIM0
#define CONFIG_SYS_CS3_FTIM1		CONFIG_SYS_FPGA_FTIM1
#define CONFIG_SYS_CS3_FTIM2		CONFIG_SYS_FPGA_FTIM2
#define CONFIG_SYS_CS3_FTIM3		CONFIG_SYS_FPGA_FTIM3
#else
#define CONFIG_SYS_CSPR0_EXT		CONFIG_SYS_NOR0_CSPR_EXT
#define CONFIG_SYS_CSPR0		CONFIG_SYS_NOR0_CSPR
#define CONFIG_SYS_AMASK0		CONFIG_SYS_NOR_AMASK
#define CONFIG_SYS_CSOR0		CONFIG_SYS_NOR_CSOR
#define CONFIG_SYS_CS0_FTIM0		CONFIG_SYS_NOR_FTIM0
#define CONFIG_SYS_CS0_FTIM1		CONFIG_SYS_NOR_FTIM1
#define CONFIG_SYS_CS0_FTIM2		CONFIG_SYS_NOR_FTIM2
#define CONFIG_SYS_CS0_FTIM3		CONFIG_SYS_NOR_FTIM3
#define CONFIG_SYS_CSPR1_EXT		CONFIG_SYS_NOR1_CSPR_EXT
#define CONFIG_SYS_CSPR1		CONFIG_SYS_NOR1_CSPR
#define CONFIG_SYS_AMASK1		CONFIG_SYS_NOR_AMASK
#define CONFIG_SYS_CSOR1		CONFIG_SYS_NOR_CSOR
#define CONFIG_SYS_CS1_FTIM0		CONFIG_SYS_NOR_FTIM0
#define CONFIG_SYS_CS1_FTIM1		CONFIG_SYS_NOR_FTIM1
#define CONFIG_SYS_CS1_FTIM2		CONFIG_SYS_NOR_FTIM2
#define CONFIG_SYS_CS1_FTIM3		CONFIG_SYS_NOR_FTIM3
#define CONFIG_SYS_CSPR2_EXT		CONFIG_SYS_NAND_CSPR_EXT
#define CONFIG_SYS_CSPR2		CONFIG_SYS_NAND_CSPR
#define CONFIG_SYS_AMASK2		CONFIG_SYS_NAND_AMASK
#define CONFIG_SYS_CSOR2		CONFIG_SYS_NAND_CSOR
#define CONFIG_SYS_CS2_FTIM0		CONFIG_SYS_NAND_FTIM0
#define CONFIG_SYS_CS2_FTIM1		CONFIG_SYS_NAND_FTIM1
#define CONFIG_SYS_CS2_FTIM2		CONFIG_SYS_NAND_FTIM2
#define CONFIG_SYS_CS2_FTIM3		CONFIG_SYS_NAND_FTIM3
#define CONFIG_SYS_CSPR3_EXT		CONFIG_SYS_FPGA_CSPR_EXT
#define CONFIG_SYS_CSPR3		CONFIG_SYS_FPGA_CSPR
#define CONFIG_SYS_AMASK3		CONFIG_SYS_FPGA_AMASK
#define CONFIG_SYS_CSOR3		CONFIG_SYS_FPGA_CSOR
#define CONFIG_SYS_CS3_FTIM0		CONFIG_SYS_FPGA_FTIM0
#define CONFIG_SYS_CS3_FTIM1		CONFIG_SYS_FPGA_FTIM1
#define CONFIG_SYS_CS3_FTIM2		CONFIG_SYS_FPGA_FTIM2
#define CONFIG_SYS_CS3_FTIM3		CONFIG_SYS_FPGA_FTIM3
#endif
#endif

/*
 * I2C bus multiplexer
 */
#define I2C_MUX_PCA_ADDR_PRI		0x77
#define I2C_MUX_PCA_ADDR_SEC		0x76 /* Secondary multiplexer */
#define I2C_RETIMER_ADDR		0x18
#define I2C_MUX_CH_DEFAULT		0x8
#define I2C_MUX_CH_CH7301		0xC
#define I2C_MUX_CH5			0xD
#define I2C_MUX_CH7			0xF

#define I2C_MUX_CH_VOL_MONITOR 0xa

/* Voltage monitor on channel 2*/
#define I2C_VOL_MONITOR_ADDR           0x40
#define I2C_VOL_MONITOR_BUS_V_OFFSET   0x2
#define I2C_VOL_MONITOR_BUS_V_OVF      0x1
#define I2C_VOL_MONITOR_BUS_V_SHIFT    3

/* The lowest and highest voltage allowed for LS1043AQDS */
#define VDD_MV_MIN			819
#define VDD_MV_MAX			1212

/*
 * Miscellaneous configurable options
 */

#define CONFIG_SYS_INIT_SP_OFFSET \
	(CONFIG_SYS_INIT_RAM_SIZE - GENERATED_GBL_DATA_SIZE)

/*
 * Environment
 */

#include <asm/fsl_secure_boot.h>

#endif /* __LS1043AQDS_H__ */
