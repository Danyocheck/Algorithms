#include <iostream>
#include <map>

int
main()
{
    std::string str1, str2;
    std::cin >> str1 >> str2;
    std::map<char, int> chars_from_str1;
    if (str1.size() != str2.size()) {
        std::cout << "NO" << std::endl;
        return 0;
    }
    for (int i = 0; i < str1.size(); ++i) {
        chars_from_str1[str1[i]] += 1;
    }
    for (int i = 0; i < str2.size(); ++i) {
        if (chars_from_str1.find(str2[i]) == chars_from_str1.end() || chars_from_str1[str2[i]] < 0) {
            std::cout << "NO" << std::endl;
            return 0;
        }
        chars_from_str1[str2[i]] -= 1;
    }

    std::cout << "YES" << std::endl;
    return 0;
}