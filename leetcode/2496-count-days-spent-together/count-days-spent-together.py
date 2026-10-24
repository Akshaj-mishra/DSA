
class Solution:
    def countDaysTogether(self, arriveAlice: str, leaveAlice: str,
                          arriveBob: str, leaveBob: str) -> int:

        months = [31, 28, 31, 30, 31, 30,
                  31, 31, 30, 31, 30, 31]

        def convert(date):
            month = int(date[:2])
            day = int(date[3:])

            return sum(months[:month - 1]) + day

        a1 = convert(arriveAlice)
        a2 = convert(leaveAlice)
        b1 = convert(arriveBob)
        b2 = convert(leaveBob)

        start = max(a1, b1)
        end = min(a2, b2)

        return max(0, end - start + 1)
