#include <stdio.h>
#include <stdbool.h>

const int size1 = 5;
const int size2 = 3;
const int size3 = size1 + size2;

void affichage_tab(int* tab, int taille){	//QUESTION 1
	for(int i=0;i<taille;i++){
		if(i!=taille-1)printf(" %d |",tab[i]);
		else printf(" %d\n",tab[i]);
	}
}

void concat_deux_vers_un(int* tab1, int* tab2, int taille1, int taille2, int* tab3){	//QUESTION 2
	int taille3=taille1+taille2;
	for(int i=0;i<taille3;i++){
		if(i<taille1)tab3[i]=tab1[i];
		else tab3[i]=tab2[i-taille1];
	}
}

int test_const_tab(int*tab, int taille){	// QUESTION 3
	for(int i=1;i<taille;i++){
		if(tab[i]!=tab[i-1]) return 0;
	}
	return 1;
}

int test_croiss_tab(int*tab,int taille){	//QUESTION 4
	for(int i=1;i<taille;i++){
		if(tab[i]<tab[i-1])return 0;
	}
	return 1;
}

int test_decroiss_tab(int*tab,int taille){	//QUESTION 5
	
	for(int i=1;i<taille;i++){
		if(tab[i]>tab[i-1])return 0;
	}
	
	return 1;
}

void tri_bulle_croissant(int*tab,int taille){	//QUESTION 7
	bool tri_fini=false; // ou int temoin=1;
	int aux;
	while(tri_fini==false/* ou temoin!=0*/){
		tri_fini=true;//ou temoin=0;
		for(int i=1;i<taille;i++){
			if(tab[i]<tab[i-1]){
				aux=tab[i];
				tab[i]=tab[i-1];
				tab[i-1]=aux;
				tri_fini=false;// ou temoin++;
			}
		}
		taille--;
	}
}

int main(){
	
	int tab1[size1]={1,4,6,3,12};
	int tab2[size2]={18,230,456};
	int tab3[size3];
	int tab4[size1]={3,3,3,3,3};
	int tab5[size1]={2,2,2,2,1};
	int tab6[size1]={2,19,7,1,3};
	
	affichage_tab(tab1,size1);	//QUESTION 1
	concat_deux_vers_un(tab1,tab2,size1,size2,tab3);	//QUESTION 2
	affichage_tab(tab3,size3);
	
	printf("\nTab 4 constant ? : %d",test_const_tab(tab4,size1));	//QUESTION 3
	printf("\nTab 5 constant ? : %d",test_const_tab(tab5,size1));
	
	
	printf("\nTab 1 croissant ? : %d",test_croiss_tab(tab1,size1));	//QUESTION 4
	printf("\nTab 2 croissant ? : %d",test_croiss_tab(tab2,size2));
	
	printf("\nTab 1 decroissant ? : %d",test_decroiss_tab(tab1,size1));	//QUESTION 5
	printf("\nTab 5 decroissant ? : %d\n",test_decroiss_tab(tab5,size1));
	
	tri_bulle_croissant(tab6,size1);	//QUESTION 7
	affichage_tab(tab6,size1);
	return 0;
}

