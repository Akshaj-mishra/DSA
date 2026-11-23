class Solution:
    def combinationSum(self, candidates: list[int], target: int) -> list[list[int]]:
        
        result = []
        comb = []

        def recur (idx , target):
            if target == 0:
                result.append(comb.copy())
                return 

            if idx >= len(candidates) or target < 0:
                return 
            
            comb.append(candidates[idx])
            recur (idx , target -  candidates[idx] )
            comb.pop()
            recur (idx + 1, target)

        recur (0 , target)
        return result