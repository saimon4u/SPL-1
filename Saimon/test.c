#include<stdio.h>
#include "priority_queue.h"
int main(){
    p_queue *p = createPriorityQueue();
    p_enqueue(p,1);
    p_enqueue(p,45);
    p_enqueue(p,32);
    p_enqueue(p,43);
    for(int i=0; i<4; i++){
        printf("%d ",p_dequeue(p));
    }
    return 0;
}