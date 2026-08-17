# 1386. Cinema Seat Allocation
from collections import defaultdict

"""
a cinema has 'n' rows of seats, numbered from 1 to 'n' and there
are ten seats in each row, labelled from 1 to 10 as shown in
the figure above. given the array 'reservedSeats' containing
the number of seats already reserved, for example 'reservedSeats[i]
= [3,8]' means the seat located in row 3 and labelled with 8
is already reserved. return the maximum number of four-person
groups you can assign on the cinema seats. a four-person group
occupies four adjacent seats in one single row. seats across
an aisle are not considered to be adjacent, but there is an
exceptional case on which an aisle split a four-person group
in that case the aisle split a four-person group in the middle
which means to have two people on each side.
"""


class Solution:
    def maxNumberOfFamilies(self, n: int, reservedSeats: List[List[int]]) -> int:
        reserved_map, ans = defaultdict(set), 0
        for i, j in reservedSeats:
            reserved_map[i].add(j)
        for i in reserved_map:
            blocked = reserved_map[i]
            left = all(seat not in blocked for seat in [2, 3, 4, 5])
            right = all(seat not in blocked for seat in [6, 7, 8, 9])
            middle = all(seat not in blocked for seat in [4, 5, 6, 7])
            if left and right:
                ans += 2
            elif left or right or middle:
                ans += 1
        ans += 2 * (n - len(reserved_map))
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.maxNumberOfFamilies(
            n=3, reservedSeats=[[1, 2], [1, 3], [1, 8], [2, 6], [3, 1], [3, 10]]
        )
    )
    print(obj.maxNumberOfFamilies(n=2, reservedSeats=[[2, 1], [1, 8], [2, 6]]))
    print(obj.maxNumberOfFamilies(n=4, reservedSeats=[[4, 3], [1, 4], [4, 6], [1, 7]]))
