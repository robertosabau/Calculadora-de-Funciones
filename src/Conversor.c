#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "Constantes.h"
#include "funcion.h"

void concatenarNumeros(char*buffer,char*resultado){
    strcat(resultado, buffer);
}
bool concatenarNumeroConLogica(Funcion *funcion,char*resultado,int pos,bool x){
    if (funcion == NULL || resultado == NULL||pos < 0 || pos >= funcion->cantidadvalores) {
    return false;
    }
    if(funcion->valores[pos]==0){
        return false;
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
        if(funcion->valores[pos]==1&&x){
            strcat(resultado,"+ ");
        return true;
        }
        if(funcion->valores[pos]>0){
            strcat(resultado,"+ ");
        }
        else{
            strcat(resultado,"- ");
            num=num*-1;
            if (funcion->valores[pos]==-1&&x){
                return true;
            }
        }
    }
    else{
        if (funcion->valores[pos]==-1){
            strcat(resultado,"- ");
            return true;
        } 
        if(funcion->valores[pos]==1&&x){
            return true;
        }
    }
    if(funcion->valores[pos]==PI||funcion->valores[pos]==-PI){
        strcat(resultado,"π");
        return true;
    }
    else{
        if(funcion->valores[pos]==EULER||funcion->valores[pos]==-EULER){
            strcat(resultado,"e");
            return true;
        }
    }
    char resul[32];
    snprintf(resul, sizeof(resul), "%g", num);
    concatenarNumeros(resul,resultado);
    return true;
}

