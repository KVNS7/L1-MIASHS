#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int** matrice_init(int cote){ // initialise les valeurs dans la matrice avec des chiffres de 1 a (cote*cote)-1 et 0 pour les murs
	int **p = (int**) malloc(sizeof(int*) * cote);

	int i, j, cpt = 1;

	for(i = 0; i<cote;i++){								// affectation des valeurs dans la matrice
		p[i] = (int*) malloc( sizeof(int) * cote);	// creation de la ligne
		for(j=0;j<cote;j++){
			
			if(i%2==0) p[i] [j] = 0;						// si ligne paire
			
			else{												// si ligne impaire
				if(j%2==0) p[i] [j] = 0;					// si colonne paire
				else p[i] [j] = cpt++;					// si colonne impaire
			}
		}
	}
	return p;
}

int test_cases(int** tab,int cote){ // teste similarité toute cases nombrées a l'origine
	int nb=tab[1][1];														 // prend la premiere case comme nb reference

	for(int i=1;i<cote-1;i+=2){
		for(int j=1;j<cote-1;j+=2) if(tab[i][j]!=nb) return 0;	// renvoie 0 si une diff de nb
	}
	return 1;																	// apres test tt les cases, renvoie 1 si aucune diff
}

void wall_break(int **tab,int cote,int L, int C){ // casse un mur avec les coordonnées [L][C], L=lignes | C=colonnes
	
	if(L%2==0){ 														//si mur ligne paire
		if(tab[L-1] [C] != tab[L+1] [C]){						// si au dessus et en dessous mur, nb different
			int random = rand()%2;								//randomize si garde valeur du haut ou bas
			if(random == 0) tab[L] [C] = tab[L-1] [C]; 
			else tab [L] [C] = tab[L+1] [C];
			
			for(int k = 1; k < cote - 1; k++){				//boucle qui rempalcent toutes les cases necessaires apres cassage mur
				for(int l = 1; l < cote - 1; l++){
					if(random==0){															//si a garder valeur du haut
						if(tab[k] [l] == tab[L+1] [C]) tab[k] [l] = tab[L-1] [C];	// change tt les cases avec nb de case du bas par celle du haut
					}if(random==1){															// si a garder valeur du bas
						if(tab[k] [l] == tab[L-1] [C]) tab[k] [l] = tab[L+1] [C];	// change tt les cases avec nb de cases du haut par celle du bas
					}
				}
			}
		}	
	}if(L%2==1){														//si mur ligne impaire
		if(tab[L] [C-1] != tab[L] [C+1]){						//si gauche et droite du mur, nb different
			int random = rand()%2;								//randomize si garde valeur de gauche ou droite
			if(random == 0) tab[L] [C] = tab[L] [C-1];
			else tab[L] [C] = tab[L] [C+1];
			
			for(int k = 1; k < cote - 1; k++){					//boucle qui rempalcent toutes les cases necessaires apres cassage mur
				for(int l = 1; l < cote - 1; l++){
					if(random==0){															//si a garder valeur de gauche
						if(tab[k] [l] == tab[L] [C+1]) tab[k] [l] = tab[L] [C-1];	//change tt les cases avec nb de case de gauche par celle de droite
					}if(random==1){															//si a garder valeur de droite
						if(tab[k] [l] == tab[L] [C-1]) tab[k] [l] = tab[L] [C+1];	//change tt les cases avec nb de case de droite par celle de gauche
					}
				}
			}
		}
	}
}

void random_wall(int** tab, int cote){ // renvoie 2 nombres random qui correspondent a la pos d'un mur intérieur au laby
	srand(time(NULL));
	int nbL,nbC,cpt=0;
	do{
		do{
			nbL = (rand()%(cote-2)) + 1; 				//pour ne pas prendre un mur exterieur on rajoute +1 (et on enleve 3 car il y a +1)

			if(nbL%2 == 1){ 									//si ligne impair
				do{
					nbC = (rand()%(cote-2)) + 1;
				}while(nbC%2 == 1);						 //colonne pair
			}

			if(nbL%2 == 0){ 									//si ligne pair
				do{
					nbC = (rand()%(cote-2))+1;
				}while(nbC%2 == 0); 						//colonne impair
			}

		}while(tab[nbL] [nbC] != 0);						//tant que les coordonnées ne renvoient pas sur un mur : (!=0)
		wall_break(tab,cote,nbL,nbC);
		printf("\n\ntab[%d] [%d] = %d \n\n", nbL, nbC, tab[nbL] [nbC]);
	}while(cpt++<600);//test_cases(tab,cote) == 0); // tant que toutes les cases du labyrinthes n'ont pas le même nombre
	

}

void murs_restants(int **tab,int cote){ //regle le probleme des murs en trop qu'il reste
	int valeurs[(cote-1)][cote-1][4],choix;
	for(int i=2;i<cote-2;i=i+2){												// double boucle qui prend tous les murs ligne paire colonne paire
		for(int j=2;j<cote-2;j=j+2){
			valeurs[i-2][j-2][0]=tab[i-1][j];									//on prend les 4 cases qui entourent ce mur
			valeurs[i-2][j-2][1]=tab[i+1][j];
			valeurs[i-2][j-2][2]=tab[i][j-1];
			valeurs[i-2][j-2][3]=tab[i][j+1];
			
			for(int k=0;k<4;k++){												//pour chaque coordonnee de tab presente dans le tableau valeurs
				for(int l=0;l<4;l++){
					if(valeurs[i-2][j-2][k]!=valeurs[i-2][j-2][l]){			//si au moins une des valeurs est differente des autres
						choix=rand()%2;
						if(choix==0)tab[i][j]=valeurs[i-2][j-2][k];		//on remplace le mur par une valeurs aleatoire parmi les 4 autour
						else tab[i][j]=valeurs[i-2][j-2][k];
					}
				}
			}
		}
	}
}

void affichage_labyrinthe(int** tab, int cote){ // affiche le labyrinthe sous forme lisible
	tab[1] [0] = tab[1] [1];
	tab[cote-2] [cote-1] = tab[cote-2] [cote-2];
	
	for(int i = 0; i < cote; i++){
		printf("\n");
		for(int j = 0; j < cote; j++){
			if(tab[i][j] == 0)printf("+");
			else printf(" ");
		}
	}
}

int main(){

	int cote = 5;
	cote = cote*2 + 1;
	int** mat = matrice_init(cote);

	////////////////////AFFICHAGE MATRICE////////////////////
	for(int i = 0; i < cote; i++){
		printf("\n\n");
		for(int j = 0; j < cote; j++) printf("|\t%d \t|",mat[i] [j]);
	}
	/////////////////////////////////////////////////////////////////////////////

	printf("\n\nTest cases : %d", test_cases(mat, cote));
	random_wall(mat, cote);
	murs_restants(mat,cote);
	////////////////////AFFICHAGE MATRICE////////////////////
	for(int i = 0; i < cote; i++){
		printf("\n\n");
		for(int j = 0; j < cote; j++) printf("|\t%d \t|",mat[i] [j]);
	}
	/////////////////////////////////////////////////////////////////////////////
	
	affichage_labyrinthe(mat,cote);
	
	return 0;
}
