

string trim(string& str) {
    // int first = str.find_first_not_of("\t");
    // int last = str.find_last_not_of("\t");
    // return str.substr(first, last - first + 1);
    int first,last;
    int i = 0;
    while(str[i]==' ')i++;
    first = i;
    i = str.length();
    while(str[i]==' ')i--;
    last = i;
    return str.substr(first,last+1);
}
int getTotalFunctionParaMeter(string& filename,set<string> &dataType){
    int count = 0;
    ifstream file(filename);
    if(!file.is_open()){
        cerr << "Error opening file: " << filename << endl;
        return -1;
    }
    string line;
    bool insideFunction = false;
    set<string> currentParameters;
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
                if(dataType.find(parameterList)!=dataType.end() || parameterList.find("=")!=string::npos || parameterList.find("<")!=string::npos || parameterList.find(">")!=string::npos || parameterList.find("\"")!=string::npos)continue;
                istringstream iss(parameterList);
                string parameter;
                while(getline(iss, parameter, ',')){
                    bool maybe = false;
                    parameter = trim(parameter);
                    for(auto dt: dataType){
                        if(parameter.find(dt)!=string::npos && parameter[0]!='('){
                            maybe = true;
                            break;
                        }
                    }
                    if(maybe && !parameter.empty() && parameter != "void"){
                        currentParameters.insert(parameter);
                    }
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
    return count;
}