#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
  float w[100],p[100],bag;
  int i,S;
  cout<<"Enter the number of items: ";
  cin>>S;
   cout<<"\nEnter the weight: ";
   for(i=0;i<S;i++){
        cin>>w[i];
   }

    cout<<"\nEnter the unit price: ";
   for(i=0;i<S;i++){
        cin>>p[i];
   }
   cout<<"\nEnter the bag size: ";
   cin>>bag;
   float pw[100];
   cout<<"\nper unit weight: ";
   for(i=0;i<S;i++){
        pw[i]=(p[i]/w[i])*1.00;
        cout<<"  "<<pw[i];
   }
  int j;
    for(i=0;i<S;i++){
        for(j=i+1;j<S;j++){
            if(pw[i]<pw[j]){
                float temp=pw[j];
                pw[j]=pw[i];
                pw[i]=temp;
                float temp1=w[j];
                w[j]=w[i];
                w[i]=temp1;

                float temp2=p[j];
                p[j]=p[i];
                p[i]=temp2;
            }
        }
    }
    cout<<endl<<"sorted unit per weight: ";

    for(i=0;i<S;i++){
        cout<<"  "<<pw[i];
   }
   cout<<endl;
   for(i=0;i<S;i++){
        cout<<"  "<<w[i];
   }
   cout<<endl;
   for(i=0;i<S;i++){
        cout<<"  "<<p[i];
   }
   float s=0.0;

   while(bag!=0.0){
    for(int i=0;i<S;i++){
    if(w[i]<=bag){
        s=s+w[i]*pw[i];
        bag=bag-w[i];
    }
    else{
        s=s+bag*pw[i];
        bag=0.0;
    }
   }
   }



   printf("\nMaximum profit is:  %f", s);

}

