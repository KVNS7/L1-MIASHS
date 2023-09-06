#include <stdio.h>

int factorielle_iterative(int n){
	int nb = 1;
	for(int i = 2; i <= n; i++){
		nb*= i;
	}
	return nb;
}

int factorielle_recursive(int n){
	if(n < 2)return 1;
	return n * factorielle_recursive(n-1);
}

int main(){
	
	int fact = 4;
	
	printf("\nItérative : %d! = %d\n",fact, factorielle_iterative(fact));

	printf("\nRécursive : %d! = %d\n",fact, factorielle_recursive(fact));
	
	return 0;
}

