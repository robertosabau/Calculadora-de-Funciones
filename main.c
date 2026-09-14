#include <stdio.h> 
#include <stdbool.h>
#include <stdint.h>
#include <math.h>
#include <float.h>
#include "funcion.h"
#include "Calculos.h"
#include "Lecturas.h"

//DECLARACIONES METODOS
void menuPrincipal(void);
void refrescoPantalla(void);
void esperaEnter(void);
void gradoPolinomioDisponible();
void opcionIncorrecta(void);
bool menuSeleccionFuncion(void);
bool menuSeleccionGradoPolinomio(void);
bool seleccionParametrosPolinomio(int grado,double *array);
bool menuFuncion(Funcion *funcion);
bool menuParametroExponencial(void);
bool menuParametroLogaritmo(void);
void dibujarFuncion2(TipoFuncion tipo,int grado);
bool dibujarFuncion(Funcion *funcion);
double obtenerX(void);
void mostrarResultadoCalculoX(double x,double resultado);
bool mostrarResultadoObtenerIgual0(double *x,Funcion *funcion);
void errorPuntero(void);
bool menuSeleccionTipoTrigonometrica(void);
void menuTiposFuncion(void);
void tiposTrigonometrica(void);
void buscarAtributoA(void);
void buscarAtributoB(void);
void buscarAtributoC(void);
double obtenerAtributoA();
double obtenerAtributoB();
double obtenerAtributoC();
void opcionesMenuFuncion(Funcion *funcion);

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
void dibujarFuncion2(TipoFuncion tipo,int grado){
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
    }
}
void esperaEnter(){
    int c;
    while (c=getchar() != '\n' && c != EOF);
    getchar();
}
void opcionIncorrecta(){
    refrescoPantalla();
    printf("OPCION NO VALIDA\n");
    printf("PRESIONE ENTER PARA CONTINUAR");
    esperaEnter();
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
void buscarAtributoA(){
    printf("INTRODUCE EL ATRIBUTO a: ");
}
void buscarAtributoB(){
    printf("INTRODUCE EL ATRIBUTO b: ");
}
void buscarAtributoC(){
    printf("INTRODUCE EL ATRIBUTO c: ");
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
void tiposTrigonometrica(){
    refrescoPantalla();
    printf("SELECCIONE UNA FUNCION TRIGONOMETRICA\n");
        printf("1. SENO\n");
        printf("2. COSENO\n");
        printf("3. TANGENTE\n");
        printf("0. VOLVER ATRAS\n");
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
void gradoPolinomioDisponible(){
    refrescoPantalla();
    printf("SELECCIONA EL GRADO DEL POLINOMIO\n");
    printf("1. GRADO 1 \n");
    printf("2. GRADO 2 \n");
    printf("0. VOLVER ATRAS\n");
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
void opcionesMenuFuncion(Funcion *funcion){
    refrescoPantalla();
    dibujarFuncion(funcion);
    printf("1. CALCULAR VALOR X \n");
    printf("2. CALCULAR F(X)=0 \n");
    printf("0. REGRESAR AL MENU PRINCIPAL\n");
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
void errorPuntero(){
    refrescoPantalla();
    printf("HA OCURRIDO UN PROBLEMA\n");
    printf("PULSE ENTER PARA CONTINUAR");
    esperaEnter();
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
    }
    return false;
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