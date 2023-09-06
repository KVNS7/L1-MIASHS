#include <stdio.h>
#include <stdio.h>

void cesar(char *source, char *destination, int decalage){
	FILE *fp_s=NULL, *fp_d=NULL;
	fp_s = fopen(source,"r"), fp_d = fopen(destination,"w");
	if(fp_s==NULL || fp_d==NULL)perror("Echec lors de l'ouverture d'un des fichier");

	while(1){
		char cchar=fgetc(fp_s);
		if(cchar==EOF)break;
		if(cchar==' ')fprintf(fp_d," ");
		else{
			fprintf(fp_d,"%c",cchar+decalage);
		}	
	}
}

int main(){
	
	cesar("c_source.txt","c_destination.txt",5);
	
	return 0;
}

