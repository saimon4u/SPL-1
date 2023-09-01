#include<stdio.h>
#include<string.h>
#include<malloc.h>
#define SIZE 100
typedef struct Map{
    int size;
    char **keys;
    int *values;
}map;
map *createMap(){
    map *m = (map *)malloc(sizeof(map));
    m->size = 0;
    m->keys =(char **)malloc(sizeof(char *)*SIZE);
    for(int i=0; i<SIZE; ++i)m->keys[i] = (char *)malloc(sizeof(char)*100);
    m->values = (int *)malloc(sizeof(int)*SIZE);
    return m;
}
int getIndex(map *m,char *key){
    for(int i=0; i<m->size; ++i){
        if(!strcmp(m->keys[i],key))return i;
    }
    return -1;
}
void insert(map *m,char *key,int value){
    printf("Inserted! %s at %d\n",key,m->size);
    if(m->size == SIZE -1) return;
    strcpy(m->keys[m->size],key);
    m->values[m->size] = value;
    m->size++;
}
int getValue(map *m,char *key){
    int index = getIndex(m,key);
    if(index==-1)return -1;
    return m->values[index];
}
char *getKey(map *m,int value){
    int index = -1;
    for(int i=0; i<m->size; ++i){
        if(m->values[i]==value){
            index = i;
            break;
        }
    }
    if(index==-1)return "";
    return m->keys[index];
}
void printMap(map *m){
    for(int i=0; i<m->size; ++i){
        printf("%s-->%d\n",m->keys[i],m->values[i]);
    }
}