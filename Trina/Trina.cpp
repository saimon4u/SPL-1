using namespace std;
double trina(vector <double> &vec){
    string path = "../Trina/file/";
    vector<vector<double>> features = extractor(path);
    vector <double> dev;
    vector <double> mean;
    // stdDeviation(features,mean,dev);
    int c = 0;
    double res = 0.0;
    for(int i=0; i<dev.size(); i++){
        ((vec[i] <= mean[i]-(1*dev[i])) || (vec[i] >= mean[i]+(1*dev[i]))) ? c=c : c++;
        // cout << endl;
        // if(detectOutliers(features[i],vec[i]))c++;
        // if(((vec[i]-mean[i])/dev[i])<=2)c++;
        // double val = cosine_similarity(features[i],vec);
        // if(val>=-1 && val <= 1)res += (val)/2;
    }
    // res /= features.size();
    res =((c*100.0)/mean.size());
    return res;
}
vector<vector<double>> getTrinaVal(){
    string path = "../Trina/file/";
    vector<vector<double>> vec = extractor(path);
    return vec;
}