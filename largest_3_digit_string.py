# 2264. Largest 3-Same-Digit Number in String

"""
given a string 'num' representing a large integer, an integer is good if it
meets the following conditions: if it is a substring of 'num' with length
'3', it consists of only one unique digit. return the maximum good integer as
a string or an empty string "" if no such integer.
"""


class Solution(object):
    def largestGoodInteger(self, num):
        """
        :type num: str
        :rtype: str
        """
        patterns = [
            "999",
            "888",
            "777",
            "666",
            "555",
            "444",
            "333",
            "222",
            "111",
            "000",
        ]
        for i in patterns:
            if i in num:
                return i
        return ""


if __name__ == "__main__":
    obj = Solution()
    print(obj.largestGoodInteger("6777133339"))  # expect: 777
    print(obj.largestGoodInteger("2300019"))  # expect: 000
    print(obj.largestGoodInteger("42352338"))  # expect: NULL
