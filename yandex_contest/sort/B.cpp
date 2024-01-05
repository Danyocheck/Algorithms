#include <iostream>
#include <vector>

void partition(std::vector<int>& vec, int left, int right)
{
    if (left >= right || right - left == 1) {
        return;
    }
    int equal_pointer = left, upper_pointer = left, x = vec[left + rand() % (right - left + 1)];
    for (int i = left; i < right; ++i) {
        if (vec[i] < x) {
            if (equal_pointer == upper_pointer) {
                int tmp = vec[equal_pointer];
                vec[equal_pointer] = vec[i];
                vec[i] = tmp;
            } else {
                int tmp1 = vec[equal_pointer], tmp2 = vec[upper_pointer];
                vec[equal_pointer] = vec[i];
                vec[upper_pointer] = tmp1;
                vec[i] = tmp2;
            }
            ++equal_pointer;
            ++upper_pointer;
        } else if (vec[i] == x) {
            int tmp = vec[upper_pointer];
            vec[upper_pointer] = vec[i];
            vec[i] = tmp;
            if (i + 1 < right && vec[upper_pointer] <= vec[i + 1]) {
                ++upper_pointer;
            }
        }
    }
    partition(vec, left, equal_pointer);
    partition(vec, upper_pointer, right);
    return;
}

int
main()
{
    int num;
    std::cin >> num;
    std::vector<int> vec(num);
    int left = 0, right = num;
    for (int i = 0; i < num; ++i) {
        std::cin >> vec[i];
    }
    partition(vec, left, right);
    for (int i = 0; i < num; ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}