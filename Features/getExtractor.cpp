#include<bits/stdc++.h>
#include"main.cpp"
using namespace std;
void readFile(string directory,vector<string> &f){
    for(auto &entry: filesystem::directory_iterator(directory)){
        if(filesystem::is_regular_file(entry)){
            if(entry.path().extension() == ".c"){
                f.push_back(directory+"/"+entry.path().filename().string());
            }
        }
    }
}
vector<vector<bool>> giveValue(string path){
    vector <string> filename;
    readFile(path,filename);
    vector<vector<bool>> feature;
    vector<bool> four;
    for(auto f: filename){
        four.clear();
        four.push_back(spaceStartLine(f));
        four.push_back(tabStartLine(f));
        four.push_back(followingCurlyBrace(f));
        four.push_back(nextlineCurlyBrace(f));
        feature.push_back(four);
    }
    return feature;
}