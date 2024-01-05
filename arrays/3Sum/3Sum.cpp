#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        if (nums.size() < 3) {
            return {};
        }

        std::vector<std::vector<int>> solutions;

        std::sort(nums.begin(), nums.end());
        for (size_t i = 0; i + 2 < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            } else if (nums[i] + nums[i + 1] + nums[i + 2] > 0) {
                break;
            } else if (nums[i] + nums[nums.size() - 1] + nums[nums.size() - 2] < 0) {
                continue;
            }

            size_t l = i + 1, r = nums.size() - 1;
            
            while (l < r && r < nums.size()) {
                auto sum = (long) nums[i] + nums[l] + nums[r];

                if (sum == 0) {
                    solutions.push_back({
                        nums[i], nums[l], nums[r]
                    });

                    do {
                        l++;
                    } while (l < r && nums[l] == nums[l - 1]);

                    do {
                        r--;
                    } while (l < r && nums[r] == nums[r + 1]);
                } else if (sum < 0) {
                    l++;
                } else {
                    r--;
                }
            }
        }
        return solutions;
    }
};

int
main()
{
    Solution A;
    int arr[] = {0,0,0}; 
    int n = sizeof(arr) / sizeof(arr[0]);
    std::vector<int> vec(arr, arr + n);
    A.threeSum(vec);
}