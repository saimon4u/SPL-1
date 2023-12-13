#include<bits/stdc++.h>
#include <regex>
#include<fstream>
using namespace std;


string word_trim(string word){
    string newWord;
    for(int i=0; i<word.size(); i++){
        if(word[i]!=' '){
            for(int j=i; j<word.size(); j++){
                newWord.push_back(word[j]);
            }
            break;
        }
    }
    word.clear();
    for(int i=newWord.size()-1; i>=0; i--){
        if(newWord[i]!=' '){
            for(int j=i; j>=0; j--){
                word.push_back(newWord[j]);
            }
            break;
        }
    }
    newWord.clear();
    for(int i=word.size()-1; i>=0; i--){
        newWord.push_back(word[i]);
    }
    return newWord;
}


vector<string> segmentation(string filename){
    ifstream file(filename);
    if(!file.is_open()){
        cerr << "Error opening file: " << filename << endl;
        return {};
    }
    vector <string> lines;
    string line;
    regex spaceRegex("\\s+");
    while(getline(file,line)){
        line = regex_replace(line, spaceRegex, " ");
        lines.push_back(line);
    }
    return lines;
}


vector<int> closing_curly_braces(string filename){
    vector <string> lines;
    lines = segmentation(filename);
    vector<int> closing_braces(2000,0);
    vector<int> openning_braces(2000,0);
    vector <int> store;
    int last_open_brace;
    string line;
    for(int i=0; i<lines.size(); i++){
        line = lines[i];
        for(auto l: line){
            if(l == '{'){
                openning_braces[i+1]=1;
                store.push_back(i+1);
            }
            else if(l == '}'){
                last_open_brace = store.back();
                store.pop_back();
                closing_braces[last_open_brace]=i+1;
                // for(int a=last_open_brace+1; a<=closing_braces[last_open_brace]; a++){
                //     if(closing_braces[a] == 0)closing_braces[a] = closing_braces[last_open_brace];
                // }
            }
        }

    }
    return closing_braces;
}



