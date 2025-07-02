#include<stdio.h>

#include<conio.h>

void main()

{

   int i, no, A[50];

   void QuickSort(int [],int,int);

   clrscr();

   printf("How many elements are u going to enter?: ");

   scanf("%d",&no);

   for(i=0;i<no;i++)

   {

      scanf("%d",&A[i]);

   }

   QuickSort(A,0,no-1);

   printf("Sorted elements : ");

   for(i=0;i<no;i++)

   {   printf(" %d",A[i]);

   }

   getch();

}

void QuickSort(int A[],int first,int last)

{

   int i, j, pivot, temp;

   if(first<last)

   {

      pivot=first;

      i=first;

      j=last;

     while(i<j)

     {

	 while(A[i]<A[pivot]&&i<last)

	    i++;

	 while(A[j]>=A[pivot]&&j>first)

	    j--;

	 if(i<j)

	{

	    temp=A[i];

	    A[i]=A[j];

	    A[j]=temp;

	}

      }

      temp=A[pivot];

      A[pivot]=A[j];

      A[j]=temp;

      QuickSort(A,first,j-1);

      QuickSort(A,j+1,last);

}

}