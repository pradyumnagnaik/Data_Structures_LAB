Implementation of Queue using static
#include<stdio.h>
#include<stdlib.h>
#define size 10
struct Queue
{
  int items[size];
  int F,R;
};
typedef struct Queue Que;

void Enqueue(Que *Q)
{
  int item;
  if(Q->R==size-1)
  {
    printf("Queue is Overflow\n");
    return;
  }
  
  printf("Enter an item\n");
  scanf("%d",&item);
  Q->items[++Q->R]=item;
}

void Dequeue(Que *Q)
{
  if(Q->F>Q->R)
  {
    printf("Queue is Underflow\n");
    return;
  }  
  printf("Deleted: %d\n",Q->items[Q->F]);
  Q->F++;
  if(Q->F>Q->R)
  {
    Q->F=0;
    Q->R=-1;
  }  
}

void Display(Que Q)
{
   int i;
   if(Q.F>Q.R)
   {
    printf("Queue is Empty\n");
    return;
   }
   printf("Status of Queue\n");
   printf("---------------\n");
   for(i=Q.F;i<=Q.R;i++)
   {
    printf("%d->",Q.items[i]);
   }
   printf("\n");
}
   
void main()
{
  int ch;
  Que Q;
  Q.F=0;
  Q.R=-1;
  system("clear");
  for(;;)
  {
    printf("Implementation of Queue\n");
    printf("-----------------------\n");
    printf("1.Insert\n");
    printf("2.Delete\n");
    printf("3.Status\n");
    printf("4.Stop the program\n");
    printf("Enter choice\n");
    scanf("%d",&ch);
    
    switch(ch)
    {
      case 1: Enqueue(&Q); Display(Q);  break;
      case 2: Dequeue(&Q); Display(Q);  break;
      case 3: Display(Q);  break;
      default: exit(0);
    }
  }
}
