class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        n, m = len(s1), len(s2)

        if n > m:
            return False

        need = [0] * 26
        window = [0] * 26

        for c in s1:
            need[ord(c) - ord('a')] += 1

        for c in s2[:n]:
            window[ord(c) - ord('a')] += 1

        def solve(start):
            if need == window:
                return True

            if start + n >= m:
                return False

            window[ord(s2[start]) - ord('a')] -= 1
            window[ord(s2[start + n]) - ord('a')] += 1

            return solve(start + 1)

        return solve(0)