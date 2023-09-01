// #include<iostream>
// #include<fstream>
// #include<regex>
// #include<set>
using namespace std;

int getTotalFunctionPrototype(string &filename,set<string> dataType,set<string> &functionName){
    int count = 0;
    ifstream file(filename);
    if(!file.is_open()){
        cerr << "Error Opening file: " << filename << endl;
        return -1;
    }
    string line;
    regex reg("[^a-zA-Z0-9_]");
    while(getline(file,line)){
        if(line.empty())continue;
        bool isExists = false;
        bool isInsidePrototype = false;
        if(line.find("{")!=string::npos || line.find("printf")!=string::npos || line.find("malloc")!=string::npos || line.find("=") != string::npos)continue;
        if(line.find("(int)")!=string::npos || line.find("(double)")!=string::npos || line.find("float")!=string::npos || line.find("char")!=string::npos)continue;
        for(auto data: dataType){
            if(line.find(data)!=string::npos){
                isExists = true;
            }
        }
        if(!isExists)continue;;
        for(int i=0; i<line.length()-1;i++){
            if(line[i] == '/' && line[i + 1] == '/'){
                while(i<line.length() && line[i]!='\n')i++;
            }
            else if(line[i]=='/' && line[i + 1]=='*'){
                while(i<line.length()-1 && !(line[i]=='*' && line[i + 1]=='/'))i++;
                i++;
            }
            else if(!isInsidePrototype){
                if(line[i + 1]=='('){
                    isInsidePrototype = true;
                    int j = i;
                    while(j<line.length() && line[j]!=';')j++;
                    if(j<line.length() && line[j] == ';')count++;
                    isInsidePrototype = false;
                    line = regex_replace(line,reg," ");
                    istringstream iss(line);
                    string word;
                    iss>>word;
                    iss>>word;
                    functionName.insert(word);
                }
            }
        }
    }
    file.close();
    return count;
}