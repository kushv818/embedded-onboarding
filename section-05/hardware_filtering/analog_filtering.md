# Introduction

The purpose of filtering a signal is to get rid of noise.
The process of "analog filtering" is the use of *reactive* components to influence the spectrum of a signal (and thus get rid of noise).
This will document not be a comprehensive overview by any means, but should provide enough information to give you a general idea of how this works.

# Signal Spectra

When it comes to filtering, the most important question to ask is, "what am I filtering?"
To answer this question, we look to the classic example of a square wave.
To understand what filtering is, you must accept the notion that periodic signals are composed of a infinite sum of sinusoids, as described by the function's *Fourier Series*.

## Fourier Series

The *Fourier Series* is a specific mathematical representation of a periodic function.

Any periodic function can be described as a linear combination (sum) of sinusoids.
As an example, here is a square wave centered at the ground potential:

![Diagram](figures\square_wave.JPG)

This function is described by an infinite sum of sinusoids:
$$f(x)=\lim_{a\to\infty}\sum_{n=1}^{a}\frac{\sin((2x-1)2\pi x)}{2x-1}$$

This can be more simply written as:
$$f(x)=\lim_{a\to\infty}\sum_{n=1}^{a}\frac{1}{n}\sin(2\pi nx)$$
Where $n$ is a positive odd integer.

If we let $a=1$, we see that this is the first sinusoid of the square wave, or more precisely, the *first harmonic*, whose frequency is at the *fundamental frequency* of the square wave.

![Diagram](figures\square_wave_2.JPG)

Notice how the waveform evolves as we add more harmonics. If we let $a=2$:

![Diagram](figures\square_wave_3.JPG)

If we let $a=4$:

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
You may also think of each peak as a term in the fourier series, the amplitude and frequency of which will correspond to the graph.

# Filters and Frequency Response

Now that you have some understanding of what the spectrum of a signal is, we can scratch the surface of filtering using analog devices.

## RC Low Pass Filters

The purpose of filtering is to rid a signal of unwanted noise. 
One of the most common types of filters is the RC *low pass* filter. 
The filter is an *RC* filter because it uses exclusively resistors and capacitors.
The filter is called a *low pass* filter because it only allows low frequency energy to pass through it.

Here is an example of a low pass filter drawn up in LT Spice:

![Diagram](figures\lpf.JPG)

The voltage source represents the input of the filter, and the connection point between R2 and C2 is the output of the filter.

## Bode Plots

We study the performance of filters using a *Bode Plot* as shown below. This bode plot is graphed when LT Spice simulates the circuit presented previously.

![Diagram](figures\lpf_bode.JPG)

The bode plot is a representation of the filter's *frequency response*. That is, how the output compares to the input as a function of frequency. The is also commonly referred to as the spectrum of the *impulse response*.

As before, the horizontal axis is frequency. The vertical axis however, is in decibels (dB). The reasons for this and what it is will become apparent later. There are two curves in the graph. The solid line represents the *magnitude*, and the faded line represents the *phase* response.
For our purposes, we will only focus on the magnitude response of a filter.

At the low end of the spectrum, we see that the magnitude plot shows 0 dB.
This means the signal is not *attenuated* by the filter, or that is is passed through without a drop in amplitude.
As the frequency increases beyond a critical point (-3 dBs), the signal becomes *attenuated* (the amplitude is reduced).
The higher the frequency, the more strongly attenuated it becomes when it tries to pass through the filter.

## Transfer Functions and Decibels

The bode plot is derived from the application of kirchhoff's laws.
This derivation is outside the scope of this work, but the point of the mathematics is to arrive at an expression for the output voltage $V_{out}$ and the input voltage $V_{in}$.

Recall that the purpose of the bode plot is to compare the input to the output as a function of frequency. This gives rise to the concept of the *transfer function* ($H$), which is defined as the ratio of the output voltage to the input voltage:

$$H=\frac{V_{out}}{V_{in}}$$

The magnitude response is written in dBs, and is defined as:

$$20\log_{10}|H|$$

Note that when the input is equal to the output, $|H|=1$, and $20\log_{10}|H|=0$ dB.

The transfer function $H$ is defined in the frequency domain, which means it is a function of frequency. It is also a complex number, which is why it has both a magnitude and a phase, though we will not need this information in this work.
