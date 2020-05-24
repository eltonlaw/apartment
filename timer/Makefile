.PHONY: all build flash programmer

CC = avr-gcc
PART_NO = m328p
MMCU = atmega328

F_CPU = 
# Might be able to increase from default to program it a bit faster, look at datasheet
BAUD = 
PORT = /dev/ttyACM0
FILE = main
CFLAGS = -g -Os -Wall -mcall-prologues
PROGRAMMER_ID = avrispv2

build: $(FILE).hex

flash: build
	avrdude -c $(PROGRAMMER_ID) -p $(PART_NO) -P $(PORT) -e -v -U flash:w:$(FILE).hex

$(FILE).o: $(FILE).c
	$(CC) $(CFLAGS) -mmcu=$(MMCU) -c -o $(FILE).o $(FILE).c

$(FILE).obj: $(FILE).o
	$(CC) $(CFLAGS) -mmcu=$(MMCU) $(FILE).o -o $(FILE).obj

$(FILE).hex: $(FILE).obj
	avr-objcopy -R .eeprom -O ihex $(FILE).obj $(FILE).hex

ccls:
	bear make

clean:
	rm -f *.elf *.obj *.hex *.o *.s

# Check connection to programmer okay
progconn:
	avrdude -vvv -p $(PART_NO) -P $(PORT) -c avrispv2
