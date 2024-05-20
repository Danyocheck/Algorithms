#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool comparator(pair<long long, long long> a, pair<long long, long long> b) {
    return a.first < b.first;
}

int
main() {
    long long n, q;
    cin >> n >> q;
    vector<pair<long long, long long>> staff(n);
    vector<pair<long long, long long>> indexes(n);

    for (long long i = 0; i < n; ++i) {
        long long a_i, b_i;
        cin >> a_i >> b_i;
        staff[i] = make_pair(a_i, b_i);
        indexes[i] = make_pair(b_i, i);
    }

    sort(indexes.begin(), indexes.end(), comparator);
    long long max_profit = 0;
    for (long long i = 0; i < n; ++i) {
        max_profit += staff[i].first - (n - i) * staff[indexes[i].second].second;
    }

    cout << max_profit << endl;

    for (long long i = 0; i < q; ++i) {
        long long index, a_i, b_i;
        cin >> index >> a_i >> b_i;
        --index;
        staff[index] = make_pair(a_i, b_i);
        for (long long k = 0; k < n; k++) {
            if (indexes[k].second == index) {
                index = k;
                break;
            }
        }
        indexes[index].first = b_i;

        if (index != n - 1 && indexes[index].first >= indexes[index + 1].first) {
            long long k = index;
            while (k < n - 1 && indexes[k].first >= indexes[k + 1].first) {
                swap(indexes[k], indexes[k + 1]);
                k++;
            }
        } else if (index != 0 && indexes[index].first <= indexes[index - 1].first) {
            long long k = index;
            while (k > 0 && indexes[k].first <= indexes[k - 1].first) {
                swap(indexes[k], indexes[k - 1]);
                k--;
            }
        }

        max_profit = 0;
        for (long long j = 0; j < n; ++j) {
            max_profit += staff[j].first - (n - j) * staff[indexes[j].second].second;
        }

        cout << max_profit << endl;
    }
}