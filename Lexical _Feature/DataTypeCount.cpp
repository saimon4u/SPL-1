// #include<iostream>
// #include<fstream>
// #include<vector>
// #include<regex>
// #include<set>
// #include"Tokenize.cpp"
using namespace std;



void getTotalDataTyep(string &filename,int &count,set<string> &dataType){
    ifstream file(filename);
    if(!file.is_open()){
        cerr << "Error Opening file: " << filename << endl;
        return;
    }
    string line;
    regex reg("[^a-zA-Z0-9 ]");
    while(getline(file,line)){
        vector <string> tokens = TokenizeLine(line,reg," ");
        for(auto token: tokens){
            if(dataType.find(token)!=dataType.end())count++;
        }
    }
    file.close();
}