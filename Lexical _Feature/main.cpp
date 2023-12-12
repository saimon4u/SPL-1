#include<iostream>
#include<set>
#include<regex>
#include<fstream>
#include<sstream>
#include<vector>
#include<numeric>
#include<filesystem>
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
#include"VariableCount.cpp"
#include"TypeCastCount.cpp"
#include"GlobalVariableCount.cpp"
#include"SpacingAroundOperatorCount.cpp"
#include"AverageVariableLength.cpp"
#include"AverageLengthOfFunctionName.cpp"
#include"../Syntactical_Features/FunctionLength.cpp"
// #include"../Syntactical_Features/BlockLength.cpp"
#include"../Syntactical_Features/Nesting.cpp"
#include"../Syntactical_Features/LongChain.cpp"
#include"../Syntactical_Features/BlockLength.cpp"
#include"ConditionCount.cpp"
#include"LoopCount.cpp"
#include"../Features/BraceFollow.cpp"
#include"../Features/BraceNext.cpp"
#include"../Features/SpaceLine.cpp"
#include"../Features/TabLine.cpp"
using namespace std;


// int main(){



    set <string> operators = {
        "+", "-", "*", "/", "%", "==", "!=", "<", ">", "<=", ">=", "&&", "||", "!",
        "&", "|", "^", "~", "<<", ">>", "=", "+=", "-=", "*=", "/=", "%=", "&=", "|=", "^=",
        "<<=", ">>=","->", ":", "?"
    };



    set <string> Keywords = {
        "auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else",
        "enum", "extern", "float", "for", "goto", "if", "int", "long", "register", "return",
        "short", "signed", "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned",
        "void", "volatile", "while","include"
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

    // string filename = "newfile.c";

    int totalLine;
    // int numOfKeyword = getTotalKeyword(filename,Keywords);
    // int numOfDirectives = getTotalDirective(filename);
    // int numOfIdentifier = getTotalIdentifier(filename,Keywords);
    // int numOfDataType = getTotalDataTyep(filename,dataType);
    // int numOfCommentLine = getTotalComment(filename);
    // int numOfFunctionPrototype = getTotalFunctionPrototype(filename,dataType,functionName);
    // int numOfFunctionDefinition = getTotalFunctionDefinition(filename,dataType,functionName);
    // int numOfLibraryFunction = getTotalLibraryFunction(filename,commonLibraryFunctions);
    // int numOfFunctionParameter = getTotalFunctionParaMeter(filename,dataType);
    // int numOfMacro = getTotalMacro(filename);
    // int numOfOperator = getTotalOperator(filename);
    // int numOfLoop = getTotalLoop(filename);
    // int numOfCondition = getTotalCondition(filename);
    // int numOfVariable = getTotalVariable(filename,functionName,declaredVariables,dataType,commonLibraryFunctions);
    // int numOfTypeCast = getTotalTypeCast(filename,dataType);
    // int numOfGlobalVariable = getTotalGlobalVariable(filename,dataType,functionName);
    // int numOfLineSpacingAroundOperators = getTotalLineSpacingAroundOperators(filename,operators);
    // int maxFunctionLength = 0;
    // int maxNestingLevel = 0;
    // int maxVarDeclared = 0;
    // double averageVariableLength = getAverageVariableLength(declaredVariables);
    // double averageFunctionLength = getAverageLengthOfFunctionName(functionName);
    // double averageFunctionNameLength = 0.0;
    // double averageNestingLevel = 0.0;
    // double averageVarDeclare = 0.0;

    // vector <int> v = blockLength(filename);
    // maxNestingLevel = *max_element(v.begin(),v.end());
    // double total = 0.0;
    // total = accumulate(v.begin(),v.end(),total);
    // averageNestingLevel = total/v.size();
    // functionLength(filename,0,dataType,averageFunctionLength,maxFunctionLength);
    // // blockLength(filename,maxNestingLevel,averageNestingLevel);
    // longChainDeclaration(filename,maxVarDeclared,averageVarDeclare,dataType,declaredVariables);



    // cout << "1.NumOfLine = " << totalLine << endl;
    // cout << "2.NumofKeywords = " << numOfKeyword << endl;
    // cout << "3.NumofDirectives = " << numOfDirectives << endl;
    // cout << "4.NumofIndentifier = " << numOfIdentifier << endl;
    // cout << "5.NumofDataType = " << numOfDataType << endl;
    // cout << "6.NumofCommentLine = " << numOfCommentLine << endl;
    // cout << "7.NumofFunctionProtoType = " << numOfFunctionPrototype << endl;
    // cout << "8.NumofFunctionDefinition = " << numOfFunctionDefinition << endl;
    // cout << "9.NumofLibraryFunction = " << numOfLibraryFunction << endl;
    // cout << "10.NumofFunctionParameter = " << numOfFunctionParameter << endl;
    // cout << "11.NumofMacroDefinition = " << numOfMacro << endl;
    // cout << "12.NumofOperator = " << numOfOperator << endl;
    // cout << "13.NumofLoop = " << numOfLoop << endl;
    // cout << "14.NumofCondition = " << numOfCondition << endl;
    // cout << "15.NumofVariable = " << numOfVariable << endl;
    // cout << "16.NumofTypeCast = " << numOfTypeCast << endl;
    // cout << "17.NumofGlobalVariable = " << numOfGlobalVariable << endl;
    // cout << "18.NumofLineSpacingAroundOperators = " << numOfLineSpacingAroundOperators << endl;
    // cout << "19.AverageLengthOfVariable = " << averageVariableLength << endl;
    // cout << "20.AverageLengthOfFunctionName = " << averageFunctionNameLength << endl;
    // cout << "21.AverageFunctionLength = " << averageFunctionLength << endl;
    // cout << "22.MaximumFunctionLength = " << maxFunctionLength << endl;
    // cout << "23.AverageNestingLevel = " << averageNestingLevel << endl;
    // cout << "24.MaximumNestingLevel = " << maxNestingLevel << endl;
    // cout << "25 MaximumVarDeclaration = " << maxVarDeclared << endl;
    // cout << "26 AverageVarDeclaration = " << averageVarDeclare << endl;
//     return 0;
// }