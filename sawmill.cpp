#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<int> consumptions;
	vector<int> logs;
	int repeats;
	cin >> repeats;
	for (int i = repeats; i > 0; i--) {
		int use;
		cin >> use;
		consumptions.push_back(use);
	}
	for (int i = repeats; i > 0; i--) {
		int use;
		cin >> use;
		logs.push_back(use);
	}
	sort(consumptions.begin(), consumptions.end());
	sort(logs.begin(), logs.end());
	reverse(logs.begin(), logs.end());
	long total = 0;
	for (int i = 0; i < repeats; i++) {
		total += (consumptions[i] * logs[i]);
	}
	cout << total;
	return 0;
}
