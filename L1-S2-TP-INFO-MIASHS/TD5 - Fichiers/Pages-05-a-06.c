#include <stdio.h>
#include <stdlib.h>

void affichage_fichier_lignes(char *nom){
	FILE *fp = NULL;
	int i = 1;
	fp = fopen(nom,"r");
	if(fp==NULL)perror("Echec ouverture du fichier");

	printf("%d :\t",i);
	while(1){ 							//Boucle infinie
		char cchar = fgetc(fp);
		if(cchar==EOF)break; 	//Quitte la boucle quand rencontre EOF lors de lecture du fichier

		if(cchar=='\n'){
			i++;
			printf("\n%d :\t",i);
		}else{
			 printf("%c",cchar);
		}
	}
	fclose(fp);
}

void affichage_sans_commentaires(char *nom){ // Masque commentaires et \t mais pas espaces en debut de phrase
	FILE *fp = NULL;
	fp = fopen(nom,"r");
	if(fp==NULL)perror("\nEchec d'ouverture du fichier\n");

	while(1){
		char cchar=fgetc(fp);
		if(cchar==EOF)break;

		if(cchar=='#'){
			while(cchar!='\n'){
				cchar = fgetc(fp);
			}
		}
		if(cchar!='\t')printf("%c",cchar);
	}
	fclose(fp);
}

int main(){
	
	printf("\nAffichage avec lignes :\n\n");
	affichage_fichier_lignes("exemple2.txt");
	printf("\n\n\nAffichage sans commentaires :\n");
	affichage_sans_commentaires("exemple2.txt");

	return 0;
}
