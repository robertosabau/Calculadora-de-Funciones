#ifndef ILUSTRAR_H
#define ILUSTRAR_H
#include "funcion.h"
    //Configurar la consola de comandos para funcionar en UTF-8
    void configurarConsola();   
    //Limpieza consola de comandos
    void refrescoPantalla(void);
    //Mostrar que la opcion no es correcta
    void opcionIncorrecta(void);
    //Mostrar error cuando hay un problema con un puntero
    void errorPuntero(void);
    //Muestra del menu principal
    void menuPrincipal(void);
    //Mostrar las opciones de tipos de funcion que hay
    void menuTiposFuncion(void);
    //Mostrar las opciones de grado de polinomio disponibles
    void gradoPolinomioDisponible(void);
    //Mostrar los tipos de funciones trigonometricas disponibles
    void tiposTrigonometrica(void);
    //Busqueda atributo A
    void buscarAtributoA(void);
    //Busqueda atributo B
    void buscarAtributoB(void);
    //Busqueda atributo C
    void buscarAtributoC(void);
    //Dibujar funcion con los datos guardados
    bool dibujarFuncion(Funcion *funcion);
    //Dibujar funcion de forma generica
    void dibujarFuncion2(TipoFuncion tipo, int grado);
    //Mostrar opciones del menu de la función
    void opcionesMenuFuncion(Funcion *funcion);
    //Metodo para obtener el valor de la x para calcularlo
    double obtenerX(void);
    //Mostrar el resultado que ha dado la x en la funcion
    void mostrarResultadoCalculoX(double x,double resultado);
    //Mostrar el resultado de intentar obtener cuando f(x)=0
    bool mostrarResultadoObtenerIgual0(double *x,Funcion *funcion);
    //Texto para pedir el nombre del guardado que quiere cargar
    void menuCargarFuncion(void);
    //Mostrar que ha habido un problema al cargar el fichero
    void errorCargar(void);
    //Mostrar que ha cargado correctamente la función
    void cargadoCorrecto(void);
    //Texto para guardar una función
    void menuGuardarFuncion(void);
    //Mostrar que se ha guardado correctamente
    void guardadoCorrecto(void);
    //Mostrar que no se ha podido guardar
    void errorGuardar(void);
#endif