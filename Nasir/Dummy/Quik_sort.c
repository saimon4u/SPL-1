//uses-> programming language is good for recursion  //  time complexity matter //space complexity matter (^^)
//quick sort in C
//Tine complexity O(n*n) (worse case)
//Time complexity O(n*log n) ( average/best)
//Space complexity O(log n)
//Stability No

#include<stdio.h>

void quick_sort(int arr[],int low,int high)
{
    if(high>low)
    {
        int pi=partition(arr,low,high);
        quick_sort(arr,low,pi-1);
        quick_sort(arr,pi+1,high);
    }
}

int partition(int arr[],int low,int high)
{
   int  pivot=arr[low];
    int l=low,h=high;

    while(h>l)
    {
        while(pivot>=arr[l]){
                 l++;
                 }
        while(pivot<arr[h]){
                 h--;
                }
                if(h>l)
                {
                 int t=arr[l];
                 arr[l]=arr[h];
                 arr[h]=t;
                }
    }
    int t=arr[h];
    arr[h]=arr[low];
    arr[low]=t;

    return h;


}

  void print_array(int arr[], int size)
  {
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
  }
int main()
{
     int arr[]={3,-5,1,7,503,8,2,1,12};
     int size=sizeof(arr)/sizeof(arr[0]);

     int high,low;
     high=size-1;
     low=0;
     quick_sort(arr,low,high);
     printf("Sorted array is : ");
     print_array(arr,size);
     return 0;
}
