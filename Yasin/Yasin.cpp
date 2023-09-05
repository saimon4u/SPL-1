#include<bits/stdc++.h>
// #include"../Lexical _Feature/Extractor.cpp"
#include"../Analysis/standardDeviation.cpp"
#include"../Analysis/outliers.cpp"
#include<filesystem>
using namespace std;
double yasin(vector <double> &vec){
    string path = "../Yasin/file/";
    vector<vector<double>> features = extractor(path,"");
    vector <double> dev;
    vector <double> mean;
    for(int i=1; i<features.size(); i++){
        mean.push_back(calculateMean(features[i]));
        dev.push_back(calculateStandardDeviation(features[i]));
    }
    int c = 0;
    for(int i=0; i<dev.size(); i++){
        // cout << setprecision(2) << "mean = " << mean[i]-dev[i] << '\t' << "dev = " << mean[i] + dev[i] << '\t' << tausif[i][0] << '\t';
        // ((vec[i] <= mean[i]-(3*dev[i])) || (vec[i] >= mean[i]+(3*dev[i]))) ? c=c : c++;
        // cout << endl;
        // if(detectOutliers(features[i],vec[i]))c++;
        if(((vec[i]-mean[i])/(dev[i])/sqrt(dev.size()))<=2)c++;
    }
    double res =((c*100.0)/mean.size());
    return res;
}