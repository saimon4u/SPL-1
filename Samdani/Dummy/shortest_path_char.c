#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

#define N 100


int graph[N][N];
int distance[N];
bool visited[N];

void create_graph(int edges) {
    char u, v;
    int node_u, node_v;
    for(int i = 1; i <= edges; i++) {
        scanf(" %c %c", &u, &v); 
        node_u = u - 'a'+1 ; // Convert character to node number (a=1, b=2, ...)
        node_v = v - 'a'+1 ;
        graph[node_u][node_v] = 1;
        graph[node_v][node_u] = 1;   
    }
}
void print_graph(){
    for(int i=1;i<=26;i++){
        for(int j=1;j<=26;j++){
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }
}
void bfs(int start) {
    int queue[N];
    int front = 0, rear = 0;

    for(int i = 1; i <= 26; i++) {
        distance[i] = INT_MAX;
    }

    // Mark start node as visited and enqueue it with distance 0
    visited[start] = true;
    distance[start] = 0;
    queue[rear++] = start;

    // Traverse the graph
    while(front != rear) {
        int current = queue[front++];

        // Enqueue all unvisited neighbors of current node
        for(int i = 1; i <= 26; i++) {
            if(graph[current][i] == 1 && visited[i] == false) {
                visited[i] = true;
                distance[i] = distance[current] + 1;
                queue[rear++] = i;
            }
        }
    }

    printf("\nShortest distances from node %c:\n", start+'a'-1); // Convert node number to character
    for(int i = 1; i <= 26; i++) {
        if(distance[i]!=INT_MAX)
        printf("Node %c: %d\n", i+'a'-1, distance[i]); // Convert node number to character
    }
}

int main(int argc, char *argv[]) {
    int nodes, edges,beg;
    char start;
    scanf("%d %d", &nodes, &edges);

    create_graph( edges);
    //print_graph();

    printf("Enter the starting node: ");
    scanf(" %c", &start);
    beg= start - 'a' + 1; // Convert character to node number (a=1, b=2, ...)
    bfs(beg);

    return 0;
}
