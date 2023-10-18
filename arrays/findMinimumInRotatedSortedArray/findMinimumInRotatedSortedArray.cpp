#include <iostream>
#include <vector>

class Solution {
public:
    int findMin(std::vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            if (nums[left] < nums[right]) {
                return nums[left];
            }
            int mid = (left + right) / 2;
            if (nums[mid] < nums[right]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return nums[left];
    }
};

int
main()
{
    Solution A;
    int arr[] = {2, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    std::vector<int> vec(arr, arr + n);
    std::cout << A.findMin(vec) << std::endl;
}