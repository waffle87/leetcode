# 1642. Furthest Building You Can Reach
import heapq

"""
given an integer array 'heights' representing the heights of buildings, some
'bricks' and some 'ladders'. you start your journey from building 0 and move
to the next building by possibly using bricks or ladders. while moving from
building 'i' to building 'i + 1' (0-indexed):
- if the current building's height is greater than or equal to the height of
next building, you do not need a ladder or bricks
- if the current building's height is less than the next building's height,
you can either use one ladder or '(h[i + 1] - h[i])' bricks return the
furthest building index (0-indexed) you can reach if you use the given
ladders and bricks optimally
"""


class Solution(object):
    def furthestBuilding(self, heights, bricks, ladders):
        heap = []
        for i in range(len(heights) - 1):
            d = heights[i + 1] - heights[i]
            if d > 0:
                heapq.heappush(heap, d)
            if len(heap) > ladders:
                bricks -= heapq.heappop(heap)
            if bricks < 0:
                return i
        return len(heights) - 1


if __name__ == "__main__":
    obj = Solution()
    print(obj.furthestBuilding([4, 2, 7, 6, 9, 14, 12], 5, 1))  # expect: 4
    print(obj.furthestBuilding([4, 12, 2, 7, 3, 18, 20, 3, 19], 10, 2))  # expect: 7
    print(obj.furthestBuilding([14, 3, 19, 3], 17, 0))  # expect: 3
