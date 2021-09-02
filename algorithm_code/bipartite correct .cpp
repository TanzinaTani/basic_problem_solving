#include <iostream>
#include <queue>
#include <stdlib.h>
#include <time.h>
#include<stdio.h>

using namespace std;

int AdjMat[100][100];
int colorArr[100];
int V;
 bool isBipartite(int V ,int src){
     queue <int> q;
    for (int i = 1; i <= V; ++i){
        colorArr[i] = 0;
    }
       colorArr[src] = 1;
    q.push(src);
    while (!q.empty()){
        int u = q.front();
        q.pop();

        for (int v = 1; v <= V; ++v){
              if (AdjMat[v][v] == 1){
              return false;
        }
            if (AdjMat[u][v]==1 && colorArr[v] == 0){

                colorArr[v] = 1 - colorArr[u];
                q.push(v);
            }
            else if (AdjMat[u][v]==1 && colorArr[v] == colorArr[u])
                return false;
        }
    }

    return true;
}

int Bipar()
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



int main(){
   int r, i, data[10000];;

    FILE *in, *out;
    out = fopen("data.txt", "w");

    srand(time(NULL));   // Initialization, should only be called once.
    for(i = 0; i < 10; i++){
        r = rand();
        fprintf(out, "%d\n",r);
    }
    fclose(out);

    in = fopen("data.txt", "r");

    for(i = 0; i < 10; i++){
        fscanf(in, "%d",&data[i]);
        //printf("%d",&data[i]);
    }
    fclose(in);

    clock_t start, end;
    double cpu_time_used;

    start = clock();

    Bipar();
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nruntime:  %f", cpu_time_used);
    return 0;


}
