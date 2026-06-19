# 1732. Find the Highest Altitude
from itertools import accumulate
from typing import List

"""
there is a biker going on a road trip. the road trip consists of 'n + 1'
points at different altitudes. the biker starts his trip on point 0 with
altitude 0. given an integer array 'ain' of length 'n' where 'gain[i]' is the
net gain in altidude between points 'i' and 'i + 1' for all '0 <= i < n'.
return the highest altitude of a point
"""


class Solution:
    def largestAltitude(self, gain: List[int]) -> int:
        return max(0, max(accumulate(gain)))


if __name__ == "__main__":
    obj = Solution()
    print(obj.largestAltitude(gain=[-5, 1, 5, 0, -7]))
    print(obj.largestAltitude(gain=[-4, -3, -2, -1, 4, 3, 2]))
