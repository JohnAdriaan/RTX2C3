// © 2019 John Adriaan. Licensed under the "3-clause BSD License"
///
/// \file ARM/SCBs/SCB.hh
///
/// This provides all the registers and definitions associated with the
/// ARM System Control Block
///

#ifndef ARM_SCBs_SCB_hh
#define ARM_SCBs_SCB_hh

#include <General/General.hh>
#include <General/Field.hh>

#include "../SCBs.hh"

namespace ARM {
namespace SCBs {

	enum Implementors {
		ARM = 0x41
	}; // Implementors

	enum PartNos {
		CortexM7 = 0xC27
	}; // PartNos

	/// CPU Identification register
    struct CPUID {
    	unsigned Revision    :  4; ///< The `P` number in the "RnPn" identifier
    	unsigned PartNo      : 12; ///< {PartNos} Part Number
    	unsigned             :  4; ///< Reads as `0xF`
    	unsigned Variant     :  4; ///< The 'R' number in the "RnPn" identifier
    	unsigned Implementor :  8; ///< {Implementors} Implementor code
    	unsigned             :  0;
    }; // CPUID
    typedef Field<CPUID, unsigned> FieldCPUID;

    /// Interrupt Control and Status Register
    struct ICSR {
    	const unsigned VECTACTIVE  : 9; ///< Vector currently Active
    	      unsigned             : 2;
    	const unsigned RETTOBASE   : 1; ///< No currently preempted exceptions
    	const unsigned VECTPENDING : 9; ///< Vector pending
    	      unsigned             : 1;
    	const unsigned ISRPENDING  : 1; ///< Interrupt Pending flag (not NMI or Faults)
    	const unsigned             : 1; ///< Reserved for Debug Use
    	      unsigned             : 1;
    	      unsigned PENDSTCLR   : 1; ///< Clear `SysTick`
    	      unsigned PENDSTSET   : 1; ///< Trigger `SysTick`
    	      unsigned PENDSVCLR   : 1; ///< Clear `PendSV`
    	      unsigned PENDSVSET   : 1; ///< Trigger `PendSV`
    	      unsigned             : 2;
    	      unsigned NMIPENDSET  : 1; ///< NMI pending? (Only likely within NMI handler)
    	      unsigned             : 0;
    }; // ICSR
    typedef Field<ICSR, unsigned> FieldICSR;

    /// Vector Table Offset Register
    struct VTOR {
    	unsigned        :  7;
    	unsigned TBLOFF : 25; ///< Vector Table Offset
    	unsigned        :  0;
    }; // VTOR
    typedef Field<VTOR, void *> FieldVTOR;

    /// Different VECTKEY values for `AIRCR.VECTKEY`
    enum VectKeys {
    	VECTKEY     = 0x05FA,
    	VECTKEYSTAT = 0xFA05
    }; // VectKeys

    /// Different Endian values for `AIRCR.ENDIANNESS`
    enum Endians : bit {
    	LittleEndian = 0,
		BigEndian
    }; // Endians

    /// Application Interrupt and Reset Control Register
    struct AIRCR {
	          unsigned VECTRESET     :  1; ///< Reserved for Debug. Always write `0`
	          unsigned VECTCLRACTIVE :  1; ///< Reserved for Debug. Always write `0`
    	      unsigned SYSRESETREQ   :  1; ///< `1`=Request System Reset
    	      unsigned               :  5;
    	      unsigned PRIGROUP      :  3; ///< Interrupt Priority Grouping field
    	      unsigned               :  4;
    	const unsigned ENDIANNESS    :  1; ///< {Endians} Implementation configured
    	      unsigned VECTKEY       : 16; ///< {VectKeys} Reads as VECTKEYSTAT. Always write VECTKEY
    	      unsigned               :  0;
    }; // AIRCR
    typedef Field<AIRCR, unsigned> FieldAIRCR;

    /// System Control Register
    struct SCR {
    	unsigned             :  1;
    	unsigned SLEEPONEXIT :  1; ///< 1=Sleep on return from ISR
    	unsigned SLEEPDEEP   :  1; ///< 0=Sleep. 1=Deep Sleep.
    	unsigned             :  1;
    	unsigned SEVONPEND   :  1; ///< Send Event on Pending bit
    	unsigned             : 27;
    	unsigned             :  0;
    }; // SCR
    typedef Field<SCR, unsigned> FieldSCR;

