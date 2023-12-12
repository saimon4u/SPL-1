#include<stdio.h>

int main()
{
    int row, colmn, i, j;
    printf("Enter row & column : \n");
    scanf("%d%d",&row,&colmn);
    int mat1[row][colmn], mat2[row][colmn];
    int sum[row][colmn];

    printf("In matrix-01:\n");
    for(i=0; i<row; i++)
    {
        for(j=0; j<colmn; j++)
        {
        printf("Element-%d,%d: ",i+1,j+1);
        scanf("%d",&mat1[i][j]);
        }
    }
    printf("In matrix-02:\n");
    for(i=0; i<row; i++)
    {
        for(j=0; j<colmn; j++)
        {
        printf("Element-%d,%d: ",i+1,j+1);
        scanf("%d",&mat2[i][j]);
        }
    }

    for(i=0; i<row; i++)
    {
        for(j=0; j<colmn; j++)
        {
        sum[i][j]=mat1[i][j]+mat2[i][j];
        }
    }

    printf("Sum Matrix:\n");
    for(i=0; i<row; i++)
    {
        for(j=0; j<colmn; j++)
        {
        printf("%d  ",sum[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}