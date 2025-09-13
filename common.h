#ifndef common_h
#define common_h

#include <cstdint>
#include <stdarg.h>
#include <ntifs.h>
#include <ntddk.h>
#include <ntimage.h>
#include <intrin.h>

#include "ketypes.h"
#include "mmtypes.h"

typedef bool ALT_SYSCALL_HANDLER(
	PKTRAP_FRAME trap_frame
);

typedef char* (*pPsGetProcessImageFileName)(PEPROCESS);
typedef NTSTATUS(*pPsRegisterAltSystemCallHandler)(ALT_SYSCALL_HANDLER handler, int);
typedef NTSTATUS(*pZwSetInformationProcess)(HANDLE handle, std::uint32_t info_class, void* information, std::uint32_t length);

#endif