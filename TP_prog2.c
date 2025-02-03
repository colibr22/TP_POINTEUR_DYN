#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

typedef struct {
    char* nom;
    int frequence;
    int duree;
} Note;

Note* creerNote(char* nom, int frequence, int duree) {
    Note* note = (Note*)malloc(sizeof(Note));
    note->nom = nom;
    note->frequence = frequence;
    note->duree = duree;
    return note;
}

void jouerSon(int frequence, int duree) {
    Beep(frequence, duree);
}

void simulerPiano(Note** notes, int nbNotes) {
    char touches[] = {'a', 'z', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', 'm', 'l'};
    while (1) {
        if (_kbhit()) {
            char touche = _getch();
            if (touche == 'q') {
                break;
            }
            for (int i = 0; i < nbNotes; ++i) {
                if (touche == touches[i]) {
                    jouerSon(notes[i]->frequence, notes[i]->duree);
                    printf("Note jouée: %s\n", notes[i]->nom);
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
    char* noms[12] = {"Do", "Do#", "Re", "Re#", "Mi", "Fa", "Fa#", "Sol", "Sol#", "La", "La#", "Si"};
    int duree = 500;

    Note* notes[12];
    for (int i = 0; i < 12; ++i) {
        notes[i] = creerNote(noms[i], (int)frequencies[i], duree);
    }

    simulerPiano(notes, 12);
    libererNotes(notes, 12);

    return 0;
}
