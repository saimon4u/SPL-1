#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define loop(i,n) for (int i = 0; i < n; i++)
using namespace std;
vector <int> graph[10];
bool visited[10];
int discovery[10];
int final[10];
void DFS(int source,int &time){
    time++;
    discovery[source] = time;
    visited[source] = true;
    for(auto child : graph[source]){
        if(!visited[child]){
            DFS(child,time);
        }
    }
    time++;
    final[source] = time;
    cout << source << "--> "<< "Discovery-->" << discovery[source] << " " << "final-->" << final[source] << endl;
}
int main(){
    int time = 0;
    int vertex,edges;
    cin >> vertex >> edges;
    for(int i=0; i<edges; ++i){
        int v1,v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
    }
    for(int i=1; i<=vertex; i++){
        if(!visited[i])
        DFS(i,time);
    }
    return 0;
}