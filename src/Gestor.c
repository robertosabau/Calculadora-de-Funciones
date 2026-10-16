#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "Ilustrar.h"
#include "funcion.h"
#include "Lecturas.h"
#ifdef _WIN32
#define RUTA_SAVES "saves\\"  // Windows usa doble barra para escapar el carácter
#else
#define RUTA_SAVES "saves/"   // Linux y macOS usan la barra normal
#endif

bool guardarFuncion(Funcion *funcion, char* nombre){
    if (funcion==NULL||nombre==NULL){
        return false;
    }
    const char* extension=".bin";
    char *nombre_completo = malloc(strlen(RUTA_SAVES)+strlen(nombre) + strlen(extension) + 1);
    if (nombre_completo==NULL){
        return false;
    }
    strcpy(nombre_completo,RUTA_SAVES);
    strcat(nombre_completo, nombre);
    strcat(nombre_completo, extension);
    FILE *archivo=fopen(nombre_completo,"wb");
    if (archivo==NULL){
        free(nombre_completo);
        return false;
    }
    if(fwrite(&funcion->tipo,sizeof(TipoFuncion),1,archivo)!= 1){
        free(nombre_completo);
        fclose(archivo);
        return false;
    }
    if(fwrite(&funcion->cantidadvalores,sizeof(int),1,archivo)!= 1){
        free(nombre_completo);
        fclose(archivo);
        return false;
    }
    if(fwrite(funcion->valores,sizeof(double),funcion->cantidadvalores,archivo)!=funcion->cantidadvalores){
        free(nombre_completo);
        fclose(archivo);
        return false;
    }
    if (fflush(archivo)!=0){
        fclose(archivo);
        free(nombre_completo);
        return false;
    }
    fclose(archivo);
    free(nombre_completo);
    return true;
}

Funcion cargarFuncion(char* nombre){
    Funcion funcion;
    if (nombre==NULL){
        funcion.valores=NULL;
        return funcion;
    }
    const char *extension = ".bin";
    char *nombre_completo = malloc(strlen(RUTA_SAVES)+strlen(nombre) + strlen(extension) + 1);
    if (nombre_completo==NULL){
        funcion.valores=NULL;
        return funcion;
    }
    strcpy(nombre_completo,RUTA_SAVES);
    strcat(nombre_completo, nombre);
    strcat(nombre_completo, extension);
    FILE *archivo=fopen(nombre_completo,"rb");
    if (archivo==NULL){
        free(nombre_completo);
        funcion.valores=NULL;
        return funcion;
    }
    if (fread(&funcion.tipo,sizeof(TipoFuncion),1,archivo)!= 1){
        fclose(archivo);
        free(nombre_completo);
        funcion.valores=NULL;
        return funcion;
    }
    if (!comprobacionTipoCorrecto(funcion.tipo)){
        fclose(archivo);
        free(nombre_completo);
        funcion.valores=NULL;
        return funcion;
    }
    if(fread(&funcion.cantidadvalores,sizeof(int),1,archivo)!= 1){
        fclose(archivo);
        free(nombre_completo);
        funcion.valores=NULL;
        return funcion;
    }
    if (funcion.cantidadvalores <= 0 || funcion.cantidadvalores > 3) {
        fclose(archivo);
        free(nombre_completo);
        funcion.valores = NULL;
        return funcion;
    }
    static double valores[3];
    funcion.valores=valores;
    for (int i=0;i<funcion.cantidadvalores;i++){
        if (fread(&funcion.valores[i],sizeof(double),1,archivo)!= 1){
            fclose(archivo);
            free(nombre_completo);
            funcion.valores=NULL;
            return funcion;
        }
    }
    if (fclose(archivo) != 0) {
        free(nombre_completo);
        funcion.valores=NULL;
        return funcion;
    }
    free(nombre_completo);
    return funcion;
}