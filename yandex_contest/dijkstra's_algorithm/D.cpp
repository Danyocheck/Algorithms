#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <map>

const long long INF = std::numeric_limits<long long>::max();

struct Bus {
    int departureTime;
    int destinationVillage;
    int arrivalTime;

    Bus(int depT, int destV, int arrT)
        : departureTime(depT), destinationVillage(destV), arrivalTime(arrT) {}
};

void dijkstra(const std::vector<std::vector<Bus> >& graph, long long start, std::vector<long long>& distance) {
    int n = graph.size();
    distance.assign(n + 1, INF);
    distance[start] = 0;

    std::priority_queue<std::pair<long long, long long>, std::vector<std::pair<long long, long long> >, std::greater<std::pair<long long, long long> > > pq;
    pq.push({0, start});

    while (!pq.empty()) {
        long long u = pq.top().second;
        long long dist_u = pq.top().first;
        pq.pop();

        for (auto bus: graph[u]) {
            if (bus.departureTime < distance[u]) {
                continue;
            }
            long long weight = bus.arrivalTime;
            long long v = bus.destinationVillage;
            if (weight < distance[v]) {
                distance[v] = weight;
                pq.push({distance[v], v});
            }
        }
    }
}

int
main()
{
    long long n, d, v, r;
    std::cin >> n >> d >> v >> r;
    std::vector<std::vector<Bus> > graph(n + 1);

    for (long long i = 0; i < r; ++i) {
        long long a, ts, b, tf;
        std::cin >> a >> ts >> b >> tf;
        graph[a].push_back(Bus(ts, b, tf));
    }

    std::vector<long long> distance;
    dijkstra(graph, d, distance);

    if (distance[v] == INF) {
        std::cout << -1 << std::endl;
    } else {
        std::cout << distance[v] << std::endl;
    }

    return 0;
}