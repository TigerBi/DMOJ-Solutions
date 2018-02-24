#include <stdio.h>

int arr[100005], n, q, c, t1, t2;
unsigned long long bit[100005];

void add(int i, int v) { for (; i <= n; i += i&-i) bit[i] += v; }

void take(int i, int v) { for (; i <= n; i += i&-i) bit[i] -= v; }

int query(int i)
{
    int v = 0;
    for (; i > 0; i -= i&-i)
        v += bit[i];
    return v;
}

int main()
{
    scanf("%d %d\n", &n, &q);
    for (int i = 0; i < n; i++) bit[i] = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
        add(i,arr[i]);
    }
    while (q-- && getchar()) {
        c = getchar();
        if (c == 'C') {
            scanf("%d %d", &t1, &t2);
            take(t2,arr[t1-1]);
            add(t2,t1);
            arr[t1-1] = t2;
        }
        else if (c == 'S') {
            scanf("%d %d", &t1, &t2);
            printf("%lld\n", query(t1)-query(t2));
        }
        else {
            scanf("%d", &t2);
            t1 = 0;
            for (int i = 0; i < n; i++)
                if (arr[i] <= t2) ++t1;
            printf("%d\n", t1);
        }
    }
    return 0;
}
