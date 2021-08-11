CC=gcc
CFLAGS=-g -Wall

SRCDIR=src
BUILDDIR=build
BINDIR=bin

BINS=main.o chordgen.o
DEPS=$(BINDIR)/main.o $(BINDIR)/chordgen.o
TARGET=chordgen

all: $(BINS)

target: $(DEPS)
	$(CC) $(CFLAGS) $^ -o $(BUILDDIR)/$(TARGET)

%.o: $(SRCDIR)\%.c
	$(CC) $(CFLAGS) -c $< -o $(BINDIR)/$@

debug:
	$(CC) -g $(CFLAGS) $(wildcard $(SRCDIR)/*.c) -o $(BLDDIR)\$(TARGET) 

clean:
	del /Q /F $(BUILDDIR)\$(TARGET).exe $(BINDIR)\*.o