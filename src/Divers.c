//inclusion des fichier nécessaires
#include "../include/Divers.h"

//inclusion des bibliothèques
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void Stop (char *message[], bool stop)
{
	//affichage du message
	printf("%s",message);

	//on regarde la valeur de stop, si stop on laisse afficher 100s avant de quitter
	if(stop)
	{
		sleep (100);
		exit (1);
	}
}