// passes as opposed to cars_on_ice.cpp

#include <stdio.h>

#define gc getchar
#define SIZE 2001

int grid[SIZE][SIZE];
int r, c;

void trace(int y, int x)
{
    if (grid[y][x] == 'N')
    {
        for (int _y = y-1; _y >= 0; _y--)
            if (grid[_y][x] != '.')
                trace(_y,x);
    }
    else if (grid[y][x] == 'E')
    {
        for (int _x = x+1; _x < c; _x++)
            if (grid[y][_x] != '.')
                trace(y,_x);
    }
    else if (grid[y][x] == 'S')
    {
        for (int _y = y+1; _y < r; _y++)
            if (grid[_y][x] != '.')
                trace(_y,x);
    }
    else if (grid[y][x] == 'W')
    {
        for (int _x = x-1; _x >= 0; _x--)
            if (grid[y][_x] != '.')
                trace(y,_x);
    }
    printf("(%d,%d)\n", y, x);
    grid[y][x] = '.';
}

int main()
{
    scanf("%d %d\n", &r, &c);
    for (int y = 0; y < r; y++)
    {
        for (int x = 0; x < c; x++)
            grid[y][x] = gc();
        gc();
    }
    for (int y = r-1; y >= 0; y--)
    {
        for (int x = c-1; x >= 0; x--)
            if (grid[y][x] != '.')
                trace(y,x);
    }
    return 0;
}
