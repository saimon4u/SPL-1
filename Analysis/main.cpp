#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<double> vec = {.4,.1,2.5,.2,.0,.0,.0,.2,.1,.0,1.1,.1,.0,.3,.0};
    vector<double> two = {.7,.1,1.5,.3,.0,.0,.1,.4,.0,.0,.8,.0,.1,.1,.0};
    double res = 0.0;
    for(int i=0; i<vec.size(); i++){
        res += pow((vec[i]-two[i]),2);
    }
    cout << sqrt(res) << endl;
    return 0;
}