#ifndef CONVERSOR_H
#define CONVERSOR_H
#include "funcion.h"

//Metodo para convertir a subindice un parametro
void convertirASubindice(double numero,char* resultado);
//Metodo para convertir una funcion en un string
void convertirFuncionATexto(Funcion *funcion,char* resultado);
//Metodo para convertir la derivada de una función en un string
void convertirDerivadaATexto(Funcion *funcion,char *resultado);
//Metodo para convertir la integral de una funcion en un string
void convertirIntegralATexto(Funcion *funcion,char *resultado);
//Metodo para concatenar un numero en un lugar
void concatenarNumeros(char*buffer,char*resultado);
//Metodo para concatenar correctamente el caracter
bool concatenarNumeroConLogica(Funcion *funcion,char*resultado,int pos,bool x);
//Metodo para convertir a superindice un parametro
void convertirASuperindice(double numero,char* resultado);
#endif