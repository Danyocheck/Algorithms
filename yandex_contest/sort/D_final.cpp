#include <iostream>
#include <vector>

std::vector<int> merge(std::vector<int> &vec1, std::vector<int> &vec2) {
    std::vector<int> resMas;
    resMas.reserve(vec1.size() + vec2.size()); // Заранее выделение памяти

    size_t vec1Pointer = 0, vec2Pointer = 0;

    while (vec1Pointer < vec1.size() && vec2Pointer < vec2.size()) {
        if (vec1[vec1Pointer] <= vec2[vec2Pointer]) {
            resMas.push_back(vec1[vec1Pointer]);
            ++vec1Pointer;
        } else {
            resMas.push_back(vec2[vec2Pointer]);
            ++vec2Pointer;
        }
    }

    // Добавление оставшихся элементов
    resMas.insert(resMas.end(), vec1.begin() + vec1Pointer, vec1.end());
    resMas.insert(resMas.end(), vec2.begin() + vec2Pointer, vec2.end());

    return resMas;
}

std::vector<int> merge_sorting(std::vector<int> &vec) {
    if (vec.size() <= 1) {
        return vec;
    }

    std::vector<int> vec1(vec.begin(), vec.begin() + vec.size() / 2);
    std::vector<int> vec2(vec.begin() + vec.size() / 2, vec.end());

    vec1 = merge_sorting(vec1);
    vec2 = merge_sorting(vec2);

    return merge(vec1, vec2);
}

int main() {
    int num;
    std::cin >> num;

    std::vector<int> vec;
    vec.reserve(num); // Заранее выделение памяти

    for (int i = 0; i < num; ++i) {
        int value;
        std::cin >> value;
        vec.push_back(value);
    }

    vec = merge_sorting(vec);

    for (const auto &value : vec) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    return 0;
}