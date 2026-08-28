#include <stdio.h> 
#include <stdbool.h>
#include <stdint.h>
#include <funcion.h>

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
        printf("SELECCIONA EL TIPO DE FUNCION\n");
        printf("1. GRADO 1 \n");
        printf("2. GRADO 2 \n");
        printf("0. REGRESAR AL MENU PRINCIPAL\n");
        scanf("%d",&seleccion);
        switch (seleccion){
            case 1:
                double parametros[2];
                seleccionParametrosPolinomio(1,parametros);
                Funcion funcion;
                funcion.cantidadvalores=2;
                funcion.tipo=POLINOMIO;
                funcion.valores=parametros;

            break;
            case 2:
                double parametros[3];
                seleccionParametrosPolinomio(2,parametros);
            break;
            case 0:
            return false;
            break;
            default:
            opcionIncorrecta();
            break;
        }
    }
    return false;
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
            printf("TU FUNCION: aX + b");
            break;
        case 2:
            printf("TU FUNCION: ax2 + bx + c");
    }
}
bool menuFuncion(Funcion *funcion){
    
}