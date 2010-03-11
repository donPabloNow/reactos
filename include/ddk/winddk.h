/*
 * winddk.h
 *
 * Windows Device Driver Kit
 *
 * This file is part of the w32api package.
 *
 * Contributors:
 *   Created by Casper S. Hornstrup <chorns@users.sourceforge.net>
 *
 * THIS SOFTWARE IS NOT COPYRIGHTED
 *
 * This source code is offered for use in the public domain. You may
 * use, modify or distribute it freely.
 *
 * This code is distributed in the hope that it will be useful but
 * WITHOUT ANY WARRANTY. ALL WARRANTIES, EXPRESS OR IMPLIED ARE HEREBY
 * DISCLAIMED. This includes but is not limited to warranties of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 */

#ifndef __WINDDK_H
#define __WINDDK_H

/* Helper macro to enable gcc's extension.  */
#ifndef __GNU_EXTENSION
#ifdef __GNUC__
#define __GNU_EXTENSION __extension__
#else
#define __GNU_EXTENSION
#endif
#endif

#ifdef __cplusplus
extern "C" {
#endif

#include <excpt.h>
#include <ntdef.h>
#include <ntstatus.h>

#include "intrin.h"

/* Pseudo modifiers for parameters */
#ifndef IN
#define IN
#endif
#ifndef OUT
#define OUT
#endif
#ifndef OPTIONAL
#define OPTIONAL
#endif
#ifndef UNALLIGNED
#define UNALLIGNED
#endif

#define CONST const

#define RESTRICTED_POINTER

#define DECLSPEC_ADDRSAFE

#ifdef NONAMELESSUNION
# define _DDK_DUMMYUNION_MEMBER(name) DUMMYUNIONNAME.name
# define _DDK_DUMMYUNION_N_MEMBER(n, name) DUMMYUNIONNAME##n.name
#else
# define _DDK_DUMMYUNION_MEMBER(name) name
# define _DDK_DUMMYUNION_N_MEMBER(n, name) name
#endif

/*
** Forward declarations
*/

struct _KPCR;
struct _KPRCB;
struct _KTSS;
struct _DRIVE_LAYOUT_INFORMATION_EX;
struct _LOADER_PARAMETER_BLOCK;
struct _BUS_HANDLER;

#if 1
/* FIXME: Unknown definitions */
struct _SET_PARTITION_INFORMATION_EX;
#define WaitAll 0
#define WaitAny 1
typedef HANDLE TRACEHANDLE;
typedef PVOID PWMILIB_CONTEXT;
#endif

/*
** WmiLib specific structure
*/
typedef enum
{
    IrpProcessed,    // Irp was processed and possibly completed
    IrpNotCompleted, // Irp was process and NOT completed
    IrpNotWmi,       // Irp is not a WMI irp
    IrpForward       // Irp is wmi irp, but targeted at another device object
} SYSCTL_IRP_DISPOSITION, *PSYSCTL_IRP_DISPOSITION;

#define DPFLTR_ERROR_LEVEL                  0
#define DPFLTR_WARNING_LEVEL                1
#define DPFLTR_TRACE_LEVEL                  2
#define DPFLTR_INFO_LEVEL                   3
#define DPFLTR_MASK                         0x80000000

typedef enum _DPFLTR_TYPE
{
    DPFLTR_SYSTEM_ID = 0,
    DPFLTR_SMSS_ID = 1,
    DPFLTR_SETUP_ID = 2,
    DPFLTR_NTFS_ID = 3,
    DPFLTR_FSTUB_ID = 4,
    DPFLTR_CRASHDUMP_ID = 5,
    DPFLTR_CDAUDIO_ID = 6,
    DPFLTR_CDROM_ID = 7,
    DPFLTR_CLASSPNP_ID = 8,
    DPFLTR_DISK_ID = 9,
    DPFLTR_REDBOOK_ID = 10,
    DPFLTR_STORPROP_ID = 11,
    DPFLTR_SCSIPORT_ID = 12,
    DPFLTR_SCSIMINIPORT_ID = 13,
    DPFLTR_CONFIG_ID = 14,
    DPFLTR_I8042PRT_ID = 15,
    DPFLTR_SERMOUSE_ID = 16,
    DPFLTR_LSERMOUS_ID = 17,
    DPFLTR_KBDHID_ID = 18,
    DPFLTR_MOUHID_ID = 19,
    DPFLTR_KBDCLASS_ID = 20,
    DPFLTR_MOUCLASS_ID = 21,
    DPFLTR_TWOTRACK_ID = 22,
    DPFLTR_WMILIB_ID = 23,
    DPFLTR_ACPI_ID = 24,
    DPFLTR_AMLI_ID = 25,
    DPFLTR_HALIA64_ID = 26,
    DPFLTR_VIDEO_ID = 27,
    DPFLTR_SVCHOST_ID = 28,
    DPFLTR_VIDEOPRT_ID = 29,
    DPFLTR_TCPIP_ID = 30,
    DPFLTR_DMSYNTH_ID = 31,
    DPFLTR_NTOSPNP_ID = 32,
    DPFLTR_FASTFAT_ID = 33,
    DPFLTR_SAMSS_ID = 34,
    DPFLTR_PNPMGR_ID = 35,
    DPFLTR_NETAPI_ID = 36,
    DPFLTR_SCSERVER_ID = 37,
    DPFLTR_SCCLIENT_ID = 38,
    DPFLTR_SERIAL_ID = 39,
    DPFLTR_SERENUM_ID = 40,
    DPFLTR_UHCD_ID = 41,
    DPFLTR_BOOTOK_ID = 42,
    DPFLTR_BOOTVRFY_ID = 43,
    DPFLTR_RPCPROXY_ID = 44,
    DPFLTR_AUTOCHK_ID = 45,
    DPFLTR_DCOMSS_ID = 46,
    DPFLTR_UNIMODEM_ID = 47,
    DPFLTR_SIS_ID = 48,
    DPFLTR_FLTMGR_ID = 49,
    DPFLTR_WMICORE_ID = 50,
    DPFLTR_BURNENG_ID = 51,
    DPFLTR_IMAPI_ID = 52,
    DPFLTR_SXS_ID = 53,
    DPFLTR_FUSION_ID = 54,
    DPFLTR_IDLETASK_ID = 55,
    DPFLTR_SOFTPCI_ID = 56,
    DPFLTR_TAPE_ID = 57,
    DPFLTR_MCHGR_ID = 58,
    DPFLTR_IDEP_ID = 59,
    DPFLTR_PCIIDE_ID = 60,
    DPFLTR_FLOPPY_ID = 61,
    DPFLTR_FDC_ID = 62,
    DPFLTR_TERMSRV_ID = 63,
    DPFLTR_W32TIME_ID = 64,
    DPFLTR_PREFETCHER_ID = 65,
    DPFLTR_RSFILTER_ID = 66,
    DPFLTR_FCPORT_ID = 67,
    DPFLTR_PCI_ID = 68,
    DPFLTR_DMIO_ID = 69,
    DPFLTR_DMCONFIG_ID = 70,
    DPFLTR_DMADMIN_ID = 71,
    DPFLTR_WSOCKTRANSPORT_ID = 72,
    DPFLTR_VSS_ID = 73,
    DPFLTR_PNPMEM_ID = 74,
    DPFLTR_PROCESSOR_ID = 75,
    DPFLTR_DMSERVER_ID = 76,
    DPFLTR_SR_ID = 77,
    DPFLTR_INFINIBAND_ID = 78,
    DPFLTR_IHVDRIVER_ID = 79,
    DPFLTR_IHVVIDEO_ID = 80,
    DPFLTR_IHVAUDIO_ID = 81,
    DPFLTR_IHVNETWORK_ID = 82,
    DPFLTR_IHVSTREAMING_ID = 83,
    DPFLTR_IHVBUS_ID = 84,
    DPFLTR_HPS_ID = 85,
    DPFLTR_RTLTHREADPOOL_ID = 86,
    DPFLTR_LDR_ID = 87,
    DPFLTR_TCPIP6_ID = 88,
    DPFLTR_ISAPNP_ID = 89,
    DPFLTR_SHPC_ID = 90,
    DPFLTR_STORPORT_ID = 91,
    DPFLTR_STORMINIPORT_ID = 92,
    DPFLTR_PRINTSPOOLER_ID = 93,
    DPFLTR_VDS_ID = 94,
    DPFLTR_VDSBAS_ID = 95,
    DPFLTR_VDSDYNDR_ID = 96,
    DPFLTR_VDSUTIL_ID = 97,
    DPFLTR_DFRGIFC_ID = 98,
    DPFLTR_DEFAULT_ID = 99,
    DPFLTR_MM_ID = 100,
    DPFLTR_DFSC_ID = 101,
    DPFLTR_WOW64_ID = 102,
    DPFLTR_ENDOFTABLE_ID
} DPFLTR_TYPE;

/* also in winnt.h */

#define FILE_COPY_STRUCTURED_STORAGE      0x00000041
#define FILE_STRUCTURED_STORAGE           0x00000441

/* end winnt.h */

/* Exported object types */
extern POBJECT_TYPE NTSYSAPI ExDesktopObjectType;
extern POBJECT_TYPE NTSYSAPI ExWindowStationObjectType;
extern ULONG NTSYSAPI IoDeviceHandlerObjectSize;
extern POBJECT_TYPE NTSYSAPI IoDeviceHandlerObjectType;
extern POBJECT_TYPE NTSYSAPI IoDeviceObjectType;
extern POBJECT_TYPE NTSYSAPI IoDriverObjectType;
extern POBJECT_TYPE NTSYSAPI LpcPortObjectType;
extern POBJECT_TYPE NTSYSAPI PsProcessType;

typedef EXCEPTION_DISPOSITION
(DDKAPI *PEXCEPTION_ROUTINE)(
  IN struct _EXCEPTION_RECORD *ExceptionRecord,
  IN PVOID EstablisherFrame,
  IN OUT struct _CONTEXT *ContextRecord,
  IN OUT PVOID DispatcherContext);

typedef NTSTATUS
(DDKAPI *PDRIVER_ENTRY)(
  IN struct _DRIVER_OBJECT  *DriverObject,
  IN PUNICODE_STRING  RegistryPath);

typedef BOOLEAN
(DDKAPI *PKTRANSFER_ROUTINE)(
  VOID);

#define ASSERT_GATE(object) \
    ASSERT((((object)->Header.Type & KOBJECT_TYPE_MASK) == GateObject) || \
          (((object)->Header.Type & KOBJECT_TYPE_MASK) == EventSynchronizationObject))

#define TIMER_TABLE_SIZE 512
#define TIMER_TABLE_SHIFT 9

#define ASSERT_TIMER(E) \
    ASSERT(((E)->Header.Type == TimerNotificationObject) || \
           ((E)->Header.Type == TimerSynchronizationObject))

#define ASSERT_MUTANT(E) \
    ASSERT((E)->Header.Type == MutantObject)

#define ASSERT_SEMAPHORE(E) \
    ASSERT((E)->Header.Type == SemaphoreObject)

#define ASSERT_EVENT(E) \
    ASSERT(((E)->Header.Type == NotificationEvent) || \
           ((E)->Header.Type == SynchronizationEvent))

#define KEYBOARD_INSERT_ON                0x08
#define KEYBOARD_CAPS_LOCK_ON             0x04
#define KEYBOARD_NUM_LOCK_ON              0x02
#define KEYBOARD_SCROLL_LOCK_ON           0x01
#define KEYBOARD_ALT_KEY_DOWN             0x80
#define KEYBOARD_CTRL_KEY_DOWN            0x40
#define KEYBOARD_LEFT_SHIFT_DOWN          0x20
#define KEYBOARD_RIGHT_SHIFT_DOWN         0x10

/* Function Type Defintions for Dispatch Functions */
struct _DEVICE_CONTROL_CONTEXT;

typedef VOID
(DDKAPI *PDEVICE_CONTROL_COMPLETION)(
  IN struct _DEVICE_CONTROL_CONTEXT  *ControlContext);

typedef struct _DEVICE_CONTROL_CONTEXT {
  NTSTATUS  Status;
  PDEVICE_HANDLER_OBJECT  DeviceHandler;
  PDEVICE_OBJECT  DeviceObject;
  ULONG  ControlCode;
  PVOID  Buffer;
  PULONG  BufferLength;
  PVOID  Context;
} DEVICE_CONTROL_CONTEXT, *PDEVICE_CONTROL_CONTEXT;

typedef NTSTATUS
(DDKAPI *pHalDeviceControl)(
  IN PDEVICE_HANDLER_OBJECT  DeviceHandler,
  IN PDEVICE_OBJECT  DeviceObject,
  IN ULONG  ControlCode,
  IN OUT PVOID  Buffer OPTIONAL,
  IN OUT PULONG  BufferLength OPTIONAL,
  IN PVOID  Context,
  IN PDEVICE_CONTROL_COMPLETION  CompletionRoutine);

typedef
ULONG
(DDKAPI *pHalGetInterruptVector)(
    IN INTERFACE_TYPE InterfaceType,
    IN ULONG BusNumber,
    IN ULONG BusInterruptLevel,
    IN ULONG BusInterruptVector,
    OUT PKIRQL Irql,
    OUT PKAFFINITY Affinity
);

typedef
NTSTATUS
(DDKAPI *pHalGetVectorInput)(
    IN ULONG Vector,
    IN KAFFINITY Affinity,
    OUT PULONG Input,
    OUT PKINTERRUPT_POLARITY Polarity
);

typedef struct _KEY_USER_FLAGS_INFORMATION {
  ULONG  UserFlags;
} KEY_USER_FLAGS_INFORMATION, *PKEY_USER_FLAGS_INFORMATION;

#define PCI_ADDRESS_MEMORY_SPACE            0x00000000

struct _RTL_RANGE;

typedef BOOLEAN
(NTAPI *PRTL_CONFLICT_RANGE_CALLBACK) (
    PVOID Context,
    struct _RTL_RANGE *Range
);

/*
** Storage structures
*/
typedef enum _PARTITION_STYLE {
  PARTITION_STYLE_MBR,
  PARTITION_STYLE_GPT,
  PARTITION_STYLE_RAW
} PARTITION_STYLE;

typedef struct _CREATE_DISK_MBR {
  ULONG  Signature;
} CREATE_DISK_MBR, *PCREATE_DISK_MBR;

typedef struct _CREATE_DISK_GPT {
  GUID  DiskId;
  ULONG  MaxPartitionCount;
} CREATE_DISK_GPT, *PCREATE_DISK_GPT;

typedef struct _CREATE_DISK {
  PARTITION_STYLE  PartitionStyle;
  _ANONYMOUS_UNION union {
    CREATE_DISK_MBR  Mbr;
    CREATE_DISK_GPT  Gpt;
  } DUMMYUNIONNAME;
} CREATE_DISK, *PCREATE_DISK;

typedef VOID
(FASTCALL*PTIME_UPDATE_NOTIFY_ROUTINE)(
  IN HANDLE  ThreadId,
  IN KPROCESSOR_MODE  Mode);

/*
** Architecture specific structures
*/

#ifdef _X86_

typedef struct _KPCR_TIB {
  PVOID  ExceptionList;         /* 00 */
  PVOID  StackBase;             /* 04 */
  PVOID  StackLimit;            /* 08 */
  PVOID  SubSystemTib;          /* 0C */
  _ANONYMOUS_UNION union {
    PVOID  FiberData;           /* 10 */
    ULONG  Version;             /* 10 */
  } DUMMYUNIONNAME;
  PVOID  ArbitraryUserPointer;  /* 14 */
  struct _KPCR_TIB *Self;       /* 18 */
} KPCR_TIB, *PKPCR_TIB;         /* 1C */

#define KeGetPcr()                      PCR

FORCEINLINE
ULONG
KeGetCurrentProcessorNumber(VOID)
{
    return (ULONG)__readfsbyte(FIELD_OFFSET(KPCR, Number));
}

extern NTKERNELAPI PVOID MmHighestUserAddress;
extern NTKERNELAPI PVOID MmSystemRangeStart;
extern NTKERNELAPI ULONG_PTR MmUserProbeAddress;

#define MM_HIGHEST_USER_ADDRESS           MmHighestUserAddress
#define MM_SYSTEM_RANGE_START             MmSystemRangeStart
#define MM_USER_PROBE_ADDRESS             MmUserProbeAddress
#define MM_LOWEST_USER_ADDRESS            (PVOID)0x10000
#define MM_LOWEST_SYSTEM_ADDRESS          (PVOID)0xC0C00000

#define MM_KSEG0_BASE       MM_SYSTEM_RANGE_START
#define MM_SYSTEM_SPACE_END 0xFFFFFFFF
    
#elif defined(__x86_64__)

typedef struct DECLSPEC_ALIGN(16) _CONTEXT {
    ULONG64 P1Home;
    ULONG64 P2Home;
    ULONG64 P3Home;
    ULONG64 P4Home;
    ULONG64 P5Home;
    ULONG64 P6Home;

    /* Control flags */
    ULONG ContextFlags;
    ULONG MxCsr;

    /* Segment */
    USHORT SegCs;
    USHORT SegDs;
    USHORT SegEs;
    USHORT SegFs;
    USHORT SegGs;
    USHORT SegSs;
    ULONG EFlags;

    /* Debug */
    ULONG64 Dr0;
    ULONG64 Dr1;
    ULONG64 Dr2;
    ULONG64 Dr3;
    ULONG64 Dr6;
    ULONG64 Dr7;

    /* Integer */
    ULONG64 Rax;
    ULONG64 Rcx;
    ULONG64 Rdx;
    ULONG64 Rbx;
    ULONG64 Rsp;
    ULONG64 Rbp;
    ULONG64 Rsi;
    ULONG64 Rdi;
    ULONG64 R8;
    ULONG64 R9;
    ULONG64 R10;
    ULONG64 R11;
    ULONG64 R12;
    ULONG64 R13;
    ULONG64 R14;
    ULONG64 R15;

    /* Counter */
    ULONG64 Rip;

   /* Floating point */
   union {
       XMM_SAVE_AREA32 FltSave;
       struct {
           M128A Header[2];
           M128A Legacy[8];
           M128A Xmm0;
           M128A Xmm1;
           M128A Xmm2;
           M128A Xmm3;
           M128A Xmm4;
           M128A Xmm5;
           M128A Xmm6;
           M128A Xmm7;
           M128A Xmm8;
           M128A Xmm9;
           M128A Xmm10;
           M128A Xmm11;
           M128A Xmm12;
           M128A Xmm13;
           M128A Xmm14;
           M128A Xmm15;
      } DUMMYSTRUCTNAME;
    } DUMMYUNIONNAME;

     /* Vector */
    M128A VectorRegister[26];
    ULONG64 VectorControl;

    /* Debug control */
    ULONG64 DebugControl;
    ULONG64 LastBranchToRip;
    ULONG64 LastBranchFromRip;
    ULONG64 LastExceptionToRip;
    ULONG64 LastExceptionFromRip;
} CONTEXT;

#define PAGE_SIZE   0x1000
#define PAGE_SHIFT 12L
#define PTI_SHIFT  12L
#define PDI_SHIFT  21L
#define PPI_SHIFT  30L
#define PXI_SHIFT  39L
#define PTE_PER_PAGE 512
#define PDE_PER_PAGE 512
#define PPE_PER_PAGE 512
#define PXE_PER_PAGE 512
#define PTI_MASK_AMD64 (PTE_PER_PAGE - 1)
#define PDI_MASK_AMD64 (PDE_PER_PAGE - 1)
#define PPI_MASK (PPE_PER_PAGE - 1)
#define PXI_MASK (PXE_PER_PAGE - 1)

#define PXE_BASE    0xFFFFF6FB7DBED000ULL
#define PXE_SELFMAP 0xFFFFF6FB7DBEDF68ULL
#define PPE_BASE    0xFFFFF6FB7DA00000ULL
#define PDE_BASE    0xFFFFF6FB40000000ULL
#define PTE_BASE    0xFFFFF68000000000ULL
#define PXE_TOP     0xFFFFF6FB7DBEDFFFULL
#define PPE_TOP     0xFFFFF6FB7DBFFFFFULL
#define PDE_TOP     0xFFFFF6FB7FFFFFFFULL
#define PTE_TOP     0xFFFFF6FFFFFFFFFFULL

extern NTKERNELAPI PVOID MmHighestUserAddress;
extern NTKERNELAPI PVOID MmSystemRangeStart;
extern NTKERNELAPI ULONG_PTR MmUserProbeAddress;

#define MM_HIGHEST_USER_ADDRESS           MmHighestUserAddress
#define MM_SYSTEM_RANGE_START             MmSystemRangeStart
#define MM_USER_PROBE_ADDRESS             MmUserProbeAddress
#define MM_LOWEST_USER_ADDRESS   (PVOID)0x10000
#define MM_LOWEST_SYSTEM_ADDRESS (PVOID)0xFFFF080000000000ULL
#define KI_USER_SHARED_DATA       0xFFFFF78000000000ULL

#define SharedUserData ((PKUSER_SHARED_DATA const)KI_USER_SHARED_DATA)
#define SharedInterruptTime (&SharedUserData->InterruptTime)
#define SharedSystemTime (&SharedUserData->SystemTime)
#define SharedTickCount (&SharedUserData->TickCount)

#define KeQueryInterruptTime() \
    (*(volatile ULONG64*)SharedInterruptTime)
#define KeQuerySystemTime(CurrentCount) \
    *(ULONG64*)(CurrentCount) = *(volatile ULONG64*)SharedSystemTime
#define KeQueryTickCount(CurrentCount) \
    *(ULONG64*)(CurrentCount) = *(volatile ULONG64*)SharedTickCount

typedef struct _KPCR
{
    __GNU_EXTENSION union
    {
        NT_TIB NtTib;
        __GNU_EXTENSION struct
        {
            union _KGDTENTRY64 *GdtBase;
            struct _KTSS64 *TssBase;
            ULONG64 UserRsp;
            struct _KPCR *Self;
            struct _KPRCB *CurrentPrcb;
            PKSPIN_LOCK_QUEUE LockArray;
            PVOID Used_Self;
        };
    };
    union _KIDTENTRY64 *IdtBase;
    ULONG64 Unused[2];
    KIRQL Irql;
    UCHAR SecondLevelCacheAssociativity;
    UCHAR ObsoleteNumber;
    UCHAR Fill0;
    ULONG Unused0[3];
    USHORT MajorVersion;
    USHORT MinorVersion;
    ULONG StallScaleFactor;
    PVOID Unused1[3];
    ULONG KernelReserved[15];
    ULONG SecondLevelCacheSize;
    ULONG HalReserved[16];
    ULONG Unused2;
    PVOID KdVersionBlock;
    PVOID Unused3;
    ULONG PcrAlign1[24];
} KPCR, *PKPCR;

typedef struct _KFLOATING_SAVE {
  ULONG Dummy;
} KFLOATING_SAVE, *PKFLOATING_SAVE;

FORCEINLINE
PKPCR
KeGetPcr(VOID)
{
    return (PKPCR)__readgsqword(FIELD_OFFSET(KPCR, Self));
}

FORCEINLINE
ULONG
KeGetCurrentProcessorNumber(VOID)
{
    return (ULONG)__readgsword(0x184);
}

#elif defined(__PowerPC__)

//
// Used to contain PFNs and PFN counts
//
typedef ULONG PFN_COUNT;
typedef ULONG PFN_NUMBER, *PPFN_NUMBER;
typedef LONG SPFN_NUMBER, *PSPFN_NUMBER;

#define PASSIVE_LEVEL                      0
#define LOW_LEVEL                          0
#define APC_LEVEL                          1
#define DISPATCH_LEVEL                     2
#define PROFILE_LEVEL                     27
#define CLOCK1_LEVEL                      28
#define CLOCK2_LEVEL                      28
#define IPI_LEVEL                         29
#define POWER_LEVEL                       30
#define HIGH_LEVEL                        31

typedef struct _KFLOATING_SAVE {
  ULONG Dummy;
} KFLOATING_SAVE, *PKFLOATING_SAVE;

typedef struct _KPCR_TIB {
  PVOID  ExceptionList;         /* 00 */
  PVOID  StackBase;             /* 04 */
  PVOID  StackLimit;            /* 08 */
  PVOID  SubSystemTib;          /* 0C */
  _ANONYMOUS_UNION union {
    PVOID  FiberData;           /* 10 */
    ULONG  Version;             /* 10 */
  } DUMMYUNIONNAME;
  PVOID  ArbitraryUserPointer;  /* 14 */
  struct _KPCR_TIB *Self;       /* 18 */
} KPCR_TIB, *PKPCR_TIB;         /* 1C */

#define PCR_MINOR_VERSION 1
#define PCR_MAJOR_VERSION 1

typedef struct _KPCR {
  KPCR_TIB  Tib;                /* 00 */
  struct _KPCR  *Self;          /* 1C */
  struct _KPRCB  *Prcb;         /* 20 */
  KIRQL  Irql;                  /* 24 */
  ULONG  IRR;                   /* 28 */
  ULONG  IrrActive;             /* 2C */
  ULONG  IDR;                   /* 30 */
  PVOID  KdVersionBlock;        /* 34 */
  PUSHORT  IDT;                 /* 38 */
  PUSHORT  GDT;                 /* 3C */
  struct _KTSS  *TSS;           /* 40 */
  USHORT  MajorVersion;         /* 44 */
  USHORT  MinorVersion;         /* 46 */
  KAFFINITY  SetMember;         /* 48 */
  ULONG  StallScaleFactor;      /* 4C */
  UCHAR  SpareUnused;           /* 50 */
  UCHAR  Number;                /* 51 */
} KPCR, *PKPCR;                 /* 54 */

#define KeGetPcr()                      PCR

static __inline
ULONG
DDKAPI
KeGetCurrentProcessorNumber(VOID)
{
    ULONG Number;
  __asm__ __volatile__ (
    "lwz %0, %c1(12)\n"
    : "=r" (Number)
    : "i" (FIELD_OFFSET(KPCR, Number))
  );
  return Number;
}

#elif defined(_MIPS_)

#error MIPS Headers are totally incorrect

//
// Used to contain PFNs and PFN counts
//
typedef ULONG PFN_COUNT;
typedef ULONG PFN_NUMBER, *PPFN_NUMBER;
typedef LONG SPFN_NUMBER, *PSPFN_NUMBER;

#define PASSIVE_LEVEL                      0
#define APC_LEVEL                          1
#define DISPATCH_LEVEL                     2
#define PROFILE_LEVEL                     27
#define IPI_LEVEL                         29
#define HIGH_LEVEL                        31

typedef struct _KPCR {
    struct _KPRCB  *Prcb;         /* 20 */
    KIRQL  Irql;                  /* 24 */
    ULONG  IRR;                   /* 28 */
    ULONG  IDR;                   /* 30 */
} KPCR, *PKPCR;

#define KeGetPcr()                      PCR

typedef struct _KFLOATING_SAVE {
} KFLOATING_SAVE, *PKFLOATING_SAVE;

static __inline
ULONG
DDKAPI
KeGetCurrentProcessorNumber(VOID)
{
    return 0;
}

#elif defined(_M_ARM)

//
// NT-ARM is not documented, need DDK-ARM
//
#include <armddk.h>

#else
#error Unknown architecture
#endif

/** SPINLOCK FUNCTIONS ********************************************************/

#if defined (_X86_)

#if defined(WIN9X_COMPAT_SPINLOCK)

NTKERNELAPI
VOID
NTAPI
KeInitializeSpinLock(
    IN PKSPIN_LOCK SpinLock
);

#else

FORCEINLINE
VOID
KeInitializeSpinLock(IN PKSPIN_LOCK SpinLock)
{
    /* Clear the lock */
    *SpinLock = 0;
}

#endif

NTHALAPI
KIRQL
FASTCALL
KfAcquireSpinLock(
  IN PKSPIN_LOCK SpinLock);

NTHALAPI
VOID
FASTCALL
KfReleaseSpinLock(
  IN PKSPIN_LOCK SpinLock,
  IN KIRQL NewIrql);

NTKERNELAPI
VOID
FASTCALL
KefAcquireSpinLockAtDpcLevel(
  IN PKSPIN_LOCK  SpinLock);

NTKERNELAPI
VOID
FASTCALL
KefReleaseSpinLockFromDpcLevel(
  IN PKSPIN_LOCK  SpinLock);

#define KeAcquireSpinLockAtDpcLevel(SpinLock) KefAcquireSpinLockAtDpcLevel(SpinLock)
#define KeReleaseSpinLockFromDpcLevel(SpinLock) KefReleaseSpinLockFromDpcLevel(SpinLock)
#define KeAcquireSpinLock(a,b)  *(b) = KfAcquireSpinLock(a)
#define KeReleaseSpinLock(a,b)  KfReleaseSpinLock(a,b)

#define KeGetDcacheFillSize() 1L
    
#elif defined(_M_ARM) // !defined (_X86_)
    
    FORCEINLINE
    VOID
    KeInitializeSpinLock(IN PKSPIN_LOCK SpinLock)
    {
        /* Clear the lock */
        *SpinLock = 0;
    }
    
    NTHALAPI
    KIRQL
    FASTCALL
    KfAcquireSpinLock(
                      IN PKSPIN_LOCK SpinLock);
    
    NTHALAPI
    VOID
    FASTCALL
    KfReleaseSpinLock(
                      IN PKSPIN_LOCK SpinLock,
                      IN KIRQL NewIrql);
    
    
    NTKERNELAPI
    VOID
    FASTCALL
    KefAcquireSpinLockAtDpcLevel(
                                 IN PKSPIN_LOCK  SpinLock);
    
    NTKERNELAPI
    VOID
    FASTCALL
    KefReleaseSpinLockFromDpcLevel(
                                   IN PKSPIN_LOCK  SpinLock);
    
    
#define KeAcquireSpinLockAtDpcLevel(SpinLock) KefAcquireSpinLockAtDpcLevel(SpinLock)
#define KeReleaseSpinLockFromDpcLevel(SpinLock) KefReleaseSpinLockFromDpcLevel(SpinLock)
#define KeAcquireSpinLock(a,b)  *(b) = KfAcquireSpinLock(a)
#define KeReleaseSpinLock(a,b)  KfReleaseSpinLock(a,b)
    
    NTKERNELAPI
    VOID
    NTAPI
    KeInitializeSpinLock(
                         IN PKSPIN_LOCK  SpinLock);
    
#else
    
FORCEINLINE
VOID
NTAPI
KeInitializeSpinLock(
  PKSPIN_LOCK SpinLock)
{
    *SpinLock = 0;
}

NTKERNELAPI
VOID
KeReleaseSpinLock(
  IN PKSPIN_LOCK SpinLock,
  IN KIRQL NewIrql);

NTKERNELAPI
VOID
KeAcquireSpinLockAtDpcLevel(
  IN PKSPIN_LOCK SpinLock);

NTKERNELAPI
VOID
KeReleaseSpinLockFromDpcLevel(
  IN PKSPIN_LOCK SpinLock);

NTKERNELAPI
KIRQL
KeAcquireSpinLockRaiseToDpc(
  IN PKSPIN_LOCK SpinLock);

#define KeAcquireSpinLock(SpinLock, OldIrql) \
  *(OldIrql) = KeAcquireSpinLockRaiseToDpc(SpinLock)
    
#endif // !defined (_X86_)

#define ARGUMENT_PRESENT(ArgumentPointer) \
  ((CHAR*)((ULONG_PTR)(ArgumentPointer)) != (CHAR*)NULL)

NTSYSAPI
VOID
NTAPI
RtlCopyMemory32(
  IN VOID UNALIGNED  *Destination,
  IN CONST VOID UNALIGNED  *Source,
  IN ULONG  Length);

/** Kernel routines **/

#ifdef _X86_

static __inline
VOID
KeMemoryBarrier(
  VOID)
{
  volatile LONG Barrier;
#if defined(__GNUC__)
  __asm__ __volatile__ ("xchg %%eax, %0" : : "m" (Barrier) : "%eax");
#elif defined(_MSC_VER)
  __asm xchg [Barrier], eax
#endif
}

#endif

#if !defined(_M_AMD64)

NTKERNELAPI
VOID
NTAPI
KeQueryTickCount(
  OUT PLARGE_INTEGER  TickCount);
#endif

NTKERNELAPI
VOID
FASTCALL
KeSetTimeUpdateNotifyRoutine(
  IN PTIME_UPDATE_NOTIFY_ROUTINE  NotifyRoutine);

#if defined(_X86_)

NTHALAPI
VOID
FASTCALL
KfLowerIrql(
  IN KIRQL  NewIrql);

NTHALAPI
KIRQL
FASTCALL
KfRaiseIrql(
  IN KIRQL  NewIrql);

NTHALAPI
KIRQL
DDKAPI
KeRaiseIrqlToDpcLevel(
  VOID);

NTHALAPI
KIRQL
DDKAPI
KeRaiseIrqlToSynchLevel(
    VOID);

#define KeLowerIrql(a) KfLowerIrql(a)
#define KeRaiseIrql(a,b) *(b) = KfRaiseIrql(a)

#elif defined(_M_AMD64)

FORCEINLINE
KIRQL
KeGetCurrentIrql(VOID)
{
    return (KIRQL)__readcr8();
}

FORCEINLINE
VOID
KeLowerIrql(IN KIRQL NewIrql)
{
    ASSERT(KeGetCurrentIrql() >= NewIrql);
    __writecr8(NewIrql);
}

FORCEINLINE
KIRQL
KfRaiseIrql(IN KIRQL NewIrql)
{
    KIRQL OldIrql;

    OldIrql = __readcr8();
    ASSERT(OldIrql <= NewIrql);
    __writecr8(NewIrql);
    return OldIrql;
}
#define KeRaiseIrql(a,b) *(b) = KfRaiseIrql(a)

FORCEINLINE
KIRQL
KeRaiseIrqlToDpcLevel(VOID)
{
    return KfRaiseIrql(DISPATCH_LEVEL);
}

FORCEINLINE
KIRQL
KeRaiseIrqlToSynchLevel(VOID)
{
    return KfRaiseIrql(12); // SYNCH_LEVEL = IPI_LEVEL - 2
}

#elif defined(__PowerPC__)

NTHALAPI
VOID
FASTCALL
KfLowerIrql(
  IN KIRQL  NewIrql);

NTHALAPI
KIRQL
FASTCALL
KfRaiseIrql(
  IN KIRQL  NewIrql);

NTHALAPI
KIRQL
DDKAPI
KeRaiseIrqlToDpcLevel(
  VOID);

NTHALAPI
KIRQL
DDKAPI
KeRaiseIrqlToSynchLevel(
    VOID);

#define KeLowerIrql(a) KfLowerIrql(a)
#define KeRaiseIrql(a,b) *(b) = KfRaiseIrql(a)

#elif defined(_M_MIPS)

#define KeLowerIrql(a) KfLowerIrql(a)
#define KeRaiseIrql(a,b) *(b) = KfRaiseIrql(a)

NTKERNELAPI
VOID
NTAPI
KfLowerIrql(
  IN KIRQL  NewIrql);

NTKERNELAPI
KIRQL
NTAPI
KfRaiseIrql(
  IN KIRQL  NewIrql);

NTKERNELAPI
KIRQL
NTAPI
KeRaiseIrqlToDpcLevel(
  VOID);

NTKERNELAPI
KIRQL
DDKAPI
KeRaiseIrqlToSynchLevel(
    VOID);

#elif defined(_M_ARM)

#include <armddk.h>

#else

NTKERNELAPI
VOID
NTAPI
KeLowerIrql(
  IN KIRQL  NewIrql);

NTKERNELAPI
VOID
NTAPI
KeRaiseIrql(
  IN KIRQL  NewIrql,
  OUT PKIRQL  OldIrql);

NTKERNELAPI
KIRQL
NTAPI
KeRaiseIrqlToDpcLevel(
  VOID);

NTKERNELAPI
KIRQL
DDKAPI
KeRaiseIrqlToSynchLevel(
    VOID);

#endif

/** Memory manager routines **/

NTKERNELAPI
NTSTATUS
NTAPI
MmMarkPhysicalMemoryAsBad(
  IN PPHYSICAL_ADDRESS  StartAddress,
  IN OUT PLARGE_INTEGER  NumberOfBytes);

NTKERNELAPI
NTSTATUS
NTAPI
MmMarkPhysicalMemoryAsGood(
  IN PPHYSICAL_ADDRESS  StartAddress,
  IN OUT PLARGE_INTEGER  NumberOfBytes);

/*
 * ULONG
 * ADDRESS_AND_SIZE_TO_SPAN_PAGES(
 *   IN PVOID  Va,
 *   IN ULONG  Size)
 */
#define ADDRESS_AND_SIZE_TO_SPAN_PAGES(_Va, \
                                       _Size) \
  ((ULONG) ((((ULONG_PTR) (_Va) & (PAGE_SIZE - 1)) \
    + (_Size) + (PAGE_SIZE - 1)) >> PAGE_SHIFT))

