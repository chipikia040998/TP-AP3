#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "include/Divers.h"
#include "include/ArbresSyntaxiques.h"
#include "include/TraitementsArbresSyntaxiques.h"

int main (void) 
{	
	/* test pour cfonction AficherMessage
	char MSG[100];
	sprintf(MSG, "1 + sin(ln(10*x))");
	AfficherMessage(MSG, false);
	AfficherMessage("Troisième et dernier message", true);
	AfficherMessage("Dernier message non affihcer", false);
	*/
	/*
	TArbreSynt A = ConsBinaire('+',ConsConstante(1), ConsFonction('s', ConsFonction('l', ConsBinaire('*', ConsConstante(10), ConsVariable()))));
	char *Ch ;
	srand(time(NULL));
	*/
	/*version longue
	Arbre = ConsBinaire('*', ConsConstante(10), ConsVariable());
	Arbre = ConsFonction('l', Arbre);
	Arbre = ConsFonction('s', Arbre);
	Arbre = ConsBinaire('+', ConsConstante(1), Arbre);
	*/
	/*test de Evaluer arbre
	double x=1;
	printf ("En %lf, l'expression devrait valoir %lf et vaut %lf\n", x, 1 + sin(log(10 * x)), EvaluerArbre(A, x));
	x = 10;
	printf("En %lf, l'expression devrait valoir %lf et vaut %lf\n", x, 1 + sin(log(10 * x)), EvaluerArbre(A, x));
	x = 100;
	printf("En %lf, l'expression devrait valoir %lf et vaut %lf\n", x, 1 + sin(log(10 * x)), EvaluerArbre(A, x)); 
	*/
	/* test fonction convertion arbre en chain
	Ch = ArbreToChaine(A);
	printf("La conversion de l'arbre en chaine devrait donner 1.000+s(l(10.000*x)) et donne : %s\n)",Ch);
	free(Ch);
	*/
	/* test de la fonction deriver
	TArbreSynt DerivA = Deriv(A);
 	Ch = ArbreToChaine(DerivA);
 	Liberer(DerivA);
 	printf("La derivee de 1 + s(l(10*x)) est %s\n", Ch);
 	free(Ch); 
	*/
	/*test de arbre alea et comparaison
	bool same;
	TArbreSynt Ar = CreerArbreAlea(10);
	char * Cha = ArbreToChaine(Ar);
	printf("La convertion de l'arbre en chaine aléatoire donne : %s \n",Cha);
	same = Comparaison(Ar, Ar);
	if (Comparaison(A, Ar))
	{
		printf("Les arbres sont identique \n");
	}
	else
	{
		printf("Les Arbres sont différent \n");
	}
	*/

	int HautMax = 10;
	int nbEchecs=0;

	for (int nbTest = 1; nbTest <= 10; nbTest++)
	{
		//création arbre alea
		int HauteurArbreCourant = EntierAleatoire(1, HautMax);
		TArbreSynt A1 = CreerArbreAlea(HautMax);

		//conversion arbre courant en chaine
		char * Chaine = ArbreToChaine(A1); 
		//conversion chaine en arbre
		TArbreSynt A2;
		int Fin;
		ChaineToArbre(Chaine, 0, &A2, &Fin);

		//comparaison des 2 arbres
		if (!Comparaison(A1, A2))
		{
			nbEchecs++;
		}

		free(Chaine);
		Liberer(A1);
		Liberer(A2);
	}

	if (nbEchecs>0)
	{
		printf("Le long test a echoue %d fois \n", nbEchecs);
	}
	else
	{
		printf("Le long test a reussi");
	}


	//Liberer(A);
	return 0;
}