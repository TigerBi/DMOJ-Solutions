#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

char grid[25][25];

#define valid(y,x) (grid[y][x] == '.')

int explore(int sy, int sx)
{
	int size = 1;
	grid[sy][sx] = 'V';
	if (valid(sy+1, sx))
		size += explore(sy+1, sx);
	if (valid(sy-1, sx))
		size += explore(sy-1, sx);
	if (valid(sy, sx+1))
		size += explore(sy, sx+1);
	if (valid(sy, sx-1))
		size += explore(sy, sx-1);
	return size;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int planks, w, h;
	cin >> planks >> h >> w;
	for (int y = 0; y < h; y++) {
		for (int x = 0; x < w; x++) {
			cin >> grid[y][x];
		}
	}
	vector<int> sizes;
	while (true) {
		int ex, ey;
		bool brk = false;
		for (int y = 0; y < h; y++) {
			for (int x = 0; x < w; x++) {
				if (valid(y, x)) {
					ey = y;
					ex = x;
					brk = true;
					break;
				}
			}
			if (brk) break;
		}
		if (!brk)
			break;
		sizes.push_back(explore(ey, ex));
	}
	sort(sizes.begin(), sizes.end());
	int r_fitted = 0;
	for (int i = sizes.size()-1; i >= 0; i--) {
		if (planks - sizes[i] >= 0) {
			planks -= sizes[i];
			r_fitted++;
		}
		else
			break;
	}
	if (r_fitted == 1)
		cout << "1 room, ";
	else
		cout << r_fitted << " rooms, ";
	cout << planks << " square metre(s) left over";
    return 0;
}
