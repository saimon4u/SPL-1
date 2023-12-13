#include<bits/stdc++.h>
#include<filesystem>
#include"../Lexical _Feature/Extractor.cpp"
#include "library.h"
using namespace std;

int main(){
    srand(time(0));
    string path = filesystem::current_path().string();
    vector<vector<double>> vec = extractor(path);
    for(auto ve: vec){
        for(auto v: ve){
            printf("%.2lf ",v);
        }
        cout << endl;
    }
}