class Solution:
    def subsetsWithDup(self, nums: list[int]) -> list[list[int]]:

        nums.sort()

        result = []
        ans = []

        def back(i):
            if i == len(nums):
                result.append(ans.copy())
                return

           
            ans.append(nums[i])
            back(i + 1)

            ans.pop()

            j = i+1
            while  j < len(nums) and nums[j] == nums[j-1]:
                j += 1
            
            back(j)

        
        back(0)
        return result