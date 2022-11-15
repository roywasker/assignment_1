#include <stdio.h>
#include "NumClass.h"

int isPrime(int num){
    for (int i = 2; i < num; i++)
    {
        if (num%i==0){
        return 0;
        }
    }
    return 1;
}


int Factorial(int num){
    int result=1;
    for (int i = 1; i <=num; i++)
    {
        result*=i;
    }
    return result;
}


int isStrong(int num){
    int temp=num,sum=0;
    while (temp>0)
    {
        sum+=Factorial(temp%10);
        temp/=10;
    }
    if (num==sum)
    {
       return 1;
    }
    return 0;
}