/*
 * © 2019 John Adriaan. Licensed under the "3-clause BSD License"
 *
 * \file ARM/NXP/MCUs/iMX-RT10xx/APB2.ld
 *
 * Included by `iMX-RT10xx.ld` to define addresses for the GPIO2 peripheral
 */

SECTIONS
{

  /* General Purpose Input/Output 2 section */
  .GPIO2 (NOLOAD) :
  {
    _ZN3ARM3NXP5GPIOs5gpio2E       = . + 0x0000; /* ARM::NXP::GPIOs::gpio2 */
  } >GPIO2
  
} /* SECTIONS */
