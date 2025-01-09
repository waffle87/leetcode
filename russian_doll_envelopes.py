# 354. Russian Doll envelopesnvelopes
from bisect import bisect_left

"""
you are given a 2d array of integers 'envelopes' where 'envelopes[i] = [w_i,
h_i]' represents the width and height of an envelope. one envelope can fit
into another if and only if both the width and height of one envelope are
greater than the other envelope's width and height. return the maximum number
of envelopes you can russian doll (ie. put one inside the other).
"""


class Solution(object):
    def maxenvelopesnvelopes(self, envelopes):
        """
        :type envelopes: List[List[int]]
        :rtype: int
        """
        envelopes.sort(key=lambda x: (x[0], -x[1]))
        dp = []
        for _, height in envelopes:
            left = bisect_left(dp, height)
            if left == len(dp):
                dp.append(height)
            else:
                dp[left] = height
        return len(dp)


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxenvelopesnvelopes(envelopes=[[5, 4], [6, 4], [6, 7], [2, 3]]))
    print(obj.maxenvelopesnvelopes(envelopes=[[1, 1], [1, 1], [1, 1]]))
