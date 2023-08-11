void getTotalVariable(string& filename,int &count,set<string> &functionName) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }
    string line;
    unordered_set<string> declaredVariables;
    while (getline(file,line)) {
        istringstream iss(line);
        string word;
        while (iss >> word){
            if (word == "int" || word == "char" || word == "float" || word == "double" || word == "long" ||
                word == "short" || word == "unsigned" || word == "signed"){
                if(iss >> word){
                    string variableName = "";
                    for(char c : word){
                        if(isalnum(c) || c == '_'){
                            variableName += c;
                        }
                        else{
                            break;
                        }
                    }
                    if(!variableName.empty() && functionName.find(variableName)==functionName.end()){
                        declaredVariables.insert(variableName);
                    }
                }
            }
        }
    }
    file.close();
    count = declaredVariables.size();
}
