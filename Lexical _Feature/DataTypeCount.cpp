// #include<iostream>
// #include<fstream>
// #include<vector>
// #include<regex>
// #include<set>
// #include"Tokenize.cpp"
using namespace std;



int getTotalDataTyep(string &filename,set<string> &dataType){
    int count = 0;
    ifstream file(filename);
    if(!file.is_open()){
        cerr << "Error Opening file: " << filename << endl;
        return -1;
    }
    string line;
    regex reg("[^a-zA-Z0-9 ]");
    while(getline(file,line)){
        if(line.empty())continue;
        vector <string> tokens = TokenizeLine(line,reg," ");
        for(auto token: tokens){
            if(dataType.find(token)!=dataType.end())count++;
        }
    }
    file.close();
    return count;
}