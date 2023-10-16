#include <iostream>
#include <vector>
#include <map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::map<int, int> numsDictionary;
        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            int sub = target - num;
            if (numsDictionary.find(sub) == numsDictionary.end()) {
                numsDictionary[num] = i;
            } else {
                std::vector<int> answer;
                answer.push_back(numsDictionary[sub]);
                answer.push_back(i);
                return answer;
            }
        }
        return nums;
    }
};

int
main()
{
    Solution A;
    int arr[] = {2, 7, 11, 17}; 
    int n = sizeof(arr) / sizeof(arr[0]);
    std::vector<int> vec(arr, arr + n);
    for (auto i : A.twoSum(vec, 9)) {
        std::cout << i << std::endl;
    }
}