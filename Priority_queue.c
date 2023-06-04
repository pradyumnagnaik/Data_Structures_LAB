//Implementation of Priority Queue using dynamic
#include<stdio.h>
#include<stdlib.h>

struct Queue
{
  int *items;
  int F,R,size;
};
typedef struct Queue Que;

void Insert(Que *Q)
{
  int item,i;
  if(Q->R==Q->size-1)
  {
    printf("Queue is Overflow\n");
    return;
  }
  printf("Enter an item\n");
  scanf("%d",&item);
 
  for(i=Q->R;i>=0 && item<Q->items[i];i--)
  {
    Q->items[i+1]=Q->items[i];  
  }
  Q->items[i+1]=item;
  Q->R++;  
    
}

void Asc_pri(Que *Q)
{
  if(Q->F>Q->R)
  {
    printf("Queue is Underflow\n");
    return;
  }
  printf("Deleted : %d\n",Q->items[Q->F++]);
  
  if(Q->F>Q->R)
  {
    Q->F=0;
    Q->R=-1;
  }  
}

void Dsc_pri(Que *Q)
{
  if(Q->F>Q->R)
  {
    printf("Queue is Underflow\n");
    return;
  }
  printf("Deleted : %d\n",Q->items[Q->R--]);
  
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
  Que Q;
  Q.F=0;
  Q.R=-1;
  system("clear");
  printf("Enter the Queue size\n");
  scanf("%d",&Q.size);
  Q.items=(int *)malloc(sizeof(int));
  int ch;
  for(;;)
  {
    printf("Implementation of Priority Queue\n");
    printf("--------------------------------\n");
    printf("1.Insert\n");
    printf("2.Ascending Priority\n");
    printf("3.Descending Priority\n");
    printf("4.Display\n");
    printf("Enter choice\n");
    scanf("%d",&ch);
     
    switch(ch)
    {
      case 1: Insert(&Q); Display(Q); break;
      case 2: Asc_pri(&Q); Display(Q);  break;
      case 3: Dsc_pri(&Q); Display(Q);  break;
      case 4: Display(Q);  break;
      default: exit(0);
    }
  }
}
