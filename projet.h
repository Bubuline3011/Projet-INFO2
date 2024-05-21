#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#define couleur(param) printf("\033[%sm", param)
#define NB_MANCHES 4
#define NB_SEC 45

typedef struct { // structure pour les coordonnées
  int x;
  int y;
} Coordonnee;

typedef struct{
  int nb_point;
  int nb_depla;
}Joueur;

int alea_longueur();
int alea_hauteur();
void vide_file();
char ** creer_plateau(int longueur, int hauteur);
void afficher_plateau(int longueur, int hauteur, char **plat_jeu);
int case_valide(Coordonnee* cible, int longueur, int hauteur, char **plat_jeu, int k);
Coordonnee* placer_cible(int longueur, int hauteur, char** plat_jeu);
void placer_mur_autour_cible(int longueur, int hauteur, char** plat_jeu);
int case_ok_robot(Coordonnee* robot, int longueur, int hauteur, char** plat_jeu, int i);
Coordonnee* placer_robot(int longueur, int hauteur, char** plat_jeu);
int min_deplacement(int nb_joueurs, Joueur* joueur, int* indice);
void deplacer_robot_temp (char** plat_jeu,int longueur, int hauteur, int robot_alea, int cible_alea, int* nb_depla_actu, Coordonnee* tab_robot, Coordonnee* tab_cible, int manche_actu, Coordonnee * i, char * tab_temp);
void effacer_ligne();
void resultat(int nb_joueurs, Joueur* joueur);
void maj_point(int nb_joueurs, int nb_depla_actu, int min_depla, int indice, Joueur* joueur);
void cible_robot_choisit(int robot_alea, int cible_alea, char* cible);
int deja_tire(int* r_tire, int taille,  int nombre);
void partie(int longueur, int hauteur, char** plat_jeu, int nb_joueurs, Coordonnee * tab_robot, Coordonnee* tab_cible);
