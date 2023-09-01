// #include<iostream>
// #include<fstream>
// #include<regex>
// #include<set>
using namespace std;


int getTotalIdentifier(string &filename,set<string> &keywords){
    int count = 0;
    ifstream file(filename);
    if(!file.is_open()){
        cerr << "Error Opening file: " << filename << endl;
        return -1;
    }
    string line;
    regex reg("[^a-zA-Z0-9.<>]");
    bool insideMultiComment = false;
    while(getline(file,line)){
        if(line.empty())continue;
        if(line.find("//")!=string::npos)continue;
        if(line.find("/*")!=string::npos)insideMultiComment = true;
        if(line.find("*/")!=string::npos){
            insideMultiComment = false;
            continue;
        }
        if(insideMultiComment)continue;
        vector <string> tokens = TokenizeLine(line,reg," ");
        for(auto token: tokens){
            if(!isdigit(token[0]) && isalpha(token[0]) || token[0] == '_'){
                bool valid = true;
                for(auto ch : token){
                    if(!isalpha(ch) && ch != '_') {
                        valid = false;
                        break;
                    }
                }
                if(valid && keywords.find(token) == keywords.end()){
                    count++;
                }
            }
        }
    }
    file.close();
    return count;
}