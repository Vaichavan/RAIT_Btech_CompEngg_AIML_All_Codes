#include<stdio.h>
char stk[20];
int top = -1;

int ischar(char c)
{return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

void push(char x)
{stk[++top] = x;
}

char pop()
{if (top == -1)
  return -1;
 else
  return stk[top--];
}

int pri(char x)
{if (x == '(')
  return 0;
 if (x == '+' || x == '-')
  return 1;
 if (x == '*' || x == '/')
  return 2;
 if (x == '^')
  return 3;
  return 0;
}

int main()
{char exp[20];
 char *p, x;
 printf("\nEnter the equation: ");
 scanf("%s", exp);
 printf("\n");
 p = exp;

 while (*p != '\0')
 {if (ischar(*p))
   printf("%c ", *p);
  else if (*p == '(')
   push(*p);
  else if (*p == ')')
  {while ((x = pop()) != '(')
   printf("%c ", x);
  }
  else
  {while (pri(stk[top]) >= pri(*p))
   printf("%c ", pop());
   push(*p);
  }
  p++;
 }

 while (top != -1)
 {printf("%c ", pop());
 }
 return 0;
}
