#include<stdio.h>
#include<stdbool.h>
#include "saimon.h"
#define size 100
int graph[size][size];
int visited[size];
void TopologicalSort(int source,stack *s){
    visited[source] = 1;
    for(int i=0; i<size; ++i){
        if(graph[source][i]==1 && visited[i]==-1){
            TopologicalSort(i,s);
        }
    }
    push(s,source);
}
int main(){
    int vertex,edge;
    scanf("%d %d",&vertex,&edge);
    for(int i=0; i<edge; ++i){
        int v1,v2;
        scanf("%d %d",&v1,&v2);
        graph[v1][v2] = 1;
        visited[v1] = -1;
        visited[v2] = -1;
    }
    stack *s = createStack();
    for(int i=0; i<size; ++i){
        if(visited[i]==-1)TopologicalSort(i,s);
    }
    printf("The ordering should be like: \n");
    while(!StackEmpty(s))printf("%d ",pop(s));
    printf("\n");
    return 0;
}