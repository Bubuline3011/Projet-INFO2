# Projet-INFO2 : CY-BER Path / Le Labyrinthe Magique
## Table des Matières
1. [Description](#description)
2. [Structure](#structure)
3. [Installation](#installation)
4. [Utilisation](#utilisation)
6. [Auteurs](#auteurs)

## Description 

Le projet consiste à  développer un jeu de robots glisseurs, à compiler sur le terminal, où les joueurs doivent guider des robots vers des cibles sur une grille en 2D. Le jeu peut être joué à deux joueurs ou plus, sans limite fixée. Chaque joueur doit estimer le nombre minimum de mouvements nécessaires pour atteindre la cible avant de saisir ses mouvements. Ainsi, c'est un jeu divertissant mettant à l'épreuve la réflexion et la stratégie des joueurs.

## Structure 

- **`main.c`** : contient la fonction principale
- **`projet.h`** : contient la déclaration de toutes les fonctions, les structures, les constantes et les inclusions de bibliothèques.
- **`jeu.c`** : contient toutes les fonctions relatives au jeu, comme le déplacement des robots, mise à jour des points des joueurs etc..
- **`f_utilisateur.c`** : contient les fonctions relatives à l'interface utilisteur et évite certaines fautes de frappe.
- **`crea_affi_plateau.c`** : contient les fonctions qui créent et affichent le plateau de jeu.
- **Makefile** : permet d'automatiser la compilation.
- **Rapport du projet CY-BER Path MI-05-1.pdf** : contient un compte rendu sur l'organisation de l'équipe concernant le projet, les difficultés rencontrées, les solutions apportées et une brève description du projet.

## Installation 

### Prérequis 

- Un terminal C
### Etapes 

Consignes avant de pouvoir jouer : 
1. Télécharger tous les fichiers en cliquant sur chacun, excepté le rapport de projet et le README.
2. Mettre tous les fichiers dans un dossier dans un même fichier si vous le souhaitez.
3. Si vous l’avez mis dans un fichier, écrire : **cd nom_du_fichier**.
4. Écrire dans le terminal : **make all**

## Utilisation 

- Écrire dans le terminal : **./exec**
- Jouez !

## Auteurs

- Bulard Yona - Initial Work - Bubuline3011
- Farid Hafsa - Initial Work - hfsaa
- Pellegrino Capucine - Initial Work - capuuch

