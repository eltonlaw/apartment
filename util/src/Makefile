INCLUDE_DIR =../include
HEADERS=$(wildcard $(INCLUDE_DIR)/*.h)
SOURCES=$(wildcard *.c)
OBJECTS=$(SOURCES:.c=.o)

CC=gcc
CFLAGS=-g -Wall -I$(INCLUDE_DIR)
LIBS=-lm

TARGET_DIR=../target

%.o: %.c $(HEADERS)
	$(CC) -c -o $@ $< $(CFLAGS)

build: $(OBJECTS)
	cp *.o $(TARGET_DIR)/

.PHONY: clean
clean:
	rm -f *.o
