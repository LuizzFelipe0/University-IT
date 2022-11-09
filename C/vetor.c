#include<stdio.h>

#define MAX 10

int main(void)
{
   int a[10];
   
   for (int i=0;i<MAX;i++)
    scanf("%d",&a[i]);
   
   for(int i=MAX-1;i>=0;i--)
     printf("%d ",a[i]); 
   
   return 0;
}