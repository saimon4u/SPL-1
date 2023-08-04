
void getTotalLoopCondition(string &filename,int &lcount,int &Ccount){
    ifstream file(filename);
    if(!file.is_open()){
        cerr << "Error opening file: " << filename << endl;
        return;
    }
    string line;
    bool insideDowhile = false;
    while(getline(file,line)){
        if(line.empty())continue;
        if(line.find("for(")!=string::npos || line.find("for (")!=string::npos)lcount++;
        else if(insideDowhile && (line.find("while(")!=string::npos || line.find("while (")!=string::npos)){
            lcount++;
            insideDowhile = false;
        }
        else if(line.find("do {")!=string::npos || line.find("do{")!=string::npos){
            insideDowhile = true;
        }
        else if(!insideDowhile && (line.find("while(")!=string::npos || line.find("while (")!=string::npos)){
            lcount++;
        }
        else if(line.find("if(")!=string::npos || line.find("if (")!=string::npos){
            Ccount++;
        }
        else if(line.find("else{")!=string::npos || line.find("else {")!=string::npos || line.find("else;")!=string::npos){
            Ccount++;
        }
        else if(line.find("else if(")!=string::npos || line.find("else if (")!=string::npos){
            Ccount++;
        }
    }
}