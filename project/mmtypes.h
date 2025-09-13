#ifndef mmtypes_h
#define mmtypes_h



/**
 * @defgroup intel_manual \
 *           Intel Manual
 * @{
 */
/**
 * @defgroup control_registers \
 *           Control registers
 * @{
 */
typedef union {
  struct {
    std::uint64_t protection_enable : 1;
    std::uint64_t monitor_coprocessor : 1;
    std::uint64_t emulate_fpu : 1;
    std::uint64_t task_switched : 1;
    std::uint64_t extension_type : 1;
    std::uint64_t numeric_error : 1;
    std::uint64_t reserved_1 : 10;
    std::uint64_t write_protect : 1;
    std::uint64_t reserved_2 : 1;
    std::uint64_t alignment_mask : 1;
    std::uint64_t reserved_3 : 10;
    std::uint64_t not_write_through : 1;
    std::uint64_t cache_disable : 1;
    std::uint64_t paging_enable : 1;
  };

  std::uint64_t flags;
} cr0_t;

typedef union {
  struct {
    std::uint64_t reserved_1 : 3;
    std::uint64_t page_level_write_through : 1;
    std::uint64_t page_level_cache_disable : 1;
    std::uint64_t reserved_2 : 7;
    std::uint64_t address_of_page_directory : 36;
  };

  std::uint64_t flags;
} cr3_t;

typedef union {
  struct {
    std::uint64_t page_index : 12; /* 0:11  */
    std::uint64_t pt_index : 9;    /* 12:20 */
    std::uint64_t pd_index : 9;    /* 21:29 */
    std::uint64_t pdpt_index : 9;  /* 30:38 */
    std::uint64_t pml4_index : 9;  /* 39:47 */
    std::uint64_t reserved_1 : 16; /* 48:63 */
  };

  std::uint64_t flags;
} virtual_address_t;

typedef union {
  struct {
    std::uint64_t virtual_mode_extensions : 1;
    std::uint64_t protected_mode_virtual_interrupts : 1;
    std::uint64_t timestamp_disable : 1;
    std::uint64_t debugging_extensions : 1;
    std::uint64_t page_size_extensions : 1;
    std::uint64_t physical_address_extension : 1;
    std::uint64_t machine_check_enable : 1;
    std::uint64_t page_global_enable : 1;
    std::uint64_t performance_monitoring_counter_enable : 1;
    std::uint64_t os_fxsave_fxrstor_support : 1;
    std::uint64_t os_xmm_exception_support : 1;
    std::uint64_t usermode_instruction_prevention : 1;
    std::uint64_t linear_addresses_57_bit : 1;
    std::uint64_t vmx_enable : 1;
    std::uint64_t smx_enable : 1;
    std::uint64_t reserved_1 : 1;
    std::uint64_t fsgsbase_enable : 1;
    std::uint64_t pcid_enable : 1;
    std::uint64_t os_xsave : 1;
    std::uint64_t key_locker_enable : 1;
    std::uint64_t smep_enable : 1;
    std::uint64_t smap_enable : 1;
    std::uint64_t protection_key_enable : 1;
    std::uint64_t control_flow_enforcement_enable : 1;
    std::uint64_t protection_key_for_supervisor_mode_enable : 1;
  };

  std::uint64_t flags;
} cr4_t;

typedef union {
  struct {
    std::uint64_t task_priority_level : 4;
    std::uint64_t reserved : 60;
  };

  std::uint64_t flags;
} cr8_t;

/**
 * @}
 */

/**
 * @defgroup debug_registers \
 *           Debug registers
 * @{
 */
typedef union {
  struct {
    std::uint64_t breakpoint_condition : 4;
    std::uint64_t reserved_1 : 9;
    std::uint64_t debug_register_access_detected : 1;
    std::uint64_t single_instruction : 1;
    std::uint64_t task_switch : 1;
    std::uint64_t restricted_transactional_memory : 1;
  };

  std::uint64_t flags;
} dr6_t;

typedef union {
  struct {
    std::uint64_t local_breakpoint_0 : 1;
    std::uint64_t global_breakpoint_0 : 1;
    std::uint64_t local_breakpoint_1 : 1;
    std::uint64_t global_breakpoint_1 : 1;
    std::uint64_t local_breakpoint_2 : 1;
    std::uint64_t global_breakpoint_2 : 1;
    std::uint64_t local_breakpoint_3 : 1;
    std::uint64_t global_breakpoint_3 : 1;
    std::uint64_t local_exact_breakpoint : 1;
    std::uint64_t global_exact_breakpoint : 1;
    std::uint64_t reserved_1 : 1;
    std::uint64_t restricted_transactional_memory : 1;
    std::uint64_t reserved_2 : 1;
    std::uint64_t general_detect : 1;
    std::uint64_t reserved_3 : 2;
    std::uint64_t read_write_0 : 2;
    std::uint64_t length_0 : 2;
    std::uint64_t read_write_1 : 2;
    std::uint64_t length_1 : 2;
    std::uint64_t read_write_2 : 2;
    std::uint64_t length_2 : 2;
    std::uint64_t read_write_3 : 2;
    std::uint64_t length_3 : 2;
  };

  std::uint64_t flags;
} dr7_t;

#define IA32_STAR 0xC0000081
#define IA32_LSTAR 0xC0000082
#define IA32_CSTAR 0xC0000083
#define IA32_FMASK 0xC0000084
#define IA32_FS_BASE 0xC0000100
#define IA32_GS_BASE 0xC0000101
#define IA32_KERNEL_GS_BASE 0xC0000102
#define IA32_TSC_AUX 0xC0000103
typedef union {
  struct {
    std::uint64_t tsc_auxiliary_signature : 32;
  };

  std::uint64_t flags;
} ia32_tsc_aux_register;

/**
 * @}
 */

/**
 * @defgroup paging \
 *           Paging
 * @{
 */
/**
 * @defgroup paging_32 \
 *           32-Bit Paging
 * @{
 */
typedef union {
  struct {
    std::uint32_t present : 1;
    std::uint32_t write : 1;
    std::uint32_t supervisor : 1;
    std::uint32_t page_level_write_through : 1;
    std::uint32_t page_level_cache_disable : 1;
    std::uint32_t accessed : 1;
    std::uint32_t dirty : 1;
    std::uint32_t large_page : 1;
    std::uint32_t global : 1;
    std::uint32_t ignored_1 : 3;
    std::uint32_t pat : 1;
    std::uint32_t page_frame_number_low : 8;
    std::uint32_t reserved_1 : 1;
    std::uint32_t page_frame_number_high : 10;
  };

  std::uint32_t flags;
} pde_4mb_32_t;

typedef union {
  struct {
    std::uint32_t present : 1;
    std::uint32_t write : 1;
    std::uint32_t supervisor : 1;
    std::uint32_t page_level_write_through : 1;
    std::uint32_t page_level_cache_disable : 1;
    std::uint32_t accessed : 1;
    std::uint32_t ignored_1 : 1;
    std::uint32_t large_page : 1;
    std::uint32_t ignored_2 : 4;
    std::uint32_t page_frame_number : 20;
  };

  std::uint32_t flags;
} pde_32_t;

typedef union {
  struct {
    std::uint32_t present : 1;
    std::uint32_t write : 1;
    std::uint32_t supervisor : 1;
    std::uint32_t page_level_write_through : 1;
    std::uint32_t page_level_cache_disable : 1;
    std::uint32_t accessed : 1;
    std::uint32_t dirty : 1;
    std::uint32_t pat : 1;
    std::uint32_t global : 1;
    std::uint32_t ignored_1 : 3;
    std::uint32_t page_frame_number : 20;
  };

  std::uint32_t flags;
} pte_32_t;

typedef union {
  struct {
    std::uint32_t present : 1;
    std::uint32_t write : 1;
    std::uint32_t supervisor : 1;
    std::uint32_t page_level_write_through : 1;
    std::uint32_t page_level_cache_disable : 1;
    std::uint32_t accessed : 1;
    std::uint32_t dirty : 1;
    std::uint32_t large_page : 1;
    std::uint32_t global : 1;
    std::uint32_t ignored_1 : 3;
    std::uint32_t page_frame_number : 20;
  };

  std::uint32_t flags;
} pt_entry_32_t;

/**
 * @defgroup paging_structures_entry_count_32 \
 *           Paging structures entry counts
 * @{
 */
#define PDE_ENTRY_COUNT_32 0x00000400
#define PTE_ENTRY_COUNT_32 0x00000400

#define PAGE_SIZE 0x1000
#define PAGE_SIZE_2MB 0x200000
#define PAGE_SIZE_1GB 0x40000000

#define PAGE_SHIFT 12L
#define PAGE_SHIFT_2MB 21L
#define PAGE_SHIFT_1GB 30L

#define PAGE_MASK_4KB (PAGE_SIZE - 1)
#define PAGE_MASK_2MB (PAGE_SIZE_2MB - 1)
#define PAGE_MASK_1GB (PAGE_SIZE_1GB - 1)

/**
 * @}
 */

/**
 * @}
 */

/**
 * @defgroup paging_64 \
 *           64-Bit (4-Level) Paging
 * @{
 */
typedef union {
  struct {
    std::uint64_t present : 1;
    std::uint64_t write : 1;
    std::uint64_t supervisor : 1;
    std::uint64_t page_level_write_through : 1;
    std::uint64_t page_level_cache_disable : 1;
    std::uint64_t accessed : 1;
    std::uint64_t reserved_1 : 1;
    std::uint64_t must_be_zero : 1;
    std::uint64_t ignored_1 : 3;
    std::uint64_t restart : 1;
    std::uint64_t page_frame_number : 36;
    std::uint64_t reserved_2 : 4;
    std::uint64_t ignored_2 : 11;
    std::uint64_t execute_disable : 1;
  };

  std::uint64_t flags;
} pml4e_64_t;

typedef union {
  struct {
    std::uint64_t present : 1;
    std::uint64_t write : 1;
    std::uint64_t supervisor : 1;
    std::uint64_t page_level_write_through : 1;
    std::uint64_t page_level_cache_disable : 1;
    std::uint64_t accessed : 1;
    std::uint64_t dirty : 1;
    std::uint64_t large_page : 1;
    std::uint64_t global : 1;
    std::uint64_t ignored_1 : 2;
    std::uint64_t restart : 1;
    std::uint64_t pat : 1;
    std::uint64_t reserved_1 : 17;
    std::uint64_t page_frame_number : 18;
    std::uint64_t reserved_2 : 4;
    std::uint64_t ignored_2 : 7;
    std::uint64_t protection_key : 4;
    std::uint64_t execute_disable : 1;
  };

  std::uint64_t flags;
} pdpte_1gb_64_t;

