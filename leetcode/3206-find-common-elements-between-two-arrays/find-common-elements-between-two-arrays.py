class Solution:
    def findIntersectionValues(self, nums1: List[int], nums2: List[int]) -> List[int]:
        a = {}
        b = {}
        ans = [0,0]


        for i in nums1:
            if i in a :
                a[i] += 1
            else :
                a[i] = 1

        for j in nums2:
            if j in b :
                b[j] += 1
            else :
                b[j] = 1
        
        for element in a :
            
            if  element in b :

                ans[0] += a[element]

                ans[1] += b[element]

        
        return ans

            

