#include"projet.h"

int alea_longueur() { // Renvoie une longueur aléatoire
  return rand() % 6 + 15; 
}

int alea_hauteur() { // Renvoie une hauteur aléatoire
  return rand() % 6 + 15; 
}

char ** creer_plateau(int longueur, int hauteur) { // fonction permettant de créer le plateau de jeu
  char **plat_jeu = NULL;
  plat_jeu = malloc((2 * hauteur) * sizeof(char *)); // creation du tableau de pointeurs qui pointent vers d'autre pointeurs;
  if (plat_jeu == NULL) { // on verifie que l'allocation s'est bien passée
    printf("Erreur veuillez relancer le jeu");
    exit(1);
  }
  for (int i = 0; i < 2 * hauteur + 1; i++) {
    plat_jeu[i] = malloc((2 * longueur + 1) * sizeof(char));
    if (plat_jeu[i] == NULL) {
      printf("Erreur veuillez relancer le jeu");
      exit(2);
    }
    for (int j = 0; j < 2 * longueur + 1; j++) { // creation du tableau de caractère pour le plateau de jeu
      if (i % 2 == 0 && j % 2 == 0) {
        plat_jeu[i][j] = '+';
      } 
      else if (i % 2 == 0) {
        plat_jeu[i][j] = '-';
      } 
      else if (j % 2 == 0) {
        plat_jeu[i][j] = '|';
      } 
      else {
        plat_jeu[i][j] = ' ';
      }
    }
  }
  return plat_jeu;
}

void afficher_plateau(int longueur, int hauteur, char **plat_jeu) { //affichage du plateau 
  for (int i = 0; i < 2 * hauteur + 1; i++) {
    for (int j = 0; j < 2 * longueur + 1; j++) {
      if(plat_jeu[i][j]== '+' ||  plat_jeu[i][j]== '|'){
        /*if(i==0 ||j==0 ||i == 2*hauteur ||j== 2*longueur){
          couleur("31");
          printf("%c", plat_jeu[i][j]);
          couleur("0");
        }
        else{*/
          couleur("30");
          printf("%c", plat_jeu[i][j]);
          couleur("0");
        //}
      }
      else if(plat_jeu[i][j]== '-'){
        /*if(i==0 ||j==0 ||i == 2*hauteur ||j== 2*longueur){
          couleur("31");
          printf("%c--",plat_jeu[i][j]);
          couleur("0");
        }*/
        //else{
          couleur("30");
          printf("%c--",plat_jeu[i][j]) ; // ajouter des tiret pour l'esthetisme 
          couleur("0");
        //}
      }
      else if(plat_jeu[i][j] >= 'A' && plat_jeu[i][j] <= 'R'){
        printf(" %c ", plat_jeu[i][j]); // ajouter des espaces pour l'esthetisme
      }
      else if(plat_jeu[i][j] == '/'){
        couleur("31");
        printf("|");
        couleur("0");
      }
      else if(plat_jeu[i][j] == '*'){
        couleur("31");
        printf("---");
        couleur("0");
      }
      else if(plat_jeu[i][j] == '='){
        couleur("31");
        printf("+");
        couleur("0");
      }
      else if(plat_jeu[i][j]=='1'){
        /*couleur("32");
        printf(" %c ", plat_jeu[i][j]);
        couleur("0");*/
        printf("\U0001F9DA ");              // fee

      }
      else if(plat_jeu[i][j]=='2'){
        /*couleur("33");
        printf(" %c ", plat_jeu[i][j]);
        couleur("0");*/
        printf("\U0001F984 ");              // licorne

      }
      else if(plat_jeu[i][j]=='3'){
        /*couleur("34");
        printf(" %c ", plat_jeu[i][j]);
        couleur("0");*/
        printf(" \U0001F98B");               // papillon
      }
      else if(plat_jeu[i][j]=='4'){
        /*couleur("35");
        printf(" %c ", plat_jeu[i][j]);
        couleur("0");*/
        printf(" \U0001F9D9");                // sorcier
      }
      else {
        printf("   "); 
      }
    }
    printf("\n");
  }
}

