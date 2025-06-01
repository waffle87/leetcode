# 2929. Distribute Candies Among Children II
from math import comb

"""
you are given two positive integers 'n' and 'limit'. return the total number
of ways to distritube 'n' candies among 3 children such that no child gets
more than 'limit' candies.
"""


class Solution(object):
    def distributeCandies(self, n, limit):
        """
        :type n: int
        :type limit: int
        :rtype: int
        """
        ans = (n + 2) * (n + 1) // 2
        for i in range(1, 4):
            if n - i * (limit + 1) < 0:
                break
            ans += (
                (-1) ** i
                * comb(3, i)
                * (n - i * (limit + 1) + 2)
                * (n - i * (limit + 1) + 1)
                // 2
            )
            return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.distributeCandies(n=5, limit=2))
    print(obj.distributeCandies(n=3, limit=3))
