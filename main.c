#include <stdio.h>
#include "playlist.h"
#include "ihm.h"

int main(void) {
    int nbPlists = 0, choix = 0;
    Playlist **plists = NULL;
    do {
        choix = menu();
        switch (choix) {
            case 1: break;
            case 2: {
                int nbPlistsOld = nbPlists;
                plists = creerPlist(plists, &nbPlists);
                if (nbPlists > nbPlistsOld) confirmPlist(plists[nbPlists - 1]);
                break;
            }
            case 3: break;
            case 4: break;
            case 5: break;
            case 6:
                clear();
                if (nbPlists > 0) {
                    int i = choixPlist(plists, nbPlists);
                    nvMorceauVersPlist(plists[i]);
                } else {
                    printf("Veuillez creer une playlist !\n");
                    entreeNext();
                }
                break;
            case 7: break;
            case 8: break;
            case 9: break;
            default:break;
        }
    } while (choix != 0);
    for (int i = 0; i < nbPlists; i++) {
        if (plists[i] != NULL) {
            free(plists[i]->nom);
            plists[i]->nom = NULL;
            free(plists[i]->tabMorceaux);
            plists[i]->tabMorceaux = NULL;
            free(plists[i]);
            plists[i] = NULL;
        }
    }
    free(plists);
    plists = NULL;

    return 0;
}