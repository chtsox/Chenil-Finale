# Projet ChenYl-Tech 🐾

Application C de gestion d'un chenil

## 📋 Fonctionnalités principales

- Ajouter, afficher, rechercher et supprimer des animaux
- Sauvegarde et chargement dans un fichier `animaux/animaux.txt`
- Génération automatique d’animaux aléatoires pour tests
- Variantes supplémentaires :
  - `INV_AGE_ASC` : inventaire des animaux par tranche d'âge (quartiles)
  - `DAY_CLEAN` : calcul du temps de nettoyage hebdomadaire

## 📂 Structure

```
Chenil/
├── src/                   # Code source
│   ├── main.c             # Point d'entrée du programme
│   ├── animal.c/h         # Structure Animal + gestion saisie/affichage
│   ├── fichier.c/h        # Lecture/écriture des fichiers animaux
│   ├── utils.c/h          # Fonctions utilitaires (année, ID libre, etc.)
│
├── animaux/               # Dossier contenant le fichier animaux.txt
│   └── animaux.txt        # Base de données textuelle
│
├── Makefile               # Compilation automatisée
└── README.md              # Documentation du projet
```

## ▶️ Compilation

```bash
make
```

## 🐧 Exécution

```bash
./chenil
```
