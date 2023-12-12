int calculateDepth(const vector<vector<int>>& graph, int startVertex){
    int vertices = graph.size();
    vector<bool> visited(vertices, false);
    stack<pair<int, int>> dfsStack;
    int maxDepth = 0;
    dfsStack.push({startVertex, 0});
    while(!dfsStack.empty()){
        pair<int, int> current = dfsStack.top();
        dfsStack.pop();
        int currentVertex = current.first;
        int currentDepth = current.second;
        visited[currentVertex] = true;
        maxDepth = max(maxDepth, currentDepth);
        for(int neighbor = 0; neighbor < vertices; ++neighbor){
            if(graph[currentVertex][neighbor] == 1 && !visited[neighbor]){
                dfsStack.push({neighbor, currentDepth + 1});
            }
        }
    }

    return maxDepth;
}

int DepthOfGraph(vector<vector<int>> &graph) {
    int startVertex = 1;
    return calculateDepth(graph, startVertex);
}
