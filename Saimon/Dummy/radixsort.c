#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void radix(int *arr, int size, int position);
int main(){
    double start,end;
    srand((int)time(0));
    int n=100000,i,j,max=0;
    int arr[n];
    start=(double)clock();
    for(i=0; i<n; i++){
        arr[i]=rand()%1000;
        if(arr[i]>max){
            max=arr[i];
        }
    }
    for(i=1; max/i>0; i*=10){
        radix(arr,n,i);
    }
    for(i=0; i<n; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    end = (double)clock();
    printf("Time takes to sort: %lf mili seconds.\n",(double)1000*((end-start)/CLOCKS_PER_SEC));
    return 0;
}
void radix(int *arr, int size, int position ){
    int result[size],count[10]={0},i,j;
    for(i=0; i<size; i++){
        count[(arr[i]/position)%10]++;
    }
    for(i=1; i<10; i++){
        count[i]+=count[i-1];
    }
    for(i=size-1; i>=0; i--){
        result[count[(arr[i]/position)%10]-1]=arr[i];
        count[(arr[i]/position)%10]--;
    }
    for(i=0; i<size; i++){
        arr[i]=result[i];
    }
}