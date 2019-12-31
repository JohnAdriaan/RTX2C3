# RTX&sup2;C&sup3;
(i.MX) RT1010 (with W5500) for Crossover Code Challenge

[TOC]

## Introduction

[Test](Test.md)

## Installation

## Project structure
I think hierarchically. Maybe that's why I like C++ so much! I want to be able
to categorise capabilities, modules, functions and definitions so that I can
_find_ them again later! I also want to maintain as loosely coupled an
infrastructure as possible, so that I can "drop in" a different implementation
if necessary.

The easiest way to do this is to 

### Linker definitions
[Main entry](Linker.md)

It may seem odd to put this section first, since the link stage of a build is
practically the last thing that is performed. But another way of thinking about
it is that it "links the whole project together" - and _that's_ exactly what
this project leverages. To maintain the different "silos" of the different
modules, _something_ needs to link this with that as needed to make the whole.

I've used some fairly sophisticated linker functionality&mdash;which has
triggered bugs in some surprised support programs. For example, Code Analysis
reports "Unreferenced variable" problems: they're referenced all right, but in
ways that `CodAn` doesn't understand, while `ld` does exactly what I want.

### C/C++ Run Time
[Main entry](/CRT/CRT.md)

The C/C++ compiler provides a number of modules for a program to use&mdash;and
some others that it uses "behind the scenes". The problem is that they're
fairly opaque, therefore difficult to debug. For example, did you know that
`rand()` calls `malloc()`? And if you're trying to find a memory allocation bug,
it'd be nice to put in hooks to help.

This project doesn't use many CRT functions&mdash;but what it does use I've
written myself.

### General
[Main entry](/General/General.md)

### ARM
[Main entry](/ARM/ARM.md)

#### NXP
[Main entry](/ARM/NXP/NXP.md)

### WIZnet
[Main entry](/WIZnet/WIZnet.md)

### App
[Main entry](/App/App.md)

