#include"projet.h"

int min_deplacement(int nb_joueurs, Joueur* joueur, int* indice){ // premet de prendre le nombre de deplacements minimun dite parmis tous les joueurs
  int min_depla = joueur[0].nb_depla;
  for(int i=0 ; i<nb_joueurs ; i++){
    if(joueur[i].nb_depla < min_depla){
      min_depla = joueur[i].nb_depla;
      *indice = i;
    }
  }
  return min_depla;
} 

void deplacer_robot_temp(char** plat_jeu, int longueur, int hauteur, int robot_alea, int cible_alea, int* nb_depla_actu, Coordonnee* tab_robot, Coordonnee* tab_cible, int manche_actu, Coordonnee* i, char* tab_temp) {
  int direction;
  int test_dir;
  do {
    printf("Saisir la direction du robot : 1 pour HAUT, 2 pour BAS, 3 pour GAUCHE, 4 pour DROITE :\n ");
    test_dir = scanf("%d", &direction);
    vide_file(); 
  } while ((direction != 1 && direction != 2 && direction != 3 && direction != 4) || test_dir == 0); 
  int dx = 0, dy = 0;
  switch (direction) {
    case 1: dy = -1; break; // HAUT
    case 2: dy = 1; break;  // BAS 
    case 3: dx = -1; break; // GAUCHE
    case 4: dx = 1; break;  // DROITE
  }
  while ((plat_jeu[i->y + dy][i->x + dx] != '*' && plat_jeu[i->y + dy][i->x + dx] != '/' && plat_jeu[i->y + 2*dy][i->x + 2*dx] != '1' && plat_jeu[i->y + 2*dy][i->x + 2*dx] != '2' && plat_jeu[i->y + 2*dy][i->x + 2*dx] != '3' && plat_jeu[i->y + 2*dy][i->x + 2*dx] != '4') && (i->y + 2*dy >= 0 && i->y + 2*dy < 2*hauteur && i->x + 2*dx >= 0 && i->x + 2*dx < 2*longueur)) {
    if (*tab_temp >= 'A' && *tab_temp <= 'R') {
      plat_jeu[i->y + 2*dy][i->x + 2*dx] = plat_jeu[i->y][i->x];
      plat_jeu[i->y][i->x] = *tab_temp;
      printf("Manche %d / %d\n", manche_actu, NB_MANCHES);
      afficher_plateau(longueur, hauteur, plat_jeu);
      *tab_temp = '\0';
      i->y += 2 * dy;
      i->x += 2 * dx;
    }
    if (plat_jeu[i->y + 2*dy][i->x + 2*dx] >= 'A' && plat_jeu[i->y + 2*dy][i->x + 2*dx] <= 'R') {
      *tab_temp = plat_jeu[i->y + 2*dy][i->x + 2*dx];
      plat_jeu[i->y + 2*dy][i->x + 2*dx] = plat_jeu[i->y][i->x];
      plat_jeu[i->y][i->x] = ' ';
      printf("Manche %d / %d\n", manche_actu, NB_MANCHES);
      afficher_plateau(longueur, hauteur, plat_jeu);
      i->y += 2 * dy;
      i->x += 2 * dx;
    } 
    else if (plat_jeu[i->y + 2*dy][i->x + 2*dx] == ' ' && (*tab_temp < 'A' || *tab_temp > 'R')){     //pas compris *tab_temp
      plat_jeu[i->y + 2*dy][i->x + 2*dx] = plat_jeu[i->y][i->x];
      plat_jeu[i->y][i->x] = ' ';
      printf("Manche %d / %d\n", manche_actu, NB_MANCHES);
      afficher_plateau(longueur, hauteur, plat_jeu);
      i->y += 2 * dy;
      i->x += 2 * dx;
    }
}
*nb_depla_actu += 1;
}

void resultat(int nb_joueurs, Joueur* joueur){ // affiche les scors finaux de tous les joueurs + qui est le gagnant
  for(int i=0; i<nb_joueurs; i++){ 
    printf("Scores finaux : Le joueur %d a %d points\n", i+1, joueur[i].nb_point);
  }
  int nb_point_max = joueur[0].nb_point;
  int indice_gagnant=0;
  int egalite = 0;
  for(int i=1; i<nb_joueurs; i++){ // cherche celui qui a le plus de points et commence à 1 car on a déjà initialisé avec le premier joueur
    if(joueur[i].nb_point > nb_point_max){
      nb_point_max = joueur[i].nb_point;
      indice_gagnant = i;
      egalite = 0;
    }
    else if(joueur[i].nb_point == nb_point_max){
      egalite = 1;
    }
  }
  if(egalite == 1){
    printf("EGALITE\n");
    printf("Fin de la partie\n");
    exit(7);
  }
  else {
    printf("Le gagnant de cette partie est le joueur %d avec %d points\n", indice_gagnant+1, nb_point_max);
    printf("Fin de la partie\n");
    exit(7);
  }
}

void maj_point (int nb_joueurs, int nb_depla_actu, int min_depla, int indice, Joueur* joueur){ // met à jour les points des joueurs
  if(nb_depla_actu > min_depla){ 
    for(int i=0; i<nb_joueurs; i++){
      if(i != indice){
        joueur[i].nb_point++;
      }
    }
  }
  else if(nb_depla_actu < min_depla){
    joueur[indice].nb_point--;
  }
  else{
    joueur[indice].nb_point+=2;
  }
  for(int i=0; i<nb_joueurs; i++){
    printf("Le joueur %d a %d points\n", i+1, joueur[i].nb_point);
  }
  printf("\n");
}

