#include <bits/stdc++.h>
using namespace std;

int main()
{
    string text, pattern;
    int cnt = 0;
    cin >> text >> pattern;
    for (int i = 0; i < text.length(); i++)
    {

        if (pattern[cnt] == text[i])
        {
            cnt++;
        }

        else
        {
            cnt = 0;
        }

        if (pattern.length() == cnt)
        {
            cout << "Pattern found at index " << i - cnt + 1;
            cout << " Upto index" << i << endl;
        }
    }
}