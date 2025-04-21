# 2145. Count the Hidden Sequences
from itertools import accumulate

"""
you are given a 0-indexed array of 'n' integers 'differences', which
describes the differences between each pair of consecutive integers of a
hidden sequence of length '(n + 1)'. you are further given two integers
'lower' and 'upper' that describe the inclusive range of values '[lower,
upper]' that the hidden sequence can contain. return the number of possible
hidden sequences there are. if there are no possible sequences, return 0.
"""


class Solution(object):
    def numberOfcntrrays(self, differences, lower, upper):
        """
        :type differences: List[int]
        :type lower: int
        :type upper: int
        :rtype: int
        """
        cnt = list(accumulate(differences, initial=0))
        return max(0, (upper - lower) - (max(cnt) - min(cnt)) + 1)


if __name__ == "__main__":
    obj = Solution()
    print(obj.numberOfcntrrays(differences=[1, -3, 4], lower=1, upper=6))
    print(obj.numberOfcntrrays(differences=[3, -4, 5, 1, -2], lower=-4, upper=5))
    print(obj.numberOfcntrrays(differences=[4, -7, 2], lower=3, upper=6))
