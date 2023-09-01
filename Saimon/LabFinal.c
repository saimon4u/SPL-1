#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<malloc.h>
#include "queue.h"
#define SIZE 40
struct node{
    int data;
    int top;
    int *adjacent;
};
bool visited[SIZE];
int level[SIZE];
char Mapping[11][100] = {
        "  ",
        "Greenland",
        "China",
        "India",
        "Pakistan",
        "Iran",
        "Bangladesh",
        "Turkey",
        "USA",
        "Canada",
        "Thailand",
};
char CanVisit[10][100];
int now = 0;
void BFS(int source,struct node *graph){
    queue *q = createQueue();
    enqueue(q,source);
    visited[source] = true;
    level[source] = 0;
    while(!QueueEmpty(q)){
        int cur_v = dequeue(q);
        if(strcmp("India",Mapping[cur_v])) strcpy(CanVisit[now++],Mapping[cur_v]);
        for(int i=0; i<graph[cur_v].top; ++i){
            if(!visited[graph[cur_v].adjacent[i]]){
                enqueue(q,graph[cur_v].adjacent[i]);
                visited[graph[cur_v].adjacent[i]] = true;
                level[graph[cur_v].adjacent[i]] = level[cur_v] + 1;
            }
        }
    }
}
int main(){
    int country,connections;
    printf("Enter country and connections number: ");
    scanf("%d %d",&country,&connections);
    struct node *graph;
    graph = malloc(sizeof(struct node) * (country+1));
    for(int i=0; i<SIZE; ++i){
        graph[i].top = 0;
        graph[i].adjacent = malloc(sizeof(int) * country);
    }
    for(int i=0; i<connections; ++i){
        char s1[100],s2[100];
        // printf("Enter country 1: ");
        scanf("%s",s1);
        // printf("Enter country 2: ");
        scanf("%s",s2);
        int v1,v2;
        for(int j=1; j<11; ++j){
            if(!strcmp(s1,Mapping[j])){
                v1 = j;
            }
            if(!strcmp(s2,Mapping[j])){
                v2 = j;
            }
        }
        graph[v1].adjacent[graph[v1].top++] = v2;
        graph[v2].adjacent[graph[v2].top++] = v1;
    }
    BFS(3,graph);
    printf("\nYou can visit the following country from India: \n\n");
    for(int i=0; i<now; ++i){
        printf("%s\n",CanVisit[i]);
    }
    return 0;
}