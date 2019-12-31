// © 2019 John Adriaan. Licensed under the "3-clause BSD License"
///
/// \file ARM/NXP/Flash/FCB.cc
///
/// This file defines and instantiates the Flash Control Block at a known address.
/// The FCB is used by the i.MX RT10xx to best configure the Flash for use.
/// Note that this is completely self-contained - no external reference needs
/// to be made to this module.
///

#include <ARM/NXP/NXP.hh>

#include <ARM/ISRs.hh>

extern const byte _FLASH[];
extern const byte _FLASH_Size; ///< Linker variable: Use address, not contents

namespace ARM::NXP::Flash {

	extern const struct BootData bootData;

	/// Image Vector Table
	struct IVT {

		struct PACKED Header {

			enum Versions : byte {
				Version40 = 0x40,
				Version41 = 0x41,
				Version42 = 0x42,
				Version43 = 0x43,
				Version44 = 0x44
			}; // Versions

			union Length {
				struct {
					byte hi;
					byte lo;
				}; // struct
				word length; ///< MSB!
			}; // Length
			static_assert(sizeof(Length)==2, "Incorrect Length size");

			byte     tag     = 0xD1;                           ///< Indicates valid Header
			Length   length  = { { .hi=0, .lo=sizeof(IVT) } }; ///< Length of header - in MSB!
			Versions version;                                  ///< Header format version
		}; // Header
		static_assert(sizeof(Header)==sizeof(unsigned), "Incorrect Header size");

		typedef void Entry();

		/// Device Configuration Data
		struct DCD { /// TODO
		}; // DCD

		/// Command Sequence File
		struct CSF { /// TODO
		}; // CSF

		      Header    header    = { .version = Header::Version41 }; ///< IVT Header
		const Entry    *entry     = nullptr; ///< Entry point
		      unsigned  reserved1 = 0;
		const DCD      *dcd       = nullptr; ///< Device Configuration Data
		const BootData *bootData  = nullptr; ///< Boot Data
		const IVT      *self      = nullptr; ///< This IVT
		const CSF      *csf       = nullptr; ///< Command Sequence File
		      unsigned  reserved2 = 0;
	}; // IVT
	static_assert(sizeof(IVT)==32, "Incorrect IVT size");

	struct BootData {
		const void    *start = nullptr; ///< Start of Boot Flash
		      unsigned length = 0;      ///< Length of Boot Flash
		      unsigned plugin = 0;
	}; // BootData
	static_assert(sizeof(BootData)==12, "Incorrect BootData size");

	SECTION(".IVT")
	const IVT ivt { .entry = &ARM::ISRs::Reset, .bootData = &bootData, .self = &ivt };

	SECTION(".IVT")
	const BootData bootData { .start = &_FLASH, .length = (unsigned)&_FLASH_Size };

} // namespace ARM::NXP::Flash
