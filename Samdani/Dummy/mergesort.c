#include<stdio.h>
#include<stdlib.h>
#include <time.h>

void msort(int list[],int start,int end);
void merge(int list[],int start,int mid,int end );
void bublesort(int *arr,int n);

int main()
{
    //time_t start_time= time(NULL);
    int n=1000;
    //scanf("%d",&n);
    int list[n];
   //int list[20]={20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
//   int list[20]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
 //    int list[20]={20,2,19,3,4,15,11,5,6,10,17,1,8,9,7,13,12,14,18,16};

    //for(int i=0;i<n;i++) scanf("%d",&list[i]);

    for(int i=0;i<n;i++) list[i]=rand();

    //bublesort(list,n);

    double start, end;
    double time_taken;
    start = (double)clock();

    msort(list,0,n-1);


    //time_taken=end-start;

    for(int i=0;i<n;i++) printf("%d ",list[i]);
    printf("\n");
    end = (double)clock();
    time_taken = (double) (end - start) / CLOCKS_PER_SEC;
    printf("\nExecution time : %lf seconds\n", time_taken);

    //time_t end_time= time(NULL);

    //printf("Execution time %f",end_time-start_time);

//     int ticks=clock();
//     printf("Execution time %f",(float)ticks/CLOCKS_PER_SEC);

    return 0;
}

void bublesort(int *arr,int n){
    int i,j,temp;
    for(i=0; i<n; i++){
        for(j=i+1; j<n; j++){
            if(arr[i]>arr[j]){
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
}

void msort(int list[],int start,int end){
    if(start==end) return;
    int mid=start+(end-start)/2;
    msort(list,start,mid);
    msort(list,mid+1,end);
    merge(list,start,mid,end);
}

void merge(int list[],int start,int mid,int end ) {
    int size = end - start + 1;
    int templist[size];
    int idx1 = start, idx2 = mid + 1;
    int k = 0;

    while (idx1 <= mid && idx2 <= end) {
        if (list[idx1] <= list[idx2]) {
            templist[k++] = list[idx1++];
        } else {
            templist[k++] = list[idx2++];
        }
    }

    while (idx1 <= mid) templist[k++] = list[idx1++];
    while (idx2 <= end) templist[k++] = list[idx2++];

//    for(int i=0;i<size;i++) printf("%d ",templist[i]);
//    printf("\n");


    for (int i = 0, j = start; i < size; i++, j++) {
        list[j] = templist[i];
    }

//    for(int i=0;i<20;i++) printf("%d ",list[i]);
//    printf("\n");
}