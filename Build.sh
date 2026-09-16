#!/bin/bash
gcc *.c -o calculadora -lm
if [ $? -eq 0 ]; then
    echo "Programa compilado con exito."
else
    echo "Hubo un error al compilar el programa."
fi
read -p "Presiona Enter para continuar..."