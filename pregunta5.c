#include <stdio.h>  // Inclusión de la biblioteca de entrada/salida estándar
#include <stdlib.h> // Inclusión de la biblioteca de funciones de propósito general
#include <mpi.h>    // Inclusión de la biblioteca de MPI

// Función de multiplicación de matriz por vector (secuencial)
void multiplicarMatrizPorVector(int N, int matriz[N][N], int vector[N], int resultado_local[N]) {
    for (int i = 0; i < N; i++) {
        resultado_local[i] = 0;  // Inicialización del elemento i del vector resultado a 0
        for (int j = 0; j < N; j++) {
            resultado_local[i] += matriz[i][j] * vector[j];  // Cálculo del elemento i del vector resultado
        }
    }
}

int main(int argc, char *argv[]) {
    int rank, size, N;  // Declaración de variables para el rango del proceso, el tamaño del mundo MPI y el tamaño de la matriz/vector

    MPI_Init(&argc, &argv);  // Inicialización de MPI
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);  // Obtención del rango del proceso actual
    MPI_Comm_size(MPI_COMM_WORLD, &size);  // Obtención del tamaño del mundo MPI

    if (rank == 0) {
        printf("Ingrese el tamaño N de la matriz y el vector: ");
        scanf("%d", &N);  // Lectura del valor de N
    }

    // Se transmite el tamaño N a todos los procesos
    MPI_Bcast(&N, 1, MPI_INT, 0, MPI_COMM_WORLD);

    int matriz[N][N];  // Declaración de la matriz cuadrada de tamaño N
    int vector[N];     // Declaración del vector de tamaño N
    int resultado_local[N], resultado_final[N];  // Declaración de los vectores de resultado local y final

    if (rank == 0) {
        printf("Ingrese los elementos de la matriz:\n");
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                scanf("%d", &matriz[i][j]);  // Lectura de los elementos de la matriz
            }
        }

        printf("Ingrese los elementos del vector:\n");
        for (int i = 0; i < N; i++) {
            scanf("%d", &vector[i]);  // Lectura de los elementos del vector
        }
    }

    // Se transmiten la matriz y el vector a todos los procesos
    MPI_Bcast(matriz, N*N, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(vector, N, MPI_INT, 0, MPI_COMM_WORLD);

    // Cada proceso calcula parte del resultado
    multiplicarMatrizPorVector(N, matriz, vector, resultado_local);

    // Se realiza la reducción de los resultados locales
    MPI_Reduce(resultado_local, resultado_final, N, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        printf("Resultado de la multiplicación:\n");
        for (int i = 0; i < N; i++) {
            printf("%d ", resultado_final[i]);  // Impresión del vector resultado
        }
        printf("\n");
    }

    MPI_Finalize();  // Finalización de MPI

    return 0;  // Fin del programa
}