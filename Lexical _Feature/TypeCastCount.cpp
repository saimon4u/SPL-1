int getTotalTypeCast(string& filename,set<string> &dataType){
    int count = 0;
    ifstream file(filename);
    if(!file.is_open()){
        cerr << "Error opening file: " << filename << endl;
        return -1;
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
    return count;
}
