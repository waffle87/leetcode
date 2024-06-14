# 1903. Largest Odd Number in String

"""
given a string 'num' representing a large integer. return the largest-valued
odd integer as a string is a non-empty substring of 'num', or an empty string
"" if no odd integer exists. a substring is a contiguous sequence of
characters within a string
"""


class Solution(object):
    def largestOddNumber(self, num):
        """
        :type num: str
        :rtype: str
        """
        for i in range(len(num) - 1, -1, -1):
            if num[i] in {"1", "3", "5", "7", "9"}:
                return num[: i + 1]
        return ""


if __name__ == "__main__":
    obj = Solution()
    print(obj.largestOddNumber("52"))  # expect: 5
    print(obj.largestOddNumber("4206"))  # expect: ""
    print(obj.largestOddNumber("35427"))  # expect: 35427
