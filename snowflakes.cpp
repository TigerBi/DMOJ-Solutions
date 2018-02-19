// fast enough to pass

#include <bits/stdc++.h>
using namespace std;

set<vector<int>> snowflakes;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, ns, i, tmp;
    cin >> ns;
    n = ns;
    while (ns--)
    {
        vector<int> snowflake;
        for (int i = 0; i < 6; i++)
        {
            cin >> tmp;
            snowflake.push_back(tmp);
        }
        sort(snowflake.begin(), snowflake.end());
        snowflakes.insert(snowflake);
    }
    if (snowflakes.size() == n)
        cout << "No two snowflakes are alike.";
    else
        cout << "Twin snowflakes found.";
    return 0;
}
