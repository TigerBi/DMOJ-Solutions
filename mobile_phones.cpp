#include <iostream>
using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0);
int **grid, arr[4], s, q, y, x, t1, t2, t3, t4, out;
char _;

int main()
{
    scan(q);
    scan(s);
    grid = new int *[s];
    for (y = 0; y < s; y++)
    {
        grid[y] = new int[s];
        for (x = 0; x < s; x++)
            grid[y][x] = 0;
    }
    while (1)
    {
        scan(q);
        if (q == 1)
        {
            scan(t1);
            scan(t2);
            scanf("%d", &t3);
            grid[t1][t2] += t3;
            continue;
        }
        else if (q == 2)
        {
            out = 0;
            scan(t1);
            scan(t2);
            scan(t3);
            scan(t4);
            for (y = t1; y <= t3; y++)
            {
                for (x = t2; x <= t4; x++)
                    out += grid[y][x];
            }
            printf("%d\n", out);
            continue;
        }
        break;
    }
    return 0;
}
