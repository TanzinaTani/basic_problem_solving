#include<iostream>
using namespace std;

void knapsack(int p[],int w[],int bag,int n){
int i,j,V[100][100];
for(i=0;i<=bag;i++){
        V[0][i]=0;
   }
     for(j=0;j<=n;j++){
        V[j][0]=0;

     }
     for(i=1;i<=n;i++){
        for(j=1;j<=bag;j++){
           if(w[i]<=j){
            if(V[i-1][j]<(V[i-1][j-w[i]]+p[i])){
                 V[i][j]=(V[i-1][j-w[i]])+p[i];


            }
            else{

                V[i][j]=V[i-1][j];
            }
        }
        else{
            V[i][j]=V[i-1][j];
        }
     }
     }

    for(i=0;i<=n;i++){
        for(j=0;j<=bag;j++){
            cout<<"\t"<<V[i][j];
        }
        cout<<endl;
    }
    cout<<"\nMaximum knapsack : "<<V[n][bag];
    cout<<endl<<"the item number which fill up the bag:  ";
    cout<<endl<<"  item:"<<"  weight" <<"  profit" <<endl;
    for(i=n;i>0;i--){
        if(V[i][bag]!=V[i-1][bag] && V[i][bag]==(V[i-1][bag-w[i]]+p[i])){
            cout<<"    "<<i<<"      "<<w[i]<<"     "<<p[i]<<endl;
            bag=bag-w[i];
        }
    }


}

int main(){

   int i,j,p[100],w[100],n,bag;

   cout<<"\nenter number of item: ";
   cin>>n;
   cout<<"\nenter the profit: ";
   for(i=1;i<=n;i++){
      cin>>p[i];
   }
   cout<<"\nenter the weight: ";
   for(j=1;j<=n;j++){
    cin>>w[j];
   }
   cout<<"\nenter the capacity of the bag: ";
   cin>>bag;
   knapsack(p,w,bag,n);

}