typedef union {
  struct {
    std::uint64_t present : 1;
    std::uint64_t write : 1;
    std::uint64_t supervisor : 1;
    std::uint64_t page_level_write_through : 1;
    std::uint64_t page_level_cache_disable : 1;
    std::uint64_t accessed : 1;
    std::uint64_t reserved_1 : 1;
    std::uint64_t large_page : 1;
    std::uint64_t ignored_1 : 3;
    std::uint64_t restart : 1;
    std::uint64_t page_frame_number : 36;
    std::uint64_t reserved_2 : 4;
    std::uint64_t ignored_2 : 11;
    std::uint64_t execute_disable : 1;
  };

  std::uint64_t flags;
} pdpte_64_t;

typedef union {
  struct {
    std::uint64_t present : 1;
    std::uint64_t write : 1;
    std::uint64_t supervisor : 1;
    std::uint64_t page_level_write_through : 1;
    std::uint64_t page_level_cache_disable : 1;
    std::uint64_t accessed : 1;
    std::uint64_t dirty : 1;
    std::uint64_t large_page : 1;
    std::uint64_t global : 1;
    std::uint64_t ignored_1 : 2;
    std::uint64_t restart : 1;
    std::uint64_t pat : 1;
    std::uint64_t reserved_1 : 8;
    std::uint64_t page_frame_number : 27;
    std::uint64_t reserved_2 : 4;
    std::uint64_t ignored_2 : 7;
    std::uint64_t protection_key : 4;
    std::uint64_t execute_disable : 1;
  };

  std::uint64_t flags;
} pde_2mb_64_t;

typedef union {
  struct {
    std::uint64_t present : 1;
    std::uint64_t write : 1;
    std::uint64_t supervisor : 1;
    std::uint64_t page_level_write_through : 1;
    std::uint64_t page_level_cache_disable : 1;
    std::uint64_t accessed : 1;
    std::uint64_t reserved_1 : 1;
    std::uint64_t large_page : 1;
    std::uint64_t ignored_1 : 3;
    std::uint64_t restart : 1;
    std::uint64_t page_frame_number : 36;
    std::uint64_t reserved_2 : 4;
    std::uint64_t ignored_2 : 11;
    std::uint64_t execute_disable : 1;
  };

  std::uint64_t flags;
} pde_64_t;

typedef union {
  struct {
    std::uint64_t present : 1;
    std::uint64_t write : 1;
    std::uint64_t supervisor : 1;
    std::uint64_t page_level_write_through : 1;
    std::uint64_t page_level_cache_disable : 1;
    std::uint64_t accessed : 1;
    std::uint64_t dirty : 1;
    std::uint64_t pat : 1;
    std::uint64_t global : 1;
    std::uint64_t ignored_1 : 2;
    std::uint64_t restart : 1;
    std::uint64_t page_frame_number : 36;
    std::uint64_t reserved_1 : 4;
    std::uint64_t ignored_2 : 7;
    std::uint64_t protection_key : 4;
    std::uint64_t execute_disable : 1;
  };

  std::uint64_t flags;
} pte_64_t;

typedef union {
  struct {
    std::uint64_t present : 1;
    std::uint64_t write : 1;
    std::uint64_t supervisor : 1;
    std::uint64_t page_level_write_through : 1;
    std::uint64_t page_level_cache_disable : 1;
    std::uint64_t accessed : 1;
    std::uint64_t dirty : 1;
    std::uint64_t large_page : 1;
    std::uint64_t global : 1;
    std::uint64_t ignored_1 : 2;
    std::uint64_t restart : 1;
    std::uint64_t page_frame_number : 36;
    std::uint64_t reserved_1 : 4;
    std::uint64_t ignored_2 : 7;
    std::uint64_t protection_key : 4;
    std::uint64_t execute_disable : 1;
  };

  std::uint64_t flags;
} pt_entry_64_t;

/**
 * @defgroup paging_structures_entry_count_64 \
 *           Paging structures entry counts
 * @{
 */
#define PML4_ENTRY_COUNT_64 0x00000200
#define PDPTE_ENTRY_COUNT_64 0x00000200
#define PDE_ENTRY_COUNT_64 0x00000200
#define PTE_ENTRY_COUNT_64 0x00000200
/**
 * @}
 */

/**
 * @}
 */

/**
 * @}
 */

typedef enum {
  invpcid_individual_address = 0x00000000,
  invpcid_single_context = 0x00000001,
  invpcid_all_context_with_globals = 0x00000002,
  invpcid_all_context = 0x00000003,
} invpcid_type;

typedef union {
  struct {
    std::uint64_t pcid : 12;
    std::uint64_t reserved1 : 52;
    std::uint64_t linear_address : 64;
  };

  std::uint64_t flags;
} invpcid_descriptor;

/**
 * @defgroup segment_descriptors \
 *           Segment descriptors
 * @{
 */
#pragma pack(push, 1)
typedef struct {
  std::uint16_t limit;
  std::uint32_t base_address;
} segment_descriptor_register_32;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct {
  std::uint16_t limit;
  std::uint64_t base_address;
} segment_descriptor_register_64;
#pragma pack(pop)

typedef union {
  struct {
    std::uint32_t reserved_1 : 8;
    std::uint32_t type : 4;
    std::uint32_t descriptor_type : 1;
    std::uint32_t descriptor_privilege_level : 2;
    std::uint32_t present : 1;
    std::uint32_t reserved_2 : 4;
    std::uint32_t available_bit : 1;
    std::uint32_t long_mode : 1;
    std::uint32_t default_big : 1;
    std::uint32_t granularity : 1;
  };

  std::uint32_t flags;
} segment_access_rights;

typedef struct {
  std::uint16_t segment_limit_low;
  std::uint16_t base_address_low;
  union {
    struct {
      std::uint32_t base_address_middle : 8;
      std::uint32_t type : 4;
      std::uint32_t descriptor_type : 1;
      std::uint32_t descriptor_privilege_level : 2;
      std::uint32_t present : 1;
      std::uint32_t segment_limit_high : 4;
      std::uint32_t available_bit : 1;
      std::uint32_t long_mode : 1;
      std::uint32_t default_big : 1;
      std::uint32_t granularity : 1;
      std::uint32_t base_address_high : 8;
    };

    std::uint32_t flags;
  };

} segment_descriptor_32;

typedef struct {
  std::uint16_t segment_limit_low;
  std::uint16_t base_address_low;
  union {
    struct {
      std::uint32_t base_address_middle : 8;
      std::uint32_t type : 4;
      std::uint32_t descriptor_type : 1;
      std::uint32_t descriptor_privilege_level : 2;
      std::uint32_t present : 1;
      std::uint32_t segment_limit_high : 4;
      std::uint32_t available_bit : 1;
      std::uint32_t long_mode : 1;
      std::uint32_t default_big : 1;
      std::uint32_t granularity : 1;
      std::uint32_t base_address_high : 8;
    };

    std::uint32_t flags;
  };

  std::uint32_t base_address_upper;
  std::uint32_t must_be_zero;
} segment_descriptor_64;

typedef struct {
  std::uint16_t offset_low;
  std::uint16_t segment_selector;
  union {
    struct {
      std::uint32_t interrupt_stack_table : 3;
      std::uint32_t must_be_zero_0 : 5;
      std::uint32_t type : 4;
      std::uint32_t must_be_zero_1 : 1;
      std::uint32_t descriptor_privilege_level : 2;
      std::uint32_t present : 1;
      std::uint32_t offset_middle : 16;
    };

    std::uint32_t flags;
  };

  std::uint32_t offset_high;
  std::uint32_t reserved;
} segment_descriptor_interrupt_gate_64;

#define SEGMENT_DESCRIPTOR_TYPE_SYSTEM 0x00000000
#define SEGMENT_DESCRIPTOR_TYPE_CODE_OR_DATA 0x00000001
/**
 * @defgroup segment_descriptor_code_and_data_type \
 *           Code- and Data-Segment Descriptor Types
 * @{
 */
#define SEGMENT_DESCRIPTOR_TYPE_DATA_R 0x00000000
#define SEGMENT_DESCRIPTOR_TYPE_DATA_RA 0x00000001
#define SEGMENT_DESCRIPTOR_TYPE_DATA_RW 0x00000002
#define SEGMENT_DESCRIPTOR_TYPE_DATA_RWA 0x00000003
#define SEGMENT_DESCRIPTOR_TYPE_DATA_RE 0x00000004
#define SEGMENT_DESCRIPTOR_TYPE_DATA_REA 0x00000005
#define SEGMENT_DESCRIPTOR_TYPE_DATA_RWE 0x00000006
#define SEGMENT_DESCRIPTOR_TYPE_DATA_RWEA 0x00000007
#define SEGMENT_DESCRIPTOR_TYPE_CODE_E 0x00000008
#define SEGMENT_DESCRIPTOR_TYPE_CODE_EA 0x00000009
#define SEGMENT_DESCRIPTOR_TYPE_CODE_ER 0x0000000A
#define SEGMENT_DESCRIPTOR_TYPE_CODE_ERA 0x0000000B
#define SEGMENT_DESCRIPTOR_TYPE_CODE_EC 0x0000000C
#define SEGMENT_DESCRIPTOR_TYPE_CODE_ECA 0x0000000D
#define SEGMENT_DESCRIPTOR_TYPE_CODE_ERC 0x0000000E
#define SEGMENT_DESCRIPTOR_TYPE_CODE_ERCA 0x0000000F
/**
 * @}
 */

/**
 * @defgroup segment_descriptor_system_type \
 *           System Descriptor Types
 * @{
 */
#define SEGMENT_DESCRIPTOR_TYPE_RESERVED_1 0x00000000
#define SEGMENT_DESCRIPTOR_TYPE_TSS_16_AVAILABLE 0x00000001
#define SEGMENT_DESCRIPTOR_TYPE_LDT 0x00000002
#define SEGMENT_DESCRIPTOR_TYPE_TSS_16_BUSY 0x00000003
#define SEGMENT_DESCRIPTOR_TYPE_CALL_GATE_16 0x00000004
#define SEGMENT_DESCRIPTOR_TYPE_TASK_GATE 0x00000005
#define SEGMENT_DESCRIPTOR_TYPE_INTERRUPT_GATE_16 0x00000006
#define SEGMENT_DESCRIPTOR_TYPE_TRAP_GATE_16 0x00000007
#define SEGMENT_DESCRIPTOR_TYPE_RESERVED_2 0x00000008
#define SEGMENT_DESCRIPTOR_TYPE_TSS_AVAILABLE 0x00000009
#define SEGMENT_DESCRIPTOR_TYPE_RESERVED_3 0x0000000A
#define SEGMENT_DESCRIPTOR_TYPE_TSS_BUSY 0x0000000B
#define SEGMENT_DESCRIPTOR_TYPE_CALL_GATE 0x0000000C
#define SEGMENT_DESCRIPTOR_TYPE_RESERVED_4 0x0000000D
#define SEGMENT_DESCRIPTOR_TYPE_INTERRUPT_GATE 0x0000000E
#define SEGMENT_DESCRIPTOR_TYPE_TRAP_GATE 0x0000000F
/**
 * @}
 */