NTKERNELAPI
PVOID
NTAPI
MmLockPagableImageSection(
  IN PVOID  AddressWithinSection);

/*
 * PVOID
 * MmLockPagableCodeSection(
 *   IN PVOID  AddressWithinSection)
 */
#define MmLockPagableCodeSection(Address) MmLockPagableDataSection(Address)

NTKERNELAPI
PVOID
NTAPI
MmLockPageableDataSection (
    IN PVOID AddressWithinSection
);

NTKERNELAPI
VOID
NTAPI
MmUnlockPageableImageSection(
    IN PVOID ImageSectionHandle
);

/** Object manager routines **/

NTKERNELAPI
NTSTATUS
NTAPI
ObAssignSecurity(
  IN PACCESS_STATE  AccessState,
  IN PSECURITY_DESCRIPTOR  SecurityDescriptor,
  IN PVOID  Object,
  IN POBJECT_TYPE  Type);

NTKERNELAPI
VOID
NTAPI
ObDereferenceSecurityDescriptor(
  PSECURITY_DESCRIPTOR  SecurityDescriptor,
  ULONG  Count);

NTKERNELAPI
NTSTATUS
NTAPI
ObLogSecurityDescriptor(
  IN PSECURITY_DESCRIPTOR  InputSecurityDescriptor,
  OUT PSECURITY_DESCRIPTOR  *OutputSecurityDescriptor,
  IN ULONG RefBias);

