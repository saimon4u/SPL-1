#include<stdio.h>
int main()
{
    int  x;
    int *ptr;
    ptr=(int *)malloc(5*sizeof(int));
    int ptr1;
     ptr1=(int*)calloc(5,sizeof(int ));
    free(ptr);

    ptr1=realloc(ptr1,50);

    if(ptr==NULL || ptr1==NULL)
    {
        printf("No memory allocation\n");

    }
    else{
        printf("Memory allocation successfully\n");

    }
}
