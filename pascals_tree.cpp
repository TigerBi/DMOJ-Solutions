// too slow!

#include <stdio.h>
#include <vector>
using namespace std;

int main() {
    int r, m;
    scanf("%d %d", &r, &m);
    vector<long> current;
    current.push_back(1);
    for (int i = 0; i < r; i++) {
        vector<long> build;
        build.push_back(1);
        if (current.size() >= 2) {
            for (int x = 0; x < current.size()-1; x++) {
                build.push_back(current[x]+current[x+1]);
            }
        }
        build.push_back(1);
        current = build;
    }
    for (int i = 0; i < current.size(); i++) {
        printf("%ld\n", current[i]%m);
    }
    return 0;
}
