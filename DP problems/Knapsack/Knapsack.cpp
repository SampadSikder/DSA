#include <bits/stdc++.h>
using namespace std;
const int N = 100;

int item[N], weight[N], value[N];
int dp[N][N]; //->1 to n indexing

int main()
{
    int n, W;
    cin >> n >> W; //highest no of items and total Weight

    for (int i = 1; i <= n; i++)
    {
        cin >> weight[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> value[i];
    }

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= W; j++)
    {
        dp[0][j] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int w = 1; w <= W; w++)
        {
            if (weight[i] > w) //i tomo item er weight jodi current weight theke beshi
            {
                dp[i][w] = dp[i - 1][w];
            }
            else
            {
                dp[i][w] = max(value[i] + dp[i - 1][w - weight[i]], dp[i - 1][w]);
            }
        }
    }
    cout << dp[n][W] << endl;

    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            cout << dp[i][w] << " ";
        }
        cout << endl;
    }
}