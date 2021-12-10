//inclusion des bibliothèques
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
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

char * ArbreToChaine(TArbreSynt A)
{
	char * Chain, * temp;
	char * G, * D, *arg;
	char *Racine;
	char ch[100];
	int n;

	switch(Nature(A))
	{
		case Variable:
			Chain = (char*)malloc(2 * sizeof(char));
			if(Chain == NULL)
			{
				AfficherMessage("TraitementArbresSyntaxiques:ArbreToChaine:Variable : memoire pleine", true);
				return NULL;
			}
			else
			{
				Chain[0]='x';
				Chain[1]='\0';
				return Chain;
			}
		case Constante:
			n = sprintf(ch, "%lf", ValeurConstante(A));
			Chain= (char*)malloc(sizeof(char) * (n+1));
			if(Chain == NULL)
			{
				AfficherMessage("TraitementArbresSyntaxiques:ArbreToChaine:Constante : memoire pleine", true);
				return NULL;
			}
			else
			{
				strcpy(Chain,ch);
				return Chain;
			}
		case Fonction:
			arg = ArbreToChaine(Argument(A));
			n=strlen(arg)+4;
			Chain=(char*)malloc(sizeof(char) * n);
			if(Chain == NULL)
			{
				AfficherMessage("TraitementArbresSyntaxiques:ArbreToChaine:Fonction : memoire pleine", true);
				return NULL;
			}
			else
			{
				sprintf(Chain,"%c(%s)",NomFonction(A),arg);
				return Chain;
			}
		case Binaire:
			G = ArbreToChaine( FG(A) );
			D = ArbreToChaine( FD(A) );
			
			if (Nature(FG(A)) == Binaire)
			{
				n = strlen(G);
				temp = (char*)malloc(sizeof(char) * (n+3)); 
				if(temp==NULL)
				{
					AfficherMessage("TraitementArbresSyntaxiques:ArbreToChaine:Bianire : memoire pleine", true);
					return NULL;
				}
				else
				{
					sprintf(temp,"(%s)",G);
					free(G);
					G = temp;
				}
			}
			if (Nature(FD(A)) == Binaire)
			{
				n = strlen(D);
				temp = (char*)malloc(sizeof(char) * (n+3)); 
				if(temp==NULL)
				{
					AfficherMessage("TraitementArbresSyntaxiques:ArbreToChaine:Bianire : memoire pleine", true);
					return NULL;
				}
				else
				{
					sprintf(temp,"(%s)",D);
					free(D);
					D = temp;
				}
			}

			n = strlen(G) + strlen(D) + 2;
			Chain = (char*)malloc(sizeof(char) * n);
			if (Chain == NULL)
			{
				AfficherMessage("TraitementArbresSyntaxiques:ArbreToChaine:Bianire : memoire pleine", true);
				return NULL;
			}
			else
			{
				sprintf(Chain,"%s%c%s",G,Operateur(A),D);
				free(G);
				free(D);
				return Chain;
			}
		default :
			AfficherMessage("Nature incorrect",true);
			return NULL;
	}

	
	return Chain;
}

TArbreSynt CopieArbre(TArbreSynt A)
{
	switch(Nature(A))
	{
		case Variable:
			return ConsVariable();
		case Constante :
			return ConsConstante(ValeurConstante(A));
		case Fonction :
			return ConsFonction(NomFonction(A),CopieArbre(Argument(A)));
		case Binaire:
			return ConsBinaire(Operateur(A),CopieArbre(FG(A)),CopieArbre(FD(A)));
		default :
			AfficherMessage("Erreur de nature dans l'arbre",true);
	}
}

TArbreSynt Deriv(TArbreSynt A)
{
	TArbreSynt Copie;
	switch(Nature(A))
	{
		case Variable:
			return ConsConstante(1);
		case Constante:
			return ConsConstante(0);
		case Fonction :
	        switch (NomFonction(A))
	        {
		        case 'c':
		            return ConsBinaire('-',ConsConstante(0),ConsBinaire('*',ConsFonction('s', CopieArbre(Argument(A))),Deriv(Argument(A))));
		        case 's':
		            return ConsBinaire('*',ConsFonction('c', CopieArbre(Argument(A))),Deriv(Argument(A)));
		        case 'l':
		            return ConsBinaire('/',Deriv(Argument(A)),CopieArbre(Argument(A)));
		        case 't':;
		        case 'r':;
		        default:
		            AfficherMessage("Derivation:Fonction : Fonction inconnu", true);
		            return NULL;
			}
		case Binaire :
			switch(Operateur(A))
			{
				case '+':
					return ConsBinaire(Operateur(A), Deriv(FG(A)), Deriv(FD(A)));
				case '-' :
					return ConsBinaire(Operateur(A), Deriv(FG(A)), Deriv(FD(A)));
				case '*' :
					return ConsBinaire('+', ConsBinaire('*', Deriv(FG(A)), CopieArbre(FD(A))), ConsBinaire('*', CopieArbre(FG(A)), Deriv(FD(A))));
				case '/':
					return ConsBinaire('/',ConsBinaire('-',ConsBinaire('*',Deriv(FG(A)),CopieArbre(FD(A))),ConsBinaire('*',CopieArbre(FG(A)),Deriv(FD(A)))),ConsBinaire('*',CopieArbre(FD(A)),CopieArbre(FD(A))));
				default :
					AfficherMessage("Derivation : Operateur inconnue", true);
					return NULL;
			}
	}
}