#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
void radixsort(char word[][100],int size,int index);
int main(){
   srand((int)time(0));
    int n=5,i,j,len,max=0,input;
    char word[5][100];
    for(i=0; i<n; ){
        len=rand()%50;
        if(len>5){
            for(j=0; j<len; j++){
                input=rand()%26;
                word[i][j]='a'+input;
            }
            word[i][j]='\0';
            puts(word[i]);
            printf("\n");
            i++;
        }
    }
    for(i=0;i<n; i++){
        len=strlen(word[i]);
        if(len>max)
            max=len;
    }
    printf("%d\n",max);
    for(i=max-1; i>=0; i--){
        radixsort(word,n,i);
    }
    for(i=0; i<n; i++){
        puts(word[i]);
        printf("\n");
    }
    return 0;
}
void radixsort(char word[][100],int size,int index){
    printf("for index %d\n",index);
    printf("radix start\n");
    char output[size+1][100];
    int count[256]={0},i;
    for(i=0; i<size; i++){
        count[word[i][index]]++;
    }
    for(i=1; i<256; i++){
        count[i]+=count[i-1];
    }
    printf("count complete\n");
    for(i=size-1; i>=0; i--){
        printf("%d\t",i);
        strcpy(output[count[word[i][index]]-1],word[i]);
        count[word[i][index]]--;
    }
    printf("\n");
    printf("sort complete\n");
    for(i=0; i<size; i++){
        strcpy(word[i],output[i]);
    }
}