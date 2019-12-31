# Linker

[TOC]

## Introduction
This project has a number of disparate modules that need to coöperate together
to produce the final executable. And those modules have been written
generically&mdash;they don't know how the other modules will use them. So
instead, each defines a number of linker symbols, and expect the _user_ of the
module to "alias" their symbols against the modules expectations.

## Interrupt Service Routines (ISRs)
The most thorough example of this is as a result of the design of the ARM&reg;
Cortex&copy; M core. It defines an Interrupt Vector Table, with the first few
entries completely invariant. Where those entries _vector_ to cannot be defined
by the ARM library&mdash;that's a function of the 