vector<vector<int>>Graph(string filename){
    vector<string>lines;
    lines = segmentation(filename);
    int num_lines = lines.size();
    num_lines++;


    vector <vector<int>> Control_Graph(num_lines,vector<int>(num_lines,0));
    vector <int> closingBrace = closing_curly_braces(filename);


    // for(int i=0; i<closingBrace.size(); i++){
    //     if(closingBrace[i] != 0)cout << i << ' ' << closingBrace[i] << endl;
    // }



    vector <int> store_loop,case_,switch_,doWhile;
    string line,word = "";
    int last_loop = 0,curr_line,k,d,q,r;

    for(int i=1; i<num_lines-1; i++){
        Control_Graph[i][i+1]=1;
    }
    
    bool skipLine = false;
    for(int i=0; i<lines.size(); i++){
        if(skipLine){
            skipLine = false;
            continue;
        }
        for(auto dw: doWhile){
            if(i == dw) {
                skipLine = true;
                break;
            }   
        }
        line = lines[i];
        if(store_loop.size() != 0){
            last_loop = store_loop.back();
            if(closingBrace[last_loop] == 0 && i > last_loop) store_loop.pop_back();
            else if(closingBrace[last_loop] != 0 && closingBrace[last_loop] < i)store_loop.pop_back();
        }
        for(int j=0; j<line.size(); j++){
            if(j == line.size()-1 || line[j] == '(' || line[j] == ')' || line[j] == '{' || line[j] == '}'){
                // cout << word << "-> " << line[j] << endl;
                word = word_trim(word);
                if(word == "for" || word == "while"){
                    curr_line = i+1;
                    while(closingBrace[curr_line] == 0){
                        curr_line++;
                        if(curr_line == lines.size()) break;
                    }
                    store_loop.push_back(curr_line);
                    if(curr_line != lines.size()){
                        Control_Graph[i+1][closingBrace[curr_line] + 1] = 1;
                        Control_Graph[closingBrace[curr_line]][closingBrace[curr_line]+1] = 0;
                        Control_Graph[closingBrace[curr_line]][i+1] = 1;
                    }
                }
                else if(word == "do"){
                    curr_line = i+1;
                    while(closingBrace[curr_line] == 0){
                        curr_line++;
                        if(curr_line == lines.size()) break;
                    }
                    k = 0;
                    string wh,ss1,ss2,ss = "";
                    ss1 = lines[closingBrace[curr_line]];
                    for(int p = 0; p<ss1.size(); p++){
                        if(p == ss1.size() || ss1[p] == ' ' || ss1[p] == '(' || ss1[p] == ')' || ss1[p] == '{' || ss1[p] == '}'){
                            if(ss == "while"){
                                k = 1;
                                ss = "";
                                break;
                            }
                            else{
                                ss = "";
                            }
                        }
                        else{
                            ss += ss1[p];
                        }
                    }
                    if(k==1){
                        store_loop.push_back(curr_line);
                        doWhile.push_back(closingBrace[curr_line]);
                    }
                    else{
                        store_loop.push_back(curr_line+1);
                        doWhile.push_back(closingBrace[curr_line]+1);
                    }
                    if(curr_line == lines.size()){
                        if(k == 1) Control_Graph[closingBrace[curr_line]][i+1] = 1;
                        else Control_Graph[closingBrace[curr_line]+1][i+1] = 1;
                    }
                }
                else if(word == "continue"){
                    last_loop = store_loop.back();
                    if(closingBrace[last_loop] == 0) Control_Graph[i+1][last_loop] = 1;
                    else Control_Graph[i+1][last_loop-1] = 1;
                }
                else if(word == "break"){
                    last_loop = store_loop.back();
                    if(closingBrace[last_loop] == 0) Control_Graph[i+1][last_loop+1] = 1;
                    else Control_Graph[i+1][closingBrace[last_loop]+1] = 1;
                }
                else if(word == "if"){
                    if (lines[i].find("{") != string::npos)
                    {
                        int next_else = i;
                        k = 1;
                        // cout << next_else << endl;
                        while (k)
                        {
                            d = closingBrace[next_else + 1];
                            string ss = "", compare = lines[d];
                            // cout << compare << endl;
                            k = 0;
                            for (int p = 0; p < compare.size(); p++)
                            {
                                if (p == compare.size() - 1 || compare[p] == ' ' || compare[p] == '(' || compare[p] == ')' || compare[p] == '{' || compare[p] == '}')
                                {
                                    if (ss == "else")
                                    {
                                        k = 1;
                                        ss = "";
                                        Control_Graph[i + 1][d + 1] = 1;
                                        Control_Graph[d][d + 1] = 0;
                                        break;
                                    }
                                    else
                                    {
                                        ss = "";
                                    }
                                }
                                else
                                {
                                    ss += compare[p];
                                }
                            }
                            next_else = d;
                        }
                        Control_Graph[i + 1][closingBrace[i + 1] + 1] = 1;
                    }
                    else
                    {
                        int next_else = i+1;
                        k = 1;
                        // cout << next_else << endl;
                        while (k)
                        {
                            d = closingBrace[next_else + 2];
                            string ss = "", compare = lines[d];
                            // cout << compare << endl;
                            k = 0;
                            for (int p = 0; p < compare.size(); p++)
                            {
                                if (p == compare.size() - 1 || compare[p] == ' ' || compare[p] == '(' || compare[p] == ')' || compare[p] == '{' || compare[p] == '}')
                                {
                                    if (ss == "else")
                                    {
                                        k = 1;
                                        ss = "";
                                        Control_Graph[i + 2][d + 1] = 1;
                                        Control_Graph[d][d + 1] = 0;
                                        break;
                                    }
                                    else
                                    {
                                        ss = "";
                                    }
                                }
                                else
                                {
                                    ss += compare[p];
                                }
                            }
                            next_else = d;
                        }
                        Control_Graph[i + 2][closingBrace[i + 2] + 1] = 1;
                    }
                }
                else if(word == "else if"){
                    Control_Graph[i+1][closingBrace[i+1]+1] = 1;
                    j += 2;
                }
                else if(word == "else"){
                    j+=2;
                }
                else if(word == "switch"){
                    if (lines[i].find("{") != string::npos)
                    {
                        q = i + 1;
                        r = i;
                        d = closingBrace[q];
                        Control_Graph[q - 1][q] = 0;
                        Control_Graph[q][q + 1] = 1;
                        k = 1;
                        while (k)
                        {
                            string ss = "", compare = lines[q];
                            for (int p = 0; p <= compare.size(); p++)
                            {
                                if (p == compare.size() || compare[p] == ' ' || compare[p] == '(' || compare[p] == ')' || compare[p] == '{' || compare[p] == '}')
                                {
                                    if (ss == "case" || ss == "default")
                                    {
                                        k = 1;
                                        ss = "";
                                        if (q != i + 2)
                                            Control_Graph[r + 1][q + 1] = 1;
                                        r = q;
                                        break;
                                    }
                                    else if (ss == "break")
                                    {
                                        k = 1;
                                        ss = "";
                                        Control_Graph[q + 1][d + 1] = 1;
                                        break;
                                    }
                                    else
                                    {
                                        ss += compare[p];
                                    }
                                }
                            }
                            q++;
                            if (q == d)
                                break;
                        }
                        i = d + 1;
                    }
                    else
                    {
                        q = i + 2;
                        r = i;
                        d = closingBrace[q];
                        Control_Graph[q - 1][q] = 0;
                        Control_Graph[q][q + 1] = 1;
                        k = 1;
                        while (k)
                        {
                            string ss = "", compare = lines[q];
                            for (int p = 0; p <= compare.size(); p++)
                            {
                                if (p == compare.size() || compare[p] == ' ' || compare[p] == '(' || compare[p] == ')' || compare[p] == '{' || compare[p] == '}')
                                {
                                    if (ss == "case" || ss == "default")
                                    {
                                        k = 1;
                                        ss = "";
                                        if (q != i + 2)
                                            Control_Graph[r + 1][q + 1] = 1;
                                        r = q;
                                        break;
                                    }
                                    else if (ss == "break")
                                    {
                                        k = 1;
                                        ss = "";
                                        Control_Graph[q + 1][d + 1] = 1;
                                        break;
                                    }
                                    else
                                    {
                                        ss += compare[p];
                                    }
                                }
                            }
                            q++;
                            if (q == d)
                                break;
                        }
                        i = d + 1;
                    }
                }
                word = "";
            }
            else{
                word.push_back(line[j]);
            }
        }
    }
    // cout << "hello" << endl;
    return Control_Graph;
}



// string removeExtraSpacesAndSemicolons(const string& input) {
//     // Remove extra spaces
//     regex spaceRegex("\\s+");
//     string noExtraSpaces = regex_replace(input, spaceRegex, " ");

//     // Remove semicolons
//     regex semicolonRegex("\\s*;\\s*");
//     return regex_replace(noExtraSpaces, semicolonRegex, "");
// }




// int main(){
//     string filename = "newfile.txt";
//     vector <vector<int>> G = Graph(filename);
    // for(int i=0; i<G.size(); i++){
    //     for(int j=0; j<G[i].size(); j++){
    //         if(G[i][j] != 0) cout << i << " " << j << endl;
    //     }
    // }
// }