typedef union {
  struct {
    std::uint16_t request_privilege_level : 2;
    std::uint16_t table_indicator : 1;
    std::uint16_t index : 13;
  };

  std::uint16_t flags;
} segment_selector;

/**
 * @}
 */

#pragma pack(push, 1)
typedef struct {
  std::uint32_t reserved_0;
  std::uint64_t rsp0;
  std::uint64_t rsp1;
  std::uint64_t rsp2;
  std::uint64_t reserved_1;
  std::uint64_t ist1;
  std::uint64_t ist2;
  std::uint64_t ist3;
  std::uint64_t ist4;
  std::uint64_t ist5;
  std::uint64_t ist6;
  std::uint64_t ist7;
  std::uint64_t reserved_2;
  std::uint16_t reserved_3;
  std::uint16_t io_map_base;
} task_state_segment_64;
#pragma pack(pop)

/**
 * @defgroup vmx \
 *           VMX
 * @{
 */
/**
 * @{
 */
/**
 * @defgroup vmx_basic_exit_reasons \
 *           VMX Basic Exit Reasons
 * @{
 */
#define VMX_EXIT_REASON_XCPT_OR_NMI 0x00000000
#define VMX_EXIT_REASON_EXT_INT 0x00000001
#define VMX_EXIT_REASON_TRIPLE_FAULT 0x00000002
#define VMX_EXIT_REASON_INIT_SIGNAL 0x00000003
#define VMX_EXIT_REASON_SIPI 0x00000004
#define VMX_EXIT_REASON_IO_SMI 0x00000005
#define VMX_EXIT_REASON_SMI 0x00000006
#define VMX_EXIT_REASON_INT_WINDOW 0x00000007
#define VMX_EXIT_REASON_NMI_WINDOW 0x00000008
#define VMX_EXIT_REASON_TASK_SWITCH 0x00000009
#define VMX_EXIT_REASON_CPUID 0x0000000A
#define VMX_EXIT_REASON_GETSEC 0x0000000B
#define VMX_EXIT_REASON_HLT 0x0000000C
#define VMX_EXIT_REASON_INVD 0x0000000D
#define VMX_EXIT_REASON_INVLPG 0x0000000E
#define VMX_EXIT_REASON_RDPMC 0x0000000F
#define VMX_EXIT_REASON_RDTSC 0x00000010
#define VMX_EXIT_REASON_RSM 0x00000011
#define VMX_EXIT_REASON_VMCALL 0x00000012
#define VMX_EXIT_REASON_VMCLEAR 0x00000013
#define VMX_EXIT_REASON_VMLAUNCH 0x00000014
#define VMX_EXIT_REASON_VMPTRLD 0x00000015
#define VMX_EXIT_REASON_VMPTRST 0x00000016
#define VMX_EXIT_REASON_VMREAD 0x00000017
#define VMX_EXIT_REASON_VMRESUME 0x00000018
#define VMX_EXIT_REASON_VMWRITE 0x00000019
#define VMX_EXIT_REASON_VMXOFF 0x0000001A
#define VMX_EXIT_REASON_VMXON 0x0000001B
#define VMX_EXIT_REASON_MOV_CRX 0x0000001C
#define VMX_EXIT_REASON_MOV_DRX 0x0000001D
#define VMX_EXIT_REASON_IO_INSTR 0x0000001E
#define VMX_EXIT_REASON_RDMSR 0x0000001F
#define VMX_EXIT_REASON_WRMSR 0x00000020
#define VMX_EXIT_REASON_ERR_INVALID_GUEST_STATE 0x00000021
#define VMX_EXIT_REASON_ERR_MSR_LOAD 0x00000022
#define VMX_EXIT_REASON_MWAIT 0x00000024
#define VMX_EXIT_REASON_MTF 0x00000025
#define VMX_EXIT_REASON_MONITOR 0x00000027
#define VMX_EXIT_REASON_PAUSE 0x00000028
#define VMX_EXIT_REASON_ERR_MACHINE_CHECK 0x00000029
#define VMX_EXIT_REASON_TPR_BELOW_THRESHOLD 0x0000002B
#define VMX_EXIT_REASON_APIC_ACCESS 0x0000002C
#define VMX_EXIT_REASON_VIRTUALIZED_EOI 0x0000002D
#define VMX_EXIT_REASON_XDTR_ACCESS 0x0000002E
#define VMX_EXIT_REASON_TR_ACCESS 0x0000002F
#define VMX_EXIT_REASON_EPT_VIOLATION 0x00000030
#define VMX_EXIT_REASON_EPT_MISCONFIG 0x00000031
#define VMX_EXIT_REASON_INVEPT 0x00000032
#define VMX_EXIT_REASON_RDTSCP 0x00000033
#define VMX_EXIT_REASON_PREEMPT_TIMER 0x00000034
#define VMX_EXIT_REASON_INVVPID 0x00000035
#define VMX_EXIT_REASON_WBINVD 0x00000036
#define VMX_EXIT_REASON_XSETBV 0x00000037
#define VMX_EXIT_REASON_APIC_WRITE 0x00000038
#define VMX_EXIT_REASON_RDRAND 0x00000039
#define VMX_EXIT_REASON_INVPCID 0x0000003A
#define VMX_EXIT_REASON_VMFUNC 0x0000003B
#define VMX_EXIT_REASON_ENCLS 0x0000003C
#define VMX_EXIT_REASON_RDSEED 0x0000003D
#define VMX_EXIT_REASON_PML_FULL 0x0000003E
#define VMX_EXIT_REASON_XSAVES 0x0000003F
#define VMX_EXIT_REASON_XRSTORS 0x00000040
#define VMX_EXIT_REASON_PCONFIG 0x00000041
#define VMX_EXIT_REASON_SPP_EVENT 0x00000042
#define VMX_EXIT_REASON_UMWAIT 0x00000043
#define VMX_EXIT_REASON_TPAUSE 0x00000044
#define VMX_EXIT_REASON_LOADIWKEY 0x00000045
#define VMX_EXIT_REASON_ENCLV 0x00000046
#define VMX_EXIT_REASON_ENQCMD 0x00000048
#define VMX_EXIT_REASON_ENQCMDS 0x00000049
#define VMX_EXIT_REASON_BUS_LOCK 0x0000004A
#define VMX_EXIT_REASON_INSTRUCTION_TIMEOUT 0x0000004B
#define VMX_EXIT_REASON_SEAMCALL 0x0000004C
#define VMX_EXIT_REASON_TDCALL 0x0000004D
#define VMX_EXIT_REASON_RDMSRLIST 0x0000004E
#define VMX_EXIT_REASON_WRMSRLIST 0x0000004F
/**
 * @}
 */

/**
 * @defgroup vmx_instruction_error_numbers \
 *           VM-Instruction Error Numbers
 * @{
 */
#define VMX_ERROR_VMCALL 0x00000001
#define VMX_ERROR_VMCLEAR_INVALID_PHYS_ADDR 0x00000002
#define VMX_ERROR_VMCLEAR_INVALID_VMXON_PTR 0x00000003
#define VMX_ERROR_VMLAUCH_NON_CLEAR_VMCS 0x00000004
#define VMX_ERROR_VMRESUME_NON_LAUNCHED_VMCS 0x00000005
#define VMX_ERROR_VMRESUME_CORRUPTED_VMCS 0x00000006
#define VMX_ERROR_VMENTRY_INVALID_CONTROL_FIELDS 0x00000007
#define VMX_ERROR_VMENTRY_INVALID_HOST_STATE 0x00000008
#define VMX_ERROR_VMPTRLD_INVALID_PHYS_ADDR 0x00000009
#define VMX_ERROR_VMPTRLD_VMXON_PTR 0x0000000A
#define VMX_ERROR_VMPTRLD_WRONG_VMCS_REVISION 0x0000000B
#define VMX_ERROR_VMREAD_VMWRITE_INVALID_COMPONENT 0x0000000C
#define VMX_ERROR_VMWRITE_READONLY_COMPONENT 0x0000000D
#define VMX_ERROR_VMXON_IN_VMX_ROOT_OP 0x0000000F
#define VMX_ERROR_VMENTRY_INVALID_VMCS_EXEC_PTR 0x00000010
#define VMX_ERROR_VMENTRY_NON_LAUNCHED_EXEC_VMCS 0x00000011
#define VMX_ERROR_VMENTRY_EXEC_VMCS_PTR 0x00000012
#define VMX_ERROR_VMCALL_NON_CLEAR_VMCS 0x00000013
#define VMX_ERROR_VMCALL_INVALID_VMEXIT_FIELDS 0x00000014
#define VMX_ERROR_VMCALL_INVALID_MSEG_REVISION 0x00000016
#define VMX_ERROR_VMXOFF_DUAL_MONITOR 0x00000017
#define VMX_ERROR_VMCALL_INVALID_SMM_MONITOR 0x00000018
#define VMX_ERROR_VMENTRY_INVALID_VM_EXEC_CTRL 0x00000019
#define VMX_ERROR_VMENTRY_MOV_SS 0x0000001A
#define VMX_ERROR_INVEPTVPID_INVALID_OPERAND 0x0000001C
/**
 * @}
 */

/**
 * @defgroup vmx_exceptions \
 *           Virtualization Exceptions
 * @{
 */
typedef struct {
  std::uint32_t reason;
  std::uint32_t exception_mask;
  std::uint64_t exit;
  std::uint64_t guest_linear_address;
  std::uint64_t guest_physical_address;
  std::uint16_t current_eptp_index;
} vmx_ve_except_info;

/**
 * @}
 */

/**
 * @defgroup vmx_basic_exit_information \
 *           Basic VM-Exit Information
 * @{
 */
typedef union {
  struct {
    std::uint64_t breakpoint_condition : 4;
    std::uint64_t reserved_1 : 9;
    std::uint64_t debug_register_access_detected : 1;
    std::uint64_t single_instruction : 1;
  };

  std::uint64_t flags;
} vmx_exit_qualification_debug_exception;

typedef union {
  struct {
    std::uint64_t selector : 16;
    std::uint64_t reserved_1 : 14;
    std::uint64_t type : 2;
#define VMX_EXIT_QUALIFICATION_TYPE_CALL 0x00000000
#define VMX_EXIT_QUALIFICATION_TYPE_IRET 0x00000001
#define VMX_EXIT_QUALIFICATION_TYPE_JMP 0x00000002
#define VMX_EXIT_QUALIFICATION_TYPE_IDT 0x00000003
  };

  std::uint64_t flags;
} vmx_exit_qualification_task_switch;

