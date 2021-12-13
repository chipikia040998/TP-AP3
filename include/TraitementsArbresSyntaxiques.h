#pragma once
#include "ArbresSyntaxiques.h"

double EvaluerArbre(TArbreSynt A, double x);
char * ArbreToChaine(TArbreSynt A);
TArbreSynt CopieArbre(TArbreSynt A);
TArbreSynt Deriv(TArbreSynt A);
TArbreSynt CreerArbreAlea (int H);