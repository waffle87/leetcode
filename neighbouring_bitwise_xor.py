# 2683. Neighboring Bitwise XOR
from functools import reduce
from operator import xor

"""
a 0-indexed array 'derived' with length 'n' is derived by computing the
bitwise xor of adjacnet values in a binary array 'original' of length 'n'.
specifically, for each index 'i' in the range '[0, n - 1]' if 'i = n - 1'
then 'derived[i] = original[i] ^ original[0]', otherwise 'derived[i] =
original[i] ^ original[i + 1]'. given an array 'derived', your task is to
determine whether there exists a valid binary array 'original' that could
have formed 'derived'. return true if such an array exists or false
otherwise.
"""


class Solution(object):
    def doesValidArrayExist(self, derived):
        """
        :type derived: List[int]
        :rtype: bool
        """
        return not reduce(xor, derived)


if __name__ == "__main__":
    obj = Solution()
    print(obj.doesValidArrayExist(derived=[1, 1, 0]))
    print(obj.doesValidArrayExist(derived=[1, 1]))
    print(obj.doesValidArrayExist(derived=[1, 0]))
