//Selection sort in C
//Time complexity O(n*n)
//Space complexity O(1)  Because we do not need extra array or any space
#include<stdio.h>
int main()
{
    int min_index;
    int arr[]={3,6,2,1,6,9,5,54,33};
    int size=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<size;i++)
    {
        min_index=i;
        for(int j=i+1;j<size;j++)
        {
            if(arr[j]<arr[min_index])// for descending order use arr[j]>arr[min_index]
            {
                 min_index=j;
            }
        }
        if(min_index!=i)
        {
            int temp=arr[i];
            arr[i]=arr[min_index];
            arr[min_index]=temp;
        }
    }
    printf("Sorted array in ascending order : ");
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
}
