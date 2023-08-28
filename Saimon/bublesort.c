#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void swap(int *a, int *b){
        *a = (*a)^(*b);
        *b = (*a)^(*b);
        *a = (*a)^(*b);
}
int main(){
    double initial,final;
    initial=(double)clock();
    int n=10;
    int arr[n],i,j,temp;
    for(i=0; i<n; i++){
        temp=rand()%50;
        arr[i]=temp;
    }
    for(i=0; i<n; i++){
        for(j=i; j<n; j++){
            if(arr[i]>arr[j]){
                swap(&arr[i],&arr[j]);
            }
        }
    }
    for(i=0; i<n; i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");
    final=(double)clock();
    printf("Time takes to sort this: %lf seconds.\n",(double)((final-initial)/CLOCKS_PER_SEC));
}