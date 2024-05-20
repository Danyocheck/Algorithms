#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>

using namespace std;

int
main() {
    long long N, K, t;
    cin >> N >> K >> t;
    vector<long long> fireworks(N);
    for (long long i = 0; i < N; ++i) {
        cin >> fireworks[i];
    }
    long long elem = fireworks[t - 1];

    sort(fireworks.begin(), fireworks.end());
    long long l = 0;
    while (fireworks[l] != elem) {
        ++l;
    }

    long long min_diff = LONG_MAX;
    for (int i = l; i <= l + K - 1; ++i) {
        if (i - K + 1 < 0 || i > N - 1) continue;
        min_diff = min(min_diff, fireworks[i] - fireworks[i - K + 1]);
    }

    cout << min_diff << endl;

    return 0;
}