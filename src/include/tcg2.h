/*
 * The definitions for EFI TCG2 Protocol
 *
 * Copyright (c) 2016, Wind River Systems, Inc.
 * All rights reserved.
 *
 * See "LICENSE" for license terms.
 *
 * Author:
 *      Jia Zhang <zhang.jia@linux.alibaba.com>
 */

#ifndef TCG2_H
#define TCG2_H

#include <efi.h>
#include <efilib.h>

/* The definitions for TCG Spec */

typedef UINT16			TPM_ALG_ID;
typedef TPM_ALG_ID		TPMI_ALG_HASH;

#define TPM_ALG_SHA1 		(TPM_ALG_ID)(0x0004)
#define TPM_ALG_AES 		(TPM_ALG_ID)(0x0006)
#define TPM_ALG_KEYEDHASH	(TPM_ALG_ID)(0x0008)
#define TPM_ALG_SHA256		(TPM_ALG_ID)(0x000B)
#define TPM_ALG_SHA384		(TPM_ALG_ID)(0x000C)
#define TPM_ALG_SHA512		(TPM_ALG_ID)(0x000D)
#define TPM_ALG_NULL		(TPM_ALG_ID)(0x0010)
#define TPM_ALG_SM3_256		(TPM_ALG_ID)(0x0012)
#define TPM_ALG_SM4		(TPM_ALG_ID)(0x0013)
#define TPM_ALG_RSASSA		(TPM_ALG_ID)(0x0014)
#define TPM_ALG_RSAES		(TPM_ALG_ID)(0x0015)
#define TPM_ALG_RSAPSS		(TPM_ALG_ID)(0x0016)
#define TPM_ALG_OAEP		(TPM_ALG_ID)(0x0017)
#define TPM_ALG_ECDSA		(TPM_ALG_ID)(0x0018)
#define TPM_ALG_ECDH		(TPM_ALG_ID)(0x0019)
#define TPM_ALG_ECDAA		(TPM_ALG_ID)(0x001A)
#define TPM_ALG_SM2		(TPM_ALG_ID)(0x001B)
#define TPM_ALG_ECSCHNORR	(TPM_ALG_ID)(0x001C)
#define TPM_ALG_ECMQV		(TPM_ALG_ID)(0x001D)
#define TPM_ALG_KDF1_SP800_56a	(TPM_ALG_ID)(0x0020)
#define TPM_ALG_KDF2		(TPM_ALG_ID)(0x0021)
#define TPM_ALG_KDF1_SP800_108	(TPM_ALG_ID)(0x0022)
#define TPM_ALG_ECC 		(TPM_ALG_ID)(0x0023)
#define TPM_ALG_SYMCIPHER	(TPM_ALG_ID)(0x0025)
#define TPM_ALG_CTR		(TPM_ALG_ID)(0x0040)
#define TPM_ALG_OFB		(TPM_ALG_ID)(0x0041)
#define TPM_ALG_CBC		(TPM_ALG_ID)(0x0042)
#define TPM_ALG_CFB		(TPM_ALG_ID)(0x0043)
#define TPM_ALG_ECB		(TPM_ALG_ID)(0x0044)

#define SHA1_DIGEST_SIZE 	20
#define SHA256_DIGEST_SIZE	32
#define SHA384_DIGEST_SIZE	48
#define SHA512_DIGEST_SIZE	64
#define SM3_256_DIGEST_SIZE	32

/* The definitions for EFI TCG2 Protocol */

#define EFI_TCG2_PROTOCOL_GUID	\
	{ 0x607f766c, 0x7455, 0x42be,	\
	{ 0x93, 0x0b, 0xe4, 0xd7, 0x6d, 0xb2, 0x72, 0x0f } }

typedef struct {
	UINT8 Major;
	UINT8 Minor;
} EFI_TCG2_VERSION;

typedef UINT32				EFI_TCG2_EVENT_ALGORITHM_BITMAP;

#define EFI_TCG2_BOOT_HASH_ALG_SHA1 	0x00000001
#define EFI_TCG2_BOOT_HASH_ALG_SHA256	0x00000002
#define EFI_TCG2_BOOT_HASH_ALG_SHA384	0x00000004
#define EFI_TCG2_BOOT_HASH_ALG_SHA512	0x00000008
#define EFI_TCG2_BOOT_HASH_ALG_SM3_256	0x00000010
#define EFI_TCG2_BOOT_HASH_ALG_MASK	\
	(EFI_TCG2_BOOT_HASH_ALG_SHA1 |		\
	 EFI_TCG2_BOOT_HASH_ALG_SHA256 |	\
	 EFI_TCG2_BOOT_HASH_ALG_SHA384 |	\
	 EFI_TCG2_BOOT_HASH_ALG_SHA512 |	\
	 EFI_TCG2_BOOT_HASH_ALG_SM3_256)

