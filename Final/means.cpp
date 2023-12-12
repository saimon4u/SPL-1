#include <iostream>
#include <vector>
#include <cmath>
#include <random>
#include <algorithm>
#include <ctime>
using namespace std;


const int NUM_FEATURES = 20;
const int NUM_CLUSTERS = 3;


struct ProgrammerData
{
    vector<vector<double>> matrix;
    int cluster;
    int position;
};

vector<vector<double>> initializeMatrix(){
    vector<vector<double>> matrix(NUM_FEATURES, vector<double>(NUM_FEATURES));
    for(int i=0; i<NUM_FEATURES; ++i){
        for (int j=0; j<NUM_FEATURES; ++j){
            cin >> matrix[i][j];
        }
    }
    return matrix;
}
vector<vector<double>> initialize1DMatrix(){
    vector<vector<double>> matrix(1, vector<double>(NUM_FEATURES));
    for(int i=0; i<1; ++i){
        for (int j=0; j<NUM_FEATURES; ++j){
            cin >> matrix[i][j];
        }
    }
    return matrix;
}


void printMatrix(vector<vector<double>> &matrix){
    for (int i=0; i<matrix.size(); ++i){
        for (int j=0; j<matrix[i].size(); ++j){
            printf("%.2lf ",matrix[i][j]);
        }
        cout << endl;
    }
    cout << endl;
}


double euclideanDistance(vector<vector<double>> &p1,vector<vector<double>> &p2){
    double sum = 0.0;
    for(int i=0; i<p1.size(); ++i){
        for(int j=0; j<p1[i].size(); ++j){
            double diff = p1[i][j] - p2[i][j];
            sum += (diff * diff);
        }
    }
    return sqrt(sum);
}

double newEuclideanDistance(vector<vector<double>> &p1,vector<vector<double>> &p2){
    double sum = 0.0;
    for(int i=0; i<p1.size(); ++i){
        for(int j=0; j<p1[i].size(); ++j){
            double diff = p1[i][j] - p2[0][j];
            sum += (diff * diff);
        }
    }
    return sqrt(sum);
}


vector<ProgrammerData> initializeCentroids(vector<ProgrammerData> &data, int k){
    vector<ProgrammerData> centroids;
    random_device rd;
    mt19937 gen(rd());
    vector<ProgrammerData> shuffledData = data;
    shuffle(shuffledData.begin(), shuffledData.end(), gen);
    centroids.assign(shuffledData.begin(), shuffledData.begin() + k);
    int pos = 1;
    for(auto &cen: centroids){
        cen.cluster = pos++;
    }
    return centroids;
}


void assignToClusters(vector<ProgrammerData>& data,vector<ProgrammerData>& centroids){
    for(auto &point : data){
        double minDistance = numeric_limits<double>::max();
        for(auto &centroid : centroids){
            double distance = euclideanDistance(point.matrix, centroid.matrix);
            if(distance < minDistance){
                minDistance = distance;
                point.cluster = centroid.cluster;
            }
        }
    }
}

void updateCentroids(vector<ProgrammerData>& centroids,vector<ProgrammerData>& data){
    for(auto &centroid : centroids){
        for(auto &cen: centroid.matrix){
            for(auto &c: cen){
                c = 0.0;
            }
        }
        int clusterSize = 0;
        for(auto &point : data){
            if(point.cluster == centroid.cluster){
                clusterSize++;
                for(int i=0; i<NUM_FEATURES; ++i){
                    for(int j=0; j<NUM_FEATURES; ++j){
                        centroid.matrix[i][j] += point.matrix[i][j];
                    }
                }
            }
        }
        if(clusterSize > 0){
            for(int i=0; i<NUM_FEATURES; ++i){
                for(int j=0; j<NUM_FEATURES; ++j){
                    centroid.matrix[i][j] /= clusterSize;
                }
            }
        }
    }
}

bool clustersChanged(vector<ProgrammerData>& oldCentroids,vector<ProgrammerData>& newCentroids){
    if(oldCentroids.empty()) return true;
    for(int i=0; i<NUM_CLUSTERS; ++i) if(euclideanDistance(oldCentroids[i].matrix,newCentroids[i].matrix) > 10e-6) return true;
    return false;
}

vector<ProgrammerData> kMeansClustering(vector<ProgrammerData> &data,vector<ProgrammerData> &copyCentoroids){
    vector<ProgrammerData> centroids = initializeCentroids(data, NUM_CLUSTERS);
    vector<ProgrammerData> oldCentroids;
    while (clustersChanged(oldCentroids, centroids)){
        oldCentroids = centroids;
        assignToClusters(data, centroids);
        updateCentroids(centroids, data);
    }
    for(int i=0; i<centroids.size(); i++){
        for(int j=0; j<centroids[i].matrix.size(); j++){
            for(int k=0; k<centroids[i].matrix[j].size(); k++){
                copyCentoroids[i].matrix[j][k] = centroids[i].matrix[j][k];
            }
        }
        copyCentoroids[i].cluster = centroids[i].cluster;
        copyCentoroids[i].position = centroids[i].position;
    }
    return data;
}

bool compare(ProgrammerData a,ProgrammerData b){
    return a.cluster<b.cluster;
}

void addNewDataToCluster(ProgrammerData &data,vector<ProgrammerData>& centroids){
    double minDistance = numeric_limits<double>::max();
    for(auto &centroid : centroids){
        double distance = newEuclideanDistance(centroid.matrix, data.matrix);
        if(distance < minDistance){
            minDistance = distance;
            data.cluster = centroid.cluster;
        }
    }
}

int main(){
    freopen("matrix.txt","r",stdin);
    srand(time(0));
    vector<ProgrammerData> programmerData(10);
    int pos = 1;
    for(auto &pd: programmerData){
        pd.position = pos++;
    }
    for (int i=0; i<10; ++i){
        programmerData[i].matrix = initializeMatrix();
    }

    vector<ProgrammerData> centroids = initializeCentroids(programmerData, NUM_CLUSTERS);
    vector<ProgrammerData> clusteredData = kMeansClustering(programmerData,centroids);
    // sort(clusteredData.begin(),clusteredData.end(),compare);
    ProgrammerData data;
    data.matrix = initialize1DMatrix();
    data.position = 20;
    for(auto dat: data.matrix){
        for(auto d: dat){
            cout << d << " ";
        }
        cout << endl;
    }
    // addNewDataToCluster(data,centroids);
    // cout << data.cluster << endl;
    // for(auto cl: clusteredData){
    //     cout << cl.position << " " << cl.cluster <<  endl;
    // }
}