// © 2019 John Adriaan. Licensed under the "3-clause BSD License"
///
/// \file ARM/NVICs.hh
///

#ifndef ARM_NVICs_hh
#define ARM_NVICs_hh

#include "ARM.hh"

/// \namespace ARM::NVICs
/// ARM have defined the Nested Vector Interrupt Controller (NVIC).
/// These are its definitions.
namespace ARM::NVICs {

	/// See `NVICs/NVICs.hh` for full definition
	enum class IRQs;

	class _NVIC_ : private _ARM_ {
	}; // _NVIC_

	/// See `NVICs/NVIC.hh` for definitions
	struct NVIC;

	typedef volatile unsigned TypeSTIR;

	extern NVIC nvic;

	extern TypeSTIR stir; // Write only

	// These are the "hook" functions for each of the IRQs.
	// The architecture-specific linker script provides the mapping between the
	// actual ISRs and these
	void IRQ0();   void IRQ1();   void IRQ2();   void IRQ3();
	void IRQ4();   void IRQ5();   void IRQ6();   void IRQ7();
	void IRQ8();   void IRQ9();   void IRQ10();  void IRQ11();
	void IRQ12();  void IRQ13();  void IRQ14();  void IRQ15();
	void IRQ16();  void IRQ17();  void IRQ18();  void IRQ19();
	void IRQ20();  void IRQ21();  void IRQ22();  void IRQ23();
	void IRQ24();  void IRQ25();  void IRQ26();  void IRQ27();
	void IRQ28();  void IRQ29();  void IRQ30();  void IRQ31();
	void IRQ32();  void IRQ33();  void IRQ34();  void IRQ35();
	void IRQ36();  void IRQ37();  void IRQ38();  void IRQ39();
	void IRQ40();  void IRQ41();  void IRQ42();  void IRQ43();
	void IRQ44();  void IRQ45();  void IRQ46();  void IRQ47();
	void IRQ48();  void IRQ49();  void IRQ50();  void IRQ51();
	void IRQ52();  void IRQ53();  void IRQ54();  void IRQ55();
	void IRQ56();  void IRQ57();  void IRQ58();  void IRQ59();
	void IRQ60();  void IRQ61();  void IRQ62();  void IRQ63();
	void IRQ64();  void IRQ65();  void IRQ66();  void IRQ67();
	void IRQ68();  void IRQ69();  void IRQ70();  void IRQ71();
	void IRQ72();  void IRQ73();  void IRQ74();  void IRQ75();
	void IRQ76();  void IRQ77();  void IRQ78();  void IRQ79();
	void IRQ80();  void IRQ81();  void IRQ82();  void IRQ83();
	void IRQ84();  void IRQ85();  void IRQ86();  void IRQ87();
	void IRQ88();  void IRQ89();  void IRQ90();  void IRQ91();
	void IRQ92();  void IRQ93();  void IRQ94();  void IRQ95();
	void IRQ96();  void IRQ97();  void IRQ98();  void IRQ99();
	void IRQ100(); void IRQ101(); void IRQ102(); void IRQ103();
	void IRQ104(); void IRQ105(); void IRQ106(); void IRQ107();
	void IRQ108(); void IRQ109(); void IRQ110(); void IRQ111();
	void IRQ112(); void IRQ113(); void IRQ114(); void IRQ115();
	void IRQ116(); void IRQ117(); void IRQ118(); void IRQ119();
	void IRQ120(); void IRQ121(); void IRQ122(); void IRQ123();
	void IRQ124(); void IRQ125(); void IRQ126(); void IRQ127();
	void IRQ128(); void IRQ129(); void IRQ130(); void IRQ131();
	void IRQ132(); void IRQ133(); void IRQ134(); void IRQ135();
	void IRQ136(); void IRQ137(); void IRQ138(); void IRQ139();
	void IRQ140(); void IRQ141(); void IRQ142(); void IRQ143();
	void IRQ144(); void IRQ145(); void IRQ146(); void IRQ147();
	void IRQ148(); void IRQ149(); void IRQ150(); void IRQ151();
	void IRQ152(); void IRQ153(); void IRQ154(); void IRQ155();
	void IRQ156(); void IRQ157(); void IRQ158(); void IRQ159();
	void IRQ160(); void IRQ161(); void IRQ162(); void IRQ163();
	void IRQ164(); void IRQ165(); void IRQ166(); void IRQ167();
	void IRQ168(); void IRQ169(); void IRQ170(); void IRQ171();
	void IRQ172(); void IRQ173(); void IRQ174(); void IRQ175();
	void IRQ176(); void IRQ177(); void IRQ178(); void IRQ179();
	void IRQ180(); void IRQ181(); void IRQ182(); void IRQ183();
	void IRQ184(); void IRQ185(); void IRQ186(); void IRQ187();
	void IRQ188(); void IRQ189(); void IRQ190(); void IRQ191();
	void IRQ192(); void IRQ193(); void IRQ194(); void IRQ195();
	void IRQ196(); void IRQ197(); void IRQ198(); void IRQ199();
	void IRQ200(); void IRQ201(); void IRQ202(); void IRQ203();
	void IRQ204(); void IRQ205(); void IRQ206(); void IRQ207();
	void IRQ208(); void IRQ209(); void IRQ210(); void IRQ211();
	void IRQ212(); void IRQ213(); void IRQ214(); void IRQ215();
	void IRQ216(); void IRQ217(); void IRQ218(); void IRQ219();
	void IRQ220(); void IRQ221(); void IRQ222(); void IRQ223();
	void IRQ224(); void IRQ225(); void IRQ226(); void IRQ227();
	void IRQ228(); void IRQ229(); void IRQ230(); void IRQ231();
	void IRQ232(); void IRQ233(); void IRQ234(); void IRQ235();
	void IRQ236(); void IRQ237(); void IRQ238(); void IRQ239();

} // namespace ARM::NVICs

#include "NVICs/NVICs.hh"
#include "NVICs/NVIC.hh"

#endif // ARM_NVICs_hh
