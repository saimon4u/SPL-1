// #include<iostream>
// #include<fstream>
// #include<regex>
// #include<set>
using namespace std;


void getTotalFunctionDefinition(string &filename,int &count,set<string> &dataType,set<string> &functionName,double &averageStatement){
    ifstream file(filename);
    if(!file.is_open()){
        cerr << "Error opening file: " << filename << std::endl;
        return;
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
        if(insideFunction && nest != 0){
            statement++;
        }
        if(line.find("}") != string::npos && insideFunction && exists && nest==0){
            insideFunction = false;
            exists = false;
            count++;
            statement--;
        }
    }
    averageStatement = (double)statement/count;
    file.close();
}