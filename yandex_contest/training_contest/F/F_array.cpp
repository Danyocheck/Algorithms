#include <iostream>
#include <vector>

int
main()
{
    unsigned long long max, floors_num, seconds = 0;
    std::cin >> max >> floors_num;
    long long remains = max;
    std::vector<long long> floors(floors_num, 0);
    for (long long i = 0; i < floors_num; ++i) {
        long long num_of_people;
        std::cin >> num_of_people;
        floors[i] = num_of_people;
    }

    for (long long i = floors_num; i > 0; --i) {
        while (i > 0 && floors[i - 1] == 0) {
            --i;
        }
        if (i <= 0) {
            break;
        }
        if (floors[i - 1] > remains) {
            if (remains == max) {
                if (floors[i - 1] % max == 0) {
                    seconds += (floors[i - 1] / max) * 2 * i;
                } else {
                    seconds += (floors[i - 1] / max + 1) * 2 * i;
                    remains -= floors[i - 1] % max;
                }
            } else {
                floors[i - 1] -= remains;
                remains = max;
                ++i;
            }
        } else if (remains > floors[i - 1]) {
            if (remains == max) {
                seconds += 2 * i;
            }
            remains -= floors[i - 1];
        } else {
            if (remains == max) {
                seconds += 2 * i;
            } else {
                remains = max;
            }
        }
    }

    std::cout << seconds << std::endl;
    return 0;
}