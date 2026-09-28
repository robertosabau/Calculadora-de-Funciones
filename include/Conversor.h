#ifndef CONVERSOR_H
#define CONVERSOR_H
#include "funcion.h"

//Metodo para convertir a subindice un parametro
void convertirASubindice(double numero,char* resultado);
//Metodo para convertir una funcion en un string
void convertirATexto(Funcion *funcion,char* resultado);
//Metodo para concatenar un numero en un lugar
void concatenarNumeros(char*buffer,char*resultado);

#endif