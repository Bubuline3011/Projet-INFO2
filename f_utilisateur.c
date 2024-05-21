#include"projet.h"

void vide_file() { // sert a aviter les fautes de frappe
  while (getchar() != '\n') {
  }
}

void effacer_ligne() { // chat gpt => efface la derniere ligne  
    printf("\x1b[1A"); // Déplace le curseur d'une ligne vers le haut
    printf("\x1b[2K"); // Efface toute la ligne
}
