from typing import List

class Solution(object):
    def maxProfit(self, prices: List[int]) -> int:
        min_price = prices[0]
        max_profit = 0
        for i in range(len(prices)):
            if (min_price > prices[i]):
                min_price = prices[i]
            if (max_profit < prices[i] - min_price):
                max_profit = prices[i] - min_price
        return max_profit


a = Solution()
print(a.maxProfit([1, 4, 2, 3]))