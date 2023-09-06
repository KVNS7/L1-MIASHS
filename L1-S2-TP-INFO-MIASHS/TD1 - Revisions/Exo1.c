#include <stdio.h>
#include <math.h>

int test_premier(long long nb){
	
	for(long i=2;i<sqrt(nb);i++){
		if(nb%i==0){
			return 0;
		}
	}
	return 1;
}

long long pp_facteur_prem(long long nb){	//QUESTION 1
	long long i,pp_div=0;
	
	for(i=sqrt(nb);i>1;i--){
		if(test_premier(i)==1){
			if(nb%i==0){
				pp_div=i;
				nb/=i;
			}
		}
	}
	if(pp_div!=0) return pp_div;
	else return nb;
}

long long pg_facteur_prem(long long nb){	//QUESTION 2
	long long i;
	
	for(i=sqrt(nb);i>1;i--){
		if(test_premier(i)==1){
			if(nb%i==0){
				return i;
			}
		}
	}
	return nb;
}

int test_nbperfect(long long nb){	//QUESTION 3
	long long sum=0;
	
	for(long long i=nb/2;i>0;i--){
		if(nb%i==0){
			sum+=i;
		}
	}
	if(sum==nb) return 1;
	else return 0;
}

long test_Harshad(long long nb){	//QUESTION 4
	if(nb<1)return 0;
	long long temp=nb;
	long sum=0;
	
	while(temp!=0){
		sum+=(temp%10);
		temp/=10;
	}
	if(nb%sum==0) return 1;
	else return 0;
}

int main(){
	
	long long a=600851475143;
	long long b=8128;
	long long c=195;
	
	printf("\nPremier ou non : %d",test_premier(a));
	printf("\nPlus petit facteur premier : %lld",pp_facteur_prem(a));	//QUESTION 1
	printf("\nPlus grand facteur premier : %lld",pg_facteur_prem(a));	//QUESTION 2
	
	printf("\nParfait ou non : %d",test_nbperfect(b));	//QUESTION 3
	
	printf("\nTest Harshad : %ld",test_Harshad(c));	//QUESTION 4
	
	return 0;
}
