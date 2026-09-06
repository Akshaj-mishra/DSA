class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:

        a = {}
        
        for i in range (len(nums)):
            need = target - nums[i]

            if need in a:
                return [a[need] , i]
            
            a[nums[i]] = i
           
                
    
        return []
