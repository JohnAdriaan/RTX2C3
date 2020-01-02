// © 2019 John Adriaan. Licensed under the "3-clause BSD License"
///
/// \file ARM/NVICs/NVIC.hh
///

#ifndef ARM_NVICs_NVIC_hh
#define ARM_NVICs_NVIC_hh

#include <General/General.hh>
#include <General/Bit.hh>

namespace ARM {
namespace NVICs {

	/// Interrupt Set-Enable Register
	struct ISER {
		unsigned SETENA; ///< Set Enable
	}; // ISER
	typedef Bit::Write<ISER, unsigned, 1> FieldISER;

	/// Interrupt Clear-Enable Register
	struct ICER {
		unsigned CLRENA; ///< Clear Enable
	}; // ICER
	typedef Bit::Write<ICER, unsigned, 1> FieldICER;

	/// Interrupt Set-Pending Register
	struct ISPR {
		unsigned SETPEND; ///< Set Pending
	}; // ISPR
	typedef Bit::Write<ISPR, unsigned, 1> FieldISPR;

	/// Interrupt Clear-Pending Register
	struct ICPR {
		unsigned CLRPEND; ///< Clear Pending
	}; // ICPR
	typedef Bit::Write<ICPR, unsigned, 1> FieldICPR;

	/// Interrupt Active Bit Register
	struct IABR {
		const unsigned ACTIVE; ///< Currently Active
	}; // IABR
	typedef Bit::Read<IABR, unsigned, 1> FieldIABR;

	/// Interrupt Priority Register
	struct IPR {
		unsigned IP; ///< Interrupt Priority
	}; // IPR
	typedef Bit::Update<IPR, unsigned, 8> FieldIPR;

	/// Nested Vectored Interrupt Controller
	struct NVIC : private _NVIC_ {
#define ISERs(ISERs)         \
		struct ISERs {       \
			FieldISER ISER0; \
			FieldISER ISER1; \
			FieldISER ISER2; \
			FieldISER ISER3; \
			FieldISER ISER4; \
			FieldISER ISER5; \
			FieldISER ISER6; \
			FieldISER ISER7; \
		} // struct
		ISERs(ISERs); ///< Declare a struct called "ISERs" as `#define`d by `ISERs()`
		union {
			ISERs();  ///< Define an anonymous struct as `#define`d by `ISERS()`
			Bit::Array::Write<ISERs, bit, 1, 0, IRQs> ISER; ///< Interrupt Set-Enable Register
		}; // union
#undef ISERs // Don't leave this lying around

		unsigned x020[24]; // Reserved

#define ICERs(ICERs)         \
		struct ICERs {       \
			FieldICER ICER0; \
			FieldICER ICER1; \
			FieldICER ICER2; \
			FieldICER ICER3; \
			FieldICER ICER4; \
			FieldICER ICER5; \
			FieldICER ICER6; \
			FieldICER ICER7; \
		} // struct
		ICERs(ICERs); // Declare a struct called "ICERs" as `#define`d by `ICERs()`
		union {
			ICERs(); // Define an anonymous struct as `#define`d by `ICERs()`
			Bit::Array::Write<ICERs, bit, 1, 0, IRQs> ICER; ///< Interrupt Clear-Enable Register
		}; // union
#undef ICERs // Don't leave this lying around

		unsigned x0A0[24]; // Reserved

#define ISPRs(ISPRs)         \
		struct ISPRs {       \
			FieldISPR ISPR0; \
			FieldISPR ISPR1; \
			FieldISPR ISPR2; \
			FieldISPR ISPR3; \
			FieldISPR ISPR4; \
			FieldISPR ISPR5; \
			FieldISPR ISPR6; \
			FieldISPR ISPR7; \
		} // struct
		ISPRs(ISPRs); // Declare a struct called "ISPRs" as `#define`d by `ISPRs()`
		union {
			ISPRs(); // Define an anonymous struct as `#define`d by `ISPRs()`
			Bit::Array::Write<ISPRs, bit, 1, 0, IRQs> ISPR; ///< Interrupt Set-Pending Register
		}; // union
#undef ISPRs // Don't leave this lying around

