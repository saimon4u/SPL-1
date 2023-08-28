#include<bits/stdc++.h>
#include"../Lexical _Feature/main.cpp"
using namespace std;


void readFile(string directory,vector<string> &fileName){
    for(auto &entry: filesystem::directory_iterator(directory)){
        if(filesystem::is_regular_file(entry)){
            if(entry.path().extension() == ".c"){
                fileName.push_back(entry.path().filename().string());
            }
        }
    }
}



int main(){
    string directoryPath = filesystem::current_path().string();
    vector <string> fileName;
    readFile(directoryPath,fileName);
    int x = 0;
    for(auto f: fileName){
        getTotalLine(f,x);
    }
}