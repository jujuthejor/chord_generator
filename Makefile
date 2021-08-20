CC=gcc
CFLAGS=-g -Wall

SRCDIR=src
BUILDDIR=build
BINDIR=bin

SRCS=$(wildcard $(SRCDIR)/*.c)
BINS=$(patsubst  %.c, $(BINDIR)/%.o, $(notdir $(SRCS)))
DEPS=$(BINS)
TARGET=chordgen

.PHONY: all target clean

all: $(BINS)

target: $(DEPS)
	$(CC) $(CFLAGS) $^ -o $(BUILDDIR)/$(TARGET)

$(BINDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

debug:
	$(CC) -g $(CFLAGS) $(wildcard $(SRCDIR)/*.c) -o $(BLDDIR)\$(TARGET) 

clean:
	del /Q /F $(BUILDDIR)\$(TARGET).exe $(BINDIR)\*.o