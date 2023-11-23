## @file
#  FDF include file that defines the main macros and sets the dependent PCDs.
#
#  Copyright (C) 2014, Red Hat, Inc.
#  Copyright (c) 2006 - 2019, Intel Corporation. All rights reserved.<BR>
#
#  SPDX-License-Identifier: BSD-2-Clause-Patent
#
##

#
# Default flash size is 2MB.
#
# Defining FD_SIZE_2MB on the build command line can override this.
#

DEFINE BLOCK_SIZE        = 0x1000
DEFINE VARS_SIZE         = 0x3e000

DEFINE FW_BASE_ADDRESS   = 0xFFD00000
DEFINE FW_SIZE           = 0x00300000
DEFINE FW_BLOCKS         = 0x300


DEFINE FSP_S_OFFSET      = 0x00080000
DEFINE FSP_S_SIZE        = 0x00045000
DEFINE FSP_M_OFFSET      = 0x000C5000
DEFINE FSP_M_SIZE        = 0x00038000
DEFINE FSP_T_OFFSET      = 0x000FD000
DEFINE FSP_T_SIZE        = 0x00003000

DEFINE FVMAIN_OFFSET     = 0x00100000
DEFINE FVMAIN_SIZE       = 0x001D3000

DEFINE SECFV_OFFSET      = 0x002D3000
DEFINE SECFV_SIZE        = 0x0002D000


SET gSimicsOpenBoardPkgTokenSpaceGuid.PcdSimicsFdBaseAddress     = $(FW_BASE_ADDRESS)
SET gSimicsOpenBoardPkgTokenSpaceGuid.PcdSimicsFirmwareFdSize    = $(FW_SIZE)
SET gSimicsOpenBoardPkgTokenSpaceGuid.PcdSimicsFirmwareBlockSize = $(BLOCK_SIZE)

SET gSimicsOpenBoardPkgTokenSpaceGuid.PcdSimicsFlashNvStorageVariableBase = $(FW_BASE_ADDRESS)
SET gEfiMdeModulePkgTokenSpaceGuid.PcdFlashNvStorageVariableSize = 0xE000

SET gSimicsOpenBoardPkgTokenSpaceGuid.PcdSimicsFlashNvStorageEventLogBase = gSimicsOpenBoardPkgTokenSpaceGuid.PcdSimicsFlashNvStorageVariableBase + gEfiMdeModulePkgTokenSpaceGuid.PcdFlashNvStorageVariableSize
SET gSimicsOpenBoardPkgTokenSpaceGuid.PcdSimicsFlashNvStorageEventLogSize = $(BLOCK_SIZE)

SET gSimicsOpenBoardPkgTokenSpaceGuid.PcdSimicsFlashNvStorageFtwWorkingBase = gSimicsOpenBoardPkgTokenSpaceGuid.PcdSimicsFlashNvStorageEventLogBase + gSimicsOpenBoardPkgTokenSpaceGuid.PcdSimicsFlashNvStorageEventLogSize
SET gEfiMdeModulePkgTokenSpaceGuid.PcdFlashNvStorageFtwWorkingSize = $(BLOCK_SIZE)

SET gSimicsOpenBoardPkgTokenSpaceGuid.PcdSimicsFlashNvStorageFtwSpareBase = gSimicsOpenBoardPkgTokenSpaceGuid.PcdSimicsFlashNvStorageFtwWorkingBase + gEfiMdeModulePkgTokenSpaceGuid.PcdFlashNvStorageFtwWorkingSize
SET gEfiMdeModulePkgTokenSpaceGuid.PcdFlashNvStorageFtwSpareSize = 0x10000

SET gIntelSiliconPkgTokenSpaceGuid.PcdBiosAreaBaseAddress = $(FW_BASE_ADDRESS)
SET gIntelSiliconPkgTokenSpaceGuid.PcdBiosSize = $(FW_SIZE)

SET gMinPlatformPkgTokenSpaceGuid.PcdFlashAreaBaseAddress = gIntelSiliconPkgTokenSpaceGuid.PcdBiosAreaBaseAddress
SET gMinPlatformPkgTokenSpaceGuid.PcdFlashAreaSize = gIntelSiliconPkgTokenSpaceGuid.PcdBiosSize

DEFINE MEMFD_BASE_ADDRESS = 0x800000
