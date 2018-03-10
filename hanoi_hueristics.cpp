#include <stdio.h>
using namespace std;

void move(int n, int from, int to)
{
    int empty = 6-from-to;
    if (n <= 0)
        return;
    move(n-1, from, to);
    printf("%d %d\n", from, empty);
    move(n-1, to, from);
    printf("%d %d\n", empty, to);
    move(n-1, from, to);
}

int main()
{
    int n, thing, out = 1;
    // all input data is useless to me, except for "n"
    scanf("%d %d", &n, &thing);
    while (thing--)
    {
        char nothing[4];
        scanf("%s", &nothing);
    }
    for (int i = 0; i < n; i++)
        out *= 3;
    --out;
    printf("%d\n", out);
    move(n, 1, 3);
}
