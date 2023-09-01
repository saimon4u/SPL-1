#include<stdio.h>
#include<stdbool.h>
#define size 50
int graph[size][size];
bool visited[size];
int path[size];
int top;
int Num_Path;
void DFS(int source,int destination){
    visited[source] = true;
    path[top++] = source;
    if(source == destination){
        Num_Path++;
        printf("This is a path: \n");
        for(int i=0; i<top; ++i){
            printf("%d ",path[i]);
        }
        printf("\n");
    }
    else{
        for(int i=0; i<size; ++i){
            if(graph[source][i]==1 && visited[i]==false){
                DFS(i,destination);
            }
        }
    }
    top--;
    visited[source] = false;
}
int main(){
    int vertex,edge;
    scanf("%d %d",&vertex,&edge);
    for(int i=0; i<edge; ++i){
        int v1,v2;
        scanf("%d %d",&v1,&v2);
        graph[v1][v2] = 1;
    }
    DFS(2,3);
    printf("There are %d path!\n",Num_Path);
    return 0;
}