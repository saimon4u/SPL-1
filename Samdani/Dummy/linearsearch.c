#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void linear_search(int arr[],int start,int end,int key){

    for ( start; start < end; start++) {
        if(arr[start]==key) {
            printf("Found\n");
            break;
        }
    }
    if(start==end) printf("Not found\n");
}

int main()
{


    long long size,key;
//    scanf("%d",&size);
//    int arr[size];
//    for(int i=0;i<size;i++) scanf("%d",&arr[i]);
//    scanf("%d",&key);

    int n=100000;
    int arr[n];
    for(int i=0;i<n;i++) arr[i]=rand();

    for(int i=0;i<n;i++) printf("%d ",arr[i]);
    printf("\n");

    //scanf("%d",&key);
    key=arr[(n/2)-1];

    clock_t start_time, end_time;
    double execution_time;
   // start_time=(double)clock();

    linear_search(arr,0,n,key);


    end_time = clock();

    execution_time = (((double)(end_time - start_time))/ CLOCKS_PER_SEC) ;

    printf("Execution time: %f ms\n", (1000.0*execution_time));


    return 0;
}

