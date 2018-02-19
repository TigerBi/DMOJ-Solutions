#include <stdio.h>
using namespace std;

#define process(y, x, z) if ((x) < w && (y) < h && (y) >= 0 && (x) >= 0 && (grid[y][x] == 'O' || grid[y][x] == 'W')) grid[y][x] = (z);

int grid[50][50];
int w, h;

void explore(int n)
{
	for (int y = 0; y < h; y++) {
		for (int x = 0; x < w; x++) {
			if (grid[y][x] == n) {
				process(y-1, x, n+1);
				process(y+1, x, n+1);
				process(y, x+1, n+1);
				process(y, x-1, n+1);
			}
		}
	}
}

int main()
{
	int test_cases;
	scanf("%d", &test_cases);
	for (; test_cases > 0; test_cases--) {
		int targetX = -1, targetY = -1;
		scanf("%d %d\n", &w, &h);
		for (int y = 0; y < h; y++) {
			for (int x = 0; x < w; x++) {
				grid[y][x] = getchar();
				if (grid[y][x] == 'W') {
					targetY = y;
					targetX = x;
				}
				else if (grid[y][x] == 'C')
					grid[y][x] = 0;
			}
            getchar();
		}
		for (int i = 0; i < 65; i++) {
			explore(i);
			if (grid[targetY][targetX] != 'W')
				break;
		}
		if (grid[targetY][targetX] >= 60)
			printf("#notworth\n");
		else
            printf("%d\n", grid[targetY][targetX]);
	}
	return 0;
}
