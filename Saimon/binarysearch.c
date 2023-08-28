#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int search(int *arr, int first, int last, int target);
void sort(int *arr,int size);
int main(){
    srand((int)time(0));
    double start,end;
    int n=100,i,arr[n],target=80,x;
    for(i=0; i<n; i++)
        arr[i]=rand()%100;
    int mid=(0+n-1)/2;
    arr[mid]=100;
    sort(arr,n);
    start=(double)clock();
    x=search(arr,0,n-1,target);
    if(x==-1)
        printf("\nThere was no %d in the array.\n",target);
    else
        printf("\n%d was in the %dth index.\n",target,x);
    end=(double)clock();
    printf("Time needs to find %d is %lf mili seconds.\n",target,(double)1000*((end-start)/CLOCKS_PER_SEC));
    return 0;

}
int search(int *arr, int first, int last, int target){
    if(first<=last){
        int mid=(first+last)/2;
        if(target==arr[mid])
            return mid;
        else if(target<arr[mid])
            return search(arr,first,mid-1,target);
        else
            return search(arr,mid+1,last,target);
    }
    return -1;
}
void sort(int *arr,int size){
    int i,j,temp;
    for(i=0; i<size; i++){
        for(j=i; j<size; j++){
            if(arr[i]>arr[j]){
                temp=arr[j];
                arr[j]=arr[i];
                arr[i]=temp;
            }
        }
    }
}