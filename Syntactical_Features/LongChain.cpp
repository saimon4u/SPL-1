#include<bits/stdc++.h>
using namespace std;
bool inDataType(string line,set<string> &dataType){
    for(auto dt:dataType){
        if(line.find(dt) != string::npos)return true;
    }
    return false;
}
void longChainDeclaration(string &filename,int &maxVarDeclare,double &averageVarDeclare,set<string> &dataType,set<string> &variables){
    ifstream file(filename);
    if(!file.is_open()){
        cerr << "Error opening file: " << filename << endl;
        return;
    }
    string line;
    int len;
    vector <int> val;
    while(getline(file,line)){
        len = 0;
        if(line.find("(") != string::npos || line.find("{") != string::npos)continue;
        if(isDataType(line,dataType)){
            string variableName = "";
            int pos = 0;
            while(line[pos]==' ')pos++;
            while(line[pos]!=' ')pos++;
            pos++;
            while(pos < line.size()){
                if(line[pos]==',' || line[pos]==';' || line[pos]=='='){
                    if(variables.find(variableName) != variables.end()){
                        len++;
                    }
                    variableName = "";
                }
                else if(isalnum(line[pos]) || line[pos]=='_'){
                    variableName += line[pos];
                }
                pos++;
            }
        }
        if(len)val.push_back(len);
        if(maxVarDeclare < len)maxVarDeclare = len;
    }
    file.close();
    double total = 0.0;
    for(auto v: val){
        total += v;
    }
    averageVarDeclare = total/val.size();
}