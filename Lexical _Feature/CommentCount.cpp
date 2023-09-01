// #include<iostream>
// #include<fstream>
// #include<regex>
using namespace std;

int getTotalComment(string &filename){
    int count = 0;
    ifstream file(filename);
    if(!file.is_open()){
        cerr << "Error Opening file: " << filename << endl;
        return -1;
    }
    string line;
    regex reg("[^a-zA-Z0-9//*]");
    bool insideMultiComment = false;
    while(getline(file,line)){
        if(line.empty())continue;
        if(line.size() >= 2 && line.find("//") != string::npos)count++;
        else if(line.size() >= 2 && line.find("/*") != string::npos) {
            insideMultiComment = true;
            count++;
        }
        else if(insideMultiComment && line.find("*/") != string::npos) {
            insideMultiComment = false;
            count++;
        }
        else if(insideMultiComment)count++;
    }
    file.close();
    return count;
}
