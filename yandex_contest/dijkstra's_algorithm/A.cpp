#include <iostream>
#include <vector>
#include <queue>

void dijkstraa(std::vector<std::vector<int> > &matrix, std::vector<int> &distance, std::vector<bool> &visited, int current)
{
    if (visited[current]) {
        return;
    }
    visited[current] = true;
    for (int i = 1; i < matrix.size(); ++i) {
        if (matrix[current][i] == -1 || i == current) {
            continue;
        }
        distance[i] = std::min(distance[i], distance[current] + matrix[current][i]);
    }

    for (int i = 1; i < matrix.size(); ++i) {
        if (matrix[current][i] == -1 || i == current) {
            continue;
        }
        dijkstraa(matrix, distance, visited, i);
    }
}

int
main()
{
    int n, s, f;
    std::cin >> n >> s >> f;
    std::vector<std::vector<int> > matrix(n + 1, std::vector<int>(n + 1));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; j++) {
            std::cin >> matrix[i][j];
        }
    }

    std::vector<int> distance(n + 1, 1000000000);
    std::vector<bool> visited(n + 1, false);
    distance[s] = 0;
    dijkstraa(matrix, distance, visited, s);

    std::cout << distance[f] << std::endl;

    return 0;
}