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

namespace ARM::NXP::Flash {

	/// FlexSPI Configuration Block
	struct FlexSPIConfig {

		struct Version {
				  byte bugfix;
				  byte minor;
				  byte major;
			const char v = 'V';
		}; // Version
		static_assert(sizeof(Version)==4, "Incorrect Version size");

		enum SampleClkSrcs : byte {
			Internal = 0,
			Loopback = 1,
			FlashDQS = 3
		}; // SampleClkSrcs

		struct LUTs {
				  byte number;          ///< Number of LUT sequences
				  byte index;           ///< Starting LUT index
			const word x2     = Rsvd16; ///< Reserved
		}; // LUTs
		static_assert(sizeof(LUTs)==4, "Incorrect LUTs size");

		struct MiscOptions {
			bit diffClkEnable            :  1;
			unsigned                     :  1;
			bit parallelModeEnable       :  1;
			bit wordAddressableEnable    :  1;
			bit safeConfigFreqEnable     :  1;
			bit padSettingOverrideEnable :  1;
			bit ddrModeEnable            :  1;
			unsigned                     :  2;
			bit secondDQSPinMux          :  1;
			unsigned                     : 22;
			unsigned                     :  0;
		}; // MiscOptions
		static_assert(sizeof(MiscOptions)==sizeof(unsigned), "Incorrect MiscOptions size");

		enum DeviceTypes : byte {
			DeviceUnknown = 0, ///< *** Examples have this value
			SerialNOR     = 1  ///< *** Documents show this is only valid option
		}; // DeviceTypes

		enum Pads : byte {
			SinglePad = 1,
			DualPads  = 2,
			QuadPads  = 4,
			OctalPads = 8
		}; // Pads

		enum ClockFreqs : byte {
			Freq30MHz  = 1,
			Freq50MHz  = 2,
			Freq60MHz  = 3,
			Freq75MHz  = 4,
			Freq80MHz  = 5,
			Freq100MHz = 6,
			Freq120MHz = 7,
			Freq133MHz = 8
		}; // ClockFreqs

		struct ValidTimes {
			word dllA;
			word dllB;
		}; // ValidTimes
		static_assert(sizeof(ValidTimes)==sizeof(unsigned), "Incorrect ValidTimes size");

		enum Busys : word {
			Busy1 = 0, ///< 0: "Busy Bit==1 when busy
			Busy0 = 1  ///< 1: "Busy Bit==0 when busy
		}; // Busys

		enum LUTPads {
			Pad1 = 0,
			Pad2 = 1,
			Pad4 = 2,
			Pad8 = 3
		}; // LUTPads

		enum Instructions {
			STOP  = 0,
			JMP   = 9,

			CMD   = 1,
			ADDR  = 2,
			DUMMY = 3,
			MODE  = 4,
			MODE2 = 5,
			MODE4 = 6,
			READ  = 7,
			WRITE = 8,

			CMD_DDR   = 0x11,
			ADDR_DDR  = 0x0A,
			MODE_DDR  = 0x0B,
			MODE2_DDR = 0x0C,
			MODE4_DDR = 0x0D,
			READ_DDR  = 0x0E,
			WRITE_DDR = 0x0F
		}; // Instructions

		struct LUTCommand {
			byte         operand     : 8;
			LUTPads      pad         : 2;
			Instructions instruction : 6;
			word                     : 0;
		}; // LUTCommand
		static_assert(sizeof(LUTCommand)==2, "Incorrect LUTCommand size");

		typedef LUTCommand LUTSequence[8];
		static_assert(sizeof(LUTSequence)==16, "Incorrect LUTCommand size");

