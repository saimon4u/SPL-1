void functionLength(string &filename,int count,set<string> &dataType,double &aveLength,int &maxLength){
    ifstream file(filename);
    if(!file.is_open()){
        cerr << "Error opening file: " << filename << std::endl;
        return;
    }
    string line;
    bool insideFunction = false;
    regex  reg("[^a-zA-Z0-9{}, ()]");
    bool exists = false;
    int pos;
    int nest = 0;
    int statement = 0;
    vector<int> length;
    while(getline(file, line)){
        if(line.empty())continue;
        line = regex_replace(line,reg," ");
        if(!insideFunction)
            for(auto dt: dataType)
                if(line.find(dt) != string::npos)exists = true;
        if(!insideFunction && line.find("{") != string::npos && exists && line.find("(") != string::npos && line.find(")") != string::npos){
            insideFunction = true;
        }
        if(insideFunction && line.find("{") != string::npos && exists){
            nest++;
        }
        if(line.find("}") != string::npos && insideFunction && exists && nest != 0){
            nest --;
        }
        if(insideFunction && nest != 0){
            statement++;
        }
        if(line.find("}") != string::npos && insideFunction && exists && nest==0){
            insideFunction = false;
            exists = false;
            count++;
            statement--;
            length.push_back(statement);
            if(maxLength < statement)maxLength = statement;
            statement = 0;
        }
    }
    double total = 0;
    for(auto l: length){
        total += l;
    }
    aveLength = total/count;
    file.close();
}