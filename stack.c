#include "stdio.h"
#include "stdlib.h"
#include "limits.h" // For INT_MIN, see https://codeforwin.org/2018/08/stack-implementation-using-linked-list-push-pop.html

//#include "curses.h" // For clrscr, in c <conio.h>. clrscr now not used.

#define CAPACITY 3 // Only 3 nodes;

struct node{
  int data;
  struct node * next;
}*top;

int size=0;

void push(struct node **top, int data);
int pop(struct node **top);
int seeTop(struct node *top);

int isEmptyStack(struct node *top);
void disp(struct node *top);
void del(struct node **top);

int main(void){

  int choice;
  int data;

  while(1){
      printf("STACK IMPLEMENTATION\n");
      printf("====================\n");

      printf("Enter your choice:\n");
      printf("1. PUSH\n");
      printf("2. POP\n");
      printf("3. TOP\n");
      printf("4. SIZE\n");
      printf("5. DISP\n");
      printf("6. DELETE STACK\n");
      printf("7. CLEAR SCREEN\n");
      printf("8. EXIT\n");

      scanf("%d", &choice);

      switch(choice){
        case 1:
          printf("Enter number to push:\n");
          scanf("%d", &data);
          push(&top,data);
          break;

        case 2:
          data = pop(&top);
          if (data!=INT_MIN)
            printf("Data poped: %d.\n", data);
          break;

        case 3:
          data = seeTop(top);
          if (data!=INT_MIN)
            printf("Data on top: %d.\n", data);
          break;

        case 4:
          printf("Stack size: %d.\n", size);
          break;

        case 5:
          printf("Stack elements:\n");
          disp(top);
          break;

        case 6:
          del(&top);
          break;

        case 7:
          system("clear");
          break;

        case 8:
          printf("Exiting application...\n");
          exit(0); // exit is system call, so not reserved keyword, also break not needed.
          // break;

        default:
          printf("Invalid choice, try again.\n");
          // break; is not needed for default.
      }
  }
  return 0;
}

void push(struct node **top, int data){
  // Check stack overflow
  if (size >= CAPACITY)
  {
      printf("Stack Overflow, can't add more element to stack.\n");
      return;
  }

  struct node * temp = malloc(sizeof(struct node));
  if(!temp){
    printf("Memory error on creating node.\n");
    return;
  }
  temp->data=data;
  temp->next = *top;
  *top=temp;
  size=size+1;
  return;
}

int isEmptyStack(struct node *top){
  return (top==NULL || size==0);
}

int pop(struct node **top){
  if(isEmptyStack(*top)){
    return INT_MIN;
  }
  
  struct node *temp = *top;
  *top = temp->next;
  int dt = temp->data;
  free(temp);
  size--;
  return dt;
}

int seeTop(struct node *top){
  if(isEmptyStack(top)){
    return INT_MIN;
  }
  return top->data;
}

void disp(struct node *top){
  if(isEmptyStack(top)){
    printf("Empty stack.\n");
  }
  else{
    struct node * temp = top;
    while(temp!=NULL){
      printf("%d->", temp->data);
      temp=temp->next;
    }
    printf("\n");
  }
  return;
}

void del(struct node **top){
  struct node * temp, *p;
  if(isEmptyStack(*top)){
    printf("Empty stack.\n");
    return;
  }
  p=*top;
  while(p->next){
      temp=p->next;
      p->next=temp->next;
      free(temp);
    }
  free(p);
  size=0;
  return;
}

