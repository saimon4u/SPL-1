void getTotalVariable(string& filename,int &count,set<string> &functionName,set<string> &declaredVariables){
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }
    string line;
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
    cout << endl;
    file.close();
    count = declaredVariables.size();
}
