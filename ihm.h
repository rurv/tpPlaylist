//
// Created by ruben on 2/13/2026.
//

#ifndef TPPLAYLIST_IHM_H
#define TPPLAYLIST_IHM_H

typedef struct Playlist Playlist;

void clear (void);
void entreeNext (void);
int menu (void);
void saisieStr (char* str, const char* dialogue, int max);
int saisieInt (const char* dialogue, int min, int max);
void confirmPlist (const Playlist* p);
void listePlists (Playlist*** plists, int nbPlists);
int choixPlist (Playlist** plists, int nbPlists);
int choixMorceau (const Playlist* pl);
void naviguerDansVotreBibliotheque (int nbPlists, Playlist*** plists);
void creerUnePlaylist (int *nbPlists, Playlist*** plists);
void creerMorceauAjouterPlaylist (int nbPlists, Playlist*** plists);
void supprimerPlaylist (int *nbPlists, Playlist*** plists);

#endif //TPPLAYLIST_IHM_H