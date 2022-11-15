#include <stdio.h>
#include "NumClass.h"
#include <math.h>


int isPalindrome(int num){
   if(num>=0&&num<=9){
    return 1;
   }else if (num%10==num/10&&num>=11&&num<=99)
   {
    return 1;
   }else{
    int numofdig=(int)log10(num);
    int savefirstdig=num/pow(10,numofdig);
    if (savefirstdig==num%10)
    {
        num=num%(int)pow(10,numofdig);
        return isPalindrome(num/10);
    }
   }
   return 0;
}

int cheackisArmstrong(int num ,int savenum,int numofdig){
    int temp=pow(savenum%10,numofdig);
    if ((num-temp==0)&&(savenum/10==0))
    {
        return 1;
    }else if (num>0)
    {
        num-=pow(savenum%10,numofdig);
        return cheackisArmstrong(num,savenum/10,numofdig);
    }
    return 0;
}

int isArmstrong(int num){
    return cheackisArmstrong(num ,num,log10(num)+1);
}
