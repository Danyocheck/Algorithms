#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printPermutations(int N) {
    vector<int> numbers(N);
    for (int i = 0; i < N; ++i) {
        numbers[i] = i + 1;
    }

    do {
        for (int i = 0; i < N; ++i) {
            cout << numbers[i];
        }
        cout << endl;
    } while (next_permutation(numbers.begin(), numbers.end()));
}

int main() {
    int N;
    cin >> N;
    printPermutations(N);

    return 0;
}