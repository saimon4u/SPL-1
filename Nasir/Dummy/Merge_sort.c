//uses-> Inversion count problem //External Sorting // E-commerce application(^^)
//Merge sort in C
//Time Complexity O(n*log n) (Best/worse/average)
//Space Complexity O(n)
//Stability Yes
#include<stdio.h>

void merge_sort(int arr[],int left,int right)
{
    if(left<right)
    {
        int mid=left+(right-left)/2;

        merge_sort(arr,left,mid);
        merge_sort(arr,mid+1,right);

        merge(arr,left,mid,right);

    }
}

void merge(int arr[],int left,int mid,int right)
{
    int left_size,right_size;
    left_size=mid-left+1;
    right_size=right-mid;

    int L[left_size],R[right_size];
    for(int i=0; i<left_size; i++)
    {
        L[i]=arr[left+i];
    }
    for(int i=0; i<right_size; i++)
    {
        R[i]=arr[mid+1+i];


    }
    int l=0,r=0,index=left;
    while(l<left_size && r<right_size)
    {
        if(L[l]<R[r])// Use  L[l]>R[r]   for Descending order
        {
            arr[index]=L[l];
            l++;
        }
        else
        {
            arr[index]=R[r];
            r++;
        }
        index++;
    }
    while(l<left_size)
    {
        arr[index]=L[l];
                   l++;
        index++;
    }
    while(r<right_size)
    {
        arr[index]=R[r];
        r++;
        index++;
    }
}
int main()
{
    int arr[]= {5,7,3,222,4,9,7,19,-10};
    int size=sizeof(arr)/sizeof(arr[0]);
    int left=0,right=size-1;

    merge_sort(arr,left,right);

    printf("Sorted array is : ");
    for(int i=0; i<size; i++)
    {
        printf("%d ",arr[i]);
    }

}

