# 89. Gray Code

"""
an n-bit gray code sequence is a sequence of '2^n' integers where every
integer is in the inclusive range '[0, 2^n - 1]', the first integer is 0, an
integer appears no more than once in the sequence, the binary representation
of every pair of adjacent integers differs by exactly one bit and the binary
representation of the first and last integers differs by exactly one bit.
given an integer 'n', return any valid n-bit gray code sequence
"""


class Solution(object):
    def grayCode(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        ans = [0]
        for i in range(n):
            ans += [j + pow(2, i) for j in reversed(ans)]
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.grayCode(n=2))
    print(obj.grayCode(n=1))
