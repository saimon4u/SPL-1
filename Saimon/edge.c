#include<stdio.h>
#define size 50
enum EdgeType{
    tree,
    back,
    forward,
    cross
};
int graph[size][size];
int visited[size];
int parent[size];
void DFS(int vertex,int source,enum EdgeType edgeType[size][size]){
    visited[source] = 1;
    for(int i=0; i<vertex; ++i){
        if(graph[source][i]==1){
            if(!visited[i]){
                parent[i] = source;
                edgeType[source][i] = tree;
                DFS(vertex,i,edgeType);
            }
            else{
                if(parent[source]!=i){
                    if(visited[i]==1 && graph[i][source]==1){
                        edgeType[source][i] = back;
                    }
                    else if(visited[i]==1 && graph[source][i]==1){
                        edgeType[source][i] = forward;
                    }
                    else{
                        edgeType[source][i] = cross;
                    }
                }
            }
        }
    }
    visited[source] = 2;
}
void ClassifyEdges(int vertex,enum EdgeType edgeType[size][size]){
    for(int i=0; i<vertex; ++i){
        visited[i]=0;
        parent[i]=-1;
        for(int j=0; j<vertex; ++j){
            edgeType[i][j] = -1;
        }
    }
    for(int i=0; i<vertex; ++i){
        if(!visited[i])DFS(vertex,i,edgeType);
    }
}
int main(){
    int vertex,edge;
    scanf("%d %d",&vertex,&edge);
    for(int i=0; i<edge; ++i){
        int v1,v2;
        scanf("%d %d",&v1,&v2);
        graph[v1][v2] = 1;
    }
    enum EdgeType edgeType[size][size];
    ClassifyEdges(vertex,edgeType);
    printf("Edge List: \n");
    for(int i=0; i<vertex; ++i){
        for(int j=0; j<vertex; ++j){
            if(edgeType[i][j]!=-1){
                printf("(%d,%d) - ",i,j);
                switch(edgeType[i][j]){
                    case tree:
                        printf("Tree edge\n");
                        break;
                    case back:
                        printf("Back edge\n");
                        break;
                    case forward:
                        printf("Forward edge\n");
                        break;
                    case cross:
                        printf("Cross edge\n");
                        break;
                }
            }
        }
    }
    return 0;
}