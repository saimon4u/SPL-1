#include<iostream>
using namespace std;
void Enqueue(int *arr,int *rear,int size){
    int value;
    cout << "Enter value to insert: ";
    cin >> value;
    if(*rear==size){
        cout << "Overflow!" << endl;
        return ;
    }
    else{
        arr[*rear] = value;
        (*rear)++;
    }
}
void Dequeue(int *arr, int *front,int size){
    int value;
    if(*front == size+1){
        cout << "Underflow!" << endl;
        return ;
    }
    else{
        value = arr[*front];
        (*front)++;
    }
}
void display(int *arr,int front, int rear){
    cout << "Current queue is: " << endl;
    while(front<rear){
        cout << arr[front] << "\t";
        front++;
    }
    cout << endl;
}
int main(){
    int size=10;
    int arr[size];
    int choice;
    int front=0,rear=0;
    while(1){
        cout << "1. Insert" << endl;
        cout << "2. Delete" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: "; 
        cin >> choice;
        switch(choice){
            case 1:
                Enqueue(arr,&rear,size);
                break;
            case 2:
                Dequeue(arr,&front,size);
                break;
            case 3:
                display(arr,front,rear);
                break;
            case 4:
                exit(0);
        }
    }
    return 0;
}