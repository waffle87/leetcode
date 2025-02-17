# 973. K Closest Points to Origin
import heapq
from math import sqrt

"""
given an array of 'points' where 'points[i] = [x_i, y_i]' represents a point
on the x-y plane and an integer 'k', return the 'k' closest points to the
origin '(0, 0)'. the distance between two points on the x-y plane is the
euclidean distance (ie. 'sqrt((x1 - x2)^2 + (y1 - y2)^2))'.  you may return
the answer in any order. the answer is guaranteed to be unique (except for
the order that it is in).
"""


class Node:
    def __init__(self, x, y):
        self.x = x
        self.y = y
        self.dist = sqrt(x**2 + y**2)

    def __lt__(self, other):
        return self.dist < other.dist


class Solution(object):
    def kClosest(self, points, k):
        """
        :type points: List[List[int]]
        :type k: int
        :rtype: List[List[int]]
        """
        min_heap, ans = [], []
        for x, y in points:
            node = Node(x, y)
            heapq.heappush(min_heap, node)
        for _ in range(k):
            top = heapq.heappop(min_heap)
            ans.append([top.x, top.y])
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.kClosest(points=[[1, 3], [-2, 2]], k=1))
    print(obj.kClosest(points=[[3, 3], [5, -1], [-2, 4]], k=2))
