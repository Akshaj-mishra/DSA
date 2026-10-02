class Solution:
    def rearrangeArray(self, nums: list[int]) -> list[int]:
        a = [0] * len(nums)

        pos = 0
        neg = 1

        for i in range (len(nums)):
            if (nums[i] > 0):
                a[pos] = nums[i]
                pos += 2
            if (nums[i] < 0):
                a[neg] =  nums[i]
                neg += 2

        return a