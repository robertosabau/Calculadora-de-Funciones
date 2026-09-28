#ifndef GESTOR_H
#define GESTOR_H

    #include "funcion.h"

    //Para guardar una funcion en un archivo
    bool guardarFuncion(Funcion *funcion, char* nombre);
    //Para cargar una funcion de un archivo
    Funcion cargarFuncion(char* nombre);

#endif