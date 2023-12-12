#include<stdio.h>

int main()
{
    int row1, row2, colmn1, colmn2, i, j, k, sum=0;

    printf("For matrix-01:\n");
    printf("Enter row & column : \n");
    scanf("%d%d",&row1,&colmn1);
    int mat1[row1][colmn1];
    for(i=0; i<row1; i++)
    {
        for(j=0; j<colmn1; j++)
        {
            printf("Element-%d,%d: ",i+1,j+1);
            scanf("%d",&mat1[i][j]);
        }
    }

    printf("In matrix-02:\n");
    printf("Enter row & column : \n");
    scanf("%d%d",&row2,&colmn2);
    int mat2[row2][colmn2];
    for(i=0; i<row2; i++)
    {
        for(j=0; j<colmn2; j++)
        {
            printf("Element-%d,%d: ",i+1,j+1);
            scanf("%d",&mat2[i][j]);
        }
    }

    if(colmn1!=row2)
    {
        printf("Multiplication not possible.\n");
    }
    else 
    {
        int prod[row1][colmn2]; 

        for(i=0; i<row1; i++)
        {
            for(j=0; j<colmn2; j++)
            {
                sum=0;
                for(k=0; k<colmn1; k++)
                {
                    sum=sum+mat1[i][k]*mat2[k][j];
                }
                prod[i][j]=sum;
            }
        }

        printf("Product of the Matrices:\n");
        for(i=0; i<row1; i++)
        {
            for(j=0; j<colmn2; j++)
            {
            printf("%d\t",prod[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}