//
// Created by ruben on 2/13/2026.
//

#include "morceau.h"
#include "playlist.h"
#include <stdlib.h>
#include <string.h>

Morceau* creerMorceau (void) {
    Morceau* m = malloc(sizeof(Morceau));
    if (m == NULL) return NULL;
    char titre[MC_TITRE_MAX];
    saisieStr(titre, "\nSaisir titre du morceau", MC_TITRE_MAX);
    m->titre = malloc((strlen(titre) + 1) * sizeof(char));
    if (m->titre == NULL) {
        free(m);
        m = NULL;
        return NULL;
    }
    strcpy(m->titre, titre);
    char artiste[MC_ARTISTE_MAX];
    saisieStr(artiste, "\nSaisir artiste", MC_ARTISTE_MAX);
    m->artiste = malloc((strlen(artiste) + 1) * sizeof(char));
    if (m->artiste == NULL) {
        free(m->titre);
        m->titre = NULL;
        free(m);
        m = NULL;
        return NULL;
    }
    strcpy(m->artiste, artiste);
    m->duree = saisieInt("\nSaisir duree du morceau en secondes", MC_DUREE_MIN, MC_DUREE_MAX);
    m->annee = saisieInt("\nSaisir annee de sortie", MC_ANNEE_MIN, MC_ANNEE_MAX);
    m->nbRef = 1;
    return m;
}

void libererMorceau (Morceau* m) {
    if (m != NULL) {
        free(m->titre);
        m->titre = NULL;
        free(m->artiste);
        m->artiste = NULL;
        free(m);
        m = NULL;
    }
}

void convDuree (const int duree, int* h, int* m, int* s) {
    *h = duree / 3600;
    *m = (duree % 3600) / 60;
    *s = duree % 60;
}

void ajouterMorceauPlist (Playlist* plo, Playlist* pld, const int m) {
    if (plo == NULL || pld == NULL) return;
    pld->tabMorceaux[pld->nbMorceaux] = plo->tabMorceaux[m];
    pld->tabMorceaux[pld->nbMorceaux]->nbRef++;
    pld->nbMorceaux++;
}

void supprimerMorceau (Playlist* p, int m) {
    if (p == NULL || m < 0 || m >= p->nbMorceaux) return;
    p->tabMorceaux[m]->nbRef--;
    if (p->tabMorceaux[m]->nbRef <= 0) {
        libererMorceau(p->tabMorceaux[m]);
    }
    for (int i = m; i < p->nbMorceaux; i++) {
        p->tabMorceaux[i] = p->tabMorceaux[i + 1];
    }
    p->nbMorceaux--;
}

void suppMorceauAll (Playlist* p, int m, int nbPlists, Playlist*** plists) {
    if (p == NULL || plists == NULL || m < 0 || m >= p->nbMorceaux) return;
    const Morceau* c = p->tabMorceaux[m];
    for (int i = 0; i < nbPlists; i++) {
        Playlist* pl = (*plists)[i];
        for (int j = 0; j < pl->nbMorceaux; j++) {
            if (pl->tabMorceaux[j] == c) {
                supprimerMorceau(pl, j);
                j--;
            }
        }
    }
}