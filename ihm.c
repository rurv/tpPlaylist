//
// Created by ruben on 2/13/2026.
//

#include "ihm.h"

#include <stdio.h>

#include "playlist.h"

void debug (const char* str) {
    if (DEBUG) printf("\tDEBUG : %s\n", str);
}

int menu (void) {
    debug("APPEL menu");
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

char* saisieStr (const char* dialogue, const int max) {
    debug("APPEL saisie string");
    char str[max];
    printf("%s\n", dialogue);
    printf("> ");
    scanf("%s", str);
    if (str[max - 1] != '\0') str[max - 1] = '\0';
    return str;
}

int saisieInt (const char* dialogue, const int min, const int max) {
    debug("APPEL saisie int");
    int n;
    printf("%s (%d - %d)\n", dialogue, min, max);
    do {
        printf("> ");
        scanf("%d", &n);
    } while (n < min || n > max);
    return n;
}