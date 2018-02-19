#include <cstdio>
using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0);
int arr[100001], n, q, i, t1, t2, o;
char _, query;

int main()
{
    scan(n);
    scan(q);
    for (i = 1; i <= n; i++)
        scan(arr[i]);
    while (q--) {
        query = getchar();
        if (query == 'U') {
            scan(t1);
            scan(t2);
            arr[t1] = t2;
        }
        else {
            scan(t1);
            scan(t2);
            scan(o);
            for (i = t1; i <= t2; i++)
                o &= arr[i];
            printf("%d\n", o);
        }
    }
    return 0;
}
