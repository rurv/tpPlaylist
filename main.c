#include <stdio.h>
#include "playlist.h"
#include "ihm.h"

int main(void) {
    debug("Demarrage");
    int nbPlist = 0, choix = 0;
    Playlist **plists = NULL;
    debug("Tableau des playlists cree");
    do {
        choix = menu();
        switch (choix) {
            case 1:
                creerPlist(saisieStr("Veuillez saisir le nom de la playlist.", PL_NOM_TAILLE_MAX), saisieInt("Veuillez saisir la capacite maximale de la playlist", PL_CAPACITE_MIN, PL_CAPACITE_MAX));
                break;
            default:
                break;
        }
    } while (choix != 0);
    for (int i = 0; i < nbPlist; i++) {
        if (plists[i] != NULL) {
            free(plists[i]);
            plists[i] = NULL;
        }
    }
    return 0;
}
