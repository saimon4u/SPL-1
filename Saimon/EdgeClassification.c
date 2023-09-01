#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define size 50
typedef struct node{
    int data;
    int top;
    int *adjacent;
}node;
typedef enum EdgeType{
    tree,back,forward,cross
}EdgeType;
int visited[size];
int parent[size];
int discovery[size];
int finish[size];
int time;
void DFS(int source,int vertex,int par,EdgeType edgeType[size][size],node *graph,int *time){
    visited[source] = 1;
    discovery[source] = ++(*time);
    for(int i=0; i<graph[source].top; ++i){
        if(visited[graph[source].adjacent[i]] == -1){
            parent[graph[source].adjacent[i]] = source;
            edgeType[source][graph[source].adjacent[i]] = tree;
            DFS(graph[source].adjacent[i],vertex,source,edgeType,graph,time);
        }
        else{
            if(finish[graph[source].adjacent[i]]==-1 && discovery[source] >= discovery[graph[source].adjacent[i]] && visited[graph[source].adjacent[i]]==1) edgeType[source][graph[source].adjacent[i]] = back;
            else if(discovery[source] < discovery[graph[source].adjacent[i]] && finish[source] <= finish[graph[source].adjacent[i]])
                edgeType[source][graph[source].adjacent[i]] = forward;
            else edgeType[source][graph[source].adjacent[i]] = cross;
        }
    }
    (*time)++;
    visited[source] = 2;
}
void ClassifyEdge(int vertex,EdgeType edgeType[size][size],node* graph){
    int time = 0;
    for(int i=0; i<vertex; ++i){
        visited[i] = -1;
        parent[i] = -1;
        finish[i] = -1;
        for(int j=0; j<vertex; ++j){
            edgeType[i][j] = -1;
        }
    }
    for(int i=0; i<vertex; ++i){
        if(visited[i]==-1)DFS(i,vertex,-1,edgeType,graph,&time);
    }
}
int main(){
    int vertex,edge;
    scanf("%d%d",&vertex,&edge);
    node *graph=(node*)malloc(sizeof(node)*(vertex+1));
    for(int i=0; i<vertex; ++i){
        graph[i].top = 0;
        graph[i].adjacent = malloc(sizeof(int)*vertex);
    }
    for(int i=0; i<edge; ++i){
        int v1,v2;
        scanf("%d%d",&v1,&v2);
        graph[v1].adjacent[graph[v1].top++] = v2;
    }
    EdgeType edgeType[size][size];
    ClassifyEdge(vertex,edgeType,graph);
    for(int i=0; i<vertex; ++i){
        for(int j=0; j<vertex; ++j){
            if(edgeType[i][j] != -1){
                printf("(%d -> %d) - ",i,j);
                switch(edgeType[i][j]){
                    case tree:
                        printf("tree\n");
                        break;
                    case back:
                        printf("back\n");
                        break;
                    case forward:
                        printf("forward\n");
                        break;
                    case cross:
                        printf("cross\n");
                        break;
                }
            }
        }
    }
    return 0;
}