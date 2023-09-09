#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
double cosine_similarity(vector<double>& vec1, vector<double>& vec2){
    if (vec1.size() != vec2.size()){
        throw invalid_argument("Vectors must have the same dimensionality.");
    }
    double dot_product = 0.0;
    double magnitude_vec1 = 0.0;
    double magnitude_vec2 = 0.0;

    for(int i = 0; i < vec1.size(); ++i){
        dot_product += vec1[i] * vec2[i];
        magnitude_vec1 += vec1[i] * vec2[i];
        magnitude_vec2 += vec2[i] * vec2[i];
    }

    magnitude_vec1 = sqrt(magnitude_vec1);
    magnitude_vec2 = sqrt(magnitude_vec2);

    return dot_product / (magnitude_vec1 * magnitude_vec2);
}
