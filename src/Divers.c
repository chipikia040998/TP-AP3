//inclusion des bibliothèques
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
//inclusion de fichier
#include "../include/Divers.h"

void AfficherMessage (char * message, bool stop)
{
	//affichage du message
	printf("%s \n", message);

	//on regarde la valeur de stop, si stop on laisse afficher avant de quitter
	if(stop)
	{
		//system("pause"); (marche pas sur replit a metre sur vs)
		exit (1);
	}
}

int EntierAleatoire(int inf, int sup)
{
    srand(time(NULL));
    int r = inf + rand() % (sup - inf + 1);
    return r;
}