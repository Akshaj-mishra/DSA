class Solution:
    def minimumSumSubarray(self, nums: List[int], l: int, r: int) -> int:
                
        n = len(nums)
        prefix = [0] * (n + 1)

        for i in range(n):
            prefix[i + 1] = prefix[i] + nums[i]

        min_sum = float('inf')

        for i in range(n):
            for size in range(l, r + 1):

                end = i + size

                if end > n:
                    break
                    
                total = prefix[end] - prefix[i]

                if total > 0:
                    min_sum = min(min_sum, total)

        if min_sum == float('inf'):
            return -1

        return min_sum