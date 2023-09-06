#include <stdio.h>

typedef struct spectacle{
	int jour;
	int mois;
	int annee;
	int salle;
	float prix;
	char titre;
}spectacle;

spectacle init_spectacle(int j, int m, int a, int s,float p, char t){
	spectacle var={j,m,a,s,p,t};
	return var;
}

int main(){
	
	spectacle var=init_spectacle(7,4,2022,2,7.89,'A');
	
	printf("\nDate : %d/%d/%d \nSalle : %d\nPrix : %f\nPremiere lettre film : %c",var.jour,var.mois,var.annee,var.salle,var.prix,var.titre);
	
	return 0;
}

