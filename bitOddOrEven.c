#include<stdio.h>
#include<conio.h>
#define printf(f_, ...); printf((f_), ##__VA_ARGS__); fflush(stdout);

int main(){
	int n;
	printf("Enter an integer: ");
	scanf("%d", &n);
	if(n&1){
		printf("%d is odd.", n);
	}
	else{
		printf("%d is even.", n);
	}
	return 0;
}