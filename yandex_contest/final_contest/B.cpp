#include <iostream>
#include <vector>

using namespace std;

vector<int> calculateZFunction(const string& S) {
    int N = S.length();
    vector<int> z(N, 0);

    int left = 0, right = 0;

    for (int i = 1; i < N; ++i) {
        if (i <= right) {
            z[i] = min(right - i + 1, z[i - left]);
        }

        while (i + z[i] < N && S[z[i]] == S[i + z[i]]) {
            ++z[i];
        }

        if (i + z[i] - 1 > right) {
            left = i;
            right = i + z[i] - 1;
        }
    }

    return z;
}

int main() {
    int N;
    cin >> N;

    string S;
    cin >> S;

    vector<int> zFunction = calculateZFunction(S);

    for (int i = 0; i < N; ++i) {
        cout << zFunction[i] << " ";
    }

    return 0;
}