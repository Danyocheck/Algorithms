#include <iostream>
#include <vector>

class Solution {
public:
    int maxProduct(std::vector<int>& nums) {
        int max_prod = nums[0], curr_max = 1, curr_min = 1;
        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            if (num == 0 && i + 1 < nums.size()) {
                curr_max = 1;
                curr_min = 1;
                max_prod = std::max(0, max_prod);
                continue;
            }
            int prev_curr_max = curr_max;
            curr_max = std::max(std::max(num * curr_min, num * curr_max), num);
            curr_min = std::min(std::min(num * curr_min, num * prev_curr_max), num);
            max_prod = std::max(curr_max, max_prod);
        }

        return max_prod;
    }
};

int
main()
{
    Solution A;
    int arr[] = {0, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    std::vector<int> vec(arr, arr + n);
    std::cout << A.maxProduct(vec) << std::endl;
}