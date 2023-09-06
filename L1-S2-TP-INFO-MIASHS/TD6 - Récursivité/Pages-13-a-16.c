#include <stdio.h>

int dichotomie_recursive(int *tab, int debut, int fin, int valeur){
	
	if(debut==fin)return -1;
	int m=(debut+fin)/2;

	if(tab[m]==valeur) return m;
	
	if(tab[m]>valeur)return(dichotomie_recursive(tab,debut,m-1,valeur));
				
	else return(dichotomie_recursive(tab,m+1,fin,valeur));
}

int dichotomie(int *tab, int taille, int valeur);

int main(){
	
	int taille=10,tab[]={1,4,7,10,13,23,158,239,1236,3573};
	
	printf("\n%d",dichotomie_recursive(tab,0,taille-1,4));
	printf("\n%d",dichotomie_recursive(tab,0,taille-1,1236));
	printf("\n%d",dichotomie_recursive(tab,0,taille-1,32748));
	
	
	return 0;
}
