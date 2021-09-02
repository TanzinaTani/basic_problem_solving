#include<iostream>
#include<stdio.h>
#include<queue>

using namespace std;
const int MaxVertex=100;
int AdjMat[MaxVertex][MaxVertex];
int dis[MaxVertex],prevs[MaxVertex],color[MaxVertex];

void BFS(int sourse,int V){
  queue<int>q;
  for(int i=1; i<=V; i++){
    color[i]=0;
    prevs[i]=-1;
    dis[i]=10000;
  }
  color[sourse]=1;
  dis[sourse]=0;
  prevs[sourse]=-1;
  q.empty();
  q.push(sourse);
  while(!q.empty()){
        sourse=q.front();
        q.pop();
    for(int i=1;i<=V;i++){
        if(AdjMat[sourse][i]==1 && color[i]==0){
            color[i]=1;
            dis[i]=dis[sourse]+1;
            prevs[i]=sourse;

            q.push(i);

        }
    }
    color[sourse]=2;
  }
  }
 void print_path(int s,int V)
{
    if(V==s)
    {
        printf("%d  ",s);
    }
    else if(prevs[V]==-1)
    {
        printf("\nNo path\n");
        return;
    }
    else
    {
        print_path(s,prevs[V]);
        printf("%d ",V);
    }
}
void BFS_display(int V)
{
    printf("\nThe reachable vertices are:\n");
    for(int i=1; i<=V; i++)
    {
        if(color[i]==2&&i==1)
        {
            printf("%d",i);
        }
        else if(color[i]==2)
        {
            printf(" -> %d  ",i);
        }
        else
        {
            printf("\nBFS not possible. Not all nodes are reachable\n");
            break;
        }
    }
    printf("\n");
}


int main(){
 int V,E,i,start,end,sourse;
 cout<<"enter the number of  vertex & edge: ";
 cin>>V>>E;
 cout<<"\nEnter the connected edge: ";
 for( i=1; i<=E; i++){
 cin>>start>>end;
 AdjMat[start][end]=1;

 }

 for(i=1;i<=V;i++){
    dis[i]=10000;
 }
 BFS(1,V);
  BFS_display(V);
 print_path(1,6);

 for(i=1;i<=V;i++){
 cout<<"\nthe distance of "<<V<<" is: "<<dis[i];
 cout<<"\nColor "<<i<<" : "<<color[i];
   cout<<"\nprevs "<<i<<" : "<<prevs[i];
}
}
