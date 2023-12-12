#include<stdio.h>

int main(){
    int arr[21];
    int i,j;
    for(i=0;i<21;i++) arr[i]=1;
    for(i=1;i<21/2;i++)
    {
        for(j=2;j<=i/2;j++)
        {
            arr[i*j]=0;
        }
    }
    for(i=0;i<21;i++)
    {
        if(arr[i]) printf("%d\n",i);
    }
    return 0;
}