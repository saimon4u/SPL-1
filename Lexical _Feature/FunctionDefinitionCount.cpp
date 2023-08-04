// #include<iostream>
// #include<fstream>
// #include<regex>
// #include<set>
using namespace std;


void getTotalFunctionDefinition(string &filename,int &count,set<string> &dataType){
    ifstream file(filename);
    if(!file.is_open()){
        cerr << "Error opening file: " << filename << std::endl;
        return;
    }
    string line;
    bool insideFunction = false;
    regex  reg("[^a-zA-Z0-9{}, ]");
    bool exists = false;
    while(getline(file, line)){
        if(line.empty())continue;
        line = regex_replace(line,reg," ");
        if(!insideFunction)
            for(auto dt: dataType)
                if(line.find(dt) <= 6)exists = true;
        if(!insideFunction && line.find("{") != std::string::npos && exists){
            insideFunction = true;
        }
        if(line.find("}") != std::string::npos && insideFunction && exists){
            insideFunction = false;
            exists = false;
            count++;
        }
    }
    file.close();
}