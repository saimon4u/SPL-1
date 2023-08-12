void getAverageLengthOfFunctionName(double &count,set<string> &functionName){
    double totalSize = 0.0;
    for(auto fn: functionName){
        totalSize += fn.size();
    }
    count = totalSize/functionName.size();
}