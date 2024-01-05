#include <iostream>
#include <vector>

std::vector<int> merge(std::vector<int> &vec1, std::vector<int> &vec2) {
    if (vec1.size() == 0) {
        return vec2;
    }
    if (vec2.size() == 0) {
        return vec1;
    }
    int resMasSize = vec1.size() + vec2.size();
    int vec1Pointer = 0, vec2Pointer = 0, resPointer = 0;
    std::vector<int> resMas(resMasSize);
    while (resPointer != resMasSize) {
        if (vec1Pointer == vec1.size()) {
            resMas[resPointer] = vec2[vec2Pointer];
            ++vec2Pointer;
        } else if (vec2Pointer == vec2.size()) {
            resMas[resPointer] = vec1[vec1Pointer];
            ++vec1Pointer;
        } else if (vec1[vec1Pointer] <= vec2[vec2Pointer]) {
            resMas[resPointer] = vec1[vec1Pointer];
            ++vec1Pointer;
        } else {
            resMas[resPointer] = vec2[vec2Pointer];
            ++vec2Pointer;
        }
        ++resPointer;
    }
    return resMas;
}

std::vector<int> merge_sorting(std::vector<int> &vec) {
    if (vec.size() == 1) {
        return vec;
    }
    std::vector<int> vec1(vec.begin(), vec.begin() + vec.size() / 2);
    std::vector<int> vec2(vec.begin() + vec.size() / 2, vec.end());
    vec1 = merge_sorting(vec1);
    vec2 = merge_sorting(vec2);
    vec = merge(vec1, vec2);
    return vec;
}

int
main()
{
    int num;
    std::cin >> num;
    std::vector<int> vec(num);
    for (int i = 0; i < num; ++i) {
        std::cin >> vec[i];
    }
    vec = merge_sorting(vec);
    for (int i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}