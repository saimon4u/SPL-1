#include<iostream>
#include<fstream>
using namespace std;


int getTotalLine(string &filename){
    int count = 0;
    ifstream file(filename);
    if(!file.is_open()){
        cerr << "Error Opening file: " << filename << endl;
        return -1;
    }
    string line;
    while(getline(file,line)){
        count++;
    }
    file.close();
    return count;
}