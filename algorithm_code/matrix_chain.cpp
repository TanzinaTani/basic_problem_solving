#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;


int main()
{
    FILE *file1,*file2;

    file1=fopen("dimension.txt","r");
    file2=fopen("cost.txt","w");

    int n,j,q,min,i;
    int p[100];
    int m[5][5]={0};

    cout<<"loading size...."<<endl;
    fscanf(file1,"%d",&n);

    cout<<"loading dimension....."<<endl;
    for(i=0; i<n; i++)
    {
        fscanf(file1,"%d",&p[i]);
    }

    for(int d=1; d<n-1; d++)
    {
        for(i=1; i<n-d; i++)
        {
            j=i+d;
            min=10000000;
            for(int k=i; k<=j-1; k++)
            {
                q = m[i][k] + m[k+1][j] +  p[i-1]*p[k]*p[j];
                if(q<min)
                {
                    min=q;
                }
            }
            m[i][j]=min;
        }
    }
    fprintf(file2,"minimum cost of multipication : %d",m[1][n-1]);

    fclose(file1);
    fclose(file2);
    return 0;
}
