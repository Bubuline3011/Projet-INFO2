all : exec
main.o: main.c projet.h
	gcc -c main.c -o main.o
crea_affi_plateau.o:  crea_affi_plateau.c projet.h
	gcc -c crea_affi_plateau.c -o crea_affi_plateau.o
f_utilisateur.o: f_utilisateur.c projet.h
	gcc -c f_utilisateur.c -o f_utilisateur.o
jeu.o: jeu.c projet.h
	gcc -c jeu.c -o jeu.o
exec: main.o crea_affi_plateau.o f_utilisateur.o jeu.o
	gcc jeu.o main.o crea_affi_plateau.o f_utilisateur.o -o exec
