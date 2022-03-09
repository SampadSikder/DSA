#include <bits/stdc++.h>
using namespace std;
bool comparator(pair<int, int> a, pair<int, int> b)
{
    return a.first > b.first;
}
int main()
{
    // freopen("inputactivity.txt", "r", stdin);
    int n;
    cin >> n;

    int s[n], f[n];

    for (int i = 0; i < n; i++)
    {
        cin >> s[i] >> f[i];
    }

    pair<int, int> activity[n];

    for (int i = 0; i < n; i++)
    {
        activity[i].first = f[i];
        activity[i].second = s[i];
    }
    sort(activity, activity + n, comparator); // sorting the activities according to finish time

    for (int i = 0; i < n; i++)
    {
        f[i] = activity[i].first;
        s[i] = activity[i].second;
    }
    cout << "After sorting according to finish time:" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << ":" << s[i] << " " << f[i] << endl;
    }
    /*int index_array[n];

    for (int i = 0; i < n; i++)
    {
        index_array[i] = -1;
    }*/

    int index = n - 1;
    vector<int> index_array;
    index_array.push_back(n - 1);
    int j = index_array.size() - 1;
    // index_array[index] = 0;

    for (int i = n - 2; i >= 0; i--)
    {
        if (f[index_array[j]] <= s[i]) // if current activity is finished before the next activity starts(accepted er khetre)
        {
            index_array.push_back(i);
            j++;
        }
    }
    cout << "Accepted index:(Taking first index as 1)" << endl;
    cout << "{";
    // printing
    for (int i = 0; i < index_array.size(); i++)
    {
        if (i == index_array.size() - 1) // for printing comma
        {
            cout << index_array[i];
        }
        else
        {
            cout << index_array[i] << ",";
        }
    }
    cout << "}" << endl;

    return 0;
}