#include<stdio.h>
#include<iostream>
using namespace std;
const int MaxVertex = 100;
int V, E;
int AdjMat[MaxVertex][MaxVertex];
int s[MaxVertex], f[MaxVertex], prev[MaxVertex], color[MaxVertex];

bool DFS_Recur(int u){
    int i;
    color[u] = 1;
    for(i = 1; i <= V; i++){
        if(AdjMat[u][i]==1 && color[i] == 1 ){
                return true;
        }
          if(AdjMat[u][i]==1  && color[i]==0 &&  DFS_Recur(i) ){
            return true;
          }
        }

    color[u] = 2;

    return false;
}

bool DFS_Forest(){
    int i;

    for(i = 1; i <= V; i++){
        color[i] = 0;
    }
    for(i = 1; i <= V; i++){
        if(color[i] == 0){
           if( DFS_Recur(i)==true){

            return true;
}
}
}

           return false;
}

int main(){
    int start, end, i;
    freopen("detect cycle.txt", "r", stdin);
    scanf("%d%d", &V, &E);
    for(i = 1; i <= E; i++){
        scanf("%d%d",&start,&end);
        AdjMat[start][end] = 1;
       // AdjMat[end][start] = 1;
    }
    if(DFS_Forest())

     cout << "Graph contains cycle";
    else
        cout << "Graph doesn't contain cycle";

}


