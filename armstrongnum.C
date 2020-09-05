#include "stdio.h"
#include "conio.h"

int main(void)
{
  int num, r, sum = 0, temp;

  printf("Enter a number: \n");
  scanf("%d", &num);

  temp = num;
  while(temp>0)
  {
    r = temp%10;
    sum = sum + (r*r*r);
    temp = temp/10;
  }
  
  if(sum == num)
    printf("%d is Armstrong Number", num);
  else
    printf("%d is not Armstrong Number", num);

  getch();	
  return 0;
}