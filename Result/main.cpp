#include<bits/stdc++.h>
#include<filesystem>
#include"../Lexical _Feature/Extractor.cpp"
#include"../Yasin/Yasin.cpp"
#include"../Saimon/Saimon.cpp"
#include"../Samdani/Samdani.cpp"
// #include"../Analysis/standardDeviation.cpp"
using namespace std;
int main(){
    string path = filesystem::current_path().string();
    vector<vector<double>> vec = extractor(path,"test");
    for(int i=0; i<vec.size(); i++){
        cout << "For file : " << i+1 << endl;
        cout << "Yasin ->" << yasin(vec[i]) << endl;
        cout << "Saimon ->" << saimon(vec[i]) << endl;
        cout << "Samdani ->" << samdani(vec[i]) << endl;
        cout << endl;
    }
}