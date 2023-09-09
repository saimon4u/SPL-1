#include<bits/stdc++.h>
#include<fstream>
using namespace std;
bool tabStartLine(string &filename){
    ifstream file(filename);
    if(!file.is_open()){
        cerr << "Error opening file: " << filename << endl;
        return 0;
    }
    string line;
    while(getline(file,line)){
        if(line.empty())continue;
        if((line[0]==' ' && line[1]==' ' && line[2]==' ')  || line[0]=='\t')return true;
    }
    return false;
}