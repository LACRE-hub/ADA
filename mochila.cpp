#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    const int n = 4;
    const int W = 4;

    // Ítems: nombre, peso y valor 
    string nombre[n] = { "Guitarra", "Laptop", "Estereo", "iPhone" };
    int peso[n]  = { 1, 3, 4, 1 };
    int valor[n] = { 1500, 2000, 3000, 2000 };

    // Tabla DP de tamaño (n+1) x (W+1)
    int dp[n+1][W+1];
    for(int i = 0; i <= n; ++i)
        for(int w = 0; w <= W; ++w)
            dp[i][w] = 0;

    // Llenado de la tabla
    for(int i = 1; i <= n; ++i) {
        for(int w = 0; w <= W; ++w) {
            dp[i][w] = dp[i-1][w];
            if (peso[i-1] <= w) {
                int posible = dp[i-1][w - peso[i-1]] + valor[i-1];
                if (posible > dp[i][w])
                    dp[i][w] = posible;
            }
        }
    }

    // Mostrar cabecera de capacidades
    cout << "      ";
    for(int w = 1; w <= W; ++w)
        cout << setw(6) << w;
    cout << "\n";

    // Mostrar filas: i y dp[i][w]
    for(int i = 1; i <= n; ++i) {
        cout << setw(4) << i << "  ";
        for(int w = 1; w <= W; ++w)
            cout << setw(6) << dp[i][w];
        cout << "\n";
    }

    // Valor óptimo
    cout << "\nValor maximo con capacidad " << W << " lb:  $"
         << dp[n][W] << "\n\n";

    // Reconstruir solución
    bool tomado[n] = { false };
    int w = W;
    for(int i = n; i >= 1; --i) {
        if (dp[i][w] != dp[i-1][w]) {
            tomado[i-1] = true;
            w -= peso[i-1];
        }
        if (w == 0) break;
    }

    // Mostrar ítems seleccionados
    cout << "Items seleccionados:\n";
    for(int i = 0; i < n; ++i) {
        if (tomado[i])
            cout << " - " << nombre[i] << "\n";
    }

    return 0;
}
