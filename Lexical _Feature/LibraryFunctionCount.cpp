// #include<iostream>
// #include<fstream>
// #include<regex>
using namespace std;


bool isValidIdentifierChar(char c){
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c == '_') || (c >= '0' && c <= '9');
}

void getTotalLibraryFunction(string& filename,int &count,set<string> &libraryFunction){
    ifstream file(filename);
    if(!file.is_open()){
        cerr << "Error opening file: " << filename << endl;
        return;
    }
    string line;
    regex reg("[^a-zA-Z0-9,\"();.%]");
    while (getline(file, line)) {
        if(line.empty())continue;
        line = regex_replace(line,reg," ");
        if(line.find("malloc.h")!=string::npos)continue;
        bool insideFunctionCall = false;
        bool insideQuote = false;
        for(int i = 0; i < line.length(); i++){
            char c = line[i];
            if(!insideFunctionCall && c=='"' && (i==0 || line[i - 1]!='\\'))insideQuote = !insideQuote;
            else if(!insideQuote && isValidIdentifierChar(c)){
                int j = i + 1;
                while(j<line.length() && isValidIdentifierChar(line[j]))j++;
                string potentialFunctionCall = line.substr(i, j - i);
                // if(potentialFunctionCall == "printf" || potentialFunctionCall == "scanf" || 
                //     potentialFunctionCall == "malloc"  /* Add other standard library functions here */) {
                //     count++;
                //     insideFunctionCall = true;
                // }
                if(libraryFunction.find(potentialFunctionCall)!=libraryFunction.end()){
                    count++;
                    insideFunctionCall = true;
                }
            }
            else if(c=='(')insideFunctionCall = false;
        }
    }
    file.close();
}