int case_valide(Coordonnee* cible, int longueur, int hauteur, char **plat_jeu, int k){ // fonction permettant de vérifier si la case correspond aux criteres de l'enonce
  if(plat_jeu[cible[k].y][cible[k].x] != ' '){ // on verifie que la case situé au coordonné tiré au sort est vide
  return 0;
  }
  if(cible[k].x  == 1 || cible[k].x >= 2*longueur-1 || cible[k].y == 1 || cible[k].y >= 2*hauteur-1){ // on verifie que les coordonnee ne sont pas surr les cases de la bordure exterieur 
    return 0;
  }  
  for (int i = -2; i <= 2; i+=2) { // on verifie que les 8 cases autour sont vides (on incremente de deux car toute les longueurs sont double)
      for (int j = -2; j <= 2; j+=2) {
          if (i != 0 || j != 0) {
              if (plat_jeu[cible[k].y + i][cible[k].x + j] != ' ') {
                return 0;
              }
          }
      }
  }
  return 1;
}


Coordonnee* placer_cible(int longueur, int hauteur, char** plat_jeu) { // fonction permettant de placer les cibles aléatoirement sur le plateau et retourne un tableau avec les coordonnés des cibles
  char cible[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R'};
  Coordonnee* a;
  int nb_cible_cree = 0;
  int i=0;
  a = malloc(18*sizeof(Coordonnee));
  if(a==NULL){
    printf("Erreur");
    exit(3);
  }
  while (nb_cible_cree < 18) { // on recommence tant que les 18 cible ne sont pas placé
    a[i].x = rand() % (2*longueur); //on tire au sort une coordonnée x
    a[i].y = rand() % (2*hauteur);  // et une coordonnée y
    if(case_valide(a,longueur,hauteur,plat_jeu,i)==1) {
      plat_jeu[a[i].y][a[i].x] = cible[nb_cible_cree]; // on dit que la case a.y et a.x prend la valeur de la lettre corespondant a la cible dans le tableau cible[]
      nb_cible_cree++; // on incrémente le nombre de cible cree
      i++;
    }
  }
  return a;
}

void placer_mur_autour_cible(int longueur, int hauteur, char** plat_jeu){ // fonction visant a mettre les deux murs autour des cibles et mettre les murs perpendiculaire au mur exterieur
  int mur1_ext_horizon_g; // on cree les murs perpendiculaires aux bords extérieurs de la grille, ici on crée des variables qui representeront les murs horizontaux des cotés gauche et droit.
  int mur2_ext_horizon_g;
  int mur1_ext_horizon_d;
  int mur2_ext_horizon_d;
  
   int mur1_ext_verti_h; // on cree  les murs perpendiculaires aux bords extérieurs de la grille, ici on crée des variables qui representeront les murs verticales du coté en haut et en bas.
  int mur2_ext_verti_h;
  int mur1_ext_verti_b;
  int mur2_ext_verti_b;
  
  for (int i = 0; i < 2 * hauteur + 1; i++) {
    for (int j = 0; j < 2 * longueur + 1; j++) {
      if(plat_jeu[i][j]>='A' && plat_jeu[i][j]<='R'){
        int mur1_alea = rand() % 4 + 1 ; // 1 pour gauche, 2 pour droite, 3 pour haut, 4 pour bas
        int mur2_alea;
        do{
          mur2_alea = rand() % 4 + 1 ;
        }while( mur2_alea == mur1_alea || mur2_alea == mur1_alea+1 || mur2_alea == mur1_alea-1); // on verifie que les deux murs tiré au sort ne sont pas sur le meme cote

        if(mur1_alea == 1 || mur2_alea == 1){ // en fonction de la position du mur on attrubue un nouveau caractere pour pouvoir le differencier lors que l'affichage
          plat_jeu[i-1][j] = '*';
        }
        if(mur1_alea == 2 || mur2_alea == 2){
          plat_jeu[i+1][j] = '*';
        }
        if(mur1_alea == 3 || mur2_alea == 3){
          plat_jeu[i][j-1] = '/';
        }
        if(mur1_alea == 4 || mur2_alea == 4){
          plat_jeu[i][j+1] = '/';
        }
      }
      else if(i==0 ||j==0 ||i==2*hauteur ||j==2*longueur || (i==0 && j%2 == 0) || (i==2*hauteur && j%2 == 0) || (j==0 && i%2==0)||(j==2*longueur && i%2==0) ){
        if(plat_jeu[i][j]=='|'){
          plat_jeu[i][j] = '/';
        }
        else if(plat_jeu[i][j]=='-'){
          plat_jeu[i][j] = '*';
        }
        else if(plat_jeu[i][j]== '+'){
          plat_jeu[i][j] = '=';
        }
      }
    }
  }
  
  do{
    mur1_ext_horizon_g = rand() % (2*hauteur-1) + 1; // on tire au sort la poisition du mur horizontale du coté gauche, la plage de valeur est de 1 à la hauteur de la grille moins 1 (de meme pour les autres tirages au sort)
    do{
      mur2_ext_horizon_g = rand() % (2*hauteur-1) + 1;
    }while(mur2_ext_horizon_g == mur1_ext_horizon_g);// on recommence tant que les murs tirés au sort sont les memes (il faut deux murs distincts)

    mur1_ext_horizon_d = rand() % (2*hauteur-1) + 1;
    do{
      mur2_ext_horizon_d = rand() % (2*hauteur-1) + 1;
    }while(mur2_ext_horizon_d == mur1_ext_horizon_d); // on recommence tant que les murs tiré au sort sont les memes (il faut deux murs distint)
  }while((plat_jeu[mur1_ext_horizon_g][1] == ' ') || (plat_jeu[mur2_ext_horizon_g][1]== ' ')||(plat_jeu[mur1_ext_horizon_d][2*longueur-1]== ' ')||(plat_jeu[mur2_ext_horizon_d][2*longueur-1] == ' ')); // on recommence tant que les murs tiré au sort ce place sur des cases "vide" (on ne peut pas avoir un mur sur une case vide)
  plat_jeu[mur1_ext_horizon_g][1] = '*'; // on attribue un nouveau caractere pour les murs horizontaux pour les differencier a l'affichage 
  plat_jeu[mur2_ext_horizon_g][1] = '*';
  plat_jeu[mur1_ext_horizon_d][2*longueur-1] = '*';
  plat_jeu[mur2_ext_horizon_d][2*longueur-1] = '*';

  do{// on effectue de la meme maniere que précédemment les placement des murs verticaux
    mur1_ext_verti_h = rand() % (2*longueur-1) + 1;
    do{
      mur2_ext_verti_h = rand() % (2*longueur-1) + 1;
    }while(mur2_ext_verti_h == mur1_ext_verti_h);

    mur1_ext_verti_b = rand() % (2*longueur-1) + 1;
    do{
      mur2_ext_verti_b = rand() % (2*longueur-1) + 1;
    }while(mur2_ext_verti_b == mur1_ext_verti_b);
  }while((plat_jeu[1][mur1_ext_verti_h] == ' ') || (plat_jeu[1][mur2_ext_verti_h]== ' ')||(plat_jeu[2*hauteur-1][mur1_ext_verti_b]== ' ')||(plat_jeu[2*hauteur-1][mur2_ext_verti_b] == ' ')); 
  plat_jeu[1][mur1_ext_verti_h] = '/';  
  plat_jeu[1][mur2_ext_verti_h] = '/';
  plat_jeu[2*hauteur-1][mur1_ext_verti_b] = '/';
  plat_jeu[2*hauteur-1][mur2_ext_verti_b] = '/';
}


int case_ok_robot(Coordonnee* robot, int longueur, int hauteur, char** plat_jeu, int i){ // on verifie que la case situé au coordonné tiré au sort est vide
  if(plat_jeu[robot[i].y][robot[i].x] != ' '){
    return 0;
  }
  return 1;
}

Coordonnee* placer_robot(int longueur, int hauteur, char** plat_jeu){ // fonction permettant de placer les robots aléatoirement sur le plateau et retourne un tableau avec les coordonnés des robots
  char robot[] = {'1', '2', '3', '4'};
  Coordonnee* a;
  int i = 0;
  int nb_robot_cree = 0;
  a = malloc(4*sizeof(Coordonnee));
  if(a==NULL){
    printf("Erreur");
    exit(4);
  }
  while (nb_robot_cree < 4) { // on recommence tant que les 4 robot ne sont pas placé
    a[i].x = rand() % (2*longueur); //on tire au sort une coordonnée x
    a[i].y = rand() % (2*hauteur);  // et une coordonnée y
    if(case_ok_robot(a,longueur,hauteur,plat_jeu, i)==1) {
      plat_jeu[a[i].y][a[i].x] =  robot[nb_robot_cree]; // on dit que la case a[i].y et a[i].x prend le caractere numero a associé au robot voulu
      nb_robot_cree++; // on incrémente le nombre de robot cree
      i++;
    }
  }
  return a;
}
