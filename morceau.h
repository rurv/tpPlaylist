//
// Created by ruben on 2/13/2026.
//

#ifndef TPPLAYLIST_MORCEAU_H
#define TPPLAYLIST_MORCEAU_H

#include <stdlib.h>

typedef struct {
    char *titre, *artiste;
    int duree, annee, nbRef;
} Morceau;

#endif //TPPLAYLIST_MORCEAU_H