#include<stdio.h>
#include<limits.h>

#define N 1000

int graph[N][N];
int prev[N],d[N],f[N],color[N];
int sortedOrder[N]; 
int time=0;


void creat_graph(int nodes,int edges){
    int u,v;
    for(int i=1;i<=edges;i++){
        scanf("%d %d",&u,&v);
        graph[u][v]=1;   //directed graph

    }
    
}
void dfs_visit(int u,int nodes){
    color[u]=1; //1 represents grey
    time=time+1;
    d[u]=time;
    for (int i = 1; i <= nodes; i++) {
        if (graph[u][i] == 1 && color[i] == 0) {
            color[i] = 1; // Mark the adjacent node as gray
            prev[i] = u;
            dfs_visit(i,nodes);
        }
    }
    color[u]=2; //make the current node as black
    time=time+1;
    f[u]=time;
    sortedOrder[time]=u;
}
void dfs(int nodes) {

    for (int i = 1; i <= nodes; i++) {
        color[i] = 0; // 0 represents white color
        prev[i] = -1;
        d[i] = INT_MAX;
        f[i]=INT_MAX;
    }

    for(int i=1;i<=nodes;i++){
        if(color[i]==0) {
            dfs_visit(i,nodes);
        }
        
    }
}

int main(int argc,char *argv[])
{
    int nodes,edges,start;
    scanf("%d %d",&nodes,&edges);
    creat_graph(nodes,edges); 

    dfs(nodes);

    printf("Topological sort");
    for(int i=time;i>=1;i--){
       if(sortedOrder[i]!=0) printf("%d ",sortedOrder[i]);
    }
    printf("\n");


    return 0;
}