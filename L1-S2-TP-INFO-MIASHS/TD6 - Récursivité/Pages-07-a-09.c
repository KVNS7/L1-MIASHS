#include <stdio.h>

void tous_les_entiers_de_x_a_y_recursif( int debut , int fin){
	if(debut < fin){
		printf("%d\n",debut);
		tous_les_entiers_de_x_a_y_recursif(debut + 1, fin);
	}else printf("%d\n",fin);
}

int nombre_de_chiffres_recursif (int n){
	if(n<0) n = -n;
	if(n < 10) return 1;
	return 1 + nombre_de_chiffres_recursif(n / 10);	
}

int pgcd(int a, int b){
	if(b==0)return a;
	return pgcd(b, a % b);
}

int main(){
	
	int x = 28, y = 40, nb = 1293, a = 100, b = 180;
	
	tous_les_entiers_de_x_a_y_recursif(x,y);
	
	printf("\nNombre de chiffre de %d : %d\n",nb, nombre_de_chiffres_recursif(nb));
	
	printf("\nPGCD(%d,%d) = %d",a, b, pgcd(a,b));
	
	return 0;
}

