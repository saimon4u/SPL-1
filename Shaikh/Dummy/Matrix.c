#include<stdio.h>
#include<conio.h>

int main()
{
    int row, colmn, i, j;
    printf("Enter row & column : \n");
    scanf("%d%d",&row,&colmn);
    int mat1[row*colmn], mat2[row*colmn];
    int sum[row*colmn];

    printf("In matrix-01:\n");
    for(i=0; i<row*colmn; i++)
    {
        printf("Element-%d: ",i+1);
        scanf("%d",&mat1[i]);
    }
    printf("In matrix-02:\n");
    for(i=0; i<row*colmn; i++)
    {
        printf("Element-%d: ",i+1);
        scanf("%d",&mat2[i]);
    }

    for(i=0; i<row*colmn; i++)
    {
        sum[i]=mat1[i]+mat2[i];
    }

    for(i=0; i<row*colmn; i++)
    {
        printf("%d ",sum[i]);
        if((i+1)%colmn==0)printf("\n");
    }
    
    return 0;
}