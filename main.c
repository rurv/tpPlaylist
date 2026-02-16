#include <stdio.h>
#include "playlist.h"
#include "ihm.h"

int main(void) {
    int nbPlists = 0, choix = 0;
    Playlist **plists = NULL;
    do {
        choix = menu();
        switch (choix) {
            case 1:
                naviguerDansVotreBibliotheque(nbPlists, &plists);
                break;
            case 2: {
                creerUnePlaylist(&nbPlists, &plists);
                break;
            }
            case 3:
                //supprimerPlaylist();
                break;
            case 4:
                //importerPlaylist();
                break;
            case 5:
                //exporterPlaylist();
                break;
            case 6:
                creerMorceauAjouterPlaylist(nbPlists, &plists);
                break;
            case 7:
                //morceauPlAPl();
                break;
            case 8:
                //supprimerMorceauPl();
                break;
            case 9:
                //supprimerMorceauAll();
                break;
            default:break;
        }
    } while (choix != 0);

    for (int i = 0; i < nbPlists; i++) libererPlist(plists[i]);
    free(plists);
    plists = NULL;

    return 0;
}