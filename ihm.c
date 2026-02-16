//
// Created by ruben on 2/13/2026.
//

#include "ihm.h"

#include <stdio.h>

void debug (const char* str) {
    if (DEBUG) printf("\tDEBUG : %s\n", str);
}

int menu (void) {
    debug("Appel du menu");
    int choix = 0;
    printf("Bibliotheque Musicale\n");
    printf("Menu :\n");
    printf("1. Creer Playlist\n");
    printf("0. Quitter\n");
    do {
        printf("> ");
        scanf("%d", &choix);
        getchar();
    } while (choix < 0 || choix > 1);
    return choix;
}