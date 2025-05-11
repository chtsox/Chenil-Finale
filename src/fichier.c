// fichier.c - Gestion de la lecture/écriture des animaux dans un fichier texte
#include <stdio.h>
#include <string.h>
#include "fichier.h"

#define CHEMIN "animaux/animaux.txt" // Chemin vers le fichier principal de données

// Charge les animaux depuis le fichier texte dans un tableau
int charger_animaux(Animal animaux[], int max) {
    FILE *f = fopen(CHEMIN, "r"); // Ouverture en lecture
    if (!f) return 0; // Si le fichier n'existe pas, on retourne 0 animaux

    int i = 0;
    // Lecture ligne par ligne (format CSV)
    while (i < max && fscanf(f, "%d;%49[^;];%19[^;];%d;%f;%99[^\n]\n",
        &animaux[i].id, animaux[i].nom, animaux[i].espece,
        &animaux[i].annee_naissance, &animaux[i].poids, animaux[i].commentaire) == 6) {
        i++;
    }
    fclose(f);
    return i; // Retourne le nombre d'animaux chargés
}

// Sauvegarde les animaux du tableau dans un fichier texte
int sauvegarder_animaux(const Animal animaux[], int nb) {
    FILE *f = fopen(CHEMIN, "w"); // Ouverture en écriture (écrase le contenu)
    if (!f) return -1; // Erreur d'ouverture

    for (int i = 0; i < nb; i++) {
        // Écriture au format : ID;Nom;Espèce;Année;Poids;Commentaire
        fprintf(f, "%d;%s;%s;%d;%.2f;%s\n",
            animaux[i].id, animaux[i].nom, animaux[i].espece,
            animaux[i].annee_naissance, animaux[i].poids,
            strlen(animaux[i].commentaire) ? animaux[i].commentaire : "");
    }
    fclose(f);
    return 0; // Succès
}
