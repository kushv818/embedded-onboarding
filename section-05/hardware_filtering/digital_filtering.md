# Introduction

This document assumes you have read `analog_filtering.md`.
Digital filtering is a conceptual extension of analog filtering, since it requires a stronger understanding of the calculus drives the process of filtering.

Digital filtering is the process of filtering in the *digital domain*.
The general idea is to sample a voltage with an ADC through time, then mathematically process it to filter out noise.
The purpose of filtering in the digital domain is to build filters that are not possible to build with analog components.

Digital filters can be built to have special properties that are advantageous to the application.
These properties include:
 - Linear phase response
 - Ideal or arbitrary magnitude response

# Mathematical Basis for Digital Filtering

Before diving into the specific applications on the DFR team, some time needs to be spent understanding what is happening mathematically.
