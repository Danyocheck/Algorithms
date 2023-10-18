#include <iostream>
#include <vector>

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            if (nums[left] == target) return left;
            if (nums[right] == target) return right;
            int mid = (left + right) / 2;
            int mid_num = nums[mid];
            if (mid_num == target) return mid;
            if (mid_num > nums[right]) {
                if (mid_num > target && target > nums[left]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                if (mid_num < target && target < nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};

int
main()
{
    Solution A;
    int arr[] = {4};
    int n = sizeof(arr) / sizeof(arr[0]);
    std::vector<int> vec(arr, arr + n);
    std::cout << A.search(vec, 4) << std::endl;
}