
class Solution:
    def beautifulSubsets(self, nums: List[int], k: int) -> int:

        ans = []
        count = 0

        def back(i):
            nonlocal count

            if i == len(nums):
                if ans:
                    count += 1
                return

            valid = True
            for x in ans:
                if abs(x - nums[i]) == k:
                    valid = False
                    break

            if valid:
                ans.append(nums[i])
                back(i + 1)
                ans.pop()


            back(i + 1)

        back(0)
        return count
