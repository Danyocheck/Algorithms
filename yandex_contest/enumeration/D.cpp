#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>

const int INF = std::numeric_limits<int>::max();

int salesman(std::vector<std::vector<int>> &matrix, int N) {
    if (N <= 1) {
        return 0;
    }
    std::vector<int> numbers(N);
    for (int i = 0; i < N; ++i) {
        numbers[i] = i + 1;
    }
    int min = INF;
    bool is_circle = false;

    do {
        int dist = matrix[numbers[0]][numbers[1]];
        bool no_loop = false;
        if (dist >= min || matrix[numbers[0]][numbers[1]] == 0) {
            continue;
        }
        for (int i = 1; i < N - 1; ++i) {
            if (dist > min || matrix[numbers[i]][numbers[i + 1]] == 0) {
                no_loop = true;
                break;;
            }
            dist += matrix[numbers[i]][numbers[i + 1]];
        }
        if (matrix[numbers[N - 1]][numbers[0]] == 0 || no_loop) {
            continue;
        }
        dist += matrix[numbers[N - 1]][numbers[0]];
        if (dist < min) {
            min = dist;
            is_circle = true;
        }
    } while (next_permutation(numbers.begin(), numbers.end()));

    if (is_circle) {
        return min;
    } else {
        return -1;
    }
}

int
main()
{
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> matrix(n + 1, std::vector<int>(n + 1));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    std::cout << salesman(matrix, n) << std::endl;
}