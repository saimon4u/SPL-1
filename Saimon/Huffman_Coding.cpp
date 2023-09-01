#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define Maximum_Tree_Height 100
#define loop(i,n) for (int i = 0; i < n; i++)
using namespace std;
int TotalBit = 0;
struct HuffmanNode{
    char data;
    int freq;
    HuffmanNode *left,*right;
};
struct HuffmanHeap{
    int size;
    int capacity;
    HuffmanNode* *array;
};
void HuffmanCoding(char *list,int *freq,int size);
void ArrangeHeap(HuffmanHeap *heap);
void ExchangeHeapValue(HuffmanHeap *heap ,int index);
void SwapNode(HuffmanNode* *a,HuffmanNode* *b);
void InsertIntoHeap(HuffmanHeap *heap,HuffmanNode *node);
void GetHuffmanCode(HuffmanNode *root,int *arr,int top);
void PrintCode(int *arr,int size);
HuffmanNode* CreateHuffmanTree(char *list,int *freq,int size);
HuffmanNode* CreateNode(char data,int freq);
HuffmanNode* ExtractMinimum(HuffmanHeap *heap);
HuffmanHeap* FillHeapArray(char *list,int *freq,int size);
HuffmanHeap* AllocateMemory(int capacity);
bool IsLeaf(HuffmanNode *root);
bool IsSizeOne(HuffmanHeap *heap);
int main(){
    char list[] = {'a','b','c','d','e','f'};
    int freq[] = {45,13,12,16,9,5};
    int size = sizeof(list) / sizeof(list[0]);
    cout << "Data--->Code" << endl;
    HuffmanCoding(list,freq,size);
    cout << endl;
    cout << "Memory saved: " << (100*8)-TotalBit << " bit" << endl;
    return 0;
}
void HuffmanCoding(char *list,int *freq,int size){
    HuffmanNode *root = CreateHuffmanTree(list,freq,size);
    int arr[Maximum_Tree_Height],top = 0;
    GetHuffmanCode(root,arr,top);
}
HuffmanNode* CreateHuffmanTree(char *list,int *freq,int size){
    HuffmanNode *left,*right,*top;
    HuffmanHeap *heap = FillHeapArray(list,freq,size);
    while(!IsSizeOne(heap)){
        left = ExtractMinimum(heap);
        right = ExtractMinimum(heap);
        top = CreateNode('*',left->freq + right->freq);
        top->left = left;
        top->right = right;
        InsertIntoHeap(heap,top);
    }
    return ExtractMinimum(heap);
}
HuffmanHeap* FillHeapArray(char *list,int *freq,int size){
    HuffmanHeap *heap = AllocateMemory(size);
    for(int i=0; i<size; i++) heap->array[i] = CreateNode(list[i],freq[i]);
    heap->size = size;
    ArrangeHeap(heap);
    return heap;
}
HuffmanHeap* AllocateMemory(int capacity){
    HuffmanHeap *heap = (HuffmanHeap *)malloc(sizeof(HuffmanHeap));
    heap->size = 0;
    heap->capacity = capacity;
    heap->array = (HuffmanNode **)malloc(heap->capacity * sizeof(HuffmanNode *));
    return heap;
}
HuffmanNode* CreateNode(char data,int freq){
    HuffmanNode *node = (HuffmanNode *)malloc(sizeof(HuffmanNode));
    node->left = node->right = NULL;
    node->data = data;
    node->freq = freq;
    return node;
}
void ArrangeHeap(HuffmanHeap *heap){
    int n = heap->size - 1;
    int i;
    for(i=(n-1)/2; i>=0; i--) ExchangeHeapValue(heap,i);
}
void ExchangeHeapValue(HuffmanHeap *heap ,int index){
    int smallest = index;
    int left = 2*index + 1;
    int right = 2*index + 2;
    if(left < heap->size && heap->array[left]->freq < heap->array[smallest]->freq)smallest = left;
    if(right < heap->size && heap->array[right]->freq < heap->array[smallest]->freq)smallest = right;
    if(smallest!=index){
        SwapNode(&heap->array[smallest],&heap->array[index]);
        ExchangeHeapValue(heap,smallest);
    }
}
void SwapNode(int *a, int *b){
    *a = (*a)^(*b);
    *b = (*a)^(*b);
    *a = (*a)^(*b);
}
bool IsSizeOne(HuffmanHeap *heap){
    return heap->size == 1;
}
HuffmanNode* ExtractMinimum(HuffmanHeap *heap){
    HuffmanNode *node = heap->array[0];
    heap->array[0] = heap->array[heap->size -1];
    --heap->size;
    ExchangeHeapValue(heap,0);
    return node;
}
void InsertIntoHeap(HuffmanHeap *heap,HuffmanNode *node){
    ++heap->size;
    int i = heap->size - 1;
    while(i && node->freq < heap->array[(i-1)/2]->freq){
        heap->array[i] = heap->array[(i-1)/2];
        i = (i-1)/2;
    }
    heap->array[i] = node;
}
void GetHuffmanCode(HuffmanNode *root,int *arr,int top){
    if(root->left){
        arr[top] = 0;
        GetHuffmanCode(root->left,arr,top+1);
    }
    if(root->right){
        arr[top] = 1;
        GetHuffmanCode(root->right,arr,top+1);
    }
    if(IsLeaf(root)){
        cout << root->data << "--->";
        TotalBit += root->freq * top;
        PrintCode(arr,top);
    }
}
bool IsLeaf(HuffmanNode *root){
    return !(root->left) && !(root->right);
}
void PrintCode(int *arr,int size){
    for(int i=0; i<size; i++) cout << arr[i];
    cout << endl;
}