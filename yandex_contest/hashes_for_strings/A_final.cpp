#include <iostream>
#include <vector>

using namespace std;

const int p = 31; // простое число
const int m = 1e9 + 9; // большое простое число

vector<long long> compute_hashes(const string& s, vector<long long> &p_powers) {
    int n = s.length();
    vector<long long> hashes(n + 1, 0);
    p_powers[0] = 1;

    // Заполняем степени p
    for (int i = 1; i <= n; ++i) {
        p_powers[i] = (p_powers[i - 1] * p) % m;
    }

    // Вычисляем хэши для всех префиксов
    for (int i = 0; i < n; ++i) {
        hashes[i + 1] = (hashes[i] + (s[i] - 'a' + 1) * p_powers[i]) % m;
    }

    return hashes;
}

bool are_hashes_equal(const vector<long long>& hashes, vector<long long> &p_powers, int a, int b, int l) {
    long long hash_a = (hashes[a + l] - hashes[a] + m) % m;
    long long hash_b = (hashes[b + l] - hashes[b] + m) % m;
    return (hash_a * p_powers[b]) % m == (hash_b * p_powers[a]) % m;
}

int main() {
    string s;
    cin >> s;
    vector<long long> p_powers(s.length() + 1, 0);

    int q;
    cin >> q;

    vector<long long> hashes = compute_hashes(s, p_powers);

    for (int i = 0; i < q; ++i) {
        int l, a, b;
        cin >> l >> a >> b;
        if (are_hashes_equal(hashes, p_powers, a, b, l)) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }

    return 0;
}
