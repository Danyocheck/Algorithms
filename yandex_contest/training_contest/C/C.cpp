#include <iostream>
#include <iomanip>
#include <cmath>

bool is_circle(double x1, double y1, double x2, double y2) {
    if ((x1 * x1 + y1 * y1) == (x2 * x2 + y2 * y2)) {
        return true;
    } else {
        return false;
    }
}

bool is_straight(double x1, double y1, double x2, double y2) {
    if ((x1 == 0 && x2 != 0) || (x1 != 0 && x2 == 0)
        || (y1 == 0 && y2 != 0) || (y1 != 0 && y2 == 0)
    ) {
        return false;
    } else if ((x1 == 0 && x2 == 0) || (y1 == 0 && y2 == 0)
        || (x1 == 0 && y1 == 0) || (x2 == 0 && y2 == 0)
    ) {
        return true;
    }
    double k1 = y1 / x1, k2 = y2 / x2;
    if (k1 == k2) {
        return true;
    } else {
        return false;
    }
}

double find_angle(double x1, double y1, double x2, double y2) {
    return abs(atan2(y2, x2) - atan2(y1, x1));
}

double find_alpha(double x1, double y1, double x2, double y2, double r) {
    double k, alpha;
    if (x2 == 0) {
        if (y2 < 0) alpha = find_angle(x1, y1, 0, -r);
        else alpha = find_angle(x1, y1, 0, r);
    } else {
        k = y2 / x2;
        double intersection_x, intersection_y;
        if (x2 < 0) {
            intersection_x = - r / sqrt(1 + k * k);
        } else {
            intersection_x = r / sqrt(1 + k * k);
        }
        intersection_y = k * intersection_x;
        alpha = find_angle(x1, y1, intersection_x, intersection_y);
    }

    return alpha;
}

int
main()
{
    double x1, y1, x2, y2, answer;
    std::cin >> x1 >> y1 >> x2 >> y2;
    if (is_straight(x1, y1, x2, y2)) {
        double sub_x = x1 - x2;
        double sub_y = y1 - y2;
        std::cout << std::fixed << std::setprecision(12) << sqrt(sub_x * sub_x + sub_y * sub_y) << std::endl;
    } else if (is_circle(x1, y1, x2, y2)) {
        double r = sqrt(x1 * x1 + y1 * y1);
        double angle = find_angle(x1, y1, x2, y2);
        if (angle < 2) {
            answer = angle * r;
            std::cout << std::fixed << std::setprecision(12) << answer << std::endl;
        } else {
            answer = 2 * r;
            std::cout << std::fixed << std::setprecision(12) << answer << std::endl;
        }
    } else {
        double r1 = sqrt(x1 * x1 + y1 * y1);
        double r2 = sqrt(x2 * x2 + y2 * y2);
        if (r1 < r2) {
            double alpha = find_alpha(x1, y1, x2, y2, r1);
            if (alpha < 2) {
                answer = alpha * r1 + r2 - r1;
                std::cout << std::fixed << std::setprecision(12) << answer << std::endl;
            } else {
                std::cout << std::fixed << std::setprecision(12) << r1 + r2 << std::endl;
            }
        } else {
            double alpha = find_alpha(x2, y2, x1, y1, r2);
            double ans = alpha * r2;
            if (alpha < 2) {
                std::cout << std::fixed << std::setprecision(12) << alpha * r2 + r1 - r2 << std::endl;
            } else {
                std::cout << std::fixed << std::setprecision(12) << r1 + r2 << std::endl;
            }
        }
    }

    return 0;
}