typedef UINT32				EFI_TCG2_EVENT_LOG_BITMAP;
typedef UINT32				EFI_TCG2_EVENT_LOG_FORMAT;

#define EFI_TCG2_EVENT_LOG_FORMAT_TCG_1_2	0x00000001
#define EFI_TCG2_EVENT_LOG_FORMAT_TCG_2		0x00000002
#define EFI_TCG2_EVENT_LOG_FORMAT_MASK		\
	(EFI_TCG2_EVENT_LOG_FORMAT_TCG_1_2 |	\
	 EFI_TCG2_EVENT_LOG_FORMAT_TCG_2)

/*
 * According to TCG EFI Protocol Specification for TPM 2.0 family,
 * the EFI_TCG2_BOOT_SERVICE_CAPABILITY structure must not be packed.
 */
typedef struct {
	UINT8 Size;
	EFI_TCG2_VERSION StructureVersion;
	EFI_TCG2_VERSION ProtocolVersion;
	EFI_TCG2_EVENT_ALGORITHM_BITMAP HashAlgorithmBitmap;
	EFI_TCG2_EVENT_LOG_BITMAP SupportedEventLogs;
	BOOLEAN TPMPresentFlag;
	UINT16 MaxCommandSize;
	UINT16 MaxResponseSize;
	UINT32 ManufacturerID;
	UINT32 NumberOfPcrBanks;
	EFI_TCG2_EVENT_ALGORITHM_BITMAP ActivePcrBanks;
} EFI_TCG2_BOOT_SERVICE_CAPABILITY;

/* The definitions for Trusted Execution Environment (TrEE) */

typedef struct {
	UINT8 Major;
	UINT8 Minor;
} TREE_VERSION;

#define TREE_BOOT_HASH_ALG_SHA1 		0x00000001
#define TREE_BOOT_HASH_ALG_SHA256		0x00000002
#define TREE_BOOT_HASH_ALG_SHA384		0x00000004
#define TREE_BOOT_HASH_ALG_SHA512		0x00000008
#define TREE_BOOT_HASH_ALG_MASK			\
	(TREE_BOOT_HASH_ALG_SHA1 |	\
	 TREE_BOOT_HASH_ALG_SHA256 |	\
	 TREE_BOOT_HASH_ALG_SHA384 |	\
	 TREE_BOOT_HASH_ALG_SHA512)

typedef UINT32					TREE_EVENT_LOG_BITMAP;
typedef UINT32					TREE_EVENT_LOG_FORMAT;

#define TREE_EVENT_LOG_FORMAT_TCG_1_2		0x00000001
#define TREE_EVENT_LOG_FORMAT_MASK		TREE_EVENT_LOG_FORMAT_TCG_1_2

typedef struct {
	UINT8 Size;
	TREE_VERSION StructureVersion;
	TREE_VERSION ProtocolVersion;
	UINT32 HashAlgorithmBitmap;
	TREE_EVENT_LOG_BITMAP SupportedEventLogs;
	BOOLEAN TrEEPresentFlag;
	UINT16 MaxCommandSize;
	UINT16 MaxResponseSize;
	UINT32 ManufacturerID;
} TREE_BOOT_SERVICE_CAPABILITY;

#pragma pack(1)

typedef UINT32					TCG_PCRINDEX;
typedef UINT32					TCG_EVENTTYPE;

/* Standard event types */
#define EV_POST_CODE				((TCG_EVENTTYPE)0x00000001)
#define EV_NO_ACTION				((TCG_EVENTTYPE)0x00000003)
#define EV_SEPARATOR				((TCG_EVENTTYPE)0x00000004)
#define EV_S_CRTM_CONTENTS			((TCG_EVENTTYPE)0x00000007)
#define EV_S_CRTM_VERSION			((TCG_EVENTTYPE)0x00000008)
#define EV_CPU_MICROCODE			((TCG_EVENTTYPE)0x00000009)
#define EV_TABLE_OF_DEVICES			((TCG_EVENTTYPE)0x0000000B)

