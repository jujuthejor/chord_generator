#include<stdio.h>

#include "chordgen.h"

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
} chord_type;

int major[] = {0, 4, 7};
int minor[] = {0, 3, 7};
int dim[] = {0, 3, 6};
int aug[] = {0, 4, 8};
int maj7[] = {0, 4, 7, 11};
int min7[] = {0, 3, 7, 10};
int dom7[] = {0, 4, 7, 10};
int sus2[] = {0, 2, 7};
int sus4[] = {0, 5, 7};

// Make sure order of arrays correspond
// to the order of the chord they represent in the enum
int *chords[] = {
    major,
    minor,
    dim,
    aug,
    maj7,
    min7,
    dom7,
    sus2,
    sus4
};
const int CHORDS_ARR_SIZE = sizeof(chords)/sizeof(chords[0]);

// Again, make sure order of sizes corresponds
// to the array they describe
const int chords_sizes[] = {
    sizeof(major)/sizeof(major[0]),
    sizeof(minor)/sizeof(minor[0]),
    sizeof(dim)/sizeof(dim[0]),
    sizeof(aug)/sizeof(aug[0]),
    sizeof(maj7)/sizeof(maj7[0]),
    sizeof(min7)/sizeof(min7[0]),
    sizeof(dom7)/sizeof(dom7[0]),
    sizeof(sus2)/sizeof(sus2[0]),
    sizeof(sus4)/sizeof(sus4[0]),
};

char *label[] = {
    "maj",
    "min",
    "dim",
    "aug",
    "maj7",
    "min7",
    "dim7",
    "sus2",
    "sus4"
};
const int LABEL_ARR_SIZE = sizeof(label)/sizeof(label[0]);

char *notes[] = {"A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#"};
const int numNotes = sizeof(notes)/sizeof(notes[0]);

// prints all chords based on
// the given root note to stdout
void listChords(int root_i)
{

    printf("Chord of the runtime is: %s\n", notes[root_i]);

    for(int i = 0; i < CHORD_ENUM_SIZE; i++){
        printf("%s%s:\t", notes[root_i], label[i]);

        for(int j = 0; j < chords_sizes[i]; j++) {
            printf("%s", notes[(root_i + chords[i][j]) % numNotes]);
            if(j == chords_sizes[i]-1) {
                printf("\n");
            }else {
                printf("-");
            }
        }
    }
}