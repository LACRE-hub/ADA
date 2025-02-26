#include <stdio.h>
#include <stdlib.h>

void verificar(int x, int y)
{
	int cont=0; 
	if (x == 0) {
        printf("La operacion no se puede realizar ya que el dividendo x es igual a: %i\n", x); 
        exit(1);  
    } 
    
    if (y == 0) {
        printf("La operacion no se puede realizar ya que el divisor y es igual a: %i\n", y); 
        exit(1); 
    } 

    if (y > 0) {
        while (x >= y) {
            x = x - y; 
            cont++; 
        }     
    } 
    else {
        while (x > 0) {
            x = y + x; 
            cont--; 
        }
    }
    printf("El resultado de la division de %i / %i es: %i\n", original, y, cont); 
}


int main()
{
    int x, y; 
    puts("Ingresa el valor de x:"); 
    scanf("%i", &x); 
    int original = x; 
    puts("Ingresa el valor de y:"); 
    scanf("%i", &y);
    
    verificar(x,y); 

    
    
    return 0; 
}

