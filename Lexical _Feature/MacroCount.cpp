

int getTotalMacro(string &filename){
    int count = 0;
    ifstream file(filename);
    if(!file.is_open()){
        cerr << "Error opening file: " << filename << endl;
        return -1;
    }
    string line;
    const string definePrefix = "#define";
    while(getline(file,line)){
        if(line.empty())continue;
        else if(line.find(definePrefix)!=string::npos)count++;
    }
    file.close();
    return count;
}