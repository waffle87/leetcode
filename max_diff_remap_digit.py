# 2566. Maximum Difference by Remapping a Digit

"""
you are given an integer 'num'. you know that bob will sneakily remap one of
the 10 possible digits to another digit. return the difference between the
maximum and minimum values bob can make by remapping exactly one digit in
nums.
"""


class Solution(object):
    def minMaxDifference(self, num):
        """
        :type num: int
        :rtype: int
        """
        num, i = str(num), 0
        while num[i] == "9" and i < len(num) - 1:
            i += 1
        return int(num.replace(num[i], "9")) - int(num.replace(num[0], "0"))


if __name__ == "__main__":
    obj = Solution()
    print(obj.minMaxDifference(num=11891))
    print(obj.minMaxDifference(num=90))
