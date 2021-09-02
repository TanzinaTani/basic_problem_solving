#include<iostream>
using namespace std;
int s[100],f[100],n,a[100];
void sorting(int a[],int s[],int f[]){

    int temp,temp1,temp2,i,j;
    for( i=2;i<=n;i++){
        for(j=1;j<n;j++){
            if(f[j]>f[j+1]){
                temp=f[j];
                f[j]=f[j+1];
                f[j+1]=temp;
               temp1=s[j];
               s[j]=s[j+1];
               s[j+1]=temp1;
               temp2=a[j];
               a[j]=a[j+1];
               a[j+1]=temp2;

            }
        }
    }
     cout<<endl<<"activity number:     ";
     for(int i=1;i<=n;i++){
        cout<<"\t"<<a[i];
    }
     cout<<endl<<"starting time:       ";
    for(int i=1;i<=n;i++){
        cout<<"\t"<<s[i];
    }

       cout<<"\nsorting finish time: ";
    for(int i=1;i<=n;i++){
        cout<<"\t"<<f[i];
    }

}
void activitySelection(int a[],int s[],int f[]){
     int j;
     j=1;
     cout<<"\nmaximum number of activity: " ;
     cout<<"{ "<<a[j];

    for(int i=2;i<=n;i++){
        if(s[i]>=f[j]){
            cout<<" "<<a[i];
            j=i;

        }
    }
    cout<<" } ";

}


int main(){

   cout<<"Enter the number of data: ";
   cin>>n;
   cout<<"\nenter the activity number: ";
   for(int i=1;i<=n;i++){
   cin>>a[i];
   }
   cout<<"\nenter the starting time: ";
   for(int i=1;i<=n;i++){
      cin>>s[i];
   }
   cout<<"\nEnter the finishing time: ";
   for(int i=1;i<=n;i++){
    cin>>f[i];
   }

    for(int i=1;i<=n;i++){
        cout<<"activity: "<<a[i]<<"start: "<<s[i]<<"   "<<"finish: "<<f[i]<<endl;
    }
    sorting(a,s,f) ;
    activitySelection(a,s,f);
}


