#include <iostream>
#include <queue>

using namespace std;

int AdjMat[100][100];
int colorArr[100],prevs[100],dis[100];
int V;

 int isBipartite(int V ,int src){
     queue <int> q;
    for (int i = 1; i <= V; ++i){
        colorArr[i] = 0;
        prevs[i]=0;
        dis[i]=10000;
    }
       colorArr[src] = 1;
       prevs[src]=1;
       dis[src]=0;
    q.push(src);
    while (!q.empty()){
        int u = q.front();

        for (int v = 1; v <= V; ++v){

            if (AdjMat[u][v]==1 ){
                 if (prevs[v]==prevs[u])
              return 0;

           else if(colorArr[v] == 0){
                 dis[v]=dis[u]+1;
                prevs[v] = 3- prevs[u];
                q.push(v);
        }
        }
        }
        q.pop();
      colorArr[u]==2;
      return 1;

}
 }
int main()
{
     int start,E,end,i;
  cout<<"enter the number of Vertex and Edge: ";
   cin>>V>>E;
  cout<<"\nEnter the connected edge: \n";
 for(i=1;i<=E;i++){
    cout<<"\nEnter the "<<i<<" edge: ";
    cin>>start>>end;
    AdjMat[start][end]=1;
    AdjMat[end][start]=1;
 }
    isBipartite(V, 1) ? cout << "Yes" : cout << "No";
    return 0;
}

