@echo off
gcc main.c -o calculadora.exe
if %errorlevel% equ 0 (
    echo Programa compilado con exito.
) else (
    echo Error al compilar el programa.
)
pause