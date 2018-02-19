#include <stdio.h>

int main()
{
    int grid[50][50], r, c;
    scanf("%d %d\n", &r, &c);
    for (int y = 0; y < r; y++)
    {
        for (int x = 0; x < c; x++)
            grid[y][x] = getchar();
        getchar();
    }
    --r;
    for (int i = 0; i < 100; i++)
    {
        for (int y = 0; y < r; y++)
            for (int x = 0; x < c; x++)
                if (grid[y][x] == 'o' && grid[y+1][x] == '.')
                {
                    grid[y][x] = '.';
                    grid[y+1][x] = 'o';
                }
    }
    ++r;
    for (int y = 0; y < r; y++)
    {
        for (int x = 0; x < c; x++)
            putchar(grid[y][x]);
        putchar('\n');
    }
    return 0;
}