NTKERNELAPI
NTSTATUS
NTAPI
ObOpenObjectByName(
  IN POBJECT_ATTRIBUTES  ObjectAttributes,
  IN POBJECT_TYPE  ObjectType,
  IN KPROCESSOR_MODE  AccessMode,
  IN PACCESS_STATE  PassedAccessState,
  IN ACCESS_MASK  DesiredAccess,
  IN OUT PVOID  ParseContext  OPTIONAL,
  OUT PHANDLE  Handle);

NTKERNELAPI
NTSTATUS
NTAPI
ObReferenceObjectByName(
  IN PUNICODE_STRING  ObjectPath,
  IN ULONG  Attributes,
  IN PACCESS_STATE  PassedAccessState  OPTIONAL,
  IN ACCESS_MASK  DesiredAccess  OPTIONAL,
  IN POBJECT_TYPE  ObjectType,
  IN KPROCESSOR_MODE  AccessMode,
  IN OUT PVOID  ParseContext  OPTIONAL,
  OUT PVOID  *Object);

NTKERNELAPI
VOID
NTAPI
ObReferenceSecurityDescriptor(
  IN PSECURITY_DESCRIPTOR  SecurityDescriptor,
  IN ULONG  Count);

/** Process manager routines **/

NTKERNELAPI
NTSTATUS
NTAPI
PsCreateSystemProcess(
  IN PHANDLE  ProcessHandle,
  IN ACCESS_MASK  DesiredAccess,
  IN POBJECT_ATTRIBUTES  ObjectAttributes);

