//
// Created by samdani on 6/5/23.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define size 15

void create_list(char name[],int roll,float cgpa);
void input();
void sort(float *cgpa);
void msort(float *cgpa,int start,int end);
void merge(float *cgpa,int start,int mid,int end);
void selectionSort(float *cgpa);
void insertionSort(float *cgpa);
void quicksort(float *cgpa,int start,int end);
int partition(float *cgpa,int start,int end);
void printList();
void printStructArray();
void addStudent();
void removeStudent();
void search();

struct student {
    char name[20];
    int roll;
    float cgpa;
    struct student *next;
    struct student *prev;
}bsse14[size];

int total;

struct student *head=NULL;
struct student *temp=NULL;
struct student *tail=NULL;

int main(){
    int choice;
    printf("Enter number of total students:");
    scanf("%d",&total);
    input();
    float cgpa[size];
    for(int i=0;i<total;i++){
        cgpa[i]=bsse14[i].cgpa;
    }
    //sort(cgpa);
    msort(cgpa,0,total-1);
    //selectionSort(cgpa);
    //insertionSort(cgpa);
    //quicksort(cgpa,0,total-1);
    
    for(int i=0;i<total;i++){
        for(int j=0;j<total;j++){
            if(cgpa[i]==bsse14[j].cgpa){
                create_list(bsse14[j].name,bsse14[j].roll,bsse14[j].cgpa);
                break;
            }
        }
    }

    while(1){
        printf("1.Print list\n2.Print Struct Array\n3.Add Student\n4.Remove Student\n5.Search\n6.Quit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            printList();
            break;
        case 2:
            printStructArray();
            break;
        case 3:
            addStudent();
            total++;
            break;
        case 4:
            removeStudent();
            total--;
            break;
        case 5:
            search();
            break;
        
        case 6:
            return 0;

        }
    }

}

