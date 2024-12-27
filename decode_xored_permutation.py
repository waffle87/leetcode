# 1734. Decode XORed Permutation
from operator import ixor
from functools import reduce
from itertools import accumulate

"""
there is a positive integer array 'perm' that is a permutation of the first
'n' positive integers, where 'n' is always odd. it was encoded into another
integer array 'encoded' of length 'n - 1', such that 'encoded[i] = perm[i] ^
perm[i + 1]'. given the 'encoded' array, return the original array 'perm'. it
is guaranteed that the answer exists and is unique
"""


class Solution(object):
    def decode(self, encoded):
        """
        :type encoded: List[int]
        :rtype: List[int]
        """
        first = reduce(ixor, encoded[::-2] + list(range(len(encoded) + 2)))
        return list(accumulate([first] + encoded, ixor))


if __name__ == "__main__":
    obj = Solution()
    print(obj.decode(encoded=[3, 1]))
    print(obj.decode(encoded=[6, 5, 4, 6]))
