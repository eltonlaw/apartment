# toy-car

The chip used is the ATmega328P, the microcontroller used on the Arduino Uno and Arduino Nano.

## Software Dependencies

### Installing on ArchLinux

Libraries required to cross compile:
    
    sudo pacman -S avr-gcc avrdude

Optional, an Arduino UNO was used as the hardware programmer.

    sudo pacman -S arduino

## Notes

The Makefile assumes that the first USB device you plug in is the programmer. For a quick hack, unplug everything, unplug everything, plug in the programmer first and then plug everything else back in.
