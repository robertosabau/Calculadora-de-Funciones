#include <stdio.h> 
#include <stdbool.h>
#include <stdint.h>
#include <math.h>
#include <float.h>
#include "funcion.h"
#include "Calculos.h"
#include "Lecturas.h"
#include "Ilustrar.h"
#include "Gestor.h"

//DECLARACIONES METODOS
//Esperar un enter del jugador
void esperaEnter(bool limpiar);
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
//Seleccion parametro trigonometrica
double menuParametroTrigonometrica(int tipo);
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
//Menu para cargar una funcion
bool CargarFuncion();
//Menu para guardar una funcion
bool GuardarFuncion(Funcion *funcion);

//DESCRIPCION METODOS
void esperaEnter(bool limpiar){
    int c;
    if(limpiar){
        while ((c = getchar()) != '\n' && c != EOF);
    }
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
    buscarAtributoC();
    double numero=lecturaFlotante(buscarAtributoC);
    return numero;
}
bool menuSeleccionFuncion(){
    while (true){
        menuTiposFuncion();
        int seleccion=lecturaEntero(menuTiposFuncion);
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
        int seleccion=lecturaEntero(tiposTrigonometrica);
        switch (seleccion)
        {
            case 1:
                double a=menuParametroTrigonometrica(0);
                Funcion funcion;
                funcion.cantidadvalores=1;
                funcion.tipo=SENO;
                funcion.valores=&a;
                return menuFuncion(&funcion);
            break;
            case 2:{
                double a=menuParametroTrigonometrica(1);
                Funcion funcion;
                funcion.cantidadvalores=1;
                funcion.tipo=COSENO;
                funcion.valores=&a;
                return menuFuncion(&funcion);}

            break;
            case 3:{
                double a=menuParametroTrigonometrica(2);
                Funcion funcion;
                funcion.cantidadvalores=1;
                funcion.tipo=TANGENTE;
                funcion.valores=&a;
                return menuFuncion(&funcion);
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
double menuParametroTrigonometrica(int tipo){
    double parametro;
    switch (tipo){
        //Seno
        case 0:
            dibujarFuncion2(SENO,0);
        break;
        //Coseno
        case 1:
            dibujarFuncion2(COSENO,0);
        break;
        //Tangente
        case 2:
            dibujarFuncion2(TANGENTE,0);
        break;
    }
    parametro=obtenerAtributoA();
    return parametro;
}
bool menuParametroExponencial(){
    refrescoPantalla();
    dibujarFuncion2(EXPONENCIAL,0);
    double a=obtenerAtributoA();
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
            esperaEnter(true);
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
            opcionesMenuFuncion(funcion);
            int seleccion=lecturaEntero2(opcionesMenuFuncion,funcion);
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
                case 3:
                    if(calculoDerivada(funcion)){
                        return true;
                    }
                    printf("PULSE ENTER PARA CONTINUAR");
                    esperaEnter(true);
                break;
                case 4:
                    if (calculoIntegral(funcion)){
                        return true;
                    }
                    printf("PULSE ENTER PARA CONTINUAR");
                    esperaEnter(true);
                break;
                case 5:
                    GuardarFuncion(funcion);
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
bool CargarFuncion(){
    menuCargarFuncion();
    char nombre[20];
    lecturaString(menuCargarFuncion,nombre,20);
    Funcion funcion=cargarFuncion(nombre);
    if (funcion.valores!=NULL){
        cargadoCorrecto();
        if (menuFuncion(&funcion)){
            return true;
        }
    }
    else{
        errorCargar();
        return false;
    }
}
bool GuardarFuncion(Funcion *funcion){
    menuGuardarFuncion();
    char nombre[20];
    lecturaString(menuGuardarFuncion,nombre,20);
    if (guardarFuncion(funcion,nombre)){
        guardadoCorrecto();
        return true;
    }
    else{
        errorGuardar();
        return false;
    }
}
int main(){
    while(true){
        menuPrincipal();
        int seleccion=lecturaEntero(menuPrincipal);
        switch (seleccion){
            case 1:
                menuSeleccionFuncion();
            break;
            case 2:
                CargarFuncion();
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