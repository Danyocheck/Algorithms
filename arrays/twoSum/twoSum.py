from typing import List

class Solution(object):
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        numsDict = {}
        for i in range(len(nums)):
            num = nums[i]
            sub = target - num
            if sub in numsDict:
                return [numsDict[sub], i]
            else:
                numsDict[num] = i


a = Solution()
print(a.twoSum(nums=[1, 2, 3, 4], target=6))