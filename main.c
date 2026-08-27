#include <stdio.h> 
#include <stdbool.h>
#include <stdint.h>

//DECLARACIONES METODOS
void menuPrincipal();
void refrescoPantalla();
void esperaEnter();
void opcionIncorrecta();
bool menuSeleccionFuncion();
bool menuSeleccionGradoPolinomio();

int main(){
    while(true){
        int seleccion;
        menuPrincipal();
        scanf("%d",&seleccion);
        switch (seleccion){
            case 1:
                menuSeleccionFuncion();
            break;
            case 2:
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
    printf("2. SALIR\n");
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
        printf("2. REGRESAR AL MENU PRINCIPAL\n");
        scanf("%d",&seleccion);
        switch (seleccion){
            case 1:

            break;
            case 2:
            return false;
            break;
            default:
            opcionIncorrecta();
            break;
        }
    }
    return false;
}
