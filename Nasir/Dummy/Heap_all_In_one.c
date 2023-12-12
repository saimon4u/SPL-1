#include<stdio.h>

int left_child(int i)
{
    return i*2;
}
int right_child(int i)
{
    return i*2+1;
}
int parent(int i)
{
    return i/2;
}

void is_max_heap(int heap[],int heap_size)
{
    int count=0;
    for(int i=heap_size-1;i>1;i--)
    {
        int p=parent(i);
        if(heap[p]<heap[i])
        {
            count++;
        }
    }
    if(count!=0)
    {
        printf("Sorry ! Not  Max heap\n");
    }
    else
        printf("Success ! Max heap\n");
        printf("\n");
}

void max_heapify(int heap[],int heap_size,int p) //T C ->O(log n)
{

    int l=left_child(p);
    int r=right_child(p);
    int largest;
    if(l<heap_size && heap[l]>heap[p])
      largest=l;
      else
        largest=p;
    if(r<heap_size && heap[r]>heap[largest])
        largest=r;
    if(largest!=p)
    {
        int t=heap[p];
        heap[p]=heap[largest];
        heap[largest]=t;

        max_heapify(heap,heap_size,largest);
    }

}

void print_heap(int heap[],int heap_size)
{
    for(int i=1;i<heap_size;i++)
    {
        printf("%d ",heap[i]);
    }
    printf("\n");
}
void heap_sort(int heap[],int heap_size)
{
        int size=heap_size;

    for(int i=heap_size-1;i>1;i--)
    {
        int t=heap[i];
        heap[i]=heap[1];
        heap[1]=t;
        size-=1;
        max_heapify(heap,size,1);

    }
}

void Build_max_heap(int heap[],int heap_size)
{
        for(int i=1;i<heap_size/2;i++)
        {
            max_heapify(heap,heap_size,i);
        }

}

int find_maximum(int heap[])
{
    return heap[1];
}

int Extract_max(int heap[],int heap_size)
{
    int max=heap[1];
    heap[1]=heap[heap_size-1];
    heap_size--;
    max_heapify(heap,heap_size,1);


    return heap_size;
}

   int insert_priority(int heap[],int heap_size,int item)
   {
        heap_size++;
        heap[heap_size-1]=heap[1];
        heap[1]=item;
        Build_max_heap(heap,heap_size);
        return heap_size;
   }

int main()
{
    int heap[]={0,19,7,17,3,5,12,10,1,4};
    int heap_size=sizeof(heap)/sizeof(heap[0]);
    print_heap(heap,heap_size);

    is_max_heap(heap,heap_size);

    Build_max_heap(heap,heap_size);          // T C ->O(n lon n)

    int max_value=find_maximum(heap);
    printf("\nMax priority value : %d\n\n",max_value);
    print_heap(heap,heap_size);

    is_max_heap(heap,heap_size);               // T C ->O(log n)

    heap_size=Extract_max(heap,heap_size); //T C->O(log n)
    printf("After Extract max :\n");
    print_heap(heap,heap_size);

    printf("Enter priority value that you want to insert in priority queue\n");
    int value;
    scanf("%d",&value);
    heap_size=insert_priority(heap,heap_size,value);
    printf("After inserting priority value in priority queue :\n ");
    print_heap(heap,heap_size);




    heap_sort(heap,heap_size);                    //T C ->O(n log n)
    printf("Applying heap sort\n");
    print_heap(heap,heap_size);

return 0;
}
