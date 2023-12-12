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

void merge_sort(int a[],int n){

     int i,low,high,mid,j;

     for(i=2;i<=n;i=i*2){
        for(j=0;j+i-1<=n;j=j+i){
            low=j;
            high=i+j-1;
            mid=(high+low)/2;
            merge(a,low,mid,high);
        }
     }

     if(i/2<n){
        merge(a,0,i/2-1,n-1);
     }

}

int main(){
    int n,i;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++){
       scanf("%d",&a[i]);
    }
    merge_sort(a,n);

    for(i=0;i<n;i++){
       printf("%d ",a[i]);
    }

}
//6
//8 7 1 0 8 7
