#include<stdio.h>
#include<iostream>
using namespace std;
const int MaxVertex = 100;
int V, E;
int AdjMat[MaxVertex][MaxVertex];
int s[MaxVertex], f[MaxVertex], prevs[MaxVertex], color[MaxVertex];
int time = 0;

void DFS_Recur(int u){
    int i;
    color[u] = 1;
    time++;
    s[u] = time;
    for(i = 1; i <= V; i++){
        if(AdjMat[u][i] == 1) {
        if( color[i] == 0){
            prevs[i] = u;
            color[i]=1;
            DFS_Recur(i);
    }
    }
    }
    time++;
    f[u] = time;
    color[u] = 2;

}

void DFS_Forest(){
    int i,c=0;

    for(i = 1; i <= V; i++){
        color[i] = 0;
        prevs[i]=-1;
    }
    for(i = 1; i <= V; i++){
        if(color[i] == 0 ){
             c++;
            DFS_Recur(i);

        }

    }
    cout<<"\n total tree "<<c<<endl;
}
int main(){
    int start, end, i;
    freopen("detect cycle.txt", "r", stdin);
    scanf("%d%d", &V, &E);
    for(i = 1; i <= E; i++){
        scanf("%d%d",&start,&end);
        AdjMat[start][end] = 1;
        //AdjMat[end][start] = 1;
    }
    DFS_Forest();
    for(i = 1; i <= V; i++){
        printf("for vertex %d: start: %d  finish: %d  prevs: %d\n",i, s[i], f[i],prevs[i]);
    }

}


