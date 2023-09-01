#include<stdio.h>


void heapify(int *cbt,int i);
void insert(int *cbt,int newNode);
void delete(int *cbt,int deleteNode);
void swap(int *a,int *b);
void print(int *cbt);

int size;

int main(int argc,char *argv[])
{

    int cbt[10]={3,9,2,1,4,5};
    int ins,del;
    // size= sizeof(cbt) / sizeof(cbt[0]);
    for(int i=0; i<10; i++){
        if(cbt[i]!=0)size++;
    }
    
    for(int i=(size/2)-1;i>=0;i--){
        heapify(cbt,i);
    }
    print(cbt);
    printf("Enter node to insert:");
    scanf("%d",&ins);
    insert(cbt,ins);
    print(cbt);
    // printf("Enter node to delete:");
    // scanf("%d",&del);
    // delete(cbt,del);
    // print(cbt);
   

    return 0;
}
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;

}
void heapify(int *cbt,int i){
    int l,r,largest;
    largest=i;
    l=2*i+1;
    r=2*i+2;

    if(l<size && cbt[l]>cbt[largest]) largest=l;
    if(r<size && cbt[r]>cbt[largest]) largest=r;

    if(largest!=i){
        swap(&cbt[largest],&cbt[i]);
        heapify(cbt,largest);
    }
    
}
// void insert(int *cbt,int newNode){
//     if(size==0){
//         cbt[0]=newNode;
//         size++;
//     }else{
//         cbt[size]=newNode;
//         size++;

//         // for(int i=(size/2)-1;i>=0;i--){
//         //     heapify(cbt,i);
//         // }
//         while(cbt[size/2 -1]<cbt[size-1]){
//             swap(&cbt[size/2 -1],&cbt[size-1]);
//         }
//     }
// }
void doInsert(int *cbt,int index){
    int parent = (index-1)/2;
    if(cbt[parent] < cbt[index]){
        swap(&cbt[parent],&cbt[index]);
        doInsert(cbt,parent);
    }
}
void insert(int *cbt,int data){
    cbt[size] = data;
    doInsert(cbt,size);
    size++;
}
void delete(int *cbt,int deleteNode){
    int i;
    for(int i=0;i<size;i++){
        if(deleteNode==cbt[i]) break;
    }
    swap(&cbt[i],&cbt[size-1]);
    size--;

    for(i=(size/2)-1;i>=0;i--){
        heapify(cbt,i);
    }

}
void print(int *cbt){
    for(int i=0;i<size;i++){
        printf("%d ",cbt[i]);
    }
    printf("\n");
}