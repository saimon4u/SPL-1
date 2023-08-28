#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<stdbool.h>
#include "saimon.h"
#define size 50
typedef struct Node{
    int data,top,*adjacent;
}node;
int min(int a,int b){
    if(a<b) return a;
    return b;
}
void DFS(node *graph,int u,bool visited[],int discovery[],int low[],int *time,int parent,bool point[]){
    int child = 0;
    visited[u] = true;
    discovery[u] = low[u] = ++(*time);
    for(int v=0; v<graph[u].top; ++v){
        if(!visited[graph[u].adjacent[v]]){
            child++;
            DFS(graph,graph[u].adjacent[v],visited,discovery,low,time,u,point);
            low[u] = min(low[u],low[graph[u].adjacent[v]]);
            if(parent != -1 && low[graph[u].adjacent[v]] >= discovery[u])point[u] = true;
        }
        else if(graph[u].adjacent[v] != parent)low[u] = min(low[u],discovery[graph[u].adjacent[v]]);
    }
    if(parent == -1 && child > 1)point[u] = true;
}
void DetectPoint(node *graph,int vertex){
    int low[vertex];
    int discovery[vertex];
    bool visited[vertex];
    bool point[vertex];
    int time=0,par=-1;
    for(int i=0; i<vertex; ++i){
        discovery[i] = 0;
        visited[i] = false;
        point[i] = false;
    }
    for(int u=0; u<vertex; ++u){
        if(!visited[u])DFS(graph,u,visited,discovery,low,&time,par,point);
    }
    printf("Articulation points are: ");
    for(int i=0; i<vertex; ++i){
        if(point[i])printf("%d ",i);
    }
    printf("\n");
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
        graph[v2].adjacent[graph[v2].top++] = v1;
    }
    DetectPoint(graph,vertex);
    return 0;
}