#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void countingsort(int *input, int *output, int *count, int range,int size);
int main(){
    double start,end;
    srand((int)time(0));
    int size=100,range=50,i,input[size],output[size],count[range];
    for(i=0; i<size; i++)
        input[i]=rand()%range;
    start=(double)clock();
    countingsort(input,output,count,range,size);
    for(i=0; i<size; i++)
        printf("%d--%d\n",i+1,output[i]);
    end=(double)clock();
    printf("\nTime takes to sort: %.2lf milli seconds.",(double)1000*((end-start)/CLOCKS_PER_SEC));
    return 0;
}
void countingsort(int *input, int *output, int *count, int range,int size){
    int i,j;
    for(i=0; i<=range; i++)
        count[i]=0;
    for(i=0; i<size; i++)
        count[input[i]]++;
    for(i=1; i<=range; i++)
        count[i]=count[i]+count[i-1];
    for(i=size-1; i>=0; i--){
        output[count[input[i]]]=input[i];
        count[input[i]]--;
    }
}