		unsigned x120[24]; // Reserved

#define ICPRs(ICPRs)         \
		struct ICPRs {       \
			FieldICPR ICPR0; \
			FieldICPR ICPR1; \
			FieldICPR ICPR2; \
			FieldICPR ICPR3; \
			FieldICPR ICPR4; \
			FieldICPR ICPR5; \
			FieldICPR ICPR6; \
			FieldICPR ICPR7; \
		} // struct
		ICPRs(ICPRs); // Declare a struct called "ICPRs" as `#define`d by `ICPRs()`
		union {
			ICPRs(); // Define an anonymous struct as `#define`d by `ICPRs()`
			Bit::Array::Write<ICPRs, bit, 1, 0, IRQs> ICPR; ///< Interrupt Clear-Pending Register
		}; // union
#undef ICPRs // Don't leave this lying around

		unsigned x1A0[24]; // Reserved

#define IABRs(IABRs)         \
		struct IABRs {       \
			FieldIABR IABR0; \
			FieldIABR IABR1; \
			FieldIABR IABR2; \
			FieldIABR IABR3; \
			FieldIABR IABR4; \
			FieldIABR IABR5; \
			FieldIABR IABR6; \
			FieldIABR IABR7; \
		} // struct
		IABRs(IABRs); // Declare a struct called "IABRs" as `#define`d by `IABRs()`
		union {
			IABRs(); // Define an anonymous struct as `#define`d by `IABRs()`
			Bit::Array::Read<IABRs, const bit, 1, 0, IRQs> IABR; ///< Interrupt Active Bit Register
		}; // union
#undef IABRs // Don't leave this lying around

		unsigned      x220[24]; // Reserved
		unsigned      x280[32]; // Reserved

#define IPRs(IPRs)          \
		struct IPRs {       \
			FieldIPR IPR0;  \
			FieldIPR IPR1;  \
			FieldIPR IPR2;  \
			FieldIPR IPR3;  \
			FieldIPR IPR4;  \
			FieldIPR IPR5;  \
			FieldIPR IPR6;  \
			FieldIPR IPR7;  \
			FieldIPR IPR8;  \
			FieldIPR IPR9;  \
			FieldIPR IPR10; \
			FieldIPR IPR11; \
			FieldIPR IPR12; \
			FieldIPR IPR13; \
			FieldIPR IPR14; \
			FieldIPR IPR15; \
			FieldIPR IPR16; \
			FieldIPR IPR17; \
			FieldIPR IPR18; \
			FieldIPR IPR19; \
			FieldIPR IPR20; \
			FieldIPR IPR21; \
			FieldIPR IPR22; \
			FieldIPR IPR23; \
			FieldIPR IPR24; \
			FieldIPR IPR25; \
			FieldIPR IPR26; \
			FieldIPR IPR27; \
			FieldIPR IPR28; \
			FieldIPR IPR29; \
			FieldIPR IPR30; \
			FieldIPR IPR31; \
			FieldIPR IPR32; \
			FieldIPR IPR33; \
			FieldIPR IPR34; \
			FieldIPR IPR35; \
			FieldIPR IPR36; \
			FieldIPR IPR37; \
			FieldIPR IPR38; \
			FieldIPR IPR39; \
			FieldIPR IPR40; \
			FieldIPR IPR41; \
			FieldIPR IPR42; \
			FieldIPR IPR43; \
			FieldIPR IPR44; \
			FieldIPR IPR45; \
			FieldIPR IPR46; \
			FieldIPR IPR47; \
			FieldIPR IPR48; \
			FieldIPR IPR49; \
			FieldIPR IPR50; \
			FieldIPR IPR51; \
			FieldIPR IPR52; \
			FieldIPR IPR53; \
			FieldIPR IPR54; \
			FieldIPR IPR55; \
			FieldIPR IPR56; \
			FieldIPR IPR57; \
			FieldIPR IPR58; \
			FieldIPR IPR59; \
		} // struct
		IPRs(IPRs); // Declare a struct called "IPRs" as `#define`d by `IPRs()`
		union {
			IPRs();  // Define an anonymous struct as `#define`d by `IPRs()`
			byte IPR[60*4]; ///< Interrupt Pending Register
		}; // union
#undef IPRs // Don't leave this lying around

	}; // NVIC
	static_assert(sizeof(NVIC)==252*sizeof(unsigned), "Incorrect ARM::NVICs::NVIC size");

} // namespace NVICs
} // namespace ARM

static volatile ARM::NVICs::TypeSTIR &NVIC_STIR = ARM::NVICs::stir;

