//
// Created by ruben on 2/13/2026.
//

#ifndef TPPLAYLIST_PLAYLIST_H
#define TPPLAYLIST_PLAYLIST_H

#include "morceau.h"

typedef struct {
    char* nom;
    int capacite, nbMorceaux;
    Morceau** tabMorceaux;
} Playlist;

Playlist* creerPlist (const char* nom, const int capacite, Morceau** tabMorceaux);

#endif //TPPLAYLIST_PLAYLIST_H