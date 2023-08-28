#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
struct node {
   int data;
   struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;

bool isEmpty(){
   return head == NULL;
}

int length(){
   int length = 0;
   if(head == NULL){
      return 0;
   }
   current = head;
   while(current->next !=current){
      length++;
      current = current->next;
   }
   return length;
}
void insertFirst(int data) {
   struct node *link = (struct node*) malloc(sizeof(struct node));
   link->data = data;
   link->next=NULL;
   if(isEmpty()){
      head = link;
      head->next = head;
   }
   else{
      link->next = head;
      head = link;
   }    
}
void deleteFirst(){
   struct node *tempLink = head;
   if(isEmpty())
      printf("List is empty\n");  
   else if(head->next == head){  
      head = NULL;
      return;
   }     
   head = head->next;
}
void printList() {
   struct node *ptr = head;
   printf("\n ");
   if(head != NULL){
      while(ptr->next != ptr){     
         printf("%d  ",ptr->data);
         ptr = ptr->next;
      }
   }
   printf("\n");
}
void main() {
   insertFirst(10);
   insertFirst(20);
   insertFirst(30);
   insertFirst(1);
   insertFirst(40);
   insertFirst(56); 
   printf("Original List: "); 
   printList();
   int x=length();
   printf("length is: %d\n",x);
   deleteFirst();
   printf("%d\n",length());
}