//O(nlogn)

#include<stdio.h>

void merge(int a[],int low,int mid,int high){
     int i,j,k;
     int b[low+high+1];
     i=low;
     j=mid+1;
     k=low;
     while(i<=mid && j<=high){
        if(a[i]<=a[j]){
            b[k]=a[i];
            i++;
            k++;
        }
        else{
            b[k]=a[j];
            j++;
            k++;
        }
     }
     while(i<=mid){
        b[k]=a[i];
        i++;
        k++;
     }
     while(j<=high){
        b[k]=a[j];
        j++;
        k++;
     }
    for(i=low;i<=high;i++){
       a[i]=b[i];
    }
}

void merge_sort(int a[],int low,int high){

    if(low<high){

        int mid=(low+high)/2;
        merge_sort(a,low,mid);
        merge_sort(a,mid+1,high);
        merge(a,low,mid,high);
    }

}


int main(){
    int n,i;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++){
       scanf("%d",&a[i]);
    }
    merge_sort(a,0,n-1);

    for(i=0;i<n;i++){
       printf("%d ",a[i]);
    }

}
