#include<stdio.h>
#include<malloc.h>
#include "saimon.h"
#define MAX 100
typedef struct Node{
    int data,top,*adjacent;
}node;
int par[MAX];
int level[MAX];
bool visited[MAX];
void BFS(int source,node *g){
    queue *q = createQueue();
    enqueue(source);
    visited[source] = true;
    level[source] = 0;
    while(!QueueEmpty()){
        int vertex = dequeue();
        for(int i=0; i<g[vertex].top; ++i){
            if(!visited[g[vertex].adjacent[i]]){
                enqueue(g[vertex].adjacent[i]);
                level[g[vertex].adjacent[i]] = level[vertex] + 1;
                par[g[vertex].adjacent[i]] = vertex;
                visited[g[vertex].adjacent[i]] = true;
            }
        }
    }
}
int main(){
    int v,e;
    scanf("%d %d",&v,&e);
    node *graph = malloc(sizeof(node) * (v+1));
    for(int i=0; i<MAX; ++i){
        graph[i].top = 0;
        graph[i].adjacent = malloc(sizeof(int)*v);
    }
    for(int i=1; i<=e; ++i){
        int v1,v2;
        scanf("%d %d",&v1,&v2);
        graph[v1].adjacent[graph[v1].top++] = v2;
        graph[v2].adjacent[graph[v2].top++] = v1;
    }
    int n = 1;
    BFS(n,graph);
    printf("Distance: \n");
    for(int i=1; i<=v; i++){
        printf("Distance of %d from %d is : %d\n",i,n,level[i]);
    }
    return 0;
}