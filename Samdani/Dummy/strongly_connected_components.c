#include<stdio.h>

#define size 50

int graph[size][size],trans[size][size];
int visited[size],d[size],f[size];
int time;

void create_graph(int edges);
void trans_graph();
int maximum();
void dfs(int source);
void dfs2(int source);

int main(int argc,char *argv[])
{

    int nodes,edges;
    scanf("%d %d",&nodes,&edges);

    create_graph(edges);
    for(int i=1;i<size;i++){
        if(visited[i]==-1) dfs(i);
    }
    trans_graph();

    //making the visited node unvisited for dfs2
    for(int i=1;i<size;i++){
        if(visited[i]==1) visited[i]=-1;
    }

    printf("Strongly connected components are:\n");
    for(int i=1;i<=nodes;i++){
        int index=maximum();
        if(visited[index]==-1){
            dfs2(i);
            printf("\n");
        }
    }


    return 0;
}
void create_graph(int edges){
    int u,v;
    for(int i=1;i<=edges;i++){
        scanf("%d %d",&u,&v);
        graph[u][v]=1;
        visited[u]=visited[v]=-1;
    }
}
void dfs(int source){
    visited[source]=1;
    time++;
    d[source]=time;

    for(int i=1;i<size;i++){
        if(graph[source][i]==1 && visited[i]==-1){
            dfs(i);
        }
    }
    time++;
    f[source]=time;

}
void trans_graph(){
    for(int i=0; i<size; i++){
        for(int j=0;j<size;j++){
            trans[i][j]=graph[j][i];
        }
    }
}
int maximum(){
    int index,max=0;
    for(int i=1;i<size;i++){
        if(f[i]>max){
            max=f[i];
            index=i;
        }
    }
    f[index]=0;
    return index;
}
void dfs2(int source){
    visited[source]=1;
    printf("%d ",source);
    for(int i=1;i<size;i++){
        if(trans[source][i]==1 && visited[i]==-1){
            dfs2(i);
        }
    }
}