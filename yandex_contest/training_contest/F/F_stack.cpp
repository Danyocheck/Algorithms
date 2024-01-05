#include <iostream>
#include <stack>

int
main()
{
    int max, floors_num, seconds = 0;
    std::cin >> max >> floors_num;
    std::stack<std::pair<int, int> > floors;
    for (int i = 1; i <= floors_num; ++i) {
        int num_of_people;
        std::cin >> num_of_people;
        if (num_of_people != 0) {
            floors.push(std::make_pair(i, num_of_people));
        }
    }

    while (!floors.empty()) {
        if (floors.top().second - max > 0) {
            seconds += 2 * floors.top().first;
            floors.top().second -= max;
        } else if (floors.top().second - max == 0) {
            seconds += 2 * floors.top().first;
            floors.pop();
        } else {
            int remains = max;
            seconds += 2 * floors.top().first;
            while (!floors.empty() && remains - floors.top().second >= 0) {
                remains -= floors.top().second;
                floors.pop();
            }
            if (remains != 0 && !floors.empty()) {
                floors.top().second -= remains;
            }
        }
    }

    std::cout << seconds << std::endl;
    return 0;
}