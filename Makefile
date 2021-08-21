CC=gcc
CFLAGS=-g -Wall

ifeq ($(OS), Windows_NT)
	RM=del /Q /F
else
	RM=rm -r
endif

SRCDIR=src
BUILDDIR=build
BINDIR=bin

SRCS=$(wildcard $(SRCDIR)/*.c)
BINS=$(patsubst  %.c, $(BINDIR)/%.o, $(notdir $(SRCS)))
DEPS=$(BINS)
TARGET=chordgen

ifeq ($(OS), Windows_NT)
	RMTARGET=$(BUILDDIR)\$(TARGET).exe $(BINDIR)\*.o
else
	RMTARGET=$(BUILDDIR)/$(TARGET) $(BINDIR)/*.o
endif 

.PHONY: all target clean

all: $(BINS)

target: $(DEPS)
	$(CC) $(CFLAGS) $^ -o $(BUILDDIR)/$(TARGET)

$(BINDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(RMTARGET)