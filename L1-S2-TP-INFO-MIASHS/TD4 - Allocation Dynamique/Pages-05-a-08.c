#include <stdio.h>
#include <stdlib.h>

const int size1=3,size2=5;

int* concatenation_deux_tab(int*tab1, int taille1, int*tab2, int taille2){
	int taille_tab = taille1+ taille2, *tab = malloc(sizeof(int)*(taille_tab));
	
	for(int i = 0; i < taille_tab; i ++){
		if(i<taille1)*(tab+i)=*(tab1+i);
		else *(tab+i)=*(tab2+(i-taille1));
	}
	
	return tab;
}

int* sous_tab(int*tab,int debut,int fin){
	if(fin < debut) return NULL;
	int taille = fin-debut+1, *s_tab = malloc(sizeof(int)*(taille)), j = debut;
	
	for(int i = 0; i < taille; i ++){
		*(s_tab+i)=*(tab+j);
		j++;
		
	}
	
	return s_tab;
}	

int** allocation_2D(int largeur,int hauteur){
	int**matrice;
	matrice = malloc(sizeof(int*)*largeur);
	
	for(int i = 0; i < largeur; i ++){
		*(matrice+i)=malloc(sizeof(int)*hauteur);
	}
	
	for(int j = 0; j < hauteur; j ++) {
		for(int i = 0; i < largeur; i ++) {
			*( *(matrice + i) + j) = i*j; //pareil que : matrice[i][j]=i*j
		}
	}
	
	return matrice;
}

void liberation_matrice(int** mat, int taille){
	
	for(int i = 0; i < taille; i ++) {
			free(*(mat+i));
	}	
	free(mat);
	
}

int main(){

	int tab1[] = {1, 3, 9};
	int tab2[] = {2, 32, 5, 7, 18};
	int debut = 2, fin = 4,largeur = 4,hauteur = 8;
	int*tab3 = concatenation_deux_tab(tab1, size1, tab2, size2);
	int*tab4 = sous_tab(tab2, debut, fin);
	int**tab5 = allocation_2D(largeur,hauteur);

	
	printf("\nTab3 = concatenation tab1 et tab 2 : \n");
	for(int i = 0; i < size1+ size2; i ++){
		printf("| %d | ",*(tab3+i));
	}
	
	printf("\n\nTab 4 = sous tableau tab2 indice %d à %d :\n",debut,fin);
	for(int i = 0; i < 3; i ++){
		printf("| %d | ",*(tab4+i));
	}
		
	for(int j = 0; j < hauteur; j ++) {
		printf("\n\n");
		for(int i = 0; i < largeur; i ++) {
			printf("|\t%d \t", tab5[ i ][ j ]);
		}
	}
	

	return 0;
}

