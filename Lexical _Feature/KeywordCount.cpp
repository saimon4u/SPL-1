// #include<iostream>
// #include<fstream>
// #include<set>
// #include "Tokenize.cpp"
using namespace std;


void getTotalKeyword(string &filename,int &count,set<string> &keywords){
    ifstream file(filename);
    if(!file.is_open()){
        cerr << "Error Opening file: " << filename << endl;
        return;
    }
    string line;
    regex  reg("[^a-zA-Z0-9 ]");
    while(getline(file,line)){
        if(line.empty())continue;
        vector <string> tokens = TokenizeLine(line,reg," ");
        for(auto token: tokens){
            if(keywords.find(token)!=keywords.end())count++;
        }
    }
    file.close();
}