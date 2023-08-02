// #include<iostream>
// #include<sstream>
// #include<vector>
// #include<regex>
using namespace std;


vector <string> TokenizeLine(string &line,regex &reg,string replace){
    line = regex_replace(line,reg,replace);
    istringstream isline(line);
    vector <string> tokens;
    string token;
    while(isline >> token){
        tokens.push_back(token);
    }
    return tokens;
}