#include"main.cpp"
#include<filesystem>
using namespace std;

void readFile(string directory,vector<string> &f){
    for(auto &entry: filesystem::directory_iterator(directory)){
        if(filesystem::is_regular_file(entry)){
            if(entry.path().extension() == ".c"){
                f.push_back(directory+"/"+entry.path().filename().string());
            }
        }
    }
}
double normalize(int x,int y){
    double res = (x*1.0)/y;
    return res;
}
vector<vector<double>> extractor(string directoryPath){
    // string directoryPath = filesystem::current_path().string();
    vector <string> fileName;
    readFile(directoryPath,fileName);
    vector <int> lineCount;
    vector <double> keywordCount;
    vector <double> directiveCount;
    vector <double> identifierCount;
    vector <double> datatypeCount;
    vector <double> commentCount;
    vector <double> prototypeCount;
    vector <double> definitionCount;
    vector <double> libraryCount;
    vector <double> parameterCount;
    vector <double> macroCount;
    vector <double> operatorCount;
    vector <double> loopCount;
    vector <double> conditionCount;
    vector <double> varCount;
    vector <double> typecastCount;     
    vector <double> globalCount;
    vector <double> spacingOperators;
    vector <double> averageVarLen;
    vector <double> averageFunLen;
    vector <vector <double> > features;
    for(auto f: fileName){
        // cout << f << endl;
        lineCount.push_back(getTotalLine(f));
        keywordCount.push_back(normalize(getTotalKeyword(f,Keywords),getTotalLine(f)));
        directiveCount.push_back(normalize(getTotalDirective(f),getTotalLine(f)));
        identifierCount.push_back(normalize(getTotalIdentifier(f,Keywords),getTotalLine(f)));
        datatypeCount.push_back(normalize(getTotalDataTyep(f,dataType),getTotalLine(f)));
        commentCount.push_back(normalize(getTotalComment(f),getTotalLine(f)));
        functionName.clear();
        prototypeCount.push_back(normalize(getTotalFunctionPrototype(f,dataType,functionName),getTotalLine(f)));
        definitionCount.push_back(normalize(getTotalFunctionDefinition(f,dataType,functionName),getTotalLine(f)));
        libraryCount.push_back(normalize(getTotalLibraryFunction(f,commonLibraryFunctions),getTotalLine(f)));
        parameterCount.push_back(normalize(getTotalFunctionParaMeter(f,dataType),getTotalLine(f)));
        macroCount.push_back(normalize(getTotalMacro(f),getTotalLine(f)));
        operatorCount.push_back(normalize(getTotalOperator(f),getTotalLine(f)));
        loopCount.push_back(normalize(getTotalLoop(f),getTotalLine(f)));
        conditionCount.push_back(normalize(getTotalCondition(f),getTotalLine(f)));
        declaredVariables.clear();
        varCount.push_back(normalize(getTotalVariable(f,functionName,declaredVariables,dataType,commonLibraryFunctions),getTotalLine(f)));
        typecastCount.push_back(normalize(getTotalTypeCast(f,dataType),getTotalLine(f)));
        globalCount.push_back(normalize(getTotalGlobalVariable(f,dataType,functionName),getTotalLine(f)));
        spacingOperators.push_back(normalize(getTotalLineSpacingAroundOperators(f,operators),getTotalLine(f)));
        averageVarLen.push_back(getAverageVariableLength(declaredVariables));
        averageFunLen.push_back(getAverageLengthOfFunctionName(functionName));
    }
    features = {keywordCount,directiveCount,identifierCount,datatypeCount,commentCount,prototypeCount,definitionCount,
                libraryCount,parameterCount,macroCount,operatorCount,loopCount,conditionCount,varCount,typecastCount,
                globalCount,spacingOperators,averageVarLen,averageFunLen};
    // vector<double> vec;
    // for(int i=0; i<fileName.size(); i++){
    //     vec.push_back(lineCount[i]);
    //     vec.push_back(keywordCount[i]);
    //     vec.push_back(directiveCount[i]);
    //     vec.push_back(identifierCount[i]);
    //     vec.push_back(datatypeCount[i]);
    //     vec.push_back(commentCount[i]);
    //     vec.push_back(prototypeCount[i]);
    //     vec.push_back(definitionCount[i]);
    //     vec.push_back(libraryCount[i]);
    //     vec.push_back(parameterCount[i]);
    //     vec.push_back(macroCount[i]);
    //     vec.push_back(operatorCount[i]);
    //     vec.push_back(loopCount[i]);
    //     vec.push_back(conditionCount[i]);
    //     vec.push_back(varCount[i]);
    //     vec.push_back(typecastCount[i]);
    //     vec.push_back(globalCount[i]);
    //     vec.push_back(spacingOperators[i]);
    //     vec.push_back(averageVarLen[i]);
    //     vec.push_back(averageFunLen[i]);
    //     features.push_back(vec);
    //     vec.clear();
    // }
    return features;
    // string f = "../SCC.c";
    // vector <double> vec;


    // vec.push_back(normalize(getTotalKeyword(f,Keywords),getTotalLine(f)));
    // vec.push_back(normalize(getTotalDirective(f),getTotalLine(f)));
    // vec.push_back(normalize(getTotalIdentifier(f,Keywords),getTotalLine(f)));
    // vec.push_back(normalize(getTotalDataTyep(f,dataType),getTotalLine(f)));
    // vec.push_back(normalize(getTotalComment(f),getTotalLine(f)));
    // functionName.clear();
    // vec.push_back(normalize(getTotalFunctionPrototype(f,dataType,functionName),getTotalLine(f)));
    // vec.push_back(normalize(getTotalFunctionDefinition(f,dataType,functionName),getTotalLine(f)));
    // vec.push_back(normalize(getTotalLibraryFunction(f,commonLibraryFunctions),getTotalLine(f)));
    // vec.push_back(normalize(getTotalFunctionParaMeter(f,dataType),getTotalLine(f)));
    // vec.push_back(normalize(getTotalMacro(f),getTotalLine(f)));
    // vec.push_back(normalize(getTotalOperator(f),getTotalLine(f)));
    // vec.push_back(normalize(getTotalLoop(f),getTotalLine(f)));
    // vec.push_back(normalize(getTotalCondition(f),getTotalLine(f)));
    // declaredVariables.clear();
    // vec.push_back(normalize(getTotalVariable(f,functionName,declaredVariables,dataType,commonLibraryFunctions),getTotalLine(f)));
    // vec.push_back(normalize(getTotalTypeCast(f,dataType),getTotalLine(f)));
    // vec.push_back(normalize(getTotalGlobalVariable(f,dataType,functionName),getTotalLine(f)));
    // vec.push_back(normalize(getTotalLineSpacingAroundOperators(f,operators),getTotalLine(f)));
    // vec.push_back(getAverageVariableLength(declaredVariables));
    // vec.push_back(getAverageLengthOfFunctionName(functionName));
    // for(auto v: vec){
    //     cout << v << " ";
    // }
    // cout << endl;
    // for(auto f: features){
    //     for(auto v: f){
    //         cout << v << " ";
    //     }
    //     cout << endl;
    // }
    // vector <int> lineCount;
    // vector <double> directiveCount;
    // vector <double> lib;
    // vector <double> var;
    // vector <double> ave;
    // for(auto f: fileName){
    //     lineCount.push_back(getTotalLine(f));
    //     directiveCount.push_back((getTotalDirective(f)*1.0)/getTotalLine(f));
    //     lib.push_back((getTotalLibraryFunction(f,commonLibraryFunctions)*1.0)/getTotalLine(f));
    //     functionName.clear();
    //     int p = getTotalFunctionPrototype(f,dataType,functionName);
    //     declaredVariables.clear();
    //     var.push_back(getTotalVariable(f,functionName,declaredVariables,dataType,commonLibraryFunctions));
    //     ave.push_back(getAverageVariableLength(declaredVariables));
    //     // cout << f << " " << getTotalLibraryFunction(f,commonLibraryFunctions) << endl;
    // }
    // // double mean = calculateMean(lib);
    // double sDev = calculateStandardDeviation(ave);
    // cout << sDev << endl;
    // // double lran = mean-(.1*sDev);
    // // double hran = mean-(.1*sDev);
    // string f = "binarytree.c";
    // functionName.clear();
    // declaredVariables.clear();
    // int p = getTotalFunctionPrototype(f,dataType,functionName);
    // int q = getTotalVariable(f,functionName,declaredVariables,dataType,commonLibraryFunctions);
    // double now = getAverageVariableLength(declaredVariables);
    // // double now = (getTotalLibraryFunction(f,commonLibraryFunctions)*1.0)/getTotalLine(f);
    // double x,y;
    // int c = 0;
    // for(auto l: lib){
    //     x = l - (sDev);
    //     y = l + (sDev);
    //     cout << x << " " << y << " " << now << endl;
    //     if(now>=x && now<=y){
    //         c++;
    //     }
    // }
    // cout << (c*100.0)/lib.size() << endl;
}