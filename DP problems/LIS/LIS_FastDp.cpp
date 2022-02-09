#include <bits/stdc++.h>
using namespace std;
#define INF 1e9 + 5
const int N = 100;

int L[N] = {0};
int prevv[N] = {-1};
// binary search to find the ceiling
int ceil(int input[], int T[], int end, int s)
{
    int start = 0;
    int middle;
    int len = end;
    while (start <= end)
    {
        middle = (start + end) / 2;
        if (middle < len && input[T[middle]] < s && s <= input[T[middle + 1]])
        {
            return middle + 1;
        }
        else if (input[T[middle]] < s)
        {
            start = middle + 1;
        }
        else
        {
            end = middle - 1;
        }
    }
    return -1;
}
int LIS_FastDP(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        prevv[i] = -1;
    }
    L[0] = 0;
    int len = 0;

    for (int i = 1; i < n; i++)
    {
        if (arr[L[0]] > arr[i])
        {
            L[0] = i;
        }
        else if (arr[L[len]] < arr[i])
        {
            len++;
            L[len] = i;
            prevv[L[len]] = L[len - 1];
            // cout << "len: " << len << " Element: " << L[len] << endl;
        }
        else // binary search to find ceil of arr[i]
        {
            int index = ceil(arr, L, n, arr[i]);
            L[index] = i;
            prevv[L[index]] = L[index - 1];
        }
    }
    cout << "Subsequence: " << endl;
    int index = L[len];
    while (index != -1)
    {
        cout << arr[index] << " ";
        index = prevv[index];
    }
    cout << endl;
    return len + 1;
}
int main()
{
    int n;
    // enter size of array
    cin >> n;
    int arr[n];

    // enter array elements
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "LIS fast DP: " << LIS_FastDP(arr, n) << endl;
}