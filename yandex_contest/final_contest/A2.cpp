#include <iostream>
#include <set>

long long findCx(int x) {
    std::set<long long> mergedSequence;
    long long idxA = 1, idxB = 1;

    while (mergedSequence.size() < static_cast<size_t>(x)) {
        long long valA = idxA * idxA;
        long long valB = idxB * idxB * idxB;

        if (valA < valB) {
            mergedSequence.insert(valA);
            ++idxA;
        } else {
            mergedSequence.insert(valB);
            ++idxB;
        }
    }

    auto it = mergedSequence.begin();
    std::advance(it, x - 1);
    return *it;
}

int main() {
    int x;
    std::cin >> x;

    long long resultCx = findCx(x);

    std::cout << resultCx << std::endl;

    return 0;
}
