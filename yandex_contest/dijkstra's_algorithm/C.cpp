#include <iostream>
#include <vector>
#include <limits>
#include <queue>

const long long INF = std::numeric_limits<long long>::max();

void dijkstra(const std::vector<std::vector<std::pair<long long, long long> > >& graph, long long start, std::vector<long long>& distance) {
    long long n = graph.size();
    distance.assign(n, INF);
    distance[start] = 0;

    std::priority_queue<std::pair<long long, long long>, std::vector<std::pair<long long, long long> >, std::greater<std::pair<long long, long long> > > pq;
    pq.push({0, start});

    while (!pq.empty()) {
        long long u = pq.top().second;
        long long dist_u = pq.top().first;
        pq.pop();

        if (dist_u > distance[u]) {
            continue;
        }

        long long u_n = graph[u].size();
        for (long long i = 0; i < u_n; ++i) {
            long long weight = graph[u][i].second;
            long long v = graph[u][i].first;
            if (distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                pq.push({distance[v], v});
            }
        }
    }
}

int
main()
{
    long long n, k, s, f;
    std::cin >> n >> k;
    std::vector<std::vector<std::pair<long long, long long> > > graph(n + 1);

    for (long long i = 0; i < k; ++i) {
        long long a, b, l;
        std::cin >> a >> b >> l;
        graph[a].push_back(std::make_pair(b, l));
        graph[b].push_back(std::make_pair(a, l));
    }

    std::cin >> s >> f;
    std::vector<long long> distance;
    dijkstra(graph, s, distance);

    if (distance[f] == INF) {
        std::cout << -1 << std::endl;
    } else {
        std::cout << distance[f] << std::endl;
    }

    return 0;
}