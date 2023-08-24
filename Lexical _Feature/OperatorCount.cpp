
bool isOperator(char c){
    static const set<char>operators ={
        '+', '-', '*', '/', '%', '!', '<', '>', '=', '&', '|', '^',
        '~','?'
    };
    return operators.find(c) != operators.end();
}

void getTotalOperator(string &filename,int &count){
    ifstream file(filename);
    if(!file.is_open()){
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    string line;
    bool insideComment = false;
    bool insideQoute = false;
    while(getline(file, line)){
        if(line.empty())continue;
        if(line.find("#include")!=string::npos)continue;
        else if(line.find("//")!=string::npos)continue;
        else if(line.find("/*")!=string::npos && line.find("*/")==string::npos){
            // insideComment = true;
            continue;
        }
        else if(line.find("/*") != string::npos){
            insideComment = true;
            continue;
        }
        else if(line.find("*/")!=string::npos){
            insideComment = false;
            continue;
        }
        else if(insideComment)continue;
        for(int i = 0; i < line.size(); ++i){
            char c = line[i];
            if(c=='"')insideQoute = !insideQoute;
            if(insideQoute){
                continue;
            }
            if(isOperator(c)){
                count++;
            }
            if(i+1 < line.size() && isOperator(c) && isOperator(line[i + 1])){
                i++;
            }
        }
    }
    file.close();
}