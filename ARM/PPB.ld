/*
 * © 2019 John Adriaan. Licensed under the "3-clause BSD License"
 *
 * \file ARM/PPB.ld
 *
 * Included by `ARM.ld` to define addresses for PPB peripherals
 */

SECTIONS
{

  /* Private Peripheral Bus section */
  .PPB (NOLOAD) :
  {
    _ZN3ARM4SCBs5actlrE       = . + 0x0000E008; /* ARM::SCBs::actlr */
    _ZN3ARM8SysTicks7sysTickE = . + 0x0000E010; /* ARM::SysTicks::sysTick */
    _ZN3ARM5NVICs4nvicE       = . + 0x0000E100; /* ARM::NVICs::nvic */
    _ZN3ARM4SCBs3scbE         = . + 0x0000ED00; /* ARM::SCBs::scb */
    _ZN3ARM4MPUs3mpuE         = . + 0x0000ED90; /* ARM::MPUs::mpu */
    _ZN3ARM5NVICs4stirE       = . + 0x0000EF00; /* ARM::NVICs::stir */
    _ZN3ARM4FPUs3fpuE         = . + 0x0000EF30; /* ARM::FPUs::fpu */
  } >PPB

} /* SECTIONS */
