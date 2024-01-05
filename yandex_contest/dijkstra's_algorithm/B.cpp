#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <stack>

using namespace std;

const int INF = numeric_limits<int>::max();

void dijkstra(const vector<vector<int>>& graph, int start, vector<int>& distance, vector<int>& tops) {
    int n = graph.size();
    distance.assign(n, INF);
    tops.assign(n, -1);
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
                    tops[v] = u;
                    pq.push({distance[v], v});
                }
            }
        }
    }
}

void printShortestPath(int start, int end, const vector<int>& parent) {
    stack<int> path;
    for (int at = end; at != -1; at = parent[at]) {
        path.push(at);
    }

    while (!path.empty()) {
        cout << path.top() + 1 << " ";
        path.pop();
    }
    cout << endl;
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
    vector<int> tops;
    dijkstra(graph, S - 1, distance, tops);
    deque<int> result;

    if (distance[F - 1] == INF) {
        cout << -1 << endl;
    } else {
        printShortestPath(S - 1, F - 1, tops);
    }

    return 0;
}