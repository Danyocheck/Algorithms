#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <iomanip>

double distance(int x1, int y1, int x2, int y2) {
    return std::sqrt(std::pow(x1 - x2, 2) + std::pow(y1 - y2, 2));
}

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::pair<int, int>> children(n);
    for (int i = 0; i < n; ++i) {
        int x, y;
        std::cin >> x >> y;
        children[i] = std::make_pair(x, y);
    }

    std::vector<std::vector<int>> distribution_points(m, std::vector<int>(3));
    for (int i = 0; i < m; ++i) {
        int X, Y, a;
        std::cin >> X >> Y >> a;
        distribution_points[i] = {X, Y, a};
    }

    const double MAX_VAL = std::numeric_limits<double>::max();
    std::vector<std::vector<double>> M(m, std::vector<double>(n, 0.0));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            M[i][j] = distance(children[j].first, children[j].second, distribution_points[i][0], distribution_points[i][1]);
        }
    }

    double result = 0.0;

    for (int k = 0; k < n; ++k) {
        int d_pos = -1, c_pos = -1;
        double min_dist = MAX_VAL;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (M[i][j] < min_dist) {
                    min_dist = M[i][j];
                    d_pos = i;
                    c_pos = j;
                }
            }
        }

        result += min_dist;
        for (int i = 0; i < m; ++i) {
            M[i][c_pos] = MAX_VAL;
        }
        distribution_points[d_pos][2]--;
        if (distribution_points[d_pos][2] == 0) {
            for (int j = 0; j < n; ++j) {
                M[d_pos][j] = MAX_VAL;
            }
        }
    }

    std::cout << std::fixed << std::setprecision(8) << result << std::endl;

    return 0;
}
