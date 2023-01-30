#include<conio.h>

#include<stdio.h>

void main()

{

int a[200],i,j,k,n;

clrscr();

printf("Enter the size of the element: ");

scanf("%d",&n);

printf("enter the elements: ");

for(i=0;i<n;i++)

{

scanf("%d",&a[i]);

}

for(i=0;i<n;i++)

{

for(j=i+1;j<n;j++)

{

if(a[i]==a[j])

{

for(k=j;k<n-1;k++)

{

a[k]=a[k+1];

}

n--;

j--;

}

}

}

printf("after deleting duplicates: ");

for(i=0;i<n;i++)

{

printf("%d ",a[i]);

}

 getch();

}
