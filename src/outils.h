#ifndef UTILS_H
#define UTILS_H

#include "animal.h"

int obtenir_annee_actuelle();
int trouver_id_libre(const Animal animaux[], int nb);
int comparer_int(const void *a, const void *b);
void inventaire_age(const Animal animaux[], int nb);
void calcul_charges_nettoyage(const Animal animaux[], int nb);

#endif
