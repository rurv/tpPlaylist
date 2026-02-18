//
// Created by ruben on 2/13/2026.
//

#include "ihm.h"
#include "playlist.h"
#include <stdio.h>
#include <string.h>

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
    printf("1. Naviguer dans votre bibliotheque\n");
    printf("2. Creer une playlist\n");
    printf("3. Supprimer une playlist\n");
    printf("4. Importer une playlist\n");
    printf("5. Exporter une playlist\n");
    printf("6. Creer un morceau et l'ajouter a une playlist\n");
    printf("7. Ajouter un morceau d'une playlist a une autre\n");
    printf("8. Supprimer un morceau d'une playlist\n");
    printf("9. Supprimer un morceau de toutes les playlists\n");
    printf("0. Quitter\n\n");
    choix = saisieInt("Veuillez choisir une option", 0, 9);
    return choix;
}

void saisieStr (char* str, const char* dialogue, const int max) {
    printf("%s\n> ", dialogue);
    if (fgets(str, max, stdin) != NULL) {
        if (str[0] == '\n') fgets(str, max, stdin);
        if (str[strlen(str) - 1] == '\n') str[strlen(str) - 1] = '\0';
    }
}

int saisieInt (const char* dialogue, const int min, const int max) {
    int n, r;
    printf("%s (%d - %d)\n", dialogue, min, max);
    do {
        printf("> ");
        r = scanf("%d", &n);
        if (r != 1) {
            printf("Veuillez saisir un nombre !\n");
            while (getchar() != '\n') {}
            continue;
        }
        getchar();
        if (n < min || n > max) {
            printf("Valeur saisie incorrecte !\n");
        }
    } while (r != 1 || n < min || n > max);
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

void listePlists (Playlist*** plists, const int nbPlists) {
    printf("%d playlist", nbPlists);
    if (nbPlists > 1) printf("s");
    printf(" :\n\n");
    for (int i = 0; i < nbPlists; i++) printf("%d. (%d/%d)\t%s\n", i + 1, (*plists)[i]->nbMorceaux, (*plists)[i]->capacite, (*plists)[i]->nom);
    printf("\n");
}

int choixPlist (Playlist** plists, const int nbPlists) {
    listePlists(&plists, nbPlists);
    const int choix = saisieInt("Choisir playlist", 1, nbPlists);
    return choix;
}

void listeMorceaux (const Playlist* pl) {
    if (pl == NULL) return;
    if (pl->nbMorceaux == 0) {
        printf("La playlist est vide.\n");
        entreeNext();
    } else {
        printf("%s (%d morceau", pl->nom, pl->nbMorceaux);
        if (pl->nbMorceaux > 1) printf("x");
        printf(") :\n\n");
        for (int i = 0; i < pl->nbMorceaux; i++) printf("%d.\t%s - %s\n", i + 1, pl->tabMorceaux[i]->titre, pl->tabMorceaux[i]->artiste);
        printf("\n");
    }
}

int choixMorceau (const Playlist* pl) {
    if (pl == NULL || pl->nbMorceaux == 0) return -1;
    listeMorceaux(pl);
    const int choix = saisieInt("Choisir un morceau", 1, pl->nbMorceaux);
    return choix - 1;
}

void afficherDetailsMorceau(const Morceau* m) {
    int h, min, s;
    convDuree(m->duree, &h, &min, &s);
    printf("%s\t- %s\n(%d)\n%d:%d:%d\n", m->titre, m->artiste, m->annee, h, min, s);
    entreeNext();
}

void naviguerDansVotreBibliotheque (const int nbPlists, Playlist*** plists) {
    clear();
    if (nbPlists > 0) {
        listePlists(plists, nbPlists);
        printf("0. Retourner au menu\n\n");
        const int choix = saisieInt("Choisir playlist ou 0 pour retourner au menu", 0, nbPlists);
        if (choix == 0) return;
        const int i = choix - 1;
        clear();
        if ((*plists)[i]->nbMorceaux > 0) {
            listeMorceaux((*plists)[i]);
            printf("0. Retourner au menu\n\n");
            const int choix1 = saisieInt("Choisir morceau ou 0 pour retourner au menu", 0, (*plists)[i]->nbMorceaux);
            if (choix1 == 0) return;
            const int m = choix1 - 1;
            if (m >= 0) {
                clear();
                afficherDetailsMorceau((*plists)[i]->tabMorceaux[m]);
            }
        } else {
            printf("Playlist vide.\n");
            entreeNext();
        }
    } else {
        printf("Aucune playlist.\n");
        entreeNext();
    }
}

void creerUnePlaylist (int *nbPlists, Playlist*** plists) {
    const int nbPlistsOld = *nbPlists;
    *plists = creerPlist(*plists, nbPlists);
    if (*nbPlists > nbPlistsOld) confirmPlist((*plists)[*nbPlists - 1]);
}

void creerMorceauAjouterPlaylist (const int nbPlists, Playlist*** plists) {
    clear();
    if (nbPlists > 0) {
        const int i = choixPlist(*plists, nbPlists) - 1;
        nvMorceauVersPlist((*plists)[i]);
    } else {
        printf("Veuillez creer une playlist !\n");
        entreeNext();
    }
}

void supprimerPlaylist (int *nbPlists, Playlist*** plists) {
    clear();
    if (*nbPlists > 0) {
        const int i = choixPlist(*plists, *nbPlists) - 1;
        libererPlist((*plists)[i]);
        for (int j = i; j < (*nbPlists) - 1; j++) {
            (*plists)[j] = (*plists)[j + 1];
        }
        *plists = reallocPlists(*plists, nbPlists);
        clear();
        if (*nbPlists > 0) listePlists(plists, *nbPlists);
        else printf("Aucune playlist.\n\n");
        printf("Playlist supprimee avec succes\n");
        entreeNext();
    } else {
        printf("Aucune playlist.\n");
        entreeNext();
    }
}