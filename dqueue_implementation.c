Implementation of Dynamic Dqueue
#include<stdio.h>
#include<stdlib.h>

struct Queue
{
  int *items;
  int F,R,size;
};
typedef struct Queue Que;

void InsertFront(Que* Q)
{
  int item;
  if(Q->R==Q->size-1)
  {
    printf("Queue is Overflow\n");
    return;
  }
  
  printf("Enter an item\n");
  scanf("%d",&item);
 
 if(Q->F==0 && Q->R==-1) 
 {
   Q->R++;
   Q->items[Q->R]=item;
  
 }  
 else if(Q->F!=0)
   Q->items[--Q->F]=item;
 else
   printf("Front Insertion is not possible\n");
}

void InsertRear(Que *Q)
{
   int item;
  if(Q->R==Q->size-1)
  {
    printf("Queue is Overflow\n");
    return;
  }  
  printf("Enter an item\n");
  scanf("%d",&item);
 Q->items[++Q->R]=item;
}


void DeleteFront(Que *Q)
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

void DeleteRear(Que *Q)
{  
  if(Q->F>Q->R)
  {
    printf("Queue is Underflow\n");
    return;
  }
  printf("Deleted: %d\n",Q->items[Q->R--]);
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
  printf("Status of the Queue\n");
  printf("-------------------\n");  
  for(i=Q.F;i<=Q.R;i++)
  {
    printf("%d->",Q.items[Q.F++]);
  }
printf("\n");
}     
void main()
{
  int ch;
  Que Q;
  system("clear");
  printf("Enter Queue size\n");
  scanf("%d",&Q.size);
  Q.F=0;
  Q.R=-1;
  Q.items=(int*)malloc(Q.size*sizeof(int));
  for(;;)
  {
    printf("Implementation of D Queue\n");
    printf("-------------------------\n");
    printf("1.Insert Rear\n");
    printf("2.Insert Front\n");
    printf("3.Delete Rear\n");
    printf("4.Delete Front\n");
    printf("5.Display\n");
    printf("6.Stop the program\n");
    printf("Enter choice\n");
    scanf("%d",&ch);
    
    switch(ch)
    {
      case 1: InsertRear(&Q); Display(Q);  break;
      case 2: InsertFront(&Q); Display(Q);  break;
      case 3: DeleteRear(&Q); Display(Q);  break;
      case 4: DeleteFront(&Q); Display(Q);  break;
      case 5: Display(Q);  break;
      default: exit(0);
    }
  }
}
