HEADERS = scan.h http.h
OBJECTS = main.o scan.o http.o

INCLUDE_DIR =../include
CC=gcc
CFLAGS=-g -I$(INCLUDE_DIR)

TARGET_DIR=../target

LIBS=-lm -lpcap -lcurl

_HEADERS = $(patsubst %,$(INCLUDE_DIR)/%,$(HEADERS))

_OBJECTS = $(patsubst %,$(TARGET_DIR)/%,$(OBJECTS))

$(TARGET_DIR)/%.o: %.c $(_HEADERS)
	$(CC) -c -o $@ $< $(CFLAGS)

build: $(_OBJECTS)
	mkdir -p $(TARGET_DIR)
	$(CC) -o ../$(BINARY_NAME) $^ $(CFLAGS) $(LIBS)

.PHONY: clean
clean:
	rm -f $(TARGET_DIR)/*.o *~ ../$(BINARY_NAME)