#define NVIC_ISER ARM::NVICs::nvic.ISER
static volatile ARM::NVICs::FieldISER &NVIC_ISER0 = ARM::NVICs::nvic.ISER0;
static volatile ARM::NVICs::FieldISER &NVIC_ISER1 = ARM::NVICs::nvic.ISER1;
static volatile ARM::NVICs::FieldISER &NVIC_ISER2 = ARM::NVICs::nvic.ISER2;
static volatile ARM::NVICs::FieldISER &NVIC_ISER3 = ARM::NVICs::nvic.ISER3;
static volatile ARM::NVICs::FieldISER &NVIC_ISER4 = ARM::NVICs::nvic.ISER4;
static volatile ARM::NVICs::FieldISER &NVIC_ISER5 = ARM::NVICs::nvic.ISER5;
static volatile ARM::NVICs::FieldISER &NVIC_ISER6 = ARM::NVICs::nvic.ISER6;
static volatile ARM::NVICs::FieldISER &NVIC_ISER7 = ARM::NVICs::nvic.ISER7;

#define NVIC_ICER ARM::NVICs::nvic.ICER
static volatile ARM::NVICs::FieldICER &NVIC_ICER0 = ARM::NVICs::nvic.ICER0;
static volatile ARM::NVICs::FieldICER &NVIC_ICER1 = ARM::NVICs::nvic.ICER1;
static volatile ARM::NVICs::FieldICER &NVIC_ICER2 = ARM::NVICs::nvic.ICER2;
static volatile ARM::NVICs::FieldICER &NVIC_ICER3 = ARM::NVICs::nvic.ICER3;
static volatile ARM::NVICs::FieldICER &NVIC_ICER4 = ARM::NVICs::nvic.ICER4;
static volatile ARM::NVICs::FieldICER &NVIC_ICER5 = ARM::NVICs::nvic.ICER5;
static volatile ARM::NVICs::FieldICER &NVIC_ICER6 = ARM::NVICs::nvic.ICER6;
static volatile ARM::NVICs::FieldICER &NVIC_ICER7 = ARM::NVICs::nvic.ICER7;

#define NVIC_ISPR ARM::NVICs::nvic.ISPR
static volatile ARM::NVICs::FieldISPR &NVIC_ISPR0 = ARM::NVICs::nvic.ISPR0;
static volatile ARM::NVICs::FieldISPR &NVIC_ISPR1 = ARM::NVICs::nvic.ISPR1;
static volatile ARM::NVICs::FieldISPR &NVIC_ISPR2 = ARM::NVICs::nvic.ISPR2;
static volatile ARM::NVICs::FieldISPR &NVIC_ISPR3 = ARM::NVICs::nvic.ISPR3;
static volatile ARM::NVICs::FieldISPR &NVIC_ISPR4 = ARM::NVICs::nvic.ISPR4;
static volatile ARM::NVICs::FieldISPR &NVIC_ISPR5 = ARM::NVICs::nvic.ISPR5;
static volatile ARM::NVICs::FieldISPR &NVIC_ISPR6 = ARM::NVICs::nvic.ISPR6;
static volatile ARM::NVICs::FieldISPR &NVIC_ISPR7 = ARM::NVICs::nvic.ISPR7;

#define NVIC_ICPR ARM::NVICs::nvic.ICPR
static volatile ARM::NVICs::FieldICPR &NVIC_ICPR0 = ARM::NVICs::nvic.ICPR0;
static volatile ARM::NVICs::FieldICPR &NVIC_ICPR1 = ARM::NVICs::nvic.ICPR1;
static volatile ARM::NVICs::FieldICPR &NVIC_ICPR2 = ARM::NVICs::nvic.ICPR2;
static volatile ARM::NVICs::FieldICPR &NVIC_ICPR3 = ARM::NVICs::nvic.ICPR3;
static volatile ARM::NVICs::FieldICPR &NVIC_ICPR4 = ARM::NVICs::nvic.ICPR4;
static volatile ARM::NVICs::FieldICPR &NVIC_ICPR5 = ARM::NVICs::nvic.ICPR5;
static volatile ARM::NVICs::FieldICPR &NVIC_ICPR6 = ARM::NVICs::nvic.ICPR6;
static volatile ARM::NVICs::FieldICPR &NVIC_ICPR7 = ARM::NVICs::nvic.ICPR7;

