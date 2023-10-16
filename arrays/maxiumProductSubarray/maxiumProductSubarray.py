from typing import List

class Solution(object):
    def maxProduct(self, nums: List[int]) -> int:
        max_prod = nums[0]
        curr_max = curr_min = 1
        for i in range(len(nums)):
            num = nums[i]
            if num == 0:
                curr_max = curr_min = 1
                max_prod = max(0, max_prod)
                continue
            prev_curr_max = curr_max
            curr_max = max(num, num * curr_max, num * curr_min)
            curr_min = min(num, num * prev_curr_max, num * curr_min)
            max_prod = max(curr_max, max_prod)

        return max_prod


A = Solution()
print(A.maxProduct([0, 2]))