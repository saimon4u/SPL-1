#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int partition(int *arr, int start, int end);
void swap(int *a, int *b);
void quicksort(int *arr, int start, int end);
void sort(int *arr,int size);
int main(){
    double start,end;
    srand((int)time(0));
    int n=10000,i,arr[n];
    for(i=0; i<n; i++){
        arr[i]=rand()%100;
    }
    //sort(arr,n);
    start=(double)clock();
    quicksort(arr,0,n-1);
    for(i=0; i<n; i++){
        printf("%d  ",arr[i]);
    }
    end=(double)clock();
    printf("\nTime takes to sort this array: %lf mili seconds.",(double)1000*((end-start)/CLOCKS_PER_SEC));
    return 0;
}
void sort(int *arr, int size){
    int temp,i,j;
    for(i=0; i<size; i++){
        for(j=i; j<size; j++){
            if(arr[i]<arr[j]){
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
}
void quicksort(int *arr, int start, int end){
    int set;
    if(start<end){
        set=partition(arr,start,end);
        quicksort(arr,start,set-1);
        quicksort(arr,set+1,end);
    }
}
int partition(int *arr, int start, int end){
    int i=start, j=start-1,pivot=arr[end];
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