//
// Created by ruben on 2/13/2026.
//

#include "playlist.h"

Playlist* creerPlist (const char* nom, const int capacite) {
    debug("DEBUT alloc. structure");
    Playlist *p = malloc(sizeof(Playlist));
    if (p == NULL) {
        debug("ECHEC alloc. structure");
        return NULL;
    }
    debug("SUCCES alloc. structure");
    debug("DEBUT alloc. tab morceaux");
    p->tabMorceaux = malloc(capacite * sizeof(Morceau*));
    if (p->tabMorceaux == NULL) {
        debug("ECHEC alloc. tab morceaux");
        debug("FREE structure");
        free(p);
        p = NULL;
        return NULL;
    }
    debug("SUCCES alloc. tab morceaux");
    debug("DEBUT alloc. nom");
    int len = strlen(nom) + 1;
    p->nom = malloc(len * sizeof(char));
    if (p->nom == NULL) {
        debug("ECHEC alloc. nom");
        debug("FREE tab morceaux");
        free(p->tabMorceaux);
        p->tabMorceaux = NULL;
        debug("FREE structure");
        free(p);
        p = NULL;
        return NULL;
    }
    debug("SUCCES alloc. nom");
    p->capacite = capacite;
    p->nbMorceaux = 0;
    debug("SUCCES toutes alloc., retour de p");
    return p;
}
