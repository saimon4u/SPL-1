#include<stdio.h>
#include<stdlib.h>
struct Student{
    int roll;
    double marks;
    struct Student *next;
}bsse14[100];
struct Student *head=NULL;
int numofstudent=0;
void link(int current){
    int i=0,position=0;
    struct Student *ptr;
    while(i<=numofstudent){
        if(bsse14[i].marks>=bsse14[current].marks)
            position++;
        i++;
    }
    if(position!=0)
        position--;
    bsse14[current].next=NULL;
    if(position==0){
        bsse14[current].next= head;
        head=&bsse14[current];
    }
    else{
        ptr=head;
        i=0;
        while(i<position-1){
            printf("%d  ",i);
            ptr=ptr->next;
            printf("\n");
            i++;
        }
        bsse14[current].next=ptr->next;
        ptr->next=&bsse14[current];
    }
}
void AddStudent(){
    printf("Enter Student's roll: ");
    scanf("%d",&bsse14[numofstudent].roll);
    printf("Enter Student's marks: ");
    scanf("%lf",&bsse14[numofstudent].marks);
    numofstudent++;
    link(numofstudent-1);
}
void display(){
    struct Student *ptr;
    ptr=head;
    printf("Rank of your student's: \n");
    while(ptr!=NULL){
        printf("Marks: %.2lf\tRoll: %d\n",ptr->marks,ptr->roll);
        ptr=ptr->next;
    }
}
void delete_student(){
    int roll;
    printf("Enter roll: ");
    scanf("%d",&roll);
    struct Student *ptr,*temp;
    ptr=head;
    while(ptr->roll!=roll){
        temp=ptr;
        ptr=ptr->next;
    }
    temp->next=ptr->next;
}
void search_student(){
    int roll;
    printf("Enter Roll: ");
    scanf("%d",&roll);
    struct Student *ptr;
    ptr=head;
    int position=0;
    while(ptr->roll!=roll){
        position++;
        ptr=ptr->next;
    }
    printf("Roll-%d is in the %dth position.\n",roll,position+1);
}
int main(){
    while(1){
        int choice;
        printf("\n         MENU\n");
        printf("1. Add a student\n");
        printf("2. Delete a student\n");
        printf("3. Get your rank\n");
        printf("4. Display full result\n");
        printf("5. Print Structure\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                AddStudent();
                break;
            case 2:
                delete_student();
                break;
            case 3:
                search_student();
                break;
            case 4:
                display();
                break;
            case 5:
                for(int i=0; i<numofstudent; i++)
                    printf("Roll-%d\n",bsse14[i].roll);
                break;
            case 6:
                exit(0);
        }
    }
    return 0;
}