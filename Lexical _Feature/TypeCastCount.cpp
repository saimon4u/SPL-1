void getTotalTypeCast(string& filename,int &count,set<string> &dataType){
    ifstream file(filename);
    if(!file.is_open()){
        cerr << "Error opening file: " << filename << endl;
        return;
    }
    string line;
    while(getline(file,line)){
        int startPos = 0;
        while((startPos = line.find("(", startPos)) != string::npos){
            int endPos = line.find(")", startPos);
            if(endPos != string::npos){
                string str = line.substr(startPos + 1, endPos - startPos - 1);
                if(dataType.find(str)!=dataType.end()){
                    count++;
                }
                startPos = endPos + 1;
            }
            else{
                break;
            }
        }
    }
    file.close();
}
