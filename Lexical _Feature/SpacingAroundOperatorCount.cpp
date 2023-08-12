void getTotalLineSpacingAroundOperators(string& filename,int &count,set<string> &operators){
    ifstream file(filename);
    if(!file.is_open()){
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    string line;

    while(getline(file,line)){
        bool hasSpacing = false;
        bool foundOperator = false;
        int pos;
        for(auto op: operators){
            if((pos = line.find(op))!=string::npos){
                foundOperator = true;
                break;
            }
        }
        if(isspace(line[pos-1]) && isspace(line[pos+1])){
            hasSpacing = true;
        }
        if(foundOperator && hasSpacing){
            count++;
        }
    }

    file.close();
}