void convertirASubindice(double numero,char* resultado){
    // Vaciamos la cadena de destino
    resultado[0] = '\0';
    char buffer[32];
    // Convertimos el double a texto normal usando %g para omitir ceros finales
    snprintf(buffer, sizeof(buffer), "%g", numero);
    
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
void convertirASuperindice(double numero,char* resultado){
    // Vaciamos la cadena de destino
    resultado[0] = '\0';
    if (numero==PI){
        strcat(resultado,"π");
        return;
    }
    else{
        if (numero==-PI){
            strcat(resultado,"-π");
            return;
        }
        else{
            if (numero==EULER){
                strcat(resultado,"e");
                return;
            }
            else{
                if (numero==-EULER){
                    strcat(resultado,"-e");
                    return;
                }
            }
        }
    }
    char buffer[32];
    // Convertimos el double a texto normal usando %g para omitir ceros finales
    snprintf(buffer, sizeof(buffer), "%g", numero);
    
    // Recorremos cada carácter del número normal y añadimos su byte octal correspondiente
    for (int i = 0; buffer[i] != '\0'; i++) {
        switch (buffer[i]) {
            case '0': strcat(resultado, "\342\201\260"); break; // ⁰
            case '1': strcat(resultado, "\302\271");     break; // ¹
            case '2': strcat(resultado, "\302\262");     break; // ²
            case '3': strcat(resultado, "\302\263");     break; // ³
            case '4': strcat(resultado, "\342\201\264"); break; // ⁴
            case '5': strcat(resultado, "\342\201\265"); break; // ⁵
            case '6': strcat(resultado, "\342\201\266"); break; // ⁶
            case '7': strcat(resultado, "\342\201\267"); break; // ⁷
            case '8': strcat(resultado, "\342\201\270"); break; // ⁸
            case '9': strcat(resultado, "\342\201\271"); break; // ⁹
            case '-': strcat(resultado, "\342\201\273"); break; // ⁻
            case '.': strcat(resultado, "\302\267"); break;     // · 
            default: 
                int len = strlen(resultado);
                resultado[len] = buffer[i];
                resultado[len+1] = '\0';
                break;
        }
    }
}
void convertirFuncionATexto(Funcion *funcion,char* resultado){
    resultado[0] = '\0';
    switch (funcion->tipo){
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
            if (concatenarNumeroConLogica(funcion,resultado,0,true)){
                strcat(resultado,"ˣ");
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
                    if (funcion->valores[0]!=0){
                        convertirASubindice(funcion->valores[0],resul);
                        strcat(resultado,"log");
                        strcat(resultado,resul);
                        strcat(resultado,"(x)");
                    }
                }
            }
        break;
        case SENO:
            strcat(resultado,"sin(");
            if(concatenarNumeroConLogica(funcion,resultado,0,true)){
                strcat(resultado,"x)");
            }
            else{
                resultado[0]='\0';
            }
        break;
        case COSENO:
                strcat(resultado,"cos(");
                if(concatenarNumeroConLogica(funcion,resultado,0,true)){
                    strcat(resultado,"x)");
                }
                else{
                    resultado[0]='\0';
                }
        break;
        case TANGENTE:
                strcat(resultado,"tan(");
                if(concatenarNumeroConLogica(funcion,resultado,0,true)){
                    strcat(resultado,"x)");
                }
                else{
                    resultado[0]='\0';
                }
        break;
    }
}
void convertirDerivadaATexto(Funcion *funcion,char *resultado){
    resultado[0] = '\0';
    switch (funcion->tipo){
        case POLINOMIO:
            switch (funcion->cantidadvalores){
                case 2:
                    concatenarNumeroConLogica(funcion,resultado,0,false);
                break;
                case 3:
                    if(concatenarNumeroConLogica(funcion,resultado,0,true)){
                        strcat(resultado,"x ");
                    }
                    concatenarNumeroConLogica(funcion,resultado,1,true);
                break;
            }
        break;
        case EXPONENCIAL:
            if (funcion->valores[0]==EULER){
                strcat(resultado,"eˣ");
            }
            else{
                if (funcion->valores[0]==-EULER){
                    strcat(resultado,"-eˣ");
                }
                else{
                    if (concatenarNumeroConLogica(funcion,resultado,0,false)){
                        strcat(resultado,"ˣ");
                        strcat(resultado," · ");
                        strcat(resultado,"ln(");
                        if (concatenarNumeroConLogica(funcion,resultado,0,true)){
                            strcat(resultado,")");
                        }
                        else{
                            resultado[0]='\0';
                        }
                    }
                }
            }
        break;
        case LOGARITMO:
            if (funcion->valores[0]==EULER){
                strcat(resultado,"¹/ₓ");
            }
            else{
                strcat(resultado,"¹/(x · ln(");
                if(concatenarNumeroConLogica(funcion,resultado,0,false)){
                    strcat(resultado,"))");
                }
                else{
                    resultado[0]='\0';
                }
            }
        break;
        case SENO:
            if(concatenarNumeroConLogica(funcion,resultado,0,true)){
                strcat(resultado,"cos(");
                if(concatenarNumeroConLogica(funcion,resultado,0,true)){
                    strcat(resultado,"x)");
                }
                else{
                    resultado[0]='\0';
                }
            }
        break;
        case COSENO:
            double numero=funcion->valores[0]*-1;
            Funcion funcioninverso;
            funcioninverso.cantidadvalores=funcion->cantidadvalores;
            funcioninverso.tipo=funcion->tipo;
            funcioninverso.valores=&numero;
            if(concatenarNumeroConLogica(&funcioninverso,resultado,0,true)){
                strcat(resultado,"sin(");
                if(concatenarNumeroConLogica(funcion,resultado,0,true)){
                    strcat(resultado,"x)");
                }
                else{
                    resultado[0]='\0';
                }
            }
        break;
        case TANGENTE:
            if(concatenarNumeroConLogica(funcion,resultado,0,true)){
                strcat(resultado,"sec²(");
                if(concatenarNumeroConLogica(funcion,resultado,0,true)){
                    strcat(resultado,"x)");
                }
                else{
                    resultado[0]='\0';
                }
            }
        break;
    }
}
void convertirIntegralATexto(Funcion *funcion,char *resultado){
    resultado[0] = '\0';
    char buffer[32];
    switch (funcion->tipo){
        case POLINOMIO:
            switch (funcion->cantidadvalores){
                double num;
                case 2:
                    num=funcion->valores[0]/2;
                    if (fmod(num, 1.0) == 0.0){
                        Funcion fuct;
                        fuct.cantidadvalores=funcion->cantidadvalores;
                        fuct.tipo=funcion->tipo;
                        fuct.valores=&num;
                        concatenarNumeroConLogica(&fuct,resultado,0,true);
                    }
                    else{
                        convertirASuperindice(funcion->valores[0],buffer);
                        strcat(resultado,buffer);
                        strcat(resultado,"/₂");
                    }
                    strcat(resultado,"x² ");
                    concatenarNumeroConLogica(funcion,resultado,1,true);
                    strcat(resultado,"x + C");
                break;
                case 3:
                    num=funcion->valores[0]/3;
                    if (fmod(num, 1.0) == 0.0){
                        Funcion fuct;
                        fuct.cantidadvalores=funcion->cantidadvalores;
                        fuct.tipo=funcion->tipo;
                        fuct.valores=&num;
                        if(concatenarNumeroConLogica(&fuct,resultado,0,true)){
                            strcat(resultado,"/₃");
                            strcat(resultado,"x³ ");
                        }
                    }
                    else{
                        convertirASuperindice(funcion->valores[0],buffer);
                        strcat(resultado,buffer);
                        strcat(resultado,"x³ ");
                    }
                    num=funcion->valores[1]/2;
                    if (fmod(num, 1.0) == 0.0){
                        Funcion fuct;
                        fuct.cantidadvalores=funcion->cantidadvalores;
                        fuct.tipo=funcion->tipo;
                        fuct.valores=&num;
                        concatenarNumeroConLogica(&fuct,resultado,0,true);
                    }
                    else{
                        convertirASuperindice(funcion->valores[1],buffer);
                        strcat(resultado,buffer);
                        strcat(resultado,"/₂");
                    }
                    strcat(resultado,"x² ");
                    concatenarNumeroConLogica(funcion,resultado,2,true);
                    strcat(resultado,"x + C");
                break;
            }
        break;
        case EXPONENCIAL:
            if (funcion->valores[0]==EULER){
                strcat(resultado,"eˣ");
            }
            else{
                if (funcion->valores[0]==-EULER){
                    strcat(resultado,"-eˣ");
                }
                else{
                    if (concatenarNumeroConLogica(funcion,resultado,0,false)){
                        strcat(resultado,"ˣ");
                        strcat(resultado," / ");
                        strcat(resultado,"ln(");
                        if (concatenarNumeroConLogica(funcion,resultado,0,false)){
                            strcat(resultado,")  + C");
                        }
                        else{
                            resultado[0]='\0';
                        }
                    }
                }
            }
        break;
        case LOGARITMO:
            if (funcion->valores[0]==EULER){
                strcat(resultado,"x · ln(x) - x + C");
            }
            else{
                strcat(resultado,"x · log");
                if (funcion->valores[0]==PI){
                    strcat(resultado,"_π");
                }
                else{
                    convertirASubindice(funcion->valores[0],buffer);
                    strcat(resultado,buffer);
                }
                strcat(resultado,"(x) - x/ln(");
                if(concatenarNumeroConLogica(funcion,resultado,0,false)){
                    strcat(resultado,") + C");
                }
                else{
                    resultado[0]='\0';
                }
            }
        break;
        case SENO:
            strcat(resultado,"-");
            strcat(resultado,"¹/");
            if (funcion->valores[0]<0){
                double numero=funcion->valores[0]*-1;
                convertirASubindice(numero,buffer);
                strcat(resultado,buffer);
            }
            else{
                if (funcion->valores[0]!=0){
                    convertirASubindice(funcion->valores[0],buffer);
                    strcat(resultado,buffer);

                }
                else{
                    resultado[0]='\0';
                }  
            }
            strcat(resultado, " · cos(");
            if(concatenarNumeroConLogica(funcion,resultado,0,true)){
                strcat(resultado,"x) + C");
            }
            else{
                resultado[0]='\0';
            }
        break;
        case COSENO:
            if (funcion->valores[0]<0){
                strcat(resultado,"-");
                strcat(resultado,"¹/");
                double numero=funcion->valores[0]*-1;
                convertirASubindice(numero,buffer);
                strcat(resultado,buffer);
            }
            else{
                if (funcion->valores[0]!=0){
                    strcat(resultado,"¹/");
                    convertirASubindice(funcion->valores[0],buffer);
                    strcat(resultado,buffer);

                }
                else{
                    resultado[0]='\0';
                } 
            } 
            strcat(resultado, " · sin(");
            if(concatenarNumeroConLogica(funcion,resultado,0,true)){
                strcat(resultado,"x) + C");
            }
            else{
                resultado[0]='\0';
            }
        break;
        case TANGENTE:
            strcat(resultado,"-");
            strcat(resultado,"¹/");
            if (funcion->valores[0]<0){
                double numero=funcion->valores[0]*-1;
                convertirASubindice(numero,buffer);
                strcat(resultado,buffer);
            }
            else{
                if (funcion->valores[0]!=0){
                    convertirASubindice(funcion->valores[0],buffer);
                    strcat(resultado,buffer);
                }
                else{
                    resultado[0]='\0';
                }  
            }
            strcat(resultado, " · ln|cos(");
            if(concatenarNumeroConLogica(funcion,resultado,0,true)){
                strcat(resultado,"x)| + C");
            }
            else{
                resultado[0]='\0';
            }
        break;
    }
}