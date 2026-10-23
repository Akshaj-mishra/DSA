class Solution:
    def countNumbersWithUniqueDigits(self, n: int) -> int:
        if n == 0:
            return 1

        total = 10
        current = 9
        available = 9

        for i in range(2, n + 1):
            current *= available
            total += current
            available -= 1

        return total