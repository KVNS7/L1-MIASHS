#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* allocation1(int taille){
	int *tab=malloc(sizeof(int)*taille);
	return tab;
}

int*allocation2(int taille){
	int *tab=calloc(sizeof(int),taille);
	return tab;
}

int* allocation3(int taille,int n){
	srand(time(NULL));
	int *tab=malloc(sizeof(int)*taille);
	
	for(int i=0;i<taille;i++){
		*(tab+i)=rand()%n;
	}
	return tab;
}

void liberation1(int *tab){
	free(tab);
}

int main(){
  
  printf("\n%p\n\n",allocation1(3));
  int*tab2=allocation2(3);
  int*tab3=allocation3(6,8);
  
  for(int i=0;i<3;i++){
	printf("%d ",*(tab2+i));
	}
	printf("\n\ntab3 avant liberation :\n");
	for(int i=0;i<3;i++){
	printf("%d ",*(tab3+i));
	}
  liberation1(tab2);
  liberation1(tab3);
  
  printf("\n\ntab3 apres liberation :\n");
	for(int i=0;i<3;i++){
	printf("%d ",*(tab3+i));
	}
  return 0;
}
