//inclusion des bibliothèques
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
//inclusion de fichier
#include "../include/TraitementsArbresSyntaxiques.h"
#include "../include/ArbresSyntaxiques.h"
#include "../include/Divers.h"

double EvaluerArbre(TArbreSynt A, double x)
{
	double arg,res,EvalFG,EvalFD;
	char MSG[100];
	switch (Nature(A))
	{
		case Variable:
			return x;
		case Constante:
			return ValeurConstante(A);
		case Fonction:
			arg = EvaluerArbre(Argument(A),x);
			switch (NomFonction((A)))
			{
				case 'c':
					return cos(arg);
				case 's':
					return sin(arg);
				case 'l':
					return log(arg);
				case 't':
					return tan(arg);
				case 'r':
					return sqrt(arg);
				default :
					sprintf(MSG,"Erreur : fonction %c inconnue dans EvaluerArbre", NomFonction(A));
					AfficherMessage(MSG, true);
					return 0;
			}
		case Binaire:
			EvalFG = EvaluerArbre(FG(A), x);
			EvalFD = EvaluerArbre(FD(A), x);
			switch(Operateur(A))
			{
				case '+':
					return EvalFD + EvalFG;
				case '-' :
					return EvalFD - EvalFG;
				case '*' :
					return EvalFG*EvalFD;
				case '/':
					if (EvalFD==0)
					{
						AfficherMessage("""Division par 0 dans EvaluerArbres", true);
						return 0;
					}
					else
					{
						return EvalFG/EvalFD;
					}
			}
	}
	return res;
}