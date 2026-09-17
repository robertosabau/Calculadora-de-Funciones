#include <stdio.h>
#include <stdbool.h>
#include "Ilustrar.h"
#include "funcion.h"
#include "Lecturas.h"

bool guardarFuncion(Funcion *funcion, char* nombre){
    const char* extension=".bin";
    char *nombre_completo = malloc(strlen(nombre) + strlen(extension) + 1);
    if (nombre_completo==NULL){
        return false;
    }
    strcpy(nombre_completo, nombre);
    strcpy(nombre_completo, extension);
    FILE *archivo=fopen(nombre_completo,"wb");
    if (archivo==NULL){
        return false;
    }
    fwirte(&funcion->tipo,sizeof(TipoFuncion),1,archivo);
    fwrite(&funcion->cantidadvalores,sizeof(int),1,archivo);
    fwrite(funcion->valores,sizeof(double),funcion->cantidadvalores,archivo);
    fclose(archivo);
    free(nombre_completo);
    return true;
}

Funcion cargarFuncion(char* nombre){
    Funcion funcion;
    const char *extension = ".bin";
    char *nombre_completo = malloc(strlen(nombre) + strlen(extension) + 1);
    if (nombre_completo==NULL){
        funcion.valores=NULL;
        return funcion;
    }
    strcpy(nombre_completo, nombre);
    strcat(nombre_completo, extension);
    FILE *archivo=fopen(nombre_completo,"wb");
    if (archivo==NULL){
        funcion.valores=NULL;
        return funcion;
    }
    fread(funcion.tipo,sizeof(TipoFuncion),1,archivo);
    fread(funcion.cantidadvalores,sizeof(int),1,archivo);
    static double valores[3];
    funcion.valores=valores;
    for (int i=0;i<funcion.cantidadvalores;i++){
        fread(&funcion.valores[i],sizeof(double),1,archivo);
    }
    return funcion;
}