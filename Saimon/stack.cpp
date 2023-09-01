#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define loop(i,n) for (int i = 0; i < n; i++)
using namespace std;
int n = 5;
void push(int *top,int *arr){
    if(*top==n){
        cout << "Stack Overflow!" << endl;
        return;
    }
    int value;
    cout << "Enter value to push: ";
    cin >> value;
    arr[*top] = value;
    (*top)++;
}
void pop(int *top,int *arr){
    if(*top==0){
        cout << "Stack Underflow!" << endl;
        return;
    }
    (*top)--;
}
void display(int top,int *arr){
    if(top==0){
        cout << "Stack is empty!" << endl;
        return;
    }
    cout << "Value of stack are: " << endl;
    for(int i=0; i<top; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main(){
    int arr[n];
    int choice;
    int top=0;
    while(1){
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: "; 
        cin >> choice;
        switch(choice){
            case 1:
                push(&top,arr);
                break;
            case 2:
                pop(&top,arr);
                break;
            case 3:
                display(top,arr);
                break;
            case 4:
                exit(0);
        }
    }
    return 0;
}