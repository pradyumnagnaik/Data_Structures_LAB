//Implementation of Circular Queue using dynamic
#include<stdio.h>
#include<stdlib.h>

struct Queue
{
  int* items;
  int F,R,size,count;
};
typedef struct Queue Que;


void Enqueue(Que *Q)
{
  int item;
  if(Q->count==Q->size)
  {
    printf("Queue is Overflow\n");
    return;
  }
  
  printf("Enter an item\n");
  scanf("%d",&item);
  Q->R=(Q->R+1)%Q->size;
  Q->items[Q->R]=item;
  Q->count++;
}


void Dequeue(Que *Q)
{
  if(Q->count==0)
  {
    printf("Queue is Underflow\n");
    return;
  }
  
  printf("Deleted: %d\n",Q->items[Q->F]);
  Q->F=(Q->F+1)%Q->size;
  Q->count--;
}


void Status(Que Q)
{
   int i;
   if(Q.count==0)
  {
    printf("Queue is Empty\n");
    return;
  }
  printf("Status of the Queue\n");
  printf("-------------------\n");  
  for(i=0;i<Q.count;i++)
  {
    printf("%d->",Q.items[Q.F]);
    Q.F=(Q.F+1)%Q.size;
  }
printf("\n");
}
   
void main()
{
  int ch;
  Que Q;
  printf("Enter Queue size\n");
  scanf("%d",&Q.size);
  Q.F=0;
  Q.R=Q.size-1;
  Q.items=(int *)malloc(Q.size*sizeof(int));
  Q.count=0;
  system("clear");
  for(;;)
  {
    printf("Implementation of Circular Queue\n");
    printf("--------------------------------\n");
    printf("1.Insert \n");
    printf("2.Delete \n");
    printf("3.Display\n");
    printf("4.Stop the program\n");
    printf("Enter choice\n");
    scanf("%d",&ch);
    
    switch(ch)
    {
      case 1: Enqueue(&Q); Status(Q); break;
      case 2: Dequeue(&Q); Status(Q); break;
      case 3: Status(Q);  break;
      default: exit(0);
    }
  }
}
