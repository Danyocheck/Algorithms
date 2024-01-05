#include <iostream>
#include <vector>
#include <map>

class Solution {
public:
    bool is_visited(std::vector<std::pair<int, int> > &visited, int num) {
        for (auto i: visited) {
            if (num == i.first) return true;
        }
        return false;
    }

    bool is_find(std::vector<std::pair<int, int> > &visited, int num1, int num2) {
        for (auto i: visited) {
            if ((num1 == i.first && num2 == i.second)
                || (num2 == i.first && num1 == i.second)
            ) return true;
        }
        return false;
    }

    std::vector<std::vector<int> > threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int> > answer {};
        std::vector<std::pair<int, int> > visited;
        for (int i = 0; i < nums.size() - 2; ++i) {
            if (is_visited(visited, nums[i])) {
                continue;
            }
            int target = -nums[i];
            std::map<int, int> dict;
            for (int j = i + 1; j < nums.size(); ++j) {
                if (dict.find(nums[j]) != dict.end()) {
                    if (is_find(visited, nums[j], dict[nums[j]])
                        || is_find(visited, nums[i], nums[j])
                        || is_find(visited, nums[i], dict[nums[j]])
                    ) {
                        continue;
                    }
                    std::cout << -target << " " << nums[j] << " " << dict[nums[j]] << std::endl;
                    answer.push_back({-target, dict[nums[j]], nums[j]});
                    visited.push_back(std::make_pair(nums[i], nums[j]));
                    dict[nums[j]] = 0;
                } else {
                    dict[target - nums[j]] = nums[j];
                }
            }
        }
        return answer;
    }
};

int
main()
{
    Solution A;
    int arr[] = {-2,0,0,2,2}; 
    int n = sizeof(arr) / sizeof(arr[0]);
    std::vector<int> vec(arr, arr + n);
    std::vector<std::vector<int> > answer = A.threeSum(vec);
}