#include <iostream>

using namespace std;

class Operaciones {
    // Definición de la clase "Operaciones"
private:
    // Declaración de las variables miembro "num1" y "num2" como atributos privados de la clase
    float num1, num2;

public:
    // Declaración del método público "ingresarValores()"
    void ingresarValores() {
        // Solicita al usuario que ingrese el primer número
        cout << "Ingrese un número: ";
        cin >> num1;
        // Solicita al usuario que ingrese el segundo número
        cout << "Ingrese otro número: ";
        cin >> num2;
    }

    // Declaración del método público "suma()"
    float suma() {
        // Devuelve la suma de "num1" y "num2"
        return num1 + num2;
    }

    // Declaración del método público "resta()"
    float resta() {
        // Devuelve la resta de "num1" y "num2"
        return num1 - num2;
    }

    // Declaración del método público "multiplicacion()"
    float multiplicacion() {
        // Inicializa la variable "resultado" en 0
        float resultado = 0;
        // Realiza un bucle que suma "num1" "num2" veces
        for (int i = 0; i < num2; i++) {
            resultado += num1;
        }
        // Devuelve el resultado de la multiplicación
        return resultado;
    }

    // Declaración del método público "division()"
    float division() {
        // Inicializa la variable "resultado" en 0
        float resultado = 0;
        // Inicializa la variable "residuo" con el valor de "num1"
        float residuo = num1;

        // Realiza un bucle mientras el "residuo" sea mayor o igual que "num2"
        while (residuo >= num2) {
            // Incrementa el "resultado" en 1
            resultado++;
            // Actualiza el "residuo" restando "num2"
            residuo -= num2;
        }

        // Si el "residuo" es mayor que 0, ajusta el "resultado" para incluir los decimales
        if (residuo > 0) {
            resultado += residuo / num2;
        }

        // Devuelve el resultado de la división
        return resultado;
    }
};

int main() {
    // Crea un objeto de la clase "Operaciones"
    Operaciones op;
    // Llama al método "ingresarValores()" para obtener los valores de entrada del usuario
    op.ingresarValores();

    // Imprime en pantalla el resultado de la suma
    cout << "Suma: " << op.suma() << endl;
    // Imprime en pantalla el resultado de la resta
    cout << "Resta: " << op.resta() << endl;
    // Imprime en pantalla el resultado de la multiplicación
    cout << "Multiplicación: " << op.multiplicacion() << endl;
    // Imprime en pantalla el resultado de la división
    cout << "División: " << op.division() << endl;

    // Finaliza el programa
    return 0;
}
