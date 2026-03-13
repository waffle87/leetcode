# 3296. Minimum Number of Seconds to Make Mountain Height Zero
import heapq
from typing import List

"""
you are given an integer 'mountainHeight' denoting the height of a mountain.
you are also given an integer array 'workerTimes' representing the work time
of workers in seconds. the workers simultaneously work to reduce the height
of a mountain. return an integer representing the minimum number of seconds
required foor the workers to make the height of the mountain 0.
"""


class Solution:
    def minNumberOfSeconds(self, mountainHeight: int, workerTimes: List[int]) -> int:
        h = [(j, j, 1) for i, j in enumerate(workerTimes)]
        heapq.heapify(h)
        while mountainHeight > 1:
            ps, wt, x = heapq.heappop(h)
            heapq.heappush(h, (ps + wt * (x + 1), wt, x + 1))
            mountainHeight -= 1
        return heapq.heappop(h)[0]


if __name__ == "__main__":
    obj = Solution()
    print(obj.minNumberOfSeconds(mountainHeight=4, workerTimes=[2, 1, 1]))
    print(obj.minNumberOfSeconds(mountainHeight=10, workerTimes=[3, 2, 2, 4]))
    print(obj.minNumberOfSeconds(mountainHeight=5, workerTimes=[1]))
