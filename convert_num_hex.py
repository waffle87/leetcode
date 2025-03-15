# 405. Convert a Number to Hexadecimal

"""
given a 32 bit integer 'num', return a string representing its hexadecimal
representation. for negative integers, two's complement method is used. all
the letters in the answer string should be lowercase characters, nd there not
be any leading zeros in the answer except for the zero itself. note: you are
not allowed to use any built-in library method to directly solve this
problem.
"""


class Solution(object):
    def toHex(self, num):
        """
        :type num: int
        :rtype: str
        """
        map, ans, num = "0123456789abcdef", "", num & 0xFFFFFFFF
        while num:
            ans += map[num % 16]
            num >>= 4
        return ans[::-1] or "0"


if __name__ == "__main__":
    obj = Solution()
    print(obj.toHex(num=26))
    print(obj.toHex(num=-1))
