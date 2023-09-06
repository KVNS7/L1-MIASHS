#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

typedef struct case_tab{
	bool pass;
	int nb_case;
}cstb;

cstb ** matrice(int cote){
	cstb **p=(cstb**)malloc( sizeof (cstb*) * cote); //crée un tableau 1D de taille cote;
	int cpt = 1, i,j;

	for(i = 0; i < cote; i++){
		p[i] = (cstb*) malloc(sizeof(cstb) * cote); //crée la 2e D de taille cote dans tableau
	}
	
	for(i=0;i<cote;i++){
		if(i%2==1){
			for(j=0;j<cote;j++){
				if(j%2==1){
					p[i][j].nb_case = cpt++,p[i][j].pass = 0;
				}else{
					p[i][j].nb_case = 0;
				}
			}
		}else{
			for(j=0;j<cote;j++){
				p[i][j].nb_case = 0;
			}
		}
	}
	return p;
}

void casse_mur(cstb** tab,int i, int j,int cote){
    //ligne paire:
    if(i%2==0){
        if(j%2==1){//colonne impaire
            if(tab [i-1] [j].nb_case != tab [i+1] [j].nb_case){
				
                tab [i] [j].nb_case = tab [i-1] [j].nb_case;//on casse le mur 
                
                for(int k=1;k<cote-1;k++){
					for(int l=1;l<cote-1;l++){
						if(tab[k][l].nb_case==tab[i+1][j].nb_case) tab [k] [l].nb_case = tab [i-1] [j].nb_case; //on remplace par la valeur a gauche du mur (question de simplicite)
					}
				}
            }
            else printf("Err 1");
        }
        else printf("On ne peut rien faire dans ce cas la");//colonne paire
    }
    
    //ligne impaire:
    else{
        if(j%2==0){//colonne paire
            
            if(tab [i] [j-1].nb_case != tab [i] [j+1].nb_case){
				
                tab [i] [j].nb_case = tab [i] [j-1].nb_case;//on casse le mur
                
				for(int k=1;k<cote-1;k++){
					for(int l=1;l<cote-1;l++){
						if(tab[k][l].nb_case==tab[i][j+1].nb_case) tab [k] [l].nb_case = tab [i] [j-1].nb_case;//on remplace par la valeur au dessus du mur (question de simplicite)
					}
				}
            }
            else printf("Err 2");
        }
        else printf("On ne peut rien faire dans ce cas la");//colonne impaire
    }
}

int test_nb_cases(cstb** mat,int cote){
	int cpt=0;
		for(int k = 1; k < cote-1; k+=2){
			for(int l = 1; l < cote-1; l+=2){
				if(mat[k][l].nb_case==mat[1][1].nb_case){ //ajoute 1 quand la case contient le nombre
					cpt++;
				}
			}
		}
	if(cpt==((cote-1)/2)*((cote-1)/2))return 1; // s'il y'a n fois le nombre dans la matrice, retourne 1(True) avec n= nb de cases de la matrice
	else return 0;
}

void mur_random(int cote,cstb** mat){
	srand(time(NULL));
	int nb1,nb2;
	//while(test_nb_cases(mat,cote)==0){
	//for(int test=0;test<100;test++){
		do{
			nb1=(rand()%(cote-3))+1;
			if(nb1%2==1){
				do{
					nb2=(rand()%(cote-3))+1;
				}while(nb2%2==1);
			}
			if(nb1%2==0){
				do{
					nb2=(rand()%(cote-2))+1;
				}while(nb2%2==0);
			}
		}while (mat[nb1][nb2].nb_case != 0);
		printf("\n\ntab[%d][%d] = %d \n\n",nb1,nb2,mat[nb1][nb2].nb_case);
		//casse_mur(mat,nb1,nb2,cote);
	//}
}

int main(){

	cstb** maze=NULL;
	int cote=5;
	cote = cote*2+1;

	maze=matrice(cote);

 //Affichage de la matrice
	for(int i=0;i<cote;i++){
		printf("\n\n");
		for(int j=0;j<cote;j++){
			printf("|\t%d \t|",maze[i][j].nb_case);
		}
	}
	printf("\n\nCases toutes pareilles ?  : %d\n\n",test_nb_cases(maze,cote));
	
	mur_random(cote,maze);
	
	printf("\n\n\n");
	for(int i=0;i<cote;i++){
		printf("\n\n");
		for(int j=0;j<cote;j++){
			printf("|\t%d \t|",maze[i][j].nb_case);
		}
	}
	
	printf("\n\nCases toutes pareilles ?  : %d\n\n",test_nb_cases(maze,cote));

	return 0;
}
