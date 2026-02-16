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
                plists = creerPlist(plists, &nbPlists);
                break;
            default:
                break;
        }
    } while (choix != 0);
    for (int i = 0; i < nbPlists; i++) {
        if (plists[i] != NULL) {
            free(plists[i]);
            plists[i] = NULL;
        }
    }
    return 0;
}
