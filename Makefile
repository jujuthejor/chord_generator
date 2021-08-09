CC=gcc
CFLAGS=-g -Wall
TARGET=chordgen

SRCDIR=src
BLDDIR=build

BIN=chordgen

all: $(BIN)

%: $(SRCDIR)\%.c
	$(CC) $(CFLAGS) $< -o $(BLDDIR)\$@

debug:
	$(CC) -g $(CFLAGS) $(wildcard $(SRCDIR)/*.c) -o $(BLDDIR)\$(TARGET) 

clean:
	rm $(BLDDIR)\$(TARGET).exe