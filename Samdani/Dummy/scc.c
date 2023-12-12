#include<stdio.h>
#define size 50
int graph[size][size];
int trans[size][size];
int visited[size];
int start[size],finish[size];
int time;

void DFS(int source){
    visited[source] = 1;
    time++;
    start[source] = time;
    for(int i=0; i<size; ++i){
        if(graph[source][i]==1 && visited[i]==-1){
            DFS(i);
        }
    }
    time++;
    finish[source] = time;
}
int maximum(){
    int index,max=0;
    for(int i=0; i<size; ++i){
        if(finish[i]>max){
            max=finish[i];
            index=i;
        }
    }
    finish[index]=0;
    return index;
}
void DFS2(int source){
    visited[source] = 1;
    printf("%d ",source);
    for(int i=0; i<size; ++i){
        if(trans[source][i]==1 && visited[i]==-1){
            DFS2(i);
        }
    }
}
int main(int argc,char *argv[])
{
    int vertex,edge;
    scanf("%d %d",&vertex,&edge);
    for(int i=0; i<edge; ++i){
        int v1,v2;
        scanf("%d %d",&v1,&v2);
        graph[v1][v2] = 1;
        visited[v1]=visited[v2] = -1;
    }   
    for(int i=0; i<size; ++i){
        if(visited[i]==-1){
            DFS(i);
        }
    }
    for(int i=0; i<size; i++){
        for(int j=0;j<size;j++){
            trans[i][j]=graph[j][i];
        }
    }
    for(int i=0; i<size; i++){
        if(visited[i]==1)visited[i]=-1;
    }
    printf("Strongly connected components are: \n");
    for(int i=1; i<=vertex; ++i){
        int index = maximum();
        if(visited[index]==-1){
            DFS2(index);
            printf("\n");
        }
    }
    return 0;
}