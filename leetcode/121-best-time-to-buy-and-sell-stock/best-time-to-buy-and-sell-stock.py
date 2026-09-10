class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        m = float('inf')
        n = 0

        for p in prices:
            m = min(m,p)
            n = max(n, p - m)

        return n