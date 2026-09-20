#ifndef CALCULOS_H
#define CALCULOS_H
#include "funcion.h"

//Calcular un valor de x especifica
double calculoValorX(double x,Funcion *funcion);
//Calcular cuando una funcion da 0
double* calculoValorIgual0(Funcion *funcion);
//Calcular la derivada de una funcion
bool calculoDerivada(Funcion *funcion);
#endif