#include<iostream>
using namespace std;
struct node{
    int value;
    struct node *next;
};
struct node *head=NULL;
void create_new_link();
void display_the_existing_nodes();
void insert_at_beginning();
void insert_at_end();
void insert_at_any_position();
void delete_from_beginning();
void delete_from_end();
void delete_from_any_position();
void search_a_value();
void get_length();
int main(){
    int choice;
    while(1){
        cout << endl << "                MENU" << endl;
        cout << "1. Create New Link" << endl;
        cout << "2. Display the existing nodes" << endl;
        cout << "3. Insert at the beginning" << endl;
        cout << "4. Insert at the end" << endl;
        cout << "5. Insert at any position" << endl;
        cout << "6. Delete from the beginning" << endl;
        cout << "7. Delete from the end" << endl;
        cout << "8. Delete from any position" << endl;
        cout << "9. Search a value" << endl;
        cout << "10. Get current length of the list" << endl;
        cout << "11. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice){
            case 1:
                create_new_link();
                break;
            case 2:
                display_the_existing_nodes();
                break;
            case 3:
                insert_at_beginning();
                break;
            case 4:
                insert_at_end();
                break;
            case 5:
                insert_at_any_position();
                break;
            case 6:
                delete_from_beginning();
                break;
            case 7:
                delete_from_end();
                break;
            case 8:
                delete_from_any_position();
                break;
            case 9:
                search_a_value();
                break;
            case 10:
                get_length();
                break;
            case 11:
                exit(0);
                break;
            default:
                cout << "Wrong Choice" << endl;
                break;
        }
    }
    return 0;
}
void create_new_link(){
    struct node *ptr,*temp;
    ptr=(struct node *)malloc(sizeof(struct node));
    cout << "Enter the value for new node: ";
    cin >> ptr->value;
    ptr->next=NULL;
    if(head==NULL)
        head=ptr;
    else{
        temp=head;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=ptr;
    }
}
void display_the_existing_nodes(){
    struct node *ptr;
    if(head==NULL){
        cout << endl << "List is empty" << endl;
        return ;
    }
    else{
        ptr=head;
        cout << endl << "The nodes are: " << endl;
        while(ptr!=NULL){
            cout << ptr->value << "\t";
            ptr=ptr->next;
        }
        cout << endl;
    }
}
void insert_at_beginning(){
    struct node *ptr;
    ptr=(struct node *)malloc(sizeof(struct node));
    cout << "Enter value for new node" << endl;
    cin >> ptr->value;
    ptr->next=NULL;
    if(head==NULL)
        head=ptr;
    else{
        ptr->next=head;
        head=ptr;
    }
}
void insert_at_end(){
    struct node *ptr,*temp;
    ptr=(struct node *)malloc(sizeof(struct node));
    cout << "Enter value for new node: ";
    cin >> ptr->value;
    ptr->next=NULL;
    if(head==NULL)
        head=ptr;
    else{
        temp=head;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=ptr;
    }
}
void insert_at_any_position(){
    struct node *ptr,*temp;
    int i=0,position;
    ptr=(struct node *)malloc(sizeof(struct node));
    cout << "Enter the position for new node[index based]: ";
    cin >> position;
    cout << "Enter value for new node: ";
    cin >> ptr->value;
    ptr->next=NULL;
    if(position==0){
        ptr->next=head;
        head=ptr;
    }
    else{
        temp=head;
        while(i<position-1){
            temp=temp->next;
            if(temp==NULL){
                cout << endl << "Position didn't exists" << endl;
                return ;
            }
            i++;
        }
        ptr->next=temp->next;
        temp->next=ptr;
    }
}
void delete_from_beginning(){
    struct node *ptr;
    if(head==NULL){
        cout << endl << "List is empty" << endl;
        return;
    }
    else{
        ptr=head;
        head=head->next;
        cout << endl << "Deleted Value is: " << ptr->value << endl;
        free(ptr);
    }
}
void delete_from_end(){
    struct node *ptr,*temp;
    if(head==NULL){
        cout  << endl << "List is empty" << endl;
        return ;
    }
    else if(head->next==NULL){
        ptr=head;
        head=NULL;
        cout << endl << "Deleted value is: " << ptr->value << endl;
        free(ptr);
    }
    else{
        temp=head;
        while(temp->next!=NULL){
            ptr=temp;
            temp=temp->next;
        }
        ptr->next=NULL;
        cout << endl << "Deleted value is: " << temp->value << endl;
        free(temp);
    }
}
void delete_from_any_position(){
    int i=0,position;
    struct node *ptr,*temp;
    if(head==NULL){
        cout << endl << "List is empty" << endl;
        return ;
    }
    else{
        cout << "Enter the position to delete[index based]: ";
        cin >> position;
        if(position==0){
            ptr=head;
            head=head->next;
            cout << endl << "Deleted value is: " << ptr->value << endl;
            free(ptr);
        }
        else{
            temp=head;
            while(i<position){
                ptr=temp;
                temp=temp->next;
                if(temp==NULL){
                    cout << endl << "Position didn't exists" << endl;
                    return ;
                }
                i++;
            }
            ptr->next=temp->next;
            cout << endl << "Deleted value is: " << temp->value << endl;
            free(temp);
        }
    }
}
void search_a_value(){
    struct node *ptr;
    int value;
    if(head==NULL){
        cout << endl << "The list is empty" << endl;
        return;
    }
    else{
        cout << "Enter a value for search: ";
        cin >> value;
        ptr=head;
        while(ptr!=NULL){
            if(ptr->value==value){
                cout << endl << "There is " << value << " in the list." << endl;
                break;
            }
            ptr=ptr->next;
        }
        if(ptr==NULL)
            cout << endl << "There is no " << value << " in the list." << endl;
    }
}
void get_length(){
    struct node *ptr;
    int length=0;
    if(head==NULL){
        cout << endl << "List is empty" << endl;
        return;
    }
    else{
        ptr=head;
        while(ptr!=NULL){
            length++;
            ptr=ptr->next;
        }
        cout << endl << "Total length of current list is: " << length << endl;
    }
}