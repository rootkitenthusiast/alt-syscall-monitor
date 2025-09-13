#ifndef ketypes_h
#define ketypes_h

typedef struct _KLDR_DATA_TABLE_ENTRY {
  LIST_ENTRY in_load_order_links;
  std::uint64_t exception_table;
  std::uint32_t exception_table_size;
  std::uint64_t gp_value;
  std::uint64_t non_paged_debug_info;
  std::uint64_t image_base;
  std::uint64_t image_entry;
  std::uint32_t image_size;
  UNICODE_STRING image_full_name;
  UNICODE_STRING image_base_name;
  std::uint32_t flags;
  std::uint16_t load_count;
  union {
    std::uint16_t signature_level : 4;
    std::uint16_t signature_type : 3;
    std::uint16_t unused : 9;
    std::uint16_t entire_field;
  } signature_field;
  std::uint64_t section_pointer;
  std::uint32_t check_sum;
  std::uint32_t converage_section_size;
  std::uint64_t coverage_section;
  std::uint64_t loaded_imports;
  std::uint64_t spare;
  std::uint32_t size_of_image_non_rounded;
  std::uint32_t time_date_stamped;
} KLDR_DATA_TABLE_ENTRY, *PKLDR_DATA_TABLE_ENTRY;

struct _KTHREAD {
  DISPATCHER_HEADER Header;
  void *SListFaultAddress;
  std::uint64_t QuantumTarget;
  void *InitialStack;
  void *volatile StackLimit;
  void *StackBase;
  std::uint64_t ThreadLock;
  volatile std::uint64_t CycleTime;
  std::uint32_t CurrentRunTime;
  std::uint32_t ExpectedRunTime;
  void *KernelStack;
  _XSAVE_FORMAT *StateSaveArea;
  struct _KSCHEDULING_GROUP *volatile SchedulingGroup;
  std::uint8_t WaitRegister;
  volatile std::uint8_t Running;
  std::uint8_t Alerted[2];

  union {
    struct {
      std::uint32_t AutoBoostActive : 1;
      std::uint32_t ReadyTransition : 1;
      std::uint32_t WaitNext : 1;
      std::uint32_t SystemAffinityActive : 1;
      std::uint32_t Alertable : 1;
      std::uint32_t UserStackWalkActive : 1;
      std::uint32_t ApcInterruptRequest : 1;
      std::uint32_t QuantumEndMigrate : 1;
      std::uint32_t UmsDirectedSwitchEnable : 1;
      std::uint32_t TimerActive : 1;
      std::uint32_t SystemThread : 1;
      std::uint32_t ProcessDetachActive : 1;
      std::uint32_t CalloutActive : 1;
      std::uint32_t ScbReadyQueue : 1;
      std::uint32_t ApcQueueable : 1;
      std::uint32_t ReservedStackInUse : 1;
      std::uint32_t UmsPerformingSyscall : 1;
      std::uint32_t TimerSuspended : 1;
      std::uint32_t SuspendedWaitMode : 1;
      std::uint32_t SuspendSchedulerApcWait : 1;
      std::uint32_t CetUserShadowStack : 1;
      std::uint32_t BypassProcessFreeze : 1;
      std::uint32_t Reserved : 10;
    };
    std::int32_t MiscFlags;
  };

  union {
    struct {
      std::uint32_t ThreadFlagsSpare : 2;
      std::uint32_t AutoAlignment : 1;
      std::uint32_t DisableBoost : 1;
      std::uint32_t AlertedByThreadId : 1;
      std::uint32_t QuantumDonation : 1;
      std::uint32_t EnableStackSwap : 1;
      std::uint32_t GuiThread : 1;
      std::uint32_t DisableQuantum : 1;
      std::uint32_t ChargeOnlySchedulingGroup : 1;
      std::uint32_t DeferPreemption : 1;
      std::uint32_t QueueDeferPreemption : 1;
      std::uint32_t ForceDeferSchedule : 1;
      std::uint32_t SharedReadyQueueAffinity : 1;
      std::uint32_t FreezeCount : 1;
      std::uint32_t TerminationApcRequest : 1;
      std::uint32_t AutoBoostEntriesExhausted : 1;
      std::uint32_t KernelStackResident : 1;
      std::uint32_t TerminateRequestReason : 2;
      std::uint32_t ProcessStackCountDecremented : 1;
      std::uint32_t RestrictedGuiThread : 1;
      std::uint32_t VpBackingThread : 1;
      std::uint32_t ThreadFlagsSpare2 : 1;
      std::uint32_t EtwStackTraceApcInserted : 8;
    };
    volatile std::int32_t ThreadFlags;
  };

  volatile std::uint8_t Tag;
  std::uint8_t SystemHeteroCpuPolicy;
  std::uint8_t UserHeteroCpuPolicy : 7;
  std::uint8_t ExplicitSystemHeteroCpuPolicy : 1;

  union {
    struct {
      std::uint8_t RunningNonRetpolineCode : 1;
      std::uint8_t SpecCtrlSpare : 7;
    };
    std::uint8_t SpecCtrl;
  };

  std::uint32_t SystemCallNumber;
  std::uint32_t ReadyTime;
  void *FirstArgument;
  struct _KTRAP_FRAME *TrapFrame;

  union {
    struct _KAPC_STATE ApcState;
    struct {
      std::uint8_t ApcStateFill[43];
      char Priority;
      std::uint32_t UserIdealProcessor;
    };
  };

