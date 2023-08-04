

void getTotalMacro(string &filename,int &count){
    ifstream file(filename);
    if(!file.is_open()){
        cerr << "Error opening file: " << filename << endl;
        return;
    }
    string line;
    const string definePrefix = "#define";
    while(getline(file,line)){
        if(line.empty())continue;
        else if(line.find(definePrefix)!=string::npos)count++;
    }
    file.close();
}