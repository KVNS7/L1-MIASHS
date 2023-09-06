#include <stdio.h>

int puissance(int x, int n){
	if(n==0) return 1;
	int aux=x;
	for(int i=1;i<n;i++){
		x*=aux;
	}
	return x;
}

int nb_chiffres(int nb){
	int cpt=0;
	while(nb!=0){
		nb/=10;
		cpt++;
	}
	return cpt;
}	

int narcissique(int nb){
	int nbc=nb_chiffres(nb),sum=0,aux=nb;
	
	while(aux!=0){
		sum+=puissance((aux%10),nbc);
		aux/=10;
	}
	if(sum==nb) return 1;
	else return 0;
}

int main(){
	
	int a=3,b=15,c=548834,d=93084;
	
	printf("\n%d^%d = %d",a,b,puissance(a,b));
	
	printf("\n\nNombre de chiffres de %d^%d : %d",a,b,nb_chiffres(puissance(a,b)));

	printf("\n\n%d narcissique ? : %d",c,narcissique(c));
	
	printf("\n\n%d narcissique ? : %d",d,narcissique(d));

	return 0;
}

