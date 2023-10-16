#include <iostream>
#include <algorithm>
#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int min = prices[0], max_profit = 0;
        for (int i = 1; i < prices.size(); ++i) {
            min = std::min(min, prices[i]);
            max_profit = std::max(max_profit, prices[i] - min);
        }
        return max_profit;
    }
};

int
main()
{
    Solution A;
    int arr[] = {2, 5, 1, 3}; 
    int n = sizeof(arr) / sizeof(arr[0]);
    std::vector<int> vec(arr, arr + n);
    std::cout << A.maxProfit(vec) << std::endl;
}