#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	unordered_set<long> powers;
	powers.insert(1);
	long power = 2;
	for (short i = 1; i <= 62; i++) {
		powers.insert(power);
		power *= 2;
	}
	int repeats;
	cin >> repeats;
	while (repeats--) {
		long number;
		cin >> number;
		if (powers.find(number) != powers.end())
			cout << "T\n";
		else
			cout << "F\n";
	}
    return 0;
}
