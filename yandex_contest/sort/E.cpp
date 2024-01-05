#include <iostream>
#include <vector>
#include <map>

int
main()
{
    int num;
    std::cin >> num;
    std::vector<std::string> vec(num);
    std::map<char, std::vector<std::string> > dict;
    for (int i = 0; i < num; ++i) {
        std::cin >> vec[i];
    }

    if (vec.size() == 0) {
        return 0;
    }

    std::cout << "Initial array:" << std::endl;
    for (int i = 0; i < vec.size() - 1; ++i) {
        std::cout << vec[i] << ", ";
    }
    std::cout << vec[vec.size() - 1] << std::endl;
    
    int len = vec[0].length();
    for (int i = 0; i < len; ++i) {
        std::cout << "**********" << std::endl;
        std::cout << "Phase " << i + 1 << std::endl;
        for (int j = 0; j < vec.size(); ++j) {
            dict[vec[j][len - 1 - i]].push_back(vec[j]);
        }
        int pointer = 0;
        for (int j = 48; j < 58; ++j) {
            std::cout << "Bucket " << j - 48 << ": ";
            if (dict[j].size() == 0) {
                std::cout << "empty" << std::endl;
            } else {
                while (!dict[j].empty()) {
                    vec[pointer] = dict[j].front();
                    ++pointer;
                    if (dict[j].size() == 1) {
                        std::cout << dict[j].front();
                    } else {
                        std::cout << dict[j].front() << ", ";
                    }
                    dict[j].erase(dict[j].begin());
                }
                std::cout << std::endl;
            }
        }
    }
    std::cout << "**********" << std::endl;
    std::cout << "Sorted array:" << std::endl;
    for (int i = 0; i < vec.size() - 1; ++i) {
        std::cout << vec[i] << ", ";
    }
    std::cout << vec[vec.size() - 1] << std::endl;

    return 0;
}