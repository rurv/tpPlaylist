//
// Created by ruben on 2/13/2026.
//

#include "ihm.h"
#include "playlist.h"

int menu (void) {
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

void saisieStr (char* str, const char* dialogue, const int max) {
    printf("%s\n", dialogue);
    printf("> ");
    if (fgets(str, max, stdin) != NULL) {
        if (str[strlen(str) - 1] == '\n') str[strlen(str) - 1] = '\0';
    }
}

int saisieInt (const char* dialogue, const int min, const int max) {
    int n;
    printf("%s (%d - %d)\n", dialogue, min, max);
    do {
        printf("> ");
        scanf("%d", &n);
        getchar();
    } while (n < min || n > max);
    return n;
}

void confirmPlist (const Playlist* p) {
    if (p == NULL) return;
    printf("Playlist creee avec succes\n");
    printf("\"%s\"\n", p->nom);
    printf("0/%d Morceaux\n", p->capacite);
}