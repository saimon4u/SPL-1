double NumEdge(vector<vector<int>> &graph){
    int edge = 0;
    for(auto gr: graph){
        for(auto g: gr){
            if(g==1) edge++;
        }
    }
    return edge*1.0;
}