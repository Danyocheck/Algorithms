#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int> > threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int> > answer;
        std::sort(nums.begin(), nums.end());

        if (nums.size() < 3) {
            return {};
        }
        if (nums[0] > 0) {
            return {};
        }
        int left = 0, right = nums.size() - 1;
        while (left < right && (nums[left] < 0 || nums[right] >= 0)) {
            if (nums[right] >= -nums[left]) {
                int target = -nums[right];
                std::map<int, int> dict;
                int i = left;
                while (nums[i] <= 0 && i < right) {
                    bool is_find = dict.find(nums[i]) != dict.end();
                    if (is_find && dict[nums[i]] != 1) {
                        std::cout << -target << " " << nums[i] << " " << dict[nums[i]] << std::endl;
                        int arr[] = {-target, nums[i], dict[nums[i]]}; 
                        int n = sizeof(arr) / sizeof(arr[0]);
                        std::vector<int> vec(arr, arr + n);
                        answer.push_back(vec);
                        dict[dict[nums[i]]] = 1;
                        dict[nums[i]] = 1;
                    } else if (!is_find) {
                        dict[target - nums[i]] = nums[i];
                    }
                    ++i;
                }
                while (left < right && nums[right] >= 0 && nums[right - 1] == nums[right]) {
                    --right;
                }
                --right;
            } else {
                int target = -nums[left];
                std::map<int, int> dict;
                int i = right;
                while (nums[i] >= 0 && i >= left) {
                    bool is_find = dict.find(nums[i]) != dict.end();
                    if (is_find && dict[nums[i]] != -1) {
                        std::cout << -target << " " << nums[i] << " " << dict[nums[i]] << std::endl;
                        int arr[] = {-target, nums[i], dict[nums[i]]}; 
                        int n = sizeof(arr) / sizeof(arr[0]);
                        std::vector<int> vec(arr, arr + n);
                        answer.push_back(vec);
                        dict[dict[nums[i]]] = -1;
                        dict[nums[i]] = -1;
                    } else if (!is_find) {
                        dict[target - nums[i]] = nums[i];
                    }
                    --i;
                }
                while (nums[left] <= 0 && nums[left + 1] == nums[left]) {
                    ++left;
                }
                ++left;
            }
        }

        return answer;
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