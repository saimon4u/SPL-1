#include<stdio.h>
#include<stdbool.h>
#define MAX 50
int graph[MAX][MAX];
int trans[MAX][MAX];
int finish[MAX];
int parent[MAX];
int time;
bool visited[MAX];
void swap(int *a, int *b){
        *a = (*a)^(*b);
        *b = (*a)^(*b);
        *a = (*a)^(*b);
}
void DFS(int source,int vertex){
    time++;
    visited[source] = true;
    for(int i=1; i<=vertex; ++i){
        if(graph[source][i] == 1 && visited[i] == false){
            DFS(i,vertex);
        }
    }
    time++;
    finish[source] = time;
}
void DFS2(int source,int vertex){
    visited[source] = true;
    printf("%d  ",source);
    for(int i=1; i<=vertex; ++i){
        if(trans[source][i] == 1 && visited[i] == false){
            DFS2(i,vertex);
        }
    }
}
int maximum(){
    int max = 0;
    int index;
    for(int i=0; i<MAX; ++i){
        if(max<=finish[i]){
            max = finish[i];
            index = i;
        }
    }
    finish[index] = 0;
    return index;
}
int main(){
    int vertex,edge;
    scanf("%d %d",&vertex,&edge);
    for(int i=0; i<edge; i++){
        int v1,v2;
        scanf("%d %d",&v1,&v2);
        graph[v1][v2] = 1;
    }
    for(int i=1; i<=vertex; ++i){
        if(!visited[i]){
            DFS(i,vertex);
        }
    }
    // for(int i=1; i<=vertex; i++){
    //     printf("%d F-> %d\n",i,finish[i]);
    // }
    for(int i=1; i<=vertex; ++i){
        for(int j=1; j<=vertex; ++j){
            trans[i][j] = graph[j][i];
        }
    }
    for(int i=0; i<MAX; ++i){
        visited[i] = false;
    }
    printf("Strongly connected components are: \n");
    for(int i=1; i<=vertex; i++){
        int index = maximum();
        if(!visited[index]){
            DFS2(index,vertex);
            printf("\n");
        }
    }
    return 0;
}