#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

const int MaxVertex=100;
int AdjMat[MaxVertex][MaxVertex]={0};
int d[MaxVertex],prevs[MaxVertex],color[MaxVertex],f[MaxVertex];
int time,a[100];
void insertion_sort(int V){
    int k,i,j;
   for(int i=2;i<=V;i++){
        k=a[i];
        j=i-1;
        while(j>0 && a[j]<k){
            a[j+1]=a[j];
            j=j-1;
        }
        a[i+1]=k;
   }


}
void transpose_matrix(int  V){

 for(int i=1;i<=V;i++){
    for(int j=i+1;j<=V;j++){
        swap(AdjMat[i][j],AdjMat[j][i]);
    }
 }

}
void DFS_visit(int V,int u){

color[u]=1;
d[u]=++time;
for(int i=1;i<=V;i++){
    if(AdjMat[u][i]==1 && color[i]==0){
        prevs[i]=u;
        DFS_visit(V,i);
    }
}
color[u]=2;
f[u]=++time;
a[u]=f[u];

}
void DFS_Visit1(int V,int u){
    color[u]=1;
    cout<<u<< "  ";

for(int i=1;i<=V;i++){
    if(AdjMat[u][i]==1 && color[i]==0){
        prevs[i]=u;
        DFS_Visit1(V,i);
    }
}
color[u]=2;

}

void DFS(int V){
   int i;
for( i=1;i<=V;i++){
    color[i]=0;
    prevs[i]=-1;
    f[i]=10000;
    d[i]=10000;

}
time=0;
  cout<<" enter the source: ";
  cin>>i;
  if(i<=V && i>0 && color[i]==0){
      DFS_visit(V,i);
  }
 for(int i=1;i<=V;i++){
    if(color[i]==0){
        DFS_visit(V,i);
    }
 }
 insertion_sort(V);
 transpose_matrix( V);
 for(int i=1;i<=V;i++){
    color[i]=0;
 }
  cout<<"\n strongly connected components are: "<<endl;
  for(int i=1;i<=V;i++){
    int c=0;
    for(int j=1;j<=V;j++){
        if(a[i]==f[j] && color[j]==0){
            DFS_Visit1(V,j);
            c=1;
            break;
        }
    }
    if(c==1){
        cout<<endl<<endl;
        c=0;
    }
  }
}

int main(){
 int start,V,E,end,i;
  cout<<"enter the number of Vertex and Edge: ";
 cin>>V>>E;
 cout<<"\nEnter the connected edge: \n";
 for(i=0;i<E;i++){
    cout<<"\nEnter the "<<i+1<<" edge: ";
      cin>>start>>end;
    AdjMat[start][end]=1;
 }

 DFS(V);

}


