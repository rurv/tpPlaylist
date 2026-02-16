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