#include <bits/stdc++.h>
using namespace std;
#define UP -1
#define LEFT -2
#define DIAGONAL -3
int b[100][100] = {0}; //arrow table
int lcs_length(string x, string y, int m, int n)
{
    //lcs table c
    int c[m + 1][n + 1];

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
            {
                c[i][j] = 0; //c[i][0] = 0 and c[j][0] = 0
            }
            else if (x[i - 1] == y[j - 1])
            {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = DIAGONAL;
            }
            else if (c[i - 1][j] >= c[i][j - 1])
            {
                c[i][j] = c[i - 1][j];
                b[i][j] = UP;
            }
            else
            {
                c[i][j] = c[i][j - 1];
                b[i][j] = LEFT;
            }
        }
    }
    return c[m][n];
}
void print_lcs(string x, string y, int m, int n)
{
    int i = m, j = n;
    vector<char> res;
    while (i > 0 && j > 0)
    { //using two pointers
        if (b[i][j] == DIAGONAL)
        {
            res.push_back(x[i - 1]);
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
    reverse(res.begin(), res.end()); //reverse the string
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i];
    }
}

int main()
{
    //freopen("lcsinput.txt", "r", stdin);
    string x, y;
    int m, n;
    cout << "Enter the two strings: ";
    cin >> x >> y;
    m = x.length(); //first string
    n = y.length(); //second string
    int len = lcs_length(x, y, m, n);
    cout << "LCS:" << len << endl;
    print_lcs(x, y, m, n);
}