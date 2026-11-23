class Solution:
    def createGrid(self, m: int, n: int) -> list[str]:
        grid = []

        for i in range(m):
            row = ['#'] * n

            if i == m - 1:
                row = ['.'] * n
            else:
                row[0] = '.'

            grid.append(''.join(row))

        return grid