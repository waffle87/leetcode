# 717. 1-bit and 2-bit Characters

"""
we have two special characters: the first character is represented by one bit
0, and the second character can be represented by two bits (10 or 11). given
a binary array 'bits' that ends with 0, return true if the last character
must be a one-bit character.
"""


class Solution(object):
    def isOneBitCharacter(self, bits):
        """
        :type bits: List[int]
        :rtype: bool
        """
        parity = bits.pop()
        while bits and bits.pop():
            parity ^= 1
        return parity == 0


if __name__ == "__main__":
    obj = Solution()
    print(obj.isOneBitCharacter(bits=[1, 0, 0]))
    print(obj.isOneBitCharacter(bits=[1, 1, 1, 0]))
