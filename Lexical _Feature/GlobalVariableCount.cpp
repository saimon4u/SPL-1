void getTotalGlobalVariable(string& filename,int &count) {
    ifstream file(filename);
    if(!file.is_open()){
        cerr << "Error opening file: " << filename << endl;
        return;
    }
    string line;
    unordered_set <string> declaredVariables;
    while(getline(file,line)){
        if(line.find("void main()") != string::npos || line.find("int main()") != string::npos)break;
        istringstream iss(line);
        string word;
        if(iss >> word && (word == "int" || word == "char" || word == "float" || word == "double" ||
                            word == "long" || word == "short" || word == "unsigned" || word == "signed" ||
                            word == "void" || word == "static" || word == "const")){
            while(iss >> word){
                if(word.find("(")!=string::npos)break;
                string variableName = "";
                for(char c : word){
                    if(isalnum(c) || c == '_'){
                        variableName += c;
                    }
                    else{
                        break;
                    }
                }
                if(!variableName.empty()){
                    declaredVariables.insert(variableName);
                    break;
                }
            }
        }
    }
    file.close();
    count = declaredVariables.size();
}

