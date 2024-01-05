#include <iostream>

int
main()
{
    int num;
    std::cin >> num;
    for (int i = 0; i < num; ++i) {
        unsigned long long n, a, b;
        std::cin >> n >> a >> b;
        unsigned long long k;
        if (n % b == 0) {
            std::cout << "YES" << std::endl;
            continue;
        } else {
            k = n / b + 1;
        }
        if (a * k <= n && n <= b * k) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}