#include <iostream>
using namespace std;

int board[8][8];
#define process(y, x) if((!(y >= 8 || y < 0 || x >= 8 || x < 0)) && (board[y][x] == -1))board[y][x]=use;

int hop(int n, int targetX, int targetY)
{
	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++) {
			if (board[y][x] == n) {
				int use = n + 1;
				process(y+1, x+2);
				process(y+2, x+1);
				process(y+2, x-1);
				process(y+1, x-2);
				process(y-1, x-2);
				process(y-2, x-1);
				process(y-2, x+1);
				process(y-1, x+2);
			}
		}
	}
	if (board[targetY][targetX] != -1)
		return board[targetY][targetX];
	return -1;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++) {
			board[y][x] = -1;
		}
	}
	int sx, sy, tx, ty;
	cin >> sx >> sy >> tx >> ty;
	sx--;
	sy--;
	tx--;
	ty--;
	board[sy][sx] = 0;
	for (int i = 0; i < 40; i++) {
		int use = hop(i, tx, ty);
		if (use != -1) {
			cout << use;
			return 0;
		}
	}
  return 0;
}
