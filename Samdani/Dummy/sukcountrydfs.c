#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 10

#define white 0
#define grey  1
#define black -1

int graph[N][N];
int level[N];
int visited[N];
int parent[N]; // store the parent of each visited vertex

char manusherName[N][N];

int manusherNamerIndex(char name[])
{
    for(int i =0;i<N;i++)
    {
        if(strcmp(manusherName[i],name)== 0)
        {
            return i;
        }
    }
    return -1; // Return -1 if name not found
}

struct queue
{
    int item[N];
    int front;
    int rear;
};

struct queue* createQueue()
{
    struct queue* q = malloc(sizeof(struct queue));
    q->front = -1;
    q->rear = -1;
    return q;
};

int isEmpty(struct queue* q)
{
    if(q->rear == -1)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct queue* q,int vertex)
{
    if(q->rear == N-1)
    {
        printf("Queue overflow!\n");
        return;
    }
    if(q->front == -1)
    {
        q->front = 0;
    }
    q->rear++;
    q->item[q->rear] = vertex;
}

int dequeue(struct queue* q)
{
    if(isEmpty(q))
    {
        printf("Queue underflow!\n");
        return -1;
    }
    int item = q->item[q->front];
    q->front++;
    if(q->front > q->rear)
    {
        q->front = q->rear = -1;
    }
    return item;
}

void bfs(int source, int destination)
{
    struct queue* q = createQueue();
    enqueue(q, source);
    visited[source] = grey;
    level[source] = 0;
    parent[source] = -1;

    while(!isEmpty(q))
    {
        int currentVertex = dequeue(q);
        if(currentVertex == destination)
        {
            break;
        }

        for(int i = 0; i < N; i++)
        {
            if(graph[currentVertex][i] && visited[i] == white)
            {
                visited[i] = grey;
                level[i] = level[currentVertex] + 1;
                parent[i] = currentVertex;
                enqueue(q, i);
            }
        }
        visited[currentVertex] = black;
    }
}

void printShortestPath(int source, int destination)
{
    int shortestPath[N];
    int pathIndex = 0;
    int current = destination;

    while(current != -1)
    {
        shortestPath[pathIndex++] = current;
        current = parent[current];
    }

    if(shortestPath[pathIndex - 1] != source)
    {
        printf("Path doesn't exist.\n");
        return;
    }
    else
    {
        printf("Shortest path from %d to %d: ", source, destination);
        for(int i = pathIndex - 1; i >= 0; i--)
        {
            printf("%d ", shortestPath[i]);
        }
        printf("\n");
    }
}

int main()
{
    int num;
    printf("How many people are in this social media? ");
    scanf("%d", &num);
    getchar();

    for(int i = 0; i < num; i++)
    {
        printf("Enter the name of person %d: ", i + 1);
        scanf("%s", manusherName[i]);
    }

    int edges;
    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    getchar();

    for(int j = 0; j < edges; j++)
    {
        char str1[30];
        char str2[30];
        printf("Enter who is friends with whom: ");
        scanf("%s %s", str1, str2);
        int n = manusherNamerIndex(str1);
        int m = manusherNamerIndex(str2);
        if(n != -1 && m != -1)
        {
            graph[n][m] = graph[m][n] = 1;
        }
        else
        {
            printf("Invalid names! Please enter existing names.\n");
            j--;
        }
    }

    char sr[30], ds[30];
    printf("Enter the source: ");
    scanf("%s", sr);
    int source = manusherNamerIndex(sr);

    printf("Enter the destination: ");
    scanf("%s", ds);
    int destination = manusherNamerIndex(ds);

    bfs(source, destination);
    printShortestPath(source, destination);

    return 0;
}


