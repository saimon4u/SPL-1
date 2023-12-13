#include<stdio.h>
#define WHITE 0
#define GREY 1
#define BLACK 2
#define INFINITY 1000000

int mtx[200][200],d[200],queue[200],rare=-1,front=-1;
int colour[200],prev[200];
void BFS(int mtx[200][200],int s,int v);
int dequeue();
void print(int v);
void enqueue(int x);
int queueSize();

int main()
{
    int i,j,v,x,y,s,ed;
    printf("Enter the num of vertices:\n");
    scanf("%d",&v);
    for(i=0;i<=v;i++)
    {
        for(j=0;j<=v;j++)
        {
            mtx[i][j]=0;
        }
    }
    printf("Enter vertex name\n");
    for(j=1;j<=v;j++)
        {
            int val;
            scanf("%d",&val);
            mtx[0][j]=val;
             mtx[j][0]=val;
        }

    printf("Enter the num of edges:\n");
    scanf("%d",&ed);
    while(ed--)
    {
        printf("enter vertices share edge:\n");
        scanf("%d %d",&x,&y);
        mtx[x][y]=1;
        mtx[y][x]=1;
    }
    for(i=0;i<=v;i++)
    {
        for(j=0;j<=v;j++)
        {
            printf("%d ",mtx[i][j]);
        }
        printf("\n");
    }
    printf("Enter source:\n");
    scanf("%d",&s);
    BFS(mtx,s,v);
    print(v);

      return 0;
}

void BFS(int mtx[200][200],int s,int v)
{
    int i,j,u;
        for(i=1;i<=v;i++)
        {
            colour[u]=WHITE;
            prev[u]=-1;
            d[u]=INFINITY;
        }

    colour[s]=GREY;
    prev[s]=-1;
    d[s]=0;

    enqueue(s);
    while(queueSize()!=0)
    {
       u=dequeue();

       for(i=1;i<=v;i++)
       {
           if(mtx[u][i]==1&&colour[i]==WHITE)
           {

            colour[i]=GREY;
            prev[i]=u;
            d[i]=d[u]+1;
            enqueue(i);
           }
       }
      colour[u]=BLACK;
    }

}

void enqueue(int x)
{
    if(front==-1)
    {
        front++;
        rare++;
        queue[front]=x;

    }
    else {
            rare++;
            queue[rare]=x;

    }
}
int queueSize()
{
if(front>rare) return 0;
else return 1;
}
int dequeue()
{
    int i=front;
    front++;
    return queue[i];
}
void print(int v)
{
    int i;
    for(i=1;i<=v;i++)
    {
        printf("%d ",mtx[0][i]);
    }
    printf("\n");
    for(i=1;i<=v;i++)
    {
        printf("%d ",colour[i]);
    }
    printf("\n");
    for(i=1;i<=v;i++)
    {
        printf("%d ",d[i]);
    }
    printf("\n");
    for(i=1;i<=v;i++)
    {
        printf("%d ",prev[i]);
    }
    printf("\n");
}
