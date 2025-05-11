#ifndef ANIMAL_H
#define ANIMAL_H

#define MAX_ANIMAUX 50

typedef struct {
    int id;
    char nom[50];
    char espece[20];
    int annee_naissance;
    float poids;
    char commentaire[100];
} Animal;

Animal init_animal(const char *nom, const char *espece, int annee, float poids, const char *commentaire);
Animal saisir_animal(const Animal animaux[], int nb);
void afficher_animal(const Animal *a);
int supprimer_animal(Animal animaux[], int *nb, int id);
int generer_animaux_aleatoires(Animal animaux[], int *nb, int combien);

#endif
