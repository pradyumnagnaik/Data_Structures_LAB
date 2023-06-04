//Student operations:(to compute avg of three tests)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 10

struct student
{
  int regno;
  float marks[3];
  char name[10];
  float avg;
};

typedef struct student STD;

void Read(STD *);
void Disp(STD *);
void computeavg(STD *);
int N;

void main()
{
  STD s[size];
  int pos,choice;
  
  system("clear");
  
  for(;;)
  {
    printf("Enter choice\n1:READ\n2:Average of best two marks\n3:DISPLAY\n");
    scanf("%d",&choice);
    
    switch(choice)
    {
      case 1: Read(s);
              break;
      case 2: computeavg(s);             
              break;        
      case 3: Disp(s);
              break;
     
      default: exit(0);
    }
  }
}


void Read(STD *ps)
{
  int i,j;
   
   printf("Enter the number of students\n");
   scanf("%d",&N);
   
   printf("Enter %d student information\n",N);
     for(i=0;i<N;i++)
      {
        printf("\nEnter Regno of student%d: ",i+1);
        scanf("%d",&(ps+i)->regno);
        printf("Enter Name of student%d: ",i+1);
        scanf("%s",(ps+i)->name);
     //   printf("Enter marks of 3 subjects of student%d: \n",i+1);
         for(j=0;j<3;j++)
         {
           printf("Enter subject%d marks: ",j+1);
           scanf("%f",&(ps+i)->marks[j]);
         }
      }
}


void Disp(STD *ps)
{
   int i,k;
    
   if(N==0)
   {
     printf("Student Array is empty\n");
     return;
   }
   
   printf("Student details are as follows: \n");
   printf("Register_no\tName\tMarks1\tMarks2\tMarks3\tAverage\n");
   printf("---------------------------------------------------\n");
      
      for(i=0;i<N;i++)
      {
        printf("%d\t",(ps+i)->regno);
        printf("%s\t",(ps+i)->name);        
        for(k=0;k<3;k++)        
          printf("%.2f\t",(ps+i)->marks[k]);
        printf("%f\t\n",(ps+i)->avg);
      }
      printf("\n");
 }
 
 void computeavg(STD *ps)         
 {
   int i,k;
   float sum,min;
   
   for(i=0;i<N;i++)
   {
    sum=0;
     for(k=0;k<3;k++)     
       sum+=(ps+i)->marks[k];
     min=(ps+i)->marks[0];
     
     for(k=1;k<3;k++)
     {
       if((ps+i)->marks[k]<min) 
         min=(ps+i)->marks[i];
     }
     (ps+i)->avg=(sum-min)/2.0;
   }
 }
