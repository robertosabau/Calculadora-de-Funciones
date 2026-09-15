#include <stdio.h> 
#include <stdbool.h>
#include <stdint.h>
#include <math.h>
#include <float.h>
#include "funcion.h"
#include "Calculos.h"
#include "Lecturas.h"
#include "Ilustrar.h"

//DECLARACIONES METODOS
//Esperar un enter del jugador
void esperaEnter(void);
//Obtener el atributo a de la función
double obtenerAtributoA(void);
//Obtener el atributo b de la función
double obtenerAtributoB(void);
//Obtener el atributo c de la función
double obtenerAtributoC(void);
//Seleccion del tipo de funcion deseada
bool menuSeleccionFuncion(void);
//Seleccion tipo de funcion trigonometrica
bool menuSeleccionTipoTrigonometrica(void);
//Selección parametro función exponencial
bool menuParametroExponencial(void);
//Seleccion parametro funcion logaritmo
bool menuParametroLogaritmo(void);
//Seleccion del grado del polinomio
bool menuSeleccionGradoPolinomio(void);
//Selección de los parametros del polinomio
bool seleccionParametrosPolinomio(int grado,double *array);
//Menu de la funcion
bool menuFuncion(Funcion *funcion);
void mostrarResultadoCalculoX(double x,double resultado);
bool mostrarResultadoObtenerIgual0(double *x,Funcion *funcion);

//DESCRIPCION METODOS
void esperaEnter(){
    int c;
    while (c=getchar() != '\n' && c != EOF);
    getchar();
}
double obtenerAtributoA(){
    buscarAtributoA();
    double numero=lecturaFlotante(buscarAtributoA);
    return numero;
}
double obtenerAtributoB(){
    buscarAtributoB();
    double numero=lecturaFlotante(buscarAtributoB);
    return numero;
}
double obtenerAtributoC(){
    buscarAtributoB();
    double numero=lecturaFlotante(buscarAtributoB);
    return numero;
}
bool menuSeleccionFuncion(){
    while (true){
        int seleccion;
        menuTiposFuncion();
        seleccion=lecturaEntero(menuTiposFuncion);
        switch (seleccion){
            case 1:
                if (menuSeleccionGradoPolinomio()){
                    return true;
                }
            break;
            case 2:
                if(menuParametroExponencial()){
                    return true;
                }
            break;
            case 3:
                if(menuParametroLogaritmo()){
                    return true;
                }
            break;
            case 4:
                if (menuSeleccionTipoTrigonometrica()){
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
bool menuSeleccionTipoTrigonometrica(){
    while (true){
        tiposTrigonometrica();
        int seleccion;
        seleccion=lecturaEntero(tiposTrigonometrica);
        switch (seleccion)
        {
            case 1:
            break;
            case 2:
            break;
            case 3:
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
bool menuParametroExponencial(){
    refrescoPantalla();
    double a;
    dibujarFuncion2(EXPONENCIAL,0);
    a=obtenerAtributoA();
    Funcion funcion;
    funcion.cantidadvalores=1;
    funcion.tipo=EXPONENCIAL;
    funcion.valores=&a;
    return menuFuncion(&funcion);
}
bool menuParametroLogaritmo(){
    bool parametroCorrecto=false;
    double a;
    while(!parametroCorrecto){
        refrescoPantalla();
        dibujarFuncion2(LOGARITMO,0);
        a=obtenerAtributoA();
        if(a>0&&a!=1){
            parametroCorrecto=true;
        }
        else{
            refrescoPantalla();
            printf("EL PARAMETRO NO ES CORRECTO");
            esperaEnter();
        }
    }
    Funcion funcion;
    funcion.cantidadvalores=1;
    funcion.tipo=LOGARITMO;
    funcion.valores=&a;
    return menuFuncion(&funcion);
}
bool menuSeleccionGradoPolinomio(){
    while (true){
        gradoPolinomioDisponible();
        int seleccion=lecturaEntero(gradoPolinomioDisponible);
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
                if (seleccionParametrosPolinomio(2,parametros)){
                    return true;
                }
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
bool seleccionParametrosPolinomio(int grado,double *array){
    if (array==NULL){
        errorPuntero();
        return true;
    }
    refrescoPantalla();
    dibujarFuncion2(POLINOMIO,grado);
    switch (grado){
        case 1:
            array[0]=obtenerAtributoA();
            array[1]=obtenerAtributoB();
        break;
        case 2:
            array[0]=obtenerAtributoA();
            array[1]=obtenerAtributoB();
            array[2]=obtenerAtributoC();
        break;
    }
    return false;
}
bool menuFuncion(Funcion *funcion){
    if (funcion!=NULL){
        while (true){
            int seleccion;
            opcionesMenuFuncion(funcion);
            seleccion=lecturaEntero2(opcionesMenuFuncion,funcion);
            switch (seleccion){
                case 0:
                return true;
                break;
                case 1:
                    double x=obtenerX();
                    if (x==DBL_MIN){
                        errorPuntero();
                        return true;
                    }
                    double resultado=calculoValorX(x,funcion);
                    mostrarResultadoCalculoX(x,resultado);
                break;
                case 2:
                    double *x2=calculoValorIgual0(funcion);
                    if (x2==NULL){
                        errorPuntero();
                        return true;
                    }
                    if(mostrarResultadoObtenerIgual0(x2,funcion)){
                        return true;
                    }
                break;
                default:
                    opcionIncorrecta();
                break;
            }
        }
    }
    else{
        errorPuntero();
        return true;
    }
    
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
int main(){
    while(true){
        int seleccion;
        menuPrincipal();
        seleccion=lecturaEntero(menuPrincipal);
        switch (seleccion){
            case 1:
                menuSeleccionFuncion();
            break;
            case 0:
                refrescoPantalla();
                return 0;
            break;
            default:
                opcionIncorrecta();
            break;
        }
    }
}