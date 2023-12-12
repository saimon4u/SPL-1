// #include<bits/stdc++.h>
// using namespace std;
// bool isBlock(string line){
//     return line.find("for") != string::npos || line.find("while") != string::npos
//         || line.find("if") != string::npos || line.find("do") != string::npos
//         || line.find("switch") != string::npos;
// }
// vector<int> blockLength(string &filename){
//     ifstream file(filename);
//     if(!file.is_open()){
//         cerr << "Error opening file: " << filename << std::endl;
//         return {};
//     }
//     string line;
//     vector <string> lines;
//     while(getline(file,line)){
//         lines.push_back(line);
//     }
//     vector <int> val;
//     int nest = 0;
//     bool exists = false;
//     for(int i=0; i<lines.size(); i++){
//         if(lines[i].empty())continue;
//         if(isBlock(lines[i]) && lines[i].find("{") != string::npos){
//             nest = 1;
//             int count = 0;
//             for(int j=i+1; j<lines.size(); j++){
//                 if(nest==0){
//                     break;
//                 }
//                 if(lines[j].empty())continue;
//                 else if(lines[j].find("{") != string::npos){
//                     nest++;
//                     count++;
//                 }
//                 else if(lines[j].find("}") != string::npos){
//                     if(nest>1)count++;
//                     nest--;
//                 }
//                 else count++;
//             }
//             val.push_back(count);
//             nest = 0;
//         }
//     }
//     file.close();
//     return val;
// }