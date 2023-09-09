bool followingCurlyBrace(string &filename){
    ifstream file(filename);
    if(!file.is_open()){
        cerr << "Error opening file: " << filename << endl;
        return -1;
    }
    string line;
    while(getline(file,line)){
        if(line.empty())continue;
        if(line.find("(") != string::npos){
            int i;
            for(i=0; i<line.size(); i++){
                if(line[i]==')')break;
            }
            if(line[i+1]=='{' || ((i+2)<line.size() && line[i+2]=='{'))return true;
        }
    }
    return false;
}