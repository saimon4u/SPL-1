double getAverageLengthOfFunctionName(set<string> &functionName){
    double count = 0.0;
    double totalSize = 0.0;
    for(auto fn: functionName){
        totalSize += fn.size();
    }
    count = totalSize/functionName.size();
    return count;
}