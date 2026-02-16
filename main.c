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

                break;
            default: break;
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
