#include "funcion.h"
#include <math.h>

double calculoValorX(double x,Funcion *funcion){
    double resultado=0;
    switch (funcion->tipo){
        case POLINOMIO:
            switch (funcion->cantidadvalores){
                case 2:
                resultado=funcion->valores[0]*x+funcion->valores[1];
                break;
                case 3:
                resultado=funcion->valores[0]*pow(2,x)+funcion->valores[1]*x+funcion->valores[2];
                break;
            }
        break;
    }
    return resultado;
}