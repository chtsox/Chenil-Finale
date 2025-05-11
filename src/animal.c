// animal.c - Gestion de la structure Animal, affichage, saisie et génération aléatoire
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "animal.h"
#include "outils.h"

// Initialise une structure Animal à partir des informations fournies
Animal init_animal(const char *nom, const char *espece, int annee, float poids, const char *commentaire) {
    Animal a;
    a.id = -1; // L'ID sera défini séparément
    strncpy(a.nom, nom, sizeof(a.nom));
    strncpy(a.espece, espece, sizeof(a.espece));
    a.annee_naissance = annee;
    a.poids = poids;
    strncpy(a.commentaire, commentaire ? commentaire : "", sizeof(a.commentaire));
    return a;
}

// Permet à l'utilisateur de saisir un nouvel animal via le terminal
Animal saisir_animal(const Animal animaux[], int nb) {
    char nom[50], espece[20], commentaire[100];
    int annee;
    float poids;

    printf("Nom : ");
    scanf(" %49[^\n]", nom);
    printf("Espèce : ");
    scanf(" %19[^\n]", espece);
    printf("Année de naissance : ");
    scanf("%d", &annee);
    printf("Poids : ");
    scanf("%f", &poids);
    printf("Commentaire (ou '-' pour aucun) : ");
    scanf(" %99[^\n]", commentaire);

    Animal a = init_animal(nom, espece, annee, poids, commentaire);
    a.id = trouver_id_libre(animaux, nb); // Attribution d'un ID libre
    return a;
}

// Affiche les informations d'un animal à l'écran
void afficher_animal(const Animal *a) {
    printf("ID: %d\nNom: %s\nEspèce: %s\nNaissance: %d\nPoids: %.2f kg\n",
           a->id, a->nom, a->espece, a->annee_naissance, a->poids);
    if (strlen(a->commentaire))
        printf("Commentaire: %s\n", a->commentaire);
    printf("\n");
}

// Supprime un animal du tableau en le remplaçant par ceux qui suivent
int supprimer_animal(Animal animaux[], int *nb, int id) {
    for (int i = 0; i < *nb; i++) {
        if (animaux[i].id == id) {
            for (int j = i; j < *nb - 1; j++)
                animaux[j] = animaux[j + 1];
            (*nb)--;
            return 1; // Succès
        }
    }
    return 0; // ID non trouvé
}

// Données d'exemple pour la génération aléatoire
char *noms[] = {"Luna", "Max", "Sacha", "Nina", "Rocky"};
char *especes[] = {"Chien", "Chat", "Hamster", "Autruche"};
char *commentaires[] = {"Joueur", "Timide", "Affectueux", "Dormeur", "Aucun"};

// Génère un certain nombre d'animaux avec des données aléatoires
int generer_animaux_aleatoires(Animal animaux[], int *nb, int combien) {
    srand(time(NULL)); // Initialisation de l'aléatoire
    for (int i = 0; i < combien && *nb < MAX_ANIMAUX; i++) {
        char *nom = noms[rand() % 5];
        char *esp = especes[rand() % 4];
        char *com = commentaires[rand() % 5];
        int annee = 2010 + rand() % 14; // Entre 2010 et 2023
        float poids = (rand() % 1500) / 10.0 + 1.0; // Poids plausible
        Animal a = init_animal(nom, esp, annee, poids, com);
        a.id = trouver_id_libre(animaux, *nb);
        animaux[(*nb)++] = a;
    }
    return 1;
}
