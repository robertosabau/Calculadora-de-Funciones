#include <stdio.h> 
#include "funcion.h"

//Metodos del main
extern void refrescoPantalla();
extern void esperaEnter();

int lecturaEntero(void (*texto)(void)){
    int numero;
    while (scanf("%d",&numero)!=1){
        refrescoPantalla();
        printf("TIENE QUE INTRODUCIR UN NUMERO ENTERO\n");
        printf("PULSE ENTER PARA CONTINUAR");
        esperaEnter();
        refrescoPantalla();
        texto();
    }
    return numero;
}
int lecturaEntero2(void (*texto)(Funcion*),Funcion *funcion){
    int numero;
    while (scanf("%d",&numero)!=1){
        refrescoPantalla();
        printf("TIENE QUE INTRODUCIR UN NUMERO ENTERO\n");
        printf("PULSE ENTER PARA CONTINUAR");
        esperaEnter();
        refrescoPantalla();
        texto(funcion);
    }
    return numero;
}
double lecturaFlotante(void (*texto)(void)){
    double numero;
    while (scanf("%lf",&numero)!=1){
        refrescoPantalla();
        printf("TIENE QUE INTRODUCIR UN NUMERO\n");
        printf("PULSE ENTER PARA CONTINUAR");
        esperaEnter();
        refrescoPantalla();
        texto();
    }
    return numero;
}