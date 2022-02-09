#include <bits/stdc++.h>
using namespace std;
#define N 100
const long long int INF = LONG_MAX;
int r[N] = {-INF};
int s[N];

int cut_rod(int p[], int length)
{
    r[0] = 0;
    int i, j;

    for (int i = 1; i <= length; i++)
    {
        int q = -INF;
        for (int j = 0; j < i; j++) //0 index == length 1
        {
            if (q < p[j] + r[i - j - 1]) //if q is less than p+r-index
            {
                q = p[j] + r[i - j - 1];

                s[i] = j + 1; //saving the indexes jehetu 0 theke tai +1

                //cout << s[i] << endl;
            }
            //mx = max(mx, p[j] + r[i - j - 1]); //-1 diye 1 index komacchi as 1 length er value 0 index e
        }
        r[i] = q;
    }

    return r[length];
}
int print_cut_rod(int length)
{
    int n = length;
    cout << "Lengths are: ";
    while (n > 0)
    {
        cout << s[n] << " ";
        n -= s[n];
    }
}
int main()
{
    int total_length;
    //freopen("rodinput.txt", "r", stdin);
    cout << "Input total length: ";
    cin >> total_length;
    cout << "Enter lengthwise profit: ";
    int p[total_length];

    for (int i = 0; i < total_length; i++)
    {
        cin >> p[i]; //length wise profit
    }

    int max_profit = cut_rod(p, total_length);

    cout << "Profit is: " << max_profit << " ";
    print_cut_rod(total_length);
}
