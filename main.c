#include <stdio.h> 
#include <stdbool.h>
#include <stdint.h>

//DECLARACIONES METODOS
void menuPrincipal();
void refrescoPantalla();
void esperaEnter();

int main(){
    while(true){
        int seleccion;
        menuPrincipal();
        scanf("%d",&seleccion);
        switch (seleccion){
            case 1:

            break;
            case 2:
                return 0;
            break;
            default:
                refrescoPantalla();
                printf("OPCION NO VALIDA\n");
                printf("PRESIONE ENTER PARA CONTINUAR");
                esperaEnter();
            break;
        }
    }
    

}

//DESCRIPCION METODOS
void menuPrincipal(){
    refrescoPantalla();
    printf("1. Crear funcion \n");
    printf("2. Salir\n");
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