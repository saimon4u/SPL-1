bool nextlineCurlyBrace(string &filename){
    ifstream file(filename);
    if(!file.is_open()){
        cerr << "Error opening file: " << filename << endl;
        return -1;
    }
    string line;
    vector<string> lines;
    while(getline(file,line)){
        lines.push_back(line);
    }
    for(int i=0; i<lines.size(); i++){
        if(lines[i].empty())continue;
        if(lines[i].find("()") != string::npos && lines[i].find("{")==string::npos && lines[i].find(";") == string::npos){
            if((i+1)<lines.size() && lines[i+1].find("{") != string::npos){
                return true;
            }
        }
    }
    return false;
}