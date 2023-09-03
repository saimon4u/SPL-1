#include<bits/stdc++.h>
using namespace std;
double calculatePercentile(vector<double> &x, double percentile){
    //sort
    sort(x.begin(), x.end());
    int sampleSize = x.size();
    double percentileValue;
    double rank = (sampleSize + 1) * (percentile / 100.0);

    //check whether rank is a whole number or not 
    if(rank - floor(rank) == 0.0){
        percentileValue = x[rank-1];
    }
    else{
        percentileValue = (x[rank-1] + x[rank]) / 2.0;
    }

    return percentileValue;
}