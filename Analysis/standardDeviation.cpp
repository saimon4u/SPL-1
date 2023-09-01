#include"mean.cpp"
double calculateStandardDeviation(vector<double> &x){
    int dataSize = x.size();
    double mean = calculateMean(x);
    double sumSquaredValue = 0.0;
    double variance;
    for(auto val: x){
        sumSquaredValue += val*val;
    }
    variance = (sumSquaredValue - (dataSize*mean*mean))/(dataSize-1);
    return sqrt(variance);
}