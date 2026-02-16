//
// Created by ruben on 2/13/2026.
//

#include "playlist.h"

Playlist* initPlist (const char* nom, const int capacite) {
    Playlist *p = malloc(sizeof(Playlist));
    if (p == NULL) return NULL;
    p->tabMorceaux = malloc(capacite * sizeof(Morceau*));
    if (p->tabMorceaux == NULL) {
        free(p);
        p = NULL;
        return NULL;
    }
    p->nom = malloc((strlen(nom) + 1) * sizeof(char));
    if (p->nom == NULL) {
        free(p->tabMorceaux);
        p->tabMorceaux = NULL;
        free(p);
        p = NULL;
        return NULL;
    }
    strcpy(p->nom, nom);
    p->capacite = capacite;
    p->nbMorceaux = 0;
    return p;
}

Playlist** creerPlist (Playlist** plists, int* nbPlists) {
    clear();
    char nom[PL_NOM_TAILLE_MAX];
    saisieStr(nom, "Veuillez saisir le nom de la playlist.", PL_NOM_TAILLE_MAX);
    printf("\n");
    int capacite = saisieInt("Veuillez saisir la capacite maximale de la playlist", PL_CAPACITE_MIN, PL_CAPACITE_MAX);
    Playlist* nouvellePl = initPlist(nom, capacite);
    if (nouvellePl != NULL) {
        Playlist **temp = realloc(plists, (*nbPlists + 1) * sizeof(Playlist*));
        if (temp != NULL) {
            plists = temp;
            plists[*nbPlists] = nouvellePl;
            (*nbPlists)++;
        } else {
            free(nouvellePl->nom);
            nouvellePl->nom = NULL;
            free(nouvellePl->tabMorceaux);
            nouvellePl->tabMorceaux = NULL;
            free(nouvellePl);
            nouvellePl = NULL;
        }
    }
    return plists;
}

void nvMorceauVersPlist (Playlist* pl) {
    clear();
    if (pl == NULL) return;
    printf("%s\n", pl->nom);

    if (pl->nbMorceaux >= pl->capacite) {
        printf("Playlist pleine ! (%d/%d morceaux)\n", pl->nbMorceaux, pl->capacite);
        entreeNext();
        return;
    }

    Morceau* nvm = creerMorceau();
    if (nvm != NULL) {
        pl->tabMorceaux[pl->nbMorceaux] = nvm;
        pl->nbMorceaux++;
        printf("\n\"%s\" par %s a bien ete ajoute a %s\n", nvm->titre, nvm->artiste, pl->nom);
        entreeNext();
    }
}