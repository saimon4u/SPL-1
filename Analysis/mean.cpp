
double calculateMean(vector<double> &x){
    double sum = 0.0;
    int dataSize = x.size();
    double mean;
    for(auto val: x){
        sum += val;
    }
    mean = sum/dataSize;
    return mean;
}