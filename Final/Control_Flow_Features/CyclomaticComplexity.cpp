int CyclomaticComplexity(int numNode,int numEdge,int numComponent){
    return (numEdge - numNode + (2*numComponent));
}