typedef union {
  struct {
    std::uint64_t cr_number : 4;
#define VMX_EXIT_QUALIFICATION_REGISTER_CR0 0x00000000
#define VMX_EXIT_QUALIFICATION_REGISTER_CR2 0x00000002
#define VMX_EXIT_QUALIFICATION_REGISTER_CR3 0x00000003
#define VMX_EXIT_QUALIFICATION_REGISTER_CR4 0x00000004
#define VMX_EXIT_QUALIFICATION_REGISTER_CR8 0x00000008
    std::uint64_t access_type : 2;
#define VMX_EXIT_QUALIFICATION_ACCESS_MOV_TO_CR 0x00000000
#define VMX_EXIT_QUALIFICATION_ACCESS_MOV_FROM_CR 0x00000001
#define VMX_EXIT_QUALIFICATION_ACCESS_CLTS 0x00000002
#define VMX_EXIT_QUALIFICATION_ACCESS_LMSW 0x00000003
    std::uint64_t lmsw_operand_type : 1;
#define VMX_EXIT_QUALIFICATION_LMSW_OP_REGISTER 0x00000000
#define VMX_EXIT_QUALIFICATION_LMSW_OP_MEMORY 0x00000001
    std::uint64_t reserved_1 : 1;
    std::uint64_t gp_register : 4;
#define VMX_EXIT_QUALIFICATION_GENREG_RAX 0x00000000
#define VMX_EXIT_QUALIFICATION_GENREG_RCX 0x00000001
#define VMX_EXIT_QUALIFICATION_GENREG_RDX 0x00000002
#define VMX_EXIT_QUALIFICATION_GENREG_RBX 0x00000003
#define VMX_EXIT_QUALIFICATION_GENREG_RSP 0x00000004
#define VMX_EXIT_QUALIFICATION_GENREG_RBP 0x00000005
#define VMX_EXIT_QUALIFICATION_GENREG_RSI 0x00000006
#define VMX_EXIT_QUALIFICATION_GENREG_RDI 0x00000007
#define VMX_EXIT_QUALIFICATION_GENREG_R8 0x00000008
#define VMX_EXIT_QUALIFICATION_GENREG_R9 0x00000009
#define VMX_EXIT_QUALIFICATION_GENREG_R10 0x0000000A
#define VMX_EXIT_QUALIFICATION_GENREG_R11 0x0000000B
#define VMX_EXIT_QUALIFICATION_GENREG_R12 0x0000000C
#define VMX_EXIT_QUALIFICATION_GENREG_R13 0x0000000D
#define VMX_EXIT_QUALIFICATION_GENREG_R14 0x0000000E
#define VMX_EXIT_QUALIFICATION_GENREG_R15 0x0000000F
    std::uint64_t reserved_2 : 4;
    std::uint64_t lmsw_source_data : 16;
  };

  std::uint64_t flags;
} vmx_exit_qualification_cr_access;

typedef union {
  struct {
    std::uint64_t dr_number : 3;
#define VMX_EXIT_QUALIFICATION_REGISTER_DR0 0x00000000
#define VMX_EXIT_QUALIFICATION_REGISTER_DR1 0x00000001
#define VMX_EXIT_QUALIFICATION_REGISTER_DR2 0x00000002
#define VMX_EXIT_QUALIFICATION_REGISTER_DR3 0x00000003
#define VMX_EXIT_QUALIFICATION_REGISTER_DR6 0x00000006
#define VMX_EXIT_QUALIFICATION_REGISTER_DR7 0x00000007
    std::uint64_t reserved_1 : 1;
    std::uint64_t direction_of_access : 1;
#define VMX_EXIT_QUALIFICATION_DIRECTION_MOV_TO_DR 0x00000000
#define VMX_EXIT_QUALIFICATION_DIRECTION_MOV_FROM_DR 0x00000001
    std::uint64_t reserved_2 : 3;
    std::uint64_t gp_register : 4;
  };

  std::uint64_t flags;
} vmx_exit_qualification_dr_access;

typedef union {
  struct {
    std::uint64_t size_of_access : 3;
#define VMX_EXIT_QUALIFICATION_WIDTH_1B 0x00000000
#define VMX_EXIT_QUALIFICATION_WIDTH_2B 0x00000001
#define VMX_EXIT_QUALIFICATION_WIDTH_4B 0x00000003
    std::uint64_t direction_of_access : 1;
#define VMX_EXIT_QUALIFICATION_DIRECTION_OUT 0x00000000
#define VMX_EXIT_QUALIFICATION_DIRECTION_IN 0x00000001
    std::uint64_t string_instruction : 1;
#define VMX_EXIT_QUALIFICATION_IS_STRING_NOT_STRING 0x00000000
#define VMX_EXIT_QUALIFICATION_IS_STRING_STRING 0x00000001
    std::uint64_t rep_prefixed : 1;
#define VMX_EXIT_QUALIFICATION_IS_REP_NOT_REP 0x00000000
#define VMX_EXIT_QUALIFICATION_IS_REP_REP 0x00000001
    std::uint64_t operand_encoding : 1;
#define VMX_EXIT_QUALIFICATION_ENCODING_DX 0x00000000
#define VMX_EXIT_QUALIFICATION_ENCODING_IMM 0x00000001
    std::uint64_t reserved_1 : 9;
    std::uint64_t port_number : 16;
  };

  std::uint64_t flags;
} vmx_exit_qualification_io_inst;

typedef union {
  struct {
    std::uint64_t page_offset : 12;
    std::uint64_t access_type : 4;
#define VMX_EXIT_QUALIFICATION_TYPE_LINEAR_READ 0x00000000
#define VMX_EXIT_QUALIFICATION_TYPE_LINEAR_WRITE 0x00000001
#define VMX_EXIT_QUALIFICATION_TYPE_LINEAR_INSTR_FETCH 0x00000002
#define VMX_EXIT_QUALIFICATION_TYPE_LINEAR_EVENT_DELIVERY 0x00000003
#define VMX_EXIT_QUALIFICATION_TYPE_PHYSICAL_EVENT_DELIVERY 0x0000000A
#define VMX_EXIT_QUALIFICATION_TYPE_PHYSICAL_INSTR 0x0000000F
  };

  std::uint64_t flags;
} vmx_exit_qualification_apic_access;

typedef union {
  struct {
    std::uint64_t data_read : 1;
    std::uint64_t data_write : 1;
    std::uint64_t instruction_fetch : 1;
    std::uint64_t entry_present : 1;
    std::uint64_t entry_write : 1;
    std::uint64_t entry_execute : 1;
    std::uint64_t entry_execute_for_user_mode : 1;
    std::uint64_t valid_guest_linear_address : 1;
    std::uint64_t ept_translated_access : 1;
    std::uint64_t user_mode_linear_address : 1;
    std::uint64_t readable_writable_page : 1;
    std::uint64_t execute_disable_page : 1;
    std::uint64_t nmi_unblocking : 1;
    std::uint64_t shadow_stack_access : 1;
    std::uint64_t supervisor_shadow_stack : 1;
    std::uint64_t guest_paging_verification : 1;
    std::uint64_t asynchronous_to_instruction : 1;
  };

  std::uint64_t flags;
} vmx_exit_qualification_ept_violation;

/**
 * @}
 */

/**
 * @defgroup vmx_vmexit_instruction_information \
 *           Information for VM Exits Due to Instruction Execution
 * @{
 */
typedef union {
  struct {
    std::uint64_t reserved_1 : 7;
    std::uint64_t address_size : 3;
    std::uint64_t reserved_2 : 5;
    std::uint64_t segment_register : 3;
  };

  std::uint64_t flags;
} vmx_vmexit_instruction_info_ins_outs;

typedef union {
  struct {
    std::uint64_t scaling : 2;
    std::uint64_t reserved_1 : 5;
    std::uint64_t address_size : 3;
    std::uint64_t reserved_2 : 5;
    std::uint64_t segment_register : 3;
    std::uint64_t gp_register : 4;
    std::uint64_t gp_register_invalid : 1;
    std::uint64_t base_register : 4;
    std::uint64_t base_register_invalid : 1;
    std::uint64_t register_2 : 4;
  };

  std::uint64_t flags;
} vmx_vmexit_instruction_info_invalidate;

typedef union {
  struct {
    std::uint64_t scaling : 2;
    std::uint64_t reserved_1 : 5;
    std::uint64_t address_size : 3;
    std::uint64_t reserved_2 : 1;
    std::uint64_t operand_size : 1;
    std::uint64_t reserved_3 : 3;
    std::uint64_t segment_register : 3;
    std::uint64_t gp_register : 4;
    std::uint64_t gp_register_invalid : 1;
    std::uint64_t base_register : 4;
    std::uint64_t base_register_invalid : 1;
    std::uint64_t instruction_identity : 2;
  };

  std::uint64_t flags;
} vmx_vmexit_instruction_info_gdtr_idtr_access;

typedef union {
  struct {
    std::uint64_t scaling : 2;
    std::uint64_t reserved_1 : 1;
    std::uint64_t reg_1 : 4;
    std::uint64_t address_size : 3;
    std::uint64_t memory_register : 1;
    std::uint64_t reserved_2 : 4;
    std::uint64_t segment_register : 3;
    std::uint64_t gp_register : 4;
    std::uint64_t gp_register_invalid : 1;
    std::uint64_t base_register : 4;
    std::uint64_t base_register_invalid : 1;
    std::uint64_t instruction_identity : 2;
  };

  std::uint64_t flags;
} vmx_vmexit_instruction_info_ldtr_tr_access;

typedef union {
  struct {
    std::uint64_t reserved_1 : 3;
    std::uint64_t destination_register : 4;
    std::uint64_t reserved_2 : 4;
    std::uint64_t operand_size : 2;
  };

  std::uint64_t flags;
} vmx_vmexit_instruction_info_rdrand_rdseed;

typedef union {
  struct {
    std::uint64_t scaling : 2;
    std::uint64_t reserved_1 : 5;
    std::uint64_t address_size : 3;
    std::uint64_t reserved_2 : 5;
    std::uint64_t segment_register : 3;
    std::uint64_t gp_register : 4;
    std::uint64_t gp_register_invalid : 1;
    std::uint64_t base_register : 4;
    std::uint64_t base_register_invalid : 1;
  };

  std::uint64_t flags;
} vmx_vmexit_instruction_info_vmx_and_xsaves;

typedef union {
  struct {
    std::uint64_t scaling : 2;
    std::uint64_t reserved_1 : 1;
    std::uint64_t register_1 : 4;
    std::uint64_t address_size : 3;
    std::uint64_t memory_register : 1;
    std::uint64_t reserved_2 : 4;
    std::uint64_t segment_register : 3;
    std::uint64_t gp_register : 4;
    std::uint64_t gp_register_invalid : 1;
    std::uint64_t base_register : 4;
    std::uint64_t base_register_invalid : 1;
    std::uint64_t register_2 : 4;
  };

  std::uint64_t flags;
} vmx_vmexit_instruction_info_vmread_vmwrite;

