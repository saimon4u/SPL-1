#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define loop(i,n) for (int i = 0; i < n; i++)
using namespace std;
struct Account{
    string name;
    int accountNumber;
    string type;
    int balance;
    Account *next;
};
Account *head = NULL;
bool IsExists(int accountNumber){
    Account *ptr = head;
    while(ptr!=NULL){
        if(ptr->accountNumber == accountNumber){
            cout << "Account already exists" << endl;
            return true;
        }
        ptr = ptr->next;
    }
    return false;
}
void link(Account *curr){
    Account *ptr = head;
    while(ptr->next!=NULL) ptr = ptr->next;
    ptr->next = curr;
}
void AddAccount(){
    Account *ptr = (Account *) malloc(sizeof(Account));
    cout << "Enter Name: ";
    cin >> ptr->name;
    cout << "Enter Account Number: ";
    cin >> ptr->accountNumber;
    if(IsExists(ptr->accountNumber)) return;
    cout << "Enter Account type: ";
    cin >> ptr->type;
    cout << "Enter Initial balance: ";
    cin >> ptr->balance;
    ptr->next = NULL;
    link(ptr);
}
int main(){
    
    return 0;
}