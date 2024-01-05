#include <iostream>
#include <vector>
#include <cmath>

std::string s;
long long p = pow(10, 9) + 7, n, x_ = 257;

int ord(char c) {
    return c;
}

bool isequal(std::vector<int> &h, std::vector<int> &x, int from1, int from2, int slen) {
    return (
        (h[from1 + slen - 1] + h[from2 - 1] * x[slen]) % p ==
        (h[from2 + slen - 1] + h[from1 - 1] * x[slen]) % p
    );
}

int
main()
{
    std::cin >> s;
    n = s.length();
    std::vector<int> h(n + 1), x(n + 1);
    x[0] = 1;
    s = " " + s;
    for (int i = 1; i < n + 1; ++i) {
        std::cout << h[i - 1] << std::endl;
        h[i] = (h[i - 1] * x_ + ord(s[i])) % p;
        x[i] = (x[i - 1] * x_) % p;
    }
    
    int num;
    std::cin >> num;
    for (int i = 0; i < num; ++i) {
        int l, a, b;
        std::cin >> l >> a >> b;
        if (isequal(h, x, a, b, l)) {
            std::cout << "yes" << std::endl;
        } else {
            std::cout << "no" << std::endl;
        }
    }
    return 0;
}