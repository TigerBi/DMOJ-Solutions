#include <cstdio>

#define SZ 1000001
int arr[SZ], n, t, a, b, c, sz, max_sz, cc, l;

int main()
{
    scanf("%d %d", &n, &t);
    for (int i = 0; i <= n; i++)
        arr[i] = 0;
    while (t--) {
        scanf("%d %d %d", &a, &b, &c);
        for (int i = a; i <= b; i++)
            arr[i] += c;
    }
    scanf("%d", &l);
    max_sz = 0;
    for (int i = 1; i <= n; i++) {
        cc = 0;
        sz = 0;
        for (int j = i; j <= n; j++) {
            cc += arr[j];
            if (cc > l) break;
            ++sz;
        }
        if (sz > max_sz)
            max_sz = sz;
    }
    printf("%d\n", max_sz);
    return 0;
}
