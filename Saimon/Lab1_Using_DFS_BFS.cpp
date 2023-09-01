#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define loop(i,n) for (int i = 0; i < n; i++)
using namespace std;

unordered_map <string,int> value;
vector <int> graph[11];
// int level[11] = {0};
bool visited[11];
// void BFS(int source){
//     queue <int> q;
//     q.push(source);
//     visited[source] = true;
//     level[source] = 0;
//     while(!q.empty()){
//         int curr_v = q.front();
//         q.pop();
//         for(auto child : graph[curr_v]){
//             if(!visited[child]){
//                 q.push(child);
//                 visited[child] = true;
//                 level[child] = level[curr_v] + 1;
//             }
//         }
//     }
// }
vector <string> tour;
void DFS(int source){
    visited[source] = true;
    for(auto child : graph[source]){
        if(!visited[child]){
            for(auto it : value){
                if(it.second == child){
                    tour.push_back(it.first);
                    break;
                }
            }
            DFS(child);
        }
    }
}
int main(){
    value["Greenland"] = 1;
    value["China"] = 2;
    value["India"] = 3;
    value["Pakistan"] = 4;
    value["Iran"] = 5;
    value["Bangladesh"] = 6;
    value["Turkey"] = 7;
    value["USA"] = 8;
    value["Canada"] = 9;
    value["Thailand"] = 10;
    cout << "Enter country and connections number: ";
    int country,connections;
    cin >> country >> connections;
    cout << "Enter 2 string for each connections: " << endl;
    for(int i=0; i<connections; ++i){
        string c1,c2;
        cin >> c1 >> c2;
        graph[value[c1]].push_back(value[c2]);
        graph[value[c2]].push_back(value[c1]);
    }
    DFS(value["USA"]);
    cout << "From India you can visit: " << endl;
    for(auto it : tour){
        cout << it << endl;
    }
    // BFS(value["India"]);
    // for(auto it : value){
    //     if(level[it.second])cout << it.first << endl;
    // }
    return 0;
}