/** NtXxx and ZwXxx routines **/

NTSYSCALLAPI
NTSTATUS
NTAPI
NtClose(
  IN HANDLE  Handle);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtCreateEvent(
  OUT PHANDLE  EventHandle,
  IN ACCESS_MASK  DesiredAccess,
  IN POBJECT_ATTRIBUTES  ObjectAttributes  OPTIONAL,
  IN EVENT_TYPE  EventType,
  IN BOOLEAN  InitialState);

NTSYSAPI
NTSTATUS
NTAPI
ZwCreateEvent(
  OUT PHANDLE  EventHandle,
  IN ACCESS_MASK  DesiredAccess,
  IN POBJECT_ATTRIBUTES  ObjectAttributes  OPTIONAL,
  IN EVENT_TYPE  EventType,
  IN BOOLEAN  InitialState);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtDeviceIoControlFile(
  IN HANDLE  DeviceHandle,
  IN HANDLE  Event  OPTIONAL,
  IN PIO_APC_ROUTINE  UserApcRoutine  OPTIONAL,
  IN PVOID  UserApcContext  OPTIONAL,
  OUT PIO_STATUS_BLOCK  IoStatusBlock,
  IN ULONG  IoControlCode,
  IN PVOID  InputBuffer,
  IN ULONG  InputBufferSize,
  OUT PVOID  OutputBuffer,
  IN ULONG  OutputBufferSize);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtMapViewOfSection(
  IN HANDLE  SectionHandle,
  IN HANDLE  ProcessHandle,
  IN OUT PVOID  *BaseAddress,
  IN ULONG_PTR  ZeroBits,
  IN SIZE_T  CommitSize,
  IN OUT PLARGE_INTEGER  SectionOffset  OPTIONAL,
  IN OUT PSIZE_T  ViewSize,
  IN SECTION_INHERIT  InheritDisposition,
  IN ULONG  AllocationType,
  IN ULONG  Protect);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtOpenFile(
  OUT PHANDLE  FileHandle,
  IN ACCESS_MASK  DesiredAccess,
  IN POBJECT_ATTRIBUTES  ObjectAttributes,
  OUT PIO_STATUS_BLOCK  IoStatusBlock,
  IN ULONG  ShareAccess,
  IN ULONG  OpenOptions);



