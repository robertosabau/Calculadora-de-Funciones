#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <string.h>
#include "funcion.h"
#include "Ilustrar.h"
#include "Conversor.h"

double calculoValorX(double x,Funcion *funcion){
    if (funcion==NULL){
        return DBL_MIN;
    }
    double resultado=0;
    switch (funcion->tipo){
        case POLINOMIO:
            switch (funcion->cantidadvalores){
                case 2:
                resultado=funcion->valores[0]*x+funcion->valores[1];
                break;
                case 3:
                resultado=funcion->valores[0]*pow(x,2)+funcion->valores[1]*x+funcion->valores[2];
                break;
            }
        break;
        case EXPONENCIAL:
            resultado=pow(funcion->valores[0],x);
        break;
        case LOGARITMO:
            resultado=log(x)/log(funcion->valores[0]);
        break;
        case SENO:
            resultado=sin(x*funcion->valores[0]);
        break;
        case COSENO:
            resultado=cos(x*funcion->valores[0]);
        break;
        case TANGENTE:
            resultado=tan(x*funcion->valores[0]);
        break;
    }
    return resultado;
}

double* calculoValorIgual0(Funcion *funcion){
    if (funcion==NULL){
        return NULL;
    }
    switch (funcion->tipo){
        case POLINOMIO:
            switch (funcion->cantidadvalores)
            {
            case 2:
                static double resultado;
                resultado=-funcion->valores[1]/funcion->valores[0];
                return &resultado;
            break;
            case 3:
                if (funcion->valores[0]!=0){
                    static double resultado2[2];
                    resultado2[0]=(-funcion->valores[1]+sqrt(pow(funcion->valores[1],2)-4*funcion->valores[2]*funcion->valores[0]))/(2*funcion->valores[0]);
                    resultado2[1]=(-funcion->valores[1]-sqrt(pow(funcion->valores[1],2)-4*funcion->valores[2]*funcion->valores[0]))/(2*funcion->valores[0]);
                    return resultado2;
                }
                else{
                    static double resultado;
                    resultado=-funcion->valores[1]/funcion->valores[0];
                    return &resultado;
                }
            break;
        }
        case EXPONENCIAL:
            static double resultado;
            resultado=-INFINITY;
            return &resultado;
        break;
        case LOGARITMO:
            static double resultado1;
            resultado1=1;
            return &resultado1;
        break;
        case SENO:
            static double resultado3;
            resultado3=0;
            return &resultado3;
        break;
        case COSENO:
            static double resultado4;
            resultado4=1.570796/funcion->valores[0];
            return &resultado4;
        break;
        case TANGENTE:
            static double resultado5;
            resultado5=0;
            return &resultado5;
        break;
    }
}
bool calculoDerivada(Funcion *funcion){
    if (funcion==NULL){
        errorPuntero();
        return true;
    }
    refrescoPantalla();
    char *funcio=malloc(1024);
    funcio[0]='\0';
    convertirDerivadaATexto(funcion,funcio);
    if (funcio[0]!='\0'){
        printf("f'(x) = %s\n", funcio);
        free(funcio);
        return false;
    }
    printf("No existe la derivada de la funcion\n");
    free(funcio);
    return true;
}
bool calculoIntegral(Funcion *funcion){
    if (funcion==NULL){
        errorPuntero();
        return true;
    }
    refrescoPantalla();
    char *funcio=malloc(1024);
    funcio[0]='\0';
    convertirIntegralATexto(funcion,funcio);
    if (funcio[0]!='\0'){
        printf("∫f(x) = %s\n", funcio);
        free(funcio);
        return false;
    }
    printf("No existe la integral de la funcion\n");
    free(funcio);
    return true;
}