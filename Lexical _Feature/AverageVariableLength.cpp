double getAverageVariableLength(set<string> &declaredVariables){
    double count = 0.0;
    double totalSize = 0.0;
    if(declaredVariables.size()==0)return 0.0;
    for(auto v: declaredVariables){
        totalSize += v.size();
    }
    count = totalSize / declaredVariables.size();
    return count;
}