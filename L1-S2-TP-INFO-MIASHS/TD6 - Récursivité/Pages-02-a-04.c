#include <stdio.h>

int puissance(int x, int n){
	if(n < 0) return n;
	if(n==0)return 1;
	int nb = x, i;
	for(i = 1; i < n; i++){
		nb*= x;
	}
	return nb;
}

int fonction_puissance_recursive(int x, int n){
	if(n==0)return 1;
	return x * fonction_puissance_recursive(x, n - 1);
}

int fonction_puissance_recursive_rapide(int x, int n){  //ERREUR SUR CETTE FONCTION
	if(n==0)return 1;
	int pui=n,var=x;
	
	var=fonction_puissance_recursive_rapide(x*x, pui/2);
	
	if(pui%2==0)return var;
	else return x*var;
}

int main(){
	
	int nb = 3, pui = 4;
	
	printf("\nBasique : %d^%d = %d\n",nb, pui, puissance(nb, pui));

	printf("\nRecursive : %d^%d = %d\n",nb, pui, fonction_puissance_recursive(nb, pui));
	
	printf("\nRecursive rapide : %d^%d = %d\n",nb, pui, fonction_puissance_recursive_rapide(nb, pui));

		
	return 0;
}

