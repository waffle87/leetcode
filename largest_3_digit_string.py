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
        ans = ""
        empty = ""
        tmp = 0
        check = True
        for i in range(len(num) - 2):
            if i + 2 < len(num) and num[i] == num[i + 1] == num[i + 2]:
                tmp = max(tmp, int(num[i]))
                check = False
        if not check:
            ans += str(tmp) * 3
        else:
            return empty
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.largestGoodInteger("6777133339"))  # expect: 777
    print(obj.largestGoodInteger("2300019"))  # expect: 000
    print(obj.largestGoodInteger("42352338"))  # expect: NULL
