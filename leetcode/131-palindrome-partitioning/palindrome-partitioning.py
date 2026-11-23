class Solution:
    def partition(self, s: str) -> List[List[str]]:
        res = []
        
        def is_palindrome(sub: str) -> bool:
            return sub == sub[::-1]
        
        def backtrack(start: int, path: List[str]):
            if start == len(s):
                res.append(path[:])
                return
            
            for end in range(start + 1, len(s) + 1):
                sub = s[start:end]
                if is_palindrome(sub):
                    path.append(sub)
                    backtrack(end, path)
                    path.pop()  
                    
        backtrack(0, [])
        return res