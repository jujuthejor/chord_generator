/*
 * Copyright (c) 2021 Jose Gabriel Ramos (@jujuthejor)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#include "chordgen.h"

typedef enum {
    MODE_LIST_CHORDS,
    MODE_PRINT_CHORDS,
    MODE_ENUM_SIZE
} t_mode;

const char *modes[] = {
    "print all chords of a given root note",
    "print some random chords",
};

const char prompt[] = "Enter the number corresponding to what you want to do...\n";

void printStartScreen(int *choice)
{
    printf(prompt);
    for(int i = 0; i < MODE_ENUM_SIZE; i++) {
        printf("\t%2d - %s\n", i+1, modes[i]);
    }
    printf("Enter number of your choice: ");
    scanf("%d", choice);
}

void printNoteOptions()
{
    for(int i = 0; i < NUM_NOTES; i++) {
        printf("%2d - %s\t\t", i, NOTES[i]);
        if((i+1)%3 == 0) {
            printf("\n");
        }
    }
}

void getRootNote(int *root_note)
{
    do {
        printf("Your choice: ");
        scanf("%d", root_note);

        if(*root_note < 0 || *root_note > NUM_NOTES) {
            printf("Input is out of bounds...\n");
        }
    } while (*root_note < 0 || *root_note > NUM_NOTES);
}

void printChords(int num_chords)
{
    int root_note;
    int chord_type;
    for (int i = 0; i < num_chords; i++)
    {
        root_note = rand() % NUM_NOTES;
        chord_type = rand() % CHORD_ENUM_SIZE;

        printChord(root_note, chord_type, CHORD_CHORD_ONLY);
        if (i == num_chords - 1) {
            printf("\n");
        } else {
            printf(" - ");
        }
    }
}

int main (void)
{
    srand(time(0));

    int choice;
    int root_note;
    int num_chords;

    printStartScreen(&choice);

    switch (choice)
    {
    case 1:
        printf("Enter the number corresponding to the root note you want list chords of\n");
        printNoteOptions();
        getRootNote(&root_note);
        listChords(root_note);
        break;
    case 2:
        printf("How many chords do you want? ");
        scanf("%d", &num_chords);
        printChords(num_chords);
        break;
    default:
        printf("Please enter a valid number next time.\n");
        break;
    }

    printf("Goodbye!\n");
    return 0;
}
