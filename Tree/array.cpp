#include <bits/stdc++.h>
using namespace std;
const int N = 100;

int a[N] = {0};

int main()
{
    int n;
    printf("How many nodes?: ");
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] == -1)
        {
            n++;
        }
    }
    printf("Memory representation: ");

    for (int i = 0; i < n; i++)
    {
        if (a[i] == -1)
        {
            printf("- ");
        }
        else
            printf("%d ", a[i]);
    }
    int x;
    printf("Find parent,child of: ");
    cin >> x;
    cout << n << endl;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
        {
            printf("Parent of %d: %d, left child: %d, right child: %d\n", x, a[(i - 1) / 2], a[2 * i + 1], a[2 * i + 2]);
        }
    }
    // hello there
}
