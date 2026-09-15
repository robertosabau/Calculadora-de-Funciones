#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "funcion.h"

extern void esperaEnter();

void refrescoPantalla(){
    //Windows
    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    //Basados Unix
    #elif defined(__linux__) || defined(__unix__) || defined(__APPLE__)
        system("clear");
    //Cualquier otra cosa
    #else
        for (int i = 0; i < 50; i++) {
            printf("\n");
        }
    #endif
}
void opcionIncorrecta(){
    refrescoPantalla();
    printf("OPCION NO VALIDA\n");
    printf("PRESIONE ENTER PARA CONTINUAR");
    esperaEnter();
}
void errorPuntero(void){
    refrescoPantalla();
    printf("HA OCURRIDO UN PROBLEMA\n");
    printf("PULSE ENTER PARA CONTINUAR");
    esperaEnter();
}
void menuPrincipal(){
    refrescoPantalla();
    printf("1. CREAR FUNCION \n");
    printf("0. SALIR\n");
}
void menuTiposFuncion(){
    refrescoPantalla();
    printf("SELECCIONA EL TIPO DE FUNCION\n");
    printf("1. POLINOMIO \n");
    printf("2. EXPONENCIAL \n");
    printf("3. LOGARITMO \n");
    printf("4. TRIGONOMETRICA \n");
    printf("0. REGRESAR AL MENU PRINCIPAL\n");
}
void gradoPolinomioDisponible(){
    refrescoPantalla();
    printf("SELECCIONA EL GRADO DEL POLINOMIO\n");
    printf("1. GRADO 1 \n");
    printf("2. GRADO 2 \n");
    printf("0. VOLVER ATRAS\n");
}
void tiposTrigonometrica(){
    refrescoPantalla();
    printf("SELECCIONE UNA FUNCION TRIGONOMETRICA\n");
        printf("1. SENO\n");
        printf("2. COSENO\n");
        printf("3. TANGENTE\n");
        printf("0. VOLVER ATRAS\n");
}
void buscarAtributoA(){
    printf("INTRODUCE EL ATRIBUTO a: ");
}
void buscarAtributoB(){
    printf("INTRODUCE EL ATRIBUTO b: ");
}
void buscarAtributoC(){
    printf("INTRODUCE EL ATRIBUTO c: ");
}
bool dibujarFuncion(Funcion *funcion){
    if (funcion==NULL){
        errorPuntero();
        return true;
    }
    switch (funcion->tipo){
        case POLINOMIO:
            switch (funcion->cantidadvalores){
            case 2:
                printf("TU FUNCION: %2lfX + %2lf\n",funcion->valores[0],funcion->valores[1]);
                break;
            case 3:
                printf("TU FUNCION: %2lfx^2 + %2lfx + %2lf\n",funcion->valores[0],funcion->valores[1],funcion->valores[2]);
                break;
            }
        break;
        case EXPONENCIAL:
            printf("TU FUNCION: %2lf^x\n",funcion->valores[0]);
        break;
        case LOGARITMO:
            printf("TU FUNCION: log%2lf(x)\n",funcion->valores[0]);
        break;
        case SENO:
            printf("TU FUNCION: sin(%2lfx)\n",funcion->valores[0]);
        break;
        case COSENO:
            printf("TU FUNCION: cos(%2lfx)\n",funcion->valores[0]);
        break;
        case TANGENTE:
            printf("TU FUNCION: tan(%2lfx)\n",funcion->valores[0]);
        break;
    }
    return false;
}
void dibujarFuncion2(TipoFuncion tipo, int grado){
    refrescoPantalla();
    switch (tipo){
        case POLINOMIO:
            switch (grado){
            case 1:
                printf("TU FUNCION: aX + b\n");
                break;
            case 2:
                printf("TU FUNCION: ax^2 + bx + c\n");
                break;
            }
        break;
        case EXPONENCIAL:
            printf("TU FUNCION: a^x\n");
        break;
        case LOGARITMO:
            printf("TU FUNCION: log_a(x)\n");
        break;
        case SENO:
            printf("TU FUNCION: sin(ax)\n");
        break;
        case COSENO:
            printf("TU FUNCION: cos(ax)\n");
        break;
        case TANGENTE:
            printf("TU FUNCION: tan(ax)\n");
        break;
    }
}
void opcionesMenuFuncion(Funcion *funcion){
    refrescoPantalla();
    dibujarFuncion(funcion);
    printf("1. CALCULAR VALOR X \n");
    printf("2. CALCULAR F(X)=0 \n");
    printf("0. REGRESAR AL MENU PRINCIPAL\n");
}
double obtenerX(){
    double x;
    refrescoPantalla();
    printf("INTRODUCE EL VALOR DE X PARA EVALUAR: ");
    while (scanf("%lf",&x)!=1){
        refrescoPantalla();
        printf("TIENE QUE INTRODUCIR UN NUMERO ENTERO\n");
        printf("PULSE ENTER PARA CONTINUAR");
        esperaEnter();
        refrescoPantalla();
        printf("INTRODUCE EL VALOR DE X PARA EVALUAR: ");
    }
    return x;
}
void mostrarResultadoCalculoX(double x,double resultado){
    refrescoPantalla();
    printf("F( %2lf ) = %2lf \n",x,resultado);
    printf("PULSE ENTER PARA CONTINUAR");
    esperaEnter();
}
bool mostrarResultadoObtenerIgual0(double* x,Funcion *funcion){
    if (funcion==NULL||x==NULL){
        errorPuntero();
        return true;
    }
    refrescoPantalla();
    if(isfinite(x[0])){
        switch (funcion->tipo){
            case POLINOMIO:
                switch(funcion->cantidadvalores){
                    case 2:
                        printf("RESULTADO = %2lf\n",x[0]);
                    break;
                    case 3:
                        printf("RESULTADO 1 = %2lf\n",x[0]);
                        printf("RESULTADO 2 = %2lf\n",x[1]);
                    break;
                }
            break;
            case LOGARITMO:
                printf("RESULTADO = %2lf\n",x[0]);
            break;
            case COSENO:
                printf("RESULTADO = %2lf\n",x[0]);
            break;
            case SENO:
                printf("RESULTADO = %2lf\n",x[0]);
            break;
            case TANGENTE:
                printf("RESULTADO = %2lf\n",x[0]);
            break;
        }
        printf("PULSE ENTER PARA CONTINUAR");
    }
    else{
        printf("NO EXISTE UN VALOR DONDE F(X)=0\n");
        printf("PULSE ENTER PARA CONTINUAR");
    }
    esperaEnter();
    return false;
}