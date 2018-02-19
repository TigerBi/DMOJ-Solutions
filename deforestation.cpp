#include <iostream>
using namespace std;

int *arr = new int[1000001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, total = 0, s, e;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        total += s;
        arr[i] = total;
    }
    arr[0] = 0;
    cin >> n;
    while (n-- && cin >> s >> e)
        cout << (arr[e+1] - arr[s]) << '\n';
    return 0;
}
