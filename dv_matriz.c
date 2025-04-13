#include<stdio.h>
#include<stdlib.h>

int n;  


int multiplicar_matrices(int A[n][n], int B[n][n], int i, int j, int k) {
    
    if (k == n) {
        return 0;
    }

    
    return A[i][k] * B[k][j] + multiplicar_matrices(A, B, i, j, k + 1);
}

int main() {
    printf("Ingresa la dimension de la matriz: ");
    scanf("%d", &n);
    
    if (n % 2 != 0) {
        printf("No es posible hacer el producto de matrices. El tamanio de la matriz debe ser par.\n");
        exit(1);  
    }

    int A[n][n]; 
    int B[n][n];
    int C[n][n];  

    int i, j;

    
    printf("Ingreso de los numeros de la matriz A:\n"); 
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("[%d][%d]: ", i+1, j+1);
            scanf("%d", &A[i][j]);
        }
    }

    
    printf("Ingreso de los numeros de la matriz B:\n"); 
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("[%d][%d]: ", i+1, j+1);
            scanf("%d", &B[i][j]);
        }
    }

    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            
            C[i][j] = multiplicar_matrices(A, B, i, j, 0);
        }
    }

    
    printf("El resultado de la multiplicacion de matrices A y B es:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
