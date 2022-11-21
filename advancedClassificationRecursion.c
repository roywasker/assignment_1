#include <stdio.h>
#include "NumClass.h"
#include <math.h>

int reversenum(int num);
int cheackisArmstrong(int ,int ,int);

int isPalindrome(int num){
   int result =reversenum(num);
    if (num==result) // if reverse equal to num return true
    {
        return 1;
    }   
    return 0;
}
int reversenum(int num){
    int numofdig=log10(num);
    if (num==0){
        return 0;
    }
    return ((num%10)*(pow(10,numofdig))) +(reversenum(num/10)); // return first digit pow of num of digit  + reversenum without firt digit
}

int isArmstrong(int num){
    return cheackisArmstrong(num ,num,(log10(num)+1));
}

int cheackisArmstrong(int num ,int savenum,int numofdig){
    int temp;
    if (savenum>9) // if savenum have more that 1 digit calulating the pow of first digit with num of digit 
    {
        temp=pow((savenum%10),numofdig); 
    }else{
    temp=pow((savenum),numofdig); // if savenum have 1 digit calulating the pow of that digit with num of digit
    }
    if ((num-temp==0)&&((savenum/10)==0)) // if num equal to temp and we dont have more digit return true 
    {
        return 1;
    }else if ((num>0)&&(savenum>=10)) // if we have more digit and we dont to arrived value of num continue
    {   
        num-=pow((savenum%10),numofdig);
        return cheackisArmstrong(num,savenum/10,numofdig);
    }
    return 0; // if num < 0 we over the value to sum return false
}