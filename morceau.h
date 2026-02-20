//
// Created by ruben on 2/13/2026.
//

#ifndef TPPLAYLIST_MORCEAU_H
#define TPPLAYLIST_MORCEAU_H

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
void convDuree (int duree, int* h, int* m, int* s);
void ajouterMorceauPlist (Playlist* plo, Playlist* pld, int m);
void supprimerMorceau (Playlist* p, int m);
void suppMorceauAll (Playlist* p, int m, int nbPlists, Playlist*** plists);


#endif //TPPLAYLIST_MORCEAU_H