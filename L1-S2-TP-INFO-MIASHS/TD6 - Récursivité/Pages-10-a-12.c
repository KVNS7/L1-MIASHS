#include <stdio.h>

int fibonacci_recursif(int n){
	if(n < 0)return n;
	if(n==0)return 0;
	if(n==1)return 1;
	return fibonacci_recursif(n - 1) + fibonacci_recursif(n - 2);
}

int autre_suite(int n){
	if(n < 0)return n;
	if(n==0) return 3;
	if(n==1) return 5;
	int u = autre_suite(n - 1);
	return u * u * autre_suite(n - 2);
	
}

int encore_suite(int n){
	if(n < 0)return n;
	if(n<3)return 1;
	if(n%2==0)return 1;
	return 2 * encore_suite(n - 2);
	
}

int main(){
	
	int fibo = 8, n = 3, n2 = 15;
	
	printf("\n%de terme de Fibo = %d",fibo, fibonacci_recursif(fibo));
	
	printf("\n\n%de terme de autre_suite = %d",n, autre_suite(n));
	
	printf("\n\n%de terme de encore_suite = %d",n2, encore_suite(n2));
	
	return 0;
}

