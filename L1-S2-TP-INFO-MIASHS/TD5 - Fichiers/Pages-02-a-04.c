#include <stdio.h>
#include <stdlib.h>

void ecriture_simple(){
	FILE *fp = NULL;
	fp = fopen("exemple.txt","w");
	if(fp==NULL)perror("Echec ouverture du fichier");

	fprintf(fp,"Vive la MIAGE !");
	fclose(fp);
}

void table(int nb){
	FILE *f_table = NULL;
	f_table = fopen("table.txt","w");
	if(f_table==NULL)perror("Echec ouverture du fichier");

	for(int i = 0; i <=10; i++){
		fprintf(f_table,"%d\tx\t%d\t= %d",i,nb,i*nb);
		if(i!=10)fprintf(f_table,"\n");				//Evite de sauter une ligne tout à la fin
	}
	fclose(f_table);
}

void affichage_fichier(char *nom){
	FILE *fp = NULL;
	fp = fopen(nom,"r");
	if(fp==NULL)perror("Echec ouverture du fichier");

	printf("\nAffichage fichier :\n\n");
	while(1){ 							//Boucle infinie
		char cchar=fgetc(fp);
		if(cchar==EOF)break; 	//Quitte la boucle quand rencontre EOF lors de lecture du fichier
		else printf("%c",cchar);
	}
	fclose(fp);
}

int main(){

	int nb_table;
	printf("\nDe quel nombre voulez vous la table ? : ");
	scanf("%d",&nb_table);

	table(nb_table);

	ecriture_simple();

	affichage_fichier("table.txt");

  return 0;
}
