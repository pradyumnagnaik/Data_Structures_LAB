//Evaluation of Postfix expression(Input Postfix expression)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

struct stk
{
  float item[20];
  int top;
};
typedef struct stk  STK;

void Evaluate(char[]);
float Compute(float, float, char);

void push(float c, STK *s)
{
  if(s->top ==19)
   printf("stack full\n");
  else
 s->top++;
 s->item[s->top] = c;
}

float  pop(STK *s)
 {
   float c;
   if(s->top == -1)
     printf("stack empty\n");
  else
   c = s->item[s->top];
   s->top--;
 return c;      // return s->item[s->top--]
}

int isoperand(char c)
{
   switch(c)
{
  case '+':
  case '-':
  case '*':
  case '/':
  case '(':
  case ')':
  case '$':
  case '^': return 0;
  default : return 1;
}
}

void Evaluate(char  po[])
{
  STK s;
  char c;
  float op1, op2, res;
  int i=0;
  s.top = -1;
  while((c =po[i++]) !='\0') // SCAN  EXPRESSION
  {
    if(isoperand(c))
      push(c -'0', &s); //  item = c - '0' push(item, &s)

    else
     {
      op2=pop(&s);
      op1=pop(&s);
      res = Compute(op1, op2, c);
      push(res,&s);

     }

  }
res = pop(&s);
if(s.top != -1)
  printf("Invalid expression\n");
else
  printf("Value of the expression is:%f\n",res);
} // END Evaluate

float Compute(float op1, float op2, char opr)
{
  switch(opr)
  {
     case '+': return(op1+op2);
     case '-' : return(op1-op2);
     case '*' : return(op1*op2);
     case '/' : return(op1/op2);
     case '^' : return pow(op1,op2);
     case '$' : return pow(op1,op2);
     default: printf("invalid expression");
  }
}

void main()
{
 char pos[30];
 system("clear");
 for(;;)
 {
  printf("enter exp and 0 to stop execution\n");
  scanf("%s", pos);
  if(strcmp(pos,"0")==0)  break;
  Evaluate(pos); 
  }
}
