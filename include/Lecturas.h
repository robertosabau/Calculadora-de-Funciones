#ifndef LECTURAS_H
#define LECTURAS_H
//Leer un numero entero cuyo mensaje no requiere nada
int lecturaEntero(void (*texto)(void));
//Leer un numero entero cuyo mensaje necesita una funcion
int lecturaEntero2(void (*texto)(Funcion*),Funcion *funcion);
//Leer un numero double
double lecturaFlotante(void (*texto)(void));
//Leer un string
void lecturaString(void (*texto)(void),char*buffer,int cantidad);

#endif