#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int
main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<string> directories(n);
    for (int i = 0; i < n; ++i) {
        cin >> directories[i];
    }

    sort(directories.begin(), directories.end());
    for (int i = 0; i < n; ++i) {
        int last_slah = 0, num_of_slashs = 0, len = directories[i].size();
        for (int j = 0; j < len; ++j) {
            if (directories[i][j] == '/') {
                last_slah = j;
                ++num_of_slashs;
            }
        }

        if (last_slah == 0) {
            cout << string(num_of_slashs * 2, ' ') << directories[i].substr(last_slah, len) << endl;
        } else {
            cout << string(num_of_slashs * 2, ' ') << directories[i].substr(last_slah + 1, len) << endl;
        }
    }
}