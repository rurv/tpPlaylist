//
// Created by ruben on 2/13/2026.
//

#ifndef TPPLAYLIST_IHM_H
#define TPPLAYLIST_IHM_H

#define DEBUG 1

void debug (const char* str);
int menu (void);
void saisieStr (char* str, const char* dialogue, int max);
int saisieInt(const char* dialogue, int min, int max);

#endif //TPPLAYLIST_IHM_H