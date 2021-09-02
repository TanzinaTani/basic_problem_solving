#include<iostream>
#include<limits>
#include<algorithm>
#include<stdio.h>
using namespace std;

int adj[100][100]= {0},color[100],prevs[100],d[100],f[100],v,E,p,q,u,time,i,a[100];

void build_graph(){
     int start, end, i;

    for(i = 1; i <= E; i++){
        scanf("%d%d",&start,&end);
        adj[start][end] = 1;
        //AdjMat[end][start] = 1;
    }
}

void insertion_sort(){
    for(int j=2;j<=v;j++)
    {
        int key=a[j];
        int i=j-1;
        while(i>=1&&a[i]<key){
            a[i+1]=a[i];
            i=i-1;
        }
        a[i+1]=key;
    }
}
void transpose_matrix()
{
    for(int i=1;i<=v;i++)
    {
        for(int j=i+1;j<=v;j++)
        {
            swap(adj[i][j],adj[j][i]);
        }
    }
}

void DFS_Visit(int u)
{
    color[u]=1;
    d[u]=++time;
    for(int i=1;i<=v;i++)
    {
        if(adj[u][i]==1&&color[i]==0)
        {
            prevs[i]=u;
            DFS_Visit(i);
        }
    }
    color[u]=2;
    f[u]=++time;
    a[u]=f[u];
}

void DFS_Visit1(int u)
{
    color[u]=1;
    cout<<u<< " ";
    for(int i=1;i<=v;i++)
    {
        if(adj[u][i]==1&&color[i]==0)
        {
            prevs[i]=u;
            DFS_Visit1(i);
        }
    }
    color[u]=2;
}

void back_to_prevs_color()
{
    for(int i=1;i<=v;i++)
    {
        color[i]=0;
    }
}

void DFS()
{
    int i;
    for(int i=1; i<=v; i++)
    {
        color[i]=0;
        prevs[i]=-1;
        d[i]=0;
        f[i]=0;
    }
    time=0;
    cout<< "\nEnter the vertex you want to start with:";
    cin>>i;
    if(i<=v&&i>0&&color[i]==0)
    {
        DFS_Visit(i);
    }
    for(int i=1;i<=v;i++)
    {
        if(color[i]==0)
        {
            DFS_Visit(i);
        }
    }
    insertion_sort();
    transpose_matrix();
    back_to_prevs_color();
    cout<< "\nThe strongly connected components are:\n";
    for(int u=1;u<=v;u++)
    {
        int c=0;
        for(int i=1;i<=v;i++)
        {
            if(a[u]==f[i] && color[i]==0)
            {
                DFS_Visit1(i);
                c=1;
                break;
            }
        }
        if(c==1)
        {
            cout<<endl<<endl;
            c=0;
        }
    }

}

int main()
{
    cout<< "Input number of vertex and edge:";
    cin>>v>>E;
    build_graph();
    DFS();
}
