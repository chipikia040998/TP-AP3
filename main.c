#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "include/Divers.h"
#include "include/ArbresSyntaxiques.h"

int main (void) 
{	
	/* test pour cfonction AficherMessage
	char MSG[100];
	sprintf(MSG, "1 + sin(ln(10*x))");
	AfficherMessage(MSG, false);
	AfficherMessage("Troisième et dernier message", true);
	AfficherMessage("Dernier message non affihcer", false);
	*/
	
	TArbreSynt A = ConsBinaire('+',ConsConstante(1), ConsFonction('s', ConsFonction('l', ConsBinaire('*', ConsConstante(10), ConsVariable()))));
	/*version longue
	Arbre = ConsBinaire('*', ConsConstante(10), ConsVariable());
	Arbre = ConsFonction('l', Arbre);
	Arbre = ConsFonction('s', Arbre);
	Arbre = ConsBinaire('+', ConsConstante(1), Arbre);
	*/

	return 0;
}