void cible_robot_choisit(int robot_alea, int cible_alea, char* cible){ // affiche la cible et le robot chosit aleatoirement 
  if(robot_alea == 0){
    printf("La cible %c et la fée ont été choisies au hasard\n", cible[cible_alea]);
  }
  else if(robot_alea == 1){
    printf("La cible %c et la licorne ont été choisies au hasard\n", cible[cible_alea]);
  }
  else if(robot_alea == 2){
    printf("La cible %c et le papillon ont été choisis au hasard\n", cible[cible_alea]);
  }
  else if(robot_alea == 3){
    printf("La cible %c et le sorcier ont été choisis au hasard\n", cible[cible_alea]);
  }
}

int deja_tire(int* r_tire, int taille,  int nombre){
  for(int i= 0; i<taille; i++){
    if(r_tire[i]== nombre){
      return 1;
    }
  }
  return 0;
}

void partie (int longueur, int hauteur, char** plat_jeu, int nb_joueurs, Coordonnee * tab_robot, Coordonnee* tab_cible){
  char cible[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R'};
  char robot[] = {'1', '2', '3', '4'};
  Joueur* joueur;
  int robot_alea;
  int cible_alea;
  int r_tire[4] ={-1,-1,-1,-1};
  int tirage = 0;
  joueur = malloc(nb_joueurs*sizeof(Joueur));
  if(joueur == NULL){
    printf("Erreur d'allocation de memoire");
    exit(5);
  }
  for(int i=0; i<nb_joueurs; i++){ //on initialise le nb de pts de chaque joueur à 0
    joueur[i].nb_point = 0;
  }
  for(int manche_actu = 1; manche_actu <= NB_MANCHES; manche_actu++){
    couleur("36");
    printf("\nManche %d / %d\n", manche_actu, NB_MANCHES);
    couleur("0");
    do{
        robot_alea = rand() % 4;
        cible_alea = rand() % 18;
    }while((plat_jeu[tab_cible[cible_alea].y][tab_cible[cible_alea].x] >= '1' && plat_jeu[tab_cible[cible_alea].y][tab_cible[cible_alea].x]<= '4') || deja_tire(r_tire, 4, robot_alea) == 1);
    cible_robot_choisit(robot_alea, cible_alea, cible);
    r_tire[tirage] = robot_alea;
    tirage++;
    Coordonnee placer_r;
    placer_r.y = tab_robot[robot_alea].y;  
    placer_r.x = tab_robot[robot_alea].x;
    printf("\nRéfléchissez au nombre minimal de déplacements du robot pour qu'il puisse atteindre la cible\n");
    int i;
    for(i = NB_SEC-1; i>0; i--){
      printf("Il vous reste %d seconde(s) pour réfléchir\n", i);
      sleep(1);
      effacer_ligne();
    }
    system("clear"); // on supprime tt l'écran, car les joueurs ne doivent plus voir la grille
    int test_nb_d;
    if (i == 0){ // vérfication qu'il reste 0 seconde
      for(int j=0; j<nb_joueurs; j++){ // on demande à chaque joueur le nombre de deplacements minimal pour déplacer le robot et on sécurise le code
        printf("Joueur %d saisissez le nombre de déplacements minimal que vous pensez correct\n", j+1);
        do { 
          printf("Saisissez un nombre entier!\n");
          test_nb_d = scanf("%d", &joueur[j].nb_depla);
          vide_file();
        } while (joueur[j].nb_depla <= 0 || test_nb_d ==0 );
        system("clear");
      }
      int indice = 0 ;
      int min_depla = min_deplacement(nb_joueurs, joueur, &indice);
      
      // cible_robot_choisit(robot_alea, cible_alea, cible);
      
      printf("\nJoueur %d c'est à vous de déplacer le robot !\n", indice+1);
      sleep(3);
      system("clear"); // on supprime l'écran sinon y a trop d'infos
      
      afficher_plateau(longueur, hauteur, plat_jeu);
      char* tab_temp = malloc(1);
      if (tab_temp == NULL){
        printf("Erreur d'allocation");
        exit(6);
      }
      int nb_depla_actu = 0;
      while( (placer_r.y != tab_cible[cible_alea].y || placer_r.x != tab_cible[cible_alea].x) && (nb_depla_actu) <= (min_depla)){ // tant que le robot tiré au hasard n'est pas sur la cible tirée au hasard OU que le nombre de deplacements actuel est inférieur au nombre de deplacements minimal
        printf("Manche %d / %d\n", manche_actu, NB_MANCHES);
        cible_robot_choisit(robot_alea, cible_alea, cible);
        deplacer_robot_temp (plat_jeu, longueur, hauteur, robot_alea, cible_alea, &nb_depla_actu, tab_robot, tab_cible, manche_actu, &placer_r, tab_temp);
      }
      printf("Manche %d / %d\n", manche_actu, NB_MANCHES);
      maj_point (nb_joueurs, nb_depla_actu, min_depla, indice, joueur);
    }
  }
  resultat(nb_joueurs,joueur);
}

