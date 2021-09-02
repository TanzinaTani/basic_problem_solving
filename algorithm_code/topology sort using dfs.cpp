#include<iostream>
#include<stack>
#include<stdio.h>
using namespace std;
const int MaxVertex = 100;
int V, E;
int AdjMat[MaxVertex][MaxVertex];
int s[MaxVertex], f[MaxVertex], prev[MaxVertex], color[MaxVertex];
int time = 0,m=0;

void DFS_Recur(int u,bool visited[],stack<int>&stk){
    int i;
    visited[u] = true;
    for(i = u; i <= V; i++){
        if(AdjMat[u][i] == 1 ){
        if(!visited[i]){
           DFS_Recur(i,visited,stk);
        }

    }
    }
    stk.push(u);

}

void DFS_Forest(){
    int i,c=0;

    stack<int>stk;
    bool visit[V];
    for(i = 1; i <= V; i++){
        visit[i]=false;

    }
    for(i = 1; i <= V; i++){
        if(!visit[i] ){
            DFS_Recur(i,visit,stk);

        }
        while(!stk.empty()){
            cout<<stk.top()<<" ";
            stk.pop();
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
    }
    DFS_Forest();


}
