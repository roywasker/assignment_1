#include <stdio.h>
#include "NumClass.h"


int main(){
    int num1,num2;
    printf("enter number 1: ");
    scanf("%d",&num1);
    printf("enter number 2: ");
    scanf("%d",&num2);
    if (num1>num2)
    {
       int temp =num1;
       num1=num2;
       num2=temp;
    }
    printf("The Prime numbers are:");
    for (int i = num1; i <=num2; i++)
    {
        if (isPrime(i)==1)
        {
            printf("%d ",i);
        }
    }
    printf("\nThe Armstrong numbers are:");
    for (int i = num1; i <=num2; i++)
    {
        if (isArmstrong(i)==1)
        {
            printf("%d ",i);
        }
    }
    printf("\nThe Strong numbers are:");
    for (int i = num1; i <=num2; i++)
    {
       if (isStrong(i)==1)
        {
            printf("%d ",i);
        }
    }
    printf("\nThe Palindromes numbers are:");
    for (int i = num1; i <=num2; i++)
    {
       if (isPalindrome(i)==1)
        {
            printf("%d ",i);
        }
    }
    
    return 0;
}