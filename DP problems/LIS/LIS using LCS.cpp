#include <bits/stdc++.h>
using namespace std;
#define UP -1
#define LEFT -2
#define DIAGONAL -3
int b[100][100] = {0}; // arrow table
int LIS_using_LCSlength(int seq[], int n)
{
    // lcs table c
    int dp[n + 1][n + 1];
    int sorted_seq[n];
    // copy to another array
    for (int i = 0; i < n; i++)
    {
        sorted_seq[i] = seq[i];
    }
    sort(sorted_seq, sorted_seq + n);

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0; // c[i][0] = 0 and c[j][0] = 0
            }
            else if (seq[i - 1] == sorted_seq[j - 1])
            {
                dp[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = DIAGONAL;
            }
            else if (dp[i - 1][j] >= dp[i][j - 1])
            {
                dp[i][j] = dp[i - 1][j];
                b[i][j] = UP;
            }
            else
            {
                dp[i][j] = c[i][j - 1];
                b[i][j] = LEFT;
            }
        }
    }
    return dp[m][n];
}
void print_lcs(int arr[], int n)
{
    int i = n, j = n;
    vector<int> res;
    while (i > 0 && j > 0)
    { // using two pointers
        if (b[i][j] == DIAGONAL)
        {
            res.push_back(arr[i - 1]);
            i--;
            j--;
        }
        else if (b[i][j] == UP)
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    reverse(res.begin(), res.end()); // reverse the string
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i];
    }
}

int main()
{
    // freopen("lcsinput.txt", "r", stdin);
    int n;
    // enter size of array
    cin >> n;
    int arr[n];

    // enter array elements
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "LIS using LCS: " << LIS_using_LCS(arr, n) << endl;

    print_LIS(arr, n);
}