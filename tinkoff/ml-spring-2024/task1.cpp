#include <iostream>
#include <vector>

using namespace std;

int
main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> marks(n);
    for (int i = 0; i < n; ++i) {
        cin >> marks[i];
    }

    int max_num_of_fives = -1;
    for (int i = 6; i < n; ++i) {
        int curr_num_of_fives = 0;
        for (int j = i - 6; j <= i; ++j) {
            if (marks[j] == 2 || marks[j] == 3) {
                curr_num_of_fives = -1;
                break;
            }
            if (marks[j] == 5) {
                ++curr_num_of_fives;
            }
        }

        if (curr_num_of_fives > max_num_of_fives)
            max_num_of_fives = curr_num_of_fives;
    }
    cout << max_num_of_fives << endl;
}