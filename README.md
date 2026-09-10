# Calculadora de Funciones

Este proyecto se trata de una simple calculadora donde puedes realizar diferentes operaciones con ciertas funciones que puedes personalizar.

### Funciones disponibles

1. **Polinómicas:**
   * 1 Grado: `aX + b`
   * 2 Grado: `aX^2 + bx + c`
2. **Exponencial:** `a^x`
3. **LOGARITMO** `log_a(x)`

### Operaciones soportadas

* **Calcular valor X:** Te permite calcular qué valor dará la función creada en un punto específico de X.
* **Calcular F(x) = 0:** Te permite averiguar en qué valor de X se cumple que la función da 0.

### Compilación y Ejecución

El proyecto ya viene compilado por defecto para **Windows**. 

Para compilarlo en **macOS** o **Linux**, bastaría con tener un compilador de C (como `gcc`) y ejecutar en la terminal:
```bash
gcc main.c -o calculadora
```
