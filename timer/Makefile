.PHONY: all build flash programmer

TARGET = main
INCLUDE_DIR=include/
SOURCES=$(wildcard *.c $(LIBDIR)/*.c)
HEADERS=$(wildcard $(INCLUDE_DIR)/*.h $(LIBDIR)/*.h)
CFLAGS = -g -Os -std=gnu99 -Wall -mcall-prologues -I$(INCLUDE_DIR)
OBJECTS=$(SOURCES:.c=.o)
## MCU specific
PART_NO = m328p
MMCU = atmega328
F_CPU = 8000000UL
BAUD = 
PORT = /dev/ttyACM0
## Toolchain
CC = avr-gcc
OBJCOPY = avr-objcopy
OBJDUMP = avr-objdump
AVRSIZE = avr-size
AVRDUDE = avrdude
## Flash
PROGRAMMER_ID = avrispv2

######## --------------- compile  --------------- ########
build: $(TARGET).hex

%.o: %.c $(HEADERS)
	$(CC) -mmcu=$(MMCU) -c -o $@ $< $(CFLAGS)

%.obj: $(OBJECTS)
	$(CC) $(CFLAGS) -mmcu=$(MMCU) $^ -o $@

%.hex: %.obj
	$(OBJCOPY) -R .eeprom -O ihex $< $@

######## --------------- flash --------------- ########
## Check connection to programmer okay
progconn:
	$(AVRDUDE)-vvv -p $(PART_NO) -P $(PORT) -c $(PROGRAMMER_ID)

flash: build
	$(AVRDUDE) -c $(PROGRAMMER_ID) -p $(PART_NO) -P $(PORT) -e -v -U flash:w:$(TARGET).hex

######## --------------- dev tooling --------------- ########
ccls:
	bear make

env:
	@echo "SOURCES:" $(SOURCES)
	@echo "OBJECTS:" $(OBJECTS)
	@echo "HEADERS:" $(HEADERS)

clean:
	rm -f *.elf *.obj *.hex *.o *.s
