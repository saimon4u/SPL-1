using namespace std;
double shaikh(vector <double> &vec){
    string path = "../Shaikh/file/";
    vector<vector<double>> features = extractor(path);
    vector <double> dev;
    vector <double> mean;
    stdDeviation(features,mean,dev);
    int c = 0;
    for(int i=0; i<dev.size(); i++){
        ((vec[i] <= mean[i]-(1*dev[i])) || (vec[i] >= mean[i]+(1*dev[i]))) ? c=c : c++;
        // cout << endl;
        // if(detectOutliers(features[i],vec[i]))c++;
        // if(((vec[i]-mean[i])/dev[i])<=2)c++;
    }
    double res =((c*100.0)/mean.size());
    return res;
}