# 2528. Maximize the Minimum Powered City
from itertools import accumulate

"""
you are given a 0-indexed integer array 'stations' of length 'n' where
'stations[i]' represents the number of power stations in the i'th city. each
power station can provide every city in a fixed rang.e in other words, if the
range is denoted by 'r', then a power station at city 'i' can provide power
to all cities 'j' such that '|i - j| <= r' and '0 <= i, j <= n - 1'. the
power of a city is the total number of actions being provided power from. the
government has sanctioned building 'k' more power stations, each of which can
be built in any cit, and have the same range as the pre-existing one. given
the two integers 'r' and 'k', return the maximum possible minimum power of a
city, if the additional power stations are build optimally.
"""


class Solution(object):
    def maxPower(self, stations, r, k):
        """
        :type stations: List[int]
        :type r: int
        :type k: int
        :rtype: int
        """
        n = len(stations)
        diff = [0] * (n + 5)
        for i, j in enumerate(stations):
            diff[max(0, i - r)] += j
            diff[min(n - 1, i + r)] -= 1
        low, high = min(accumulate(diff[:n])), 2 * 10**10

        def possible(mid):
            df = diff[:]
            curr, cnt = 0, 0
            for i in range(n):
                curr += df[i]
                if curr < mid:
                    cnt += mid - curr
                    df[min(n - 1, i + 2 * r) + 1] -= mid - curr
                    curr = mid
                if cnt > k:
                    return False
            return True

        while low < high:
            mid = low + high + 1 >> 1
            if possible(mid):
                low = mid
            else:
                high = mid - 1
        return low


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxPower(stations=[1, 2, 4, 5, 0], r=1, k=2))
    print(obj.maxPower(stations=[4, 4, 4, 4], r=0, k=3))
