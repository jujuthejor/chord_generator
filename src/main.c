#include<stdio.h>
#include<stdlib.h>

#include "chordgen.h"

int main (void)
{
    listChords(5);
    for(chord_t i = 0; i < CHORD_ENUM_SIZE; i++) {
        printChord(3, i);
    }
    return 0;
}