/*
 * © 2019 John Adriaan. Licensed under the "3-clause BSD License"
 *
 * \file ARM/NXP/MCUs/iMX-RT10xx/AIPS1.ld
 *
 * Included by `iMX-RT10xx.ld` to define addresses for AIPS1 peripherals
 */

SECTIONS
{

  /* ARM IP Bus 1 section */
  .AIPS1 (NOLOAD) :
  {
    _ZN3ARM3NXP4AIPSs4aips1E         = . + 0x7C000; /* ARM::NXP::AIPSs::aips1 */

    _ZN3ARM3NXP5DCDCss4dcdcE         = . + 0x80000; /* ARM::NXP::DCDCs::dcdc */

    _ZN3ARM3NXP4PITs3pitE            = . + 0x84000; /* ARM::NXP::PITs::pit */

    _ZN3ARM3NXP4ADCs3etcE            = . + 0x88000; /* ARM::NXP::ADCs::etc */
    _ZN3ARM3NXP4ADCs4adc1E           = . + 0xC4000; /* ARM::NXP::ADCs::adc1 */

    _ZN3ARM3NXP4AOIs3aoiE            = . + 0x94000; /* ARM::NXP::AOIs::aoi */

    _ZN3ARM3NXP5XBARs3xbar1E         = . + 0x98000; /* ARM::NXP::XBARs::xbar1 */

    _ZN3ARM3NXP8FlexSPIs7flexSPIE    = . + 0xA0000; /* ARM::NXP::FlexSPIs::flexSPI */

    _ZN3ARM3NXP5SNVSs2hpE            = . + 0xD4000; /* ARM::NXP::SNVSs::hp */
    _ZN3ARM3NXP5SNVSs3gprE           = . + 0xA4000; /* ARM::NXP::SNVSs::gpr */
    _ZN3ARM3NXP5SNVSs4snvsE          = . + 0xA8000; /* ARM::NXP::SNVSs::snvs */

    _ZN3ARM3NXP5IOMux3gprE           = . + 0xAC000; /* ARM::NXP::IOMux::gpr */

    _ZN3ARM3NXP8FlexRAMs7flexRAME    = . + 0xB0000; /* ARM::NXP::FlexRAMs::flexRAM */

    _ZN3ARM3NXP6Timers4EWMs3ewmE     = . + 0xB4000; /* ARM::NXP::Timers::EWMs::ewm */
    
    _ZN3ARM3NXP6Timers5WDogs5wDog1E  = . + 0xB8000; /* ARM::NXP::Timers::WDogs::wDog1 */
    _ZN3ARM3NXP6Timers5WDogs5wDog2E  = . + 0xD0000; /* ARM::NXP::Timers::WDogs::wDog2 */
    _ZN3ARM3NXP6Timers5WDogs5wDog3E  = . + 0xBC000; /* ARM::NXP::Timers::WDogs::wDog3 */
    _ZN3ARM3NXP6Timers5WDogs6rtwDogE = . + 0xBC000; /* ARM::NXP::Timers::WDogs::rtwDog */

    _ZN3ARM3NXP5GPIOs5gpio5E         = . + 0xC0000; /* ARM::NXP::GPIOs::gpio5 */

    _ZN3ARM3NXP4RNGs3trngE           = . + 0xCC000; /* ARM::NXP::RNGs::trng */

    _ZN3ARM3NXP6Clocks6analogE       = . + 0xD8000; /* ARM::NXP::Clocks::analog */
    _ZN3ARM3NXP6Clocks3ccmE          = . + 0xFC000; /* ARM::NXP::Clocks::ccm */

    _ZN3ARM3NXP4CSUs4csuE            = . + 0xDC000; /* ARM::NXP::CSUs::csu */

  } >AIPS1

} /* SECTIONS */

