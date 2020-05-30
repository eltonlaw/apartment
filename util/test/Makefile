INCLUDE_DIR =../include
HEADERS=$(wildcard $(INCLUDE_DIR)/*.h)
SOURCES=$(wildcard *.c)
OBJECTS=$(SOURCES:.c=.o)

CC=gcc
CFLAGS=-g -Wall -I$(INCLUDE_DIR)
LIBS = -l unity

TARGET_DIR=../target

test:
	$(CC) -o test_util.out test_util.c $(TARGET_DIR)/util.o $(LIBS) $(CFLAGS) && ./test_util.out

build: $(OBJECTS)

%.o: %.c $(HEADERS)
	$(CC) -c $@ $< $(CFLAGS)

.PHONY: clean
clean:
	rm -f *.o
