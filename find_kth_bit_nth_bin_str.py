# 1545. Find Kth Bit in Nth Binary String

"""
given two positive integers 'n' and 'k', the binary string 's_n' is formed as
follows: 's_1 = 0', 's_i = s_i - 1 + "1" + reverse(invert(s_i - 1))' for 'i >
1'. where '+' denotes the concatenation operation, 'reverse(x)' returns the
reversed string 'x', and 'invert(x)' inverts all teh bits in 'x'. return the
k'th bit in 's_n'. it is guaranteed that 'k' is valid for the given 'n'.
"""


class Solution(object):
    def findKthBit(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: str
        """
        flip = 0
        inv = 2**n - 1
        while k > 1:
            if k == inv / 2 + 1:
                return str(1 ^ flip)
            if k > inv / 2:
                k = inv + 1 - k
                flip = 1 - flip
            inv /= 2
        return str(flip)


if __name__ == "__main__":
    obj = Solution()
    print(obj.findKthBit(3, 1))
    print(obj.findKthBit(4, 11))
