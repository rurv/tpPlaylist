//
// Created by ruben on 2/13/2026.
//

#include "ihm.h"
#include "playlist.h"

void clear (void) {
    printf("\033[H\033[2J");
}

void entreeNext (void) {
    printf("ENTREE pour retourner au menu...");
    getchar();
}

int menu (void) {
    clear();
    int choix = 0;
    printf("Bibliotheque Musicale\n\n");
    printf("1. Naviguer dans votre bibliothèque\n");
    printf("2. Creer une playlist\n");
    printf("3. Supprimer une playlist\n");
    printf("4. Importer une playlist\n");
    printf("5. Exporter une playlist\n");
    printf("6. Creer un morceau et l'ajouter a une playlist\n");
    printf("7. Ajouter un morceau d'une playlist a une autre\n");
    printf("8. Supprimer un morceau d'une playlist\n");
    printf("9. Supprimer un morceau de toutes les playlists\n");
    printf("0. Quitter\n\n");
    do {
        printf("> ");
        scanf("%d", &choix);
        getchar();
    } while (choix < 0 || choix > 9);
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
    clear();
    if (p == NULL) return;
    printf("Playlist creee avec succes\n\n");
    printf("\"%s\"\n", p->nom);
    printf("0/%d Morceaux\n\n", p->capacite);
    entreeNext();
}

void listePlists (const Playlist** plists, const int nbPlists) {
    printf("%d playlist", nbPlists);
    if (nbPlists > 1) printf("s");
    printf(" :\n\n");
    for (int i = 0; i < nbPlists; i++) printf("%d. %s\t(%d/%d)\n", i + 1, plists[i]->nom, plists[i]->nbMorceaux, plists[i]->capacite);
    printf("\n");
}

int choixPlist (const Playlist** plists, const int nbPlists) {
    int choix;
    listePlists(plists, nbPlists);
    choix = saisieInt("Choisir playlist", 1, nbPlists);
    return choix;
}