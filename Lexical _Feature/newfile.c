#include<stdio.h>
// 0 1 1 2 3 5 8 13.....
double fibNumber[1000];
double fib(int n){
    if(n<=1){
        fibNumber[n] = n;
        return n;
    }
    if(fibNumber[n]==0){
        double fibN = fib(n-1) + fib(n-2);
        fibNumber[n] = fibN;
        return fibN;
    }
    else{
        return fibNumber[n];
    }
}
int main(){
    int n;
    printf("Enter n: ");
    scanf("%d",&n);
    double res = fib(n);
    printf("%dth fib number is: %.1lf\n",n,res);
    for(int i=0; i<5; i++);
    return 0;
}