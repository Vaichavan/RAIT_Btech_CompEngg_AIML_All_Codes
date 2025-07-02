#include<stdio.h>
#include<conio.h>
int choice,size,x,y,z,top;
int stack[100];
void main()
{
clrscr();
top=-1;
printf("Enter Stack Size:\n");
scanf("%d",&size);
printf("\n");
do{
printf("\n");
printf("1 - Push\n");
printf("2 - Pop\n");
printf("3 - Display\n");
printf("4 - Peek\n");
printf("5 - Exit\n");
printf("\n");
printf("Enter Choice:\n");
scanf("%d",&choice);
printf("\n");
switch(choice)
{
case 1:
printf("\n");
if(top==size-1)
{
printf("Stack Overflow");
}
else
{
top++;
printf("Enter Element Of Stack[%d]:",top+1);
scanf("%d",&x);
stack[top]=x;
}
break;
case 2:
printf("\n");
if(top==-1)
{
printf("No Element To Pop");
}
else
{
printf("Removed Element:%d",stack[top]);
top--;
}
break;
case 3:
printf("\n");
printf("Elements In Stack:");
printf("\n");
for(y=0;y<=top;y++)
{
printf("%d\n",stack[y]);
}
break;
case 4:
printf("\n");
if(top==-1)
{
printf("No Element To Peek");
}
else
{
printf("Topmost Element = %d",stack[top]);
}
break;
case 5:
exit(0);
default:
printf("Invaild Choice");
}
}while(choice!=5);
getch();
}