#include <stdio.h>
#include <stdbool.h>

#define MAX 1000

//ESPIN CARREÑO CARLO ALEXANDER


bool esPrimo(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0) return false;
    return true;
}


int generarFibonacciFiltrado(int fib[], int K) {
    int a = 0, b = 1, temp;
    int pos = 1, idx = 0;
    while (a <= K) {
        if (!esPrimo(pos)) {
            fib[idx++] = a;
        }
        temp = a + b;
        a = b;
        b = temp;
        pos++;
    }
    return idx;
}


int mejor[MAX], mejorTam = MAX;
void buscar(int fib[], int n, int K, int i, int suma, int usados[], int tam, int last) {
    if (suma > K || tam >= mejorTam) return;
    if (suma == K) {
        mejorTam = tam;
        for (int j = 0; j < tam; ++j) mejor[j] = usados[j];
        return;
    }
    for (int j = i; j < n; ++j) {
        if (j == last + 1) continue;  
        usados[tam] = fib[j];
        buscar(fib, n, K, j + 1, suma + fib[j], usados, tam + 1, j);
    }
}

int main() {
    int dia, mes, anio;
    printf("Introduce tu dia, mes y anio de nacimiento (DD MM AAAA): ");
    scanf("%d %d %d", &dia, &mes, &anio);

    int K = dia * 100 + mes * 10 + (anio % 100);
    printf("K calculado: %d\n", K);

    int fib[MAX], usados[MAX];
    int n = generarFibonacciFiltrado(fib, K);

    printf("Secuencia de Fibonacci filtrada:\n");
    for (int i = 0; i < n; ++i) {
        printf("%d ", fib[i]);
    }
    printf("\n");

    buscar(fib, n, K, 0, 0, usados, 0, -1);

    if (mejorTam < MAX) {
        printf("Combinacion optima con %d terminos:\n", mejorTam);
        for (int i = 0; i < mejorTam; ++i)
            printf("%d ", mejor[i]);
        printf("\n");
    } else {
        printf("No se encontro una combinacion valida.\n");
    }
    return 0;
}