# 3464. Maximize the Distance Between Points on a Square
from bisect import bisect_left
from typing import List

"""
you are given an integer 'side', representing the edge length of a square
with corners at '(0, 0)', '(0, side)', '(side, 0)', and '(side, side)' on a
cartesian plane. you are also given a positive integer 'k' and a 2d integer
array 'points' where 'points[i] = [x_i, y_i]' represents the coordinate of a
point lying on the boundary of the square. you need to select 'k' elements
among 'points' such that the minimum manhattan distance between any two
points in maximised.
"""


class Solution:
    def maxDistance(self, side: int, points: List[List[int]], k: int) -> int:
        def flatten(p):
            x, y = p
            if y == 0:
                return x
            if x == side:
                return side + y
            if y == side:
                return 3 * side - x
            if x == 0:
                return 4 * side - y

        def can_place(min_dist):
            for i, num in enumerate(arr):
                ptr, cnt = i, 1
                while cnt < k:
                    j = bisect_left(arr, arr[ptr] + min_dist)
                    if j == len(points):
                        break
                    ptr = j
                    cnt += 1
                    if min_dist + arr[ptr] > num + 4 * side:
                        cnt = 0
                        break
                if cnt == k:
                    return False
            return True

        arr = sorted(map(flatten, points))
        first_invalid = bisect_left(range(0, side + 1), True, key=can_place)
        return first_invalid - 1


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxDistance(side=2, points=[[0, 2], [2, 0], [2, 2], [0, 0]], k=4))
    print(obj.maxDistance(side=2, points=[[0, 0], [1, 2], [2, 0], [2, 2], [2, 1]], k=4))
    print(
        obj.maxDistance(
            side=2, points=[[0, 0], [0, 1], [0, 2], [1, 2], [2, 0], [2, 2], [2, 1]], k=5
        )
    )
