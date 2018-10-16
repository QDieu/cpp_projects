//
// Created by QDieu on 13.06.2018.
//

#include "funcs.h"

bool palindrome(const char *arr)
{
    int len=strlen(arr);
    for (int i=0;i<len/2;i++)
    {
        if (arr[i] != arr[len-i-1]) return false;
    }
    return true;
}

int getMax (const int *arr, int len)
{
    int max=arr[0];
    for (int i=1;i<len;i++)
    {
        if (max<arr[i]) max = arr[i];
    };
    return max;
}
char getMax (const char *arr)
{
    int len=strlen(arr);
    char max = '0';
    for (int i = 0;i<len;i++)
    {
        if(max<arr[i]) max = arr[i];
    }
    return max;
}
void conversion(const char *arr, int *out,int &counter){
    int len=strlen(arr);
    for (int i=0;i<len;i+=2){
        out[counter++] = (arr[i] - '0') * 10 + (arr[i + 1] - '0');
    }
}
bool grow(const int *arr, int len)
{
    if (len > 1){
        int dif = arr[1] - arr[0];
        for(int i = 0 ; i < len - 1 ;i++){
            if (arr[i]!=arr[i+1]-dif) return false;
        }
    }
    return true;
}
bool grow(const char *arr)
{
    int len = strlen(arr);
    char letter = arr[0];
    for (int i = 1; i < len; i++){
        if (arr[i]!=letter+1) return false;
        letter++;
    }
    return true;
}
int getMid(const int *arr, int len)
{
    int sum = 0;
    for (int i=0;i < len; i++)
    {
        sum+=arr[i];
    }
    return sum/len;
}
char getMid(const char *arr)
{
    return arr[(strlen(arr))/2];
}
