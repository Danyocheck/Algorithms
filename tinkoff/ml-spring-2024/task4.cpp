#include<iostream>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(0);
    int n;
    char c;
    cin >> n >> c;

    cout << 3 * n * n / 4 << endl;
    for(int i = 0; i < n / 2; ++i) {
        for (int j = i; j < n - i - 1; ++j) {
            if (c == 'R') {
                cout << i << " " << j << " " << n - j - 1 << " " << i << endl;
                cout << n - j - 1 << " " << i << " " << n - i - 1 << " " << n - j - 1 << endl;
                cout << n - i - 1 << " " << n - j - 1 << " " << j << " " << n - i - 1 << endl;
            } else if (c == 'L') {
                cout << n - i - 1 << " " << n - j - 1 << " " << j << " " << n - i - 1 << endl;
                cout << n - j - 1 << " " << i << " " << n - i - 1 << " " << n - j - 1 << endl;
                cout << i << " " << j << " " << n - j - 1 << " " << i << endl;
            }
        }
    }
}