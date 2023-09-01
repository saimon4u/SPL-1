// #include<iostream>
// #include<fstream>
// #include<regex>
// #include<set>
using namespace std;


int getTotalFunctionDefinition(string &filename,set<string> &dataType,set<string> &functionName){
    int count = 0;
    ifstream file(filename);
    if(!file.is_open()){
        cerr << "Error opening file: " << filename << std::endl;
        return -1;
    }
    string line;
    bool insideFunction = false;
    regex  reg("[^a-zA-Z0-9{}, ()]");
    bool exists = false;
    int pos;
    int nest = 0;
    int statement;
    while(getline(file, line)){
        if(line.empty())continue;
        line = regex_replace(line,reg," ");
        if(!insideFunction)
            for(auto dt: dataType)
                if(line.find(dt) != string::npos)exists = true;
        if(!insideFunction && line.find("{") != string::npos && exists && line.find("(") != string::npos && line.find(")") != string::npos){
            pos = line.find("(");
            pos--;
            if(isspace(line[pos-1]))pos--;
            int j = pos;
            while(!isspace(line[j])){
                j--;
            }
            j++;
            string funcName;
            while(j<=pos){
                funcName.push_back(line[j]);
                j++;
            }
            functionName.insert(funcName);
            insideFunction = true;
        }
        if(insideFunction && line.find("{") != string::npos && exists){
            nest++;
        }
        if(line.find("}") != string::npos && insideFunction && exists && nest != 0){
            nest --;
        }
        if(line.find("}") != string::npos && insideFunction && exists && nest==0){
            insideFunction = false;
            exists = false;
            count++;
        }
    }
    file.close();
    return count;
}