#define NVIC_IABR ARM::NVICs::nvic.IABR
static volatile ARM::NVICs::FieldIABR &NVIC_IABR0 = ARM::NVICs::nvic.IABR0;
static volatile ARM::NVICs::FieldIABR &NVIC_IABR1 = ARM::NVICs::nvic.IABR1;
static volatile ARM::NVICs::FieldIABR &NVIC_IABR2 = ARM::NVICs::nvic.IABR2;
static volatile ARM::NVICs::FieldIABR &NVIC_IABR3 = ARM::NVICs::nvic.IABR3;
static volatile ARM::NVICs::FieldIABR &NVIC_IABR4 = ARM::NVICs::nvic.IABR4;
static volatile ARM::NVICs::FieldIABR &NVIC_IABR5 = ARM::NVICs::nvic.IABR5;
static volatile ARM::NVICs::FieldIABR &NVIC_IABR6 = ARM::NVICs::nvic.IABR6;
static volatile ARM::NVICs::FieldIABR &NVIC_IABR7 = ARM::NVICs::nvic.IABR7;

#define NVIC_IPR ARM::NVICs::nvic.IPR
static volatile ARM::NVICs::FieldIPR &NVIC_IPR0  = ARM::NVICs::nvic.IPR0;
static volatile ARM::NVICs::FieldIPR &NVIC_IPR1  = ARM::NVICs::nvic.IPR1;
static volatile ARM::NVICs::FieldIPR &NVIC_IPR2  = ARM::NVICs::nvic.IPR2;
static volatile ARM::NVICs::FieldIPR &NVIC_IPR3  = ARM::NVICs::nvic.IPR3;
static volatile ARM::NVICs::FieldIPR &NVIC_IPR4  = ARM::NVICs::nvic.IPR4;
static volatile ARM::NVICs::FieldIPR &NVIC_IPR5  = ARM::NVICs::nvic.IPR5;
static volatile ARM::NVICs::FieldIPR &NVIC_IPR6  = ARM::NVICs::nvic.IPR6;
static volatile ARM::NVICs::FieldIPR &NVIC_IPR7  = ARM::NVICs::nvic.IPR7;
static volatile ARM::NVICs::FieldIPR &NVIC_IPR8  = ARM::NVICs::nvic.IPR8;
static volatile ARM::NVICs::FieldIPR &NVIC_IPR9  = ARM::NVICs::nvic.IPR9;
static volatile ARM::NVICs::FieldIPR &NVIC_IPR10 = ARM::NVICs::nvic.IPR10;
static volatile ARM::NVICs::FieldIPR &NVIC_IPR11 = ARM::NVICs::nvic.IPR11;
static volatile ARM::NVICs::FieldIPR &NVIC_IPR12 = ARM::NVICs::nvic.IPR12;
static volatile ARM::NVICs::FieldIPR &NVIC_IPR13 = ARM::NVICs::nvic.IPR13;
static volatile ARM::NVICs::FieldIPR &NVIC_IPR14 = ARM::NVICs::nvic.IPR14;
static volatile ARM::NVICs::FieldIPR &NVIC_IPR15 = ARM::NVICs::nvic.IPR15;
static volatile ARM::NVICs::FieldIPR &NVIC_IPR16 = ARM::NVICs::nvic.IPR16;
static volatile ARM::NVICs::FieldIPR &NVIC_IPR17 = ARM::NVICs::nvic.IPR17;
static volatile ARM::NVICs::FieldIPR &NVIC_IPR18 = ARM::NVICs::nvic.IPR18;
static volatile ARM::NVICs::FieldIPR &NVIC_IPR19 = ARM::NVICs::nvic.IPR19;
static volatile ARM::NVICs::FieldIPR &NVIC_IPR20 = ARM::NVICs::nvic.IPR20;
static volatile ARM::NVICs::FieldIPR &NVIC_IPR21 = ARM::NVICs::nvic.IPR21;
static volatile ARM::NVICs::FieldIPR &NVIC_IPR22 = ARM::NVICs::nvic.IPR22;
static volatile ARM::NVICs::FieldIPR &NVIC_IPR23 = ARM::NVICs::nvic.IPR23;
static volatile ARM::NVICs::FieldIPR &NVIC_IPR24 = ARM::NVICs::nvic.IPR24;
static volatile ARM::NVICs::FieldIPR &NVIC_IPR25 = ARM::NVICs::nvic.IPR25;
static volatile ARM::NVICs::FieldIPR &NVIC_IPR26 = ARM::NVICs::nvic.IPR26;
static volatile ARM::NVICs::FieldIPR &NVIC_IPR27 = ARM::NVICs::nvic.IPR27;
static volatile ARM::NVICs::FieldIPR &NVIC_IPR28 = ARM::NVICs::nvic.IPR28;
static volatile ARM::NVICs::FieldIPR &NVIC_IPR29 = ARM::NVICs::nvic.IPR29;
static volatile ARM::NVICs::FieldIPR &NVIC_IPR30 = ARM::NVICs::nvic.IPR30;
static volatile ARM::NVICs::FieldIPR &NVIC_IPR31 = ARM::NVICs::nvic.IPR31;
static volatile ARM::NVICs::FieldIPR &NVIC_IPR32 = ARM::NVICs::nvic.IPR32;
static volatile ARM::NVICs::FieldIPR &NVIC_IPR33 = ARM::NVICs::nvic.IPR33;
static volatile ARM::NVICs::FieldIPR &NVIC_IPR34 = ARM::NVICs::nvic.IPR34;
static volatile ARM::NVICs::FieldIPR &NVIC_IPR35 = ARM::NVICs::nvic.IPR35;
static volatile ARM::NVICs::FieldIPR &NVIC_IPR36 = ARM::NVICs::nvic.IPR36;
static volatile ARM::NVICs::FieldIPR &NVIC_IPR37 = ARM::NVICs::nvic.IPR37;
static volatile ARM::NVICs::FieldIPR &NVIC_IPR38 = ARM::NVICs::nvic.IPR38;
static volatile ARM::NVICs::FieldIPR &NVIC_IPR39 = ARM::NVICs::nvic.IPR39;
static volatile ARM::NVICs::FieldIPR &NVIC_IPR40 = ARM::NVICs::nvic.IPR40;
static volatile ARM::NVICs::FieldIPR &NVIC_IPR41 = ARM::NVICs::nvic.IPR41;
static volatile ARM::NVICs::FieldIPR &NVIC_IPR42 = ARM::NVICs::nvic.IPR42;
static volatile ARM::NVICs::FieldIPR &NVIC_IPR43 = ARM::NVICs::nvic.IPR43;
static volatile ARM::NVICs::FieldIPR &NVIC_IPR44 = ARM::NVICs::nvic.IPR44;
static volatile ARM::NVICs::FieldIPR &NVIC_IPR45 = ARM::NVICs::nvic.IPR45;
static volatile ARM::NVICs::FieldIPR &NVIC_IPR46 = ARM::NVICs::nvic.IPR46;
static volatile ARM::NVICs::FieldIPR &NVIC_IPR47 = ARM::NVICs::nvic.IPR47;
static volatile ARM::NVICs::FieldIPR &NVIC_IPR48 = ARM::NVICs::nvic.IPR48;
static volatile ARM::NVICs::FieldIPR &NVIC_IPR49 = ARM::NVICs::nvic.IPR49;
static volatile ARM::NVICs::FieldIPR &NVIC_IPR50 = ARM::NVICs::nvic.IPR50;
static volatile ARM::NVICs::FieldIPR &NVIC_IPR51 = ARM::NVICs::nvic.IPR51;
static volatile ARM::NVICs::FieldIPR &NVIC_IPR52 = ARM::NVICs::nvic.IPR52;
static volatile ARM::NVICs::FieldIPR &NVIC_IPR53 = ARM::NVICs::nvic.IPR53;
static volatile ARM::NVICs::FieldIPR &NVIC_IPR54 = ARM::NVICs::nvic.IPR54;
static volatile ARM::NVICs::FieldIPR &NVIC_IPR55 = ARM::NVICs::nvic.IPR55;
static volatile ARM::NVICs::FieldIPR &NVIC_IPR56 = ARM::NVICs::nvic.IPR56;
static volatile ARM::NVICs::FieldIPR &NVIC_IPR57 = ARM::NVICs::nvic.IPR57;
static volatile ARM::NVICs::FieldIPR &NVIC_IPR58 = ARM::NVICs::nvic.IPR58;
static volatile ARM::NVICs::FieldIPR &NVIC_IPR59 = ARM::NVICs::nvic.IPR59;

#endif // ARM_NVICs_NVIC_hh
