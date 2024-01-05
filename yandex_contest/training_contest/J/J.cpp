#include <iostream>
#include <map>

// не работает тест 34 8 9
// Ответ: 16 18

int
main()
{
    int num;
    std::cin >> num;
    for (int i = 0; i < num; ++i) {
        unsigned long long n, a, b;
        bool find = false;
        std::map<unsigned long long, unsigned long long> dict;
        std::cin >> n >> a >> b;
        for (unsigned long long j = a; j <= b; ++j) {
            if (n % j == 0) {
                std::cout << "YES" << std::endl;
                find = true;
                break;
            } else if (dict.find(n % j) != dict.end()) {
                std::cout << "YES" << std::endl;
                find = true;
                break;
            } else {
                dict[j] = 1;
            }
        }
        if (!find) {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}