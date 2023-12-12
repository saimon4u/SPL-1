#include <stdio.h>
#include <stdlib.h>
struct Heap{
	int size;
	int capacity;
	int* arr;
};
typedef struct Heap heap;
heap* BuildHeap(int capacity, int* nums,int size);
void insertHelper(heap* h, int index);
void heapify(heap* h, int index);
void swap(int *a,int *b);
int extractRoot(heap* h);
void insert(heap* h, int data);
void delete(heap* h,int index);
void swap(int *a, int *b){
        *a = (*a)^(*b);
        *b = (*a)^(*b);
        *a = (*a)^(*b);
}
heap* createHeap(int capacity){
	heap *h = malloc(sizeof(heap));
	h->size = 0;
	h->capacity = capacity;
	h->arr = malloc(capacity * sizeof(int));
	return h;
}
heap* BuildHeap(int capacity, int *nums,int size){
	heap* h = createHeap(capacity);
	int i;
	for(i = 0; i < size; i++){
		h->arr[i] = nums[i];
	}
	h->size = i;
	i = (h->size-2) / 2;
	while (i >= 0){
		heapify(h, i);
		i--;
	}
	return h;
}
void insertHelper(heap* h, int index){
	int parent = (index - 1) / 2;
	if(h->arr[parent] > h->arr[index]){
		swap(&h->arr[parent],&h->arr[index]);
		insertHelper(h, parent);
	}
}
void heapify(heap* h, int index){
	int left = index * 2 + 1;
	int right = index * 2 + 2;
	int min = index;
    if (left >= h->size || left < 0)
        left = -1;
    if (right >= h->size || right < 0)
        right = -1;
	if(left !=-1 && h->arr[left] < h->arr[min])
		min = left;
	if(right !=-1 && h->arr[right] < h->arr[min])
		min = right;
	if(min != index){
		swap(&h->arr[min],&h->arr[index]);
		heapify(h, min);
	}
}
int extractRoot(heap* h){
	int deleteItem;
	deleteItem = h->arr[0];
	h->arr[0] = h->arr[h->size - 1];
	h->size--;
	heapify(h, 0);
	return deleteItem;
}
void insert(heap* h, int data){
	if(h->size < h->capacity){
		h->arr[h->size] = data;
		insertHelper(h, h->size);
		h->size++;
	}
}
void delete(heap* h, int index){
    swap(&h->arr[index],&h->arr[h->size-1]);
    h->size--;
    for(int i= (h->size)/2; i>=0; --i){
        heapify(h,i);
    }
}
void Heapsort(heap *h){
    int size = h->size;
    for(int i=0; i<size; ++i){
        printf("%d ",extractRoot(h));
    }
    printf("\n");
}
void printHeap(heap* h){
	for (int i = 0; i < h->size; i++) {
		printf("%d ", h->arr[i]);
	}
	printf("\n");
}
int main(){
	/*
						   1
					  2		  3
			       8	22	21	34
				9	65
	

	*/
	int arr[9] = {1, 8, 34, 65, 22, 21, 3, 2, 9};
	heap* hp = BuildHeap(15,arr,9);
	// heap *hp = createHeap(15);
	// for(int i=0; i<9; i++){
	// 	insert(hp,arr[i]);
	// }
	printHeap(hp);
	extractRoot(hp);
	// printHeap(hp);
    insert(hp,20);
    // printHeap(hp);
    delete(hp,3);
    // printHeap(hp);
    Heapsort(hp);
	return 0;
}
