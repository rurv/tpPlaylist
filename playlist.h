//
// Created by ruben on 2/13/2026.
//

#ifndef TPPLAYLIST_PLAYLIST_H
#define TPPLAYLIST_PLAYLIST_H

#include <string.h>
#include "ihm.h"
#include "morceau.h"

#define PL_NOM_TAILLE_MAX 64
#define PL_CAPACITE_MIN 1
#define PL_CAPACITE_MAX 100

typedef struct Playlist {
    char* nom;
    int capacite, nbMorceaux;
    Morceau** tabMorceaux;
} Playlist;

Playlist* initPlist (const char* nom, int capacite);
Playlist** creerPlist (Playlist** plists, int* nbPlists);
void nvMorceauVersPlist (Playlist* pl);

#endif //TPPLAYLIST_PLAYLIST_H