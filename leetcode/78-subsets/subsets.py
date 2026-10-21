class Solution:
    def subsets(self, nums: list[int]) -> list[list[int]]:
        
        result = []
        ans = []

        def back(i):
            if i == len(nums):
                result.append(ans.copy())
                return

           
            ans.append(nums[i])
            back(i + 1)


            ans.pop()
            back(i + 1)

        
        back(0)
        return result