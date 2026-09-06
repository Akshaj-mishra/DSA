class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        
        a = len (matrix[0])
        b = len (matrix)

        l = 0
        r = a*b -1

        while l<=r :

            mid = (l+r) // 2

            i = mid // a
            j = mid % a

            if matrix[i][j] == target:
                return True

            if matrix[i][j] > target:
                r = mid -1 

            else :
                l = mid + 1


        return False