/**
 * @}
 */

typedef union {
  struct {
    std::uint32_t type : 4;
    std::uint32_t descriptor_type : 1;
    std::uint32_t descriptor_privilege_level : 2;
    std::uint32_t present : 1;
    std::uint32_t reserved_1 : 4;
    std::uint32_t available_bit : 1;
    std::uint32_t long_mode : 1;
    std::uint32_t default_big : 1;
    std::uint32_t granularity : 1;
    std::uint32_t unusable : 1;
  };

  std::uint32_t flags;
} vmx_segment_access_rights;

typedef union {
  struct {
    std::uint32_t blocking_by_sti : 1;
    std::uint32_t blocking_by_mov_ss : 1;
    std::uint32_t blocking_by_smi : 1;
    std::uint32_t blocking_by_nmi : 1;
    std::uint32_t enclave_interruption : 1;
  };

  std::uint32_t flags;
} vmx_interruptibility_state;

typedef enum {
  vmx_active = 0x00000000,
  vmx_hlt = 0x00000001,
  vmx_shutdown = 0x00000002,
  vmx_wait_for_sipi = 0x00000003,
} vmx_guest_activity_state;

typedef union {
  struct {
    std::uint64_t b0 : 1;
    std::uint64_t b1 : 1;
    std::uint64_t b2 : 1;
    std::uint64_t b3 : 1;
    std::uint64_t reserved_1 : 8;
    std::uint64_t enabled_breakpoint : 1;
    std::uint64_t reserved_2 : 1;
    std::uint64_t bs : 1;
    std::uint64_t reserved_3 : 1;
    std::uint64_t rtm : 1;
  };

  std::uint64_t flags;
} vmx_pending_debug_exceptions;

/**
 * @}
 */

typedef union {
  struct {
    std::uint32_t basic_exit_reason : 16;
    std::uint32_t always0 : 1;
    std::uint32_t reserved1 : 10;
    std::uint32_t enclave_mode : 1;
    std::uint32_t pending_mtf_vm_exit : 1;
    std::uint32_t vm_exit_from_vmx_root : 1;
    std::uint32_t reserved2 : 1;
    std::uint32_t vm_entry_failure : 1;
  };

  std::uint32_t flags;
} vmx_vmexit_reason;

/**
 * @defgroup ept \
 *           The extended page-table mechanism
 * @{
 */
typedef union {
  struct {
    std::uint64_t memory_type : 3;
    std::uint64_t page_walk_length : 3;
#define EPT_PAGE_WALK_LENGTH_4 0x00000003
    std::uint64_t enable_access_and_dirty_flags : 1;
    std::uint64_t enable_supervisor_shadow_stack_pages : 1;
    std::uint64_t reserved_1 : 4;
    std::uint64_t page_frame_number : 36;
  };

  std::uint64_t flags;
} eptp;

typedef union {
  struct {
    std::uint64_t read_access : 1;
    std::uint64_t write_access : 1;
    std::uint64_t execute_access : 1;
    std::uint64_t reserved_1 : 5;
    std::uint64_t accessed : 1;
    std::uint64_t reserved_2 : 1;
    std::uint64_t user_mode_execute : 1;
    std::uint64_t reserved_3 : 1;
    std::uint64_t page_frame_number : 36;
  };

  std::uint64_t flags;
} epml4e;

typedef union {
  struct {
    std::uint64_t read_access : 1;
    std::uint64_t write_access : 1;
    std::uint64_t execute_access : 1;
    std::uint64_t memory_type : 3;
    std::uint64_t ignore_pat : 1;
    std::uint64_t large_page : 1;
    std::uint64_t accessed : 1;
    std::uint64_t dirty : 1;
    std::uint64_t user_mode_execute : 1;
    std::uint64_t reserved_1 : 19;
    std::uint64_t page_frame_number : 18;
    std::uint64_t reserved_2 : 9;
    std::uint64_t verify_guest_paging : 1;
    std::uint64_t paging_write_access : 1;
    std::uint64_t reserved_3 : 1;
    std::uint64_t supervisor_shadow_stack : 1;
    std::uint64_t reserved_4 : 2;
    std::uint64_t suppress_ve : 1;
  };

  std::uint64_t flags;
} epdpte_1gb;

typedef union {
  struct {
    std::uint64_t read_access : 1;
    std::uint64_t write_access : 1;
    std::uint64_t execute_access : 1;
    std::uint64_t reserved_1 : 5;
    std::uint64_t accessed : 1;
    std::uint64_t reserved_2 : 1;
    std::uint64_t user_mode_execute : 1;
    std::uint64_t reserved_3 : 1;
    std::uint64_t page_frame_number : 36;
  };

  std::uint64_t flags;
} epdpte;

typedef union {
  struct {
    std::uint64_t read_access : 1;
    std::uint64_t write_access : 1;
    std::uint64_t execute_access : 1;
    std::uint64_t memory_type : 3;
    std::uint64_t ignore_pat : 1;
    std::uint64_t large_page : 1;
    std::uint64_t accessed : 1;
    std::uint64_t dirty : 1;
    std::uint64_t user_mode_execute : 1;
    std::uint64_t reserved_1 : 10;
    std::uint64_t page_frame_number : 27;
    std::uint64_t reserved_2 : 9;
    std::uint64_t verify_guest_paging : 1;
    std::uint64_t paging_write_access : 1;
    std::uint64_t reserved_3 : 1;
    std::uint64_t supervisor_shadow_stack : 1;
    std::uint64_t reserved_4 : 2;
    std::uint64_t suppress_ve : 1;
  };

  std::uint64_t flags;
} epde_2mb;

typedef union {
  struct {
    std::uint64_t read_access : 1;
    std::uint64_t write_access : 1;
    std::uint64_t execute_access : 1;
    std::uint64_t reserved_1 : 5;
    std::uint64_t accessed : 1;
    std::uint64_t reserved_2 : 1;
    std::uint64_t user_mode_execute : 1;
    std::uint64_t reserved_3 : 1;
    std::uint64_t page_frame_number : 36;
  };

  std::uint64_t flags;
} epde;

typedef union {
  struct {
    std::uint64_t read_access : 1;
    std::uint64_t write_access : 1;
    std::uint64_t execute_access : 1;
    std::uint64_t memory_type : 3;
    std::uint64_t ignore_pat : 1;
    std::uint64_t reserved_1 : 1;
    std::uint64_t accessed : 1;
    std::uint64_t dirty : 1;
    std::uint64_t user_mode_execute : 1;
    std::uint64_t reserved_2 : 1;
    std::uint64_t page_frame_number : 36;
    std::uint64_t reserved_3 : 9;
    std::uint64_t verify_guest_paging : 1;
    std::uint64_t paging_write_access : 1;
    std::uint64_t reserved_4 : 1;
    std::uint64_t supervisor_shadow_stack : 1;
    std::uint64_t sub_page_write_permissions : 1;
    std::uint64_t reserved_5 : 1;
    std::uint64_t suppress_ve : 1;
  };

  std::uint64_t flags;
} epte;

typedef union {
  struct {
    std::uint64_t read_access : 1;
    std::uint64_t write_access : 1;
    std::uint64_t execute_access : 1;
    std::uint64_t memory_type : 3;
    std::uint64_t ignore_pat : 1;
    std::uint64_t large_page : 1;
    std::uint64_t accessed : 1;
    std::uint64_t dirty : 1;
    std::uint64_t user_mode_execute : 1;
    std::uint64_t reserved_1 : 1;
    std::uint64_t page_frame_number : 36;
    std::uint64_t reserved_2 : 15;
    std::uint64_t suppress_ve : 1;
  };

  std::uint64_t flags;
} ept_entry;

/**
 * @defgroup ept_table_level \
 *           EPT Table level numbers
 * @{
 */
#define EPT_LEVEL_PML4E 0x00000003
#define EPT_LEVEL_PDPTE 0x00000002
#define EPT_LEVEL_PDE 0x00000001
#define EPT_LEVEL_PTE 0x00000000
/**
 * @}
 */

/**
 * @defgroup ept_entry_count \
 *           EPT Entry counts
 * @{
 */
#define EPML4_ENTRY_COUNT 0x00000200
#define EPDPTE_ENTRY_COUNT 0x00000200
#define EPDE_ENTRY_COUNT 0x00000200
#define EPTE_ENTRY_COUNT 0x00000200
/**
 * @}
 */

/**
 * @}
 */

typedef enum {
  invept_single_context = 0x00000001,
  invept_all_context = 0x00000002,
} invept_type;

typedef enum {
  invvpid_individual_address = 0x00000000,
  invvpid_single_context = 0x00000001,
  invvpid_all_context = 0x00000002,
  invvpid_single_context_retaining_globals = 0x00000003,
} invvpid_type;

typedef struct {
  std::uint64_t ept_pointer;
  std::uint64_t reserved;
} invept_descriptor;

typedef struct {
  std::uint16_t vpid;
  std::uint16_t reserved1;
  std::uint32_t reserved2;
  std::uint64_t linear_address;
} invvpid_descriptor;

typedef union {
  struct {
    std::uint64_t reserved_1 : 3;
    std::uint64_t page_level_write_through : 1;
    std::uint64_t page_level_cache_disable : 1;
    std::uint64_t reserved_2 : 7;
    std::uint64_t page_frame_number : 36;
  };

  std::uint64_t flags;
} hlatp;

typedef struct {
  struct {
    std::uint32_t revision_id : 31;
    std::uint32_t shadow_vmcs_indicator : 1;
  };

  std::uint32_t abort_indicator;
  std::uint8_t data[4088];
} vmcs;

typedef struct {
  struct {
    std::uint32_t revision_id : 31;
    std::uint32_t must_be_zero : 1;
  };

  std::uint8_t data[4092];
} vmxon;

/**
 * @defgroup vmcs_fields \
 *           VMCS (VM Control Structure)
 * @{
 */
typedef union {
  struct {
    std::uint16_t access_type : 1;
    std::uint16_t index : 9;
    std::uint16_t type : 2;
    std::uint16_t must_be_zero : 1;
    std::uint16_t width : 2;
  };

  std::uint16_t flags;
} vmcs_component_encoding;

/**
 * @defgroup vmcs_16_bit \
 *           16-Bit Fields
 * @{
 */
/**
 * @defgroup vmcs_16_bit_control_fields \
 *           16-Bit Control Fields
 * @{
 */
#define VMCS_CTRL_VPID 0x00000000
#define VMCS_CTRL_POSTED_INTR_NOTIFY_VECTOR 0x00000002
#define VMCS_CTRL_EPTP_INDEX 0x00000004
#define VMCS_CTRL_HLAT_PREFIX_SIZE 0x00000006
#define VMCS_CTRL_LAST_PID_PTR_INDEX 0x00000008
/**
 * @}
 */

