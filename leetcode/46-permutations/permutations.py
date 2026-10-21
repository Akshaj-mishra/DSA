class Solution:
    def permute(self, nums: list[int]) -> list[list[int]]:
            result = []

            def recurr( idx):
                if idx == len(nums):
                    result.append(nums.copy())
                    return 
                
                for i in range(idx , len(nums)):
                    nums[idx] , nums[i] = nums[i] , nums[idx]
                    recurr(idx + 1)
                    nums[i] , nums[idx] = nums[idx] , nums[i]
            
            recurr(0)

            return result
