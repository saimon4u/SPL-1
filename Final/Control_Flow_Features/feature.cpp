#include<bits/stdc++.h>
#include "Control_Flow.cpp"
#include "Cycle.cpp"
#include "DFS.cpp"
#include "SCC.cpp"
#include "Edge.cpp"
#include "CyclomaticComplexity.cpp"
#include "Fan_In.cpp"
#include "Fan_Out.cpp"
using namespace std;
int main(){
    vector<vector<int>> graph = Graph("newfile.txt");
    int num_cycle = numCycle(graph);
    int depth = DepthOfGraph(graph);
    int numNode = graph.size();
    int numEdge = NumEdge(graph);
    int numComponent = ConnectedComponents(graph);
    int cyclomatic = CyclomaticComplexity(numNode,numEdge,numComponent);
    double avgFanIn = FanIn(numEdge,numNode);
    double avgFanOut = FanOut(numEdge,numNode);
    cout << "Number of cycle in the graph: " << num_cycle << endl;
    cout << "Depth of this graph: " << depth << endl;
    cout << "Number of edge in this graph: " << numEdge << endl;
    cout << "Number of connected components: " << numComponent << endl;
    cout << "Cyclomatic Complexity of this graph: " << cyclomatic << endl;
    cout << "Average Fan In : " << avgFanIn << endl;
    cout << "Average Fan Out : " << avgFanOut << endl;
}