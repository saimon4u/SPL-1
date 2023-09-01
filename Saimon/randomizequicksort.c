#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int partition(int *arr, int start, int end,int size);
void swap(int *a, int *b);
void quicksort(int *arr, int start, int end,int size);
int main(){
    double start,end;
    srand((int)time(0));
    int n=100,i,arr[n];
    for(i=0; i<n; i++){
        arr[i]=rand()%100;
    }
    start=(double)clock();
    quicksort(arr,0,n-1,n);
    for(i=0; i<n; i++){
        printf("%d  ",arr[i]);
    }
    end=(double)clock();
    printf("\nTime takes to sort this array: %lf mili seconds.",(double)1000*((end-start)/CLOCKS_PER_SEC));
    return 0;
}
void quicksort(int *arr, int start, int end,int size){
    int set;
    if(start<end){
        set=partition(arr,start,end,size);
        quicksort(arr,start,set-1,size);
        quicksort(arr,set+1,end,size);
    }
}
int partition(int *arr, int start, int end,int size){
    int i=start, j=start-1,pivot;
    pivot=arr[rand()%size];
    swap(&pivot,&arr[end]);
    pivot=arr[end];
    for(; i<end; i++){
        if(arr[i]<=pivot){
            j++;
            swap(&arr[j],&arr[i]);
        }
    }
    swap(&arr[j+1],&arr[end]);
    return j+1;
}
void swap(int *a, int *b){
    int temp;
    temp=*b;
    *b=*a;
    *a=temp;
}