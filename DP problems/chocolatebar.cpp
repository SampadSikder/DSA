#include <bits/stdc++.h>
#define N 100
using namespace std;
const int INF = LONG_MAX;
int r[N];

void chocolatecutting(int p[][100], int area, int m, int n)
{
    int q = -INF;

    //finding pieces and max profit
    for (int i = 1; i <= m; i++)
    {

        for (int j = i; i * j <= area && j <= n; j++)
        {
            if (p[i][j] + r[area - (i * j)] > q)
            {
                q = p[i][j] + r[area - (i * j)];
            }
        }
    }
    r[area] = q;
}
int main()
{
    int p[100][100] = {};

    int m, n, area;
    //freopen("chocolateinput.txt", "r", stdin);

    cin >> m >> n;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> p[i][j];
        }
    }
    area = m * n;

    //calculating max profit for each individual area
    for (int i = 1; i <= area; i++)
    {
        chocolatecutting(p, i, m, n);
    }
    cout << "Max profit: " << r[area] << endl;
}