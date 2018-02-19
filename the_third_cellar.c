#include <stdio.h>

int main()
{
    int * primes = malloc(1000001 * sizeof(int));
    for (int i = 0; i <= 1000000; i++)
        primes[i] = 1;
    for (int i = 2; i < 1000; i++)
    {
        if (primes[i])
            for (int j = 2; j*i <= 1000000; j++)
                primes[(i*j)] = 0;
    }
    primes[1] = 0;
    int test_cases;
    scanf("%d", &test_cases);
    for (; test_cases > 0; test_cases--)
    {
        int s, e;
        scanf("%d %d", &s, &e);
        int out = 0;
        for (int i = s; i < e; i++)
        {
            if (primes[i])
                ++out;
        }
        printf("%d\n", out);
    }
    free(primes);
    return 0;
}
