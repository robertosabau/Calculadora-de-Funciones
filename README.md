# Calculadora de Funciones

Este proyecto se trata de una simple calculadora donde puedes realizar diferentes operaciones con ciertas funciones que puedes personalizar.

### Funcionamiento programa

Una vez iniciado el programa tienes las siguientes opciones:
  * **Crear Función:** Te permite crear una función.
  * **Cargar Función:** Te permite cargar una función desde un fichero.
  * **Salir:** Te permite salir del programa

En el caso de elegir **Crear Función**, primero deberás elegir el **tipo de función** que deseas crear. Después de elegirla deberás **introducir** los **atributos necesarios**. Una vez realizadas todas estas acciones estarás en el **Menú de la Función**.

En el caso de elegir **Cargar Función**, deberás **introducir** el **nombre** del **archivo** que **guarda la función**. Una vez introducido estaras en el **Menú de la función**.

Ya en el **Menú de la función** podrías realizar **2 acciones principales**:
* **Elegir una operacion**
* **Volver al menú de inicio**

### Funciones disponibles

1. **Polinómicas:**
   * 1 Grado: `aX + b`
   * 2 Grado: `aX² + bx + c`
2. **Exponencial:** `aⁿ`
3. **Logartimo** `log\342\202\220(x)`
4. **Trigonometrica:**
   * Seno: `sin(ax)`
   * Coseno: `cos(ax)`
   * Tangente: `tan (ax)`
  
**AVISO:** Las funciones **Trigonométricas** estan en **radianes**.

### Operaciones soportadas

* **Calcular valor X:** Te permite calcular qué valor dará la función creada en un punto específico de X.
* **Calcular F(x) = 0:** Te permite averiguar en qué valor de X se cumple que la función da 0.
* **Calcular Derivada:** Te permite ver cual seria la derivada de la función con los atributos introducidos.
* **Calcular Integral:** Te permite ver cual seria la integral de la función con los atributos introducidos.
* **Guardar Función:** Te permite guardar la función en un archivo para poder reutilizarla en el futuro.

### Compilación y ejecución

Para compilar el proyecto hay que ejecutar el archivo Build correspondiente:
   * En el caso de **Windows**: `Build.bat`
   * En el caso de **Linux/Mac OS**: `Build.sh`

En cualquier caso es necesario para ejecutar el archivo Build se necesita tener instalado el compilador **Gcc**.

Una vez finalizado la compilación, para usar la aplicación se debe ejecutar el ejecutable generado.
