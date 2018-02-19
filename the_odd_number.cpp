#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, ans = 0, x;
    cin >> n;
    while (n-- && cin >> x)
        ans ^= x;
    cout << ans;
    return 0;
}
