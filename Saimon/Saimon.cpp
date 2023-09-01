#include<bits/stdc++.h>
#include"../Lexical _Feature/Extractor.cpp"
#include"../Analysis/standardDeviation.cpp"
#include<filesystem>
using namespace std;
int main(){
    string path = filesystem::current_path().string();
    vector<vector<double>> features = extractor(path);
    // for(auto f: features){
    //     for(auto v: f){
    //         printf("%.1lf ",v);
    //     }
    //     cout << endl;
    // }
    vector <double> dev;
    vector <double> mean;
    for(int i=1; i<features.size(); i++){
        mean.push_back(calculateMean(features[i]));
        dev.push_back(calculateStandardDeviation(features[i]));
    }
    for(int i=0; i<dev.size(); i++){
        cout << setprecision(2) << "mean = " << mean[i] << '\t' << "dev = " << dev[i] << endl;
    }
}