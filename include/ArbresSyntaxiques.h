#pragma once

//Définition d'un tpe énuméré pour la nature du noeud
typedef enum {Constante,Variable,Binaire,Fonction} TNature;

/*Définitions de stypes Noeud syntaxiques et Arbre syntaxiques
le membre "nature" dit si le coeud est contante variable etc
Si noeud binaire, l'aopérateur est dans OperOuFct et les deux fils dans dans fg et fd 
Si noeuf fonction, le premier caractère du nom est dans OperOuFct et le fils dans fg
Si noeuf constante, dans ValConst
Si Noeud variable, aucune info utile*/
typedef struct NoeudSynt{
	TNature Nature;
	double ValConst;
	char OperOuFct;
	struct NoeudSynt *fg,*fd;
}TNoeudSynt,*TArbreSynt;

/**************************/
/**PRIMITIVE Construction**/
/**************************/
TArbreSynt ConsVariable();
TArbreSynt ConsConstante(double v);
TArbreSynt ConsBinaire(char Op, TArbreSynt FG, TArbreSynt FD);
TArbreSynt ConsFonction(char Fct, TArbreSynt F);

/**************************/
/**PRIMITIVE Consultation**/
/**************************/
TNature Nature(TArbreSynt A);
double ValeurConstante(TArbreSynt A);
char Operateur(TArbreSynt A);
TArbreSynt FG(TArbreSynt A);
TArbreSynt FD(TArbreSynt A);
char NomFonction(TArbreSynt A);
TArbreSynt Argument(TArbreSynt A);

/************************/
/**PRIMITIVE Libération**/
/************************/
void Liberer(TArbreSynt A);