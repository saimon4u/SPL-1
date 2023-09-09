using namespace std;
void stdDeviation(vector<vector<double>> &feature,vector<double> &mean,vector<double> &dev){
    vector<double> vec;
    for(int i=0; i<feature[0].size(); i++){
        vec.clear();
        for(int j=0; j<feature.size(); j++){
            vec.push_back(feature[j][i]);
        }
        mean.push_back(calculateMean(vec));
        dev.push_back(calculateStandardDeviation(vec));
    }
}