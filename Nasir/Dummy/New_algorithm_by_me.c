//Insertion sort in C
//Time complexity O(n*n)
//Space complexity O(1)
#include<stdio.h>
int main()
{
    int value,hole;
    int arr[]={4,2,1,5};
    int size=sizeof(arr)/sizeof(arr[0]);

    for(int i=1;i<size;i++)
    {

        hole=i;
        while(hole>0 && arr[hole-1]>arr[hole])
        {
            int temp=arr[hole];
                  arr[hole]=arr[hole-1];
                  arr[hole-1]=temp;
                  hole--;
        }
    }
    printf("Sorted array in ascending order : ");
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
}
