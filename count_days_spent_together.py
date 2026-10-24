# 2409. Count Days Spent Together

"""
alice and bob are traveling to rome for separate business meetings. you are
given 4 strings. alice will be in the city from the dates 'arriveAlice' to
'leaveAlice' (inclusive), and similarly such for bob. each will be a
5-character string in the format "MM-DD", corresponding to the month and day
of date. return the total number o days that alice and bob are in rome
together. you can assume all date occur in the same calendar year, which is
not a leap year.
"""

from itertools import accumulate


class Solution:
    def countDaysTogether(
        self, arriveAlice: str, leaveAlice: str, arriveBob: str, leaveBob: str
    ) -> int:
        before = [
            0,
            *accumulate([31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30]),
        ]
        day = lambda mmdd: before[int(mmdd[:2]) - 1] + int(mmdd[3:])
        return max(
            0, day(min(leaveAlice, leaveBob)) - day(max(arriveAlice, arriveBob)) + 1
        )


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.countDaysTogether(
            arriveAlice="08-15", leaveAlice="08-18", arriveBob="08-16", leaveBob="08-19"
        )
    )
    print(
        obj.countDaysTogether(
            arriveAlice="10-01", leaveAlice="10-31", arriveBob="11-01", leaveBob="12-31"
        )
    )
