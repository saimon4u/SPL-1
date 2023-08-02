// #include<iostream>
// #include<fstream>
using namespace std;


void getTotalLine(string &filename,int &count){
    ifstream file(filename);
    if(!file.is_open()){
        cerr << "Error Opening file: " << filename << endl;
        return;
    }
    string line;
    while(getline(file,line)){
        count++;
    }
    file.close();
}