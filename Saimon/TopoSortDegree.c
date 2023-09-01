#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<stdbool.h>
#include "saimon.h"
#define size 50
typedef struct Node{
    int data,top,*adjacent;
}node;
int inDegree[size];
int visited;
void TopologicalSort(int vertex,node *graph){
    queue *q = createQueue();
    queue *result = createQueue();
    for(int i=0; i<vertex; ++i){
        if(inDegree[i]==0)enqueue(q,i);
    }
    while(!QueueEmpty(q)){
        int x = dequeue(q);
        visited++;
        for(int i=0; i<graph[x].top; ++i){
            inDegree[graph[x].adjacent[i]]--;
            if(inDegree[graph[x].adjacent[i]]==0)enqueue(q,graph[x].adjacent[i]);
        }
        enqueue(result,x);
    }
    if(visited==vertex){
        printf("Topological sorted list: ");
        while(!QueueEmpty(result)){
            printf("%d ",dequeue(result));
        }
        printf("\n");
        return;
    }
    printf("There is a cycle in this graph!\n");
}
int main(){
    int vertex,edge;
    scanf("%d %d",&vertex,&edge);
    node *graph = malloc(sizeof(node) * (vertex+1));
    for(int i=0; i<vertex; ++i){
        graph[i].top = 0;
        graph[i].adjacent = malloc(sizeof(int) * vertex);
    }
    for(int i=0; i<edge; ++i){
        int v1,v2;
        scanf("%d %d",&v1,&v2);
        graph[v1].adjacent[graph[v1].top++] = v2;
        inDegree[v2]++;
    }
    TopologicalSort(vertex,graph);
    return 0;
}