#include<stdio.h>
#include<conio.h>
#define printf(f_, ...); printf((f_), ##__VA_ARGS__); fflush(stdout);

int main(){
	int n1, n2;
	printf("Enter first integer: ");
	scanf("%d", &n1);
	printf("Enter second integer: ");
	scanf("%d", &n2);
	printf("Sum is %d ", n1+n2);
	return 0;
}