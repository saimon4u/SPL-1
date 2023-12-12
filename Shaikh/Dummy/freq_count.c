#include<stdio.h>

int main()
{
    int num, i, j, c=0;
    printf("Enter Array size : ");
    scanf("%d",&num);
    int arr[num],count[num];
    printf("Enter the numbers : \n");
    
    for(i=0; i<num; i++)
    {
        scanf("%d",&arr[i]);
        count[i]=0;
    }

    for(i=0; i<num; i++)
    {
        for(j=0; j<num; j++)
        {
            if( arr[i]==arr[j])
            {
                count[i]=count[i]+1;
                if( i < j )
                {
                    count[i]=-1;
                }
            }
        }
    }
    
    for(i=0; i<num; i++)
    {
        if(count[i]!=-1)
        {
            printf("%d--> %d\n",arr[i],count[i]);
        }
    }
    return 0;
}