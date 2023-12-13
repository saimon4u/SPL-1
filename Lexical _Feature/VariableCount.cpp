bool isDataType(string line,set<string> &DataType){
    for(auto dt: DataType){
        if(line.find(dt) != string::npos)return true;
    }
    return false;
}
bool inLibrary(string line,set<string> &library){
    for(auto l: library){
        if(line.find(l) != string::npos)return true;
    }
    return false;
}
int getTotalVariable(string& filename,set<string> &functionName,set<string> &declaredVariables,set<string> &dataType,set<string> &library){
    int count = 0;
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return -1;
    }
    string line;
    while (getline(file,line)){
        if(inLibrary(line,library))continue;
        // if(line.find("(") != string::npos || line.find("{") != string::npos)continue;
        string word = "";
        int pos = 0;
        while(pos < line.size() and line[pos]==' ')pos++;
        while(pos < line.size() and line[pos]!=' ')pos++;
        if(isDataType(line,dataType)){
            string variableName = "";
            pos ++;
            while(pos < line.size()){
                if(isalnum(line[pos]) || line[pos]=='_'){
                    variableName += line[pos];
                }
                else{
                    if(!variableName.empty() && functionName.find(variableName)==functionName.end() && dataType.find(variableName)==dataType.end() && !isdigit(variableName[0])){
                        declaredVariables.insert(variableName);
                    }
                    variableName = "";
                }
                pos++;
            }
        }
    }
    file.close();
    count = declaredVariables.size();
    return count;
}
