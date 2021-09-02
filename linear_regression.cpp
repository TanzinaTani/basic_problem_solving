#include <iostream>
#include <fstream>
using namespace std;
int main(){
double x[4][4] = {{1, 2, 3,4},{4,5,1,3},{7,3,2,1},{3,7,5,7}};
double y[] = {5, 7, 3, 11};
float W0=0.5,W1=0.5,W2=0.5,W3=0.5,W4=0.5,alpha=0.001;
float slope[55],d[55],yPredict[50],error[55],c;
int m=0,iteration;
cout<<"Enter the iteration number: ";
cin>>iteration;
while( m < iteration){
c=0;
for(int j=0;j<4;j++){
slope[j]=0;
yPredict[j]=W0+W1*x[j][0]+W2*x[j][1]+W3*x[j][2]+W4*x[j][3];
error[j]=yPredict[j]-y[j];
c=c+error[j];
}
for(int j=0;j<4;j++){
for(int k=0;k<4;k++){
d[j]=error[k]*x[k][j];
slope[j]=slope[j]+error[k]*x[k][j];
}
}
W0=W0-(alpha*c);
W1=W1-(alpha*slope[0]);
W2=W2-(alpha*slope[1]);
W3=W3-(alpha*slope[2]);
W4=W4-(alpha*slope[3]);
cout<<"Iteration "<<m+1<<endl;
cout<<"New y predicted Value: ";
for(int i=0;i<4;i++){
cout<<" "<<yPredict[i]<< " ";
}
cout<<endl;
cout<<"error value: ";
for(int i=0;i<4;i++){
cout<<" "<<error[i]<< " ";
}
cout<<endl;
cout<<"Slope value: ";
cout<<" "<<c<<" ";
for(int i=0;i<4;i++){
cout<<" "<<slope[i]<< " ";
}
cout<<endl;
cout<<" new W0 is "<< W0<<endl;
cout<<" new W1 is "<< W1<<endl;
cout<<" new W2 is "<< W2<<endl;
cout<<" new W3 is "<< W3<<endl;
cout<<" new W4 is "<< W4<<endl;
m++;
}
}
