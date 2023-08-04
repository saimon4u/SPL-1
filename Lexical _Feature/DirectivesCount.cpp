// #include<iostream>
// #include<fstream>
using namespace std;

void getTotalDirective(string &filename,int &count){
    ifstream file(filename);
    if(!file.is_open()){
        cerr << "Error Opening file: " << filename << endl;
        return;
    }
    string line;
    while(getline(file,line)){
        if(line.empty())continue;
        if(line.find("//") == string::npos && line.find("/*") == string::npos && line.find("#include") != string::npos){
            count++;
        }
    }
}