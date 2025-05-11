// main.c
#include <stdio.h>
#include <stdlib.h>
#include "animal.h"
#include "fichier.h"
#include "outils.h"

int main() {
    Animal animaux[MAX_ANIMAUX]; // Tableau contenant tous les animaux en mémoire
    int nb_animaux = 0; // Nombre d'animaux actuellement dans le chenil
    int choix; // Choix de l'utilisateur dans le menu

    // Chargement des animaux depuis le fichier au lancement du programme
    nb_animaux = charger_animaux(animaux, MAX_ANIMAUX);
    printf("%d animaux chargés depuis le fichier.\n", nb_animaux);

    // Boucle principale du menu utilisateur
    do {
        // Affichage du menu principal
        printf("\n--- MENU ---\n");
        printf("1. Afficher tous les animaux\n");
        printf("2. Ajouter un nouvel animal\n");
        printf("3. Faire adopter un animal (supprimer)\n");
        printf("4. Inventaire par âge (quartiles)\n");
        printf("5. Calcul de la charge de nettoyage (DAY_CLEAN)\n");
        printf("0. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                // Affiche tous les animaux enregistrés
                for (int i = 0; i < nb_animaux; i++) {
                    afficher_animal(&animaux[i]);
                }
                break;

            case 2:
                // Ajoute un nouvel animal saisi par l'utilisateur si le chenil n'est pas plein
                if (nb_animaux < MAX_ANIMAUX) {
                    animaux[nb_animaux++] = saisir_animal(animaux, nb_animaux);
                    sauvegarder_animaux(animaux, nb_animaux); // Mise à jour du fichier
                    printf("Animal ajouté avec succès.\n");
                } else {
                    printf("Le chenil est plein !\n");
                }
                break;

            case 3: {
                // Suppression d'un animal à partir de son ID (adoption)
                int id;
                printf("ID de l’animal à supprimer : ");
                scanf("%d", &id);
                if (supprimer_animal(animaux, &nb_animaux, id)) {
                    sauvegarder_animaux(animaux, nb_animaux); // Mise à jour du fichier
                    printf("Animal supprimé.\n");
                } else {
                    printf("Aucun animal avec cet ID.\n");
                }
                break;
            }

            case 4:
                // Affiche le nombre total d'animaux par tranche d'âge (quartiles)
                inventaire_age(animaux, nb_animaux);
                break;

            
            case 5:
                // Calcule et affiche le temps nécessaire pour nettoyer les abris (quotidien + hebdomadaire)
                calcul_charges_nettoyage(animaux, nb_animaux);
                break;

            case 6: {
                // Génère aléatoirement un certain nombre d'animaux pour tester l'application
                int n;
                printf("Combien d’animaux aléatoires ? ");
                scanf("%d", &n);
                generer_animaux_aleatoires(animaux, &nb_animaux, n);
                sauvegarder_animaux(animaux, nb_animaux); // Mise à jour du fichier
                printf("%d animaux générés.\n", n);
                break;
            }

            case 0:
                // Quitte le programme
                printf("À bientôt !\n");
                break;

            default:
                printf("Choix invalide.\n");
        }

    } while (choix != 0); // Répète tant que l'utilisateur ne choisit pas de quitter

    return 0;
}
