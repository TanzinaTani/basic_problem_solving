#include<bits/stdc++.h>
#define M 100
using namespace std;

int item, bag, mat[M][M], arr[M][M], weight[M], cost[M], a, b;

void fun(int x, int y)
{
    if(x == 0) return;
    if(arr[x][y] == 1)
    {
        fun(x-1, y-weight[x]);
        cout << x << "  ";
    }
    else fun(x-1, y);
}

int main()
{
    freopen("input.txt", "r", stdin);

    cout << "Enter the number of items: ";
    cin >> item;

    cout << "Enter the weight and cost of the items:" << endl;
    for(int i=1; i<=item; i++)
    {
        cout << "->  ";
        cin >> weight[i] >> cost[i];
    }

    cout << "Enter the bag size: ";
    cin >> bag;

    for(int i=0; i<=bag; i++) mat[0][i] = 0, arr[0][i] = -1;
    for(int i=0; i<=item; i++) mat[i][0] = 0, arr[i][0] = -1;

    cout << endl;
    for(int i=1; i<=item; i++)
    {
        for(int j=1; j<=bag; j++)
        {
            if(j-weight[i] < 0) mat[i][j] = mat[i-1][j];
            else
            {
                a = mat[i-1][j];
                b = mat[i-1][j-weight[i]] + cost[i];
                mat[i][j] = max(a, b);
            }
        }
    }

    cout << endl << endl;
    for(int i=0; i<=item; i++)
    {
        for(int j=0; j<=bag; j++)
        {
            printf("%-5d",mat[i][j]);
        }
        cout << endl;
    }
    cout << endl;

    for(int i=1; i<=item; i++)
    {
        for(int j=1; j<=bag; j++)
        {
            if(mat[i][j] == mat[i-1][j]) arr[i][j] = 0;
            else arr[i][j] = 1;
        }
    }

    cout << "Items are: ";
    fun(item, bag);
    cout << endl;

    return 0;
}




