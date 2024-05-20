#include <iostream>
#include <vector>

using namespace std;

int
main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<long long>> matrix(n, vector<long long> (m));
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
        }
    }

    for (int j = 0; j < m; ++j) {
        for (int i = n - 1; i >= 0; --i) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}