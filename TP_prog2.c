#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

typedef struct {
    int frequence;
    int duree;
}Note;

Note* creer_note(int frequence, int duree) {
    Note* note = (Note*)malloc(sizeof(Note));
    if (note == NULL) {
        printf("Erreur d'allocation de mémoire\n");
        exit(1);
    }
    note->frequence = frequence;
    note->duree = duree;
    return note;
}
void jouerSon(int frequence) {
    Beep(frequence, 500);
}

void simulerPiano(Note** notes, int nbNotes) {
    char touches[] = {'a', 'z', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', 'm', 'l', '\'', '\\'};
    while (1) {
        if (_kbhit()) {
            char touche = _getch();
            if (touche == 'q') {
                break;
            }
            for (int i = 0; i < nbNotes; ++i) {
                if (touche == touches[i]) {
                    jouerSon(notes[i]->frequence);
                    printf("Note jouée: %s\n", notes[i]->nom);
                }
            }
        }
    }
}

void libererNotes(Note **notes, int nbNotes){
    for (int i = 0; i < nbNotes; i++){
        free(notes[i]);
    }
    free(notes);
}

int main() {
    float frequence[12] = { 261.63, 277.18, 293.66, 311.13, 329.63, 349.23, 369.99, 392.00, 415.30, 440.00, 466.16, 493.88 }; 
    char* noms[12] = { "Do", "Do#", "Re", "Re#", "Mi", "Fa", "Fa#", "Sol", "Sol#", "La", "La#", "Si" };


    return 0;
}
