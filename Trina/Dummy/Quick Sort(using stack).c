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

void stack_quick(int a,int low,int high){

     int stack[high-low+1];
     int top=-1;
     top++;
     stack[top]=low;
     top++;
     stack[top]=high;

     while(top>=0){
        high=stack[top];
         top--;
        low=stack[top];

    int pivot_index=partition(a,low,high);

        if(low<pivot_index-1){
            top++;
            stack[top]=low;
            top++;
            stack[top]=pivot_index-1;
        }
         if(pivot_index+1<high){
            top++;
            stack[top]=pivot_index+1;
            top++;
            stack[top]=high;
        }

     }

}
int main(){
    int n;
    scanf("%d",&n);
    int a[n],i;
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    stack_quick(a,0,n-1);

    for(i=0;i<n;i++){
        printf("%d ",a[i]);
     }

   return 0;

}
