#include <stdio.h>  // Inclusión de la biblioteca de entrada/salida estándar
#include <omp.h>    // Inclusión de la biblioteca de OpenMP para programación paralela

// Función de multiplicación de matriz por vector (OpenMP)
void multiMatPorVEctor(int N, int matriz[N][N], int vector[N], int resultado[N]) {
    #pragma omp parallel for
    // Directiva OpenMP que paraleliza el bucle for
    for (int i = 0; i < N; i++) {
        resultado[i] = 0;  // Inicialización del elemento i del vector resultado a 0
        for (int j = 0; j < N; j++) {
            resultado[i] += matriz[i][j] * vector[j];  // Cálculo del elemento i del vector resultado
        }
    }
}

int main() {
    int N;  // Declaración de la variable N

    printf("Ingrese el tamanio de N: ");
    scanf("%d", &N);  // Lectura del valor de N

    int matriz[N][N];  // Declaración de la matriz cuadrada de tamaño N
    int vector[N];     // Declaración del vector de tamaño N
    int resultado[N];  // Declaración del vector resultado de tamaño N

    printf("Ingrese los elementos de la matriz:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("mat[%d][%d]= ", i, j);
            scanf("%d", &matriz[i][j]);  // Lectura de los elementos de la matriz
        }
    }
    printf("Ingrese los elementos del vector:\n");
    for (int i = 0; i < N; i++) {
        printf("vect[%d]= ", i);
        scanf("%d", &vector[i]);  // Lectura de los elementos del vector
    }
    
    multiMatPorVEctor(N, matriz, vector, resultado);  // Llamada a la función de multiplicación de matriz por vector

    printf("Matriz ingresada\n");
    for (int i = 0; i < N; i++) {  // Impresión de la matriz
        for (int j = 0; j < N; j++) {
            printf("%d ", matriz[i][j]);
        }
        puts("");
    }
    printf("Vector ingresado\n");
    for (int i = 0; i < N; i++) {  // Impresión del vector
        printf("%d ", vector[i]);
    }
    printf("\nResultado de la multiplicación:\n");
    for (int i = 0; i < N; i++) {  // Impresión del vector resultado
        printf("%d ", resultado[i]);
    }
    printf("\n");
    return 0;  // Fin del programa
}#include <stdio.h>  // Inclusión de la biblioteca de entrada/salida estándar
#include <omp.h>    // Inclusión de la biblioteca de OpenMP para programación paralela

// Función de multiplicación de matriz por vector (OpenMP)
void multiMatPorVEctor(int N, int matriz[N][N], int vector[N], int resultado[N]) {
    #pragma omp parallel for
    // Directiva OpenMP que paraleliza el bucle for
    for (int i = 0; i < N; i++) {
        resultado[i] = 0;  // Inicialización del elemento i del vector resultado a 0
        for (int j = 0; j < N; j++) {
            resultado[i] += matriz[i][j] * vector[j];  // Cálculo del elemento i del vector resultado
        }
    }
}

int main() {
    int N;  // Declaración de la variable N

    printf("Ingrese el tamanio de N: ");
    scanf("%d", &N);  // Lectura del valor de N

    int matriz[N][N];  // Declaración de la matriz cuadrada de tamaño N
    int vector[N];     // Declaración del vector de tamaño N
    int resultado[N];  // Declaración del vector resultado de tamaño N

    printf("Ingrese los elementos de la matriz:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("mat[%d][%d]= ", i, j);
            scanf("%d", &matriz[i][j]);  // Lectura de los elementos de la matriz
        }
    }
    printf("Ingrese los elementos del vector:\n");
    for (int i = 0; i < N; i++) {
        printf("vect[%d]= ", i);
        scanf("%d", &vector[i]);  // Lectura de los elementos del vector
    }
    
    multiMatPorVEctor(N, matriz, vector, resultado);  // Llamada a la función de multiplicación de matriz por vector

    printf("Matriz ingresada\n");
    for (int i = 0; i < N; i++) {  // Impresión de la matriz
        for (int j = 0; j < N; j++) {
            printf("%d ", matriz[i][j]);
        }
        puts("");
    }
    printf("Vector ingresado\n");
    for (int i = 0; i < N; i++) {  // Impresión del vector
        printf("%d ", vector[i]);
    }
    printf("\nResultado de la multiplicación:\n");
    for (int i = 0; i < N; i++) {  // Impresión del vector resultado
        printf("%d ", resultado[i]);
    }
    printf("\n");
    return 0;  // Fin del programa
}