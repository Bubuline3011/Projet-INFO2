#include"projet.h"

int main() {
  srand(time(NULL));
  int nb_joueur, longueur, hauteur;
  char **plateau;
  int test_nb_j;
  printf("\nBienvenue dans le jeu du Labyrinthe Magique !\n\n");
  sleep(2);
  printf("Des créatures féériques ont perdu leurs outils magiques dans un labyrinthe un peu spécial... Aidez-les à retrouver leurs items.\n\n");
  sleep(2);
  printf("Pour cette partie il vous faut au moins 2 joueurs.\nCombien de joueurs êtes vous ?\n");
  do { // on demande a l'utilisateur le nombre de joueur et on sécurise le code
    test_nb_j = scanf("%d", &nb_joueur);
    printf("Saisissez un nombre entier !\n");
    vide_file();
  } while (nb_joueur < 2 || test_nb_j ==0 );
  system("clear");
  printf("Parfait ! Vous êtes %d joueurs !\n\n", nb_joueur);
  printf("_______________________Le Labyrinthe Magique_______________________\n\n"); //nom du jeu

  longueur = alea_longueur(); // creation des longueurs et hauteurs du plateau
  hauteur = alea_hauteur();
  plateau = creer_plateau(longueur, hauteur); // creer le plateau

  Coordonnee* tab_cible; 
  tab_cible = placer_cible(longueur, hauteur, plateau); // y placer les cibles
  placer_mur_autour_cible(longueur, hauteur, plateau); // on place les murs autour des cible et ceux perpendiculaires aux bords

  Coordonnee* tab_robot;
  tab_robot = placer_robot(longueur, hauteur, plateau);
  afficher_plateau(longueur, hauteur, plateau);
  sleep(1);
  partie(longueur, hauteur, plateau, nb_joueur, tab_robot, tab_cible);
  return 0;
}
