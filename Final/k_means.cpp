#include <iostream>
#include <vector>
#include <cmath>
#include <random>
#include <algorithm>
#include <ctime>
const int NUM_FEATURES = 20;
const int NUM_CLUSTERS = 5;

using DataMatrix = std::vector<std::vector<double>>;

struct ProgrammerData
{
    DataMatrix data; // 2D vector where rows represent files and columns represent features
    int cluster;     // Assigned cluster
};

double euclideanDistance(const DataMatrix &p1, const DataMatrix &p2)
{
    double sum = 0.0;
    // std:: cout << p1.size() << " " << p2.size() << std:: endl;
    for (int i = 0; i < p1.size(); ++i)
    {
        for (int j = 0; j < p1[i].size(); ++j)
        {
            double diff = p1[i][j] - p2[i][j];
            sum += diff * diff;
        }
    }
    return std::sqrt(sum);
}

std::vector<ProgrammerData> initializeCentroids(const std::vector<ProgrammerData> &data, int k)
{
    std::vector<ProgrammerData> centroids;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::vector<ProgrammerData> shuffledData = data;
    std::shuffle(shuffledData.begin(), shuffledData.end(), gen);
    centroids.assign(shuffledData.begin(), shuffledData.begin() + k);
    return centroids;
}

void assignToClusters(std::vector<ProgrammerData>& data, const std::vector<ProgrammerData>& centroids) {
    for (ProgrammerData& point : data) {
        double minDistance = std::numeric_limits<double>::max();
        for (const ProgrammerData& centroid : centroids) {
            double distance = euclideanDistance(point.data, centroid.data);
            if (distance < minDistance) {
                minDistance = distance;
                point.cluster = centroid.cluster;
            }
        }
    }
}

void updateCentroids(std::vector<ProgrammerData>& centroids, const std::vector<ProgrammerData>& data) {
    for (ProgrammerData& centroid : centroids) {
        std::fill(centroid.data.begin(), centroid.data.end(), 0.0);
        int clusterSize = 0;

        for (const ProgrammerData& point : data) {
            if (point.cluster == centroid.cluster) {
                clusterSize++;
                for (int i = 0; i < NUM_FEATURES; ++i) {
                    for (int j = 0; j < NUM_FEATURES; ++j) {
                        centroid.data[i][j] += point.data[i][j];
                    }
                }
            }
        }

        if (clusterSize > 0) {
            for (int i = 0; i < NUM_FEATURES; ++i) {
                for (int j = 0; j < NUM_FEATURES; ++j) {
                    centroid.data[i][j] /= clusterSize;
                }
            }
        }
    }
}

bool clustersChanged(const std::vector<ProgrammerData>& oldCentroids, const std::vector<ProgrammerData>& newCentroids) {
    if (oldCentroids.empty()) {
        return true; // If old centroids are empty, consider clusters changed
    }

    for (int i = 0; i < NUM_CLUSTERS; ++i) {
        if (euclideanDistance(oldCentroids[i].data, newCentroids[i].data) > 1e-6) {
            return true;
        }
    }
    return false;
}


std::vector<ProgrammerData> kMeansClustering(std::vector<ProgrammerData> &data)
{
    std::vector<ProgrammerData> centroids = initializeCentroids(data, NUM_CLUSTERS);
    std::vector<ProgrammerData> oldCentroids;
    // for(auto c: centroids){
    //     std:: cout << c.cluster << std:: endl;
    // }
    while (clustersChanged(oldCentroids, centroids))
    {
        // std:: cout << clustersChanged(oldCentroids,centroids) << std:: endl;
        oldCentroids = centroids;
        assignToClusters(data, centroids);
        updateCentroids(centroids, data);
    }

    return data;
}

// Function to initialize a matrix with random values
DataMatrix initializeMatrix()
{
    DataMatrix matrix(NUM_FEATURES, std::vector<double>(NUM_FEATURES));

    for (int i = 0; i < NUM_FEATURES; ++i)
    {
        for (int j = 0; j < NUM_FEATURES; ++j)
        {
            matrix[i][j] = static_cast<double>(rand()) / RAND_MAX; // Random value between 0 and 1
        }
    }

    return matrix;
}


void printMatrix(DataMatrix matrix)
{
    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = 0; j < matrix[i].size(); ++j)
        {
            printf("%.2lf ",matrix[i][j]);
        }
        std:: cout << std:: endl;
    }
    std:: cout << std:: endl;
}

int main()
{
    // Seed for random number generation
    std::srand(std::time(0));
    // Initialize matrices for each programmer
    std::vector<ProgrammerData> programmerData(30);
    for (int i = 0; i < 30; ++i)
    {
        programmerData[i].data = initializeMatrix();
    }
    //Apply k-means clustering to each programmer's data


    // for (int i = 0; i < 30; ++i) {
    //     std::vector<ProgrammerData> clusteredData = kMeansClustering(programmerData[i].data);
    //     // Now 'clusteredData' contains the clustered data for the i-th programmer
    // }

    std:: vector<ProgrammerData> clusteredData = kMeansClustering(programmerData);
    // for(auto cls: clusteredData){
    //     std:: cout << cls.cluster << std:: endl;
    // }

    // for (int i = 0; i < 30; ++i)
    // {
    //     printMatrix(programmerData[0].data);
    //     std:: cout << std:: endl;
    // }
    return 0;
}
