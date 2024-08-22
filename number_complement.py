# 476. Number Complement

"""
the complement of an integer is the integer you get when you flip all the 0's
to 1's and all the 1's to 0's in its binary representation. for example, the
integer 5 is "101" in binary and its complement is "010", which is the
integer 2. given an integer 'num', return its complement
"""


class Solution(object):
    def findComplement(self, num):
        """
        :type num: int
        :rtype: int
        """
        i = 1
        while i <= num:
            i = i << 1
        return (i - 1) ^ num


if __name__ == "__main__":
    obj = Solution()
    print(obj.findComplement(5))
    print(obj.findComplement(1))
