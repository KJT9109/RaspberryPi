/* SPDX-License-Identifier:    GPL-2.0
 * Copyright (C) 2018 Marvell International Ltd.
 *
 * https://spdx.org/licenses
 */

#ifndef __OCTEONTX2_COMMON_H__
#define __OCTEONTX2_COMMON_H__

/** Maximum size of image supported for bootm (and bootable FIT images) */
#define CONFIG_SYS_BOOTM_LEN		(256 << 20)

/** Memory base address */
#define CONFIG_SYS_SDRAM_BASE		CONFIG_SYS_TEXT_BASE

/** Stack starting address */
#define CONFIG_SYS_INIT_SP_ADDR		(CONFIG_SYS_SDRAM_BASE + 0xffff0)

/** Extra environment settings */
#define CONFIG_EXTRA_ENV_SETTINGS	\
					"loadaddr=20080000\0"	\
					"ethrotate=yes\0"	\
					"autoload=0\0"

/* Monitor Command Prompt */
#define CONFIG_SYS_CBSIZE		1024	/** Console I/O Buffer Size */
#define CONFIG_SYS_BARGSIZE		CONFIG_SYS_CBSIZE

#define CONFIG_SYS_MAXARGS		64	/** max command args */

#define CONFIG_SYS_MMC_MAX_BLK_COUNT	8192

#if defined(CONFIG_MMC_OCTEONTX)
#define MMC_SUPPORTS_TUNING
/** EMMC specific defines */
#endif

#endif /* __OCTEONTX2_COMMON_H__ */
