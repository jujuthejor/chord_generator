#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// This might not be needed
enum chord_type {
    CHORD_MAJOR,
    CHORD_MINOR,
    CHORD_SUS2,
    CHORD_SUS4,
    ENUM_SIZE
};

// Anticipating other chord types,
// it might be preferred to store
// these arrays in a (dynamically
// allocated) array
int major[] = {0, 4, 7};
int minor[] = {0, 3, 7};
int sus2[] = {0, 2, 7};
int sus4[] = {0, 5, 7};

int main(int argc, char **argv)
{
    srand(time(0));
    char notes[12][3] = {"A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#"};

    int root_i = rand() % 12;
    printf("Chord(s) of the runtime is:\n%s", notes[root_i]);

    enum chord_type chord;
    enum chord_type size = ENUM_SIZE;

    chord = rand() % size;

    switch (chord)
    {
    case CHORD_MAJOR:
        printf("maj: ");
        for(int i= 0; i < sizeof(major)/sizeof(int); i++) {
            printf("%s", notes[(root_i + major[i])%12]);
            if (i == (sizeof(major)/sizeof(int)-1)) {
                printf("\n");
            } else {
                printf("-");
            }
        }
        break;
    case CHORD_MINOR:
        printf("min: ");
        for(int i= 0; i < sizeof(minor)/sizeof(int); i++) {
            printf("%s", notes[(root_i + minor[i])%12]);
            if (i == (sizeof(minor)/sizeof(int)-1)) {
                printf("\n");
            } else {
                printf("-");
            }
        }
        break;    
    case CHORD_SUS2:
        printf("sus2: ");
        for(int i= 0; i < sizeof(sus2)/sizeof(int); i++) {
            printf("%s", notes[(root_i + sus2[i])%12]);
            if (i == (sizeof(sus2)/sizeof(int)-1)) {
                printf("\n");
            } else {
                printf("-");
            }
        }
        break;    
    case CHORD_SUS4:
        printf("sus4: ");
        for(int i= 0; i < sizeof(sus4)/sizeof(int); i++) {
            printf("%s", notes[(root_i + sus4[i])%12]);
            if (i == (sizeof(sus4)/sizeof(int)-1)) {
                printf("\n");
            } else {
                printf("-");
            }
        }
        break;    
    default:
        break;
    }

    return 0;
}