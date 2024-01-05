#include <iostream>
#include <vector>

int find_min(std::vector<int> &seq, int L, int R) {
    int min = seq[L];
    for (int i = L; i <= R; ++i) {
        if (seq[i] < min) min = seq[i];
    }
    return min;
}

int find_max(std::vector<int> &seq, int L, int R) {
    int max = seq[L];
    for (int i = L; i <= R; ++i) {
        if (seq[i] > max) max = seq[i];
    }
    return max;
}

int
main()
{
    int num1, num2;
    std::vector<int> seq;
    std::cin >> num1 >> num2;
    for (int i = 0; i < num1; ++i) {
        int num;
        std::cin >> num;
        seq.push_back(num);
    }

    for (int i = 0; i < num2; ++i) {
        int L, R;
        std::cin >> L >> R;
        int min = find_min(seq, L, R);
        int max = find_max(seq, L, R);
        if (max - min < 1) {
            std::cout << "NOT FOUND" << std::endl;
        } else {
            std::cout << max << std::endl;
        }
    }

    return 0;
}