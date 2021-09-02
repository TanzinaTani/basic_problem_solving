#include<iostream>
using namespace std;
int a[100][100],c[100][100],n,w,i,j;

int rockClimbing(){
    for(j=0;j<=w+1;j++){
        c[0][j]=0;
    }
    for(i=0;i<=n;i++){
        c[i][0]=1000;
        c[i][w+1]=1000;
    }
     for(i=1;i<=w;i++){
            c[1][i]=a[1][i];
     }

     for(i=2;i<=n;i++){
      for(j=1;j<=w;j++){
      if(c[i-1][j-1]<=c[i-1][j]&& c[i-1][j-1]<=c[i-1][j+1]){
        c[i][j]=c[i-1][j-1]+a[i][j];
      }
      else if(c[i-1][j]<=c[i-1][j-1]&& c[i-1][j]<=c[i-1][j+1]){
        c[i][j]=c[i-1][j]+a[i][j];
      }
      else if(c[i-1][j+1]<=c[i-1][j]&& c[i-1][j+1]<=c[i-1][j-1]){
        c[i][j]=c[i-1][j+1]+a[i][j];
      }
      }
   }

    int cost=1000;
    for(j=1;j<=w;j++){
        if(c[n][j]<cost){
            cost=c[n][j];
        }
    }
     return cost;
}
void printBest(int l,int k){
    if(l==0 || k==0 || k==w+1){
        return ;
    }

    if(c[l][k]==c[l-1][k-1]+a[l][k]){
        printBest(l-1,k-1);
    }
      else if( c[l][k]==c[l-1][k]+a[l][k]){
        printBest(l-1,k);
      }
      else if( c[l][k]==c[l-1][k+1]+a[l][k]){
            printBest(l-1,k+1);

      }
      cout<<"\nthe best path : "<<a[l][k]<<" index number : "<<l<<"-"<<k<<" back tracking values: "<<c[l][k]<<endl;


}

int main(){
  cout<<"enter the number of stair: ";
  cin>>n;
  cout<<"\nenter the number of way: ";
  cin>>w;
  cout<<"\nenter the value of danger: ";

  for(i=1;i<=n;i++){
    for(j=1;j<=w;j++){
         cin>>a[i][j];
    }
    }
    cout<<endl<<"the danger values are: \n";
     for(i=1;i<=n;i++){
    for(j=1;j<=w;j++){
         cout<<a[i][j]<<" ";
    }
    cout<<endl;
    }
    int s=rockClimbing();
    cout<<"minimum cost: "<<s;
     cout<<endl<<endl;
    for(i=0;i<=n;i++){
    for(j=0;j<=w+1;j++){

         cout<<c[i][j]<<"\t";
    }
    cout<<endl;
    }
    for(j=1;j<=w;j++){
        if(c[n][j]==s){
            printBest(n,j);
        }
    }

}


