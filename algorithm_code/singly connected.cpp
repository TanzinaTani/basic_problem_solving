#include<stdio.h>
#include<iostream>
using namespace std;
const int MaxVertex = 100;
int V, E;
int AdjMat[MaxVertex][MaxVertex];
int s[MaxVertex], f[MaxVertex], prevs[MaxVertex], color[MaxVertex];
int time = 0,m=0,t=0;

void DFS_Recur(int u){
    int i;
    color[u] = 1;
    time++;
    s[u] = time;
    for(i = 1; i <= V; i++){
        if(AdjMat[u][i] == 1){
            if(color[i] == 2){
                if(s[u]<s[i] ||  s[u]>s[i]){
                    m=1;
                }
            }
            if(color[i]==0){
            prevs[i] = u;
               DFS_Recur(i);
        }
    }
    }
    color[u] = 2;
    time++;
    f[u] = time;

}

void DFS_Forest(){
    int i;

    for(i = 1; i <= V; i++){
        color[i] = 0;
        s[i]=-1;
        f[i]=-1;
        prevs[i]=-1;
    }
    for(i = 1; i <= V; i++){
        if(color[i] == 0 ){

            DFS_Recur(i);
        }

    }
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
    if(m==1){
        cout<<"not singly connected\n";
    }
    else {
        cout<<"singly connected\n";
    }
    for(i = 1; i <= V; i++){
        printf("start: %d  finish: %d\n", s[i], f[i]);
    }
}


