#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1000000000;

int N;
vector<vector<int>> graph;
vector<int> matching;
vector<bool> visited;

// Алгоритм Куна для поиска максимального паросочетания
bool dfs(int v) {
    if (visited[v]) return false;
    visited[v] = true;

    for (int u = 0; u < N; ++u) {
        if (graph[v][u] != 0) {
            if (matching[u] == -1 || dfs(matching[u])) {
                matching[u] = v;
                return true;
            }
        }
    }

    return false;
}

// Находит максимальное паросочетание
int findMaxMatching() {
    matching.assign(N, -1);
    int maxMatching = 0;

    for (int v = 0; v < N; ++v) {
        visited.assign(N, false);
        if (dfs(v)) {
            ++maxMatching;
        }
    }

    return maxMatching;
}

int main() {
    cin >> N;

    graph.resize(N, vector<int>(N));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> graph[i][j];
        }
    }

    int maxMatching = findMaxMatching();

    // Выводим вес рёбер, соединяющих вершины из разных долей
    int totalWeight = 0;
    for (int u = 0; u < N; ++u) {
        if (matching[u] != -1) {
            totalWeight += graph[matching[u]][u];
        }
    }

    cout << totalWeight << endl;

    // Выводим номера долей для каждой вершины
    for (int v = 0; v < N; ++v) {
        if (matching[v] != -1) {
            cout << "1";
        } else {
            cout << "2";
        }
    }
    cout << endl;

    return 0;
}