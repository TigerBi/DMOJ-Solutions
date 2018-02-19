#include <stdio.h>

char grid[100][100], m = 'r';
int n, my, cx, cy;

void move() {
    if(m=='r')cx++; else if(m=='l')cx--; else if (m=='u')cy--; else cy++;
    if (cy < 0 || cy >= m || cx < 0 || cx >= n) return;
    char l = grid[cy][cx];
    if (m == 'u') {
        if (l == '\\') m = 'l';
        else if (l == '/') m = 'r';
        else if (l == '-') m = 'd';
    }
    else if (m == 'd') {
        if (l == '\\') m = 'r';
        else if (l == '/') m = 'l';
        else if (l == '-') m = 'u';
    }
    else if (m == 'l') {
        if (l == '\\') m = 'u';
        else if (l == '/') m = 'd';
        else if (l == '|') m = 'r';
    }
    else {
        if (l == '\\') m = 'd';
        else if (l == '/') m = 'u';
        else if (l == '|') m = 'l';
    }
}

int main() {
    int t;
    scanf("%d %d %d\n", &n, &my, &t);
    for (int y = 0; y < my; y++) {
        for (int x = 0; x < n; x++) {
            grid[y][x] = getchar();
            if (grid[y][x] == 'O') {
                cy = y;
                cx = x;
            }
        }
        getchar();
    }
    for (int i = 1; i <= t; i++) {
        move();
        if (cy < 0 || cy >= my || cx < 0 || cx >= n) {
            printf("The observer leaves the grid after %d tick(s).", i);
            return 0;
        }
    }
    printf("The observer stays within the grid.");
    return 0;
}
