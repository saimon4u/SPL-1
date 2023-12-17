#include"main.cpp"
#include<filesystem>
using namespace std;

void readFile(string directory,vector<string> &f,vector<string>&printName){
    for(auto &entry: filesystem::directory_iterator(directory)){
        if(filesystem::is_regular_file(entry)){
            if(entry.path().extension() == ".c"){
                f.push_back(directory+"/"+entry.path().filename().string());
                printName.push_back(entry.path().filename().string());
            }
        }
    }
}
double normalize(int x,int y){
    double res = (x*1.0)/y;
    return res;
}
int p=0;
vector<vector<double>> extractor(string directoryPath){
    // string directoryPath = filesystem::current_path().string();
    vector <string> fileName;
    vector <string> printName;
    readFile(directoryPath,fileName,printName);
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
    



    vector <double> braceFollow;
    vector <double> braceNext;
    vector <double> spaceLine;
    vector <double> tabLine;



    vector <double> maximumNesting;
    vector <double> averageNesting;
    vector <double> maximumDeclare;
    vector <double> averageDeclare;



    vector <double> numberCycle;
    vector <double> numberComponents;
    vector <double> numberEdges;
    vector <double> cyclomaticVal;
    vector <double> depth;
    vector <double> fanIn;
    vector <double> fanOut;


    vector <vector <double> > features;
    double val = 0,avgNest = 0,avgDec = 0;
    int maxNest = 0,maxDec = 0;
    for(auto f: fileName){
        val = getTotalLine(f);
        if(isnan(val)) lineCount.push_back(0);
        else lineCount.push_back(val);

        val = getTotalKeyword(f,Keywords);
        if(isnan(val)) keywordCount.push_back(0);
        else keywordCount.push_back(normalize(val,getTotalLine(f)));
        directiveCount.push_back(normalize(getTotalDirective(f),getTotalLine(f)));


        val = getTotalDirective(f);
        if(isnan(val)) directiveCount.push_back(0);
        else directiveCount.push_back(normalize(val,getTotalLine(f)));


        val = getTotalIdentifier(f,Keywords);
        if(isnan(val)) identifierCount.push_back(0);
        else identifierCount.push_back(normalize(val,getTotalLine(f)));


        val = getTotalDataTyep(f,dataType);
        if(isnan(val)) datatypeCount.push_back(0);
        else datatypeCount.push_back(normalize(val,getTotalLine(f)));


        val = getTotalComment(f);
        if(isnan(val)) commentCount.push_back(0);
        else commentCount.push_back(normalize(val,getTotalLine(f)));


        functionName.clear();
        val = getTotalFunctionPrototype(f,dataType,functionName);
        if(isnan(val)) prototypeCount.push_back(0);
        else prototypeCount.push_back(normalize(val,getTotalLine(f)));


        val = getTotalFunctionDefinition(f,dataType,functionName);
        if(isnan(val)) definitionCount.push_back(0);
        else definitionCount.push_back(normalize(val,getTotalLine(f)));


        val = getTotalLibraryFunction(f,commonLibraryFunctions);
        if(isnan(val)) libraryCount.push_back(0);
        else libraryCount.push_back(normalize(val,getTotalLine(f)));


        val = getTotalFunctionParaMeter(f,dataType);
        if(isnan(val)) parameterCount.push_back(0);
        else parameterCount.push_back(normalize(val,getTotalLine(f)));


        val = getTotalMacro(f);
        if(isnan(val)) macroCount.push_back(0);
        else macroCount.push_back(normalize(val,getTotalLine(f)));

        val = getTotalOperator(f);
        if(isnan(val)) operatorCount.push_back(0);
        else operatorCount.push_back(normalize(val,getTotalLine(f)));

        val = getTotalLoop(f);
        if(isnan(val)) loopCount.push_back(0);
        else loopCount.push_back(normalize(val,getTotalLine(f)));

        val = getTotalCondition(f);
        if(isnan(val)) conditionCount.push_back(0);
        else conditionCount.push_back(normalize(val,getTotalLine(f)));

        declaredVariables.clear();
        val = getTotalVariable(f,functionName,declaredVariables,dataType,commonLibraryFunctions);
        if(isnan(val)) varCount.push_back(0);
        else varCount.push_back(normalize(val,getTotalLine(f)));

        val = getTotalTypeCast(f,dataType);
        if(isnan(val)) typecastCount.push_back(0);
        else typecastCount.push_back(normalize(val,getTotalLine(f)));

        val = getTotalGlobalVariable(f,dataType,functionName);
        if(isnan(val)) globalCount.push_back(0);
        else globalCount.push_back(normalize(val,getTotalLine(f)));
        

        val = getTotalLineSpacingAroundOperators(f,operators);
        if(isnan(val)) spacingOperators.push_back(0);
        else spacingOperators.push_back(normalize(val,getTotalLine(f)));

        val = getAverageVariableLength(declaredVariables);
        if(isnan(val)) averageVarLen.push_back(0);
        else averageVarLen.push_back(val);

        val = getAverageLengthOfFunctionName(functionName);
        if(isnan(val)) averageFunLen.push_back(0);
        else averageFunLen.push_back(val);






        if(followingCurlyBrace(f))braceFollow.push_back(1);
        else braceFollow.push_back(0);
        if(nextlineCurlyBrace(f))braceNext.push_back(1);
        else braceNext.push_back(0);
        if(spaceStartLine(f))spaceLine.push_back(1);
        else spaceLine.push_back(0);
        if(tabStartLine(f))tabLine.push_back(1);
        else tabLine.push_back(0);




        blockLength(f,maxNest,avgNest);
        if(isnan(maxNest)) maximumNesting.push_back(0);
        else maximumNesting.push_back(maxNest);
        if(isnan(avgNest)) averageNesting.push_back(0);
        else averageNesting.push_back(avgNest);



        longChainDeclaration(f,maxDec,avgDec,dataType,declaredVariables);
        if(isnan(maxDec)) maximumDeclare.push_back(0);
        else maximumDeclare.push_back(maxDec);
        if(isnan(avgDec)) averageDeclare.push_back(0);
        else averageDeclare.push_back(avgDec);






        // cout << f << endl;
        vector<vector<int>> graph = Graph(f);
        int numNode = graph.size();
        double numEdge = NumEdge(graph);
        numberEdges.push_back(numEdge);
        numberCycle.push_back(numCycle(graph));
        numberComponents.push_back(ConnectedComponents(graph));
        double numComponents = ConnectedComponents(graph);
        cyclomaticVal.push_back(CyclomaticComplexity(numNode,numEdge,numComponents));
        depth.push_back(DepthOfGraph(graph));
        fanIn.push_back(FanIn(numEdge,numNode));
        fanOut.push_back(FanOut(numEdge,numNode));

    }
    vector<double> vec;
    for(int i = 0; i < fileName.size(); i++){
        // vec.push_back(lineCount[i]);
        vec.push_back(keywordCount[i]);
        vec.push_back(directiveCount[i]);
        vec.push_back(identifierCount[i]);
        vec.push_back(datatypeCount[i]);
        vec.push_back(commentCount[i]);
        vec.push_back(prototypeCount[i]);
        vec.push_back(definitionCount[i]);
        vec.push_back(libraryCount[i]);
        vec.push_back(parameterCount[i]);
        vec.push_back(macroCount[i]);
        vec.push_back(operatorCount[i]);
        vec.push_back(loopCount[i]);
        vec.push_back(conditionCount[i]);
        vec.push_back(varCount[i]);
        vec.push_back(typecastCount[i]);
        vec.push_back(globalCount[i]);
        vec.push_back(spacingOperators[i]);
        vec.push_back(averageVarLen[i]);
        vec.push_back(averageFunLen[i]);
        vec.push_back(braceFollow[i]);
        vec.push_back(braceNext[i]);
        vec.push_back(spaceLine[i]);
        vec.push_back(tabLine[i]);
        vec.push_back(maximumNesting[i]);
        vec.push_back(averageNesting[i]);
        vec.push_back(maximumDeclare[i]);
        vec.push_back(averageDeclare[i]);
        vec.push_back(numberCycle[i]);
        vec.push_back(numberComponents[i]);
        vec.push_back(numberEdges[i]);
        vec.push_back(cyclomaticVal[i]);
        vec.push_back(depth[i]);
        vec.push_back(fanIn[i]);
        vec.push_back(fanOut[i]);
        features.push_back(vec);
        vec.clear();
        // cout << fileName[i] << endl;
    }
    if(p==0){
        cout << "Files you try to identify -> " << endl;
        for(auto p: printName){
            cout << p << endl;
        }
        cout << endl << endl;
        p++;
    }
    // else {
    //     features = {keywordCount,directiveCount,identifierCount,datatypeCount,commentCount,prototypeCount,definitionCount,
    //             libraryCount,parameterCount,macroCount,operatorCount,loopCount,conditionCount,varCount,typecastCount,
    //             globalCount,spacingOperators,averageVarLen,averageFunLen};
    // }
    return features;
}