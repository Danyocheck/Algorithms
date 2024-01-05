#include <iostream>
#include <vector>

int
main()
{
    int num, x;
    std::cin >> num;
    std::vector<int> vec(num);
    for (int i = 0; i < num; ++i) {
        std::cin >> vec[i];
    }
    std::cin >> x;
    int upper_pointer = 0;
    for (int i = 0; i < num; ++i) {
        if (vec[i] < x) {
            int tmp = vec[upper_pointer];
            vec[upper_pointer] = vec[i];
            vec[i] = tmp;
            ++upper_pointer;
        }
    }

    std::cout << upper_pointer << "\n" << num - upper_pointer << std::endl;
    return 0;
}