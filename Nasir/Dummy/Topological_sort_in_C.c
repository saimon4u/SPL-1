#include<stdio.h>
#include<LIMITS.h>
int d[50000],f[500000],mtx[200][200],prev[50000],v,time,vertex[500];
char colour[50000];
void DFS(int s);
void DFS_Visit(int u);
void print();
void topologicalSort();

int main()
{
    int x,y,u,n,s,i,j,l;
    //freopen("dfs.txt","r",stdin);
    printf("Enter the number of vertices:\n");
    scanf("%d",&v);

    for(i=0;i<=v;i++)
    {
        for(j=0;j<=v;j++)
        {
            mtx[i][j]=0;
        }
    }
    for(i=1;i<=v;i++)
    {
        scanf("%d",&n);
        vertex[i]=n;
        mtx[i][0]=n;
        mtx[0][i]=n;

    }
    printf("Enter the number of edges:\n");
    scanf("%d",&l);
    while(l--)
    {
        printf("Enter the path:\n");
        scanf("%d",&x);
        scanf("%d",&y);
        mtx[x][y]=1;
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
    DFS(s);
     for(i=1;i<=v;i++)
       {
         if(colour[i]=='w') DFS_Visit(i);
       }
       topologicalSort();
    print_topological_sort(v);
  return 0;
}

void DFS(int s)
{
  int i,j;
  int u=s;
   for(i=1;i<=v;i++)
    {
        colour[i]='w';
        prev[i]=1000000;
        d[i]=-1;
    }
    time=0;
    DFS_Visit(u);
}

void DFS_Visit(int u)
{
    int i;
    colour[u]='g';
    time=time+1;
    d[u]=time;
    for(i=1;i<=v;i++)
       {
              if(mtx[u][i]==1&&colour[i]=='w')
               {
                   prev[i]=u;
                   DFS_Visit(i);
               }
           }
       colour[u]='b';
       time=time+1;
       f[u]=time;
}

void print_topological_sort(int v)
{
    printf("Topological Sort:\n");
   for(int i=1;i<=v;i++)
   {
       printf("%d ",vertex[i]);
   }
   printf("\n");
}
void topologicalSort()
{
   int i,j;
   int temp;

   for(i=1;i<=v;i++)
   {
       for(j=i+1;j<=v;j++)
       {
           if(f[vertex[i]]<f[vertex[j]])
           {
               temp=vertex[j];
               vertex[j]=vertex[i];
               vertex[i]=temp;
           }
       }
   }

}