/* EFI specific event types */
#define EV_EFI_EVENT_BASE			((TCG_EVENTTYPE)0x80000000)
#define EV_EFI_VARIABLE_DRIVER_CONFIG		(EV_EFI_EVENT_BASE + 1)
#define EV_EFI_VARIABLE_BOOT			(EV_EFI_EVENT_BASE + 2)
#define EV_EFI_BOOT_SERVICES_APPLICATION	(EV_EFI_EVENT_BASE + 3)
#define EV_EFI_BOOT_SERVICES_DRIVER		(EV_EFI_EVENT_BASE + 4)
#define EV_EFI_RUNTIME_SERVICES_DRIVER		(EV_EFI_EVENT_BASE + 5)
#define EV_EFI_GPT_EVENT			(EV_EFI_EVENT_BASE + 6)
#define EV_EFI_ACTION                       	(EV_EFI_EVENT_BASE + 7)
#define EV_EFI_PLATFORM_FIRMWARE_BLOB		(EV_EFI_EVENT_BASE + 8)
#define EV_EFI_HANDOFF_TABLES			(EV_EFI_EVENT_BASE + 9)
#define EV_EFI_VARIABLE_AUTHORITY		(EV_EFI_EVENT_BASE + 0xE0)

typedef struct {
	UINT32 HeaderSize;
	UINT16 HeaderVersion;
	TCG_PCRINDEX PCRIndex;
	TCG_EVENTTYPE EventType;
} EFI_TCG2_EVENT_HEADER;

typedef struct {
	UINT32 Size;
	EFI_TCG2_EVENT_HEADER Header;
	UINT8 Event[];
} EFI_TCG2_EVENT;

struct tdEFI_TCG2_PROTOCOL;

typedef EFI_STATUS
(EFIAPI *EFI_TCG2_GET_CAPABILITY) (
	IN struct tdEFI_TCG2_PROTOCOL *This,
	IN OUT EFI_TCG2_BOOT_SERVICE_CAPABILITY *ProtocolCapability
);

typedef EFI_STATUS
(EFIAPI *EFI_TCG2_GET_EVENT_LOG) (
	IN struct tdEFI_TCG2_PROTOCOL *This,
	IN EFI_TCG2_EVENT_LOG_FORMAT EventLogFormat,
	OUT EFI_PHYSICAL_ADDRESS *EventLogLocation,
	OUT EFI_PHYSICAL_ADDRESS *EventLogLastEntry,
	OUT BOOLEAN *EventLogTruncated
);

typedef EFI_STATUS
(EFIAPI *EFI_TCG2_HASH_LOG_EXTEND_EVENT) (
	IN struct tdEFI_TCG2_PROTOCOL *This,
	IN UINT64 Flags,
	IN EFI_PHYSICAL_ADDRESS DataToHash,
	IN UINT64 DataToHashLen,
	IN EFI_TCG2_EVENT *EfiTcgEvent
);

typedef EFI_STATUS
(EFIAPI *EFI_TCG2_SUBMIT_COMMAND) (
	IN struct tdEFI_TCG2_PROTOCOL *This,
	IN UINT32 InputParameterBlockSize,
	IN UINT8 *InputParameterBlock,
	IN UINT32 OutputParameterBlockSize,
	IN UINT8 *OutputParameterBlock
);

typedef EFI_STATUS
(EFIAPI *EFI_TCG2_GET_ACTIVE_PCR_BANKS) (
	IN struct tdEFI_TCG2_PROTOCOL *This,
	OUT UINT32 *ActivePcrBanks
);

typedef EFI_STATUS
(EFIAPI *EFI_TCG2_SET_ACTIVE_PCR_BANKS) (
	IN struct tdEFI_TCG2_PROTOCOL *This,
	IN UINT32 ActivePcrBanks
);

typedef EFI_STATUS
(EFIAPI * EFI_TCG2_GET_RESULT_OF_SET_ACTIVE_PCR_BANKS) (
	IN struct tdEFI_TCG2_PROTOCOL *This,
	OUT UINT32 *OperationPresent,
	OUT UINT32 *Response
);

typedef struct tdEFI_TCG2_PROTOCOL {
	EFI_TCG2_GET_CAPABILITY GetCapability;
	EFI_TCG2_GET_EVENT_LOG GetEventLog;
	EFI_TCG2_HASH_LOG_EXTEND_EVENT HashLogExtendEvent;
	EFI_TCG2_SUBMIT_COMMAND SubmitCommand;
	EFI_TCG2_GET_ACTIVE_PCR_BANKS GetActivePcrBanks;
	EFI_TCG2_SET_ACTIVE_PCR_BANKS SetActivePcrBanks;
	EFI_TCG2_GET_RESULT_OF_SET_ACTIVE_PCR_BANKS GetResultOfSetActivePcrBanks;
} EFI_TCG2_PROTOCOL;

extern EFI_STATUS
Tcg2LocateProtocol(EFI_TCG2_PROTOCOL **Tcg2);

extern EFI_STATUS
Tcg2GetCapability(EFI_TCG2_BOOT_SERVICE_CAPABILITY *Capability,
		  UINT8 *CapabilitySize);

#endif	/* TCG2_H */