/**
 * @defgroup vmcs_16_bit_guest_state_fields \
 *           16-Bit Guest-State Fields
 * @{
 */
#define VMCS_GUEST_ES_SEL 0x00000800
#define VMCS_GUEST_CS_SEL 0x00000802
#define VMCS_GUEST_SS_SEL 0x00000804
#define VMCS_GUEST_DS_SEL 0x00000806
#define VMCS_GUEST_FS_SEL 0x00000808
#define VMCS_GUEST_GS_SEL 0x0000080A
#define VMCS_GUEST_LDTR_SEL 0x0000080C
#define VMCS_GUEST_TR_SEL 0x0000080E
#define VMCS_GUEST_INTR_STATUS 0x00000810
#define VMCS_GUEST_PML_INDEX 0x00000812
#define VMCS_GUEST_UINV 0x00000814
/**
 * @}
 */

/**
 * @defgroup vmcs_16_bit_host_state_fields \
 *           16-Bit Host-State Fields
 * @{
 */
#define VMCS_HOST_ES_SEL 0x00000C00
#define VMCS_HOST_CS_SEL 0x00000C02
#define VMCS_HOST_SS_SEL 0x00000C04
#define VMCS_HOST_DS_SEL 0x00000C06
#define VMCS_HOST_FS_SEL 0x00000C08
#define VMCS_HOST_GS_SEL 0x00000C0A
#define VMCS_HOST_TR_SEL 0x00000C0C
/**
 * @}
 */

/**
 * @}
 */

/**
 * @defgroup vmcs_64_bit \
 *           64-Bit Fields
 * @{
 */
/**
 * @defgroup vmcs_64_bit_control_fields \
 *           64-Bit Control Fields
 * @{
 */
#define VMCS_CTRL_IO_BITMAP_A 0x00002000
#define VMCS_CTRL_IO_BITMAP_B 0x00002002
#define VMCS_CTRL_MSR_BITMAP 0x00002004
#define VMCS_CTRL_VMEXIT_MSR_STORE 0x00002006
#define VMCS_CTRL_VMEXIT_MSR_LOAD 0x00002008
#define VMCS_CTRL_VMENTRY_MSR_LOAD 0x0000200A
#define VMCS_CTRL_EXEC_VMCS_PTR 0x0000200C
#define VMCS_CTRL_PML_ADDR 0x0000200E
#define VMCS_CTRL_TSC_OFFSET 0x00002010
#define VMCS_CTRL_VAPIC_PAGEADDR 0x00002012
#define VMCS_CTRL_APIC_ACCESSADDR 0x00002014
#define VMCS_CTRL_POSTED_INTR_DESC 0x00002016
#define VMCS_CTRL_VMFUNC_CTRLS 0x00002018
#define VMCS_CTRL_EPTP 0x0000201A
#define VMCS_CTRL_EOI_BITMAP_0 0x0000201C
#define VMCS_CTRL_EOI_BITMAP_1 0x0000201E
#define VMCS_CTRL_EOI_BITMAP_2 0x00002020
#define VMCS_CTRL_EOI_BITMAP_3 0x00002022
#define VMCS_CTRL_EPTP_LIST 0x00002024
#define VMCS_CTRL_VMREAD_BITMAP 0x00002026
#define VMCS_CTRL_VMWRITE_BITMAP 0x00002028
#define VMCS_CTRL_VIRTXCPT_INFO_ADDR 0x0000202A
#define VMCS_CTRL_XSS_EXITING_BITMAP 0x0000202C
#define VMCS_CTRL_ENCLS_EXITING_BITMAP 0x0000202E
#define VMCS_CTRL_SPP_TABLE_POINTER 0x00002030
#define VMCS_CTRL_TSC_MULTIPLIER 0x00002032
#define VMCS_CTRL_PROC_EXEC3 0x00002034
#define VMCS_CTRL_ENCLV_EXITING_BITMAP 0x00002036
#define VMCS_CTRL_LOW_PASID_DIR_ADDR 0x00002038
#define VMCS_CTRL_HIGH_PASID_DIR_ADDR 0x0000203A
#define VMCS_CTRL_SHARED_EPTP 0x0000203C
#define VMCS_CTRL_PCONFIG_BITMAP 0x0000203E
#define VMCS_CTRL_HLATP 0x00002040
#define VMCS_CTRL_PID_PTR_TABLE 0x00002042
#define VMCS_CTRL_SECONDARY_EXIT 0x00002044
#define VMCS_CTRL_SPEC_CTRL_MASK 0x0000204A
#define VMCS_CTRL_SPEC_CTRL_SHADOW 0x0000204C
/**
 * @}
 */

/**
 * @defgroup vmcs_64_bit_read_only_data_fields \
 *           64-Bit Read-Only Data Field
 * @{
 */
#define VMCS_GUEST_PHYS_ADDR 0x00002400
/**
 * @}
 */

/**
 * @defgroup vmcs_64_bit_guest_state_fields \
 *           64-Bit Guest-State Fields
 * @{
 */
#define VMCS_GUEST_VMCS_LINK_PTR 0x00002800
#define VMCS_GUEST_DEBUGCTL 0x00002802
#define VMCS_GUEST_PAT 0x00002804
#define VMCS_GUEST_EFER 0x00002806
#define VMCS_GUEST_PERF_GLOBAL_CTRL 0x00002808
#define VMCS_GUEST_PDPTE0 0x0000280A
#define VMCS_GUEST_PDPTE1 0x0000280C
#define VMCS_GUEST_PDPTE2 0x0000280E
#define VMCS_GUEST_PDPTE3 0x00002810
#define VMCS_GUEST_BNDCFGS 0x00002812
#define VMCS_GUEST_RTIT_CTL 0x00002814
#define VMCS_GUEST_LBR_CTL 0x00002816
#define VMCS_GUEST_PKRS 0x00002818
/**
 * @}
 */

/**
 * @defgroup vmcs_64_bit_host_state_fields \
 *           64-Bit Host-State Fields
 * @{
 */
#define VMCS_HOST_PAT 0x00002C00
#define VMCS_HOST_EFER 0x00002C02
#define VMCS_HOST_PERF_GLOBAL_CTRL 0x00002C04
#define VMCS_HOST_PKRS 0x00002C06
/**
 * @}
 */

/**
 * @}
 */

/**
 * @defgroup vmcs_32_bit \
 *           32-Bit Fields
 * @{
 */
/**
 * @defgroup vmcs_32_bit_control_fields \
 *           32-Bit Control Fields
 * @{
 */
#define VMCS_CTRL_PIN_EXEC 0x00004000
#define VMCS_CTRL_PROC_EXEC 0x00004002
#define VMCS_CTRL_EXCEPTION_BITMAP 0x00004004
#define VMCS_CTRL_PAGEFAULT_ERROR_MASK 0x00004006
#define VMCS_CTRL_PAGEFAULT_ERROR_MATCH 0x00004008
#define VMCS_CTRL_CR3_TARGET_COUNT 0x0000400A
#define VMCS_CTRL_PRIMARY_EXIT 0x0000400C
#define VMCS_CTRL_EXIT_MSR_STORE_COUNT 0x0000400E
#define VMCS_CTRL_EXIT_MSR_LOAD_COUNT 0x00004010
#define VMCS_CTRL_ENTRY 0x00004012
#define VMCS_CTRL_ENTRY_MSR_LOAD_COUNT 0x00004014
#define VMCS_CTRL_ENTRY_INTERRUPTION_INFO 0x00004016
#define VMCS_CTRL_ENTRY_EXCEPTION_ERRCODE 0x00004018
#define VMCS_CTRL_ENTRY_INSTR_LENGTH 0x0000401A
#define VMCS_CTRL_TPR_THRESHOLD 0x0000401C
#define VMCS_CTRL_PROC_EXEC2 0x0000401E
#define VMCS_CTRL_PLE_GAP 0x00004020
#define VMCS_CTRL_PLE_WINDOW 0x00004022
/**
 * @}
 */

/**
 * @defgroup vmcs_32_bit_read_only_data_fields \
 *           32-Bit Read-Only Data Fields
 * @{
 */
#define VMCS_VM_INSTR_ERROR 0x00004400
#define VMCS_EXIT_REASON 0x00004402
#define VMCS_EXIT_INTERRUPTION_INFO 0x00004404
#define VMCS_EXIT_INTERRUPTION_ERROR_CODE 0x00004406
#define VMCS_IDT_VECTORING_INFO 0x00004408
#define VMCS_IDT_VECTORING_ERROR_CODE 0x0000440A
#define VMCS_EXIT_INSTR_LENGTH 0x0000440C
#define VMCS_EXIT_INSTR_INFO 0x0000440E
/**
 * @}
 */

/**
 * @defgroup vmcs_32_bit_guest_state_fields \
 *           32-Bit Guest-State Fields
 * @{
 */
#define VMCS_GUEST_ES_LIMIT 0x00004800
#define VMCS_GUEST_CS_LIMIT 0x00004802
#define VMCS_GUEST_SS_LIMIT 0x00004804
#define VMCS_GUEST_DS_LIMIT 0x00004806
#define VMCS_GUEST_FS_LIMIT 0x00004808
#define VMCS_GUEST_GS_LIMIT 0x0000480A
#define VMCS_GUEST_LDTR_LIMIT 0x0000480C
#define VMCS_GUEST_TR_LIMIT 0x0000480E
#define VMCS_GUEST_GDTR_LIMIT 0x00004810
#define VMCS_GUEST_IDTR_LIMIT 0x00004812
#define VMCS_GUEST_ES_ACCESS_RIGHTS 0x00004814
#define VMCS_GUEST_CS_ACCESS_RIGHTS 0x00004816
#define VMCS_GUEST_SS_ACCESS_RIGHTS 0x00004818
#define VMCS_GUEST_DS_ACCESS_RIGHTS 0x0000481A
#define VMCS_GUEST_FS_ACCESS_RIGHTS 0x0000481C
#define VMCS_GUEST_GS_ACCESS_RIGHTS 0x0000481E
#define VMCS_GUEST_LDTR_ACCESS_RIGHTS 0x00004820
#define VMCS_GUEST_TR_ACCESS_RIGHTS 0x00004822
#define VMCS_GUEST_INTERRUPTIBILITY_STATE 0x00004824
#define VMCS_GUEST_ACTIVITY_STATE 0x00004826
#define VMCS_GUEST_SMBASE 0x00004828
#define VMCS_GUEST_SYSENTER_CS 0x0000482A
#define VMCS_GUEST_PREEMPT_TIMER_VALUE 0x0000482E
/**
 * @}
 */

/**
 * @defgroup vmcs_32_bit_host_state_fields \
 *           32-Bit Host-State Field
 * @{
 */
