#include<iostream>
#include<stdio.h>
using namespace std;

const int MaxVertex=100;
int AdjMat[MaxVertex][MaxVertex];
int d[MaxVertex],prevs[MaxVertex],color[MaxVertex],f[MaxVertex];
int time;

void DFS_visit(int V,int u){

color[u]=1;
time=time+1;
cout<<"dis: "<<time<<endl;
d[u]=time;
for(int i=1;i<=V;i++){
    if(AdjMat[u][i]==1 && color[i]==0){
        prevs[i]=u;
        DFS_visit(V,i);
    }
    else{
        cout<<"\ncycle exist\n";
    }
}
color[u]=2;
time=time+1;
cout<<"Finish :"<<time<<endl;
f[u]=time;

}
void DFS(int src,int V){

for(int i=1;i<=V;i++){
    color[i]=0;
    prevs[i]=-1;
    f[i]=-1;
    d[i]=-1;

}
time=0;
 for(int i=1;i<=V;i++){
    if(color[i]==0){
        DFS_visit(V,i);
    }
 }

}
void DFS_Display(int V)
{
	cout<<"Vertex    :";
	for(int i=1;i<=V;i++)
	{
		cout<<i<<"  ";
	}
	cout<<endl;
	cout<<"Color     :";
	for(int i=1;i<=V;i++)
	{
		cout<<color[i]<<"  ";
	}
	cout<<endl;
	cout<<"Discover  :";
	for(int i=1;i<=V;i++)
	{
		cout<<d[i]<<"  ";
	}
	cout<<endl;
	cout<<"Finish    :";
	for(int i=1;i<=V;i++)
	{
		cout<<f[i]<<" ";
	}
	cout<<endl;
	cout<<"prevsious  :";
	for(int i=1;i<=V;i++)
	{
		cout<<prevs[i]<<" ";
	}
	cout<<endl;
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
 for(i=1;i<=V;i++){
    d[i]=10000;
 }
 DFS(1,V);
 cout<<"\nDistance of the vertex from each other: ";
 DFS_Display(V);
}

