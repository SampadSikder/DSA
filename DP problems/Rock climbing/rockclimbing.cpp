#include <bits/stdc++.h>
using namespace std;
#define INF 1e9 + 5
#define DIAGONAL -1
#define UP -2
#define UPRIGHT -3
const int N = 100;
int A[N][N];
int b[N][N] = {0};
int indexmin = 0;
int rock_climbing(int C[][100], int n, int m)
{
    // initialize first row with 0
    for (int j = 0; j < m + 2; j++)
    {
        A[0][j] = 0;
    }
    // initialize first column and last column with infinity
    for (int i = 0; i <= n; i++)
    {
        A[i][0] = INF;
        A[i][m + 1] = INF;
    }
    // starting from second row find the minimum moves for each indexes for up diagonal and upleft
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            A[i][j] = C[i - 1][j - 1] + min(A[i - 1][j - 1], min(A[i - 1][j], A[i - 1][j + 1]));
            // direction
            if (A[i][j] == C[i - 1][j - 1] + A[i - 1][j - 1])
            {
                b[i][j] = DIAGONAL;
            }
            if (A[i][j] == C[i - 1][j - 1] + A[i - 1][j])
            {
                b[i][j] = UP;
            }
            if (A[i][j] == C[i - 1][j - 1] + A[i - 1][j + 1])
            {
                b[i][j] = UPRIGHT;
            }
        }
    }
    int minn = INF;
    // for (int i = 0; i <= n; i++)
    // {
    //     for (int j = 0; j <= m + 1; j++)
    //     {
    //         cout << A[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    for (int j = 1; j <= m; j++)
    {
        minn = min(minn, A[n][j]);
        if (minn == A[n][j])
        {
            indexmin = j;
        }
    }
    return minn;
}

void print_path(int C[][100], int n, int m)
{
    int i = n;
    int j = indexmin;
    while (i > 0)
    {
        if (b[i][j] == DIAGONAL)
        {
            cout << C[i - 1][j - 1] << " ";
            i--;
            j--;
        }
        else if (b[i][j] == UP)
        {
            cout << C[i - 1][j - 1] << " ";
            i--;
        }
        else if (b[i][j] == UPRIGHT)
        {
            cout << C[i - 1][j - 1] << " ";
            i--;
            j++;
        }
    }
}
int main()
{
    freopen("in.txt", "r", stdin);
    int C[N][N];
    int row, col;
    cin >> row >> col;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> C[i][j];
        }
    }
    int minn = rock_climbing(C, row, col);
    cout << "Minimum climbing: " << minn << endl;
    print_path(C, row, col);

    return 0;
}
