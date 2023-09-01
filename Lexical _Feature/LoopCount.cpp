
int getTotalLoop(string &filename){
    int count = 0;
    ifstream file(filename);
    if(!file.is_open()){
        cerr << "Error opening file: " << filename << endl;
        return -1;
    }
    string line;
    bool insideDowhile = false;
    while(getline(file,line)){
        if(line.empty())continue;
        if(line.find("for(")!=string::npos || line.find("for (")!=string::npos)count++;
        else if(insideDowhile && (line.find("while(")!=string::npos || line.find("while (")!=string::npos)){
            count++;
            insideDowhile = false;
        }
        else if(line.find("do {")!=string::npos || line.find("do{")!=string::npos){
            insideDowhile = true;
        }
        else if(!insideDowhile && (line.find("while(")!=string::npos || line.find("while (")!=string::npos)){
            count++;
        }
    }
    file.close();
    return count;
}