#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void merge(int *arr,int *temp,int lpos,int rpos,int rightend){
    int leftend,temppos;
    leftend=rpos-1;
    temppos=lpos;
    int nelement=rightend-lpos+1;
    while(lpos<=leftend && rpos<=rightend){
        if(arr[lpos]<=arr[rpos]){
            temp[temppos++]=arr[lpos++];
        }
        else{
            temp[temppos++]=arr[rpos++];
        }
    }
    while(lpos<=leftend){
        temp[temppos++]=arr[lpos++];
    }
    while(rpos<=rightend){
        temp[temppos++]=arr[rpos++];
    }
    for(int i=0; i<nelement; i++){
        arr[rightend]=temp[rightend];
        rightend--;
    }
 }
void mergesort(int *arr,int *temp,int left,int right){
    int mid;
    if(left<right){
        mid=(left+right)/2;
        mergesort(arr,temp,left,mid);
        mergesort(arr,temp,mid+1,right);
        merge(arr,temp,left,mid+1,right);
    }
}
void bublesort(int *arr,int n){
    int i,j,temp;
    for(i=0; i<n; i++){
        for(j=i; j<n; j++){
            if(arr[i]<arr[j]){
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
}
int main(){
    double itime,ftime;
    int n=200000;
    int arr[n];
    int temp[n];
    for(int j=0; j<n; j++){
        arr[j]=rand();
    }
    //bublesort(arr,n);
    itime=(double)clock();
    mergesort(arr,temp,0,n-1);
    for(int i=0; i<n; i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");
    ftime=(double)clock();
    printf("Time takes to sort this array: %lf seconds.\n",(double)((ftime-itime)/CLOCKS_PER_SEC));
    return 0;
}