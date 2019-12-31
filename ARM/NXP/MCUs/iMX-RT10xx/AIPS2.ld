/*
 * © 2019 John Adriaan. Licensed under the "3-clause BSD License"
 *
 * \file ARM/NXP/MCUs/iMX-RT10xx/AHB2.ld
 *
 * Included by `iMX-RT10xx.ld` to define addresses for AIPS2 peripherals
 */

SECTIONS
{

  /* ARM IP Bus 2 section */
  .AIPS2 (NOLOAD) :
  {
    _ZN3ARM3NXP5GPIOs5portAE = . + 0x00000000; /* ARM::NXP::GPIOs::portA */
    _ZN3ARM3NXP5GPIOs5portBE = . + 0x00000400; /* ARM::NXP::GPIOs::portB */
    _ZN3ARM3NXP5GPIOs5portCE = . + 0x00000800; /* ARM::NXP::GPIOs::portC */

    _ZN3ARM3NXP5GPIOs5portHE = . + 0x00001C00; /* ARM::NXP::GPIOs::portH */

    _ZN3ARM3NXP4ADCs3adcE    = . + 0x08040000; /* ARM::NXP::ADCs::adc */

    _ZN3ARM3NXP4RNGs3rngE    = . + 0x08060800; /* ARM::NXP::RNGs::rng */
  } >AIPS2

} /* SECTIONS */
