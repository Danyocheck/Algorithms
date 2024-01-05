#include <iostream>
#include <vector>

int Manaker_odd(std::string &s) {
    int l = 0, r = -1, n = s.length();
	std::vector<int> d1(n);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        int k = i > r ? 1 : std::min(d1[l + r - i], r - i + 1);
        while (i+k < n && i-k >= 0 && s[i+k] == s[i-k]) {
            ++k;
        }
        d1[i] = k;
        sum += k;
        if (i + k - 1 > r) {
            l = i - k + 1,  r = i + k - 1;
        }
    }
    return sum;
}

int Manaker_even(std::string &s) {
    int l = 0, r = -1, n = s.length();
	std::vector<int> d2 (n);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        int k = i > r ? 0 : std::min (d2[l + r - i + 1], r - i + 1);
        while (i + k < n && i - k - 1 >= 0 && s[i + k] == s[i - k - 1]) { 
            ++k;
        }
        d2[i] = k;
        sum += k;
        if (i + k - 1 > r) {
            l = i - k,  r = i + k - 1;
        }
    }
    return sum;
}

int main() {
    std::string s;
    std::cin >> s;

    int even = Manaker_even(s);
    int odd = Manaker_odd(s);

    std::cout << even + odd << std::endl;
}