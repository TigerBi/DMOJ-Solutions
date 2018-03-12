#include <bits/stdc++.h>
using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0);
char _;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, s, e, paths[10000];
    vector<int> tree[10000];
    scan(n);

    do {
        scan(s); scan(e);
        tree[s].push_back(e);
    } while (s);

    memset(paths, 0, 10000 * sizeof(int));
    paths[1] = 1;
    for (int i = 1; i < n; i++) {
        for (int child : tree[i])
            paths[child] += paths[i];
    }

    cout << paths[n] << '\n';
    return 0;
}
