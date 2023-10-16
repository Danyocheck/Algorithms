#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        int formBegin = 1;
        int formLast = 1;
        int n = nums.size();
        std::vector<int> res(n, 1);

        for (int i = 0; i < n; ++i) {
            res[i] *= formBegin;
            res[n - i - 1] *= formLast;
            formBegin *= nums[i];
            formLast *= nums[n - i - 1];
        }

        return res;
    }
};

int
main()
{
    Solution A;
    int arr[] = {2, 5, 1, 3}; 
    int n = sizeof(arr) / sizeof(arr[0]);
    std::vector<int> vec(arr, arr + n);
    std::vector<int> res = A.productExceptSelf(vec);
    for (int i = 0; i < res.size(); ++i) {
        std::cout << res[i] << " ";
    }
    std::cout << std::endl;
}