NTSYSAPI
NTSTATUS
NTAPI
ZwOpenFile(
  OUT PHANDLE  FileHandle,
  IN ACCESS_MASK  DesiredAccess,
  IN POBJECT_ATTRIBUTES  ObjectAttributes,
  OUT PIO_STATUS_BLOCK  IoStatusBlock,
  IN ULONG  ShareAccess,
  IN ULONG  OpenOptions);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtReadFile(
  IN HANDLE  FileHandle,
  IN HANDLE  Event  OPTIONAL,
  IN PIO_APC_ROUTINE  ApcRoutine  OPTIONAL,
  IN PVOID  ApcContext  OPTIONAL,
  OUT PIO_STATUS_BLOCK  IoStatusBlock,
  OUT PVOID  Buffer,
  IN ULONG  Length,
  IN PLARGE_INTEGER  ByteOffset  OPTIONAL,
  IN PULONG  Key  OPTIONAL);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtSetEvent(
  IN HANDLE  EventHandle,
  OUT PLONG  PreviousState  OPTIONAL);

NTSYSAPI
NTSTATUS
NTAPI
ZwSetEvent(
  IN HANDLE  EventHandle,
  OUT PLONG  PreviousState  OPTIONAL);

/* [Nt|Zw]MapViewOfSection.InheritDisposition constants */
#define AT_EXTENDABLE_FILE                0x00002000
#define AT_RESERVED                       0x20000000
#define AT_ROUND_TO_PAGE                  0x40000000

