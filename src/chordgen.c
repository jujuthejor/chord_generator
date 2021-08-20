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

const char *NOTES[] = {"A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#"};
const int NUM_NOTES = sizeof(NOTES)/sizeof(NOTES[0]);

static void printChordNotes(int root_i, chord_t type)
{
        for(int i = 0; i < chords_sizes[type]; i++) {
            printf("%s", NOTES[(root_i + chords[type][i]) % NUM_NOTES]);
            if(i == chords_sizes[type]-1) {
                printf("\n");
            }else {
                printf("-");
            }
        }
}

// prints all chords based on
// the given root note to stdout
void listChords(int root_i)
{

    printf("Chord of the runtime is: %s\n", NOTES[root_i]);

    for(int i = 0; i < CHORD_ENUM_SIZE; i++){
        printf("%s%s:\t", NOTES[root_i], label[i]);

        for(int j = 0; j < chords_sizes[i]; j++) {
            printf("%s", NOTES[(root_i + chords[i][j]) % NUM_NOTES]);
            if(j == chords_sizes[i]-1) {
                printf("\n");
            }else {
                printf("-");
            }
        }
    }
}

void printChord(int root_i, chord_t chord_type, flag_t flag)
{
    switch (chord_type)
    {
        case CHORD_MAJ:
            switch (flag)
            {
                case CHORD_CHORD_ONLY:
                    printf("%s%s", NOTES[root_i], label[CHORD_MAJ]);
                    break;
                case CHORD_NOTES_ONLY:
                    printChordNotes(root_i, CHORD_MAJ);
                    break;
                default:
                    printf("%s%s:\t", NOTES[root_i], label[CHORD_MAJ]);
                    printChordNotes(root_i, CHORD_MAJ);
                    break;
            }
            break;
        case CHORD_MIN:
            switch (flag)
            {
                case CHORD_CHORD_ONLY:
                    printf("%s%s", NOTES[root_i], label[CHORD_MIN]);
                    break;
                case CHORD_NOTES_ONLY:
                    printChordNotes(root_i, CHORD_MIN);
                    break;
                default:
                    printf("%s%s:\t", NOTES[root_i], label[CHORD_MIN]);
                    printChordNotes(root_i, CHORD_MIN);
                    break;
            }
            break;
        case CHORD_DIM:
            switch (flag)
            {
                case CHORD_CHORD_ONLY:
                    printf("%s%s", NOTES[root_i], label[CHORD_DIM]);
                    break;
                case CHORD_NOTES_ONLY:
                    printChordNotes(root_i, CHORD_DIM);
                    break;
                default:
                    printf("%s%s:\t", NOTES[root_i], label[CHORD_DIM]);
                    printChordNotes(root_i, CHORD_DIM);
                    break;
            }
            break;
        case CHORD_AUG:
            switch (flag)
            {
                case CHORD_CHORD_ONLY:
                    printf("%s%s", NOTES[root_i], label[CHORD_AUG]);
                    break;
                case CHORD_NOTES_ONLY:
                    printChordNotes(root_i, CHORD_AUG);
                    break;
                default:
                    printf("%s%s:\t", NOTES[root_i], label[CHORD_AUG]);
                    printChordNotes(root_i, CHORD_AUG);
                    break;
            }
            break;
        case CHORD_MAJ7:
            switch (flag)
            {
                case CHORD_CHORD_ONLY:
                    printf("%s%s", NOTES[root_i], label[CHORD_MAJ7]);
                    break;
                case CHORD_NOTES_ONLY:
                    printChordNotes(root_i, CHORD_MAJ7);
                    break;
                default:
                    printf("%s%s:\t", NOTES[root_i], label[CHORD_MAJ7]);
                    printChordNotes(root_i, CHORD_MAJ7);
                    break;
            }
            break;
        case CHORD_MIN7:
            switch (flag)
            {
                case CHORD_CHORD_ONLY:
                    printf("%s%s", NOTES[root_i], label[CHORD_MIN7]);
                    break;
                case CHORD_NOTES_ONLY:
                    printChordNotes(root_i, CHORD_MIN7);
                    break;
                default:
                    printf("%s%s:\t", NOTES[root_i], label[CHORD_MIN7]);
                    printChordNotes(root_i, CHORD_MIN7);
                    break;
            }
            break;
        case CHORD_DOM7:
            switch (flag)
            {
                case CHORD_CHORD_ONLY:
                    printf("%s%s", NOTES[root_i], label[CHORD_DOM7]);
                    break;
                case CHORD_NOTES_ONLY:
                    printChordNotes(root_i, CHORD_DOM7);
                    break;
                default:
                    printf("%s%s:\t", NOTES[root_i], label[CHORD_DOM7]);
                    printChordNotes(root_i, CHORD_DOM7);
                    break;
            }
            break;
        case CHORD_SUS2:
            switch (flag)
            {
                case CHORD_CHORD_ONLY:
                    printf("%s%s", NOTES[root_i], label[CHORD_SUS2]);
                    break;
                case CHORD_NOTES_ONLY:
                    printChordNotes(root_i, CHORD_SUS2);
                    break;
                default:
                    printf("%s%s:\t", NOTES[root_i], label[CHORD_SUS2]);
                    printChordNotes(root_i, CHORD_SUS2);
                    break;
            }
            break;
        case CHORD_SUS4:
            switch (flag)
            {
                case CHORD_CHORD_ONLY:
                    printf("%s%s", NOTES[root_i], label[CHORD_SUS4]);
                    break;
                case CHORD_NOTES_ONLY:
                    printChordNotes(root_i, CHORD_SUS4);
                    break;
                default:
                    printf("%s%s:\t", NOTES[root_i], label[CHORD_SUS4]);
                    printChordNotes(root_i, CHORD_SUS4);
                    break;
            }
            break;
        default:
            printf("Something's amiss...\n");
            break;
    }
}
