#include <bits/stdc++.h>
using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0);
char _;

int main()
{
    ios::sync_with_stdio(0);

    int n, m, i, s, e;
    scan(n); scan(m);
    vector<int> tree[n+1];
    double chances[n+1], split;

    while (m--) {
        scan(s); scan(e);
        tree[s].push_back(e);
    }

    for (i = 0; i <= n; i++)
        chances[i] = 0;
    chances[1] = 1;

    for (i = 1; i <= n; i++) {
        if (tree[i].size()) {
            split = chances[i]/tree[i].size();
            for (int child : tree[i])
                chances[child] += split;
        }
        else
            printf("%.9lf\n", chances[i]);
    }

    return 0;
}
