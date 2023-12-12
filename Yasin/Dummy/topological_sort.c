#include<stdio.h>
int graph[20][20],discovery[20],previous[20],time,color[20],finish[20],stack[20],top;
void push(int value);
int pop();
void dfs(int vertice);
void dfs_visit(int vertice,int source);
int main(){
    int v1,v2,i,j,vertice,edge;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d",&vertice,&edge);
    for(i=0;i<edge;i++){
        printf("Enter vertices of edge %d: ",i+1);
        scanf("%d %d",&v1,&v2);
        graph[v1][v2]=1;
    }
    dfs(vertice);
    printf("Vertice\t\tdiscovery\tFinish\n");
    for(i=0;i<vertice;i++){
        printf("%d\t\t%d\t\t%d\n",i,discovery[i],finish[i]);
    }
    printf("\nTopological sort:\n");
    for(i=0;i<vertice;i++){
        printf("%d\t",pop());
    }
    return 0;
}
void push(int value){
    stack[top++]=value;
}
int pop(){
    return stack[--top];
}
void dfs(int vertice){
    int i;
    for(i=0;i<vertice;i++){
        previous[i]=-1;
        finish[i]=__INT_MAX__;
        discovery[i]=__INT_MAX__;
    }
    for(i=0;i<vertice;i++){
        if(color[i]==0){
            dfs_visit(vertice,i); // vertice is total vertice number. I represents vertex
        }
    }
}
void dfs_visit(int vertice,int source){
    int i;
    color[source]=1;
    discovery[source]=++time;
    for(i=0;i<vertice;i++){
        if(graph[source][i]&&!color[i]){
            previous[i]=source;
            dfs_visit(vertice,i);
        }
    }
    color[source]=2;
    push(source);
    finish[source]=++time;
}