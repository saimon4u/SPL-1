void findCycles(const vector<vector<int>>& graph, int node, vector<int>& visited, vector<int>& currentPath, vector<vector<int>>& cycles){
    visited[node] = 1;
    currentPath.push_back(node);
    for(int neighbor = 0; neighbor<graph[node].size(); ++neighbor){
        if(graph[node][neighbor] == 1){
            auto it = find(currentPath.begin(), currentPath.end(), neighbor);
            if(it != currentPath.end()){
                vector<int> cycle(it, currentPath.end());
                cycles.push_back(cycle);
            }
            if(!visited[neighbor]){
                findCycles(graph, neighbor, visited, currentPath, cycles);
            }
        }
    }
    currentPath.pop_back();
}

vector<vector<int>> findAllCycles(const vector<vector<int>>& graph){
    int n = graph.size();
    vector<int> visited(n, 0);
    vector<int> currentPath;
    vector<vector<int>> cycles;

    for(int node = 0; node < n; ++node){
        if(!visited[node]){
            findCycles(graph, node, visited, currentPath, cycles);
        }
    }
    return cycles;
}

double numCycle(vector<vector<int>> &graph) {
    vector<vector<int>> cycles = findAllCycles(graph);
    return cycles.size()*1.0;
}
