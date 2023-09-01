
int getTotalCondition(string &filename){
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
        else if(line.find("if(")!=string::npos || line.find("if (")!=string::npos){
            count++;
        }
        else if(line.find("else{")!=string::npos || line.find("else {")!=string::npos || line.find("else;")!=string::npos){
            count++;
        }
        else if(line.find("else if(")!=string::npos || line.find("else if (")!=string::npos){
            count++;
        }
    }
    file.close();
    return count;
}