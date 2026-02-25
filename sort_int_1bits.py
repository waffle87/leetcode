# 1356. Sort Integers by The Number of 1 Bits
from typing import List

"""
given an integer array 'arr', sort the integers in the array in ascending
order by the number of 1's in their binary representation and in case of two
or more integers have the same number of 1's, you have to sort them in
ascending order. return the array after sorting it.
"""


class Solution:
    def sortByBits(self, arr: List[int]) -> List[int]:
        def weight(n):
            w = 0
            while n:
                w += 1
                n &= n - 1
            return w

        arr.sort(key=lambda x: (weight(x), x))
        return arr


if __name__ == "__main__":
    obj = Solution()
    print(obj.sortByBits([0, 1, 2, 3, 4, 5, 6, 7, 8]))
    print(obj.sortByBits([1024, 512, 256, 128, 64, 32, 16, 8, 4, 2, 1]))
