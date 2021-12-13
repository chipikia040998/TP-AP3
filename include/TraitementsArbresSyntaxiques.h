#pragma once
#include "ArbresSyntaxiques.h"

double EvaluerArbre(TArbreSynt A, double x);
char * ArbreToChaine(TArbreSynt A);
TArbreSynt CopieArbre(TArbreSynt A);
TArbreSynt Deriv(TArbreSynt A);
TArbreSynt CreerArbreAlea (int H);
bool Comparaison (TArbreSynt Arbr1, TArbreSynt Arbr2);
void ChaineToArbre (const char ch[], int deb, TArbreSynt* PA, int *PFin);
void Echantillonner(const char Expr[], double XMin, double XMax, int NbP, const char N[] );