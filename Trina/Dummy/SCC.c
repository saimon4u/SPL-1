#include<stdio.h>
#include<stdlib.h>

void dfs_visit(int a,int b);
void dfs_scc(int ver);
void dfs_ssc_visit(int ver,int u);
void transpose(int ver);

int graph[100][100];
char color[100];
int discovery_time[100];
int finishing_time[100];
int parent[100];
int t;
int c=0;
int inverse[100][100];

struct store{

  int vertex;
  int finish_time;

}nodes[100];

void dfs(int ver,int source){

     for(int i=1;i<=ver;i++){
        color[i]='W';
        discovery_time[i]=INT_MAX;
        finishing_time[i]=INT_MAX;
        parent[i]=-1;
     }
     dfs_visit(ver,source);
     for(int i=1;i<=ver;i++){
        if(color[i]=='W'){
            dfs_visit(ver,i);
        }
     }

}

void dfs_visit(int ver,int u){

    color[u]='G';
    t++;
    discovery_time[u]=t;

      for(int j=1;j<=ver;j++){

         if(graph[u][j]==1 && color[j]=='W'){
            parent[j]=u;
            dfs_visit(ver,j);
         }
      }
      color[u]='B';
      t++;
      finishing_time[u]=t;

}

void dfs_scc(int ver){

     for(int i=1;i<=ver;i++){
        color[nodes[i].vertex]='W';
        discovery_time[nodes[i].vertex]=INT_MAX;
        finishing_time[nodes[i].vertex]=INT_MAX;
        parent[nodes[i].vertex]=-1;
     }
     t=0;
     for(int i=1;i<=ver;i++){
        if(color[nodes[i].vertex]=='W'){
            printf("\n");
            dfs_scc_visit(ver,i);
            c++;
        }
     }
}

void dfs_scc_visit(int ver,int u){

    color[u]='G';
    t++;
    discovery_time[u]=t;

      for(int j=1;j<=ver;j++){

         if(inverse[u][j]==1 && color[j]=='W'){
            parent[j]=u;
            dfs_scc_visit(ver,j);
         }
      }
      color[u]='B';
      t++;
      finishing_time[u]=t;
      printf("%d ",u);

}

void transpose(int ver){

   for(int i=1;i<=ver;i++){
    for(int j=1;j<=ver;j++){
        inverse[i][j]=graph[j][i];
    }
   }




}

int main(){

    freopen("ssc.txt","r",stdin);

    int ver,p1,p2;
    printf("How many vertices are in your graph?\n");
    scanf("%d",&ver);

    int edge,v1,v2;
    printf("How many edges are in your graph?\n");
    scanf("%d",&edge);

    for(int i=0;i<edge;i++){
        scanf("%d%d",&v1,&v2);
        graph[v1][v2]=1;
    }
    printf("Enter the source?\n");
    int source;
    scanf("%d",&source);

     dfs(ver,source);
     transpose(ver);

       for(int i=1;i<=ver;i++){
        nodes[i].vertex=i;
        nodes[i].finish_time=finishing_time[i];
       }
       for(int i=1;i<=ver;i++){
        for(int j=1;j<=ver-i;j++){
            if (nodes[i].finish_time< nodes[i+1].finish_time){
                struct store temp = nodes[i];//sorting
                nodes[i] =nodes[i + 1];
                nodes[i + 1] =temp;
            }
        }
       }
       printf("Strongly connected components are:");
       dfs_scc(ver);
       printf("\nTotal components: %d\n",c);


}

