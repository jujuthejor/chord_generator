#include<stdio.h>

#include "chordgen.h"

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
    "dom7",
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

void printChord(int root_i, chord_t chord_type)
{
    switch (chord_type)
    {
        case CHORD_MAJ:
            printf("%s%s:\t", notes[root_i], label[CHORD_MAJ]);

            for(int i = 0; i < chords_sizes[CHORD_MAJ]; i++) {
                printf("%s", notes[(root_i + chords[CHORD_MAJ][i]) % numNotes]);
                if(i == chords_sizes[CHORD_MAJ]-1) {
                    printf("\n");
                }else {
                    printf("-");
                }
            }
            break;
        case CHORD_MIN:
            printf("%s%s:\t", notes[root_i], label[CHORD_MIN]);

            for(int i = 0; i < chords_sizes[CHORD_MIN]; i++) {
                printf("%s", notes[(root_i + chords[CHORD_MIN][i]) % numNotes]);
                if(i == chords_sizes[CHORD_MIN]-1) {
                    printf("\n");
                }else {
                    printf("-");
                }
            }
            break;
        case CHORD_DIM:
            printf("%s%s:\t", notes[root_i], label[CHORD_DIM]);

            for(int i = 0; i < chords_sizes[CHORD_DIM]; i++) {
                printf("%s", notes[(root_i + chords[CHORD_DIM][i]) % numNotes]);
                if(i == chords_sizes[CHORD_DIM]-1) {
                    printf("\n");
                }else {
                    printf("-");
                }
            }
            break;
        case CHORD_AUG:
            printf("%s%s:\t", notes[root_i], label[CHORD_AUG]);

            for(int i = 0; i < chords_sizes[CHORD_AUG]; i++) {
                printf("%s", notes[(root_i + chords[CHORD_AUG][i]) % numNotes]);
                if(i == chords_sizes[CHORD_AUG]-1) {
                    printf("\n");
                }else {
                    printf("-");
                }
            }
            break;
        case CHORD_MAJ7:
            printf("%s%s:\t", notes[root_i], label[CHORD_MAJ7]);

            for(int i = 0; i < chords_sizes[CHORD_MAJ7]; i++) {
                printf("%s", notes[(root_i + chords[CHORD_MAJ7][i]) % numNotes]);
                if(i == chords_sizes[CHORD_MAJ7]-1) {
                    printf("\n");
                }else {
                    printf("-");
                }
            }
            break;
        case CHORD_MIN7:
            printf("%s%s:\t", notes[root_i], label[CHORD_MIN7]);

            for(int i = 0; i < chords_sizes[CHORD_MIN7]; i++) {
                printf("%s", notes[(root_i + chords[CHORD_MIN7][i]) % numNotes]);
                if(i == chords_sizes[CHORD_MIN7]-1) {
                    printf("\n");
                }else {
                    printf("-");
                }
            }
            break;
        case CHORD_DOM7:
            printf("%s%s:\t", notes[root_i], label[CHORD_DOM7]);

            for(int i = 0; i < chords_sizes[CHORD_DOM7]; i++) {
                printf("%s", notes[(root_i + chords[CHORD_DOM7][i]) % numNotes]);
                if(i == chords_sizes[CHORD_DOM7]-1) {
                    printf("\n");
                }else {
                    printf("-");
                }
            }
            break;
        case CHORD_SUS2:
            printf("%s%s:\t", notes[root_i], label[CHORD_SUS2]);

            for(int i = 0; i < chords_sizes[CHORD_SUS2]; i++) {
                printf("%s", notes[(root_i + chords[CHORD_SUS2][i]) % numNotes]);
                if(i == chords_sizes[CHORD_SUS2]-1) {
                    printf("\n");
                }else {
                    printf("-");
                }
            }
            break;
        case CHORD_SUS4:
            printf("%s%s:\t", notes[root_i], label[CHORD_SUS4]);

            for(int i = 0; i < chords_sizes[CHORD_SUS4]; i++) {
                printf("%s", notes[(root_i + chords[CHORD_SUS4][i]) % numNotes]);
                if(i == chords_sizes[CHORD_SUS4]-1) {
                    printf("\n");
                }else {
                    printf("-");
                }
            }
            break;
        default:
            printf("Something's amiss...\n");
            break;
    }
}