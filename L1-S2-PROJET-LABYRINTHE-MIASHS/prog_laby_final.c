#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int** matrice_init(int cote){ // initialise les cases de la matrice a des valeurs de 1 à cote*cote et a 0 pour les murs
	int **p = (int**) malloc( sizeof(int*) * cote); 		//1ere dimension
	int i, j, cpt=1;

	for(i = 0; i<cote;i++){
		p[i] = (int*) malloc( sizeof(int) * cote);			//2e dimension
		for(j=0;j<cote;j++){

			if(i%2==0) p[i] [j] = 0;								//si ligne paire, rempli de 0

			else{
				if(j%2==0) p[i] [j] = 0;							//sinon 0 sur les colonnes paires, nombre sur les colonnes impaires
				else p[i] [j] = cpt++;
			}
		}
	}
	return p;
}

int test_nb_cases(int **mat, int cote){ //teste si toutes les cases sont bien a la meme valeur (=chemin d'entree a sortie existant)
	int nb = mat[1] [1];

	for(int i = 1; i < cote - 1; i = i + 2){
		for(int j = 1; j < cote - 1; j = j + 2){
			if(mat[i][j] != nb) return 0;
		}
	}
	return 1;
}

void affiche(int **mat, int cote){ //affiche la matrice dans la console si besoin de la vérifier avec les nombres
		for(int i = 0; i < cote; i++){
		printf("\n\n");
		for(int j = 0; j < cote; j++) printf("|\t%d \t|",mat[i] [j]);
	}
}

void wall_break(int **mat, int cote){ // permet de casser les murs pour creuser le labyrinthe
	srand(time(NULL));
	mat[1] [0] = mat[1] [1]; 									// cree l'entrée
	mat[cote-2] [cote-1] = mat[cote-2] [cote-2]; 	// cree la sortie

	while(test_nb_cases(mat,cote) == 0){ 								// tant qu'il n'y a pas de chemin de l'entree a la sortie
		int nbL = rand()%(cote-2)+1,nbC;									//ligne aleatoire

		if(nbL%2 == 0) nbC = (rand()%((cote - 1) / 2))*2 + 1;		//colonne aleatoire
		else nbC = (rand()%((cote - 2)/2))*2 + 2;

		int case1,case2;

		if(mat[nbL - 1] [nbC] == 0){					//si mur au dessus du mur
			case1 = mat[nbL] [nbC-1];				//cases sont a gauche et a droite
			case2 = mat[nbL] [nbC+1];
		}else{
			case1 = mat[nbL-1] [nbC];				//sinon cases sont en haut et en bas
			case2 = mat[nbL+1] [nbC];
		}

		if(case1 != case2){ //si les cases autour du mur sont différentes

			int rdm = rand()%2;	//rend aleatoire le choix de la case qui remplacera l'autre
			if(rdm == 0) mat[nbL] [nbC] = case1;
			if(rdm == 1) mat[nbL] [nbC] = case2;

			for(int i = 1; i < cote - 1; i = i + 2){	//rempalce les cases necessaires dans tout le labyrinthe
				for(int j = 1; j < cote -1; j = j + 2){
					if(rdm == 0){
						if(mat[i] [j] == case2) mat[i] [j] = case1;
					}
					if(rdm == 1){
						if(mat[i] [j] == case1) mat[i] [j] = case2;
					}
				}
			}
		}
	}
}

void affichage_labyrinthe(int** tab, int cote){ // affiche le labyrinthe sous forme lisible dans la console

	for(int i = 0; i < cote; i++){
		printf("\n");
		for(int j = 0; j < cote; j++){
			if(tab[i][j] == 0)printf("\u2588"); //affiche un mur si la case est egale a 0
			else printf(" ");							//affiche un espace sinon
		}
	}
}

void fichier_labyrinthe(int **mat,int cote){ // affiche le labyrinthe dans un fichier.txt
	FILE *fp=NULL;							//ouverture de fichier
	fp=fopen("labyrinthe.txt","w");
	if(fp==NULL){
		printf("	Erreur lors de la creation / ouverture du fichier");
		return;
	}

	for(int i = 0; i < cote; i++){
		fprintf(fp,"\n");
		for(int j = 0; j < cote; j++){
			if(mat[i][j] == 0)fprintf(fp,"\u2588");	//affiche les murs
			else fprintf(fp," ");								//affiche les couloirs
		}
	}
	fclose(fp);												//fermeture du fichier
}


void generation_labyrinthe(int **mat,int cote){	//cree le labyrinthe a partir des fonctions precedentes
	wall_break(mat,cote);
	fichier_labyrinthe(mat,cote);
	affichage_labyrinthe(mat,cote);
}

int main(){
	int **matrice;
	int size;
	printf("Entrez la taille de labyrinthe carre souhaitee : ");
	scanf("%d", &size);
	size=size*2+1;
	
	matrice=matrice_init(size); //genere la matrice initiale

	generation_labyrinthe(matrice,size); //cree le labyrinthe, l'affiche et l'enregistre dans un fichier

	return 0;
}

