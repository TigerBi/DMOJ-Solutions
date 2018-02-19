#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<vector<int>> nodes;
vector<int> end_nodes;
unordered_map<int, long double> out;
int n;

void share(long double p, int index)
{
    if (nodes[index].size() != 0)
        p /= nodes[index].size();
    if (find(end_nodes.begin(), end_nodes.end(), index) == end_nodes.end())
    {
        for (int node : nodes[index])
            share(p, node);
    }
    else
        out[index] += p;
}

int main()
{
    int l;
    cin >> n >> l;
    while (n--)
        nodes.push_back(end_nodes);
    n = nodes.size();
    nodes.push_back(end_nodes);
    while (l--)
    {
        int s, e;
        cin >> s >> e;
        nodes[s].push_back(e);
    }
    ++n;
    for (int i = 1; i < n; i++)
    {
        if (nodes[i].size() == 0)
            end_nodes.push_back(i);
    }
    for (int item : end_nodes)
        out[item] = 0;
    share(1, 1);
    for (int item : end_nodes)
        cout << out[item] << '\n';
    return 0;
}
