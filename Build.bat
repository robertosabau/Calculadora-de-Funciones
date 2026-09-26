@echo off
gcc *.c -o calculadora.exe -finput-charset=UTF-8 -fexec-charset=UTF-8
if %errorlevel% equ 0 (
    echo Programa compilado con exito.
) else (
    echo Error al compilar el programa.
)
pause