#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    char mapping[91];
    int hydra_index[9] = {7, 0, 8, 11, 7, 24, 3, 17, 0};
    char alphabet[27], m[27];
    for (int i = 'A'; i <= 'Z'; i++)
        alphabet[i-'A'] = i;
    char line[100001];
    int l, length;
    cin >> line >> l;
    line[100000] = '\0';
    length = strlen(line);
    while (l--)
    {
		cin >> m;
        m[26] = '\0';
		char use[10];
	    for (int i = 0; i < 9; i++)
            use[i] = m[hydra_index[i]];
        use[9] = '\0';
        if (strstr(line, use) != NULL)
        {
            for (int i = 0; i < 26; i++)
                mapping[m[i]] = alphabet[i];
            for (unsigned int i = 0; i < length; i++)
                line[i] = mapping[line[i]];
            cout << line;
            return 0;
        }
    }
    cout << "KeyNotFoundError";
    return 0;
}
