class Solution:
    def combine(self, n: int, k: int) -> list[list[int]]:
        result = []
        ans = []

        def recur (i):
            if len(ans) == k :
                result.append(ans.copy())
                return
            
            for j in range (i , n+1):
                ans.append(j)
                recur(j+1)
                ans.pop()
            
        recur (1)

        return result