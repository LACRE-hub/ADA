#include<stdio.h>
#include<stdlib.h>



int main() {
    int n;

   
    printf("Ingresa la dimension de la matriz: ");
    scanf("%d", &n);

    if (n % 2 != 0) {
        printf("No es posible hacer el producto de matrices. El tamaño de la matriz debe ser par.\n");
        exit(1);  
    }

    
    int A[n][n]; 
    int B[n][n];
    int C[n][n];  

    int i, j, k; 

   
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
            C[i][j] = 0; 
            for (k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

   
    printf("El resultado de la multiplicación de matrices A y B es:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("[%d] ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
