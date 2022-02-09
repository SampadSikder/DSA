#include <bits/stdc++.h>
using namespace std;

int cutting_chocolate(int p[][100], int tp[], int chocolate_area, int len, int wid)
{
    int i, j, maxx = -1;

    //finding pieces and max profit
    for (i = 1; i <= len; i++)
    {
        for (j = i; i * j <= chocolate_area && j <= wid; j++)
        {
            if (p[i][j] + tp[chocolate_area - (i * j)] > maxx)
            {
                maxx = p[i][j] + tp[chocolate_area - (i * j)];
            }
        }
    }
    tp[chocolate_area] = maxx;

    return tp[chocolate_area];
}
int main()
{
    int profit[100][100] = {}, tot_profit[100] = {};
    int number, length, width, tot_area, k, l;

    //taking input
    cin >> number;
    cin >> length;
    cin >> width;
    for (k = 1; k <= length; k++)
    {
        for (l = 1; l <= width; l++)
        {
            cin >> profit[k][l];
        }
    }
    //calculating area
    tot_area = length * width;
    int ans;

    //calculating max profit and finds using which area we get max profit
    for (k = 1; k <= tot_area; k++)
    {
        ans = cutting_chocolate(profit, tot_profit, k, length, width);
    }
    cout << "Max: " << ans << endl;
}
