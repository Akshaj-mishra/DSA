class Solution:
    def exist(self, board: list[list[str]], word: str) -> bool:
        row = len(board)
        col = len(board[0])
        sets = set()

        def recur(r , c , i):
            if i == len(word):
                return True
            
            if r < 0 or c < 0 or r >= row or c >= col or word[i] != board[r][c] or (r,c) in sets :
                return False

            sets.add((r,c))

            res =  (recur(r+1 , c , i+1) or 
                    recur(r-1 , c , i+1) or 
                    recur(r , c+1 , i+1) or 
                    recur(r , c-1 , i+1))
            
            sets.remove((r,c))

            return res

        for a in range (row):
            for b in range (col):
                if recur (a,b,0):
                    return True

        return False
        