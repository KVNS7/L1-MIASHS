#include <stdio.h>
#include <stdlib.h>

/*Questions de cours pt. 1 :
 * 1. La mémoire est une succession -d'octets-.
 * 2. Un octet contient -8- bits. Chaque bit peut valoir -1- ou -0-.
 * 3. Chaque octet possède une -adresse-.
 * 4. Le premier octet de la mémoire a pour adresse -? 0000 0000 ?-.
 * 5. Lors de la -déclaration- d'une variable un espace mémoire est reservé (alloué) automatiquement.
 * 6. La taille de cet espace dépend de son -type-. Cette taille, en -octet-, est donné par l'opérateur -sizeof()-.
 */

void affiche_sizeof(){
	printf("sizeof(void)		=	%lu\n",sizeof(void));
	printf("sizeof(char)		=	%lu\n",sizeof(char));
	printf("sizeof(short)		=	%lu\n",sizeof(short));
	printf("sizeof(int)		=	%lu\n",sizeof(int));
	printf("sizeof(long)		=	%lu\n",sizeof(long));
	printf("sizeof(long long)	=	%lu\n",sizeof(long long));
	printf("sizeof(float)		=	%lu\n",sizeof(float));
	printf("sizeof(doube)		=	%lu\n",sizeof(double));
}

/*Questions de cours pt. 3 :
 * 1. Un pointeur est une variable qui contient l'-adresse- d'une zone dans la -mémoire-.
 * 2. Un pointeur doit toujours être initialisé à la valeur -NULL-.
 * 3. La valeur d'un pointeur qui ne pointe vers aucune variable doit être -NULL-.
 * 4. L'opérateur & placé devant le nom d'une variable permet d'obtenir son -adresse-. 
 * 5. L'adresse d'une variable correspond à l'adresse du premier de ses -octets-.
 * 6. L'opérateur * placé devant le nom d'un pointeur permet d'obtenir la -valeur- située à l'adresse pointée par ce dernier
 */
 
 /*
	int i , j , *ip ; 
	ip = &i ; 		// ip prend l'adresse de i
	i = 22 ;		// i=22 donc *ip=22 (pas ip, *ip(=valeur pointée par ip))
	j = *ip ;		// j prend la valeur pointée par ip = 22
	*ip = 17 ;	// la valeur pointée par ip devient 17 (i=17)
	
	A la fin, valeurs : i = 17 et j= 22
*/

void incremente_et_decremente(int *p,int *q){
	(*p)++;
	(*q)--;
}

void swap(int*p,int*q){
	int aux=*p;
	*p=*q,
	*q=aux;
}

/*Sequence d'instruction 2 :
 * 
 * printf1 : i = 4	j = 10		*p = 4	*q =  10
 * printf2 : i = 14	j = 10		*p = 14	*q = 10 
 * printf3 : i = 14	j = 10		*p = 10	*q = 10
 * printf4 : i = 14	j = 20		*p = 20	*q = 20
 * printf5 : i = 14	j = 20		*p = 20	*q = 14 
 * printf6 : i = 4	j = 20		*p = 20	*q = 4
 * printf7 : i = 5	j = 20		*p = 20	*q = 5
 * 
*/

int main(){
	
	int p1=5,p2=19;
	
	printf("\np1 = %d et p2 = %d",p1,p2);
	incremente_et_decremente(&p1,&p2);
	printf("\np1 = %d et p2 = %d",p1,p2);
	
	swap(&p1,&p2);
	printf("\np1 = %d et p2 = %d",p1,p2);
	
	return 0;
}

