#include<stdio.h>
#include<stdlib.h>

struct Heap
{
    int size;
    int capcity;
    int *arr;
};

typedef struct Heap heap;

void swap(int *a, int *b)
{
    int temp = *a ;
    *a = *b;
    *b = temp;
}

void heapify( heap* h, int index);

heap* create_heap(int *array, int cap, int size)
{
    heap* h = malloc(sizeof(heap));
    h->arr = (int*)malloc(cap*sizeof(int));
    h->capcity = cap ;
    h->size = size ;

    int i;  // size = sizeof(array)/sizeof(int);

    for ( i = 0; i < size ; i++ )
    {
        h->arr[i] = array[i] ;
    }
    //h->size = i ;

    i = (h->size - 2)/2 ;

    while ( i >= 0 )
    {
        heapify( h, i );
        i--;
    }
    
    return h ;

}

void heapify( heap* h, int index)
{
    int left, right, min;
    left = 2*index + 1 ;
    right = 2*index + 2 ;
    min = index ;

    if ( left >= h->size || left < 0 )
    {
        left = -1 ;
    }
    
    if ( right >= h->size || right < 0 )
    {
        right = -1 ;
    }

    if( left != -1 && h->arr[left] < h->arr[min] )
	{	
        min = left;
    }

	if( right != -1 && h->arr[right] < h->arr[min] )
	{
        min = right;
    }

    if( min != index )
    {
        swap( &h->arr[min], &h->arr[index] );
        heapify( h, min );
    }
    
}

void insert( heap *hp, int num )
{
    int i = hp->size;
    hp->arr[hp->size++] = num ;
    int parent = (hp->size-1)/2 ;
    while(1)
    {
        if(hp->arr[parent] > num){
            swap(&hp->arr[parent], &hp->arr[i]);
            i = parent ;
            parent = (i-1)/2;
        }
        else break;
    }
       
}

void delete( heap *hp, int num )
{
    int i;
    for ( i = 0; i < hp->size; i++)
    {
        if( hp->arr[i] == num )
        {
            break;
        }
    }
    
    swap( &hp->arr[i] , &hp->arr[ hp->size-1 ] ) ;
    hp->size-- ;
    
    for (int j = hp->size/2; j >= 0 ; j--)
    {
        heapify( hp, j ) ;
    }
    
}

int extractRoot( heap *hp )
{
    int item = hp->arr[0] ;
    swap( &hp->arr[0], &hp->arr[hp->size-1] );
    hp->size-- ;
    heapify( hp, 0 );
    return item ;
}

void heapsort( heap *hp )
{
    int size = hp->size;
    for( int i=0; i< size; i++ )
    {
        printf("%d\t", extractRoot(hp) );
    }
}

void print_heap( heap *hp )
{
    printf("\n");
    for (int i = 0; i < hp->size; i++)
    {
        printf("%d\t", hp->arr[i]);
    }
    printf("\n");
}

int main()
{
    int array[] = {9, 8, 34, 65, 22, 21, 3, 4, 1};
    int size = sizeof(array)/sizeof(int);
    heap *hp = create_heap(array, 10, size);
    print_heap(hp);

    int insrt;
    // printf("\nEnter number to insert in the heap : ");
    // scanf("%d", &insrt);
    // insert( hp, insrt );
    // print_heap(hp);
    // delete( hp, 65 );
    // print_heap(hp);
    
    // printf("%d\n",extractRoot( hp ));
    // print_heap( hp );

    heapsort( hp );

    return 0;
}



    //                 1
    //         4              3
    //     8      22        21    34
    //  9    65  2