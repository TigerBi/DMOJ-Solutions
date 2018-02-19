#include <stdio.h>

#define SIZE 2001
#define MIN(a,b) (((a)<(b))?(a):(b))
int grid[SIZE][SIZE];

int main()
{
    int n, y, x;
    unsigned long long triangles = 0;
    scanf("%d\n", &n);
    for (y = 0; y < n; y++) {
        for (x = 0; x < n; x++)
            grid[y][x] = getchar();
        getchar();
    }
    for (y = n-1; y >= 0; y--) {
        for (x = 0; x < n; x++) {
            if (grid[y][x] == '.')
                grid[y][x] = 0;
            else {
                if (x && x-n && y != n-1)
                    grid[y][x] = MIN(grid[y+1][x-1],MIN(grid[y+1][x],grid[y+1][x+1]))+1;
                else
                    grid[y][x] = 1;
            }
            triangles += grid[y][x];
        }
    }
    printf("%llu\n", triangles);
    return 0;
}
