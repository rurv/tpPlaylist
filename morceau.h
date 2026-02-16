//
// Created by ruben on 2/13/2026.
//

#ifndef TPPLAYLIST_MORCEAU_H
#define TPPLAYLIST_MORCEAU_H

#include <stdlib.h>

#define MC_TITRE_MAX 128
#define MC_TITRE_MIN 1
#define MC_ARTISTE_MAX 32
#define MC_ARTISTE_MIN 1
#define MC_DUREE_MAX 86399
#define MC_DUREE_MIN 1
#define MC_ANNEE_MAX 2026
#define MC_ANNEE_MIN 1

typedef struct {
    char *titre, *artiste;
    int duree, annee, nbRef;
} Morceau;

typedef struct Playlist Playlist;

Morceau* creerMorceau (void);
void libererMorceau (Morceau* m);

#endif //TPPLAYLIST_MORCEAU_H