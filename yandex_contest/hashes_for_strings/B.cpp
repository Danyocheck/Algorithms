#include <iostream>
#include <vector>

std::vector<int> prefix_function(std::string &s) {
	int n = s.length();
	std::vector<int> pi(n);
	for (int i = 1; i < n; ++i) {
		int j = pi[i - 1];
		while (j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }
		if (s[i] == s[j]) {
            ++j;
        }
		pi[i] = j;
	}
	return pi;
}

int main() {
    std::string s;
    std::cin >> s;

    std::vector<int> pi = prefix_function(s);
    // std::cout << s.length() - pi[s.length() - 1] << std::endl;
    for (int i = 0; i < pi.size(); ++i) {
        std::cout << pi[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}