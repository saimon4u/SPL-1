//Insertion sort in C
//Time complexity O(n*n)
//Space complexity O(1)
#include<stdio.h>
int main()
{
    int arr[]={99,5,6,1,77,3,};
    int value,index;
    int size=sizeof(arr)/sizeof(arr[0]);

    for(int i=1;i<size;i++)
    {
        value=arr[i];
        index=i;
        while(index>0 && arr[index-1]>value)
        {
            arr[index]=arr[index-1];
            index--;
        }
        arr[index]=value;

    }
    printf("Sorted array in ascending order : ");
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
}
