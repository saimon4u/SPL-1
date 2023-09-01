// #include<iostream>
// #include<fstream>
// #include<set>
// #include "Tokenize.cpp"
using namespace std;


int getTotalKeyword(string &filename,set<string> &keywords){
    int count = 0;
    ifstream file(filename);
    if(!file.is_open()){
        cerr << "Error Opening file: " << filename << endl;
        return -1;
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
    return count;
}