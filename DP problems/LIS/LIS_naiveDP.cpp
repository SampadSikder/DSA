#include <bits/stdc++.h>
using namespace std;
const int N = 100;
#define INF 1e9
int L[N];
int prevv[N];
int LIS_naiveDP(int arr[], int n)
{
    // int L[n + 1];
    // int prev[n + 1];
    L[0] = 0;
    prevv[0] = -1;

    int maxIndex = 0, maxLength = 0;

    for (int i = 1; i <= n; i++)
    {
        L[i] = -INF;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j] && L[i] < L[j] + 1)
            {
                L[i] = L[j] + 1;
                prevv[i] = j;
            }
        }
        if (L[i] > maxLength)
        {
            maxLength = L[i];
            maxIndex = i;
        }
    }
    return maxLength;
}
void print_LIS(int arr[], int n)
{
    int i = n - 1;
    vector<int> res;
    while (i >= 0)
    {
        res.push_back(arr[i]);
        i = prevv[i];
    }
    reverse(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
}

int main()
{

    int n;
    // enter size of array
    cin >> n;
    int arr[n] = {0};

    cout << "enter array elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "LIS Naive Dp: " << LIS_naiveDP(arr, n) << endl;

    print_LIS(arr, n);
}