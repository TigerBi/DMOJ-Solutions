#include <stdio.h>

int grid[10][10];

int explore(int y, int x)
{
    if (y >= 0 && y < 10 && x >= 0 && x < 10 && grid[y][x] == '#') {
        int out = 1;
        grid[y][x] = 'V';
        out += explore(y+1,x);
        out += explore(y-1,x);
        out += explore(y,x+1);
        out += explore(y,x-1);
        return out;
    }
    return 0;
}

int main()
{
    int sep[10], test_cases = 5, sy, sx;
    while (test_cases--) {
        for (int y = 0; y < 10; y++) {
            for (int x = 0; x < 10; x++) {
                grid[y][x] = getchar();
                if (grid[y][x] == 'A') {
                    sy = y;
                    sx = x;
                    grid[y][x] = '#';
                }
            }
            getchar();
        }
        printf("%d\n", explore(sy,sx));
        scanf("%s\n", &sep);
    }
    return 0;
}
