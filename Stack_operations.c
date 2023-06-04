 //Implementation of stack using dynamic allocation
#include<stdio.h>
#include<stdlib.h>

struct stack
{
 int *items,top,size;
};

typedef struct stack stk;

void PUSH(stk* s)
{
  int item;
  if(s->top==s->size-1)
  {
    printf("Stack is Overflow\n");
    return;
  }
  printf("Enter the item\n");
  scanf("%d",&item);    
  s->top++;
  s->items[s->top]=item;
}

void  POP(stk *s)
{
  if(s->top==-1)
  {
    printf("Stack is Underflow\n");
    return;
  }
  printf("Deleted : %d\n",s->items[s->top--]);
}  
  
void PEEK(stk s)
{
  if(s.top==-1)
  {
    printf("Stack is Underflow\n");
    return;
  }
  printf("The topmost element is : %d\n",s.items[s.top]);
}

void Status(stk s)
{
  int i;
  if(s.top==-1)
  {
    printf("Stack is Underflow\n");
    return;
  }
  
  printf("Status of the stack\n");
  printf("-------------------\n");
  for(i=s.top;i>=0;i--)
  {
    printf("%d->",s.items[i]);
  }
  printf("\n");  
}    
  

void main()
{
  int ch;
  stk s;
  s.top=-1;
  system("clear");
  printf("Enter stack size\n");
  scanf("%d",&s.size);
  s.items=(int *)malloc(s.size*sizeof(int));
  for(;;)
  {
    printf("Implementation of stack\n");
    printf("-----------------------\n");
    printf("1.PUSH\n");
    printf("2.POP\n");
    printf("3.Status\n");
    printf("4.PEEK\n");
    printf("5.Stop the program\n");
    printf("Enter choice\n");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1: PUSH(&s); Status(s); break;
      case 2: POP(&s); Status(s); break;
      case 3: Status(s); break;
      case 4: PEEK(s); break;      
      default: exit(0);      
    }
  }    
}
