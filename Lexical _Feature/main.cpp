#include<iostream>
#include<set>
#include<regex>
#include<fstream>
#include<sstream>
#include<vector>
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
using namespace std;


int main(){
    set <string> Keywords = {
        "auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else",
        "enum", "extern", "float", "for", "goto", "if", "int", "long", "register", "return",
        "short", "signed", "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned",
        "void", "volatile", "while"
    };


    set <string> dataType = {
        "int","float","double","char","void","unsigned","long"
    };


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


    string filename = "input.c";


    getTotalLine(filename,totalLine);
    getTotalKeyword(filename,numOfKeyword,Keywords);
    getTotalDirective(filename,numOfDirectives);
    getTotalDataTyep(filename,numOfDataType,dataType);
    getTotalIdentifier(filename,numOfIdentifier,Keywords);
    getTotalComment(filename,numOfCommentLine);
    getTotalFunctionPrototype(filename,numOfFunctionPrototype,dataType);
    getTotalFunctionDefinition(filename,numOfFunctionDefinition,dataType);
    getTotalLibraryFunction(filename,numOfLibraryFunction,commonLibraryFunctions);
    getTotalFunctionParaMeter(filename,numOfFunctionParameter,dataType);
    getTotalMacro(filename,numOfMacro);
    getTotalOperator(filename,numOfOperator);
    getTotalLoopCondition(filename,numOfLoop,numOfCondition);






    cout << "NumOfLine = " << totalLine << endl;
    cout << "NumofKeywords = " << numOfKeyword << endl;
    cout << "NumofDirectives = " << numOfDirectives << endl;
    cout << "NumofIndentifier = " << numOfIdentifier << endl;
    cout << "NumofDataType = " << numOfDataType << endl;
    cout << "NumofCommentLine = " << numOfCommentLine << endl;
    cout << "NumofFunctionProtoType = " << numOfFunctionPrototype << endl;
    cout << "NumofFunctionDefinition = " << numOfFunctionDefinition << endl;
    cout << "NumofLibraryFunction = " << numOfLibraryFunction << endl;
    cout << "NumofFunctionParameter = " << numOfFunctionParameter << endl;
    cout << "NumofMacroDefinition = " << numOfMacro << endl;
    cout << "NumofOperator = " << numOfOperator << endl;
    cout << "NumofLoop = " << numOfLoop << endl;
    cout << "NumofCondition = " << numOfCondition << endl;
    return 0;
}