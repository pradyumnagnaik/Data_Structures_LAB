// Time program: to read , to display, to update time, to add two times.
#include<stdio.h>
#include<stdlib.h>
struct Time
{
  int hr;
  int min;
  int sec;
};

typedef struct Time time;
void read(time *);
void display(time *);
void update(time *);
void add(time *,time *);
void main()
{
  time *t;
  time *t1;
  time *t2;
  int choice;
  
  for(;;)
  { 
   printf("1:Read\n2:Display\n3:Update\n4:Add\n");
   printf("Enter choice\n");
   scanf("%d",&choice);  
   switch(choice)
   {
    case 1: read(t); 
            break;
    case 2: display(t); 
            break;
    case 3: update(t); 
            display(t);
            break;
    case 4: read(t1);
            read(t2);
            add(t1,t2);
            break;      
    default:exit(0);
            break;
   }
  }
}

void read(time *t)
{
  printf("Enter the time in hrs:mins:secs\n");
  scanf("%d %d %d",&t->hr,&t->min,&t->sec);  
}

void display(time *t)
{
 printf("The time in hrs:mins:secs\n");
 printf("   %d:%d:%d\n",t->hr,t->min,t->sec);
} 

void update(time *t)
{
  t->sec++;
  if((t->sec)==60)
  {
    t->sec=0;
    t->min++;
  }
  if(t->min==60)
  {
    t->min=0;
    t->hr++;
  }
  if(t->hr==24)
  {
    t->sec=0;
    t->min=0;
    t->hr=0;
  }   
}

void add(time *t1,time *t2)
{  
  time t3;
  t3.sec=(t1->sec+t2->sec);
  t3.min=t1->min+t2->min;
  t3.hr=t1->hr+t2->hr; 
  if(t3.sec>=60)
  {
    t3.sec%=60;
    ++t3.min;
    if(t3.min>=60)
    {
      t3.min%=60;
      ++t3.hr;
      if(t3.hr>=24)
      {
       t3.hr%=24;
      } 
    }
  }
  printf("The added time in hrs:mins:secs\n");
  printf("  %d:%d:%d\n",t3.hr,t3.min,t3.sec);
}
