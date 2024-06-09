#include <stdio.h>  // Inclusión de la biblioteca de entrada/salida estándar
#include <omp.h>    // Inclusión de la biblioteca de OpenMP para programación paralela

// Función de multiplicación utilizando sumas (OpenMP)
float multiplicacion(float num1, float num2) {
    float resultado = 0;  // Inicialización del resultado a 0
    #pragma omp parallel for reduction(+:resultado)
    // Directiva OpenMP que paraleliza el bucle for y utiliza reducción para sumar los resultados parciales
    for (int i = 0; i < num2; i++) {
        resultado += num1;  // Suma de num1 al resultado
    }
    return resultado;  // Devolución del resultado
}

// Función de división utilizando restas (OpenMP)
float division(float num1, float num2) {
    float resultado = 0;  // Inicialización del resultado a 0
    #pragma omp parallel
    // Directiva OpenMP que crea múltiples hilos de ejecución en paralelo
    {
        float residuo = num1;  // Inicialización del residuo con el dividendo
        #pragma omp for
        // Directiva OpenMP que paraleliza el bucle for
        for (int i = 0; residuo >= num2; i++) {
            resultado++;  // Incremento del resultado (cociente)
            residuo -= num2;  // Resta del divisor al residuo
        }
        #pragma omp single
        // Directiva OpenMP que asegura que solo un hilo ejecute el siguiente bloque de código
        {
            // Ajustamos el resultado para incluir los decimales
            if (residuo > 0) {
                resultado += residuo / num2;  // Ajuste del resultado para incluir los decimales
            }
        }
    }
    return resultado;  // Devolución del resultado
}

int main() {
    float a;  // Declaración de la variable a
    float b;  // Declaración de la variable b
    printf("Ingrese un numero: ");
    scanf("%f",&a);  // Lectura del primer número
    printf("Ingrese un numero: ");
    scanf("%f",&b);  // Lectura del segundo número
    printf("Multiplicación: %.2f\n", multiplicacion(a, b));  // Llamada a la función de multiplicación y impresión del resultado
    printf("División: %.2f\n", division(a, b));  // Llamada a la función de división e impresión del resultado
    return 0;  // Fin del programa
}