

string trim(string& str) {
    int first = str.find_first_not_of("\t");
    int last = str.find_last_not_of("\t");
    return str.substr(first, last - first + 1);
}
void getTotalFunctionParaMeter(string& filename,int &count,set<string> &dataType){
    ifstream file(filename);
    if(!file.is_open()){
        cerr << "Error opening file: " << filename << endl;
        return;
    }
    string line;
    bool insideFunction = false;
    vector<string> currentParameters;
    while(getline(file,line)){
        if(line.empty())continue;
        line = trim(line);
        if(line.find("(") != string::npos && line.find(")") != string::npos){
            insideFunction = true;
            currentParameters.clear();
            int startPos = line.find("(");
            int endPos = line.find(")");
            if(startPos != string::npos && endPos != string::npos && startPos < endPos){
                string parameterList = line.substr(startPos + 1, endPos - startPos - 1);
                istringstream iss(parameterList);
                string parameter;
                while(getline(iss, parameter, ',')){
                    bool maybe = false;
                    parameter = trim(parameter);
                    for(auto dt: dataType){
                        if(parameter.find(dt)!=string::npos){
                            maybe = true;
                            break;
                        }
                    }
                    if(maybe && !parameter.empty() && parameter != "void")currentParameters.push_back(parameter);
                }
                count += currentParameters.size();
            }
        }
        else if(insideFunction){
            if(line.find("}") != string::npos){
                insideFunction = false;
            }
            else{
                while(getline(file,line)){
                    line = trim(line);
                    if(line.find("}") != string::npos){
                        insideFunction = false;
                        break;
                    }
                }
            }
        }
    }
    file.close();
}