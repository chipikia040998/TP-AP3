#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "include/Divers.h"
#include "include/ArbresSyntaxiques.h"

int main (void) 
{
	char MSG[100];
	sprintf(MSG, "saviez vous que %d + %d font %d",3,7,3+7);
	//test de la fonction Stop
	AfficherMessage(MSG, false);
	AfficherMessage("Troisième et dernier message", true);
	AfficherMessage("Dernier message non affihcer", false);
}