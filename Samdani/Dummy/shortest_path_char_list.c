#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

#define N 27

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* graph[N];

int distance[N];
bool visited[N];


void create_graph(int edges) {
    char u, v;
    int node_u, node_v;

    // Initialize the graph with empty linked lists
    for (int i = 1; i <N; i++) {
        graph[i] = NULL;
    }

    // Add edges to the graph
    for (int i = 1; i <= edges; i++) {
        scanf(" %c %c", &u, &v); 
        node_u = u - 'a' + 1; // Convert character to node number (a=1, b=2, ...)
        node_v = v - 'a' + 1;
        
        // Add node_v to the linked list of node_u
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->vertex = node_v;
        newNode->next = graph[node_u];
        graph[node_u] = newNode;

        // Add node_u to the linked list of node_v
        newNode = (Node*)malloc(sizeof(Node));
        newNode->vertex = node_u;
        newNode->next = graph[node_v];
        graph[node_v] = newNode;
    }
}


void print_graph(){
    for(int i=1;i<=26;i++){
        printf("%d: ",i);
        for(Node* curr = graph[i]; curr != NULL; curr = curr->next){
            printf("%c ", curr->vertex+'a'-1); // Convert node number to character
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
        for(Node* curr = graph[current]; curr != NULL; curr = curr->next){
            int i = curr->vertex;
            if(visited[i] == false) {
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

    create_graph(edges);
    print_graph();

    printf("Enter the starting node: ");
    scanf(" %c", &start);
    beg= start - 'a' + 1; // Convert character to node number (a=1, b=2, ...)
    bfs(beg);

    return 0;
}
