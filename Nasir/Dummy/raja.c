#include <stdio.h>



int mat1[50][50];

int color[8] = {20,20,20,20,20,20,20,20};

int prev[8];

int distance[8] = {500,500,500,500,500,500,500,500};



int queue[10];

int front = -1;

int rear = -1;



void Enqueue(int a){

    if((front == 0)&&(rear == 9))

        printf("The queue is full!");

    else if((front == -1)&&(rear == -1)){

        front++;

        rear++;

        queue[rear] = a;

}

    else{

        rear++;

        queue[rear] = a;



    }

}



int Dequeue(){

    int i = 1;

    int item;



    if((front == -1)&&(rear == -1))

        printf("The queue is empty!");

    else{

         item = queue[front];

        while(i<=rear){

            queue[i-1] = queue[i];

            i++;

        }

        rear--;



    }

    return item;

}

void print_path(int s, int v){

    if(v ==s){

        printf(" %d ", s);



    }

    else if(prev[v] == -1)

        printf("\nNo path exists!\n");

    else{

        print_path(s, prev[v]);

        printf(" %d ", v);

    }

}

int main(){



    freopen("countries.txt","r",stdin);

    int n,m,x,y,k;





    scanf("%d",&n);



   // int mat1[n][n];



    for(int i = 0; i<n; i++){

        for(int j = 0; j<n; j++){

            mat1[i][j] = 0;

        }

    }

    scanf("%d", &m);





    for(int i = 0; i<m; i++){

        scanf("%d", &x);

        scanf("%d", &y);

        mat1[x][y] = 1;

    }



    int source;

    printf("Enter the source node:\n");



    scanf("%d", &source);

    //printf("%d", source);

    distance[source] = 0;

    prev[source] = -1;



    Enqueue(source);

    for(int i = 0; i<=rear; i++)

        printf("%d ", queue[i]);

    int u;

    printf("\n");

    while((front != -1)&&(rear != -1)){

        u = Dequeue();

        printf("%d ", u);

        for(int j = 0; j<8; j++){

            if((mat1[u][j]==1)&&(color[j]==20)){

                color[j] = 30;

                distance[j] = distance[u]+1;

                prev[j] = u;

                Enqueue(j);



            }

        }

        color[u] = 40;

    }

    //printf("\nWhat is your destination?");

    //scanf("%d", &k);

    //printf(" %d\n", k);

    //printf("The path is as follows:\n");

    //print_path(source, k);



    return 0;

}
