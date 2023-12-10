#include<stdio.h>
void divide(int *array,int lb,int ub);
void conquer(int *array,int lb,int mid,int ub);
int main(){
    int a[9]={6,4,5,9,4,8,7,2,3};
    divide(a,0,8);
    for(int i=0;i<9;i++){
        printf("%d\t",a[i]);
    }
    return 0;
}
void divide(int *array,int lb,int ub){
    if(lb<ub){
        int mid=(lb+ub)/2;
        divide(array,lb,mid);
        divide(array,mid+1,ub);
        conquer(array,lb,mid,ub);
    }
}
void conquer(int *array,int lb,int mid,int ub){
    int l=lb,r=mid+1,k=lb,i,j;
    int la_size=mid-lb+1,ra_size=ub-mid;
    int la[la_size],ra[ra_size],b[la_size+ra_size];
    for(i=0;i<la_size;i++){
        la[i]=array[lb+i];
    }
    for(i=0;i<ra_size;i++){
        ra[i]=array[mid+1+i];
    }
    i=0;
    j=0;
    while(i<la_size&&j<ra_size){
        if(la[i]<ra[j]){
            array[k]=la[i];
            i++;
        }
        else{
            array[k]=ra[j];
            j++;
        }
        k++;
    }
    for( ;i<la_size;i++,k++){
        array[k]=la[i];
    }
    for( ;j<ra_size;j++,k++){
        array[k]=ra[j];
    }
}