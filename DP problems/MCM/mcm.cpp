#include <bits/stdc++.h>
using namespace std;
#define N 100
const int INF = 1e9 + 5;
int s[N][N];
int m[N][N];

int mcm(int p[], int i, int j)
{
    // m[i][j] = INF;
    if (i == j)
    {
        m[i][j] = 0; // diagonal 0
    }
    if (m[i][j] < INF)
    {
        return m[i][j];
    }

    else
    {
        for (int k = i; k < j; k++)
        {
            m[i][j] = min(mcm(p, i, k) + mcm(p, k + 1, j) + p[i - 1] * p[k] * p[j], m[i][j]);
        }
    }
    return m[i][j];
    /*for (int l = 2; l <= n; l++)
    { // l indicate kore koyta multiply kortisi
        for (int i = 1; i <= n - l + 1; i++)
        {
            int j = i + l - 1; // l length er matrix kothay sesh hobe
            m[i][j] = INF;     // for minimum
            for (int k = i; k <= j - 1; k++)
            {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }*/
}
int memoised(int p[], int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            m[i][j] = INF;
        }
    }
    return mcm(p, 1, n - 1);
}
int main()
{
    // freopen("mcm.txt", "r", stdin);
    int n;
    cin >> n;
    int p[n];

    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    cout << "Minimum order:" << memoised(p, n) << endl;

    cout << "DP array: " << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }

    /*for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << s[i][j] << " ";
        }
        cout << endl;
    }
    cout << "------------" << endl;
    cout << "Optimal cost:" << endl;*/

    // print_parens(1, n - 1);
}