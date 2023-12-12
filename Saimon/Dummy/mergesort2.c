#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void merge(int *arr,int left,int mid,int right){
    int size1,size2;
    size1=mid-left+1;
    size2=right-mid;
    int lef[size1],righ[size2],i,j,k;
    for(i=0; i<=size1; i++){
        lef[i]=arr[left+i-1];
    }
    for(i=0; i<=size2; i++){
        righ[i]=arr[mid+i];
    }
    lef[size1+1]=__INT_MAX__;
    righ[size2+1]=__INT_MAX__;
    i=1,j=1;
    for(k=left; k<=right; k++){
        if(lef[i]<=righ[j]){
            arr[k]=lef[i];
            i++;
        }
        else{
            arr[k]=righ[j];
            j++;
        }
    }
 }
void mergesort(int *arr,int left,int right){
    int mid;
    if(left<right){
        mid=(left+right)/2;
        mergesort(arr,left,mid);
        mergesort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
}
int main(){
    double itime,ftime;
    itime=(double)clock();
    int n=10000;
    int arr[n];
    for(int i=0; i<n; i++){
        arr[i]=rand()%50000;
    }
    mergesort(arr,0,n-1);
    for(int i=0; i<n; i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");
    ftime=(double)clock();
    printf("Time taken to sort this: %lf seconds.\n",(double)((ftime-itime)/CLOCKS_PER_SEC));
    return 0;
}