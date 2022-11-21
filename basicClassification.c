#include <stdio.h>
#include "NumClass.h"

int isPrime(int num){
    for (int i = 2; i < num; i++) //go over all the number beween 2 to num-1
    {
        if (num%i==0){ // if one number divide num return false
        return 0;
        }
    }
    return 1;
}
/*
calulating factorial of number
*/
int Factorial(int num){
    int result=1;
    for (int i = 1; i <=num; i++) // go over all the number beween 1 to num
    {
        result*=i;
    }
    return result;
}

int isStrong(int num){
    int temp=num,sum=0;
    while (temp>0) // sum all the factorial of num digit
    {
        sum+=Factorial(temp%10); 
        temp/=10;
    }
    if (num==sum) // if all the sum of factorial equal to num return ture
    {
       return 1;
    }
    return 0;
}