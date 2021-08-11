#include<stdio.h>
#include<stdlib.h>

#include "chordgen.h"

int main (void)
{
    listChords(5);
    for(chord_t i = 0; i < CHORD_ENUM_SIZE; i++) {
        printChord(3, i, 0);
    }

    printChord(4, CHORD_MAJ, CHORD_NO_NOTES);
    printChord(2, CHORD_MAJ7, CHORD_NO_NOTES);
    printChord(0, CHORD_SUS4, CHORD_NO_NOTES);
    printChord(6, CHORD_MAJ, CHORD_NO_NOTES);
    printChord(9, CHORD_MAJ, CHORD_NO_NOTES);
    return 0;
}