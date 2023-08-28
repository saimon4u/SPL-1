#include <stdio.h>
#include <stdbool.h>
int graph[26][26];
int discovery[26];
int finish[26];
bool visited[26];
char parent[26];
int time;
void DFS(char source)
{
    time++;
    discovery[source - 'a'] = time;
    visited[source - 'a'] = true;
    printf("%c ", source);
    for (int i = 0; i < 26; i++)
    {
        if (graph[source - 'a'][i] == 1 && visited[i] == false)
        {
            parent[i] = source;
            DFS(i + 'a');
        }
    }
    time++;
    finish[source - 'a'] = time;
}
int main()
{
    int vertex, edge;
    scanf("%d %d", &vertex, &edge);
    getchar();
    for (int i = 0; i < edge; i++)
    {
        char a, b;
        scanf("%c %c", &a, &b);
        getchar();
        graph[a - 'a'][b - 'a'] = 1;
        // graph[b-'a'][a-'a'] = 1;
    }
    int component = 0;
    for (int i = 0; i < vertex; i++)
    {
        if (!visited[i])
        {
            DFS(i + 'a');
            printf("\n");
            component++;
        }
    }
    printf("Number of tree: %d\n", component);
    for (int i = 0; i < vertex; i++)
    {
        if (discovery[i] != 0)
        {
            printf("Discovery of %c at: %d\n", i + 'a', discovery[i]);
            printf("Finish of %c at: %d\n", i + 'a', finish[i]);
        }
    }
    return 0;
}