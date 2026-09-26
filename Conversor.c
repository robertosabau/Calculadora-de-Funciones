#include <string.h>
#include <stdio.h>

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