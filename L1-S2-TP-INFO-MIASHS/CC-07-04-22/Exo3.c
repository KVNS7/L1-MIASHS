#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int SIZE = 13;
const int SIZE2 = 12;


int* allocation(int taille){
	srand(time(NULL));
	if(taille%2==0){
		perror("\nValeur de taille impaire necessaire");
		exit(EXIT_FAILURE);
	}
	int*tab = malloc(sizeof(int)*taille);
	int i, nb, aux, c1, c2;
	
	for(i = 0; i < taille; i++){
		if(i%2==0)nb = rand();
		tab[i] = nb;
	}
	for(i=0 ; i < (taille*3); i++){
		c1 = rand()%taille,c2 = rand()%taille;
		aux = tab[c1];
		tab[c1] = tab[c2];
		tab[c2] = aux;
	}
	return tab;
}
	
void single(int *tab,int taille){ 
	int i, j = 0, cpt, nb;
	do{
		cpt = 0, nb = tab[j];
		for(i = 0; i < taille; i++){
			if(tab[i]==nb)cpt++;
		}
		j++;
	}while(cpt==2 && j < (taille-1));
	printf("\ncpt = %d et j = %d",cpt,j);
	if(cpt==1)printf("\nLa valeur présente une seule fois dans le tableau est %d\n",nb);
	else printf("\nAucune des valeurs du tableau n'es présente qu'une seule fois\n");
}

int main(){
  //int *tableau = allocation(SIZE2);		//Test avec valeur paire
  int *tableau = allocation(SIZE);
  
  for(int i = 0; i < SIZE; i++){
	printf("\n%d",tableau[i]);
  }
  
  single(tableau,SIZE);
  
  return 0;
}
