// radixsort_al
//#include<bits/stdc++.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

// int find_max(int arr[], int n)
// {
//     int max = arr[0];
//     for (int i = 0; i < n; i++)
//     {
//         if(arr[i] >= max){
//             max = arr[i];
//         }
//     }

//     return max;
// } 

void countSort(char arr[][20], int n, int pos)
{
    
    int count[256] = {0};
    
    for(int i = 0; i<n; i++)
    {
        count[arr[i][pos]]++;
    }
    
    for(int i = 1; i<256; i++)
    {
        count[i]+= count[i-1];   // prefix summation
    }

    char output[n][20];

    for(int i = n-1 ; i>=0 ; i--)
    {
        count[arr[i][pos]]=count[arr[i][pos]]-1;
        strcpy(output[count[arr[i][pos]]],arr[i]);
    }

    for(int i =0; i< n; i++)
    {
        strcpy(arr[i],output[i]);
    }
}

void RadixSort(char arr[][20], int n)
{

    int max = 8;

    for(int pos = max-1; pos>=0 ; pos--)
    {
        countSort(arr, n, pos);
    }

}

int main()
{
    //srand(time(0));
    double s_time, e_time;
    int n=10;
    //scanf("%d", &n);

    char arr[10][20]={"Hasin","Samdani","Saimon","Yasin","Tashrif","Ismail","Kamrul","Sejuti","Tausif","Mustakim"};    
    
    for(int i = 0; i< n; i++)
    {
        printf("%s \n", arr[i]);
    }

    s_time = clock();
    
    RadixSort(arr,n);
    
    printf("\n");
    for(int i = 0; i< n; i++)
    {
        printf("%s \n", arr[i]);
    }

    printf("\n");
    e_time = clock();
    printf("%f\n",e_time-s_time);
    //printf("%f",(e_time-s_time)/CLOCKS_PER_SEC);

    return 0;
}