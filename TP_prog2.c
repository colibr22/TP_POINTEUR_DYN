#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

typedef struct {
    int frequence;
    int duree;
} Note;

Note* creerNote(char* nom, int frequence, int duree) {
    Note* note = (Note*)malloc(sizeof(Note));
    note->frequence = frequence;
    note->duree = duree;
    return note;
}

void simulerPiano(Note** notes, int nbNotes) {
    for (int i = 0; i < nbNotes; i++) {
        Beep(notes[i]->frequence, notes[i]->duree);
    }
    while (!_kbhit())
    
}

void libererNotes(Note** notes, int nbNotes) {
    for (int i = 0; i < nbNotes; i++) {
        free(notes[i]);
    }
}

int main() {
    float frequencies[12] = {261.63, 277.18, 293.66, 311.13, 329.63, 349.23, 369.99, 392.00, 415.30, 440.00, 466.16, 493.88};
    int duree = 500;


}
