#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void insertion(int *arr,int size);
int main(){
    double start,end;
    srand((int)time(0));
    int n=10,i,arr[n];
    for(i=0; i<n; i++)
        arr[i]=rand()%1000;
    start=(double)clock();
    insertion(arr,n);
    for(i=0; i<n; i++)
        printf("%d ",arr[i]);
    end=(double)clock();
    printf("\nTime takes to sort this: %.2lf mili seconds.",(double)1000*((end-start)/CLOCKS_PER_SEC));
    return 0;
}
void insertion(int *arr, int size){
    int i=1,j,temp;
    for(; i<size; i++){
        j=i-1;
        temp=arr[i];
        while(j>=0 && arr[j]>temp){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
}