		const char          tag[4]                 = { 'F', 'C', 'F', 'B' };  ///< Tag to identify block
			  Version       version                = { .bugfix=0, .minor=4, .major=1 };
		const unsigned      x008                   = Rsvd32;                  ///< Reserved
			  SampleClkSrcs readSampleClkSrc       = Loopback;                ///< Sample DQS Pad
			  byte          csHoldTime             = 3;                       ///< Column Select Hold Time. Recommended value
			  byte          csSetupTime            = 3;                       ///< Column Select Setup Time. Recommended value
			  byte          columnAddressWidth     = 0;                       ///< Not HyperFlash
			  byte          deviceModeCfgEnable    = No;                      ///< Don't enable Config
		const byte          x011                   = Rsvd8;                   ///< Reserved
			  word          waitTimeCfgCommands    = 0;                       ///< in 100us. Note v1.1.0 minimum
			  LUTs          deviceModeSeq          = { .number=0, .index=0 };
			  unsigned      deviceModeArg          = 0;                       ///< `deviceModeCfgEnable` must be `1`
			  byte          configCmdEnable        = No;
		const byte          x01D[3]                = { Rsvd8, Rsvd8, Rsvd8 }; ///< Reserved
			  unsigned      configCmdSeqs[3]       = { 0, 0, 0 };
		const unsigned      x02C                   = Rsvd8;                   ///< Reserved
			  unsigned      cfgCmdArgs[3]          = { 0, 0, 0 };
		const unsigned      x03C                   = Rsvd8;                   ///< Reserved
		      MiscOptions   controllerMiscOption   = { };
		      DeviceTypes   deviceType             = SerialNOR;
		      Pads          sflashPadType          = QuadPads;
		      ClockFreqs    serialClkFreq          = Freq100MHz;
		      byte          lutCustomSeqEnable     = No;
		const unsigned      x048[2]                = { Rsvd32, Rsvd32 };
		      unsigned      sflashA1Size           = 0x0100'0000;
		      unsigned      sflashA2Size           = 0x0000'0000;
		      unsigned      sflashB1Size           = 0x0000'0000;
		      unsigned      sflashB2Size           = 0x0000'0000;
			  unsigned      csPadSettingOverride   = No;
			  unsigned      sclkPadSettingOverride = No;
			  unsigned      dataPadSettingOverride = No;
			  unsigned      dqsPadSettingOverride  = No;
			  unsigned      timeoutInMs            = 0;
			  unsigned      commandInterval        = 0;  ///< in ns
			  ValidTimes    dataValidTimes         = { .dllA = 0, .dllB = 0 };
			  word          busyOffset             = 0;  ///< Valid range: 0-31
			  Busys         busyBitPolarity        = Busy1;
			  LUTSequence   lookupTable[16]        = { { { .operand = 0xEB, .pad = Pad1, .instruction = CMD },       ///< 4xI/O, READ
					                                     { .operand =   24, .pad = Pad4, .instruction = ADDR },      ///< 24 bits
														 { .operand =    6, .pad = Pad4, .instruction = MODE2_DDR }, ///< 6 Dummy cycles
//														 { .operand =    0, .pad = Pad1, .instruction = STOP } } };  ///< And STOP
	/*** This final command could simply be STOP? ***/   { .operand = 1<<2, .pad = Pad4, .instruction = JMP } } };   ///< JMP LUT[1]
			  LUTSequence   lutCustomSeq[3]        = { };
			  unsigned      reserved[4]            = { Rsvd32, Rsvd32, Rsvd32, Rsvd32 };
	}; // FlexSPIConfig
	static_assert(sizeof(FlexSPIConfig)==0x1C0, "Incorrect FlexSPIConfig size");

	struct SerialNORConfig {

		enum ClockFreqs {
			ClockUnchanged = 0,
			Clock30MHz     = 1,
			Clock50MHz     = 2,
			Clock60MHz     = 3,
			Clock75MHz     = 4,
			Clock80MHz     = 5,
			Clock100MHz    = 6,
			Clock133MHz    = 7
		}; // ClockFreqs

		FlexSPIConfig fcb = { };
		unsigned      pageSize             = 0x0100;
		unsigned      sectorSize           = 0x1000;
		ClockFreqs    ipCmdSerialClockFreq = ClockUnchanged;
		unsigned      reserved[13]         = { Rsvd32, Rsvd32, Rsvd32, Rsvd32, Rsvd32, Rsvd32, Rsvd32,
				                               Rsvd32, Rsvd32, Rsvd32, Rsvd32, Rsvd32, Rsvd32 };
	}; // SerialNORConfigBlock
	static_assert(sizeof(SerialNORConfig)==0x200, "Incorrect SerialNORConfig size");

	SECTION(".FCB")
	const SerialNORConfig serialNORConfig;

} // namespace ARM::NXP::Flash
