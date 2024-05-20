#include <iostream>
#include <vector>

int
main()
{
    std::vector<int> height;
    int new_elem;
    while (std::cin >> new_elem) {
        height.push_back(new_elem);
    }

    int max_volume = 0, left_pointer = 0, right_pointer = height.size() - 1;
    while (left_pointer < right_pointer) {
        max_volume = std::max(std::min(height[left_pointer], height[right_pointer]) * (right_pointer - left_pointer), max_volume);
        if (height[left_pointer] > height[right_pointer]) {
            right_pointer -= 1;
        } else {
            left_pointer += 1;
        }
    }

    std::cout << max_volume << std::endl;
}