#define VMCS_HOST_SYSENTER_CS 0x00004C00
/**
 * @}
 */

/**
 * @}
 */

/**
 * @defgroup vmcs_natural_width \
 *           Natural-Width Fields
 * @{
 */
/**
 * @defgroup vmcs_natural_width_control_fields \
 *           Natural-Width Control Fields
 * @{
 */
#define VMCS_CTRL_CR0_MASK 0x00006000
#define VMCS_CTRL_CR4_MASK 0x00006002
#define VMCS_CTRL_CR0_READ_SHADOW 0x00006004
#define VMCS_CTRL_CR4_READ_SHADOW 0x00006006
#define VMCS_CTRL_CR3_TARGET_VAL0 0x00006008
#define VMCS_CTRL_CR3_TARGET_VAL1 0x0000600A
#define VMCS_CTRL_CR3_TARGET_VAL2 0x0000600C
#define VMCS_CTRL_CR3_TARGET_VAL3 0x0000600E
/**
 * @}
 */

/**
 * @defgroup vmcs_natural_width_read_only_data_fields \
 *           Natural-Width Read-Only Data Fields
 * @{
 */
#define VMCS_EXIT_QUALIFICATION 0x00006400
#define VMCS_IO_RCX 0x00006402
#define VMCS_IO_RSI 0x00006404
#define VMCS_IO_RDI 0x00006406
#define VMCS_IO_RIP 0x00006408
#define VMCS_EXIT_GUEST_LINEAR_ADDR 0x0000640A
/**
 * @}
 */

/**
 * @defgroup vmcs_natural_width_guest_state_fields \
 *           Natural-Width Guest-State Fields
 * @{
 */
#define VMCS_GUEST_CR0 0x00006800
#define VMCS_GUEST_CR3 0x00006802
#define VMCS_GUEST_CR4 0x00006804
#define VMCS_GUEST_ES_BASE 0x00006806
#define VMCS_GUEST_CS_BASE 0x00006808
#define VMCS_GUEST_SS_BASE 0x0000680A
#define VMCS_GUEST_DS_BASE 0x0000680C
#define VMCS_GUEST_FS_BASE 0x0000680E
#define VMCS_GUEST_GS_BASE 0x00006810
#define VMCS_GUEST_LDTR_BASE 0x00006812
#define VMCS_GUEST_TR_BASE 0x00006814
#define VMCS_GUEST_GDTR_BASE 0x00006816
#define VMCS_GUEST_IDTR_BASE 0x00006818
#define VMCS_GUEST_DR7 0x0000681A
#define VMCS_GUEST_RSP 0x0000681C
#define VMCS_GUEST_RIP 0x0000681E
#define VMCS_GUEST_RFLAGS 0x00006820
#define VMCS_GUEST_PENDING_DEBUG_EXCEPTIONS 0x00006822
#define VMCS_GUEST_SYSENTER_ESP 0x00006824
#define VMCS_GUEST_SYSENTER_EIP 0x00006826
#define VMCS_GUEST_S_CET 0x00006828
#define VMCS_GUEST_SSP 0x0000682A
#define VMCS_GUEST_INTERRUPT_SSP_TABLE_ADDR 0x0000682C
/**
 * @}
 */

/**
 * @defgroup vmcs_natural_width_host_state_fields \
 *           Natural-Width Host-State Fields
 * @{
 */
#define VMCS_HOST_CR0 0x00006C00
#define VMCS_HOST_CR3 0x00006C02
#define VMCS_HOST_CR4 0x00006C04
#define VMCS_HOST_FS_BASE 0x00006C06
#define VMCS_HOST_GS_BASE 0x00006C08
#define VMCS_HOST_TR_BASE 0x00006C0A
#define VMCS_HOST_GDTR_BASE 0x00006C0C
#define VMCS_HOST_IDTR_BASE 0x00006C0E
#define VMCS_HOST_SYSENTER_ESP 0x00006C10
#define VMCS_HOST_SYSENTER_EIP 0x00006C12
#define VMCS_HOST_RSP 0x00006C14
#define VMCS_HOST_RIP 0x00006C16
#define VMCS_HOST_S_CET 0x00006C18
#define VMCS_HOST_SSP 0x00006C1A
#define VMCS_HOST_INTERRUPT_SSP_TABLE_ADDR 0x00006C1C
/**
 * @}
 */

/**
 * @}
 */

/**
 * @}
 */

typedef enum {
  external_interrupt = 0x00000000,
  non_maskable_interrupt = 0x00000002,
  hardware_exception = 0x00000003,
  software_interrupt = 0x00000004,
  privileged_software_exception = 0x00000005,
  software_exception = 0x00000006,
  other_event = 0x00000007,
} interruption_type;

typedef union {
  struct {
    std::uint32_t vector : 8;
    std::uint32_t interruption_type : 3;
    std::uint32_t deliver_error_code : 1;
    std::uint32_t reserved_1 : 19;
    std::uint32_t valid : 1;
  };

  std::uint32_t flags;
} vmentry_interrupt_info;

typedef union {
  struct {
    std::uint32_t vector : 8;
    std::uint32_t interruption_type : 3;
    std::uint32_t error_code_valid : 1;
    std::uint32_t nmi_unblocking : 1;
    std::uint32_t reserved_1 : 18;
    std::uint32_t valid : 1;
  };

  std::uint32_t flags;
} vmexit_interrupt_info;

/**
 * @}
 */

/**
 * @defgroup apic \
 *           Advanced Programmable Interrupt Controller (APIC)
 * @{
 */
#define APIC_BASE 0xFEE00000
#define APIC_ID 0x00000020
#define APIC_VERSION 0x00000030
#define APIC_TPR 0x00000080
#define APIC_APR 0x00000090
#define APIC_PPR 0x000000A0
#define APIC_EOI 0x000000B0
#define APIC_REMOTE_READ 0x000000C0
#define APIC_LOGICAL_DESTINATION 0x000000D0
#define APIC_DESTINATION_FORMAT 0x000000E0
#define APIC_SIV 0x000000F0
#define APIC_ISR_31_0 0x00000100
#define APIC_ISR_63_32 0x00000110
#define APIC_ISR_95_64 0x00000120
#define APIC_ISR_127_96 0x00000130
#define APIC_ISR_159_128 0x00000140
#define APIC_ISR_191_160 0x00000150
#define APIC_ISR_223_192 0x00000160
#define APIC_ISR_255_224 0x00000170
#define APIC_TMR_31_0 0x00000180
#define APIC_TMR_63_32 0x00000190
#define APIC_TMR_95_64 0x000001A0
#define APIC_TMR_127_96 0x000001B0
#define APIC_TMR_159_128 0x000001C0
#define APIC_TMR_191_160 0x000001D0
#define APIC_TMR_223_192 0x000001E0
#define APIC_TMR_255_224 0x000001F0
#define APIC_IRR_31_0 0x00000200
#define APIC_IRR_63_32 0x00000210
#define APIC_IRR_95_64 0x00000220
#define APIC_IRR_127_96 0x00000230
#define APIC_IRR_159_128 0x00000240
#define APIC_IRR_191_160 0x00000250
#define APIC_IRR_223_192 0x00000260
#define APIC_IRR_255_224 0x00000270
#define APIC_ERROR_STATUS 0x00000280
#define APIC_CMCI 0x000002F0
#define APIC_ICR_0_31 0x00000300
#define APIC_ICR_32_63 0x00000310
#define APIC_LVT_TIMER 0x00000320
#define APIC_LVT_THERMAL_SENSOR 0x00000330
#define APIC_LVT_PERFORMANCE_MONITORING_COUNTERS 0x00000340
#define APIC_LVT_LINT0 0x00000350
#define APIC_LVT_LINT1 0x00000360
#define APIC_LVT_ERROR 0x00000370
#define APIC_INITIAL_COUNT 0x00000380
#define APIC_CURRENT_COUNT 0x00000390
#define APIC_DIVIDE_CONFIGURATION 0x000003E0
/**
 * @}
 */

typedef union {
  struct {
    std::uint32_t carry_flag : 1;
    std::uint32_t read_as_1 : 1;
    std::uint32_t parity_flag : 1;
    std::uint32_t reserved_1 : 1;
    std::uint32_t auxiliary_carry_flag : 1;
    std::uint32_t reserved_2 : 1;
    std::uint32_t zero_flag : 1;
    std::uint32_t sign_flag : 1;
    std::uint32_t trap_flag : 1;
    std::uint32_t interrupt_enable_flag : 1;
    std::uint32_t direction_flag : 1;
    std::uint32_t overflow_flag : 1;
    std::uint32_t io_privilege_level : 2;
    std::uint32_t nested_task_flag : 1;
    std::uint32_t reserved_3 : 1;
    std::uint32_t resume_flag : 1;
    std::uint32_t virtual_8086_mode_flag : 1;
    std::uint32_t alignment_check_flag : 1;
    std::uint32_t virtual_interrupt_flag : 1;
    std::uint32_t virtual_interrupt_pending_flag : 1;
    std::uint32_t identification_flag : 1;
  };

  std::uint32_t flags;
} efl;

typedef union {
  struct {
    std::uint64_t carry_flag : 1;
    std::uint64_t read_as_1 : 1;
    std::uint64_t parity_flag : 1;
    std::uint64_t reserved_1 : 1;
    std::uint64_t auxiliary_carry_flag : 1;
    std::uint64_t reserved_2 : 1;
    std::uint64_t zero_flag : 1;
    std::uint64_t sign_flag : 1;
    std::uint64_t trap_flag : 1;
    std::uint64_t interrupt_enable_flag : 1;
    std::uint64_t direction_flag : 1;
    std::uint64_t overflow_flag : 1;
    std::uint64_t io_privilege_level : 2;
    std::uint64_t nested_task_flag : 1;
    std::uint64_t reserved_3 : 1;
    std::uint64_t resume_flag : 1;
    std::uint64_t virtual_8086_mode_flag : 1;
    std::uint64_t alignment_check_flag : 1;
    std::uint64_t virtual_interrupt_flag : 1;
    std::uint64_t virtual_interrupt_pending_flag : 1;
    std::uint64_t identification_flag : 1;
  };

  std::uint64_t flags;
} rfl;

/**
 * @defgroup exceptions \
 *           Exceptions
 * @{
 */
typedef union {
  struct {
    std::uint32_t cpec : 15;
    std::uint32_t encl : 1;
  };

  std::uint32_t flags;
} control_protection_exception;

