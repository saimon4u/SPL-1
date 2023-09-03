#include<bits/stdc++.h>
#include"../Lexical _Feature/Extractor.cpp"
#include"../Analysis/standardDeviation.cpp"
#include"../Analysis/outliers.cpp"
#include<filesystem>
using namespace std;
int main(){
    string path = filesystem::current_path().string() + "/file";
    vector<vector<double>> features = extractor(path);
    vector<vector<double>> tausif = extractor("../../");
    for(auto f: features){
        for(auto v: f){
            printf("%.1lf ",v);
        }
        cout << endl;
    }
    vector <double> dev;
    vector <double> mean;
    for(int i=1; i<features.size(); i++){
        mean.push_back(calculateMean(features[i]));
        dev.push_back(calculateStandardDeviation(features[i]));
    }
    int c = 0;
    for(int i=0; i<dev.size(); i++){
        // cout << setprecision(2) << "mean = " << mean[i]-dev[i] << '\t' << "dev = " << mean[i] + dev[i] << '\t' << tausif[i][0] << '\t';
        // ((tausif[i][0] <= mean[i]-(3*dev[i])) || (tausif[i][0] >= mean[i]+(3*dev[i]))) ? c=c : c++;
        // cout << endl;
        // if(detectOutliers(features[i],tausif[i][0]))c++;
        // if(((tausif[i][0]-mean[i])/dev[i])<=3)c++;
    }
    // cout << ((c*100.0)/mean.size()) << endl;
    // string f[2];
    // f[0] = "../tausif.c";
    // f[1] = "../tausif2.c";
    // for(auto f: tausif){
    //     for(auto v: f){
    //         printf("%lf ",v);
    //     }
    //     cout << endl;
    // }
}