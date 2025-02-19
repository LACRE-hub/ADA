# include <stdio.h>
 
 
 void polindromo(int num)
 {
 	int inverso=0, original=num, acumulable; 
 	
 	do{
 		
		acumulable=num%10; 
		inverso=inverso*10+acumulable;  		
 		num/=10;
 		
	 }while(num>0); 
	 
	 
	 if(original==inverso)
	 printf("El numero es polindromo"); 
	 else
	 printf("El numero no es polindromo");
	 
 	
 }
 
 
int main()
{
	
	int num;
	puts("Ingresa un numero:"); 
	scanf("%d", &num); 
	
	
	polindromo(num);
	

	return 0; 
	
	 }                                      