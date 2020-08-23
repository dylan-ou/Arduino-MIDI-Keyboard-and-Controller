# Arduino-MIDI-Keyboard-and-Controller

This is the Arduino MIDI Keyboard and Controller developed for CS 362: 
Computer Design at the University of Illinois at Chicago. This project
was the main project for the class and it was developed along with Rohan Verma.

<img src="https://user-images.githubusercontent.com/52469951/88852378-d28c9080-d1b3-11ea-9d00-8db7a4902413.JPG" width=400>

The goal of this project was to develop our own Arduino project. Given that I make music
as a hobby, I came up with the idea of a MIDI keyboard and controller. In the end,
I developed the MIDI keyboard and Rohan included the LCD screen to print out the current note being played.
Part of how it works is that the Arduino Mega 2560 (or the Elegoo Mega 2560 in our case) does not have native MIDI communication
with USB, so we had to find workarounds. The solution was using two programs; the first is called 
[Hairless MIDI](https://projectgus.github.io/hairless-midiserial/). It is required to connect
serial devices to send and receive MIDI signals. The second program is 
called [loopMIDI](https://www.tobias-erichsen.de/software/loopmidi.html). This program is needed
because the Digital Audio Workstation (DAW) would not be able to see the Arduino device as a MIDI device.

The keyboard includes 12 notes to play, two buttons to change the current octave, a joystick to control
different paramters in the DAW, and an LCD screen to display the current not being played.
