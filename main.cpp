#include "common.h"

pPsRegisterAltSystemCallHandler PsRegisterAltSystemCallHandler = nullptr;
pZwSetInformationProcess ZwSetInformationProcess = nullptr;
pPsGetProcessImageFileName PsGetProcessImageFileName = nullptr;

void debug_print(const char* format, ...) {
	return; // remove if no debug

	va_list args;
	va_start(args, format);
	vDbgPrintEx(DPFLTR_IHVDRIVER_ID, DPFLTR_INFO_LEVEL, format, args);
	va_end(args);
}

bool alt_syscall_handler(PKTRAP_FRAME trap_frame) {
	if (!trap_frame)
		return false;

	KTRAP_FRAME copied_frame = {};
	memcpy(&copied_frame, trap_frame, sizeof(KTRAP_FRAME)); 

	debug_print("[*] enter syscall \n");

	PETHREAD current_thread = KeGetCurrentThread();
	PEPROCESS current_process = (PEPROCESS)current_thread->Process;

	debug_print("[*] current thread -> %p \n", current_thread);

	if (current_process) {
		debug_print("[*] current process -> %p \n", current_process);
		debug_print("[*] process image name -> %s \n", PsGetProcessImageFileName(current_process));
	}

	debug_print("[*] syscall -> %llu \n", copied_frame.Rax);

	debug_print("[*] exit syscall \n");

	return true;
}

void process_create_routine(HANDLE parent_id, HANDLE process_id, bool create) {
	UNREFERENCED_PARAMETER(parent_id);
	
	if (create) {
		debug_print("[*] process being created -> %u \n", HandleToULong(process_id));

		OBJECT_ATTRIBUTES object_attributes = { sizeof(OBJECT_ATTRIBUTES), NULL };
		CLIENT_ID client_id = { (HANDLE)process_id, NULL };
		HANDLE process_handle = nullptr;

		NTSTATUS status = ZwOpenProcess(&process_handle, PROCESS_ALL_ACCESS, &object_attributes, &client_id);
		if (!NT_SUCCESS(status)) {
			debug_print("[*] failed to open handle to process -> %u \n", HandleToULong(process_id));
			return;
		}

		debug_print("[*] opened handle to process -> %p \n", process_handle);

		status = ZwSetInformationProcess(process_handle, 0x64, &process_id, 1);
		if (!NT_SUCCESS(status)) {
			debug_print("[*] failed to set process information -> 0x%08lX \n", status);
			ZwClose(process_handle);
			return;
		}

		debug_print("[*] set process information successfully \n");

		ZwClose(process_handle);
	}
	else {
		debug_print("[*] process being terminated -> %p \n", process_id);
	}
}

void driver_unload(PDRIVER_OBJECT driver_object) {
	UNREFERENCED_PARAMETER(driver_object);

	debug_print("[*] unload called \n");

	NTSTATUS status =
		PsSetCreateProcessNotifyRoutine((PCREATE_PROCESS_NOTIFY_ROUTINE)process_create_routine, true);

	if (!NT_SUCCESS(status)) {
		debug_print("[*] failed to unregister process notify routine \n");
	}
	else {
		debug_print("[*] unregistered process notify routine \n");
	}
}

extern "C" NTSTATUS FxDriverEntry(PDRIVER_OBJECT driver_object, PUNICODE_STRING registry_path) { 
	UNREFERENCED_PARAMETER(registry_path);

	driver_object->DriverUnload = driver_unload;

	debug_print("[*] entry called \n");

	UNICODE_STRING routine_string = {};

	RtlInitUnicodeString(&routine_string, L"PsRegisterAltSystemCallHandler");
	PsRegisterAltSystemCallHandler = (pPsRegisterAltSystemCallHandler)MmGetSystemRoutineAddress(&routine_string);

	RtlInitUnicodeString(&routine_string, L"ZwSetInformationProcess");
	ZwSetInformationProcess = (pZwSetInformationProcess)MmGetSystemRoutineAddress(&routine_string);

	RtlInitUnicodeString(&routine_string, L"PsGetProcessImageFileName");
	PsGetProcessImageFileName = (pPsGetProcessImageFileName)MmGetSystemRoutineAddress(&routine_string);

	if (!ZwSetInformationProcess || !PsRegisterAltSystemCallHandler || !PsGetProcessImageFileName) {
		debug_print("[*] failed to aquire needed routines \n");
		return STATUS_UNSUCCESSFUL;
	}

	debug_print("[*] acquired needed routines \n");

	NTSTATUS status = PsRegisterAltSystemCallHandler(&alt_syscall_handler, 1);
	if (!NT_SUCCESS(status)) {
		debug_print("[*] failed to register alt syscall handler \n");
		return STATUS_UNSUCCESSFUL;
	}
	
	debug_print("[*] registered alt syscall handler \n");

	status = 
		PsSetCreateProcessNotifyRoutine((PCREATE_PROCESS_NOTIFY_ROUTINE)process_create_routine, false);

	if (!NT_SUCCESS(status)) {
		debug_print("[*] failed to register process notify routine \n");
		return STATUS_UNSUCCESSFUL;
	}

	debug_print("[*] registered process notify routine \n");

	return STATUS_SUCCESS;
}