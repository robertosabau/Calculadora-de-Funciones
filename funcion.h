#ifndef FUNCION_H
#define FUNCION_H

typedef enum{
    POLINOMIO
} TipoFuncion;

typedef struct{
    TipoFuncion tipo;
    int cantidadvalores;
    double *valores;
} Funcion;

#endif