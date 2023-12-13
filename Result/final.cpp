#include<bits/stdc++.h>
#include<filesystem>
#include"../Lexical _Feature/Extractor.cpp"
#include "library.h"
using namespace std;


const int NUM_FEATURES = 34;
const int NUM_CLUSTERS = 4;
const int NUM_FILES = 15;

struct ProgrammerData
{
    vector<vector<double>> matrix;
    int cluster;
    int position;
    string name;
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
    double val = 0.0;
    for(int i=0; i<p1.size(); ++i){
        for(int j=0; j<p1[i].size(); ++j){
            double diff = p1[i][j] - p2[0][j];
            sum += (diff * diff);
        }
        val += sqrt(sum);
    }
    return val/NUM_FILES;
}


// vector<ProgrammerData> initializeCentroids(vector<ProgrammerData> &data, int k){
//     vector<ProgrammerData> centroids;
//     random_device rd;
//     mt19937 gen(rd());
//     vector<ProgrammerData> shuffledData = data;
//     shuffle(shuffledData.begin(), shuffledData.end(), gen);
//     centroids.assign(shuffledData.begin(), shuffledData.begin() + k);
//     // centroids.assign(shuffledData.begin(),shuffledData.begin()+k);
//     int pos = 1;
//     for(auto &cen: centroids){
//         cen.cluster = pos++;
//     }
//     return centroids;
// }



vector<ProgrammerData> initializeCentroids(vector<ProgrammerData> &data, int k){
    vector<ProgrammerData> centroids;
    random_device rd;
    mt19937 gen(rd());
    
    centroids.push_back(data[0]);
    for (int i = 1; i < k; ++i) {
        vector<double> distances(data.size(), numeric_limits<double>::max());
        for (int j = 0; j < data.size(); ++j) {
            for (auto &cen : centroids) {
                double distance = euclideanDistance(data[j].matrix, cen.matrix);
                distances[j] = min(distances[j], distance);
            }
        }

        // Select the next centroid with probability proportional to distance squared
        discrete_distribution<int> distribution(distances.begin(), distances.end());
        int nextCentroidIndex = distribution(gen);
        centroids.push_back(data[nextCentroidIndex]);
    }
    shuffle(centroids.begin(), centroids.end(), gen);
    int pos = 1;
    for (auto &cen : centroids) {
        cen.cluster = pos++;
    }

    return centroids;
}









void assignToClusters(vector<ProgrammerData>& data,vector<ProgrammerData>& centroids){
    for(auto &point : data){
            // cout << "minDistance" << endl;
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
                for(int i=0; i<NUM_FILES; ++i){
                    for(int j=0; j<NUM_FEATURES; ++j){
                        centroid.matrix[i][j] += point.matrix[i][j];
                    }
                }
            }
        }
        if(clusterSize > 0){
            for(int i=0; i<NUM_FILES; ++i){
                for(int j=0; j<NUM_FEATURES; ++j){
                    centroid.matrix[i][j] /= clusterSize;
                }
            }
        }
    }
}

bool clustersChanged(vector<ProgrammerData>& oldCentroids,vector<ProgrammerData>& newCentroids){
    if(oldCentroids.empty()){
        return true;
    }
    for(int i=0; i<NUM_CLUSTERS; ++i) if(euclideanDistance(oldCentroids[i].matrix,newCentroids[i].matrix) > 10e-4) return true;
    return false;
}

vector<ProgrammerData> kMeansClustering(vector<ProgrammerData> &data,vector<ProgrammerData> &copyCentoroids){
    vector<ProgrammerData> centroids = initializeCentroids(data, NUM_CLUSTERS);

    vector<ProgrammerData> oldCentroids;
    while(clustersChanged(oldCentroids, centroids)){
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
    srand(time(0));

    string path = filesystem::current_path().string();
    vector<vector<double>> vec = extractor(path);
    vector<ProgrammerData> programmerData(8);
    int pos = 1;
    for(auto &pd: programmerData){
        pd.position = pos++;
    }


    programmerData[0].matrix = getYasinVal();
    programmerData[0].name = "Yasin";
    programmerData[1].matrix = getSaimonVal();
    programmerData[1].name = "Saimon";
    programmerData[2].matrix = getSamdaniVal();
    programmerData[2].name = "Samdani";
    programmerData[3].matrix = getNandanVal();
    programmerData[3].name = "Nandan";
    programmerData[4].matrix = getNasirVal();
    programmerData[4].name = "Nasir";
    programmerData[5].matrix = getShaikhVal();
    programmerData[5].name = "Shaikh";
    programmerData[6].matrix = getTrinaVal();
    programmerData[6].name = "Trina";
    programmerData[7].matrix = getTashrifVal();
    programmerData[7].name = "Tashrif";

    vector<ProgrammerData> centroids = initializeCentroids(programmerData, NUM_CLUSTERS);
    // cout << "hello" << endl;

    vector<ProgrammerData> clusteredData = kMeansClustering(programmerData,centroids);
    // cout << "bye" << endl;
    sort(clusteredData.begin(),clusteredData.end(),compare);
    const int numNewData = 1;
    vector<ProgrammerData> data(numNewData);


    for(int i=0; i<numNewData; i++){
        data[i].position = pos++;
        data[i].name = "File->" + to_string(data[i].position);
        vector<double> matrix(NUM_FEATURES);
        for(int k=0; k<vec[i].size(); k++){
            matrix[k] = vec[i][k];
        }
        data[i].matrix.push_back(matrix);
        addNewDataToCluster(data[i],centroids);
    }
    cout << "Your test file is in cluster -> " << data[0].cluster << endl << endl;
    for(int i=0; i<numNewData; i++){
        cout << "Expected Programmer's are: " << endl;
        for(auto cl: clusteredData){
            if(data[i].cluster == cl.cluster){
                cout << cl.name << endl;
            }
        }
        cout << endl;
    }
}