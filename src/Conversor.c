#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "Constantes.h"
#include "funcion.h"

void concatenarNumeros(char*buffer,char*resultado){
    for (int i=0;buffer[i]!='\0';i++){
        char caracter_temporal[2] = {buffer[i], '\0'};
        strcat(resultado,caracter_temporal);
    }
}
bool concatenarNumeroConLogica(Funcion *funcion,char*resultado,int pos,bool x){
    if (funcion == NULL && resultado == NULL) {
    return false;
    }
    if(funcion->valores[pos]==0){
        return false;
    }
    if(funcion->valores[pos]==1&&x){
        return true;
    }
    int i=pos-1;
    bool vacio=true;
    while (i>=0&&vacio){
        if (funcion->valores[i]!=0){
            vacio=false;
        }
        i--;
    }
    double num=funcion->valores[pos];
    if(!vacio){
        if(funcion->valores[pos]>0){
            strcat(resultado,"+ ");
        }
        else{
            strcat(resultado,"- ");
            num=num*-1;
        }
    }
    else{
        if (funcion->valores[pos]<0){
            num=num*-1;
        }
    }
    if(funcion->valores[pos]==PI){
        strcat(resultado,"π");
        return true;
    }
    else{
        if(funcion->valores[pos]==EULER){
            strcat(resultado,"e");
            return true;
        }
    }
    char resul[32];
    sprintf(resul, "%g", num);
    concatenarNumeros(resul,resultado);
    return true;
}

void convertirASubindice(double numero,char* resultado){
    char buffer[32];
    // Convertimos el double a texto normal usando %g para omitir ceros finales
    sprintf(buffer, "%g", numero);
    
    // Vaciamos la cadena de destino
    resultado[0] = '\0';
    
    // Recorremos cada carácter del número normal y añadimos su byte octal correspondiente
    for (int i = 0; buffer[i] != '\0'; i++) {
        switch (buffer[i]) {
            case '0': strcat(resultado, "\342\202\200"); break; // ₀
            case '1': strcat(resultado, "\342\202\201"); break; // ₁
            case '2': strcat(resultado, "\342\202\202"); break; // ₂
            case '3': strcat(resultado, "\342\202\203"); break; // ₃
            case '4': strcat(resultado, "\342\202\204"); break; // ₄
            case '5': strcat(resultado, "\342\202\205"); break; // ₅
            case '6': strcat(resultado, "\342\202\206"); break; // ₆
            case '7': strcat(resultado, "\342\202\207"); break; // ₇
            case '8': strcat(resultado, "\342\202\208"); break; // ₈
            case '9': strcat(resultado, "\342\202\209"); break; // ₉
            case '-': strcat(resultado, "\342\202\213"); break; // ₋
            case '.': strcat(resultado, "\342\200\244"); break; 
            default: 
                int len = strlen(resultado);
                resultado[len] = buffer[i];
                resultado[len+1] = '\0';
                break;
        }
    }
}
void convertirFuncionATexto(Funcion *funcion,char* resultado){
    char buffer[32];
    resultado[0] = '\0';
    switch (funcion->tipo)
    {
        case POLINOMIO:
            switch (funcion->cantidadvalores){
                case 2:
                    if(concatenarNumeroConLogica(funcion,resultado,0,true)){
                        strcat(resultado,"x ");
                    }
                    concatenarNumeroConLogica(funcion,resultado,1,false);
                break;
                case 3:
                    if(concatenarNumeroConLogica(funcion,resultado,0,true)){
                        strcat(resultado,"x² ");
                    }
                    if(concatenarNumeroConLogica(funcion,resultado,1,true)){
                        strcat(resultado,"x ");
                    }
                    concatenarNumeroConLogica(funcion,resultado,2,false);
                break;
            }
        break;
        case EXPONENCIAL:
            if (funcion->valores[0]==PI){
                strcat(resultado,"πˣ");
            }
            else{
                if (funcion->valores[0]==EULER){
                    strcat(resultado,"eˣ");
                }
                else{
                    sprintf(buffer, "%g", funcion->valores[0]);
                    concatenarNumeros(buffer,resultado);
                    strcat(resultado,"ˣ");

                }
            }
        break;
        case LOGARITMO:
            if (funcion->valores[0]==EULER){
                strcat(resultado,"ln(x)");
            }
            else{
                if (funcion->valores[0]==PI){
                strcat(resultado,"log_π(x)");
                }
                else{
                    char resul[128];
                    convertirASubindice(funcion->valores[0],resul);
                    strcat(resultado,"log");
                    strcat(resultado,resul);
                    strcat(resultado,"(x)");
                }
            }
        break;
        case SENO:
            if (funcion->valores[0]==EULER){
                    strcat(resultado,"sin(ex)");
                }
                else{
                    if (funcion->valores[0]==PI){
                    strcat(resultado,"sin(πx)");
                    }
                    else{
                        sprintf(buffer, "%g", funcion->valores[0]);
                        strcat(resultado,"sin(");
                        concatenarNumeros(buffer,resultado);
                        strcat(resultado,"x)");
                    }
                }
        break;
        case COSENO:
                if (funcion->valores[0]==EULER){
                    strcat(resultado,"cos(ex)");
                }
                else{
                    if (funcion->valores[0]==PI){
                    strcat(resultado,"cos(πx)");
                    }
                    else{
                        sprintf(buffer, "%g", funcion->valores[0]);
                        strcat(resultado,"cos(");
                        concatenarNumeros(buffer,resultado);
                        strcat(resultado,"x)");
                    }
                }
        break;
        case TANGENTE:
                if (funcion->valores[0]==EULER){
                    strcat(resultado,"tan(ex)");
                }
                else{
                    if (funcion->valores[0]==PI){
                    strcat(resultado,"tan(πx)");
                    }
                    else{
                        sprintf(buffer, "%g", funcion->valores[0]);
                        strcat(resultado,"tan(");
                        concatenarNumeros(buffer,resultado);
                        strcat(resultado,"x)");
                    }
                }
        break;
    }
}