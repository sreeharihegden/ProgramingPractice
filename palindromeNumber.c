#include<stdio.h>
#define printf(f_, ...); printf((f_), ##__VA_ARGS__); fflush(stdout);

int main(){
	int n1, copyn1, currentDigit, reversedNum;
	printf("Enter a number: ");
	scanf("%d", &n1);
	copyn1 = n1;
	while(copyn1!=0){
		currentDigit = copyn1%10;
		reversedNum = (reversedNum * 10) + currentDigit;
		copyn1 = copyn1/10;
	}
	printf("Reversed number is %d.", reversedNum);
	if(n1 == reversedNum){
		printf("%d is palindrome.", n1);
	}
	else{
		printf("Not a palindrome.");
	}
	
	return 0;
}