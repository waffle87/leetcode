# 2220. Minimum Bit Flips to Convert Number

"""
a bit flip of a number 'x' is choosing a bit in the binary representation of
'x' and flipping it from either 0 to 1 or 1 to 0. given two integers 'start'
and 'goal', return the minimum number of bit flips to convert 'start' to
'goal'.
"""


class Solution(object):
    def minBitFlips(self, start, goal):
        """
        :type start: int
        :type goal: int
        :rtype: int
        """
        return (start ^ goal).bit_count()


if __name__ == "__main__":
    obj = Solution()
    print(obj.minBitFlips(10, 7))
    print(obj.minBitFlips(3, 4))
