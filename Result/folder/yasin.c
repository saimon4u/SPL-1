#include<stdio.h>
void conquer(int list[],int first,int mid,int last){
    int n1=mid-first+1,n2=last-mid,lpos=first,rpos=mid+1,i,j,k;
    int left[n1],right[n2];
    for(i=0;i<n1;i++){
        left[i]=list[lpos];
        lpos++;
    }
    for(j=0;j<n2;j++){
        right[j]=list[rpos];
        rpos++;
    }
    i=0;
    j=0;
    k=first;
    for( ;i<n1&&j<n2;k++){
        if(left[i]<=right[j]){
            list[k]=left[i];
            i++;
        }
        else{
            list[k]=right[j];
            j++;
        }
    }
    for( ;i<n1;i++){
        list[k]=left[i];
        k++;
    }
    for( ;j<n2;j++){
        list[k]=right[j];
        k++;
    }
}
void divide(int list[],int first,int last){
    if(first<last){
        int mid;
        mid=first+(last-first)/2;
        divide(list,first,mid);
        divide(list,mid+1,last);
        conquer(list,first,mid,last);
    }
}
int main(){
    int i,n;
    scanf("%d",&n);
    int list[n];
    for(i=0;i<n;i++){
        scanf("%d",&list[i]);
    }
    divide(list,0,n-1);
    for(i=0;i<n;i++){
        printf("%d ",list[i]);
    }
    return 0;
}