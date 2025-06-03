#include <iostream>
#include <vector>
using namespace std;


long long atraparAgua(const vector<int>& alturas) {
    int totalBarras = alturas.size();
    if (totalBarras < 3) return 0; // Con menos de 3 barras no se puede atrapar agua.

    int izquierda = 0;                // Puntero izquierdo
    int derecha = totalBarras - 1;    // Puntero derecho
    int maxIzquierda = 0;             // Altura max vista desde la izquierda
    int maxDerecha = 0;               // Altura max vista desde la derecha
    long long aguaAtrapada = 0;       // Cantidad total de agua atrapada

    while (izquierda < derecha) {
        if (alturas[izquierda] <= alturas[derecha]) {
            // Procesamos el lado izquierdo
            if (alturas[izquierda] >= maxIzquierda) {
                maxIzquierda = alturas[izquierda];
            } else {
                // Si la altura actual es menor que maxIzquierda, entonces hay “hueco” para agua
                aguaAtrapada += (maxIzquierda - alturas[izquierda]);
            }
            izquierda++;
        } else {
            // Procesamos el lado derecho
            if (alturas[derecha] >= maxDerecha) {
                maxDerecha = alturas[derecha];
            } else {
                // Si la altura actual es menor que maxDerecha, entonces hay “hueco” para agua
                aguaAtrapada += (maxDerecha - alturas[derecha]);
            }
            derecha--;
        }
    }

    return aguaAtrapada;
}

int main() {
    int cantidadBarras;
    cout << "Ingresa la cantidad de barras: ";
    cin >> cantidadBarras;

    if (cantidadBarras <= 0) {
        cout << "La cantidad de barras debe ser mayor que 0.\n";
        return 0;
    }

    vector<int> alturas(cantidadBarras);
    cout << "Ingresa las alturas separadas por espacios:\n";
    for (int i = 0; i < cantidadBarras; i++) {
        cin >> alturas[i];
    }

    long long resultado = atraparAgua(alturas);
    cout << "\nLa cantidad de agua que se puede atrapar es: " << resultado << "\n";

    return 0;
}
