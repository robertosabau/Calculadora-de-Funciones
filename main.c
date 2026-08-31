#include <stdio.h> 
#include <stdbool.h>
#include <stdint.h>
#include <math.h>
#include "funcion.h"
#include "Calculos.h"

//DECLARACIONES METODOS
void menuPrincipal();
void refrescoPantalla();
void esperaEnter();
void opcionIncorrecta();
bool menuSeleccionFuncion();
bool menuSeleccionGradoPolinomio();
void seleccionParametrosPolinomio(int grado,double *array);
void dibujarFuncionPolinomica(int grado);
bool menuFuncion(Funcion *funcion);
void dibujarFuncion(Funcion *funcion);
void dibujarFuncionPolinomica2(Funcion *funcion);
double obtenerX();
void mostrarResultadoCalculoX(double x,double resultado);
void mostrarResultadoObtenerIgual0(double *x,Funcion *funcion);

//DESCRIPCION METODOS
void menuPrincipal(){
    refrescoPantalla();
    printf("1. CREAR FUNCION \n");
    printf("0. SALIR\n");
}
void refrescoPantalla(){
    for (int a=0;a<50;a++){
        printf("\n");
    }
}
void esperaEnter(){
    while (getchar() != '\n' && getchar() != EOF);
    getchar();
}
void opcionIncorrecta(){
    refrescoPantalla();
    printf("OPCION NO VALIDA\n");
    printf("PRESIONE ENTER PARA CONTINUAR");
    esperaEnter();
}
bool menuSeleccionFuncion(){
    while (true){
        int seleccion;
        refrescoPantalla();
        printf("SELECCIONA EL TIPO DE FUNCION\n");
        printf("1. POLINOMIO \n");
        printf("2. EXPONENCIAL \n");
        printf("3. LOGARITMO \n");
        printf("4. TRIGONOMETRICA \n");
        printf("0. REGRESAR AL MENU PRINCIPAL\n");
        scanf("%d",&seleccion);
        switch (seleccion){
            case 1:
                if (menuSeleccionGradoPolinomio()){
                    return true;
                }
            break;
            case 0:
            return false;
            break;
            default:
            opcionIncorrecta();
            break;
        }
    }
}
bool menuSeleccionGradoPolinomio(){
    while (true){
        int seleccion;
        refrescoPantalla();
        printf("SELECCIONA EL GRADO DEL POLINOMIO\n");
        printf("1. GRADO 1 \n");
        printf("2. GRADO 2 \n");
        printf("0. VOLVER ATRAS\n");
        scanf("%d",&seleccion);
        switch (seleccion){
            case 1:{
                double parametros[2];
                seleccionParametrosPolinomio(1,parametros);
                Funcion funcion;
                funcion.cantidadvalores=2;
                funcion.tipo=POLINOMIO;
                funcion.valores=parametros;
                if (menuFuncion(&funcion)){
                    return true;
                }
            break;}
            case 2:{
                double parametros[3];
                seleccionParametrosPolinomio(2,parametros);
                Funcion funcion;
                funcion.cantidadvalores=3;
                funcion.tipo=POLINOMIO;
                funcion.valores=parametros;
                if (menuFuncion(&funcion)){
                    return true;
                }
            break;}
            case 0:
            return false;
            break;
            default:
            opcionIncorrecta();
            break;
        }
    }
}
void seleccionParametrosPolinomio(int grado,double *array){
    refrescoPantalla();
    dibujarFuncionPolinomica(grado);
    switch (grado){
        case 1:
            printf("INTRODUCE PARAMETRO a: ");
            scanf("%lf",&array[0]);
            printf("INTRODUCE PARAMETRO b: ");
            scanf("%lf",&array[1]);
        break;
        case 2:
            printf("INTRODUCE PARAMETRO a: ");
            scanf("%lf",&array[0]);
            printf("INTRODUCE PARAMETRO b: ");
            scanf("%lf",&array[1]);
            printf("INTRODUCE PARAMETRO c: ");
            scanf("%lf",&array[2]);
        break;
    }
}
void dibujarFuncionPolinomica(int grado){
    switch (grado){
        case 1:
            printf("TU FUNCION: aX + b\n");
            break;
        case 2:
            printf("TU FUNCION: ax^2 + bx + c\n");
            break;
    }
}
bool menuFuncion(Funcion *funcion){
    while (true){
        int seleccion;
        refrescoPantalla();
        dibujarFuncion(funcion);
        printf("1. CALCULAR VALOR X \n");
        printf("2. CALCULAR F(X)=0 \n");
        printf("0. REGRESAR AL MENU PRINCIPAL\n");
        scanf("%d",&seleccion);
        switch (seleccion){
            case 0:
            return true;
            break;
            case 1:
                double x=obtenerX();
                double resultado=calculoValorX(x,funcion);
                mostrarResultadoCalculoX(x,resultado);
            break;
            case 2:
                double *x2=calculoValorIgual0(funcion);
                mostrarResultadoObtenerIgual0(x2,funcion);

            break;
            default:
                opcionIncorrecta();
            break;
        }
    }
}
void dibujarFuncion(Funcion *funcion){
    switch (funcion->tipo){
        case POLINOMIO:
            dibujarFuncionPolinomica2(funcion);
        break;
    }
}
void dibujarFuncionPolinomica2(Funcion *funcion){
    switch (funcion->cantidadvalores){
        case 2:
            printf("TU FUNCION: %2lfX + %2lf\n",funcion->valores[0],funcion->valores[1]);
            break;
        case 3:
            printf("TU FUNCION: %2lfx^2 + %2lfx + %2lf\n",funcion->valores[0],funcion->valores[1],funcion->valores[2]);
            break;
    }
}
double obtenerX(){
    double x;
    refrescoPantalla();
    printf("INTRODUCE EL VALOR DE X PARA EVALUAR: ");
    scanf("%lf",&x);
    return x;
}
void mostrarResultadoCalculoX(double x,double resultado){
    refrescoPantalla();
    printf("F( %2lf ) = %2lf \n",x,resultado);
    printf("PULSE ENTER PARA CONTINUAR");
    esperaEnter();
}
void mostrarResultadoObtenerIgual0(double* x,Funcion *funcion){
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
        }
        printf("PULSE ENTER PARA CONTINUAR");
    }
    else{
        printf("NO EXISTE UN VALOR DONDE ES F(X)=0\n");
        printf("PULSE ENTER PARA CONTINUAR");
    }
    esperaEnter();
}

int main(){
    while(true){
        int seleccion;
        menuPrincipal();
        scanf("%d",&seleccion);
        switch (seleccion){
            case 1:
                menuSeleccionFuncion();
            break;
            case 0:
                return 0;
            break;
            default:
                opcionIncorrecta();
            break;
        }
    }
}