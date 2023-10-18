from typing import List

class Solution(object):
    def search(self, nums: List[int], target: int) -> int:
        left = 0
        right = len(nums) - 1
        while left <= right:
            if nums[left] == target: return left
            if nums[right] == target: return right
            mid = (left + right) // 2
            mid_num = nums[mid]
            if mid_num == target: return mid
            if mid_num > nums[right]:
                if mid_num > target > nums[left]:
                    right = mid - 1
                else:
                    left = mid + 1
            else: 
                if mid_num < target < nums[right]:
                    left = mid + 1
                else:
                    right = mid - 1
            
        return -1


A = Solution()
print(A.search([4,5,6,7,0,1,2], 0))        