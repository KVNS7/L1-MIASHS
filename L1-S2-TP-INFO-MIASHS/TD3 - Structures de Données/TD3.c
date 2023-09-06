#include <stdio.h>
#include <stdlib.h> // Pour le exit(0)
#include <math.h> //Pour le sqrt()


typedef struct rationnel{
  int num;
  int denom;
}rationnel;

rationnel construire_rationnel(int a,int b){
	if(b==0){
		printf("\n\n--- Division par 0 -> echec ---\n\n");
		exit(0);
	}
	rationnel frac;
	frac.num=a,frac.denom=b;
	return frac;
}

void affichage_rationnel(rationnel r){
	printf("\n%d / %d",r.num,r.denom);
}

rationnel somme_rationnels(rationnel a, rationnel b){
	rationnel c;
	c.num=(a.num*b.denom)+(b.num*a.denom);
	c.denom=a.denom*b.denom;
	
	for(int i=sqrt(c.denom);i>1;i--){
		if(c.denom%i==0){
			if(c.num%i==0){
				c.num/=i;
				c.denom/=i;
			}
		}
	}
	return c;
}

int main(){
	
	rationnel test,test2,test3;
	
	test=construire_rationnel(2,3);
	affichage_rationnel(test);
	
	test2=construire_rationnel(4,9);
	affichage_rationnel(test2);
	
	test3=somme_rationnels(test,test2);
	affichage_rationnel(test3);

	return 0;
}

