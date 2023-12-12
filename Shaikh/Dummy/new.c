// #include<stdio.h>
// #include<stdlib.h>

// struct Student{
//     int marks;
//     int roll;
//     struct Student *next;
// };

// struct Student *head = NULL;

// void inputFunc(struct Student a[]){ // add size to do it dynamically
//     for(int i = 0; i < 5; i++){
//         a[i].roll = i+1+1400;
//         scanf("%d",&a[i].marks);
//         a[i].next = NULL;
//     }
// }

// void sort(int a[], int size){
//     int temp;
//     for(int i = 0; i < size; i++){
//         for(int j =0; j < size - 1; j++){
//             if(a[j] < a[j+1]){
//                 temp = a[j];
//                 a[j] = a[j+1];
//                 a[j+1] = temp;
//             }
//         }
//     }
// }

// void printArray(int a[], int size){
//     for(int i =0; i<size; i++){
//         printf("%d\t",a[i]);
//     }
//     printf("\n");
// }

// void traverseList(struct Student* head){
//     //struct Student p = (struct Student) malloc(sizeof(struct Student));
    
//     int i = 0;
//     while(i < 5){
//         printf("%d\t%d", head->roll, head->marks);
//     }
// }

// int main(){

//     struct Student a[5];
//     //head.next = &a[0];
//     int temp_marks[5];

//     inputFunc(a);
    
//     for(int i = 0; i < 5; i++){
//         printf("%d\t%d\n", a[i].roll, a[i].marks);
//     }

//     for(int i =0; i<5; i++){
//         temp_marks[i] = a[i].marks;
//     }
    
//     printArray(temp_marks, 5);
//     //sort temp_marks
//     sort(temp_marks, 5);

//     printf("Sorted Marks\n");
//     // for(int i =0; i< 5; i++){
//     //     printf("%d\t", temp_marks[i]);
//     // }
//     printArray(temp_marks,5);

//     int index[5];

//     for(int j = 0; j < 5; j++){
//         for(int i = 0; i < 5; i++){
//             if(temp_marks[j] == a[i].marks)  index[j] = a[i].roll;
//         }
//     }
    
//     printArray(index, 5);

//     // head = &a[index[0]-1];
//     // printf("%d\t%d\n", head->roll, head->marks);

//     //printf("%d ", a[index[0] - 1 - 1400].marks);

//     for(int i = 0; i < 5; i++){
//         printf("Roll no %d got %d marks!\n",index[i] ,a[index[i] - 1 - 1400].marks);
//     }

//     // head = &a[index[0 - 1 - 1400]];

//     // printf("%d \t %d", head->roll, head->marks);
//     head = (struct Student*) malloc(sizeof(struct Student));

//     head = &a[index[0]- 1 - 1400];
//     printf("%d-->",head->roll);

//     struct Student *Current = (struct Student*) malloc(sizeof(struct Student));
//     head->next = Current;
//     printf("%d-->", Current->roll);
//     // int i = 1;
//     // do{
//     //     Current = &a[index[i]- 1 - 1400];
//     //     printf("%d-->",Current->roll);
//     //     Current = Current -> next;
//     //     i++;
//     // }while(index[i] > 0);                                                                                  

//     // Current->next = NULL;

//     // printf("%p",Current->next);

//     // struct Student ptr = (struct Student) malloc(sizeof(struct Student));
//     // ptr = head;
//     // printf("...%d....\n", ptr->marks);
//     // while(ptr!= NULL){
//     //     printf("%d\t", ptr->marks);
//     //     ptr = ptr->next;
//     // }
    

//     //traverseList(head); 


//     return 0;
// }


#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct stack{
    int size;
    int top;
    int *arr;
};

bool isEmpty(struct stack *ptr);
bool isFull(struct stack *ptr);
void push(struct stack *ptr, int value);
int pop(struct stack *ptr);
int peek(struct stack *ptr, int position);
int stackTop(struct stack *s);
int stackBottom(struct stack *s);

int main(){
    
    // struct stack s;
    // s.size = 10;
    // s.top = -1;
    // s.arr = (int *) malloc(sizeof(int) * s.size);
    struct stack *s = (struct stack*) malloc(sizeof(struct stack));
    s->size = 10;
    s->top = -1; //since, at this point there is no element in the stack
    s->arr = (int *) malloc(sizeof(int) * s->size);
    printf("Stack Created successfully!\n");
    
    // printf("Manual push:\n");
    // s->arr[0] = 40;
    // s->top++;
    printf("%d \n", isEmpty(s)); // Checked if isEmpty is working or not!
    //printf("At the Top of the stack:%d\n", s->arr[0]);
    printf("Before pushing: Full? %d and Empty? %d\n",isFull(s),isEmpty(s));
    push(s,10);
    push(s,20);
    push(s,30);
    push(s,40);
    push(s,50);
    push(s,60);
    push(s,70);
    push(s,80);
    push(s,90);
    push(s,100);
    //push(s,110);

    printf("After pushing: Full? %d and Empty? %d\n",isFull(s),isEmpty(s));

    // if(isEmpty(s)){
    //     printf("The stack is empty!\n");
    // }else printf("The stack is not empty!\n");

    // if(isFull(s)){
    //     printf("The stack is full!\n");
    // }else printf("The stack is not full!\n");


    // printf("%d popped from the stack\n", pop(s));
    // printf("%d popped from the stack\n", pop(s));
    // printf("%d popped from the stack\n", pop(s));
    // printf("%d popped from the stack\n", pop(s));
    // printf("%d popped form the stack\n", pop(s));
    // printf("%d popped form the stack\n", pop(s));
    // printf("%d popped form the stack\n", pop(s));    
    // printf("%d popped form the stack\n", pop(s));
    // printf("%d popped form the stack\n", pop(s));
    // printf("%d popped form the stack\n", pop(s));    
    // printf("%d popped form the stack\n", pop(s));  

    for(int i = 0; i < s->size; i++){
        printf("Value at position %d is : %d\n", i+1, peek(s, i+1));
    }  
    printf("%d is at the top of the stack\n", stackTop(s));
    printf("%d is at the bottom of the stack\n", stackBottom(s));

    return 0;
}

bool isEmpty(struct stack *ptr){
    if(ptr->top == -1){
        return true;
    }else return false;
}

bool isFull(struct stack *ptr){
    if(ptr -> top == ptr->size - 1){
        return true;
    }else return false;
}

void push(struct stack *ptr,int value){
    if(isFull(ptr)){
        printf("Stack Overflow!\nCannot push the value %d\n", value);
    }else {
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}

int pop(struct stack *ptr){
    if(isEmpty(ptr)){
        return -1;
    }
    else{
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int peek(struct stack *ptr, int position){
    int arrIndex = ( ptr->top - position + 1 );
    if( arrIndex < 0 ){
        printf("Not a valid position!\n");
    }else{
        return ptr->arr[arrIndex];
    }
}

int stackTop(struct stack* s){
    return s->arr[s->top];
}

int stackBottom(struct stack *s){
    return s->arr[0];
}