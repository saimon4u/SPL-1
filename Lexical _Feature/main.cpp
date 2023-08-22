#include<iostream>
#include<set>
#include<regex>
#include<fstream>
#include<sstream>
#include<vector>
#include<numeric>
#include<unordered_set>
#include"Tokenize.cpp"
#include"LineCount.cpp"
#include"KeywordCount.cpp"
#include"DirectivesCount.cpp"
#include"DataTypeCount.cpp"
#include"IdentifierCount.cpp"
#include"CommentCount.cpp"
#include"ProtoTypeCount.cpp"
#include"FunctionDefinitionCount.cpp"
#include"LibraryFunctionCount.cpp"
#include"ParameterCount.cpp"
#include"MacroCount.cpp"
#include"OperatorCount.cpp"
#include"LoopConditionCount.cpp"
#include"VariableCount.cpp"
#include"TypeCastCount.cpp"
#include"GlobalVariableCount.cpp"
#include"SpacingAroundOperatorCount.cpp"
#include"AverageVariableLength.cpp"
#include"AverageLengthOfFunctionName.cpp"
#include"../Syntactical_Features/FunctionLength.cpp"
#include"../Syntactical_Features/BlockLength.cpp"
using namespace std;


int main(){



    set <string> operators = {
        "+", "-", "*", "/", "%", "==", "!=", "<", ">", "<=", ">=", "&&", "||", "!",
        "&", "|", "^", "~", "<<", ">>", "=", "+=", "-=", "*=", "/=", "%=", "&=", "|=", "^=",
        "<<=", ">>=","->", ":", "?"
    };



    set <string> Keywords = {
        "auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else",
        "enum", "extern", "float", "for", "goto", "if", "int", "long", "register", "return",
        "short", "signed", "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned",
        "void", "volatile", "while"
    };


    set <string> dataType = {
        "int","float","double","char","void","unsigned","long","signed","const","static","short"
    };


    set <string> functionName = {"main"};


    set <string> declaredVariables;



    set<string> commonLibraryFunctions = {
        "printf","scanf","malloc",
        "free","calloc","realloc",
        "strlen","strcpy","strncpy",
        "strcat","strncat","strcmp",
        "strncmp","sprintf","sscanf",
        "fopen","fclose","fread",
        "fwrite","fgets","fputs",
        "fscanf","fprintf","getchar",
        "putchar","getch","putch",
        "getche","puts","system",
        "atoi","atof","isdigit",
        "isalpha","isalnum","islower",
        "isupper","tolower","toupper",
        "rand","srand","time","abs",
        "labs","sqrt","pow","ceil",
        "floor","fabs","log","log10",
        "exp","sin","cos","tan","asin",
        "acos","atan","atan2","exit",
        "getenv","system","memcpy",
        "memmove","memset","memchr",
        "memcmp"
    };


    int totalLine = 0;
    int numOfKeyword = 0;
    int numOfDirectives = 0;
    int numOfIdentifier = 0;
    int numOfDataType = 0;
    int numOfCommentLine = 0;
    int numOfFunctionPrototype = 0;
    int numOfFunctionDefinition = 0;
    int numOfLibraryFunction = 0;
    int numOfFunctionParameter = 0;
    int numOfMacro = 0;
    int numOfOperator = 0;
    int numOfLoop = 0;
    int numOfCondition = 0;
    int numOfVariable = 0;
    int numOfTypeCast = 0;
    int numOfGlobalVariable = 0;
    int numOfLineSpacingAroundOperators = 0;
    int maxFunctionLength = 0;
    int maxNestingLevel = 0;
    double averageVariableLength = 0.0;
    double averageFunctionLength = 0.0;
    double averageNestingLevel = 0.0;

    string filename = "input.c";


    getTotalLine(filename,totalLine);
    getTotalKeyword(filename,numOfKeyword,Keywords);
    getTotalDirective(filename,numOfDirectives);
    getTotalDataTyep(filename,numOfDataType,dataType);
    getTotalIdentifier(filename,numOfIdentifier,Keywords);
    getTotalComment(filename,numOfCommentLine);
    getTotalFunctionPrototype(filename,numOfFunctionPrototype,dataType,functionName);
    getTotalFunctionDefinition(filename,numOfFunctionDefinition,dataType,functionName);
    getTotalLibraryFunction(filename,numOfLibraryFunction,commonLibraryFunctions);
    getTotalFunctionParaMeter(filename,numOfFunctionParameter,dataType);
    getTotalMacro(filename,numOfMacro);
    getTotalOperator(filename,numOfOperator);
    getTotalLoopCondition(filename,numOfLoop,numOfCondition);
    getTotalVariable(filename,numOfVariable,functionName,declaredVariables);
    getTotalTypeCast(filename,numOfTypeCast,dataType);
    getTotalGlobalVariable(filename,numOfGlobalVariable);
    getAverageVariableLength(declaredVariables,averageVariableLength);
    getTotalLineSpacingAroundOperators(filename,numOfLineSpacingAroundOperators,operators);
    getAverageLengthOfFunctionName(averageFunctionLength,functionName);
    functionLength(filename,0,dataType,averageFunctionLength,maxFunctionLength);
    blockLength(filename,maxNestingLevel,averageNestingLevel);



    cout << "1.NumOfLine = " << totalLine << endl;
    cout << "2.NumofKeywords = " << numOfKeyword << endl;
    cout << "3.NumofDirectives = " << numOfDirectives << endl;
    cout << "4.NumofIndentifier = " << numOfIdentifier << endl;
    cout << "5.NumofDataType = " << numOfDataType << endl;
    cout << "6.NumofCommentLine = " << numOfCommentLine << endl;
    cout << "7.NumofFunctionProtoType = " << numOfFunctionPrototype << endl;
    cout << "8.NumofFunctionDefinition = " << numOfFunctionDefinition << endl;
    cout << "9.NumofLibraryFunction = " << numOfLibraryFunction << endl;
    cout << "10.NumofFunctionParameter = " << numOfFunctionParameter << endl;
    cout << "11.NumofMacroDefinition = " << numOfMacro << endl;
    cout << "12.NumofOperator = " << numOfOperator << endl;
    cout << "13.NumofLoop = " << numOfLoop << endl;
    cout << "14.NumofCondition = " << numOfCondition << endl;
    cout << "15.NumofVariable = " << numOfVariable << endl;
    cout << "16.NumofTypeCast = " << numOfTypeCast << endl;
    cout << "17.NumofGlobalVariable = " << numOfGlobalVariable << endl;
    cout << "18.NumofLineSpacingAroundOperators = " << numOfLineSpacingAroundOperators << endl;
    cout << "19.AverageLengthOfVariable = " << averageVariableLength << endl;
    cout << "20.AverageLengthOfFunctionName = " << averageFunctionLength << endl;
    cout << "21.AverageFunctionLength = " << averageFunctionLength << endl;
    cout << "22.MaximumFunctionLength = " << maxFunctionLength << endl;
    cout << "23.AverageNestingLevel = " << averageNestingLevel << endl;
    cout << "24.MaximumNestingLevel = " << maxNestingLevel << endl;
    return 0;
}