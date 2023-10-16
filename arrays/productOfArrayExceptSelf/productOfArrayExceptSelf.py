from typing import List

class Solution(object):
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        formBegin = 1
        formLast = 1
        n = len(nums)
        res = [1] * n
        
        for i in range(n):
            res[i] *= formBegin
            res[n - i - 1] *= formLast
            formBegin *= nums[i]
            formLast *= nums[n - i - 1]

        return res