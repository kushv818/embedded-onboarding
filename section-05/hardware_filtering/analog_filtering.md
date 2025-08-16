# Introduction

The process of "analog filtering" is the use of *reactive* components to influence the spectrum of a signal.
This will document not be a comprehensive overview by any means, but should provide enough information to give you a general idea of how this works.

# Signal Spectra

When it comes to filtering, the most important question to ask is, "what am I filtering?"
To answer this question, we look to the classic example of a square wave.
To understand what filtering is, you must accept the notion that periodic signals are composed of a infinite sum of sinusoids, as described by the function's *Fourier Series*.

## Fourier Series

Any periodic function can be described as a linear combination (sum) of sinusoids.
As an example, here is a square wave centered at the ground potential:

![Diagram](figures\square_wave.JPG)

This function is described by an infinite sum of sinusoids:
$$f(x)=\lim_{a\to\infty}\sum_{n=1}^{a}\frac{\sin((2x-1)2\pi x)}{2x-1}$$
If we let $a=1$, we see that this is the first sinusoid of the square wave, or more precisely, the *first harmonic*, whose frequency is at the *fundamental frequency* of the square wave.

![Diagram](figures\square_wave_2.JPG)

Notice how the waveform evolves as we add more harmonics. If we let $a=2$:

![Diagram](figures\square_wave_3.JPG)

If we let $a=4$

![Diagram](figures\square_wave_4.JPG)

If we let $a=10$:

![Diagram](figures\square_wave_5.JPG)

From this series of graphs, it is clear to see that as $a\to\infty$, the graph better approximates a square wave.

Below is a 1 kHz square wave:

![Diagram](figures\square_wave_1kHz.png)

By applying what is known as the *Fourier Transform*, we can get a plot that tells us what sinusoids exist in a signal:

![Diagram](figures\square_wave_1kHz_bode.png)

This graph shows us what the *spectrum* of the signal is.
At each peak, it shows us the relative amplitude of each sinusoid at their respective frequencies.

