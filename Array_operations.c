#include<stdio.h>
#include<stdlib.h>
#define size 10

void Read(int *);
void Disp(int *);
int Search(int *,int);
void Sort(int *);
void insertbypos(int *);
void deletebypos(int*);
void insertbyorder(int *);
void deletebyele(int *);
int N;

void main()
{
  int A[10],pos,choice,key;
   
    for(;;)
    {
       printf("\n\nEnter Choice\n1:Read\n2:Display\n3:Search\n4:Sort\n5:Insert by position\n6:Delete by position\n7:Insert by order\n8:Delete by element\n9:Stop the program\n");
       scanf("%d",&choice);   
       switch(choice)
       {
             case 1: Read(A);  break;         
             case 2: Disp(A);  break;         
             case 3: printf("Enter Search element\n");
                     scanf("%d",&key);                 
                     pos=Search(A,key);                  
                     if(pos==-1)
                     printf("%d not found\n",key);
                     else
                     printf("%d is found in position %d\n",key,pos);
                     break;                     
             case 4: Sort(A);
                     printf("Sorted Array\n");
                     Disp(A);
                     break;             
             case 5: insertbypos(A);
                     break;                      
             case 6: deletebypos(A);
                     break;                                                           
             case 7: insertbyorder(A);
                     break;                      
             case 8: deletebyele(A);
                     break;                                                    
             case 9: printf("Program terminated\n");
                     exit(0);
                     break;
             
             default: printf("Invalid number");        
      }
    }
}

void Read(int *p)
{
    int i;    
    printf("Enter the number of elements\n");
    scanf("%d",&N);
    if(N>0)
     {
       printf("Enter the array elements\n");
       for(i=0;i<N;i++)
       scanf("%d",(p+i));
     } 
    else
      printf("Enter number greater than zero\n");   
}                      

void Disp(int *p)
 {
    int i;
    
     if(N==0)
     {
         printf("Array is empty\n");
         return;
     }         
    printf("The array elements are: ");    
    for(i=0;i<N;i++)
    printf("%d ",*(p+i));
    printf("\n");
    
 }
  
int Search(int *p,int key) 
  {  
     int i;     
     for(i=0;i<N;i++)
     {
       if(*(p+i)==key)
          return i+1;
     } 
       return -1;
   }          
 void Sort(int *p)
    {
      int i,j,temp;      
       for(i=0;i<N-1;i++)
       {
         for(j=0;j<N-i-1;j++)
          {
             if(*(p+j) > *(p+j+1))
             {
                temp=*(p+j);
                (p+j)=(p+j+1);
                *(p+j+1)=temp;
             }
          }
      }    
    }   
                  
void insertbypos(int *p)
 {
   int i,pos,key;
   
   if(N==size)
     {
        printf("Array overflow\n");
        return;
     }        
   printf("Enter valid position\n");
   scanf("%d",&pos);
   
   if(pos>0&&pos<=N+1)
   {
     printf("Enter the element to be inserted\n");
     scanf("%d",&key);     
     for(i=N-1;i>=pos-1;i--)
     {
       (p+i+1)=(p+i);
     }     
    *(p+i+1)=key;    
    N++;   
   }    
   else printf("Invalid position\n");        
 }  
      
void deletebyele(int *p)
{
  int i,ele,pos;
 
  if(N==0)
     {
         printf("Array is empty\n");
         return;
     }     
      printf("Enter the element to be deleted\n");
      scanf("%d",&ele);      
      pos=Search(p,ele);      
      if(pos==-1)
         {
            printf("%d not exist\n",ele);
            return;
         } 
      for(i=pos-1;i<=N-2;i++)
        {
          *(p+i)= *(p+i+1);
        }
          
      printf("%d is deleted at position %d \n",ele,pos);      
      N--;
 }         
         
 void deletebypos(int*p)
 {
   int i,pos,temp;
   
    if(N==0)
     {
         printf("Array is empty\n");
         return;
     }
           
   printf("Enter valid position\n");
   scanf("%d",&pos);
   
   if(pos>0&&pos<N+1)
   {
     printf("Deleted element is %d\n",*(p+pos-1));
     //if(N==1||pos==N){ N--; return;)
     for(i=pos-1;i<=N-2;i++)
     {
       (p+i)=(p+i+1);
     }  
    N--;  
   } 
   
   else printf("Invalid position\n");
 }       
                  
void insertbyorder(int *p)
{
  int i,ele;
                  
  if(N==size)
     {
        printf("Array overflow");
        return;
     }         
  printf("Enter the element to be inserted\n");
  scanf("%d",&ele);  
  for(i=N-1; i>=0 && *(p+i)>ele; i--)
    {
      (p+i+1)=(p+i);
    }    
    *(p+i+1)=ele;    
    N++;
}
