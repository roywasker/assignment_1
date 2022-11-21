#include <stdio.h>
#include "NumClass.h"
#include <math.h>

int isPalindrome(int num){
    int x=0;
    int savenumval=num;
    while (savenumval!=0) // calulating the reverse of num 
    {
        x+=(savenumval%10);
        x*=10;
       savenumval/=10;
    }
    x/=10;
    if (x==num) // if num equal to reverse num return true
    {
        return 1;
    }
    return 0;
}

int isArmstrong(int num){
    int numofdig=log10(num)+1;
    int sumofmult=0;
    int savenumval=num;
    for (int i = 0; i < numofdig; i++) // go over all the digit 
    {
       sumofmult+=pow((savenumval%10),numofdig); // sum all the pow of the digit
       savenumval/=10;
    }
    if (sumofmult==num) // if sum all digit pow equal to num return true
    {
        return 1;
    }
    return 0;
}
