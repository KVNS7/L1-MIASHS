#include <stdio.h>

const int size=10;

/*Séquence d'instructions 3 :
 * 1. 14
 * 2. 34
 * 3. 4 (indices : 5-1)
 * 4. Vrai
 * 5. Faux
*/

/*Séquence d'instrucitons 4 :
 * Après ces lignes de code on obtient le meme tableau dans l'ordre inverse 
*/

/* Reecriture 1 :
 * 1. tab[0] = 1
 * 2. tab[5] = 10
 * 3. pt = tab
 * 4. a = toto
 * 5. a = toto
 * 6. tab[0] = tab[5]
*/

/* Reecriture 2 :
 * 1. *tab = 0
 * 2. *(tab+4) = *(tab+3)
 * 3. *(*(tab)) = *(tab+1) * *(tab+2)
*/

/* Fonction mystere :
 * e1 = 7  et  e2 = 5
*/

int main(){

	char tab_c[size],*p = &tab_c[0];
	int tab_i[size],*q = &tab_i[0];
	double tab_d[size],*r = &tab_d[0];
	
	for(int i = 0 ; i < 10; i++) {																			// Résultat :
		printf("\np+%d : Adresse= %p, valeur = %c",i,p+i,*(p+i));			// augmente de 1 a chaque tour
		printf("\nq+%d : Adresse= %p, valeur = %d",i,q+i,*(q+i));			// augmente de 4 a chaque tour
		printf("\nr+%d : Adresse = %p, valeur = %lf\n",i,r+i,*(r+i));			// augmente de 8 a chaque tour
	}
	printf("\nsizeof(char) = %lu\nsizeof(int)=%lu\nsizeof(double)=%lu",sizeof(char),sizeof(int),sizeof(double));
	
	return 0;
}