typedef enum {
  divide_error = 0x00000000,
  debug = 0x00000001,
  nmi = 0x00000002,
  breakpoint = 0x00000003,
  overflow = 0x00000004,
  bound_range_exceeded = 0x00000005,
  invalid_opcode = 0x00000006,
  device_not_available = 0x00000007,
  double_fault = 0x00000008,
  coprocessor_segment_overrun = 0x00000009,
  invalid_tss = 0x0000000A,
  segment_not_present = 0x0000000B,
  stack_segment_fault = 0x0000000C,
  general_protection = 0x0000000D,
  page_fault = 0x0000000E,
  x87_floating_point_error = 0x00000010,
  alignment_check = 0x00000011,
  machine_check = 0x00000012,
  simd_floating_point_error = 0x00000013,
  virtualization_exception = 0x00000014,
  control_protection = 0x00000015,
} exception_vector;

typedef union {
  struct {
    std::uint32_t external_event : 1;
    std::uint32_t descriptor_location : 1;
    std::uint32_t gdt_ldt : 1;
    std::uint32_t index : 13;
  };

  std::uint32_t flags;
} exception_error_code;

typedef union {
  struct {
    std::uint32_t present : 1;
    std::uint32_t write : 1;
    std::uint32_t user_mode_access : 1;
    std::uint32_t reserved_bit_violation : 1;
    std::uint32_t execute : 1;
    std::uint32_t protection_key_violation : 1;
    std::uint32_t shadow_stack : 1;
    std::uint32_t hlat : 1;
    std::uint32_t reserved_1 : 7;
    std::uint32_t sgx : 1;
  };

  std::uint32_t flags;
} page_fault_exception;

/**
 * @}
 */

/**
 * @defgroup memory_type \
 *           Memory caching type
 * @{
 */
#define MEMORY_TYPE_UC 0x00000000
#define MEMORY_TYPE_WC 0x00000001
#define MEMORY_TYPE_WT 0x00000004
#define MEMORY_TYPE_WP 0x00000005
#define MEMORY_TYPE_WB 0x00000006
#define MEMORY_TYPE_UC_MINUS 0x00000007
#define MEMORY_TYPE_INVALID 0x000000FF
/**
 * @}
 */

/**
 * @defgroup vtd \
 *           VTD
 * @{
 */
typedef struct {
  union {
    struct {
      std::uint64_t present : 1;
      std::uint64_t reserved_1 : 11;
      std::uint64_t context_table_pointer : 52;
    };

    std::uint64_t flags;
  } lower64;

  union {
    struct {
      std::uint64_t reserved : 64;
    };

    std::uint64_t flags;
  } upper64;

} vtd_root_entry;

typedef struct {
  union {
    struct {
      std::uint64_t present : 1;
      std::uint64_t fault_processing_disable : 1;
      std::uint64_t translation_type : 2;
      std::uint64_t reserved_1 : 8;
      std::uint64_t second_level_page_translation_pointer : 52;
    };

    std::uint64_t flags;
  } lower64;

  union {
    struct {
      std::uint64_t address_width : 3;
      std::uint64_t ignored : 4;
      std::uint64_t reserved_1 : 1;
      std::uint64_t domain_identifier : 10;
    };

    std::uint64_t flags;
  } upper64;

} vtd_context_entry;

/**
 * @defgroup vtd_entry_count \
 *           Table entry counts
 * @{
 */
#define VTD_ROOT_ENTRY_COUNT 0x00000100
#define VTD_CONTEXT_ENTRY_COUNT 0x00000100
/**
 * @}
 */

#define VTD_VERSION 0x00000000
typedef union {
  struct {
    std::uint32_t minor : 4;
    std::uint32_t major : 4;
  };

  std::uint32_t flags;
} vtd_version_register;

#define VTD_CAPABILITY 0x00000008
typedef union {
  struct {
    std::uint64_t number_of_domains_supported : 3;
    std::uint64_t advanced_fault_logging : 1;
    std::uint64_t required_write_buffer_flushing : 1;
    std::uint64_t protected_low_memory_region : 1;
    std::uint64_t protected_high_memory_region : 1;
    std::uint64_t caching_mode : 1;
    std::uint64_t supported_adjusted_guest_address_widths : 5;
    std::uint64_t reserved_1 : 3;
    std::uint64_t maximum_guest_address_width : 6;
    std::uint64_t zero_length_read : 1;
    std::uint64_t deprecated : 1;
    std::uint64_t fault_recording_register_offset : 10;
    std::uint64_t second_level_large_page_support : 4;
    std::uint64_t reserved_2 : 1;
    std::uint64_t page_selective_invalidation : 1;
    std::uint64_t number_of_fault_recording_registers : 8;
    std::uint64_t maximum_address_mask_value : 6;
    std::uint64_t write_draining : 1;
    std::uint64_t read_draining : 1;
    std::uint64_t first_level_1gbyte_page_support : 1;
    std::uint64_t reserved_3 : 2;
    std::uint64_t posted_interrupts_support : 1;
    std::uint64_t first_level_5level_paging_support : 1;
    std::uint64_t reserved_4 : 1;
    std::uint64_t enhanced_set_interrupt_remap_table_pointer_support : 1;
    std::uint64_t enhanced_set_root_table_pointer_support : 1;
  };

  std::uint64_t flags;
} vtd_capability_register;

#define VTD_EXTENDED_CAPABILITY 0x00000010
typedef union {
  struct {
    std::uint64_t page_walk_coherency : 1;
    std::uint64_t queued_invalidation_support : 1;
    std::uint64_t device_tlb_support : 1;
    std::uint64_t interrupt_remapping_support : 1;
    std::uint64_t extended_interrupt_mode : 1;
    std::uint64_t deprecated1 : 1;
    std::uint64_t pass_through : 1;
    std::uint64_t snoop_control : 1;
    std::uint64_t iotlb_register_offset : 10;
    std::uint64_t reserved_1 : 2;
    std::uint64_t maximum_handle_mask_value : 4;
    std::uint64_t deprecated2 : 1;
    std::uint64_t memory_type_support : 1;
    std::uint64_t nested_translation_support : 1;
    std::uint64_t reserved_2 : 1;
    std::uint64_t deprecated3 : 1;
    std::uint64_t page_request_support : 1;
    std::uint64_t execute_request_support : 1;
    std::uint64_t reserved_3 : 2;
    std::uint64_t no_write_flag_support : 1;
    std::uint64_t extended_accessed_flag_support : 1;
    std::uint64_t pasid_size_supported : 5;
    std::uint64_t process_address_space_id_support : 1;
    std::uint64_t device_tlb_invalidation_throttle : 1;
    std::uint64_t page_request_drain_support : 1;
    std::uint64_t scalable_mode_translation_support : 1;
    std::uint64_t virtual_command_support : 1;
    std::uint64_t second_level_accessed_dirty_support : 1;
    std::uint64_t second_level_translation_support : 1;
    std::uint64_t first_level_translation_support : 1;
    std::uint64_t scalable_mode_page_walk_coherency : 1;
    std::uint64_t rid_pasid_support : 1;
    std::uint64_t reserved_4 : 2;
    std::uint64_t abort_dma_mode_support : 1;
    std::uint64_t rid_priv_support : 1;
  };

  std::uint64_t flags;
} vtd_extended_capability_register;

#define VTD_GLOBAL_COMMAND 0x00000018
typedef union {
  struct {
    std::uint32_t reserved_1 : 23;
    std::uint32_t compatibility_format_interrupt : 1;
    std::uint32_t set_interrupt_remap_table_pointer : 1;
    std::uint32_t interrupt_remapping_enable : 1;
    std::uint32_t queued_invalidation_enable : 1;
    std::uint32_t write_buffer_flush : 1;
    std::uint32_t enable_advanced_fault_logging : 1;
    std::uint32_t set_fault_log : 1;
    std::uint32_t set_root_table_pointer : 1;
    std::uint32_t translation_enable : 1;
  };

  std::uint32_t flags;
} vtd_global_command_register;

#define VTD_GLOBAL_STATUS 0x0000001C
typedef union {
  struct {
    std::uint32_t reserved_1 : 23;
    std::uint32_t compatibility_format_interrupt_status : 1;
    std::uint32_t interrupt_remapping_table_pointer_status : 1;
    std::uint32_t interrupt_remapping_enable_status : 1;
    std::uint32_t queued_invalidation_enable_status : 1;
    std::uint32_t write_buffer_flush_status : 1;
    std::uint32_t advanced_fault_logging_status : 1;
    std::uint32_t fault_log_status : 1;
    std::uint32_t root_table_pointer_status : 1;
    std::uint32_t translation_enable_status : 1;
  };

  std::uint32_t flags;
} vtd_global_status_register;

#define VTD_ROOT_TABLE_ADDRESS 0x00000020
typedef union {
  struct {
    std::uint64_t reserved_1 : 10;
    std::uint64_t translation_table_mode : 2;
    std::uint64_t root_table_address : 52;
  };

  std::uint64_t flags;
} vtd_root_table_address_register;

#define VTD_CONTEXT_COMMAND 0x00000028
typedef union {
  struct {
    std::uint64_t domain_id : 16;
    std::uint64_t source_id : 16;
    std::uint64_t function_mask : 2;
    std::uint64_t reserved_1 : 25;
    std::uint64_t context_actual_invalidation_granularity : 2;
    std::uint64_t context_invalidation_request_granularity : 2;
    std::uint64_t invalidate_context_cache : 1;
  };

  std::uint64_t flags;
} vtd_context_command_register;

#define VTD_INVALIDATE_ADDRESS 0x00000000
typedef union {
  struct {
    std::uint64_t address_mask : 6;
    std::uint64_t invalidation_hint : 1;
    std::uint64_t reserved_1 : 5;
    std::uint64_t page_address : 52;
  };

  std::uint64_t flags;
} vtd_invalidate_address_register;

#define VTD_IOTLB_INVALIDATE 0x00000008
typedef union {
  struct {
    std::uint64_t reserved_1 : 32;
    std::uint64_t domain_id : 16;
    std::uint64_t drain_writes : 1;
    std::uint64_t drain_reads : 1;
    std::uint64_t reserved_2 : 7;
    std::uint64_t iotlb_actual_invalidation_granularity : 2;
    std::uint64_t reserved_3 : 1;
    std::uint64_t iotlb_invalidation_request_granularity : 2;
    std::uint64_t reserved_4 : 1;
    std::uint64_t invalidate_iotlb : 1;
  };

  std::uint64_t flags;
} vtd_iotlb_invalidate_register;

/**
 * @}
 */

typedef union {
  struct {
    std::uint64_t x87 : 1;
    std::uint64_t sse : 1;
    std::uint64_t avx : 1;
    std::uint64_t bndreg : 1;
    std::uint64_t bndcsr : 1;
    std::uint64_t opmask : 1;
    std::uint64_t zmm_hi256 : 1;
    std::uint64_t zmm_hi16 : 1;
    std::uint64_t reserved_1 : 1;
    std::uint64_t pkru : 1;
  };

  std::uint64_t flags;
} xcr0_t;

/**
 * @}
 */

#endif