  volatile std::int32_t WaitStatus;
  struct _KWAIT_BLOCK *WaitBlockList;

  union {
    struct _LIST_ENTRY WaitListEntry;
    struct _SINGLE_LIST_ENTRY SwapListEntry;
  };

  struct _DISPATCHER_HEADER *volatile Queue;
  void *Teb;
  std::uint64_t RelativeTimerBias;
  KTIMER Timer;

  union {
    struct _KWAIT_BLOCK WaitBlock[4];
    struct {
      std::uint8_t WaitBlockFill4[20];
      std::uint32_t ContextSwitches;
    };

    struct {
      std::uint8_t WaitBlockFill5[68];
      volatile std::uint8_t State;
      char Spare13;
      std::uint8_t WaitIrql;
      char WaitMode;
    };

    struct {
      std::uint8_t WaitBlockFill6[116];
      std::uint32_t WaitTime;
    };

    struct {
      std::uint8_t WaitBlockFill7[164];
      union {
        struct {
          SHORT KernelApcDisable;
          SHORT SpecialApcDisable;
        };
        std::uint32_t CombinedApcDisable;
      };
    };

    struct {
      std::uint8_t WaitBlockFill8[40];
      struct _KTHREAD_COUNTERS *ThreadCounters;
    };

    struct {
      std::uint8_t WaitBlockFill9[88];
      struct _XSTATE_SAVE *XStateSave;
    };

    struct {
      std::uint8_t WaitBlockFill10[136];
      void *volatile Win32Thread;
    };

    struct {
      std::uint8_t WaitBlockFill11[176];
      struct _UMS_CONTROL_BLOCK *Ucb;
      struct _KUMS_CONTEXT_HEADER *volatile Uch;
    };
  };

  union {
    volatile std::int32_t ThreadFlags2;
    struct {
      std::uint32_t BamQosLevel : 8;
      std::uint32_t ThreadFlags2Reserved : 24;
    };
  };

  std::uint32_t Spare21;
  struct _LIST_ENTRY QueueListEntry;

  union {
    volatile std::uint32_t NextProcessor;
    struct {
      std::uint32_t NextProcessorNumber : 31;
      std::uint32_t SharedReadyQueue : 1;
    };
  };

  std::int32_t QueuePriority;
  struct KPROCESS *Process;

  union {
    struct _GROUP_AFFINITY UserAffinity;
    struct {
      std::uint8_t UserAffinityFill[10];
      char PreviousMode;
      char BasePriority;
      union {
        char PriorityDecrement;
        struct {
          std::uint8_t ForegroundBoost : 4;
          std::uint8_t UnusualBoost : 4;
        };
      };
      std::uint8_t Preempted;
      std::uint8_t AdjustReason;
      char AdjustIncrement;
    };
  };

  std::uint64_t AffinityVersion;

  union {
    struct _GROUP_AFFINITY Affinity;
    struct {
      std::uint8_t AffinityFill[10];
      std::uint8_t ApcStateIndex;
      std::uint8_t WaitBlockCount;
      std::uint32_t IdealProcessor;
    };
  };

  std::uint64_t NpxState;

  union {
    struct _KAPC_STATE SavedApcState;
    struct {
      std::uint8_t SavedApcStateFill[43];
      std::uint8_t WaitReason;
      char SuspendCount;
      char Saturation;
      USHORT SListFaultCount;
    };
  };

  union {
    struct _KAPC SchedulerApc;
    struct {
      std::uint8_t SchedulerApcFill0[1];
      std::uint8_t ResourceIndex;
    };

    struct {
      std::uint8_t SchedulerApcFill1[3];
      std::uint8_t QuantumReset;
    };

    struct {
      std::uint8_t SchedulerApcFill2[4];
      std::uint32_t KernelTime;
    };

    struct {
      std::uint8_t SchedulerApcFill3[64];
      struct _KPRCB *volatile WaitPrcb;
    };

    struct {
      std::uint8_t SchedulerApcFill4[72];
      void *LegoData;
    };

    struct {
      std::uint8_t SchedulerApcFill5[83];
      std::uint8_t CallbackNestingLevel;
      std::uint32_t UserTime;
    };
  };

  struct _KEVENT SuspendEvent;
  struct _LIST_ENTRY ThreadListEntry;
  struct _LIST_ENTRY MutantListHead;
};

typedef struct _SYSTEM_SERVICE_TABLE {
  std::uint32_t *service_table_base; // SSDT (System Service Dispatch Table)
  std::uint32_t
      *service_counter_base; // Used for checked builds, contains the number of
                             // times each service in the SSDT has been called
  std::uint32_t
      service_count; // The number of service functions, NumberOfService*4 is
                     // the size of the entire address table
  std::uint32_t param_table_base; // SSPT (System Service Parameter Table)
} SYSTEM_SERVICE_TABLE, *PSYSTEM_SERVICE_TABLE;

typedef struct _SERVICE_DESCRIPTOR_TABLE {
  SYSTEM_SERVICE_TABLE ntoskrnl; // ntoskrnl.exe
  SYSTEM_SERVICE_TABLE win32k;   // win32k.sys
  SYSTEM_SERVICE_TABLE reserved0;
  SYSTEM_SERVICE_TABLE reserved1;
} SYSTEM_DESCRIPTOR_TABLE, *PSYSTEM_DESCRIPTOR_TABLE;

#endif