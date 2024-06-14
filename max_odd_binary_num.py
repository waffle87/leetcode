# 2864. Maximum Odd Binary Number

"""
given a binary string 's' that contains at least one '1'. you have to
rearrange the bits in such a way that the resulting binary number is the
maximum odd binary number that can be created from this combination. return a
string representing the maximum odd binary number that can be created from
the given combination.
"""


class Solution(object):
    def maximumOddBinaryNumber(self, s):
        """
        :type s: str
        :rtype: str
        """
        c = sorted(s)
        for i in range(len(c) - 1, -1, -1):
            if c[i] == "1":
                c[i], c[-1] = c[-1], c[i]
                break
        return "".join(c)


if __name__ == "__main__":
    obj = Solution()
    print(obj.maximumOddBinaryNumber("010"))
    print(obj.maximumOddBinaryNumber("0101"))
