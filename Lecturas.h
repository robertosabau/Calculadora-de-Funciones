#ifndef LECTURAS_H
#define LECTURAS_H

int lecturaEntero(void (*texto)(void));
int lecturaEntero2(void (*texto)(Funcion*),Funcion *funcion);
double lecturaFlotante(void (*texto)(void));

#endif