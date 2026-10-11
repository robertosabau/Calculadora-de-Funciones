#ifndef FUNCION_H
#define FUNCION_H

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

#endif