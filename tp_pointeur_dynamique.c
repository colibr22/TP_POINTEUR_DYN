#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

typedef struct {
    int frequence;
    int duree;
} Note;

Note* creerNote(int frequence, int duree) {
    Note* nouvelleNote = (Note*)malloc(sizeof(Note));
    nouvelleNote->frequence = frequence;
    nouvelleNote->duree = duree;
    return nouvelleNote;
}

void simulerPiano(Note** notes, int nombreNotes) {
    char touches[] = {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', '\\'};
    while (1) {
        if (_kbhit()) {
            char touche = _getch();
            if (touche == 'q') {
                break;
            }
            for (int i = 0; i < nombreNotes; ++i) {
                if (touche == touches[i]) {
                    Beep(notes[i]->frequence, notes[i]->duree);
                    printf("Note jouée: %d Hz\n", notes[i]->frequence);
                }
            }
        }
    }
}

void libererNotes(Note** notes, int nombreNotes) {
    for (int i = 0; i < nombreNotes; ++i) {
        free(notes[i]);
    }
}

int main() {
    float frequencies[12] = {261.63, 277.18, 293.66, 311.13, 329.63, 349.23, 369.99, 392.00, 415.30, 440.00, 466.16, 493.88};
    int duree = 500;

    Note* notes[12];
    for (int i = 0; i < 12; ++i) {
        notes[i] = creerNote((int)frequencies[i], duree);
    }

    simulerPiano(notes, 12);
    libererNotes(notes, 12);

    return 0;
}
