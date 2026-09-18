#include <stdio.h> 
#include <string.h>
#include "funcion.h"

//Metodos del main
extern void refrescoPantalla();
extern void esperaEnter(bool limpiar);

int lecturaEntero(void (*texto)(void)){
    int numero;
    while (scanf("%d",&numero)!=1){
        refrescoPantalla();
        printf("TIENE QUE INTRODUCIR UN NUMERO ENTERO\n");
        printf("PULSE ENTER PARA CONTINUAR");
        esperaEnter(true);
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
        esperaEnter(true);
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
        esperaEnter(true);
        refrescoPantalla();
        texto();
    }
    return numero;
}
void lecturaString(void (*texto)(void),char*buffer,int cantidad){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    fgets(buffer,cantidad,stdin);
    while(strcmp(buffer,"\n")==0||strlen(buffer)<= 1){
        refrescoPantalla();
        printf("TIENES QUE INTRODUCIR UN TEXTO VALIDO");
        printf("PULSE ENTER PARA CONTINUAR");
        esperaEnter(false);
        refrescoPantalla();
        texto();
        fgets(buffer,cantidad,stdin);
    }
    buffer[strcspn(buffer, "\n")] = '\0';
}