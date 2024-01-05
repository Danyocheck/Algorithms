#include <iostream>

long long findCx(int x) {
    long long idxA = 1, idxB = 1;
    long long valA = 1, valB = 1;

    for (int i = 1; i <= x; ++i) {
        if (valA < valB) {
            if (i == x) {
                return valA;
            }
            ++idxA;
            valA = idxA * idxA;
        } else {
            if (i == x) {
                return valB;
            }
            ++idxB;
            valB = idxB * idxB * idxB;
        }
    }

    return -1;  // Недостижимо, так как мы всегда находим элемент Cx.
}

int main() {
    int x;
    std::cin >> x;

    long long resultCx = findCx(x);

    std::cout << resultCx << std::endl;

    return 0;
}
