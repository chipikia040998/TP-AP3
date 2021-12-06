//inclusion des bibliothèques
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
//inclusion de fichier
#include "../include/ArbresSyntaxiques.h"

/*************************************************/

TArbreSynt ConsVariable()
{
	TArbreSynt noeud = (TArbreSynt)calloc(1,sizeof(TNoeudSynt));
	assert (noeud);
	noeud->Nature = Variable ;
	return noeud;
}

/*************************************************/

TArbreSynt ConsConstante(double v)
{
	TArbreSynt a = (TArbreSynt)malloc(sizeof(TNoeudSynt));
	assert (a);
	a->Nature = Constante ;
	a->ValConst = v;
	return a;
}

/*************************************************/

TArbreSynt ConsBinaire(char Op, TArbreSynt FG, TArbreSynt FD)
{
	TArbreSynt a = (TArbreSynt)calloc(1,sizeof(TNoeudSynt));
	assert (a);
	a->Nature = Binaire ;
	a->OperOuFct = Op;
	a->fg = FG;
	a->fd = FD;
	return a;
}

/*************************************************/

TArbreSynt ConsFonction(char Fct, TArbreSynt F)
{
	TArbreSynt a = (TArbreSynt)calloc(1,sizeof(TNoeudSynt));
	assert (a);
	a->Nature = Fonction ;
	a->OperOuFct = Fct;
	a->fg = F;
	return a;
}

/*************************************************/

TNature Nature(TArbreSynt A)
{
	return A->Nature;
}

/*************************************************/

double ValeurConstante(TArbreSynt A)
{
	return A->ValConst;
}

/*************************************************/

char Operateur(TArbreSynt A)
{
	return A->OperOuFct;
}

/*************************************************/

TArbreSynt FG(TArbreSynt A)
{
	return A->fg;
}

/*************************************************/

TArbreSynt FD(TArbreSynt A)
{
	return A->fd;
}

/*************************************************/

char NomFonction(TArbreSynt A)
{
	return A->OperOuFct;
}

/*************************************************/
//correspond au ss arbre qui par convention = FG
TArbreSynt Argument(TArbreSynt A)
{
	return A->fg;
}

/*************************************************/

void Liberer(TArbreSynt A)
{
	switch (A->Nature)
	{
		case Binaire :
			Liberer(A->fg);
			Liberer(A->fd);
			free(A);
			break;
		case Fonction :
			Liberer(A->fg);
			free(A);
			break;
		default :
			free(A);	
			break;
	}
}
