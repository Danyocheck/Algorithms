#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

void dijkstra(const vector<vector<int>>& graph, int start, vector<int>& distance) {
    int n = graph.size();
    distance.assign(n, INF);
    distance[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        int dist_u = pq.top().first;
        pq.pop();

        if (dist_u > distance[u]) {
            continue;
        }

        for (int v = 0; v < n; ++v) {
            if (graph[u][v] != -1) {
                int weight = graph[u][v];
                if (distance[u] + weight < distance[v]) {
                    distance[v] = distance[u] + weight;
                    pq.push({distance[v], v});
                }
            }
        }
    }
}

int main() {
    int N, S, F;
    cin >> N >> S >> F;

    vector<vector<int>> graph(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> graph[i][j];
        }
    }

    vector<int> distance;
    dijkstra(graph, S - 1, distance);

    int result = distance[F - 1];
    cout << (result == INF ? -1 : result) << endl;

    return 0;
}
