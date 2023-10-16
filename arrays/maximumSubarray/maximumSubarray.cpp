#include <iostream>
#include <vector>

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        int max_sum = nums[0], curr_sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            curr_sum += nums[i];
            max_sum = std::max(max_sum, curr_sum);
            if (curr_sum < 0) {
                curr_sum = 0;
            }
        }

        return max_sum;
    }
};

int
main()
{
    Solution A;
    int arr[] = {-1}; 
    int n = sizeof(arr) / sizeof(arr[0]);
    std::vector<int> vec(arr, arr + n);
    std::cout << A.maxSubArray(vec) << std::endl;
}