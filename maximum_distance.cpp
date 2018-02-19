#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ALL(myVec) myVec.begin(), myVec.end()
#define FOUND(myVec, x) find(ALL(myVec), x)!=myVec.end()

int findfirst(vector<int> myVec, int f)
{
	for (int i = 0; i < myVec.size(); i++) {
		if (myVec[i] == f)
			return i;
	}
}

int findlast(vector<int> myVec, int f)
{
	for (int i = myVec.size() - 1; i >= 0; i--) {
		if (myVec[i] == f)
			return i;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int test_cases;
	cin >> test_cases;
	for (; test_cases > 0; test_cases--) {
		int length;
		cin >> length;
		vector<int> one, two;
		for (int i = 0; i < length; i++) {
			int use;
			cin >> use;
			one.push_back(use);
		}
		for (int i = 0; i < length; i++) {
			int use;
			cin >> use;
			two.push_back(use);
		}
		int b = max(one[0], two[0]);
		int d = 0;
		for (; b > 0; b--) {
			if ((FOUND(one, b)) && (FOUND(two, b)))
				d = max(d, 0-(findfirst(one, b)-findlast(two, b)));
		}
		cout << "The maximum distance is " << d << '\n';
	}
  return 0;
}
