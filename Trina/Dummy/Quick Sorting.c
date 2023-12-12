//worst=n^2,best/average=nlogn

#include<stdio.h>

int partition(int a[],int low,int high){

    int pivot=a[low],temp;
    int start=low,end=high;
    while(start<end){
        while(a[start]<=pivot){
            start++;
        }
        while(a[end]>pivot){
            end--;
        }
        if(start<end){

            temp=a[start];
            a[start]=a[end];
            a[end]=temp;
        }
    }
            temp=a[low];
            a[low]=a[end];
            a[end]=temp;

    return end;

}

void quick_sort(int a[],int low,int high,int n){

     if(low<high){

     int pivot_index=partition(a,low,high);

     quick_sort(a,low,pivot_index-1,n);
     quick_sort(a,pivot_index+1,high,n);

     }

}



int main(){
    int n;
    scanf("%d",&n);
    int a[n],i;
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    quick_sort(a,0,n-1,n);

    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
     }

}