NTSYSCALLAPI
NTSTATUS
NTAPI
NtUnmapViewOfSection(
  IN HANDLE  ProcessHandle,
  IN PVOID  BaseAddress);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtWaitForSingleObject(
  IN HANDLE  ObjectHandle,
  IN BOOLEAN  Alertable,
  IN PLARGE_INTEGER  TimeOut  OPTIONAL);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtWriteFile(
  IN HANDLE  FileHandle,
  IN HANDLE  Event  OPTIONAL,
  IN PIO_APC_ROUTINE  ApcRoutine  OPTIONAL,
  IN PVOID  ApcContext  OPTIONAL,
  OUT PIO_STATUS_BLOCK  IoStatusBlock,
  IN PVOID  Buffer,
  IN ULONG  Length,
  IN PLARGE_INTEGER  ByteOffset  OPTIONAL,
  IN PULONG  Key  OPTIONAL);

/** Power management support routines **/

NTKERNELAPI
NTSTATUS
NTAPI
PoRequestShutdownEvent(
  OUT PVOID  *Event);

/** WMI library support routines **/

NTSTATUS
NTAPI
WmiCompleteRequest(
  IN PDEVICE_OBJECT  DeviceObject,
  IN PIRP  Irp,
  IN NTSTATUS  Status,
  IN ULONG  BufferUsed,
  IN CCHAR  PriorityBoost);

