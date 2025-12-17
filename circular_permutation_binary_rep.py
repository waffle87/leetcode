# 1238. Circular Permutation in Binary Representation

"""
given 2 integers 'n' and 'start', your task is to return any permutation of
'(0, 1, 2, ..., 2^n - 1)' such that 'p[0] = start', 'p[i]' and 'p[i + 1]'
differ by only one bit in their binary representation, and 'p[0]' and '[p2^n
- 1]' must also differ by oly one bit in their binary repesentation.
"""


class Solution(object):
    def circularPermutation(self, n, start):
        """
        :type n: int
        :type start: int
        :rtype: List[int]
        """
        return [start ^ i ^ i >> 1 for i in range(1 << n)]


if __name__ == "__main__":
    obj = Solution()
    print(obj.circularPermutation(n=2, start=3))
    print(obj.circularPermutation(n=3, start=2))
