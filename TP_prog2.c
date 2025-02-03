#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void liberer_note(Note* note) {
    free(note);
}

