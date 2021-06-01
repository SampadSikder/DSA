#include <bits/stdc++.h>
using namespace std;
int graph[1000][1000];



int main()
{
    string bd[100];
    int node;
    printf("Enter number of nodes: ");
    cin >> node;

    string a, b;
    printf("Enter the edges(2 at a time): \n");

    // initialize
    for (int i = 0; i < node; i++)
    {
        for (int j = 0; j < node; j++)
        {
            graph[i][j] = 0;
        }
    }
    int u = 0, v = 0;

    // input
    while (1)
    {
        cin >> a >> b; //dhaka = a khulna = b
        if (a == "-1" || b == "-1")
            break;

        for (int i = 0; i < 100; i++)
        {
            if (bd[i].size())
            {

                if (bd[i] == a)
                {
                    u = i;
                    break;
                }
            }

            else
            {
                bd[i] = a;
                u = i;
                break;
            }
        }

        for (int i = 0; i < 100; i++)
        {
            if (bd[i].size())
            {

                if (bd[i] == b)
                {
                    v = i;
                    break;
                }
            }

            else
            {
                bd[i] = b;
                v = i;
                break;
            }
        }

        graph[u][v] = 1;
        graph[v][u] = 1;
    }
    cout << setw(10) << " ";

    for (int col = 0; col < node; col++)
    {
        //printf(" %10s ", bd[col]);
        cout << setw(10) <<bd[col];
    }

    cout << endl;
    for (int row = 0; row < node; row++)
    {
        cout  <<bd[row] ;

        for (int j = 0; j < node; j++)
        {
            cout << setw(10) << graph[row][j];
        }
        cout << endl;
    }

    while(1){
        string x,y;
        cin >> x;
        cin >> y;
        if(x=="-1" || y=="-1") break;
        
        u = -1;
        v = -1;
        

        for(int i=0; i<node; i++){
            if(bd[i] == x){
                u = i;
                break;
            }
        }

         for(int i=0; i<node; i++){
            if(bd[i] == y){
                v = i;
                break;
            }
        }
        if(u == -1 || v == -1) cout << "NO" << endl;
        else if(graph[u][v]){
            cout << "YES\n";
        }
        else cout << "NO\n";
    }
    
}