NTSTATUS
NTAPI
WmiFireEvent(
  IN PDEVICE_OBJECT  DeviceObject,
  IN LPGUID  Guid,
  IN ULONG  InstanceIndex,
  IN ULONG  EventDataSize,
  IN PVOID  EventData);

NTSTATUS
NTAPI
WmiSystemControl(
  IN PWMILIB_CONTEXT  WmiLibInfo,
  IN PDEVICE_OBJECT  DeviceObject,
  IN PIRP  Irp,
  OUT PSYSCTL_IRP_DISPOSITION  IrpDisposition);

/** Stuff from winnt4.h */

#ifndef _X86_
NTKERNELAPI
INTERLOCKED_RESULT
NTAPI
ExInterlockedDecrementLong(
  IN PLONG  Addend,
  IN PKSPIN_LOCK  Lock);

NTKERNELAPI
ULONG
NTAPI
ExInterlockedExchangeUlong(
  IN PULONG  Target,
  IN ULONG  Value,
  IN PKSPIN_LOCK  Lock);

NTKERNELAPI
INTERLOCKED_RESULT
NTAPI
ExInterlockedIncrementLong(
  IN PLONG  Addend,
  IN PKSPIN_LOCK  Lock);
#endif

NTHALAPI
ULONG
NTAPI
HalGetDmaAlignmentRequirement(
  VOID);

