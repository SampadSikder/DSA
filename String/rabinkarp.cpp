#include <bits/stdc++.h>
using namespace std;
#define d 26 // matching only lowercase alphabets
#define q 13 // prime number
const int N = 100;
int main()
{
    char text[N], pattern[N];
    gets(text);
    // getchar();
    gets(pattern);

    int n = strlen(text);
    int m = strlen(pattern);

    int p = 0, t = 0, h;

    h = ((int)pow(d, m - 1)) % q;

    // precalculation
    for (int i = 0; i < m; i++)
    {
        p = ((d * p) + pattern[i]) % q;
        t = ((d * t) + text[i]) % q;
    }
    int flag = 0;
    for (int i = 0; i < n - m + 1; i++)
    {
        int j = 0;
        if (p == t)
        {
            flag = 1;
            for (j = 0; j < m; j++)
            {
                if (text[i + j] != pattern[j])
                {
                    flag = 0;
                    break;
                }
            }
            if (flag && j == m)
            {
                cout << "Pattern found at index: " << i << endl;
            }
        }
        if (i < n - m)
        {
            t = (d * (t - text[i] * h) + text[i + m]) % q;
            if (t < 0)
            {
                t = t + q;
            }
        }
    }
}