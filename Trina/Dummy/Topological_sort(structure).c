#include<stdio.h>
#include<stdlib.h>

#define inf 100000
char color[1000];
int prev[1000],f[1000],d[1000];
int time;

struct node{
    int val;
    int ft;
}nodes[1000];

void DFS_Visit(int u,int max,int g[][max+1]){
    color[u]='g';
    time++;
    d[u]=time;
    int v;

    for(int i=1;i<=max;i++){
        if(g[u][i]==1){
            v=i;
            if(color[v]=='w'){
                prev[v]=u;
                DFS_Visit(v,max,g);
            }
        }
    }
    color[u]='B';
    time++;
    f[u]=time;
}

void DFS(int max,int g[][max+1],int s){
  for(int i=1;i<=max;i++){
    color[i]='w';
    prev[i]=-1;
    f[i]=inf;
    d[i]=inf;
  }
  time=0;
  DFS_Visit(s,max,g);
  for(int i=1;i<=max;i++){
    if(color[i]=='w'){
        DFS_Visit(i,max,g);
    }
  }

}

int main(){
    printf("Enter the number of vertex and edges of the graph:\n");
    int m,n;
    scanf("%d%d",&m,&n);
    int g[m+1][m+1];
    for(int i=0;i<=m;i++){
        for(int j=0;j<=m;j++){
            g[i][j]=0;
        }
    }
    int max=m;
    printf("Enter the corresponding edges of the vertex: \n");
    for(int i=0;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        g[x][y]=1;
    }
    int s;
    printf("Enter the source node: ");
    scanf("%d",&s);
    DFS(max,g,s);

     for(int i=1;i<=max;i++){
        nodes[i].val=i;
        nodes[i].ft=f[i];
    }
    for (int j = 1; j < max; ++j) {

        for (int i = 1; i < max - j+1; ++i) {
            if (nodes[i].ft < nodes[i+1].ft){
                struct node temp = nodes[i];
                nodes[i] = nodes[i + 1];
                nodes[i + 1] = temp;
            }
        }
    }

    printf("Tropological Sort: ");

    for(int i=1;i<=max;i++)
         printf("%d ",nodes[i].val);

}
/*
6 1
6 3
3 4
4 2
5 2
5 1
*/

