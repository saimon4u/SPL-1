#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<sstream>
#include<regex>
#include<set>
using namespace std;
set <string> cKeywords = {
        "auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else",
        "enum", "extern", "float", "for", "goto", "if", "int", "long", "register", "return",
        "short", "signed", "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned",
        "void", "volatile", "while"
};
set <string> dataType = {
    "int","float","double","char","void","unsigned","long"
};

vector <string> tokenizeLine(string &line){
    vector <string> tokens;
    string token;
    istringstream isline(line);
    while(isline >> token){
        token = regex_replace(token,regex("[^a-zA-Z0-9#//*]"),"");
        tokens.push_back(token);
    }
    return tokens;
}

int extractKeyword(string &token){
    for(auto key : cKeywords){
        if(token == key)return 1;
    }
    return 0;
}

int extractDirectives(string &token){
    if(!token.empty() && token[0]=='#') return 1;
    return 0;
}

int extractIdentifiers(const string &token) {
    if(!isdigit(token[0]) && isalpha(token[0]) || token[0] == '_'){
        bool valid = true;
        for(auto c : token){
            if(!isalpha(c) && c != '_') {
                valid = false;
                break;
            }
        }
        if(valid && cKeywords.find(token) == cKeywords.end())return 1;
    }
    return 0;
}

int extractDataType(const string &token){
    if(dataType.find(token)!=dataType.end())return 1;
    return 0;
}

void extractCommentLine(const string& line,int &count,bool &isMulti){
    if(line.size() >= 2 && line.find("//") != string::npos)count++;
    else if(line.size() >= 2 && line.find("/*") != string::npos) {
        isMulti = true;
        count++;
    }
    else if (isMulti && line.find("*/") != string::npos) {
        isMulti = false;
        count++;
    }
    else if (isMulti)count++;
}


void extractFuntionPrototype(const string& line,int &count,bool &isInsidePrototype){
    bool isExists = false;
    if(line.find("{")!=string::npos || line.find("printf")!=string::npos)return;
    for(auto data: dataType){
        if(line.find(data)!=string::npos){
            isExists = true;
        }
    }
    if(!isExists)return;
    for (int i = 0; i < line.length() - 1; ++i) {
        if (line[i] == '/' && line[i + 1] == '/') {
            while (i < line.length() && line[i] != '\n') {
                ++i;
            }
        } else if (line[i] == '/' && line[i + 1] == '*') {
            while (i < line.length() - 1 && !(line[i] == '*' && line[i + 1] == '/')) {
                ++i;
            }
            ++i;
        } else if (!isInsidePrototype) {
            if (line[i + 1] == '(') {
                isInsidePrototype = true;
                int j = i;
                while (j < line.length() && line[j] != ';') {
                    ++j;
                }

                if (j < line.length() && line[j] == ';') {
                    count++;
                }

                isInsidePrototype = false;
            }
        }
    }
}


int main(){
    int totalLine = 0;
    int numOfKeyword = 0;
    int numOfDirectives = 0;
    int numOfIdentifier = 0;
    int numOfDataType = 0;
    int numOfCommentLine = 0;
    int numOfCondition = 0;
    int numOfFunctionPrototype = 0;
    bool insideFunctionProtoType = false;
    bool insideMultiComment = false;
    string fileName = "input.c";
    ifstream inputFile(fileName);
    string line;
    while(getline(inputFile,line)){
        totalLine++;
        extractCommentLine(line,numOfCommentLine,insideMultiComment);
        extractFuntionPrototype(line,numOfFunctionPrototype,insideFunctionProtoType);
        vector <string> tokens = tokenizeLine(line);
        for(auto token : tokens){
            numOfKeyword += extractKeyword(token);
            numOfDirectives += extractDirectives(token);
            numOfIdentifier += extractIdentifiers(token);
            numOfDataType += extractDataType(token);
        }
    }
    inputFile.close();
    cout << "NumOfLine = " << totalLine << endl;
    cout << "NumofKeywords = " << numOfKeyword << endl;
    cout << "NumofDirectives = " << numOfDirectives << endl;
    cout << "NumofIndentifier = " << numOfIdentifier << endl;
    cout << "NumofDataType = " << numOfDataType << endl;
    cout << "NumofCommentLine = " << numOfCommentLine << endl;
    cout << "NumofFunctionProtoType = " << numOfFunctionPrototype << endl;
}
