#include <bits/stdc++.h>
using namespace std;
#define UP -1
#define LEFT -2
#define DIAGONAL -3

int b[100][100] = {0};

int edit_distance(string x, string y, int m, int n)
{
    int edit_table[m + 1][n + 1];

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0)
            {
                edit_table[i][j] = j;
            }
            else if (j == 0)
            {
                edit_table[i][j] = i;
                //cout << "row complete" << endl;
            }
            else if (x[i - 1] == y[j - 1])
            {
                edit_table[i][j] = edit_table[i - 1][j - 1];
                b[i][j] = DIAGONAL;
            }
            else
            {
                edit_table[i][j] = 1 + min(edit_table[i - 1][j], min(edit_table[i][j - 1], edit_table[i - 1][j - 1])); //minimum of left diagonal and up

                if (min(edit_table[i - 1][j], min(edit_table[i][j - 1], edit_table[i - 1][j - 1])) == edit_table[i - 1][j])
                {
                    b[i][j] = LEFT; // left means Remove
                }
                else if (min(edit_table[i - 1][j], min(edit_table[i][j - 1], edit_table[i - 1][j - 1])) == edit_table[i][j - 1])
                {
                    b[i][j] = UP; //UP means insert
                }
                else
                    b[i][j] = DIAGONAL; //DIAGONAL means replace
            }
            //cout << edit_table[i][j] << " ";
            //if (j == n)
            //{
            //  cout << endl;
            //}
        }
    }
    return edit_table[m][n];
}
void print_path(string x, string y, int m, int n)
{
    int i = m, j = n;
    cout << "Changes starting from last:" << endl;
    while (i > 0 && j > 0)
    {
        if (b[i][j] == DIAGONAL && x[i - 1] == y[j - 1])
        {
            i--;
            j--;
        }
        else if (b[i][j] == DIAGONAL)
        {
            cout << "REPLACE at index " << i << ": " << x[i - 1] << " with " << y[j - 1] << endl;
            i--;
            j--;
        }
        else if (b[i][j] == UP)
        {
            cout << "INSERT: " << y[j - 1] << endl;
            j--;
        }
        else if (b[i][j] == LEFT)
        {
            cout << "REMOVE from index " << i << ": " << x[i - 1] << endl;
            i--;
        }
    }
}
int main()
{
    string x, y;
    cout << "Enter the 1st string followed by the 2nd: ";
    //freopen("edinput.txt", "r", stdin);
    cin >> x >> y;
    int m = x.length(), n = y.length();
    int res = edit_distance(x, y, m, n);
    cout << "Number of edits: " << res << endl;
    print_path(x, y, m, n);
}