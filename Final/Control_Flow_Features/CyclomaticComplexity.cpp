double CyclomaticComplexity(int numNode,double numEdge,double numComponent){
    return (numEdge - numNode + (2*numComponent))*1.0;
}