# 769. Max Chunks To Make Sorted
from itertools import accumulate

"""
you are given an integer array 'arr' of length 'n' that represents a
permutation of the integers in the range '[0, n - 1]'. we split 'arr' into
some number of chunks (ie. partitions), and individually sort each chunk.
after concatenating them, the result should equal the sorted array. return
the largest number of chunks we can make to sort the array.
"""


class Solution(object):
    def maxChunksToSorted(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        return sum(i == j for i, j in enumerate(accumulate(arr, max)))


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxChunksToSorted(arr=[4, 3, 2, 1, 0]))
    print(obj.maxChunksToSorted(arr=[1, 0, 2, 3, 4]))
