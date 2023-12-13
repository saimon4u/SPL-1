int getTotalLineSpacingAroundOperators(string& filename,set<string> &operators){
    int count = 0;
    ifstream file(filename);
    if(!file.is_open()){
        cerr << "Error opening file: " << filename << endl;
        return -1;
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
        if(pos > 0 and isspace(line[pos-1]) and pos < line.size()-1 and isspace(line[pos+1])){
            hasSpacing = true;
        }
        if(foundOperator && hasSpacing){
            count++;
        }
    }
    file.close();
    return count;
}

