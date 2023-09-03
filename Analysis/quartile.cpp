#include"percentile.cpp"
vector<double> calculateQuartiles(vector<double> &x){
    
    vector<double> quartiles;
    quartiles.resize(3);

    quartiles[0] = calculatePercentile(x, 25.0);
    quartiles[1] = calculatePercentile(x, 50.0);
    quartiles[2] = calculatePercentile(x, 75.0);

    return quartiles;
}