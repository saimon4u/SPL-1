// #include<iostream>
// #include<fstream>
using namespace std;

int getTotalDirective(string &filename){
    int count = 0;
    ifstream file(filename);
    if(!file.is_open()){
        cerr << "Error Opening file: " << filename << endl;
        return -1;
    }
    string line;
    while(getline(file,line)){
        if(line.empty())continue;
        if(line.find("//") == string::npos && line.find("/*") == string::npos && line.find("#include") != string::npos){
            count++;
        }
    }
    file.close();
    return count;
}