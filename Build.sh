#!/bin/bash
gcc *.c -o calculadora -lm -finput-charset=UTF-8 -fexec-charset=UTF-8
if [ $? -eq 0 ]; then
    echo "Programa compilado con exito."
else
    echo "Hubo un error al compilar el programa."
fi
read -p "Presiona Enter para continuar..."