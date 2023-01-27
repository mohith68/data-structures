#include<stdio.h>
#include<conio.h>
int main()
{
    int num;
    printf("enter the value:");
    scanf("%d",&num);
    if(num % 2 == 0)
    {
        printf("Even");
    }
    else
    {
        printf("Odd");
    }   
    return 0;
}