NTSYSAPI
BOOLEAN
NTAPI
RtlLargeIntegerEqualToZero(
  IN LARGE_INTEGER  Operand);

NTSYSAPI
BOOLEAN
NTAPI
RtlLargeIntegerGreaterOrEqualToZero(
  IN LARGE_INTEGER  Operand);

NTSYSAPI
BOOLEAN
NTAPI
RtlLargeIntegerGreaterThan(
  IN LARGE_INTEGER  Operand1,
  IN LARGE_INTEGER  Operand2);

NTSYSAPI
BOOLEAN
NTAPI
RtlLargeIntegerGreaterThanOrEqualTo(
  IN LARGE_INTEGER  Operand1,
  IN LARGE_INTEGER  Operand2);

NTSYSAPI
BOOLEAN
NTAPI
RtlLargeIntegerGreaterThanZero(
  IN LARGE_INTEGER  Operand);

NTSYSAPI
BOOLEAN
NTAPI
RtlLargeIntegerLessOrEqualToZero(
  IN LARGE_INTEGER  Operand);

NTSYSAPI
BOOLEAN
NTAPI
RtlLargeIntegerLessThan(
  IN LARGE_INTEGER  Operand1,
  IN LARGE_INTEGER  Operand2);

NTSYSAPI
BOOLEAN
NTAPI
RtlLargeIntegerLessThanOrEqualTo(
  IN LARGE_INTEGER  Operand1,
  IN LARGE_INTEGER  Operand2);

NTSYSAPI
BOOLEAN
NTAPI
RtlLargeIntegerLessThanZero(
  IN LARGE_INTEGER  Operand);

NTSYSAPI
LARGE_INTEGER
NTAPI
RtlLargeIntegerNegate(
  IN LARGE_INTEGER  Subtrahend);

NTSYSAPI
BOOLEAN
NTAPI
RtlLargeIntegerNotEqualTo(
  IN LARGE_INTEGER  Operand1,
  IN LARGE_INTEGER  Operand2);

NTSYSAPI
BOOLEAN
NTAPI
RtlLargeIntegerNotEqualToZero(
  IN LARGE_INTEGER  Operand);

NTSYSAPI
LARGE_INTEGER
NTAPI
RtlLargeIntegerShiftLeft(
  IN LARGE_INTEGER  LargeInteger,
  IN CCHAR  ShiftCount);

NTSYSAPI
LARGE_INTEGER
NTAPI
RtlLargeIntegerShiftRight(
  IN LARGE_INTEGER  LargeInteger,
  IN CCHAR  ShiftCount);

NTSYSAPI
LARGE_INTEGER
NTAPI
RtlLargeIntegerSubtract(
  IN LARGE_INTEGER  Minuend,
  IN LARGE_INTEGER  Subtrahend);


/*
 * ULONG
 * COMPUTE_PAGES_SPANNED(
 *   IN PVOID  Va,
 *   IN ULONG  Size)
 */
#define COMPUTE_PAGES_SPANNED(Va, \
                              Size) \
  (ADDRESS_AND_SIZE_TO_SPAN_PAGES(Va, Size))


/*
** Architecture specific structures
*/


#ifdef _M_ARM
//
// NT-ARM is not documented
//
#include <armddk.h>   
#endif

#ifdef __cplusplus
}
#endif

#endif /* __WINDDK_H */
