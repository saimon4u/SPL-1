void getAverageVariableLength(set<string> &declaredVariables,double &count){
    double totalSize = 0.0;
    for(auto v: declaredVariables){
        totalSize += v.size();
    }
    count = totalSize / declaredVariables.size();
}