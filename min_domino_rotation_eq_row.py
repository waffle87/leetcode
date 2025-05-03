# 1007. Minimum Domino Rotations For Equal Row
from functools import reduce

"""
in a row of dominoes, 'tops[i]' and 'bottoms[i]' represents the top and
bottom halves of the i'th domino. we may rotate the i'th domino so that
'tops[i]' and 'bottoms[i]' swap values. return the minimum number of
rotations so that all values in 'tops' are the same, or all values in
'bottoms' are the same. if it cannot be done, return -1.
"""


class Solution(object):
    def minDominoRotations(self, tops, bottoms):
        """
        :type tops: List[int]
        :type bottoms: List[int]
        :rtype: int
        """
        s = reduce(set.__and__, (set(i) for i in zip(tops, bottoms)))
        if not s:
            return -1
        x = s.pop()
        return min(len(tops) - tops.count(x), len(bottoms) - bottoms.count(x))


if __name__ == "__main__":
    obj = Solution()
    print(obj.minDominoRotations(tops=[2, 1, 2, 4, 2, 2], bottoms=[5, 2, 6, 2, 3, 2]))
    print(obj.minDominoRotations(tops=[3, 5, 1, 2, 3], bottoms=[3, 6, 3, 3, 4]))