    /// Configuration and Control Register
    struct CCR {
    	      unsigned NONBASETHRDENA :  1; ///< How can enter Thread mode
    	      unsigned USERSETMPEND   :  1; ///< Enable unprivileged access to `STIR`
    	      unsigned                :  1;
    	      unsigned UNALIGN_TRP    :  1; ///< Enable Unaligned access Trap
    	      unsigned DIV_0_TRP      :  1; ///< Enable Division by `0` Trap
    	      unsigned                :  3;
    	      unsigned BFHFNMIGN      :  1; ///< BusFault, HardFault, NMI Ignore
    	const unsigned STKALIGN       :  1; ///< `1`=Exception is 8-byte Stack Aligned
    	      unsigned                :  6;
    	      unsigned DC             :  1; ///< Enable L1 Data Cache
    	      unsigned IC             :  1; ///< Enable L1 Instruction Cache
    	const unsigned BP             :  1; ///< `1`=Branch Prediction enabled
    	      unsigned                : 13;
    	      unsigned                :  0;
    }; // CCR
    typedef Field<CCR, unsigned> FieldCCR;

    /// System Handler Priority Register 1
    struct SHPR1 {
    	byte MemManage  : 8; ///< Priority of MemManage ISR
    	byte BusFault   : 8; ///< Priority of BusFault ISR
    	byte UsageFault : 8; ///< Priority of UsageFault ISR
    	byte            : 8;
    	unsigned        : 0;
    }; // SHPR1
    typedef Field<SHPR1, unsigned> FieldSHPR1;

    /// System Handler Priority Register 2
    struct SHPR2 {
    	unsigned    : 24;
    	byte SVCall :  8; ///< Priority of SVCall ISR
    	unsigned    :  0;
    }; // SHPR2
    typedef Field<SHPR2, unsigned> FieldSHPR2;

    /// System Handler Priority Register 3
    struct SHPR3 {
    	unsigned     : 16;
    	byte PendSV  :  8; ///< Priority of PendSV ISR
    	byte SysTick :  8; ///< Priority of SysTick ISR
    	unsigned     :  0;
    }; // SHPR3
    typedef Field<SHPR3, unsigned> FieldSHPR3;

    /// System Handler Control and State Register
    struct SHCSR {
    	unsigned MEMFAULTACT    :  1; ///< MemManage ISR Active
    	unsigned BUSFAULTACT    :  1; ///< BusFault ISR Active
    	unsigned                :  1;
    	unsigned USAGEFAULTACT  :  1; ///< UsageFault ISR Active
    	unsigned                :  3;
    	unsigned SVCALLACT      :  1; ///< SVCall ISR Active
    	unsigned MONITORACT     :  1; ///< Debug Monitor ISR Active
    	unsigned                :  1;
    	unsigned PENDSVACT      :  1; ///< PendSV ISR Active
    	unsigned SYSTICKACT     :  1; ///< SysTick ISR Active
    	unsigned USGFAULTPENDED :  1; ///< UsageFault exception pending
    	unsigned MEMFAULTPENDED :  1; ///< MemManage exception pending
    	unsigned BUSFAULTPENDED :  1; ///< BusFault exception pending
    	unsigned SVCALLPENDED   :  1; ///< SVCall exception pending
    	unsigned MEMFAULTENA    :  1; ///< MemManage enabled
    	unsigned BUSFAULTENA    :  1; ///< BusFault enabled
    	unsigned USGFAULTENA    :  1; ///< UsageFault enabled
    	unsigned                : 13;
    	unsigned                :  0;
    }; // SHCSR
    typedef Field<SHCSR, unsigned> FieldSHCSR;

    /// MemManage Fault Status Register
    struct MMFSR {
    	byte IACCVIOL  : 1; ///< Instruction Access Violation
    	byte DACCVIOL  : 1; ///< Data Access Violation
    	byte           : 1;
    	byte MUNSTKERR : 1; ///< MemManage fault on Unstacking on return from exception
    	byte MSTKERR   : 1; ///< MemManage fault on Stacking for exception
    	byte MLSPERR   : 1; ///< MemManage fault on floating point Lazy State Preservation
    	byte           : 1;
    	byte MMARVALID : 1; ///< MemManage Fault Address Register Valid
    	byte           : 0;
    }; // MMFSR
    typedef Field<MMFSR, byte> FieldMMFSR;

    /// BusFault Status Register
    struct BFSR {
    	byte IBUSERR     : 1; ///< Instruction Bus Error
    	byte PRECISERR   : 1; ///< Precise data bus Error
    	byte IMPRECISERR : 1; ///< Imprecise data bus Error
    	byte UNSTKERR    : 1; ///< BusFault on Unstacking on return from exception
    	byte STKERR      : 1; ///< BusFault on Stacking for exception
    	byte LSPERR      : 1; ///< BusFault on floating point Lazy State Preservation
    	byte             : 1;
    	byte BFARVALID   : 1; ///< BusFault Address Register valid
    	byte             : 0;
    }; // BFSR
    typedef Field<BFSR, byte> FieldBFSR;

    /// UsageFault Status Register
    struct UFSR {
    	word UNDEFINSTR  : 1; ///< Undefined Instruction UsageFault
    	word INVSTATE    : 1; ///< Invalid State UsageFault
    	word INVPC       : 1; ///< Invalid PC load UsageFault
    	word NOCP        : 1; ///< No Coprocessor UsageFault
    	word             : 4;
    	word UNALIGNED   : 1; ///< Unaligned access UsageFault
    	word DIVBYZERO   : 1; ///< Divide by Zero UsageFault
    	word             : 6;
    	word             : 0;
    }; // UFSR
    typedef Field<UFSR, word> FieldUFSR;

