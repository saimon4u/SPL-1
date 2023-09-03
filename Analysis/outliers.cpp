#include"quartile.cpp"
bool detectOutliers(vector<double>& x,double val){
    

    vector<double> quartiles = calculateQuartiles(x);
    double q1 = quartiles[0];
    double q3 = quartiles[2];
    
    // Calculate Inter-Quartile Range(IQR)
    double IQR = q3 - q1;
    
    // Define lower and upper bounds for outliers
    double lowerBound = q1 - 1.5 * IQR;
    double upperBound = q3 + 1.5 * IQR;
    
    // Detect outliers

    return (val>=lowerBound && val<=upperBound);
}