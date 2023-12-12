//Linear search in C
//Time complexity O(n)
//Space complexity O(1)

#include<stdio.h>
int main()
{
    int a[]= {4,3,5,2,6,6,7,8,0};
    printf("Enter a value that you want to search\n");
    int search_value,size;
    size=sizeof(a)/sizeof(a[0]);

    scanf("%d",&search_value);
    for(int i=0; i<size; i++)
    {
        if(a[i]==search_value)
        {
            printf("%d is found in %d th index\n",search_value,i);
            return ;
        }

    }
    printf("The value is not found\n");
    return 0;
}
