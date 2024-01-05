#include <iostream>
#include <vector>

const int p = 31; // простое число
const int m = 1e9 + 9; // большое простое число

std::pair<std::vector<long long>, std::vector<long long > > compute_hashes(const std::vector<long long>& s, std::vector<long long> &p_powers) {
    int n = s.size();
    std::vector<long long> hashes(n + 1, 0);
    std::vector<long long> hashes_revers(n + 1, 0);
    p_powers[0] = 1;

    // Заполняем степени p
    for (int i = 1; i <= n; ++i) {
        p_powers[i] = (p_powers[i - 1] * p) % m;
    }

    // Вычисляем хэши для всех префиксов
    for (int i = 0; i < n; ++i) {
        hashes[i + 1] = (hashes[i] + s[i] * p_powers[i]) % m;
        hashes_revers[i + 1] = (hashes_revers[i] + s[n - 1 - i] * p_powers[i]) % m;
    }

    return std::make_pair(hashes, hashes_revers);
}

bool are_hashes_equal(const std::vector<long long>& hashes, const std::vector<long long>& hashes_revers, std::vector<long long> &p_powers, int a, int b, int l) {
    long long hash_a = (hashes_revers[a + l] - hashes_revers[a] + m) % m;
    long long hash_b = (hashes[b + l] - hashes[b] + m) % m;
    return (hash_a * p_powers[b]) % m == (hash_b * p_powers[a]) % m;
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::vector<long long> s(n);

    for (long long i = 0; i < n; ++i) {
        std::cin >> s[i];
    }

    std::vector<long long> p_powers(s.size() + 1, 0);
    std::pair<std::vector<long long>, std::vector<long long > > pair = compute_hashes(s, p_powers);
    std::vector<long long> hashes = pair.first, hashes_revers = pair.second;

    std::vector<long long> answ;
    answ.push_back(n);
    for (long long i = 1; i < n / 2 + 1; ++i) {
        if (are_hashes_equal(hashes, hashes_revers, p_powers, n - i, i, i)) {
            answ.push_back(n - i);
        }
    }

    for (int i = answ.size() - 1; i >= 0; --i) {
        std::cout << answ[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
