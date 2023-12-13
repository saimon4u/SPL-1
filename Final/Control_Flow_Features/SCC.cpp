void dfs(int node, const vector<vector<int>>& graph, vector<bool>& visited, stack<int>& order){
    visited[node] = true;
    for(int neighbor = 0; neighbor < graph[node].size(); ++neighbor){
        if(graph[node][neighbor] == 1 && !visited[neighbor]){
            dfs(neighbor, graph, visited, order);
        }
    }
    order.push(node);
}
void dfsReverse(int node, const vector<vector<int>>& reversedGraph, vector<bool>& visited, vector<int>& component){
    visited[node] = true;
    component.push_back(node);
    for(int neighbor = 0; neighbor < reversedGraph[node].size(); ++neighbor){
        if(reversedGraph[node][neighbor] == 1 && !visited[neighbor]){
            dfsReverse(neighbor, reversedGraph, visited, component);
        }
    }
}
vector<vector<int>> findStronglyConnectedComponents(const vector<vector<int>>& graph){
    int n = graph.size();
    vector<bool> visited(n, false);
    stack<int> order;
    for(int node = 0; node < n; ++node){
        if(!visited[node]){
            dfs(node, graph, visited, order);
        }
    }
    vector<vector<int>> reversedGraph(n, vector<int>(n, 0));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            reversedGraph[j][i] = graph[i][j];
        }
    }
    fill(visited.begin(), visited.end(), false);
    vector<vector<int>> stronglyConnectedComponents;
    while(!order.empty()){
        int node = order.top();
        order.pop();
        if (!visited[node]) {
            vector<int> component;
            dfsReverse(node, reversedGraph, visited, component);
            stronglyConnectedComponents.push_back(component);
            for(int i : component){
                visited[i] = true;
            }
        }
    }
    return stronglyConnectedComponents;
}
double ConnectedComponents(vector<vector<int>> graph) {
    vector<vector<int>> stronglyConnectedComponents = findStronglyConnectedComponents(graph);
    return stronglyConnectedComponents.size()*1.0;
}
