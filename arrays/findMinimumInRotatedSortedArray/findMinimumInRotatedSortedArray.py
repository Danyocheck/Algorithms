from typing import List

class Solution(object):
    def findMin(self, nums: List[int]) -> int:
        left = 0
        right = len(nums) - 1
        while (left < right):
            if nums[left] < nums[right]:
                return nums[left]
            mid = (left + right) // 2
            if nums[mid] < nums[right]:
                right = mid
            else:
                left = mid + 1
        return nums[left]


A = Solution()
print(A.findMin([2, 1]))