    /// Configurable Fault Status Register
    struct CFSR {
    	FieldMMFSR MMFSR;
    	FieldBFSR  BFSR;
    	FieldUFSR  UFSR;
    }; // CFSR
    static_assert(sizeof(CFSR)==sizeof(unsigned), "Incorrect ARM::SCBs::CFSR size");

    /// HardFault Status Register
    struct HFSR {
    	unsigned          :  1;
    	unsigned VECTTBL  :  1; ///< BusFault on Vector read during exception
    	unsigned          : 28;
    	unsigned FORCED   :  1; ///< Forced by escalation of another fault
    	unsigned DEBUGEVT :  1; ///< Always write `1`
    	unsigned          :  0;
    }; // HFSR
    typedef Field<HFSR, unsigned> FieldHFSR;

    /// Fault Address Register
    typedef void *AddrReg;

    /// System Control Block
	struct SCB : private _SCB_ {
		volatile FieldCPUID CPUID; ///< CPU Identification register
		volatile FieldICSR  ICSR;  ///< Interrupt Control and Status Register
		volatile FieldVTOR  VTOR;  ///< Vector Table Offset Register
		volatile FieldAIRCR AIRCR; ///< Application Interrupt and Reset Control Register
		volatile FieldSCR   SCR;   ///< System Control Register
		volatile FieldCCR   CCR;   ///< Configuration and Control Register
		volatile FieldSHPR1 SHPR1; ///< System Handler Priority Register 1
		volatile FieldSHPR2 SHPR2; ///< System Handler Priority Register 2
		volatile FieldSHPR3 SHPR3; ///< System Handler Priority Register 3
		volatile FieldSHCSR SHCSR; ///< System Handler Control and State Register
		union {
			volatile struct CFSR CFSR;     ///< Configurable Fault Status Register
			struct {
				volatile FieldMMFSR MMFSR; ///< MemManage Fault Status Register
				volatile FieldBFSR  BFSR;  ///< BusFault Status Register
				volatile FieldUFSR  UFSR;  ///< UsageFault Status Register
			}; // struct
		}; // union
		volatile FieldHFSR  HFSR;  ///< HardFault Status Register
		         unsigned   x30;
		volatile AddrReg    MMFAR; ///< MemManage Address Register
		volatile AddrReg    BFAR;  ///< BusFault Address Register
	}; // SCB
	static_assert(sizeof(SCB)==15*sizeof(unsigned), "Incorrect ARM::SCBs::SCB size");

} // namespace SCBs
} // namespace ARM

static volatile ARM::SCBs::ACTLR &SCB = ARM::SCBs::actlr;

static volatile ARM::SCBs::FieldCPUID &CPUID = ARM::SCBs::scb.CPUID;
static volatile ARM::SCBs::FieldICSR  &ICSR  = ARM::SCBs::scb.ICSR;
static volatile ARM::SCBs::FieldVTOR  &VTOR  = ARM::SCBs::scb.VTOR;
static volatile ARM::SCBs::FieldAIRCR &AIRCR = ARM::SCBs::scb.AIRCR;
static volatile ARM::SCBs::FieldSCR   &SCR   = ARM::SCBs::scb.SCR;
static volatile ARM::SCBs::FieldCCR   &CCR   = ARM::SCBs::scb.CCR;
static volatile ARM::SCBs::FieldSHPR1 &SHPR1 = ARM::SCBs::scb.SHPR1;
static volatile ARM::SCBs::FieldSHPR2 &SHPR2 = ARM::SCBs::scb.SHPR2;
static volatile ARM::SCBs::FieldSHPR3 &SHPR3 = ARM::SCBs::scb.SHPR3;
static volatile ARM::SCBs::FieldSHCSR &SHCSR = ARM::SCBs::scb.SHCSR;
static volatile ARM::SCBs::CFSR       &CFSR  = ARM::SCBs::scb.CFSR;
static volatile ARM::SCBs::FieldMMFSR &MMFSR = ARM::SCBs::scb.MMFSR;
static volatile ARM::SCBs::FieldBFSR  &BFSR  = ARM::SCBs::scb.BFSR;
static volatile ARM::SCBs::FieldUFSR  &UFSR  = ARM::SCBs::scb.UFSR;
static volatile ARM::SCBs::FieldHFSR  &HFSR  = ARM::SCBs::scb.HFSR;
static volatile ARM::SCBs::AddrReg    &MMFAR = ARM::SCBs::scb.MMFAR;
static volatile ARM::SCBs::AddrReg    &BFAR  = ARM::SCBs::scb.BFAR;

#endif // ARM_SCBs_SCB_hh
