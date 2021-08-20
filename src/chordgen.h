#ifndef CHORDGEN_H
#define CHORDGEN_H

typedef enum {
    CHORD_MAJ,
    CHORD_MIN,
    CHORD_DIM,
    CHORD_AUG,
    CHORD_MAJ7,
    CHORD_MIN7,
    CHORD_DOM7,
    CHORD_SUS2,
    CHORD_SUS4,
    CHORD_ENUM_SIZE
} chord_t;

typedef enum {
    CHORD_CHORD_ONLY = 1,
    CHORD_NOTES_ONLY
} flag_t;

extern const char *NOTES[];
extern const int NUM_NOTES;

void listChords(int root_i);
void printChord(int root_i, chord_t chord, flag_t flag);

#endif