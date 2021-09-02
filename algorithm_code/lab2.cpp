#include<bits/stdc++.h>
using namespace std;

const int MaxVertex=100;
int AdjMat[MaxVertex][MaxVertex];
int d[MaxVertex],prevs[MaxVertex],color[MaxVertex];
void BFS(int src,int V){
   queue<int>Q;
   for(int i=0;i<V;i++){
      color[i]=0;
      prevs[i]=-1;
      d[i]=10000;
   }
   color[src]=1;
   d[src]=0;
   prevs[src]=-1;
   Q.push(src);
   while(!Q.empty()){
    src=Q.front();
    Q.pop();
    for(int i=0;i<V;i++){
        if(AdjMat[src][i]==1 && color[i]==0){
        color[i]=1;
        d[i]=d[src]+1;
        prevs[i]=src;

        Q.push(i);
    }
    }
    color[src]=2;
   }
}
int main(){
 int start,V,E,end,i;
  cout<<"enter the number of Vertex and Edge: ";
 cin>>V>>E;
 cout<<"\nEnter the connected edge: \n";
 for(i=0;i<E;i++){
    cout<<"\nEnter the "<<i+1<<" edge: ";
    scanf("%d%d",&start,&end);
    AdjMat[start][end]=1;
    AdjMat[end][start]=1;
 }
 for(i=0;i<V;i++){
    d[i]=10000;
 }
 BFS(0,V);
 cout<<"\nDistance of the vertex from each other: ";
 for(i=0;i<V;i++){
    printf("\nVertex %d distance: %d\n",i,d[i]);
    printf("\nColor %d : %d\n",i,color[i]);
    printf("\nprevs %d : %d\n",i,prevs[i]);

 }
}


