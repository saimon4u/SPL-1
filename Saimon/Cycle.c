#include<stdio.h>
#include<stdbool.h>
#define size 50
int graph[size][size];
int visited[size];
bool check[size];
int path[size];
int top;
bool DFS(int source){
    visited[source] = 1;
    check[source] = true;
    path[top++] = source;
    bool loop = false;
    for(int i=1; i<size; ++i){
        if(visited[i]==1 && check[i]== true && graph[source][i]==1){
            printf("Loop exists between: ");
            for(int j=0; j<top; ++j){
                printf("%d ",path[j]);
            }
            printf("\n");
            return true;
        }
        if(graph[source][i]==1 && visited[i]==-1){
            loop |= DFS(i);
        }
    }
    check[source] = false;
    top--;
    return loop;
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
    bool loop = false;
    for(int i=1; i<size; ++i){
        if(visited[i]==-1){
            if(DFS(i)) loop = true;
        }
    }
    if(!loop)printf("loop doesn't exists!\n");
    return 0;
}