void input(){
    FILE *fp;
    fp= fopen("input.txt","r");

    for(int i=0;i<total;i++){
        fscanf(fp,"%s",bsse14[i].name);
        fscanf(fp,"%d",&bsse14[i].roll);
        fscanf(fp,"%f",&bsse14[i].cgpa);
    }
    fclose(fp);
}
void sort(float *cgpa){
    //bubble sort
    for(int i=0;i<total;i++){
        for(int j=i+1;j<total;j++){
            if(cgpa[i]<cgpa[j]){
                float temp=cgpa[i];
                cgpa[i]=cgpa[j];
                cgpa[j]=temp;
            }
        }
    }
}
void msort(float *cgpa,int start,int end){
    if(start==end) return;
    int mid=start+(end-start)/2;
    msort(cgpa,start,mid);
    msort(cgpa,mid+1,end);
    merge(cgpa,start,mid,end);;
}
void merge(float *cgpa,int start,int mid,int end){
    int size2=end-start+1;
    float temp[size2];
    int idx1=start,idx2=mid+1;
    int k=0;

    while(idx1<=mid && idx2<=end){
        if(cgpa[idx1] >= cgpa[idx2]){
            temp[k++]=cgpa[idx1++];
        }else{
            temp[k++]=cgpa[idx2++];
        }
    }

    while(idx1<=mid){
        temp[k++]=cgpa[idx1++];
    }
    while(idx2<=end){
        temp[k++]=cgpa[idx2++];
    }

    for(int i=0,j=start;i<size2;i++,j++){
        cgpa[j]=temp[i];
    }
}
void selectionSort(float *cgpa){
    int max;
    float temp;
    for(int i=0;i<total;i++){
        max=i;
        for(int j=i+1;j<total;j++){
            if(cgpa[j] > cgpa[max]){
                max=j;
            }
        }
        temp=cgpa[max];
        cgpa[max]=cgpa[i];
        cgpa[i]=temp;
    }
}
void insertionSort(float *cgpa){
    int j;
    float temp;
    for(int i=1;i<total;i++){
        j=i;
        while(j>0 && cgpa[j]>cgpa[j-1]){
            temp=cgpa[j];
            cgpa[j]=cgpa[j-1];
            cgpa[j-1]=temp;
            j--;
        }
    }
}
void quicksort(float *cgpa,int start,int end){
    if(start<end){
        int pivot=partition(cgpa,start,end);
        quicksort(cgpa,start,pivot-1);
        quicksort(cgpa,pivot+1,end);
    }
}
int partition(float *cgpa,int start,int end){
    float pivot=cgpa[end];
    int i=start-1;
    float temp;

    for(int j=start;j<end;j++){
        if(cgpa[j]>=pivot){
            i++;
            temp=cgpa[j];
            cgpa[j]=cgpa[i];
            cgpa[i]=temp;
        }
    }
    i++;
    temp=cgpa[i];
    cgpa[i]=pivot;
    cgpa[end]=temp;

    return i;

}
void create_list(char name[],int roll,float cgpa){
    struct student *link= (struct student*) malloc(sizeof(struct student));
    strcpy(link->name,name);
    link->roll=roll;
    link->cgpa=cgpa;

    link->prev=0;
    link->next=0;

    if(head==NULL){
        head=link;
        temp=link;
    }else{
        link->prev=temp;
        temp->next=link;
        temp=link;
        tail=link;
    }

}
void printList() {
    struct student *ptr = head;
    //start from the beginning
    printf("Name\t\tRoll\t\tCgpa\n\n");
    while(ptr != NULL) {
        printf("%s \t\t%d \t\t%.2f\n",ptr->name,ptr->roll,ptr->cgpa);
        ptr = ptr->next;
    }
	
}
void printStructArray(){
    for(int i=0;i<total;i++){
        printf("%s\t%d\t%.2f\n",bsse14[i].name,bsse14[i].roll,bsse14[i].cgpa);
    }
}
void addStudent(){
    struct student *link = (struct student*) malloc(sizeof(struct student));
    struct student *prevstudent;
    temp=head;
    printf("\nEnter Name:");
    scanf("%s",link->name);
    strcpy(bsse14[total].name,link->name);
    printf("Enter roll:");
    scanf("%d",&link->roll);
    bsse14[total].roll=link->roll;
    printf("Enter cgpa:");
    scanf("%f",&link->cgpa);
    bsse14[total].cgpa=link->cgpa;

    if(link->cgpa < head->cgpa){
        while(temp!=NULL && temp->cgpa >= link->cgpa){
            prevstudent=temp;
            temp=temp->next;
        }
        if(temp==NULL){
            prevstudent->next=link;
            link->prev=prevstudent;
            link->next=0;
            return;
        }
        link->prev=prevstudent;
        link->next=prevstudent->next;
        prevstudent->next->prev=link;
        prevstudent->next=link;
        
    }else{
        head->prev=link;
        link->next=head;
        link->prev=0;
        head=link;
    }
}
void removeStudent(){
    temp=head;
    int delRoll,index;

    printf("Enter roll:");
    scanf("%d",&delRoll);

    for(int i=0;i<total;i++){
        if(bsse14[i].roll==delRoll){
            index=i;
            break;
        }
    }

    for(int i=index+1;i<total;i++){
        strcpy(bsse14[i-1].name,bsse14[i].name);
        bsse14[i-1].roll=bsse14[i].roll;
        bsse14[i-1].cgpa=bsse14[i].cgpa;

    }

    while(temp!=NULL && temp->roll !=delRoll){
        temp=temp->next;
    }
    if(temp->next==NULL){
        temp->prev->next=0;
        return;
    }
    if(temp==head){
        head=head->next;
        head->next->prev=0;
        free(temp);
        return;
    }
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;


}
void search(){
    temp=head;
    int searchRoll;

    printf("Enter roll to search:");
    scanf("%d",&searchRoll);

    while(temp!=NULL && temp->roll!=searchRoll){
        temp=temp->next;
    }
    if(temp==NULL){
        printf("Student roll %d is not registered!\n",searchRoll);
        return;
    }
    printf("Name:%s\nRoll:%d\nCgpa:%.2f\n",temp->name,temp->roll,temp->cgpa);

}