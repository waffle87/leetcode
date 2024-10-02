# 1331. Rank Transform of an Array

"""
given an array of integers 'arr', replace each element with its rank. the
rank reprsents how large the element is. the rank has the following rules.
rank is an integer starting from 1. the larger the element, the larger the
rank. if two elements are equal, their rank must be the same. rank should be
as small as possible.
"""


class Solution(object):
    def arrayRankTransform(self, arr):
        """
        :type arr: List[int]
        :rtype: List[int]
        """
        rank = {}
        for i in sorted(arr):
            rank.setdefault(i, len(rank) + 1)
        return map(rank.get, arr)


if __name__ == "__main__":
    obj = Solution()
    print(obj.arrayRankTransform(arr=[40, 10, 20, 30]))
    print(obj.arrayRankTransform(arr=[100, 100, 100]))
    print(obj.arrayRankTransform(arr=[37, 12, 28, 9, 100, 56, 80, 5, 12]))
