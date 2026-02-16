//
// Created by ruben on 2/13/2026.
//

#ifndef TPPLAYLIST_IHM_H
#define TPPLAYLIST_IHM_H

#include <stdio.h>
#include <string.h>
typedef struct Playlist Playlist;

int menu (void);
void saisieStr (char* str, const char* dialogue, int max);
int saisieInt(const char* dialogue, int min, int max);
void confirmPlist(const Playlist* p);

#endif //TPPLAYLIST_IHM_H