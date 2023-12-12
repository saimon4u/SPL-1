#include<stdio.h>

int main(int argc,char *argv[])
{

    int arr[]={6,3,9,2,5,8};
    int min,temp,idx;
    for(int i=0;i<6;i++){
        min=i;
        for(int j=i+1;j<6;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
    }

    for(int i=0;i<6;i++){
        printf("%d ",arr[i]);
    }

    return 0;
}
