#include<stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

#define N 100

void create_graph(int nodes, int edges) ;
void dfs(int start);
void dfs2(int start);
int maximum();

int graph[N][N],trans[N][N];
int visited[N];
int f[N];
int time;

int main(int argc,char *argv[])
{
    int nodes,edges,start;
    scanf("%d %d",&nodes,&edges);
    create_graph(nodes,edges);
    
    for(int i=0; i<N ;++i){
        if(visited[i]==-1){
            dfs(i);
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0;j<N;j++){
            trans[i][j]=graph[j][i];
        }
    }
    for(int i=0;i<N;i++){
        if(visited[i]==1) visited[i]=-1;
    }

    printf("Strognly connected components:\n");
    for(int i=1; i<=nodes; ++i){
        int index = maximum();
        if(visited[index]==-1){
            DFS2(index);
            printf("\n");
        }
    }

    return 0;
}

void create_graph(int nodes, int edges) {
    int u, v;
    for(int i = 1; i <= edges; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        visited[u]=visited[v]=-1;
    }
}

void dfs(int start){
    visited[start]=1;
    time++;

    for(int i=0;i<N;i++){
        if(graph[start][i]==1 && visited[i]==-1){
           dfs(i);
        }
    }
    time++;
    f[start]=time;
}

int maximum(){
    int max=0,index;
    for(int i=0;i<N;i++){
        if(f[i]>max){
            max=f[i];
            index=i;
        }
    }
    f[index]=0;
    return index;
}
void dfs2(int start){
    visited[start]=1;

    printf("%d ",start);

    for(int i=0;i<N;i++){
        if(graph[start][i]==1 && visited[i]==-1){
           dfs(i);
        }
    }

}