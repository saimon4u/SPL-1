#include<iostream>
using namespace std;
void enqueue(int *arr, int *front, int *rear,int size){
    int value;
    cout << "Enter value: ";
    cin >> value;
    if(*rear == size){
        *rear=0;
        arr[*rear] = value;
        (*rear)++;
    }
    else if(*front == *rear+1){
        cout << "CQueue Overflow!" << endl;
        return;
    }
    else{
        arr[*rear]= value;
        (*rear)++;
    }
}
void dequeue(int *arr, int *front, int *rear, int size){
    int value;
    if(*front==0){
        cout << "CQueue Underflow!" << endl;
        return ;
    }
    value = arr[*front];
    if(*front==size){
        *front=0;
        return;
    }
    else if(*front==*rear){
        *front=0;
        *rear=0;
    }
    *front++;
    return;
}
void display(int *arr,int front,int rear){
    cout << "Element of CQueue are: " << endl;
    while(front<rear){
        cout << arr[front] << "\t" ;
        front++;
    }
    cout << endl;
}
int main(){
    int size=10;
    int front=0,rear=0;
    int arr[size];
    int choice;
    while(1){
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice){
            case 1:
                enqueue(arr,&front,&rear,size);
                break;
            case 2:
                dequeue(arr,&front,&rear,size);
                break;
            case 3:
                display(arr,front,rear);
                break;
            case 4:
                exit(0);
        }
    }
}