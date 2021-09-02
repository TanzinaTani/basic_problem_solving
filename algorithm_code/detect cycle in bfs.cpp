#include<iostream>
#include<queue>
#include<stdlib.h>
using namespace std;

int V,E,AdjMat[100][100],color[100],dis[100],prevs[100];
void BFS(int s,int V){
    queue<int>Q;
   for(int i=1;i<=V;i++){
       color[i]=0;
       dis[i]=10000;
       prevs[i]=-1;
   }
   color[s]=1;
   dis[s]=0;
   prevs[s]=-1;
   Q.empty();
   Q.push(s);
   while(!Q.empty()){
      s=Q.front();
      Q.pop();
      for(int i=1;i<=V;i++){
         if(AdjMat[s][i]==1 && color[i]==0){
            color[i]=1;
            dis[i]=dis[s]+1;
            prevs[i]=s;
            Q.push(i);
         }
      }
      color[s]=2;

   }
}
void print_path(int s,int V){
   if(s==V){
    cout<<s;
   }
   else if(prevs[V]==-1){
    cout<<" there is no path ";
    return;

   }
  else{
    print_path(s,prevs[V]);
    cout<<" "<<V;
  }

}
int  bfs_cycle(int n)
{
    int m=0,i,j;
    for(i=1; i<=n; i++)
    {
        for( j=1; j<=n; j++)
        {
            if(j!=i)
            {
                if(AdjMat[i][j]==1)
                {
                    if(color[j]==2 && prevs[j]!=i)
                    {
                        m=i;
                        for(int k=1;k<=n;k++)
                        {
                            if(prevs[j]==prevs[m]&&j!=m)
                            {

                                return 1;
                            }
                            else if(prevs[m]==-1)
                            {
                                break;
                            }
                            else
                            {
                                m=prevs[m];
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}

int main(){
   int i,j,start,end,s;
   cout<<"enter the number of vertex: ";
   cin>>V;
   cout<<"\nenter the number of edge: ";
   cin>>E;
   cout<<"\nEnter the connected edge: ";
   for(i=1;i<=E;i++){
      cout<<"\nEnter the "<<i<<" edge: ";
      cin>>start>>end;
      AdjMat[start][end]=1;
   }
   for(i=1;i<=V;i++){
        for(j=1;j<=V;j++){
     cout<< AdjMat[i][j]<<"  ";
   }
   cout<<endl;
   }
   for(i=1;i<=V;i++){
    dis[i]=10000;
 }
   cout<<"\nEnter the source: ";
   cin>>s;
   BFS(s,V);
        if(bfs_cycle(V))
        {
            cout<<"\nThere is a cycle\n";
        }
        else
        {
            cout<<"\nThere is no cycle\n";
        }
   for(i=1;i<=V;i++){
   cout<<"\nfor Vertex "<<i<<" : ";
   cout<<"\t color "<<color[i];
   cout<<"\tdistance "<<dis[i];
   cout<<"\tprevsious "<<prevs[i];
}
    cout<<"\nshortest path is: ";
    for(i=1;i<=V;i++){
    cout<<"\nfor Vertex "<<i<<":";
    print_path(s,i);
}
   cout<<"\nthe shortest  path  between A to B is : ";
   print_path(1,4);
}
