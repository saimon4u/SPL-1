#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define loop(i,n) for (int i = 0; i < n; i++)
using namespace std;
double evaluate(string &exp){
    stack <double> s;
    int start = 0;
    int length = 0;
    //5 6 2 + * 12 4 / -
    for(int i=0; i<=exp.size(); i++){
        if(exp[i]!=' ' && i!=exp.size()){
            length++;
        }
        else{
            char temp[length];
            exp.copy(temp,length,start);
            temp[length]='\0';
            if(length>1){
                s.push(stod(temp));
                start = i+1;
                length = 0;
            }
            else if(isdigit(temp[0])){
                s.push(stod(temp));
                start = i+1;
                length = 0;
            }
            else{
                double value1 = s.top();
                s.pop();
                double value2 = s.top();
                s.pop();
                switch(temp[0]){
                    case '+':
                        s.push(value2+value1);
                        break;
                    case '-':
                        s.push(value2-value1);
                        break;
                    case '*':
                        s.push(value2*value1);
                        break;
                    case '/':
                        s.push(value2/value1);
                        break;
                }
            }
            start = i+1;
            length = 0;
        }
    }
    return s.top();
}
int main(){
    string exp = "5 6 2 + * 18 4 / -";
    cout << "Result: " << evaluate(exp) << endl;
    return 0;
}