// #include<iostream>
// #include<fstream>
// #include<regex>
using namespace std;


void getTotalLiterals(string &filename, int integerCount, int floatCount,int charCount, int stringCount){
    ifstream file(filename);
    if(!file.is_open()){
        cerr << "Error opening file: " << filename << endl;
        return;
    }
    integerCount = 0;
    floatCount = 0;
    charCount = 0;
    stringCount = 0;
    string line;
    // Regular expressions for matching literals
    regex integerRegex(R"(\b-?\d+\b)");
    regex floatRegex(R"(\b-?\d+(\.\d*)?([eE][+-]?\d+)?\b)");
    regex charRegex(R"('([^'\\]|\\['"\\nt])')");
    regex stringRegex(R"("([^"\\]|\\['"\\nt])*")");

    while(getline(file,line)) {
        integerCount += distance(sregex_iterator(line.begin(), line.end(), integerRegex),sregex_iterator());

        floatCount += distance(sregex_iterator(line.begin(), line.end(), floatRegex), sregex_iterator());

        charCount += distance(sregex_iterator(line.begin(), line.end(), charRegex), sregex_iterator());

        stringCount += distance(sregex_iterator(line.begin(), line.end(), stringRegex), sregex_iterator());
    }
    cout << integerCount << " " << floatCount << " " << stringCount << " " << charCount << endl;

    file.close();
}
