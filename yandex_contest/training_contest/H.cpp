#include <iostream>

int
main()
{
    int a, b, n;
    std::cin >> a >> b >> n;
    if (b % n == 0) {
        if (a > b / n) {
            std::cout << "Yes" << std::endl;
        } else {
            std::cout << "No" << std::endl;
        }
    } else {
        if (a > b / n + 1) {
            std::cout << "Yes" << std::endl;
        } else {
            std::cout << "No" << std::endl;
        }
    }
}