#include <stdio.h>
using namespace std;

int main()
{
    bool primes[100000];
    for (int i = 0; i < 100000; i++)
        primes[i] = 1;
    for (int i = 2; i < 317; i++) {
        if (primes[i-1]) {
            for (int j = 2; j*i <= 100000; j++) {
                primes[j*i-1] = 0;
            }
        }
    }
    primes[0] = 0;
    int l, out = 0, f;
    scanf("%d", &l);
    for (; l > 0; l--) {
        scanf("%d", &f);
        if (primes[f-1])
            ++out;
    }
    printf("%d", out);
    return 0;
}
