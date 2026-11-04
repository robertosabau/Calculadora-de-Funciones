#ifndef FUNCION_H
#define FUNCION_H
#include <stdbool.h>

typedef enum{
    POLINOMIO,
    EXPONENCIAL,
    LOGARITMO,
    COSENO,
    SENO,
    TANGENTE,
    RADICAL,
    FACTORIAL,
    VALOR_ABSOLUTO
} TipoFuncion;

typedef struct{
    TipoFuncion tipo;
    int cantidadvalores;
    double *valores;
} Funcion;

bool comprobacionTipoCorrecto(TipoFuncion tipo);

#endif