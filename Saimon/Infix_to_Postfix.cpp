#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define loop(i,n) for (int i = 0; i < n; i++)
using namespace std;
int main(){
    string infix = "6 * ( 10 + 2 ) - 5 + ( 7 * 4 ) + 2 / 3";
    stack <string> s;
    queue <string> res;
    map <char,int> mapping;
    mapping['*'] = 4;
    mapping['/'] = 3;
    mapping['+'] = 2;
    mapping['-'] = 1;
    int start = 0;
    int length = 0;
    for(int i=0; i<=infix.size(); i++){
        int length = 0;
        while(infix[i]!=' ' && i!=infix.size()){
            length++;
            i++;
        }
        char out[length+1];
        infix.copy(out,length,start);
        out[length] = '\0';
        length = 0;
        start = i+1;
        if(isdigit(out[0])) res.push(out);
        else if(out[0]=='*' || out[0]=='/' || out[0]=='+' || out[0]=='-'){
            if(s.empty())s.push(out);
            else{
                string abc = s.top();
                if(abc[0]=='*' || abc[0]=='/' || abc[0]=='+' || abc[0]=='-'){
                    while(mapping[out[0]]<mapping[abc[0]]){
                        res.push(abc);
                        s.pop();
                        if(!s.empty()) abc = s.top();
                        else break;
                    }
                }
                s.push(out);
            }
        }
        if(out[0]=='(')s.push(out);
        if(out[0]==')'){
            string abc = s.top();
            while(abc[0]!='('){
                res.push(abc);
                s.pop();
                abc = s.top();
            }
            s.pop();
        }
    }
    while(!s.empty()){
        string abc = s.top();
        res.push(abc);
        s.pop();
    }
    while(!res.empty()){
        cout << res.front() << " ";
        res.pop();
    }
    cout << endl;
    // while(!s.empty()){
    //     cout << s.top() << " ";
    //     s.pop();
    // }
    // cout << endl;
    return 0;
}