#include <stdio.h>
#include "NumClass.h"
#include <math.h>

int isPalindrome(int num){
    int x=0;
    int savenumval=num;
    while (savenumval!=0)
    {
        x+=(savenumval%10);
        x*=10;
       savenumval/=10;
    }
    x/=10;
    if (x==num)
    {
        return 1;
    }
    return 0;
}

int isArmstrong(int num){
    int numofdig=log10(num)+1;
    int sumofmult=0;
    int savenumval=num;
    for (int i = 0; i < numofdig; i++)
    {
       sumofmult+=pow((savenumval%10),numofdig);
       savenumval/=10;
    }
    if (sumofmult==num)
    {
        return 1;
    }
    return 0;
}
