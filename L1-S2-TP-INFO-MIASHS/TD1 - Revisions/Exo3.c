#include <stdio.h>

int min2int(int a, int b){	//QUESTION 1
	if(a<b)return a;
	else return b;
}

int min3int(int a, int b, int c){	//QUESTION 2
	return min2int(min2int(a,b),min2int(b,c));
}

int min4int(int a,int b,int c,int d){	//QUESTION 3
	//return min3int(min2int(a,b),min2int(b,c),min2int(c,d));
	return min2int(min3int(a,b,c),min3int(b,c,d));
}

int main(){
	
	int a=36;
	int b=48;
	int c=17;
	int d=5;
	
	printf("\n\nMinimum entre %d et %d : %d",a,b,min2int(a,b));	//QUESTION 1
	
	printf("\n\nMinimum entre %d, %d et %d : %d",a,b,c,min3int(a,b,c));	//QUESTION 2

	printf("\n\nMinimum entre %d, %d, %d et %d : %d",a,b,c,d,min4int(a,b,c,d));	//QUESTION 3

	return 0;
}

