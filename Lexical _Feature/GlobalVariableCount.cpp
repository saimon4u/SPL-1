int getTotalGlobalVariable(string& filename,set<string> &dataType,set<string> &functionName){
    int count = 0;
    ifstream file(filename);
    if(!file.is_open()){
        cerr << "Error opening file: " << filename << endl;
        return -1;
    }
    string line;
    unordered_set <string> declaredVariables;
    while(getline(file,line)){
        if(line.find("void main()") != string::npos || line.find("int main()") != string::npos)break;
        // istringstream iss(line);
        // string word;
        // if(iss >> word && (word == "int" || word == "char" || word == "float" || word == "double" ||
        //                     word == "long" || word == "short" || word == "unsigned" || word == "signed" ||
        //                     word == "void" || word == "static" || word == "const")){
        //     while(iss >> word){
        //         if(word.find("(")!=string::npos)break;
        //         string variableName = "";
        //         for(char c : word){
        //             if(isalnum(c) || c == '_'){
        //                 variableName += c;
        //             }
        //             else{
        //                 break;
        //             }
        //         }
        //         if(!variableName.empty()){
        //             declaredVariables.insert(variableName);
        //             break;
        //         }
        //     }
        // }
        if(line.find("(") != string::npos || line.find("{") != string::npos)continue;
        string word = "";
        int pos = 0;
        while(line[pos]!=' ')line[pos++];
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

